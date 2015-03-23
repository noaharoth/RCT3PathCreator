// PathHelper.cpp

#include "stdafx.h"
#include "PathHelper.h"
#include "global.h"

#define DO_SECTION(PTDSECTION) sid.Name(ptd.PTDSECTION[0]); \
	sid.TxtName = text; \
	sid.GsiIcon = ptd.GsiIcon; \
	sid.OvlPath = ovlPath + ptd.PTDSECTION[0]; \
	sid.Svds.push_back(ptd.PTDSECTION[0] + ":svd"); \
	sidCol.Add(sid); \
	sid.Svds.clear();

#define DO_OPTIONAL_SECTION(OPTSECTION) if (ptd.OPTSECTION[0].length()) { \
	sid.Name(ptd.OPTSECTION[0]); \
	sid.TxtName = text; \
	sid.GsiIcon = ptd.GsiIcon; \
	sid.OvlPath = ovlPath + ptd.OPTSECTION[0]; \
	sid.Svds.push_back(ptd.OPTSECTION[0] + ":svd"); \
	sidCol.Add(sid); \
	sid.Svds.clear(); } 

String^ getOvlName(String^ ovl)
{
	array<String^>^ file = ovl->Split('\\');

	return file[file->Length - 1]->Split('.')[0];
}

RCT3Asset::PathSection MPathSection::Convert()
{
	RCT3Asset::PathSection section;

	if (filled())
	{
		section[0] = marshal_as<std::string>(getOvlName(North));
		section[1] = marshal_as<std::string>(getOvlName(East));
		section[2] = marshal_as<std::string>(getOvlName(South));
		section[3] = marshal_as<std::string>(getOvlName(West));
	}
	else
	{
		section[0] = "";
		section[1] = "";
		section[2] = "";
		section[3] = "";
	}

	return section;
}

MPathSection::MPathSection(String^ filename) {
	North = filename;
	East = filename;
	South = filename;
	West = filename;
}

bool MPathSection::filled() {
	return (!String::IsNullOrWhiteSpace(North) &&
		!String::IsNullOrWhiteSpace(East) &&
		!String::IsNullOrWhiteSpace(South) &&
		!String::IsNullOrWhiteSpace(West));
}

bool MPathSection::complete() {
	return (File::Exists(North) && File::Exists(North->Replace(".common.ovl", ".unique.ovl")) &&
		File::Exists(South) && File::Exists(South->Replace(".common.ovl", ".unique.ovl")) &&
		File::Exists(East) && File::Exists(East->Replace(".common.ovl", ".unique.ovl")) &&
		File::Exists(West) && File::Exists(West->Replace(".common.ovl", ".unique.ovl")));
}

String^ MPathSection::incomplete(String^ sectionName, unsigned int* count) {
	String^ ret = "";

	if (!File::Exists(North) || !File::Exists(North->Replace(".common.ovl", ".unique.ovl"))) {
		*count += 1;
		ret += "Error " + (*count).ToString() + ": Path section '" + sectionName + "': no selected file or file doesn't exist.\n";
	}

	if (East != North && (!File::Exists(East) || !File::Exists(East->Replace(".common.ovl", ".unique.ovl")))) {
		*count += 1;
		ret += "Error " + (*count).ToString() + ": Path section '" + sectionName + "' (East): file doesn't exist.\n";
	}

	if (South != North && (!File::Exists(South) || !File::Exists(South->Replace(".common.ovl", ".unique.ovl")))) {
		*count += 1;
		ret += "Error " + (*count).ToString() + ": Path section '" + sectionName + "' (South): file doesn't exist.\n";
	}

	if (West != North && (!File::Exists(West) || !File::Exists(West->Replace(".common.ovl", ".unique.ovl")))) {
		*count += 1;
		ret += "Error " + (*count).ToString() + ": Path section '" + sectionName + "' (West): file doesn't exist.\n";
	}

	return ret;
}

