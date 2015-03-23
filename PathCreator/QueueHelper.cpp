// QueueHelper.cpp

#include "stdafx.h"
#include "QueueHelper.h"

#define DOQUEUESECTION(QSECTION) sid.Name(qtd.QSECTION); \
	sid.TxtName = text; \
	sid.GsiIcon = qtd.GsiIcon; \
	sid.OvlPath = ovlPath + qtd.QSECTION; \
	sid.Svds.push_back(qtd.QSECTION + ":svd"); \
	sidCol.Add(sid); \
	sid.Svds.clear();

#define EXISTS(f) (File::Exists((f)))
#define NSTRFILLED(s) (String::IsNullOrWhiteSpace((s)))

QueuePath::QueuePath() {
	Name = "";
	IngameName = "";
	Icon = "";
	Texture = "";
	Shared = "";
	Straight = "";
	TurnL = "";
	TurnR = "";
	SlopeUp = "";
	SlopeDown = "";
	SlopeStraight1 = "";
	SlopeStraight2 = "";
	Recolor1 = false;
	Recolor2 = false;
	Recolor3 = false;
}

bool QueuePath::filled() {
	return (!NSTRFILLED(Name) && !NSTRFILLED(IngameName) && EXISTS(Icon) && EXISTS(Texture) &&
		EXISTS(Straight) && EXISTS(TurnL) && EXISTS(TurnR) && EXISTS(SlopeUp) && EXISTS(SlopeDown) &&
		EXISTS(SlopeStraight1));
}

String^ QueuePath::incomplete() {
	String^ ret;
	int count = 0;

	if (NSTRFILLED(Name))
	{
		count++;
		ret += "Error " + count.ToString() + ": No queue name specified.\n";
	}

	if (NSTRFILLED(IngameName))
	{
		count++;
		ret += "Error " + count.ToString() + ": No ingame queue name specified.\n";
	}

	if (!EXISTS(Icon))
	{
		count++;
		ret += "Error " + count.ToString() + ": Icon image: no file specified or file doesn't exist.\n";
	}

	if (!EXISTS(Texture))
	{
		count++;
		ret += "Error " + count.ToString() + ": Texture image: no file specified or file doesn't exist.\n";
	}

	if (!EXISTS(Straight))
	{
		count++;
		ret += "Error " + count.ToString() + ": 'Straight' model: no OVL specified or OVL doesn't exist.\n";
	}

	if (!EXISTS(TurnL))
	{
		count++;
		ret += "Error " + count.ToString() + ": 'TurnL' model: no OVL specified or OVL doesn't exist.\n";
	}

	if (!EXISTS(TurnR))
	{
		count++;
		ret += "Error " + count.ToString() + ": 'TurnR' model: no OVL specified or OVL doesn't exist.\n";
	}

	if (!EXISTS(SlopeUp))
	{
		count++;
		ret += "Error " + count.ToString() + ": 'SlopeUp' model: no OVL specified or OVL doesn't exist.\n";
	}

	if (!EXISTS(SlopeDown))
	{
		count++;
		ret += "Error " + count.ToString() + ": 'SlopeDown' model: no OVL specified or OVL doesn't exist.\n";
	}

	if (!EXISTS(SlopeStraight1))
	{
		count++;
		ret += "Error " + count.ToString() + ": 'SlopeStraight' model: no OVL specified or OVL doesn't exist.\n";
	}

	return ret;
}

