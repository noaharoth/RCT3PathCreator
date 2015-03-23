// ProgramSettings.cpp

#include "stdafx.h"
#include "ProgramSettings.h"

ProgramSettings::ProgramSettings()
{
	RecentProjects = gcnew List<RecentProject>(RECENT_PROJECTS_MAX);

	CurrentVersion = GetCurrentVersion();

	SaveOnExit = false;
}

void ProgramSettings::AddRecentProject(RecentProject proj)
{
	unsigned int count = RecentProjects->Count;

	if (count >= RECENT_PROJECTS_MAX)
	{
		if (RecentProjects->Contains(proj))
			RecentProjects->Remove(proj);
		else
		{
			int index = count - 1;
			RecentProjects->RemoveAt(index);
		}
	}

	if (RecentProjects->Contains(proj))
		RecentProjects->Remove(proj);

	RecentProjects->Add(proj);

	SaveOnExit = true;
}

void ProgramSettings::Save()
{
	if (!File::Exists("settings"))
	{
		File::Create("settings")->Close();
	}

	BinaryWriter^ f = gcnew BinaryWriter(File::Open("settings", System::IO::FileMode::Truncate), Encoding::ASCII);

	f->Write(SETTINGS_FILE_SIGNATURE);

	int padding = RECENT_PROJECTS_MAX - RecentProjects->Count;

	for (int i = 0; i < RecentProjects->Count; i++)
	{
		f->Write((unsigned short)RecentProjects[i].ProjectName->Length);
		f->Write(Encoding::Unicode->GetBytes(RecentProjects[i].ProjectName));
		f->Write((unsigned short)RecentProjects[i].FileName->Length);
		f->Write(Encoding::Unicode->GetBytes(RecentProjects[i].FileName));
	}

	for (int i = 0; i < padding; i++)
	{
		f->Write((unsigned short)0);
		f->Write((unsigned short)0);
	}

	f->Write((unsigned short)RCT3InstallDirectory->Length);
	f->Write(Encoding::Unicode->GetBytes(RCT3InstallDirectory));

	f->Write(DebugLog ? FILE_BOOL_TRUE : 0);

	f->Write((unsigned int)UpdateCheckFreq);
	f->Write(LastUpdateCheck.Month);
	f->Write(LastUpdateCheck.Day);
	f->Write(LastUpdateCheck.Year);

	f->Flush();
	f->Close();
}

String^ ProgramSettings::FindRCT3InstallDirectory(String^% msg)
{
	String^ atariDir = Environment::ExpandEnvironmentVariables("%PROGRAMFILES%\\Atari\\");

	String^ rct3BaseDir = atariDir + "Roller Coaster Tycoon 3";

	if (Directory::Exists(rct3BaseDir))
	{
		return rct3BaseDir;
	}

	rct3BaseDir = atariDir + "RollerCoaster Tycoon 3";

	if (Directory::Exists(rct3BaseDir))
	{
		return rct3BaseDir;
	}

	msg = "Unable to locate RollerCoaster Tycoon 3 root directory. You can set the directory manually in "
		"program settings.";

	return "";
}

VersionInfo ProgramSettings::GetCurrentVersion()
{
	StreamReader^ reader = gcnew StreamReader(Assembly::GetExecutingAssembly()->GetManifestResourceStream("version.txt"));
	String^ versionTxt = reader->ReadToEnd();
	return VersionInfo::FromString(versionTxt);
}

ProgramSettings^ ProgramSettings::CreateDefault(String^% msg)
{
	ProgramSettings^ settings = gcnew ProgramSettings();
	settings->DebugLog = false;
	settings->RCT3InstallDirectory = FindRCT3InstallDirectory(msg);
	settings->CurrentVersion = ProgramSettings::GetCurrentVersion();
	settings->UpdateCheckFreq = UpdateFrequency::EveryWeek;

	DateTime now = DateTime::Now;
	DateTime time = DateTime(now.Year, now.Month, now.Day - 8);
	settings->LastUpdateCheck = time;
	settings->LastUpdateCheck = DateTime::Now;

	settings->Save();
	return settings;
}

void ProgramSettings::Open(String^% msg)
{
	BinaryReader^ f;

	try
	{
		f = gcnew BinaryReader(File::Open("settings", System::IO::FileMode::Open), Encoding::ASCII);

		unsigned int signature = f->ReadUInt32();

		if (signature != SETTINGS_FILE_SIGNATURE)
			throw gcnew Exception("Settings file corrupted! Aborting...");

		unsigned short len = 0;
		RecentProject curr;

		for (int i = 0; i < RECENT_PROJECTS_MAX; i++)
		{
			len = f->ReadUInt16();

			if (len == 0)
			{
				f->ReadUInt16();
			}
			else
			{

				curr.ProjectName = Encoding::Unicode->GetString(f->ReadBytes(len * 2));

				len = f->ReadUInt16();

				curr.FileName = Encoding::Unicode->GetString(f->ReadBytes(len * 2));

				RecentProjects->Add(curr);
			}
		}

		len = f->ReadUInt16();

		if (len)
		{
			RCT3InstallDirectory = Encoding::Unicode->GetString(f->ReadBytes(len * 2));
		}
		else
		{
			//RCT3InstallDirectory = FindRCT3InstallDirectory(msg);
			RCT3InstallDirectory = "";
		}

		unsigned int debug = f->ReadUInt32();

		DebugLog = debug == FILE_BOOL_TRUE ? true : false;

		UpdateFrequency freq = (UpdateFrequency)f->ReadUInt32();

		UpdateCheckFreq = freq;

		int month, day, year;

		month = f->ReadInt32();
		day = f->ReadInt32();
		year = f->ReadInt32();

		LastUpdateCheck = DateTime(year, month, day);
	}
	catch (Exception^ ex)
	{
		MessageBox::Show("Error reading settings file. Delete 'settings' and restart application.");
	}
	finally
	{
		if (f != nullptr)
			f->Close();
	}
}