void MPathSection::copyFilesTo(String^ dest) {
	if (!String::IsNullOrWhiteSpace(North)) {
		String^ commonS = North;
		String^ commonD = dest + Path::GetFileName(North);
		String^ uniqueS = North->Replace(".common.ovl", ".unique.ovl");
		String^ uniqueD = dest + Path::GetFileName(uniqueS);

		BufferedFileCopy(marshal_as<std::string>(commonS), marshal_as<std::string>(commonD));
		BufferedFileCopy(marshal_as<std::string>(uniqueS), marshal_as<std::string>(uniqueD));

		/*File::Copy(North, dest + Path::GetFileName(North), true);
		File::Copy(unique = North->Replace(".common.ovl", ".unique.ovl"), dest + Path::GetFileName(unique), true);

		if (South != North) {
			File::Copy(South, dest + Path::GetFileName(South), true);
			File::Copy(unique = South->Replace(".common.ovl", ".unique.ovl"), dest + Path::GetFileName(unique), true);
		}

		if (East != North) {
			File::Copy(East, dest + Path::GetFileName(East), true);
			File::Copy(unique = East->Replace(".common.ovl", ".unique.ovl"), dest + Path::GetFileName(unique), true);
		}

		if (West != North) {
			File::Copy(West, dest + Path::GetFileName(West), true);
			File::Copy(unique = West->Replace(".common.ovl", ".unique.ovl"), dest + Path::GetFileName(unique), true);
		}*/
	}
}

void MPathSection::read(BinaryReader^ f) {
	unsigned short length;

	READUSTRING(North);

	if ((length = f->ReadUInt16()) != 0xFFFF) {
		East = Encoding::Unicode->GetString(f->ReadBytes(length * 2));
	}
	else
		East = North;

	if ((length = f->ReadUInt16()) != 0xFFFF) {
		South = Encoding::Unicode->GetString(f->ReadBytes(length * 2));
	}
	else
		South = North;

	if ((length = f->ReadUInt16()) != 0xFFFF) {
		West = Encoding::Unicode->GetString(f->ReadBytes(length * 2));
	}
	else
		West = North;
}

void MPathSection::serialize(BinaryWriter^ f) {
	f->Write((short)North->Length);
	f->Write(Encoding::Unicode->GetBytes(North));

	if (East != North) {
		f->Write((short)East->Length);
		f->Write(Encoding::Unicode->GetBytes(East));
	}
	else
		f->Write((unsigned short)0xFFFF);


	if (South != North) {
		f->Write((short)South->Length);
		f->Write(Encoding::Unicode->GetBytes(South));
	}
	else
		f->Write((unsigned short)0xFFFF);

	if (West != North) {
		f->Write((short)West->Length);
		f->Write(Encoding::Unicode->GetBytes(West));
	}
	else
		f->Write((unsigned short)0xFFFF);
}

BasicPath::BasicPath() {
	Name = "";
	IngameName = "";
	Icon = "";
	TextureA = "";
	TextureB = "";
	Shared = "";
	Flat = MPathSection("");
	StraightA = MPathSection("");
	StraightB = MPathSection("");
	CornerA = MPathSection("");
	CornerB = MPathSection("");
	CornerC = MPathSection("");
	CornerD = MPathSection("");
	TurnU = MPathSection("");
	TurnLA = MPathSection("");
	TurnLB = MPathSection("");
	TurnTA = MPathSection("");
	TurnTB = MPathSection("");
	TurnTC = MPathSection("");
	TurnX = MPathSection("");
	Slope = MPathSection("");
	SlopeStraight = MPathSection("");
	SlopeStraightL = MPathSection("");
	SlopeStraightR = MPathSection("");
	SlopeMid = MPathSection("");
	Flags = RCT3Asset::PathFlags::Default;
}

bool BasicPath::filled() {
	return (!String::IsNullOrWhiteSpace(Name) && !String::IsNullOrWhiteSpace(IngameName) && !String::IsNullOrWhiteSpace(Icon) &&
		!String::IsNullOrWhiteSpace(TextureA) && !String::IsNullOrWhiteSpace(TextureB) && Flat.filled() && StraightA.filled()
		&& StraightB.filled() && CornerA.filled() && CornerB.filled() && CornerC.filled() && CornerD.filled() && TurnU.filled()
		&& TurnLA.filled() && TurnLB.filled() && TurnTA.filled() && TurnTB.filled() && TurnTC.filled() && TurnX.filled() && Slope.filled()
		&& SlopeStraight.filled() && SlopeStraightL.filled() && SlopeStraightR.filled() && SlopeMid.filled());
}