void QueuePath::copyFilesTo(String^ dest) {
	String^ unique;

	if (File::Exists(Shared)) {
		File::Copy(Shared, dest + Path::GetFileName(Shared));
		File::Copy(unique = Shared->Replace(".common.ovl", ".unique.ovl"), dest + Path::GetFileName(unique));
	}

	File::Copy(Straight, dest + Path::GetFileName(Straight));
	File::Copy(unique = Straight->Replace(".common.ovl", ".unique.ovl"), dest + Path::GetFileName(unique));

	File::Copy(TurnL, dest + Path::GetFileName(TurnL));
	File::Copy(unique = TurnL->Replace(".common.ovl", ".unique.ovl"), dest + Path::GetFileName(unique));

	File::Copy(TurnR, dest + Path::GetFileName(TurnR));
	File::Copy(unique = TurnR->Replace(".common.ovl", ".unique.ovl"), dest + Path::GetFileName(unique));

	File::Copy(SlopeDown, dest + Path::GetFileName(SlopeDown));
	File::Copy(unique = SlopeDown->Replace(".common.ovl", ".unique.ovl"), dest + Path::GetFileName(unique));

	File::Copy(SlopeStraight1, dest + Path::GetFileName(SlopeStraight1));
	File::Copy(unique = SlopeStraight1->Replace(".common.ovl", ".unique.ovl"), dest + Path::GetFileName(unique));

	if (EXISTS(SlopeStraight2))
	{
		File::Copy(SlopeStraight2, dest + Path::GetFileName(SlopeStraight2));
		File::Copy(unique = SlopeStraight2->Replace(".common.ovl", ".unique.ovl"), dest + Path::GetFileName(unique));
	}
}

void QueuePath::read(BinaryReader^ f) {
	unsigned int length;
	READSTRING(Name);
	READUSTRING(IngameName);
	READUSTRING(Icon);
	READUSTRING(Texture);
	Recolor1 = f->ReadBoolean();
	Recolor2 = f->ReadBoolean();
	Recolor3 = f->ReadBoolean();
	READUSTRING(Shared);
	READUSTRING(Straight);
	READUSTRING(TurnL);
	READUSTRING(TurnR);
	READUSTRING(SlopeUp);
	READUSTRING(SlopeDown);
	READUSTRING(SlopeStraight1);
	READUSTRING(SlopeStraight2);
}

void QueuePath::serialize(BinaryWriter^ f) {
	String^ pathType = "queue";

	f->Write((short)pathType->Length);
	f->Write(pathType->ToCharArray()); // queue chunk

	f->Write((short)Name->Length);
	f->Write(Name->ToCharArray());
	f->Write((short)IngameName->Length);
	f->Write(Encoding::Unicode->GetBytes(IngameName));
	f->Write((short)Icon->Length);
	f->Write(Encoding::Unicode->GetBytes(Icon));
	f->Write((short)Texture->Length);
	f->Write(Encoding::Unicode->GetBytes(Texture));
	f->Write(Recolor1);
	f->Write(Recolor2);
	f->Write(Recolor3);
	f->Write((short)Shared->Length);
	f->Write(Encoding::Unicode->GetBytes(Shared));
	f->Write((short)Straight->Length);
	f->Write(Encoding::Unicode->GetBytes(Straight));
	f->Write((short)TurnL->Length);
	f->Write(Encoding::Unicode->GetBytes(TurnL));
	f->Write((short)TurnR->Length);
	f->Write(Encoding::Unicode->GetBytes(TurnR));
	f->Write((short)SlopeUp->Length);
	f->Write(Encoding::Unicode->GetBytes(SlopeUp));
	f->Write((short)SlopeDown->Length);
	f->Write(Encoding::Unicode->GetBytes(SlopeDown));
	f->Write((short)SlopeStraight1->Length);
	f->Write(Encoding::Unicode->GetBytes(SlopeStraight1));
	f->Write((short)SlopeStraight2->Length);
	f->Write(Encoding::Unicode->GetBytes(SlopeStraight2));
}

