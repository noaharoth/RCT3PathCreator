// global.cpp

#include "stdafx.h"
#include "global.h"

//using namespace msclr::interop;

void BufferedFileCopy(const std::string& source, const std::string& dest)
{
	FILE* in = fopen(source.c_str(), "rb");
	FILE* out = fopen(dest.c_str(), "wb");

	char buffer[2048];
	int size = 0;

	while (size = fread(buffer, 1, 2048, in))
	{
		fwrite(buffer, 1, size, out);
	}

	fclose(in);
	fclose(out);
}

void LoadResourceImages() {
	ImageResourceManager::images = gcnew array<Bitmap^>(IMG_COUNT);

	for (int i = 0; i < IMG_COUNT; i++) {
		ImageResourceManager::images[i] = gcnew Bitmap(Assembly::GetExecutingAssembly()->GetManifestResourceStream(ImageResourceManager::imageNames[i]));
	}
}

Bitmap^ GetResourceImage(unsigned int image) {
	return ImageResourceManager::images[image];
}

bool global::openCpathProject(String^ filename) {
	Basic = nullptr;
	Extended = nullptr;
	Queue = nullptr;
	SavedDirectory = filename;
	ProjectName = Path::GetFileNameWithoutExtension(filename);
	
	bool ret;

	BinaryReader^ f = gcnew BinaryReader(File::Open(filename, System::IO::FileMode::Open), Encoding::ASCII);

	try 
	{

		unsigned int signature = f->ReadUInt32();

		if (signature != CPATH_FILE_SIGNATURE)
			throw gcnew Exception("Load project error - not a valid path project!");

		float version = f->ReadSingle();

		if (version != CPATH_FILE_VERSION)
			throw gcnew Exception("Load project error - path project version outdated!");

		signature = f->ReadUInt32();

		if (signature != CPATH_FILE_SIGNATURE2)
			throw gcnew Exception("Load project error - file is corrupt or not a valid project file!");

		unsigned int special = f->ReadUInt32();

		IsDarkHorizons = special;

		unsigned int chunkCount = f->ReadUInt32();

		for (int i = 0; i < chunkCount; i++)
		{
			unsigned int type = f->ReadUInt32();
			global::Type = (Rct3PathType)type;


			if (global::Type == Rct3PathType::Basic)
			{
				global::Basic = gcnew BasicPath();
			}
			else if (global::Type == Rct3PathType::Extended)
			{
				if (global::Basic == nullptr)
					throw gcnew Exception("Load project error - no base for path extension!");
				global::Extended = gcnew ExtendedPath(Basic);
			}
			else if (global::Type == Rct3PathType::Queue)
			{
				global::Queue = gcnew QueuePath();
			}
			else
				throw gcnew Exception("Load project error - unknown path type value!");
		}

		String^ chunkType;

		for (int i = 0; i < chunkCount; i++) 
		{
			chunkType = gcnew String(f->ReadChars(f->ReadUInt16()));

			if (chunkType == "basic") 
			{
				if (global::Basic == nullptr)
					throw gcnew Exception("Load project error - unexpected chunk (basic)!");

				global::Basic->read(f);
			}
			else if (chunkType == "extended") 
			{
				if (global::Extended == nullptr)
					throw gcnew Exception("Load project error - unexpected chunk (extended)!");

				global::Extended->read(f);
			}
			else if (chunkType == "queue") 
			{
				if (global::Queue == nullptr)
					throw gcnew Exception("Load project error - unexpected chunk (queue)!");

				global::Queue->read(f);
			}
			else 
			{
				throw gcnew Exception("Load project error - unknown data chunk! (" + chunkType + ")");
			}
		}

		RecentProject proj;
		proj.FileName = filename;
		proj.ProjectName = ProjectName;
		Settings->AddRecentProject(proj);

		ret = true;
	}
	catch (Exception^ ex) 
	{
		MessageBox::Show(ex->Message, "Load project error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		SavedDirectory = nullptr;
		ProjectName = "";

		ret = false;
	}
	finally 
	{
		f->Close();
		delete f;
	}

	return ret;
}

bool IsPowerOfTwo(unsigned int value) {
	return (value != 0) && ((value & (value - 1)) == 0);
}

bool StringContains(String^ source, String^ find, System::StringComparison comp) {
	return source->IndexOf(find, comp) >= 0;
}

VersionInfo CheckForUpdates(String^& out_downloadUrl)
{
	String^ xmlUrl = "https://dl.dropboxusercontent.com/s/7ljoy8w22bdd8a8/version.xml";

	XmlTextReader^ reader;
	String^ patchNotes = nullptr;
	VersionInfo info;

	info.SpecialNotes = "";

	try
	{

		reader = gcnew XmlTextReader(xmlUrl);
		reader->MoveToContent();

		String^ elementName = "";

		if ((reader->NodeType == XmlNodeType::Element) && (reader->Name == "pathcreator"))
		{

			while (reader->Read())
			{

				if (reader->NodeType == XmlNodeType::Element)
					elementName = reader->Name;
				else
				{
					if (reader->NodeType == XmlNodeType::Text && reader->HasValue)
					{
						if (elementName == "version")
						{
							info = VersionInfo::FromString(reader->Value);
						}
						else if (elementName == "patchnotes")
						{
							info.VersionInformationText = reader->Value;
						}
						else if (elementName == "url")
						{
							out_downloadUrl = reader->Value;
						}
						else
						{
							throw gcnew Exception("Unknown XML element '" + elementName + "'");
						}
					}
				}
			}
		}
	}
	catch (Exception^ ex)
	{
		MessageBox::Show( "There was an error retrieving update info: " +
			ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	finally
	{
		if (reader != nullptr)
			reader->Close();
	}

	return info;
}