String^ BasicPath::incomplete() {
	String^ ret = "";
	unsigned int count = 0;

	if (String::IsNullOrWhiteSpace(Name)) {
		count++;
		ret += "Error " + count.ToString() + ": No path name specified.\n";
	}

	if (String::IsNullOrWhiteSpace(IngameName)) {
		count++;
		ret += "Error " + count.ToString() + ": No ingame path name specified.\n";
	}

	if (!File::Exists(Icon)) {
		count++;
		ret += "Error " + count.ToString() + ": Icon image: no file specified or file doesn't exist.\n";
	}

	if (!File::Exists(TextureA)) {
		count++;
		ret += "Error " + count.ToString() + ": TextureA image: no file specified or file doesn't exist.\n";
	}

	if (!File::Exists(TextureB)) {
		count++;
		ret += "Error " + count.ToString() + ": TextureB image: no file specified or file doesn't exist.\n";
	}

	ret += Flat.incomplete("Flat", &count);
	ret += StraightA.incomplete("StraightA", &count);
	ret += StraightB.incomplete("StraightB", &count);
	ret += CornerA.incomplete("CornerA", &count);
	ret += CornerB.incomplete("CornerB", &count);
	ret += CornerC.incomplete("CornerC", &count);
	ret += CornerD.incomplete("CornerD", &count);
	ret += TurnU.incomplete("TurnU", &count);
	ret += TurnLA.incomplete("TurnLA", &count);
	ret += TurnLB.incomplete("TurnLB", &count);
	ret += TurnTA.incomplete("TurnTA", &count);
	ret += TurnTB.incomplete("TurnTB", &count);
	ret += TurnTC.incomplete("TurnTC", &count);
	ret += TurnX.incomplete("TurnX", &count);
	ret += Slope.incomplete("Slope", &count);
	ret += SlopeStraight.incomplete("SlopeStraight", &count);
	ret += SlopeStraightL.incomplete("SlopeStraightL", &count);
	ret += SlopeStraightR.incomplete("SlopeStraightR", &count);
	ret += SlopeMid.incomplete("SlopeMid", &count);

	return ret;
}

void BasicPath::CreateTextureOVL(String^ path, RCT3Debugging::OutputLog& log)
{
	using namespace RCT3Asset;

	log.Info("Path Creator 2.0: Creating Texture OVL...");

	OvlFile ovl(log);

	String^ texADir = this->TextureA;
	String^ texBDir = this->TextureB;
	String^ texAName = System::IO::Path::GetFileNameWithoutExtension(this->TextureA);
	String^ texBName = System::IO::Path::GetFileNameWithoutExtension(this->TextureB);

	TextureStyle txs = TextureStyle::PathGround;
	txs.AddTo(ovl);

	TexImage imgA(log);
	imgA.FromFile(marshal_as<std::string>(texADir));

	TextureMip mainAMip(imgA);

	Texture mainA;
	mainA.Name(marshal_as<std::string>(texAName));
	mainA.TxsStyle = txs;
	mainA.Mips.push_back(mainAMip);

	TexImage imgB(log);
	imgB.FromFile(marshal_as<std::string>(texBDir));

	TextureMip mainBMip(imgB);

	Texture mainB;
	mainB.Name(marshal_as<std::string>(texBName));
	mainB.TxsStyle = txs;
	mainB.Mips.push_back(mainBMip);

	// always create flic before textures
	FlicManager flic;
	flic.Add(mainA);
	flic.Add(mainB);
	flic.CreateAndAssign(ovl);

	// now we can create textures
	TextureCollection texCol;
	texCol.Add(mainA);
	texCol.Add(mainB);
	texCol.AddTo(ovl);

	ovl.Save(marshal_as<std::string>(path));

	log.Info("Path Creator 2.0: ...Texture OVL created.");
}

void BasicPath::CreateBlankOVL(String^ path, RCT3Debugging::OutputLog& log)
{
	using namespace RCT3Asset;

	log.Info("Path Creator 2.0: Creating blank OVL...");

	OvlFile ovl(log);

	ovl.Save(marshal_as<std::string>(path));

	log.Info("Path Creator 2.0: ...blank OVL created.");
}