bool QueuePath::saveAsCpath(String^ filename, unsigned int IsDarkHorizons) {
	try {
		BinaryWriter^ f = gcnew BinaryWriter(File::Open(filename, System::IO::FileMode::Create, System::IO::FileAccess::Write), Encoding::ASCII);

		f->Write(CPATH_FILE_SIGNATURE);
		f->Write(CPATH_FILE_VERSION);
		f->Write(CPATH_FILE_SIGNATURE2);
		f->Write(IsDarkHorizons);

		f->Write(1); // chunk count (1)

		f->Write((unsigned int)Rct3PathType::Queue);

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

void  QueuePath::CreateBlankOVL(String^ path, RCT3Debugging::OutputLog& log)
{
	using namespace RCT3Asset;

	log.Info("Path Creator 2.0: Creating blank OVL...");

	OvlFile ovl(log);

	ovl.Save(marshal_as<std::string>(path));

	log.Info("Path Creator 2.0: ...blank OVL created.");
}

void QueuePath::CreateTextureOVL(String^ path, RCT3Debugging::OutputLog& log)
{
	using namespace RCT3Asset;

	log.Info("Path Creator 2.0: Creating texture OVL...");

	OvlFile ovl(log);

	String^ texture = Texture;

	unsigned int recolor = 0;

	recolor |= Recolor1 ? RCT3Asset::RecolorOptions::FirstColor : 0;
	recolor |= Recolor2 ? RCT3Asset::RecolorOptions::SecondColor : 0;
	recolor |= Recolor3 ? RCT3Asset::RecolorOptions::ThirdColor : 0;

	FtxImage ftxImg(log);
	ftxImg.FromFile(marshal_as<std::string>(texture));

	FlexiTextureFrame main(ftxImg);
	main.Recolorability(recolor);

	FlexiTexture ftx;
	ftx.Name(GETFILENAME(texture));
	ftx.MakeStillImage(main);

	FlexiTextureCollection ftxCol;
	ftxCol.Add(ftx);

	ftxCol.AddTo(ovl);

	ovl.Save(marshal_as<std::string>(path));

	log.Info("Path Creator 2.0: ...texture OVL created.");
}

void QueuePath::CreateIconOVL(String^ path, RCT3Debugging::OutputLog& log)
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

	RCT3Asset::Texture tex;
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

void QueuePath::CreateStubOVL(String^ path, RCT3Debugging::OutputLog& log)
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

	RCT3Asset::Queue qtd;

	qtd.Name(marshal_as<std::string>(_name));
	qtd.GsiIcon = marshal_as<std::string>(_name + "_Icon:gsi");
	qtd.Text = text;
	qtd.FtxTexture = GETFILENAME(Texture) + ":ftx";

	qtd.Straight = marshal_as<std::string>(getOvlName(Straight));
	qtd.TurnL = marshal_as<std::string>(getOvlName(TurnL));
	qtd.TurnR = marshal_as<std::string>(getOvlName(TurnR));
	qtd.SlopeUp = marshal_as<std::string>(getOvlName(SlopeUp));
	qtd.SlopeDown = marshal_as<std::string>(getOvlName(SlopeDown));
	qtd.SlopeStraight1 = marshal_as<std::string>(getOvlName(SlopeStraight1));

	if (!NSTRFILLED(SlopeStraight2) && EXISTS(SlopeStraight2))
	{
		qtd.SlopeStraight2 = marshal_as<std::string>(getOvlName(SlopeStraight2));
	}
	else
	{
		qtd.SlopeStraight2 = qtd.SlopeStraight1;
	}

	QueueCollection qtdCol;
	qtdCol.Add(qtd);

	SceneryItemCollection sidCol;

	std::string ovlPath = "Queue\\" + stdname + "\\";

	SceneryItem sid;
	sid.SceneryItemType = SIDType::Path;
	sid.Size.X = 4.0f;
	sid.Size.Y = 3.0f;
	sid.Size.Z = 4.0f;

	DOQUEUESECTION(Straight);
	DOQUEUESECTION(TurnL);
	DOQUEUESECTION(TurnR);
	DOQUEUESECTION(SlopeUp);
	DOQUEUESECTION(SlopeDown);
	DOQUEUESECTION(SlopeStraight1);

	if (!NSTRFILLED(SlopeStraight2) && EXISTS(SlopeStraight2))
	{
		DOQUEUESECTION(SlopeStraight2);
	}

	qtdCol.AddTo(ovl);
	sidCol.AddTo(ovl);
	txtCol.AddTo(ovl);

	ovl.Save(marshal_as<std::string>(path));

	log.Info("Path Creator 2.0: ...Stub OVL created.");
}