void BasicPath::CreateStubOVL(String^ path, RCT3Debugging::OutputLog& log)
{
	using namespace RCT3Asset;

	log.Info("Path Creator 2.0: Creating Stub OVL...");

	OvlFile ovl(log);

	String^ _name = Name;
	String^ _ingameName = IngameName;

	std::string stdname = marshal_as<std::string>(_name);

	ovl.AddFileReference(stdname + "_Icon");

	TextString text;
	text.Name(marshal_as<std::string>(_name + "_Text"));
	text.Text(marshal_as<std::wstring>(_ingameName));

	TextStringCollection txtCol;
	txtCol.Add(text);

	RCT3Asset::Path ptd;

	ptd.Name(marshal_as<std::string>(_name));
	ptd.GsiIcon = marshal_as<std::string>(_name + "_Icon:gsi");
	ptd.Text = text;
	ptd.Flags = Flags;
	ptd.TextureA = GETFILENAME(TextureA);
	ptd.TextureB = GETFILENAME(TextureB);

	ptd.Flat = Flat.Convert();
	ptd.StraightA = StraightA.Convert();
	ptd.StraightB = StraightB.Convert();
	ptd.CornerA = CornerA.Convert();
	ptd.CornerB = CornerB.Convert();
	ptd.CornerC = CornerC.Convert();
	ptd.CornerD = CornerD.Convert();
	ptd.TurnU = TurnU.Convert();
	ptd.TurnLA = TurnLA.Convert();
	ptd.TurnLB = TurnLB.Convert();
	ptd.TurnTA = TurnTA.Convert();
	ptd.TurnTB = TurnTB.Convert();
	ptd.TurnTC = TurnTC.Convert();
	ptd.TurnX = TurnX.Convert();
	ptd.Slope = Slope.Convert();
	ptd.SlopeStraight = SlopeStraight.Convert();
	ptd.SlopeStraightLeft = SlopeStraightL.Convert();
	ptd.SlopeStraightRight = SlopeStraightR.Convert();
	ptd.SlopeMid = SlopeMid.Convert();

	PathCollection ptdCol;
	ptdCol.Add(ptd);

	SceneryItemCollection sidCol;

	std::string ovlPath = "Path\\" + stdname + "\\";

	SceneryItem sid;
	sid.SceneryItemType = SIDType::Path;
	sid.Size.X = 4.0f;
	sid.Size.Y = 3.0f;
	sid.Size.Z = 4.0f;

	DO_SECTION(Flat);
	DO_SECTION(StraightA);
	DO_SECTION(StraightB);
	DO_SECTION(CornerA);
	DO_SECTION(CornerB);
	DO_SECTION(CornerC);
	DO_SECTION(CornerD);
	DO_SECTION(TurnU);
	DO_SECTION(TurnLA);
	DO_SECTION(TurnLB);
	DO_SECTION(TurnTA);
	DO_SECTION(TurnTB);
	DO_SECTION(TurnTC);
	DO_SECTION(TurnX);
	DO_SECTION(Slope);
	DO_SECTION(SlopeStraight);
	DO_SECTION(SlopeStraightLeft);
	DO_SECTION(SlopeStraightRight);
	DO_SECTION(SlopeMid);

	ptdCol.AddTo(ovl);
	sidCol.AddTo(ovl);
	txtCol.AddTo(ovl);

	ovl.Save(marshal_as<std::string>(path));

	log.Info("Path Creator 2.0: ...Stub OVL created.");
}

void BasicPath::CreateIconOVL(String^ path, RCT3Debugging::OutputLog& log)
{
	using namespace RCT3Asset;

	log.Info("Path Creator 2.0: Creating Icon OVL...");

	OvlFile ovl(log);

	String^ _name = Name;
	String^ _icon = Icon;

	TextureStyle txs = TextureStyle::GUIIcon;
	txs.AddTo(ovl);

	TexImage imgIcon(log);
	imgIcon.FromFile(marshal_as<std::string>(_icon));

	TextureMip mainMip(imgIcon);

	Texture tex;
	tex.Name(GETFILENAME(_icon));
	tex.TxsStyle = txs;
	tex.Mips.push_back(mainMip);

	GuiSkinItem gsiIcon;
	gsiIcon.Name(marshal_as<std::string>(_name + "_Icon"));

	IconPosition pos;

	pos.Top = 0;
	pos.Left = 0;
	pos.Right = 40;
	pos.Bottom = 40;

	gsiIcon.Position = pos;
	gsiIcon.Texture = tex;

	FlicManager flic;
	flic.Add(tex);
	flic.CreateAndAssign(ovl);

	GuiSkinItemCollection gsiCol;
	gsiCol.Add(gsiIcon);
	gsiCol.AddTo(ovl);

	TextureCollection texCol;
	texCol.Add(tex);
	texCol.AddTo(ovl);

	ovl.Save(marshal_as<std::string>(path));

	log.Info("Path Creator 2.0: ...Icon OVL created.");
}

void BasicPath::copyFilesTo(String^ dest) {
	if (File::Exists(Shared)) {
		String^ unique;
		File::Copy(Shared, dest + Path::GetFileName(Shared));
		File::Copy(unique = Shared->Replace(".common.ovl", ".unique.ovl"), dest + Path::GetFileName(unique));
	}

	Flat.copyFilesTo(dest);
	StraightA.copyFilesTo(dest);
	StraightB.copyFilesTo(dest);
	CornerA.copyFilesTo(dest);
	CornerB.copyFilesTo(dest);
	CornerC.copyFilesTo(dest);
	CornerD.copyFilesTo(dest);
	TurnU.copyFilesTo(dest);
	TurnLA.copyFilesTo(dest);
	TurnLB.copyFilesTo(dest);
	TurnTA.copyFilesTo(dest);
	TurnTB.copyFilesTo(dest);
	TurnTC.copyFilesTo(dest);
	TurnX.copyFilesTo(dest);
	Slope.copyFilesTo(dest);
	SlopeStraight.copyFilesTo(dest);
	SlopeStraightL.copyFilesTo(dest);
	SlopeStraightR.copyFilesTo(dest);
	SlopeMid.copyFilesTo(dest);
}

void BasicPath::read(BinaryReader^ f) {
	unsigned int length;
	READSTRING(Name);
	READUSTRING(IngameName);
	READUSTRING(Icon);
	READUSTRING(TextureA);
	READUSTRING(TextureB);
	//HasShared = f->ReadUInt32() == 0xFFFFFFFF;
	f->ReadUInt32();
	READUSTRING(Shared);

	Flat.read(f);
	StraightA.read(f);
	StraightB.read(f);
	CornerA.read(f);
	CornerB.read(f);
	CornerC.read(f);
	CornerD.read(f);
	TurnU.read(f);
	TurnLA.read(f);
	TurnLB.read(f);
	TurnTA.read(f);
	TurnTB.read(f);
	TurnTC.read(f);
	TurnX.read(f);
	Slope.read(f);
	SlopeStraight.read(f);
	SlopeStraightL.read(f);
	SlopeStraightR.read(f);
	SlopeMid.read(f);

	Flags = f->ReadUInt32();
}

void BasicPath::serialize(BinaryWriter^ f) {
	String^ pathType = "basic";

	f->Write((short)pathType->Length);
	f->Write(pathType->ToCharArray()); // basic chunk

	f->Write((short)Name->Length);
	f->Write(Name->ToCharArray());
	f->Write((short)IngameName->Length);
	f->Write(Encoding::Unicode->GetBytes(IngameName));
	f->Write((short)Icon->Length);
	f->Write(Encoding::Unicode->GetBytes(Icon));
	f->Write((short)TextureA->Length);
	f->Write(Encoding::Unicode->GetBytes(TextureA));
	f->Write((short)TextureB->Length);
	f->Write(Encoding::Unicode->GetBytes(TextureB));
	f->Write(0xFEFEFEFE);
	f->Write((short)Shared->Length);
	f->Write(Encoding::Unicode->GetBytes(Shared));

	Flat.serialize(f);
	StraightA.serialize(f);
	StraightB.serialize(f);
	CornerA.serialize(f);
	CornerB.serialize(f);
	CornerC.serialize(f);
	CornerD.serialize(f);
	TurnU.serialize(f);
	TurnLA.serialize(f);
	TurnLB.serialize(f);
	TurnTA.serialize(f);
	TurnTB.serialize(f);
	TurnTC.serialize(f);
	TurnX.serialize(f);
	Slope.serialize(f);
	SlopeStraight.serialize(f);
	SlopeStraightL.serialize(f);
	SlopeStraightR.serialize(f);
	SlopeMid.serialize(f);

	f->Write(Flags);
}

bool BasicPath::saveAsCpath(String^ filename, unsigned int IsDarkHorizons) {
	try {
		BinaryWriter^ f = gcnew BinaryWriter(File::Open(filename, System::IO::FileMode::Create, System::IO::FileAccess::Write), Encoding::ASCII);

		f->Write(CPATH_FILE_SIGNATURE);
		f->Write(CPATH_FILE_VERSION);
		f->Write(CPATH_FILE_SIGNATURE2);
		f->Write(IsDarkHorizons);

		f->Write(1); // chunk count (1)

		f->Write((unsigned int)Rct3PathType::Basic);

		serialize(f);

		f->Flush();
		f->Close();

		delete f;
	}
	catch (Exception^ ex) {
		MessageBox::Show(ex->Message, "Error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return false;
	}

	return true;
}

ExtendedPath::ExtendedPath(BasicPath^ base) {
	Base = base;
	base->Flags = RCT3Asset::PathFlags::Default | RCT3Asset::PathFlags::Extended;
	Unknown03 = 0;
	Unknown04 = 1;
	FlatFC = MPathSection("");
	SlopeFC = MPathSection("");
	SlopeBC = MPathSection("");
	SlopeTC = MPathSection("");
	SlopeStraightFC = MPathSection("");
	SlopeStraightBC = MPathSection("");
	SlopeStraightTC = MPathSection("");
	SlopeStraightLFC = MPathSection("");
	SlopeStraightLBC = MPathSection("");
	SlopeStraightLTC = MPathSection("");
	SlopeStraightRFC = MPathSection("");
	SlopeStraightRBC = MPathSection("");
	SlopeStraightRTC = MPathSection("");
	SlopeMidFC = MPathSection("");
	SlopeMidBC = MPathSection("");
	SlopeMidTC = MPathSection("");
	Paving = "";
}

void ExtendedPath::copyFilesTo(String^ dest) {
	Base->copyFilesTo(dest);

	FlatFC.copyFilesTo(dest);
	SlopeFC.copyFilesTo(dest);
	SlopeBC.copyFilesTo(dest);
	SlopeTC.copyFilesTo(dest);
	SlopeStraightFC.copyFilesTo(dest);
	SlopeStraightBC.copyFilesTo(dest);
	SlopeStraightTC.copyFilesTo(dest);
	SlopeStraightLFC.copyFilesTo(dest);
	SlopeStraightLBC.copyFilesTo(dest);
	SlopeStraightLTC.copyFilesTo(dest);
	SlopeStraightRFC.copyFilesTo(dest);
	SlopeStraightRBC.copyFilesTo(dest);
	SlopeStraightRTC.copyFilesTo(dest);
	SlopeMidFC.copyFilesTo(dest);
	SlopeMidBC.copyFilesTo(dest);
	SlopeMidTC.copyFilesTo(dest);

	if (!String::IsNullOrWhiteSpace(Paving)) {
		String^ unique;
		File::Copy(Paving, dest + Path::GetFileName(Paving));
		File::Copy(unique = Paving->Replace(".common.ovl", ".unique.ovl"), dest + Path::GetFileName(unique));
	}
}

void ExtendedPath::read(BinaryReader^ f) {
	unsigned int length;
	unsigned int baseReference = f->ReadUInt32();

	if (baseReference != Base->Name->GetHashCode())
		throw gcnew Exception("Load project error - conflicting base reference!");

	Unknown03 = f->ReadUInt32();
	Unknown04 = f->ReadUInt32();

	FlatFC.read(f);
	SlopeFC.read(f);
	SlopeBC.read(f);
	SlopeTC.read(f);
	SlopeStraightFC.read(f);
	SlopeStraightBC.read(f);
	SlopeStraightTC.read(f);
	SlopeStraightLFC.read(f);
	SlopeStraightLBC.read(f);
	SlopeStraightLTC.read(f);
	SlopeStraightRFC.read(f);
	SlopeStraightRBC.read(f);
	SlopeStraightRTC.read(f);
	SlopeMidFC.read(f);
	SlopeMidBC.read(f);
	SlopeMidTC.read(f);

	READUSTRING(Paving);
}

void ExtendedPath::serialize(BinaryWriter^ f) {
	String^ pathType = "extended";

	f->Write((short)pathType->Length);
	f->Write(pathType->ToCharArray()); // extended chunk

	f->Write(Base->Name->GetHashCode()); // reference base

	f->Write(Unknown03);
	f->Write(Unknown04);

	FlatFC.serialize(f);
	SlopeFC.serialize(f);
	SlopeBC.serialize(f);
	SlopeTC.serialize(f);
	SlopeStraightFC.serialize(f);
	SlopeStraightBC.serialize(f);
	SlopeStraightTC.serialize(f);
	SlopeStraightLFC.serialize(f);
	SlopeStraightLBC.serialize(f);
	SlopeStraightLTC.serialize(f);
	SlopeStraightRFC.serialize(f);
	SlopeStraightRBC.serialize(f);
	SlopeStraightRTC.serialize(f);
	SlopeMidFC.serialize(f);
	SlopeMidBC.serialize(f);
	SlopeMidTC.serialize(f);

	f->Write((short)Paving->Length);
	f->Write(Encoding::Unicode->GetBytes(Paving));
}

bool ExtendedPath::saveAsCpath(String^ filename, unsigned int IsDarkHorizons) {
	try {
		BinaryWriter^ f = gcnew BinaryWriter(File::Open(filename, System::IO::FileMode::Create, System::IO::FileAccess::Write), Encoding::ASCII);

		f->Write(CPATH_FILE_SIGNATURE);
		f->Write(CPATH_FILE_VERSION);
		f->Write(CPATH_FILE_SIGNATURE2);
		f->Write(IsDarkHorizons);

		f->Write(2); // chunk count (2)

		f->Write((unsigned int)Rct3PathType::Basic);
		f->Write((unsigned int)Rct3PathType::Extended);

		Base->serialize(f);

		serialize(f);

		f->Flush();
		f->Close();

		delete f;
	}
	catch (Exception^ ex) {
		MessageBox::Show(ex->Message, "Error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return false;
	}

	return true;
}

void ExtendedPath::CreateTextureOVL(String^ path, RCT3Debugging::OutputLog& log)
{
	Base->CreateTextureOVL(path, log);
}

void ExtendedPath::CreateBlankOVL(String^ path, RCT3Debugging::OutputLog& log)
{
	Base->CreateBlankOVL(path, log);
}

void ExtendedPath::CreateStubOVL(String^ path, RCT3Debugging::OutputLog& log)
{
	using namespace RCT3Asset;

	log.Info("Path Creator 2.0: Creating Stub OVL...");

	OvlFile ovl(log);

	String^ _name = Base->Name;
	String^ _ingameName = Base->IngameName;

	std::string stdname = marshal_as<std::string>(_name);

	ovl.AddFileReference(stdname + "_Icon");

	TextString text;
	text.Name(marshal_as<std::string>(_name + "_Text"));
	text.Text(marshal_as<std::wstring>(_ingameName));

	TextStringCollection txtCol;
	txtCol.Add(text);

	RCT3Asset::Path ptd;

	ptd.Name(marshal_as<std::string>(_name));
	ptd.GsiIcon = marshal_as<std::string>(_name + "_Icon:gsi");
	ptd.Text = text;
	ptd.Flags = Base->Flags;
	ptd.TextureA = GETFILENAME(Base->TextureA);
	ptd.TextureB = GETFILENAME(Base->TextureB);
	ptd.Unknown01 = Unknown03;
	ptd.Unknown02 = Unknown04;

	ptd.Flat = Base->Flat.Convert();
	ptd.StraightA = Base->StraightA.Convert();
	ptd.StraightB = Base->StraightB.Convert();
	ptd.CornerA = Base->CornerA.Convert();
	ptd.CornerB = Base->CornerB.Convert();
	ptd.CornerC = Base->CornerC.Convert();
	ptd.CornerD = Base->CornerD.Convert();
	ptd.TurnU = Base->TurnU.Convert();
	ptd.TurnLA = Base->TurnLA.Convert();
	ptd.TurnLB = Base->TurnLB.Convert();
	ptd.TurnTA = Base->TurnTA.Convert();
	ptd.TurnTB = Base->TurnTB.Convert();
	ptd.TurnTC = Base->TurnTC.Convert();
	ptd.TurnX = Base->TurnX.Convert();
	ptd.Slope = Base->Slope.Convert();
	ptd.SlopeStraight = Base->SlopeStraight.Convert();
	ptd.SlopeStraightLeft = Base->SlopeStraightL.Convert();
	ptd.SlopeStraightRight = Base->SlopeStraightR.Convert();
	ptd.SlopeMid = Base->SlopeMid.Convert();

	// extended
	ptd.FlatFC = FlatFC.Convert();
	ptd.SlopeFC = SlopeFC.Convert();
	ptd.SlopeBC = SlopeBC.Convert();
	ptd.SlopeTC = SlopeTC.Convert();
	ptd.SlopeStraightFC = SlopeStraightFC.Convert();
	ptd.SlopeStraightBC = SlopeStraightBC.Convert();
	ptd.SlopeStraightTC = SlopeStraightTC.Convert();
	ptd.SlopeStraightLeftFC = SlopeStraightLFC.Convert();
	ptd.SlopeStraightLeftBC = SlopeStraightLBC.Convert();
	ptd.SlopeStraightLeftTC = SlopeStraightLTC.Convert();
	ptd.SlopeStraightRightFC = SlopeStraightRFC.Convert();
	ptd.SlopeStraightRightBC = SlopeStraightRBC.Convert();
	ptd.SlopeStraightRightTC = SlopeStraightRTC.Convert();
	ptd.SlopeMidFC = SlopeMidFC.Convert();
	ptd.SlopeMidBC = SlopeMidBC.Convert();
	ptd.SlopeMidTC = SlopeMidTC.Convert();

	PathCollection ptdCol;
	ptdCol.Add(ptd);

	SceneryItemCollection sidCol;

	std::string ovlPath = "Path\\" + stdname + "\\";

	SceneryItem sid;
	sid.SceneryItemType = SIDType::Path;

	DO_SECTION(Flat);
	DO_SECTION(StraightA);
	DO_SECTION(StraightB);
	DO_SECTION(CornerA);
	DO_SECTION(CornerB);
	DO_SECTION(CornerC);
	DO_SECTION(CornerD);
	DO_SECTION(TurnU);
	DO_SECTION(TurnLA);
	DO_SECTION(TurnLB);
	DO_SECTION(TurnTA);
	DO_SECTION(TurnTB);
	DO_SECTION(TurnTC);
	DO_SECTION(TurnX);
	DO_SECTION(Slope);
	DO_SECTION(SlopeStraight);
	DO_SECTION(SlopeStraightLeft);
	DO_SECTION(SlopeStraightRight);
	DO_SECTION(SlopeMid);

	// extended

	DO_OPTIONAL_SECTION(FlatFC);
	DO_OPTIONAL_SECTION(SlopeFC);
	DO_OPTIONAL_SECTION(SlopeBC);
	DO_OPTIONAL_SECTION(SlopeTC);
	DO_OPTIONAL_SECTION(SlopeStraightFC);
	DO_OPTIONAL_SECTION(SlopeStraightBC);
	DO_OPTIONAL_SECTION(SlopeStraightTC);
	DO_OPTIONAL_SECTION(SlopeStraightLeftFC);
	DO_OPTIONAL_SECTION(SlopeStraightLeftBC);
	DO_OPTIONAL_SECTION(SlopeStraightLeftTC);
	DO_OPTIONAL_SECTION(SlopeStraightRightFC);
	DO_OPTIONAL_SECTION(SlopeStraightRightBC);
	DO_OPTIONAL_SECTION(SlopeStraightRightTC);
	DO_OPTIONAL_SECTION(SlopeMidFC);
	DO_OPTIONAL_SECTION(SlopeMidBC);
	DO_OPTIONAL_SECTION(SlopeMidTC);

	ptdCol.AddTo(ovl);
	sidCol.AddTo(ovl);
	txtCol.AddTo(ovl);

	ovl.Save(marshal_as<std::string>(path));

	log.Info("Path Creator 2.0: ...Stub OVL created.");
}

void ExtendedPath::CreateIconOVL(String^ path, RCT3Debugging::OutputLog& log)
{
	Base->CreateIconOVL(path, log);
}