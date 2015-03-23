// ExtendedModelsControl.cpp

#include "StdAfx.h"
#include "ExtendedModelsControl.h"

using namespace PathCreator;

#define INITOFD(num, title) section_ofds[num] = gcnew OpenFileDialog(); \
	section_ofds[num]->Title = title; \
	section_ofds[num]->Filter = "OVL Files|*.common.ovl"; \
	section_ofds[num]->SupportMultiDottedExtensions = true

#define INITOFDEXT(num, name) INITOFD(num##_FC, "Load 'name##FC'."); \
	INITOFD(num##_BC, "Load 'name##BC'."); \
	INITOFD(num##_TC, "Load 'name##TC'.");

ExtendedModelsControl::ExtendedModelsControl(void) {
	InitializeComponent();

	activeInstance = this;

	this->VScroll = true;
	this->VerticalScroll->Enabled = true;
	this->VerticalScroll->Minimum = 20;

	this->HorizontalScroll->Enabled = false;
	this->HScroll = false;

	this->PerformLayout();

	btn_slopemid->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_slopestraight_r->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_slopestraight_l->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_slopestraight->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_slope->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_cornerd->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_cornerc->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_cornerb->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_cornera->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_turnx->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_turntc->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_turntb->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_turnta->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_turnlb->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_turnla->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_turnu->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_straightb->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_straighta->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_flat->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_flat_fc->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_slope_tc->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_slope_bc->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_slope_fc->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_slope_straight_tc->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_slope_straight_bc->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_slope_straight_fc->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_slope_straight_l_bc->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_slope_straight_l_fc->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_slope_straight_l_tc->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_slope_straight_r_tc->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_slope_straight_r_bc->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_slope_straight_r_fc->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_paving->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_slope_mid_tc->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_slope_mid_bc->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_slope_mid_fc->BackgroundImage = GetResourceImage(IMG_BUTTON);

	section_ofds = gcnew array<OpenFileDialog^>(PS_EXT_PATH_COUNT);

	INITOFD(PS_FLAT, "Load 'Flat'.");
	INITOFD(PS_STRAIGHT_A, "Load 'StraightA'.");
	INITOFD(PS_STRAIGHT_B, "Load 'StraightB'.");
	INITOFD(PS_TURN_U, "Load 'TurnU'.");
	INITOFD(PS_TURN_LA, "Load 'TurnLA'.");
	INITOFD(PS_TURN_LB, "Load 'TurnLB'.");
	INITOFD(PS_TURN_TA, "Load 'TurnTA'.");
	INITOFD(PS_TURN_TB, "Load 'TurnTB'.");
	INITOFD(PS_TURN_TC, "Load 'TurnTC'.");
	INITOFD(PS_TURN_X, "Load 'TurnX'.");
	INITOFD(PS_CORNER_A, "Load 'CornerA'.");
	INITOFD(PS_CORNER_B, "Load 'CornerB'.");
	INITOFD(PS_CORNER_C, "Load 'CornerC'.");
	INITOFD(PS_CORNER_D, "Load 'CornerD'.");
	INITOFD(PS_SLOPE, "Load 'Slope'.");
	INITOFD(PS_SLOPE_STRAIGHT, "Load 'SlopeStraight'.");
	INITOFD(PS_SLOPE_STRAIGHT_L, "Load 'SlopeStraightLeft'.");
	INITOFD(PS_SLOPE_STRAIGHT_R, "Load 'SlopeStraightRight'.");
	INITOFD(PS_SLOPE_MID, "Load 'SlopeMid'.");
	INITOFD(PS_FLAT_FC, "Load 'FlatFC'.");

	INITOFDEXT(PS_SLOPE, "Slope");
	INITOFDEXT(PS_SLOPE_STRAIGHT, "SlopeStraight");
	INITOFDEXT(PS_SLOPE_STRAIGHT_L, "SlopeStraightL");
	INITOFDEXT(PS_SLOPE_STRAIGHT_R, "SlopeStraightR");
	INITOFDEXT(PS_SLOPE_MID, "SlopeMid");
	INITOFD(PS_PAVING, "Paving");
}

ExtendedModelsControl::~ExtendedModelsControl() {
	if (components)
	{
		delete components;
	}
}

void ExtendedModelsControl::reset() {
	for (int i = 0; i < PS_EXT_PATH_COUNT; i++) {
		section_ofds[i]->Reset();
	}

	global::Basic->Flat = MPathSection("");
	btn_flat->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_flat->Text = "Load 'Flat'.";

	global::Basic->StraightA = MPathSection("");
	btn_straighta->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_straighta->Text = "Load 'StraightA'.";

	global::Basic->StraightB = MPathSection("");
	btn_straightb->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_straightb->Text = "Load 'StraightB'.";

	global::Basic->TurnU = MPathSection("");
	btn_turnu->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_turnu->Text = "Load 'TurnU'.";

	global::Basic->TurnLA = MPathSection("");
	btn_turnla->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_turnla->Text = "Load 'TurnLA'.";

	global::Basic->TurnLB = MPathSection("");
	btn_turnlb->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_turnlb->Text = "Load 'TurnLB'.";

	global::Basic->TurnTA = MPathSection("");
	btn_turnta->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_turnta->Text = "Load 'TurnTA'.";

	global::Basic->TurnTB = MPathSection("");
	btn_turntb->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_turntb->Text = "Load 'TurnTB'.";

	global::Basic->TurnTC = MPathSection("");
	btn_turntc->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_turntc->Text = "Load 'TurnTC'.";

	global::Basic->TurnX = MPathSection("");
	btn_turnx->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_turnx->Text = "Load 'TurnX'.";

	global::Basic->CornerA = MPathSection("");
	btn_cornera->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_cornera->Text = "Load 'CornerA'.";

	global::Basic->CornerB = MPathSection("");
	btn_cornerb->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_cornerb->Text = "Load 'CornerB'.";

	global::Basic->CornerC = MPathSection("");
	btn_cornerc->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_cornerc->Text = "Load 'CornerC'.";

	global::Basic->CornerD = MPathSection("");
	btn_cornerd->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_cornerd->Text = "Load 'CornerD'.";

	global::Basic->Slope = MPathSection("");
	btn_slope->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_slope->Text = "Load 'Slope'.";

	global::Basic->SlopeStraight = MPathSection("");
	btn_slopestraight->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_slopestraight->Text = "Load 'SlopeStraight'.";

	global::Basic->SlopeStraightL = MPathSection("");
	btn_slopestraight_l->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_slopestraight_l->Text = "Load 'SlopeStraightLeft'.";

	global::Basic->SlopeStraightR = MPathSection("");
	btn_slopestraight_r->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_slopestraight_r->Text = "Load 'SlopeStraightRight'.";

	global::Basic->SlopeMid = MPathSection("");
	btn_slopemid->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_slopemid->Text = "Load 'SlopeMid'.";

	global::Extended->FlatFC = MPathSection("");
	btn_slopemid->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_slopemid->Text = "Load 'FlatFC'.";

	global::Extended->SlopeFC = MPathSection("");
	btn_slopemid->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_slopemid->Text = "Load 'SlopeFC'.";

	global::Extended->SlopeBC = MPathSection("");
	btn_slopemid->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_slopemid->Text = "Load 'SlopeBC'.";

	global::Extended->SlopeTC = MPathSection("");
	btn_slopemid->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_slopemid->Text = "Load 'SlopeTC'.";

	global::Extended->SlopeStraightFC = MPathSection("");
	btn_slopemid->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_slopemid->Text = "Load 'SlopeStraightFC'.";

	global::Extended->SlopeStraightBC = MPathSection("");
	btn_slopemid->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_slopemid->Text = "Load 'SlopeStraightBC'.";

	global::Extended->SlopeStraightTC = MPathSection("");
	btn_slopemid->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_slopemid->Text = "Load 'SlopeStraightTC'.";

	global::Extended->SlopeStraightLFC = MPathSection("");
	btn_slopemid->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_slopemid->Text = "Load 'SlopeStraightLFC'.";

	global::Extended->SlopeStraightLBC = MPathSection("");
	btn_slopemid->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_slopemid->Text = "Load 'SlopeStraightLBC'.";

	global::Extended->SlopeStraightLTC = MPathSection("");
	btn_slopemid->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_slopemid->Text = "Load 'SlopeStraightLTC'.";

	global::Extended->SlopeStraightRFC = MPathSection("");
	btn_slopemid->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_slopemid->Text = "Load 'SlopeStraightRFC'.";

	global::Extended->SlopeStraightRBC = MPathSection("");
	btn_slopemid->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_slopemid->Text = "Load 'SlopeStraightRBC'.";

	global::Extended->SlopeStraightRTC = MPathSection("");
	btn_slopemid->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_slopemid->Text = "Load 'SlopeStraightRTC'.";

	global::Extended->SlopeMidFC = MPathSection("");
	btn_slopemid->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_slopemid->Text = "Load 'SlopeMidFC'.";

	global::Extended->SlopeMidBC = MPathSection("");
	btn_slopemid->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_slopemid->Text = "Load 'SlopeMidBC'.";

	global::Extended->SlopeMidTC = MPathSection("");
	btn_slopemid->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_slopemid->Text = "Load 'SlopeMidTC'.";

	global::Extended->Paving = "";
	btn_slopemid->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_slopemid->Text = "Load 'Paving'.";
}

#define UPDATE(btn, name, name2) if (File::Exists(global::Basic->name.North) && File::Exists(global::Basic->name.North->Replace(".common.ovl", ".unique.ovl"))) { \
	btn->Text = "'" name2 "' loaded."; \
	btn->BackgroundImage = GetResourceImage(IMG_BUTTON_G); \
}

#define UPDATEEXT(btn, name, name2) if (File::Exists(global::Extended->name.North) && File::Exists(global::Extended->name.North->Replace(".common.ovl", ".unique.ovl"))) { \
	btn->Text = "'" name2 "' loaded."; \
	btn->BackgroundImage = GetResourceImage(IMG_BUTTON_G); \
}

#define UPDATEEXT_G(btn, name, name2) UPDATEEXT(btn##_fc, name##FC, name2 "FC") \
	UPDATEEXT(btn##_bc, name##BC, name2 "BC") \
	UPDATEEXT(btn##_tc, name##TC, name2 "TC")

void ExtendedModelsControl::update() {
	UPDATE(btn_slopemid, SlopeMid, "SlopeMid")
	UPDATE(btn_slopestraight_r, SlopeStraightR, "SlopeStraightRight")
	UPDATE(btn_slopestraight_l, SlopeStraightL, "SlopeStraightLeft")
	UPDATE(btn_slopestraight, SlopeStraight, "SlopeStraight")
	UPDATE(btn_slope, Slope, "Slope")
	UPDATE(btn_cornerd, CornerD, "CornerD")
	UPDATE(btn_cornerc, CornerC, "CornerC")
	UPDATE(btn_cornerb, CornerB, "CornerB")
	UPDATE(btn_cornera, CornerA, "CornerA")
	UPDATE(btn_turnx, TurnX, "TurnX")
	UPDATE(btn_turntc, TurnTC, "TurnTC")
	UPDATE(btn_turntb, TurnTB, "TurnTB")
	UPDATE(btn_turnta, TurnTA, "TurnTA")
	UPDATE(btn_turnlb, TurnLB, "TurnLB")
	UPDATE(btn_turnla, TurnLA, "TurnLA")
	UPDATE(btn_turnu, TurnU, "TurnU")
	UPDATE(btn_straightb, StraightB, "StraightB")
	UPDATE(btn_straighta, StraightA, "StraightA")
	UPDATE(btn_flat, Flat, "Flat")

	UPDATEEXT(btn_flat_fc, FlatFC, "FlatFC")

	UPDATEEXT_G(btn_slope, Slope, "Slope")
	UPDATEEXT_G(btn_slope_straight, SlopeStraight, "SlopeStraight")
	UPDATEEXT_G(btn_slope_straight_l, SlopeStraightL, "SlopeStraightL")
	UPDATEEXT_G(btn_slope_straight_r, SlopeStraightR, "SlopeStraightR")
	UPDATEEXT_G(btn_slope_mid, SlopeMid, "SlopeMid")

	if (File::Exists(global::Extended->Paving) && File::Exists(global::Extended->Paving->Replace(".common.ovl", ".unique.ovl"))) {
		btn_paving->Text = "'Paving' loaded.";
		btn_paving->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
	}
}

void ExtendedModelsControl::link_auto_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) 
{
	AutoLoadDialog^ autod = gcnew AutoLoadDialog();

	if (fbd_autoLoad->ShowDialog(this) == ::DialogResult::OK) {
		if (autod->ShowDialog(this) == ::DialogResult::OK) {

			array<String^>^ ovls = Directory::GetFiles(fbd_autoLoad->SelectedPath, "*.common.ovl");

			if (ovls->Length <= 0) {
				MessageBox::Show("Selected folder doesn't contain any OVL files!", "Error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			String^ currFile;

			for (int i = 0; i < ovls->Length; i++) {
				currFile = ovls[i]->Split('\\')[ovls[i]->Split('\\')->Length - 1];

				if (autod->complete())
				{
					/*if (StringContains(currFile, "FlatFC", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->FlatFC = MPathSection(ovls[i]);
						btn_flat_fc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_flat_fc->Text = "'FlatFC' model loaded!";
					}
					else if (StringContains(currFile, "SlopeFC", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->SlopeFC = MPathSection(ovls[i]);
						btn_slope_fc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_fc->Text = "'SlopeFC' model loaded!";
					}
					else if (StringContains(currFile, "SlopeBC", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->SlopeBC = MPathSection(ovls[i]);
						btn_slope_bc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_bc->Text = "'SlopeBC' model loaded!";
					}
					else if (StringContains(currFile, "SlopeTC", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->SlopeTC = MPathSection(ovls[i]);
						btn_slope_tc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_tc->Text = "'SlopeTC' model loaded!";
					}
					else if (StringContains(currFile, "SlopeStraightFC", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->SlopeStraightFC = MPathSection(ovls[i]);
						btn_slope_straight_fc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_straight_fc->Text = "'SlopeStraightFC' model loaded!";
					}
					else if (StringContains(currFile, "SlopeStraightBC", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->SlopeStraightBC = MPathSection(ovls[i]);
						btn_slope_straight_bc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_straight_bc->Text = "'SlopeStraightBC' model loaded!";
					}
					else if (StringContains(currFile, "SlopeStraightTC", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->SlopeStraightTC = MPathSection(ovls[i]);
						btn_slope_straight_tc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_straight_tc->Text = "'SlopeStraightTC' model loaded!";
					}
					else if (StringContains(currFile, "SlopeStraightLFC", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->SlopeStraightLFC = MPathSection(ovls[i]);
						btn_slope_straight_l_fc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_straight_l_fc->Text = "'SlopeStraightLFC' model loaded!";
					}
					else if (StringContains(currFile, "SlopeStraightLBC", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->SlopeStraightLBC = MPathSection(ovls[i]);
						btn_slope_straight_l_bc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_straight_l_bc->Text = "'SlopeStraightLBC' model loaded!";
					}
					else if (StringContains(currFile, "SlopeStraightLTC", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->SlopeStraightLTC = MPathSection(ovls[i]);
						btn_slope_straight_l_bc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_straight_l_bc->Text = "'SlopeStraightLTC' model loaded!";
					}
					else if (StringContains(currFile, "SlopeStraightRFC", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->SlopeStraightRFC = MPathSection(ovls[i]);
						btn_slope_straight_r_fc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_straight_r_fc->Text = "'SlopeStraightRFC' model loaded!";
					}
					else if (StringContains(currFile, "SlopeStraightRBC", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->SlopeStraightRBC = MPathSection(ovls[i]);
						btn_slope_straight_r_bc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_straight_r_bc->Text = "'SlopeStraightRBC' model loaded!";
					}
					else if (StringContains(currFile, "SlopeStraightRTC", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->SlopeStraightRTC = MPathSection(ovls[i]);
						btn_slope_straight_r_tc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_straight_r_tc->Text = "'SlopeStraightRTC' model loaded!";
					}
					else if (StringContains(currFile, "SlopeMidFC", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->SlopeMidFC = MPathSection(ovls[i]);
						btn_slope_mid_fc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_mid_fc->Text = "'SlopeMidFC' model loaded!";
					}
					else if (StringContains(currFile, "SlopeMidBC", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->SlopeMidBC = MPathSection(ovls[i]);
						btn_slope_mid_bc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_mid_bc->Text = "'SlopeMidBC' model loaded!";
					}
					else if (StringContains(currFile, "SlopeMidTC", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->SlopeMidTC = MPathSection(ovls[i]);
						btn_slope_mid_tc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_mid_tc->Text = "'SlopeMidTC' model loaded!";
					}
					else if (StringContains(currFile, "Paving", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->Paving = ovls[i];
						btn_paving->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_paving->Text = "'Paving' model loaded!";
					}*/

					// ----- basic ----- //

					if (StringContains(currFile, "Flat", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->Flat = MPathSection(ovls[i]);
						btn_flat->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_flat->Text = "'Flat' loaded!";
					}
					else if (StringContains(currFile, "StraightA", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->StraightA = MPathSection(ovls[i]);
						btn_straighta->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_straighta->Text = "'StraightA' loaded!";
					}
					else if (StringContains(currFile, "StraightB", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->StraightB = MPathSection(ovls[i]);
						btn_straightb->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_straightb->Text = "'StraightB' loaded!";
					}
					else if (StringContains(currFile, "TurnU", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->TurnU = MPathSection(ovls[i]);
						btn_turnu->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_turnu->Text = "'TurnU' loaded!";
					}
					else if (StringContains(currFile, "TurnLA", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->TurnLA = MPathSection(ovls[i]);
						btn_turnla->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_turnla->Text = "'TurnLA' loaded!";
					}
					else if (StringContains(currFile, "TurnLB", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->TurnLB = MPathSection(ovls[i]);
						btn_turnlb->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_turnlb->Text = "'TurnLB' loaded!";
					}
					else if (StringContains(currFile, "TurnTA", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->TurnTA = MPathSection(ovls[i]);
						btn_turnta->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_turnta->Text = "'TurnTA' loaded!";
					}
					else if (StringContains(currFile, "TurnTB", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->TurnTB = MPathSection(ovls[i]);
						btn_turntb->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_turntb->Text = "'TurnTB' loaded!";
					}
					else if (StringContains(currFile, "TurnTC", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->TurnTC = MPathSection(ovls[i]);
						btn_turntc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_turntc->Text = "'TurnTC' loaded!";
					}
					else if (StringContains(currFile, "TurnX", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->TurnX = MPathSection(ovls[i]);
						btn_turnx->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_turnx->Text = "'TurnX' loaded!";
					}
					else if (StringContains(currFile, "CornerA", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->CornerA = MPathSection(ovls[i]);
						btn_cornera->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_cornera->Text = "'CornerA' loaded!";
					}
					else if (StringContains(currFile, "CornerB", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->CornerB = MPathSection(ovls[i]);
						btn_cornerb->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_cornerb->Text = "'CornerB' loaded!";
					}
					else if (StringContains(currFile, "CornerC", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->CornerC = MPathSection(ovls[i]);
						btn_cornerc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_cornerc->Text = "'CornerC' loaded!";
					}
					else if (StringContains(currFile, "CornerD", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->CornerD = MPathSection(ovls[i]);
						btn_cornerd->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_cornerd->Text = "'CornerD' loaded!";
					}
					else if (StringContains(currFile, "SlopeStraightRight", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->SlopeStraightR = MPathSection(ovls[i]);
						btn_slopestraight_r->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slopestraight_r->Text = "'SlopeStraightRight' loaded!";
					}
					else if (StringContains(currFile, "SlopeStraightLeft", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->SlopeStraightL = MPathSection(ovls[i]);
						btn_slopestraight_l->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slopestraight_l->Text = "'SlopeStraightLeft' loaded!";
					}
					else if (StringContains(currFile, "SlopeStraight", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->SlopeStraight = MPathSection(ovls[i]);
						btn_slopestraight->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slopestraight->Text = "'SlopeStraight' loaded!";
					}
					else if (StringContains(currFile, "SlopeMid", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->SlopeMid = MPathSection(ovls[i]);
						btn_slopemid->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slopemid->Text = "'SlopeMid' loaded!";
					}

					else if (StringContains(currFile, "Slope", System::StringComparison::CurrentCultureIgnoreCase) &&
						!StringContains(currFile, "straight", System::StringComparison::CurrentCultureIgnoreCase) &&
						!StringContains(currFile, "left", System::StringComparison::CurrentCultureIgnoreCase) &&
						!StringContains(currFile, "right", System::StringComparison::CurrentCultureIgnoreCase) &&
						!StringContains(currFile, "mid", System::StringComparison::CurrentCultureIgnoreCase) &&
						!StringContains(currFile, "fc", System::StringComparison::CurrentCultureIgnoreCase) &&
						!StringContains(currFile, "bc", System::StringComparison::CurrentCultureIgnoreCase) &&
						!StringContains(currFile, "tc", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->Slope = MPathSection(ovls[i]);
						btn_slope->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope->Text = "'Slope' loaded!";
					}
				}

				if (autod->underlined())
				{
					/*if (StringContains(currFile, "Flat_F_C", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->FlatFC = MPathSection(ovls[i]);
						btn_flat_fc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_flat_fc->Text = "'FlatFC' loaded!";
					}
					else if (StringContains(currFile, "Slope_F_C", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->SlopeFC = MPathSection(ovls[i]);
						btn_slope_fc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_fc->Text = "'SlopeFC' loaded!";
					}
					else if (StringContains(currFile, "Slope_B_C", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->SlopeBC = MPathSection(ovls[i]);
						btn_slope_bc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_bc->Text = "'SlopeBC' loaded!";
					}
					else if (StringContains(currFile, "Slope_T_C", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->SlopeTC = MPathSection(ovls[i]);
						btn_slope_tc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_tc->Text = "'SlopeTC' loaded!";
					}
					else if (StringContains(currFile, "Slope_Straight_F_C", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->SlopeStraightFC = MPathSection(ovls[i]);
						btn_slope_straight_fc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_straight_fc->Text = "'SlopeStraightFC' loaded!";
					}
					else if (StringContains(currFile, "Slope_Straight_B_C", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->SlopeStraightBC = MPathSection(ovls[i]);
						btn_slope_straight_bc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_straight_bc->Text = "'SlopeStraightBC' loaded!";
					}
					else if (StringContains(currFile, "Slope_Straight_T_C", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->SlopeStraightTC = MPathSection(ovls[i]);
						btn_slope_straight_tc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_straight_tc->Text = "'SlopeStraightTC' loaded!";
					}
					else if (StringContains(currFile, "Slope_Straight_L_F_C", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->SlopeStraightLFC = MPathSection(ovls[i]);
						btn_slope_straight_l_fc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_straight_l_fc->Text = "'SlopeStraightLFC' loaded!";
					}
					else if (StringContains(currFile, "Slope_Straight_L_B_C", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->SlopeStraightLBC = MPathSection(ovls[i]);
						btn_slope_straight_l_bc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_straight_l_bc->Text = "'SlopeStraightLBC' loaded!";
					}
					else if (StringContains(currFile, "Slope_Straight_L_T_C", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->SlopeStraightLTC = MPathSection(ovls[i]);
						btn_slope_straight_l_bc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_straight_l_bc->Text = "'SlopeStraightLTC' loaded!";
					}
					else if (StringContains(currFile, "Slope_Straight_R_F_C", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->SlopeStraightRFC = MPathSection(ovls[i]);
						btn_slope_straight_r_fc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_straight_r_fc->Text = "'SlopeStraightRFC' loaded!";
					}
					else if (StringContains(currFile, "Slope_Straight_R_B_C", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->SlopeStraightRBC = MPathSection(ovls[i]);
						btn_slope_straight_r_bc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_straight_r_bc->Text = "'SlopeStraightRBC' loaded!";
					}
					else if (StringContains(currFile, "Slope_Straight_R_T_C", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->SlopeStraightRTC = MPathSection(ovls[i]);
						btn_slope_straight_r_tc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_straight_r_tc->Text = "'SlopeStraightRTC' loaded!";
					}
					else if (StringContains(currFile, "Slope_Mid_F_C", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->SlopeMidFC = MPathSection(ovls[i]);
						btn_slope_mid_fc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_mid_fc->Text = "'SlopeMidFC' loaded!";
					}
					else if (StringContains(currFile, "Slope_Mid_B_C", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->SlopeMidBC = MPathSection(ovls[i]);
						btn_slope_mid_bc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_mid_bc->Text = "'SlopeMidBC' loaded!";
					}
					else if (StringContains(currFile, "Slope_Mid_T_C", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->SlopeMidTC = MPathSection(ovls[i]);
						btn_slope_mid_tc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_mid_tc->Text = "'SlopeMidTC' loaded!";
					}
					else if (StringContains(currFile, "Paving", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->Paving = ovls[i];
						btn_paving->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_paving->Text = "'Paving' loaded!";
					}*/

					// ---- basic ---- //

					if (StringContains(currFile, "Straight_A", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->StraightA = MPathSection(ovls[i]);
						btn_straighta->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_straighta->Text = "'StraightA' loaded!";
					}
					else if (StringContains(currFile, "Straight_B", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->StraightB = MPathSection(ovls[i]);
						btn_straightb->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_straightb->Text = "'StraightB' loaded!";
					}
					else if (StringContains(currFile, "Turn_U", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->TurnU = MPathSection(ovls[i]);
						btn_turnu->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_turnu->Text = "'TurnU' loaded!";
					}
					else if (StringContains(currFile, "Turn_L_A", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->TurnLA = MPathSection(ovls[i]);
						btn_turnla->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_turnla->Text = "'TurnLA' loaded!";
					}
					else if (StringContains(currFile, "Turn_L_B", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->TurnLB = MPathSection(ovls[i]);
						btn_turnlb->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_turnlb->Text = "'TurnLB' loaded!";
					}
					else if (StringContains(currFile, "Turn_T_A", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->TurnTA = MPathSection(ovls[i]);
						btn_turnta->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_turnta->Text = "'TurnTA' loaded!";
					}
					else if (StringContains(currFile, "Turn_T_B", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->TurnTB = MPathSection(ovls[i]);
						btn_turntb->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_turntb->Text = "'TurnTB' loaded!";
					}
					else if (StringContains(currFile, "Turn_T_C", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->TurnTC = MPathSection(ovls[i]);
						btn_turntc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_turntc->Text = "'TurnTC' loaded!";
					}
					else if (StringContains(currFile, "Turn_X", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->TurnX = MPathSection(ovls[i]);
						btn_turnx->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_turnx->Text = "'TurnX' loaded!";
					}
					else if (StringContains(currFile, "Corner_A", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->CornerA = MPathSection(ovls[i]);
						btn_cornera->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_cornera->Text = "'CornerA' loaded!";
					}
					else if (StringContains(currFile, "Corner_B", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->CornerB = MPathSection(ovls[i]);
						btn_cornerb->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_cornerb->Text = "'CornerB' loaded!";
					}
					else if (StringContains(currFile, "Corner_C", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->CornerC = MPathSection(ovls[i]);
						btn_cornerc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_cornerc->Text = "'CornerC' loaded!";
					}
					else if (StringContains(currFile, "Corner_D", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->CornerD = MPathSection(ovls[i]);
						btn_cornerd->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_cornerd->Text = "'CornerD' loaded!";
					}
					else if (StringContains(currFile, "Slope_Straight_Right", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->SlopeStraightR = MPathSection(ovls[i]);
						btn_slopestraight_r->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slopestraight_r->Text = "'SlopeStraightRight' loaded!";
					}
					else if (StringContains(currFile, "Slope_Straight_Left", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->SlopeStraightL = MPathSection(ovls[i]);
						btn_slopestraight_l->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slopestraight_l->Text = "'SlopeStraightLeft' loaded!";
					}
					else if (StringContains(currFile, "Slope_Straight", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->SlopeStraight = MPathSection(ovls[i]);
						btn_slopestraight->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slopestraight->Text = "'SlopeStraight' loaded!";
					}
					else if (StringContains(currFile, "Slope_Mid", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->SlopeMid = MPathSection(ovls[i]);
						btn_slopemid->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slopemid->Text = "'SlopeMid' loaded!";
					}

					else if (StringContains(currFile, "Slope", System::StringComparison::CurrentCultureIgnoreCase) &&
						!StringContains(currFile, "straight", System::StringComparison::CurrentCultureIgnoreCase) &&
						!StringContains(currFile, "left", System::StringComparison::CurrentCultureIgnoreCase) &&
						!StringContains(currFile, "right", System::StringComparison::CurrentCultureIgnoreCase) &&
						!StringContains(currFile, "mid", System::StringComparison::CurrentCultureIgnoreCase) &&
						!StringContains(currFile, "fc", System::StringComparison::CurrentCultureIgnoreCase) &&
						!StringContains(currFile, "bc", System::StringComparison::CurrentCultureIgnoreCase) &&
						!StringContains(currFile, "tc", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->Slope = MPathSection(ovls[i]);
						btn_slope->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope->Text = "'Slope' loaded!";
					}
				}

				if (autod->separated())
				{

					/*if (StringContains(currFile, "Flat-F-C", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->FlatFC = MPathSection(ovls[i]);
						btn_flat_fc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_flat_fc->Text = "'FlatFC' loaded!";
					}
					else if (StringContains(currFile, "Slope-F-C", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->SlopeFC = MPathSection(ovls[i]);
						btn_slope_fc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_fc->Text = "'SlopeFC' loaded!";
					}
					else if (StringContains(currFile, "Slope-B-C", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->SlopeBC = MPathSection(ovls[i]);
						btn_slope_bc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_bc->Text = "'SlopeBC' loaded!";
					}
					else if (StringContains(currFile, "Slope-T-C", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->SlopeTC = MPathSection(ovls[i]);
						btn_slope_tc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_tc->Text = "'SlopeTC' loaded!";
					}
					else if (StringContains(currFile, "Slope-Straight-F-C", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->SlopeStraightFC = MPathSection(ovls[i]);
						btn_slope_straight_fc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_straight_fc->Text = "'SlopeStraightFC' loaded!";
					}
					else if (StringContains(currFile, "Slope-Straight-B-C", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->SlopeStraightBC = MPathSection(ovls[i]);
						btn_slope_straight_bc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_straight_bc->Text = "'SlopeStraightBC' loaded!";
					}
					else if (StringContains(currFile, "Slope-Straight-T-C", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->SlopeStraightTC = MPathSection(ovls[i]);
						btn_slope_straight_tc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_straight_tc->Text = "'SlopeStraightTC' loaded!";
					}
					else if (StringContains(currFile, "Slope-Straight-L-F-C", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->SlopeStraightLFC = MPathSection(ovls[i]);
						btn_slope_straight_l_fc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_straight_l_fc->Text = "'SlopeStraightLFC' loaded!";
					}
					else if (StringContains(currFile, "Slope-Straight-L-B-C", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->SlopeStraightLBC = MPathSection(ovls[i]);
						btn_slope_straight_l_bc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_straight_l_bc->Text = "'SlopeStraightLBC' loaded!";
					}
					else if (StringContains(currFile, "Slope-Straight-L-T-C", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->SlopeStraightLTC = MPathSection(ovls[i]);
						btn_slope_straight_l_bc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_straight_l_bc->Text = "'SlopeStraightLTC' loaded!";
					}
					else if (StringContains(currFile, "Slope-Straight-R-F-C", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->SlopeStraightRFC = MPathSection(ovls[i]);
						btn_slope_straight_r_fc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_straight_r_fc->Text = "'SlopeStraightRFC' loaded!";
					}
					else if (StringContains(currFile, "Slope-Straight-R-B-C", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->SlopeStraightRBC = MPathSection(ovls[i]);
						btn_slope_straight_r_bc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_straight_r_bc->Text = "'SlopeStraightRBC' loaded!";
					}
					else if (StringContains(currFile, "Slope-Straight-R-T-C", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->SlopeStraightRTC = MPathSection(ovls[i]);
						btn_slope_straight_r_tc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_straight_r_tc->Text = "'SlopeStraightRTC' loaded!";
					}
					else if (StringContains(currFile, "Slope-Mid-F-C", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->SlopeMidFC = MPathSection(ovls[i]);
						btn_slope_mid_fc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_mid_fc->Text = "'SlopeMidFC' loaded!";
					}
					else if (StringContains(currFile, "Slope-Mid-B-C", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->SlopeMidBC = MPathSection(ovls[i]);
						btn_slope_mid_bc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_mid_bc->Text = "'SlopeMidBC' loaded!";
					}
					else if (StringContains(currFile, "Slope-Mid-T-C", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->SlopeMidTC = MPathSection(ovls[i]);
						btn_slope_mid_tc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_mid_tc->Text = "'SlopeMidTC' loaded!";
					}
					else if (StringContains(currFile, "Paving", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Extended->Paving = ovls[i];
						btn_paving->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_paving->Text = "'Paving' loaded!";
					}*/

					// ---- basic ---- //

					if (StringContains(currFile, "Straight-A", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->StraightA = MPathSection(ovls[i]);
						btn_straighta->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_straighta->Text = "'StraightA' loaded!";
					}
					else if (StringContains(currFile, "Straight-B", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->StraightB = MPathSection(ovls[i]);
						btn_straightb->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_straightb->Text = "'StraightB' loaded!";
					}
					else if (StringContains(currFile, "Turn-U", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->TurnU = MPathSection(ovls[i]);
						btn_turnu->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_turnu->Text = "'TurnU' loaded!";
					}
					else if (StringContains(currFile, "Turn-L-A", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->TurnLA = MPathSection(ovls[i]);
						btn_turnla->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_turnla->Text = "'TurnLA' loaded!";
					}
					else if (StringContains(currFile, "Turn-L-B", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->TurnLB = MPathSection(ovls[i]);
						btn_turnlb->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_turnlb->Text = "'TurnLB' loaded!";
					}
					else if (StringContains(currFile, "Turn-T-A", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->TurnTA = MPathSection(ovls[i]);
						btn_turnta->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_turnta->Text = "'TurnTA' loaded!";
					}
					else if (StringContains(currFile, "Turn-T-B", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->TurnTB = MPathSection(ovls[i]);
						btn_turntb->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_turntb->Text = "'TurnTB' loaded!";
					}
					else if (StringContains(currFile, "Turn-T-C", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->TurnTC = MPathSection(ovls[i]);
						btn_turntc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_turntc->Text = "'TurnTC' loaded!";
					}
					else if (StringContains(currFile, "Turn-X", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->TurnX = MPathSection(ovls[i]);
						btn_turnx->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_turnx->Text = "'TurnX' loaded!";
					}
					else if (StringContains(currFile, "Corner-A", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->CornerA = MPathSection(ovls[i]);
						btn_cornera->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_cornera->Text = "'CornerA' loaded!";
					}
					else if (StringContains(currFile, "Corner-B", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->CornerB = MPathSection(ovls[i]);
						btn_cornerb->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_cornerb->Text = "'CornerB' loaded!";
					}
					else if (StringContains(currFile, "Corner-C", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->CornerC = MPathSection(ovls[i]);
						btn_cornerc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_cornerc->Text = "'CornerC' loaded!";
					}
					else if (StringContains(currFile, "Corner-D", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->CornerD = MPathSection(ovls[i]);
						btn_cornerd->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_cornerd->Text = "'CornerD' loaded!";
					}
					else if (StringContains(currFile, "Slope-Straight-Right", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->SlopeStraightR = MPathSection(ovls[i]);
						btn_slopestraight_r->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slopestraight_r->Text = "'SlopeStraightRight' loaded!";
					}
					else if (StringContains(currFile, "Slope-Straight-Left", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->SlopeStraightL = MPathSection(ovls[i]);
						btn_slopestraight_l->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slopestraight_l->Text = "'SlopeStraightLeft' loaded!";
					}
					else if (StringContains(currFile, "Slope-Straight", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->SlopeStraight = MPathSection(ovls[i]);
						btn_slopestraight->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slopestraight->Text = "'SlopeStraight' loaded!";
					}
					else if (StringContains(currFile, "Slope-Mid", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->SlopeMid = MPathSection(ovls[i]);
						btn_slopemid->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slopemid->Text = "'SlopeMid' loaded!";
					}

					// --- extended --- //

					
					else if (StringContains(currFile, "Slope", System::StringComparison::CurrentCultureIgnoreCase) &&
						!StringContains(currFile, "straight", System::StringComparison::CurrentCultureIgnoreCase) &&
						!StringContains(currFile, "left", System::StringComparison::CurrentCultureIgnoreCase) &&
						!StringContains(currFile, "right", System::StringComparison::CurrentCultureIgnoreCase) &&
						!StringContains(currFile, "mid", System::StringComparison::CurrentCultureIgnoreCase) &&
						!StringContains(currFile, "fc", System::StringComparison::CurrentCultureIgnoreCase) &&
						!StringContains(currFile, "bc", System::StringComparison::CurrentCultureIgnoreCase) &&
						!StringContains(currFile, "tc", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Basic->Slope = MPathSection(ovls[i]);
						btn_slope->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope->Text = "'Slope' loaded!";
					}
				}
			}
		}
	}

	MainWindow::activeWindow->Ready = global::Basic->filled();
}

void ExtendedModelsControl::btn_flat_Click(System::Object^  sender, System::EventArgs^  e) {
	if (section_ofds[PS_FLAT]->ShowDialog(this) ==::DialogResult::OK) {
		if (File::Exists(section_ofds[PS_FLAT]->FileName->Replace(".common.ovl", ".unique.ovl"))) {
			global::Basic->Flat = MPathSection(section_ofds[PS_FLAT]->FileName);

			btn_flat->Text = "'Flat' loaded.";
			btn_flat->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
		}
		else {
			btn_flat->Text = "Load 'Flat'.";
			btn_flat->BackgroundImage = GetResourceImage(IMG_BUTTON);
			global::Basic->Flat = MPathSection("");
			MessageBox::Show("Couldn't locate matching unique OVL for path model.", "Load model error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	MainWindow::activeWindow->Ready = global::Basic->filled();
}

void ExtendedModelsControl::btn_straighta_Click(System::Object^  sender, System::EventArgs^  e) {
	if (section_ofds[PS_STRAIGHT_A]->ShowDialog(this) ==::DialogResult::OK) {
		if (File::Exists(section_ofds[PS_STRAIGHT_A]->FileName->Replace(".common.ovl", ".unique.ovl"))) {
			global::Basic->StraightA = MPathSection(section_ofds[PS_STRAIGHT_A]->FileName);

			btn_straighta->Text = "'StraightA' loaded.";
			btn_straighta->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
		}
		else {
			btn_straighta->Text = "Load 'StraightA'.";
			btn_straighta->BackgroundImage = GetResourceImage(IMG_BUTTON);
			global::Basic->StraightA = MPathSection("");
			MessageBox::Show("Couldn't locate matching unique OVL for path model.", "Load model error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	MainWindow::activeWindow->Ready = global::Basic->filled();
}

void ExtendedModelsControl::btn_straightb_Click(System::Object^  sender, System::EventArgs^  e) {
	if (section_ofds[PS_STRAIGHT_B]->ShowDialog(this) ==::DialogResult::OK) {
		if (File::Exists(section_ofds[PS_STRAIGHT_B]->FileName->Replace(".common.ovl", ".unique.ovl"))) {
			global::Basic->StraightB = MPathSection(section_ofds[PS_STRAIGHT_B]->FileName);

			btn_straightb->Text = "'StraightB' loaded.";
			btn_straightb->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
		}
		else {
			btn_straightb->Text = "Load 'StraightB'.";
			btn_straightb->BackgroundImage = GetResourceImage(IMG_BUTTON);
			global::Basic->StraightB = MPathSection("");
			MessageBox::Show("Couldn't locate matching unique OVL for path model.", "Load model error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	MainWindow::activeWindow->Ready = global::Basic->filled();
}

void ExtendedModelsControl::btn_turnu_Click(System::Object^  sender, System::EventArgs^  e) {
	if (section_ofds[PS_TURN_U]->ShowDialog(this) ==::DialogResult::OK) {
		if (File::Exists(section_ofds[PS_TURN_U]->FileName->Replace(".common.ovl", ".unique.ovl"))) {
			global::Basic->TurnU = MPathSection(section_ofds[PS_TURN_U]->FileName);

			btn_turnu->Text = "'TurnU' loaded.";
			btn_turnu->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
		}
		else {
			btn_turnu->Text = "Load 'TurnU'.";
			btn_turnu->BackgroundImage = GetResourceImage(IMG_BUTTON);
			global::Basic->TurnU = MPathSection("");
			MessageBox::Show("Couldn't locate matching unique OVL for path model.", "Load model error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	MainWindow::activeWindow->Ready = global::Basic->filled();
}

void ExtendedModelsControl::btn_turnla_Click(System::Object^  sender, System::EventArgs^  e) {
	if (section_ofds[PS_TURN_LA]->ShowDialog(this) ==::DialogResult::OK) {
		if (File::Exists(section_ofds[PS_TURN_LA]->FileName->Replace(".common.ovl", ".unique.ovl"))) {
			global::Basic->TurnLA = MPathSection(section_ofds[PS_TURN_LA]->FileName);

			btn_turnla->Text = "'TurnLA' loaded.";
			btn_turnla->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
		}
		else {
			btn_turnla->Text = "Load 'TurnLA'.";
			btn_turnla->BackgroundImage = GetResourceImage(IMG_BUTTON);
			global::Basic->TurnLA = MPathSection("");
			MessageBox::Show("Couldn't locate matching unique OVL for path model.", "Load model error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	MainWindow::activeWindow->Ready = global::Basic->filled();
}

void ExtendedModelsControl::btn_turnlb_Click(System::Object^  sender, System::EventArgs^  e) {
	if (section_ofds[PS_TURN_LB]->ShowDialog(this) ==::DialogResult::OK) {
		if (File::Exists(section_ofds[PS_TURN_LB]->FileName->Replace(".common.ovl", ".unique.ovl"))) {
			global::Basic->TurnLB = MPathSection(section_ofds[PS_TURN_LB]->FileName);

			btn_turnlb->Text = "'TurnLB' loaded.";
			btn_turnlb->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
		}
		else {
			btn_turnlb->Text = "Load 'TurnLB'.";
			btn_turnlb->BackgroundImage = GetResourceImage(IMG_BUTTON);
			global::Basic->TurnLB = MPathSection("");
			MessageBox::Show("Couldn't locate matching unique OVL for path model.", "Load model error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	MainWindow::activeWindow->Ready = global::Basic->filled();
}

void ExtendedModelsControl::btn_turnta_Click(System::Object^  sender, System::EventArgs^  e) {
	if (section_ofds[PS_TURN_TA]->ShowDialog(this) ==::DialogResult::OK) {
		if (File::Exists(section_ofds[PS_TURN_TA]->FileName->Replace(".common.ovl", ".unique.ovl"))) {
			global::Basic->TurnTA = MPathSection(section_ofds[PS_TURN_TA]->FileName);

			btn_turnta->Text = "'TurnTA' loaded.";
			btn_turnta->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
		}
		else {
			btn_turnta->Text = "Load 'TurnTA'.";
			btn_turnta->BackgroundImage = GetResourceImage(IMG_BUTTON);
			global::Basic->TurnTA = MPathSection("");
			MessageBox::Show("Couldn't locate matching unique OVL for path model.", "Load model error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	MainWindow::activeWindow->Ready = global::Basic->filled();
}

void ExtendedModelsControl::btn_turntb_Click(System::Object^  sender, System::EventArgs^  e) {
	if (section_ofds[PS_TURN_TB]->ShowDialog(this) ==::DialogResult::OK) {
		if (File::Exists(section_ofds[PS_TURN_TB]->FileName->Replace(".common.ovl", ".unique.ovl"))) {
			global::Basic->TurnTB = MPathSection(section_ofds[PS_TURN_TB]->FileName);

			btn_turntb->Text = "'TurnTB' loaded.";
			btn_turntb->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
		}
		else {
			btn_turntb->Text = "Load 'TurnTB'.";
			btn_turntb->BackgroundImage = GetResourceImage(IMG_BUTTON);
			global::Basic->TurnTB = MPathSection("");
			MessageBox::Show("Couldn't locate matching unique OVL for path model.", "Load model error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	MainWindow::activeWindow->Ready = global::Basic->filled();
}

void ExtendedModelsControl::btn_turntc_Click(System::Object^  sender, System::EventArgs^  e) {
	if (section_ofds[PS_TURN_TC]->ShowDialog(this) ==::DialogResult::OK) {
		if (File::Exists(section_ofds[PS_TURN_TC]->FileName->Replace(".common.ovl", ".unique.ovl"))) {
			global::Basic->TurnTC = MPathSection(section_ofds[PS_TURN_TC]->FileName);

			btn_turntc->Text = "'TurnTC' loaded.";
			btn_turntc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
		}
		else {
			btn_turntc->Text = "Load 'TurnTC'.";
			btn_turntc->BackgroundImage = GetResourceImage(IMG_BUTTON);
			global::Basic->TurnTC = MPathSection("");
			MessageBox::Show("Couldn't locate matching unique OVL for path model.", "Load model error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	MainWindow::activeWindow->Ready = global::Basic->filled();
}

void ExtendedModelsControl::btn_turnx_Click(System::Object^  sender, System::EventArgs^  e) {
	if (section_ofds[PS_TURN_X]->ShowDialog(this) ==::DialogResult::OK) {
		if (File::Exists(section_ofds[PS_TURN_X]->FileName->Replace(".common.ovl", ".unique.ovl"))) {
			global::Basic->TurnX = MPathSection(section_ofds[PS_TURN_X]->FileName);

			btn_turnx->Text = "'TurnX' loaded.";
			btn_turnx->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
		}
		else {
			btn_turnx->Text = "Load 'TurnX'.";
			btn_turnx->BackgroundImage = GetResourceImage(IMG_BUTTON);
			global::Basic->TurnX = MPathSection("");
			MessageBox::Show("Couldn't locate matching unique OVL for path model.", "Load model error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	MainWindow::activeWindow->Ready = global::Basic->filled();
}

void ExtendedModelsControl::btn_cornera_Click(System::Object^  sender, System::EventArgs^  e) {
	if (section_ofds[PS_CORNER_A]->ShowDialog(this) ==::DialogResult::OK) {
		if (File::Exists(section_ofds[PS_CORNER_A]->FileName->Replace(".common.ovl", ".unique.ovl"))) {
			global::Basic->CornerA = MPathSection(section_ofds[PS_CORNER_A]->FileName);

			btn_cornera->Text = "'CornerA' loaded.";
			btn_cornera->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
		}
		else {
			btn_cornera->Text = "Load 'CornerA'.";
			btn_cornera->BackgroundImage = GetResourceImage(IMG_BUTTON);
			global::Basic->CornerA = MPathSection("");
			MessageBox::Show("Couldn't locate matching unique OVL for path model.", "Load model error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	MainWindow::activeWindow->Ready = global::Basic->filled();
}

void ExtendedModelsControl::btn_cornerb_Click(System::Object^  sender, System::EventArgs^  e) {
	if (section_ofds[PS_CORNER_B]->ShowDialog(this) ==::DialogResult::OK) {
		if (File::Exists(section_ofds[PS_CORNER_B]->FileName->Replace(".common.ovl", ".unique.ovl"))) {
			global::Basic->CornerB = MPathSection(section_ofds[PS_CORNER_B]->FileName);

			btn_cornerb->Text = "'CornerB' loaded.";
			btn_cornerb->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
		}
		else {
			btn_cornerb->Text = "Load 'CornerB'.";
			btn_cornerb->BackgroundImage = GetResourceImage(IMG_BUTTON);
			global::Basic->CornerB = MPathSection("");
			MessageBox::Show("Couldn't locate matching unique OVL for path model.", "Load model error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	MainWindow::activeWindow->Ready = global::Basic->filled();
}

void ExtendedModelsControl::btn_cornerc_Click(System::Object^  sender, System::EventArgs^  e) {
	if (section_ofds[PS_CORNER_C]->ShowDialog(this) ==::DialogResult::OK) {
		if (File::Exists(section_ofds[PS_CORNER_C]->FileName->Replace(".common.ovl", ".unique.ovl"))) {
			global::Basic->CornerC = MPathSection(section_ofds[PS_CORNER_C]->FileName);

			btn_cornerc->Text = "'CornerC' loaded.";
			btn_cornerc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
		}
		else {
			btn_cornerc->Text = "Load 'CornerC'.";
			btn_cornerc->BackgroundImage = GetResourceImage(IMG_BUTTON);
			global::Basic->CornerC = MPathSection("");
			MessageBox::Show("Couldn't locate matching unique OVL for path model.", "Load model error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	MainWindow::activeWindow->Ready = global::Basic->filled();
}

void ExtendedModelsControl::btn_cornerd_Click(System::Object^  sender, System::EventArgs^  e) {
	if (section_ofds[PS_CORNER_D]->ShowDialog(this) ==::DialogResult::OK) {
		if (File::Exists(section_ofds[PS_CORNER_D]->FileName->Replace(".common.ovl", ".unique.ovl"))) {
			global::Basic->CornerD = MPathSection(section_ofds[PS_CORNER_D]->FileName);

			btn_cornerd->Text = "'CornerD' loaded.";
			btn_cornerd->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
		}
		else {
			btn_cornerd->Text = "Load 'CornerD'.";
			btn_cornerd->BackgroundImage = GetResourceImage(IMG_BUTTON);
			global::Basic->CornerD = MPathSection("");
			MessageBox::Show("Couldn't locate matching unique OVL for path model.", "Load model error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	MainWindow::activeWindow->Ready = global::Basic->filled();
}

void ExtendedModelsControl::btn_slope_Click(System::Object^  sender, System::EventArgs^  e) {
	if (section_ofds[PS_SLOPE]->ShowDialog(this) ==::DialogResult::OK) {
		if (File::Exists(section_ofds[PS_SLOPE]->FileName->Replace(".common.ovl", ".unique.ovl"))) {
			global::Basic->Slope = MPathSection(section_ofds[PS_SLOPE]->FileName);

			btn_slope->Text = "'Slope' loaded.";
			btn_slope->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
		}
		else {
			btn_slope->Text = "Load 'Slope'.";
			btn_slope->BackgroundImage = GetResourceImage(IMG_BUTTON);
			global::Basic->Slope = MPathSection("");
			MessageBox::Show("Couldn't locate matching unique OVL for path model.", "Load model error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	MainWindow::activeWindow->Ready = global::Basic->filled();
}

void ExtendedModelsControl::btn_slopestraight_Click(System::Object^  sender, System::EventArgs^  e) {
	if (section_ofds[PS_SLOPE_STRAIGHT]->ShowDialog(this) ==::DialogResult::OK) {
		if (File::Exists(section_ofds[PS_SLOPE_STRAIGHT]->FileName->Replace(".common.ovl", ".unique.ovl"))) {
			global::Basic->SlopeStraight = MPathSection(section_ofds[PS_SLOPE_STRAIGHT]->FileName);

			btn_slopestraight->Text = "'SlopeStraight' loaded.";
			btn_slopestraight->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
		}
		else {
			btn_slopestraight->Text = "Load 'SlopeStraight'.";
			btn_slopestraight->BackgroundImage = GetResourceImage(IMG_BUTTON);
			global::Basic->SlopeStraight = MPathSection("");
			MessageBox::Show("Couldn't locate matching unique OVL for path model.", "Load model error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	MainWindow::activeWindow->Ready = global::Basic->filled();
}

void ExtendedModelsControl::btn_slopestraight_l_Click(System::Object^  sender, System::EventArgs^  e) {
	if (section_ofds[PS_SLOPE_STRAIGHT_L]->ShowDialog(this) ==::DialogResult::OK) {
		if (File::Exists(section_ofds[PS_SLOPE_STRAIGHT_L]->FileName->Replace(".common.ovl", ".unique.ovl"))) {
			global::Basic->SlopeStraightL = MPathSection(section_ofds[PS_SLOPE_STRAIGHT_L]->FileName);

			btn_slopestraight_l->Text = "'SlopeStraightLeft' loaded.";
			btn_slopestraight_l->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
		}
		else {
			btn_slopestraight_l->Text = "Load 'SlopeStraightLeft'.";
			btn_slopestraight_l->BackgroundImage = GetResourceImage(IMG_BUTTON);
			global::Basic->SlopeStraightL = MPathSection("");
			MessageBox::Show("Couldn't locate matching unique OVL for path model.", "Load model error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	MainWindow::activeWindow->Ready = global::Basic->filled();
}

void ExtendedModelsControl::btn_slopestraight_r_Click(System::Object^  sender, System::EventArgs^  e) {
	if (section_ofds[PS_SLOPE_STRAIGHT_R]->ShowDialog(this) ==::DialogResult::OK) {
		if (File::Exists(section_ofds[PS_SLOPE_STRAIGHT_R]->FileName->Replace(".common.ovl", ".unique.ovl"))) {
			global::Basic->SlopeStraightR = MPathSection(section_ofds[PS_SLOPE_STRAIGHT_R]->FileName);

			btn_slopestraight_r->Text = "'SlopeStraightRight' loaded.";
			btn_slopestraight_r->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
		}
		else {
			btn_slopestraight_r->Text = "Load 'SlopeStraightRight'.";
			btn_slopestraight_r->BackgroundImage = GetResourceImage(IMG_BUTTON);
			global::Basic->SlopeStraightR = MPathSection("");
			MessageBox::Show("Couldn't locate matching unique OVL for path model.", "Load model error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	MainWindow::activeWindow->Ready = global::Basic->filled();
}

void ExtendedModelsControl::btn_slopemid_Click(System::Object^  sender, System::EventArgs^  e) {
	if (section_ofds[PS_SLOPE_MID]->ShowDialog(this) ==::DialogResult::OK) {
		if (File::Exists(section_ofds[PS_SLOPE_MID]->FileName->Replace(".common.ovl", ".unique.ovl"))) {
			global::Basic->SlopeMid = MPathSection(section_ofds[PS_SLOPE_MID]->FileName);

			btn_slopemid->Text = "'SlopeMid' loaded.";
			btn_slopemid->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
		}
		else {
			btn_slopemid->Text = "Load 'SlopeMid'.";
			btn_slopemid->BackgroundImage = GetResourceImage(IMG_BUTTON);
			global::Basic->SlopeMid = MPathSection("");
			MessageBox::Show("Couldn't locate matching unique OVL for path model.", "Load model error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	MainWindow::activeWindow->Ready = global::Basic->filled();
}

void ExtendedModelsControl::btn_flat_fc_Click(System::Object^  sender, System::EventArgs^  e) {
	if (section_ofds[PS_FLAT_FC]->ShowDialog(this) ==::DialogResult::OK) {
		if (File::Exists(section_ofds[PS_FLAT_FC]->FileName->Replace(".common.ovl", ".unique.ovl"))) {
			global::Extended->FlatFC = MPathSection(section_ofds[PS_FLAT_FC]->FileName);

			btn_flat_fc->Text = "'FlatFC' loaded.";
			btn_flat_fc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
		}
		else {
			btn_flat_fc->Text = "Load 'SlopeMid'.";
			btn_flat_fc->BackgroundImage = GetResourceImage(IMG_BUTTON);
			global::Extended->FlatFC = MPathSection("");
			MessageBox::Show("Couldn't locate matching unique OVL for path model.", "Load model error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	MainWindow::activeWindow->Ready = global::Basic->filled();
}

void ExtendedModelsControl::btn_slope_fc_Click(System::Object^  sender, System::EventArgs^  e) {
	if (section_ofds[PS_SLOPE_FC]->ShowDialog(this) ==::DialogResult::OK) {
		if (File::Exists(section_ofds[PS_SLOPE_FC]->FileName->Replace(".common.ovl", ".unique.ovl"))) {
			global::Extended->SlopeFC = MPathSection(section_ofds[PS_SLOPE_FC]->FileName);

			btn_slope_fc->Text = "'SlopeFC' loaded.";
			btn_slope_fc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
		}
		else {
			btn_slope_fc->Text = "Load 'SlopeFC'.";
			btn_slope_fc->BackgroundImage = GetResourceImage(IMG_BUTTON);
			global::Extended->SlopeFC = MPathSection("");
			MessageBox::Show("Couldn't locate matching unique OVL for path model.", "Load model error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	MainWindow::activeWindow->Ready = global::Basic->filled();
}

void ExtendedModelsControl::btn_slope_bc_Click(System::Object^  sender, System::EventArgs^  e) {
	if (section_ofds[PS_SLOPE_BC]->ShowDialog(this) ==::DialogResult::OK) {
		if (File::Exists(section_ofds[PS_SLOPE_BC]->FileName->Replace(".common.ovl", ".unique.ovl"))) {
			global::Extended->SlopeBC = MPathSection(section_ofds[PS_SLOPE_BC]->FileName);

			btn_slope_bc->Text = "'SlopeBC' loaded.";
			btn_slope_bc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
		}
		else {
			btn_slope_bc->Text = "Load 'SlopeBC'.";
			btn_slope_bc->BackgroundImage = GetResourceImage(IMG_BUTTON);
			global::Extended->SlopeBC = MPathSection("");
			MessageBox::Show("Couldn't locate matching unique OVL for path model.", "Load model error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	MainWindow::activeWindow->Ready = global::Basic->filled();
}

void ExtendedModelsControl::btn_slope_tc_Click(System::Object^  sender, System::EventArgs^  e) {
	if (section_ofds[PS_SLOPE_TC]->ShowDialog(this) ==::DialogResult::OK) {
		if (File::Exists(section_ofds[PS_SLOPE_TC]->FileName->Replace(".common.ovl", ".unique.ovl"))) {
			global::Extended->SlopeTC = MPathSection(section_ofds[PS_SLOPE_TC]->FileName);

			btn_slope_tc->Text = "'SlopeTC' loaded.";
			btn_slope_tc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
		}
		else {
			btn_slope_tc->Text = "Load 'SlopeTC'.";
			btn_slope_tc->BackgroundImage = GetResourceImage(IMG_BUTTON);
			global::Extended->SlopeTC = MPathSection("");
			MessageBox::Show("Couldn't locate matching unique OVL for path model.", "Load model error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	MainWindow::activeWindow->Ready = global::Basic->filled();
}

void ExtendedModelsControl::btn_slope_straight_fc_Click(System::Object^  sender, System::EventArgs^  e) {
	if (section_ofds[PS_SLOPE_STRAIGHT_FC]->ShowDialog(this) ==::DialogResult::OK) {
		if (File::Exists(section_ofds[PS_SLOPE_STRAIGHT_FC]->FileName->Replace(".common.ovl", ".unique.ovl"))) {
			global::Extended->SlopeStraightFC = MPathSection(section_ofds[PS_SLOPE_STRAIGHT_FC]->FileName);

			btn_slope_straight_fc->Text = "'SlopeStraightFC' loaded.";
			btn_slope_straight_fc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
		}
		else {
			btn_slope_straight_fc->Text = "Load 'SlopeStraightFC'.";
			btn_slope_straight_fc->BackgroundImage = GetResourceImage(IMG_BUTTON);
			global::Extended->SlopeStraightFC = MPathSection("");
			MessageBox::Show("Couldn't locate matching unique OVL for path model.", "Load model error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	MainWindow::activeWindow->Ready = global::Basic->filled();
}

void ExtendedModelsControl::btn_slope_straight_bc_Click(System::Object^  sender, System::EventArgs^  e) {
	if (section_ofds[PS_SLOPE_STRAIGHT_BC]->ShowDialog(this) ==::DialogResult::OK) {
		if (File::Exists(section_ofds[PS_SLOPE_STRAIGHT_BC]->FileName->Replace(".common.ovl", ".unique.ovl"))) {
			global::Extended->SlopeStraightBC = MPathSection(section_ofds[PS_SLOPE_STRAIGHT_BC]->FileName);

			btn_slope_straight_bc->Text = "'SlopeStraightBC' loaded.";
			btn_slope_straight_bc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
		}
		else {
			btn_slope_straight_bc->Text = "Load 'SlopeStraightBC'.";
			btn_slope_straight_bc->BackgroundImage = GetResourceImage(IMG_BUTTON);
			global::Extended->SlopeStraightBC = MPathSection("");
			MessageBox::Show("Couldn't locate matching unique OVL for path model.", "Load model error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	MainWindow::activeWindow->Ready = global::Basic->filled();
}

void ExtendedModelsControl::btn_slope_straight_tc_Click(System::Object^  sender, System::EventArgs^  e) {
	if (section_ofds[PS_SLOPE_STRAIGHT_TC]->ShowDialog(this) ==::DialogResult::OK) {
		if (File::Exists(section_ofds[PS_SLOPE_STRAIGHT_TC]->FileName->Replace(".common.ovl", ".unique.ovl"))) {
			global::Extended->SlopeStraightTC = MPathSection(section_ofds[PS_SLOPE_STRAIGHT_TC]->FileName);

			btn_slope_straight_tc->Text = "'SlopeStraightTC' loaded.";
			btn_slope_straight_tc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
		}
		else {
			btn_slope_straight_tc->Text = "Load 'SlopeStraightTC'.";
			btn_slope_straight_tc->BackgroundImage = GetResourceImage(IMG_BUTTON);
			global::Extended->SlopeStraightTC = MPathSection("");
			MessageBox::Show("Couldn't locate matching unique OVL for path model.", "Load model error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	MainWindow::activeWindow->Ready = global::Basic->filled();
}

void ExtendedModelsControl::btn_slope_straight_l_fc_Click(System::Object^  sender, System::EventArgs^  e) {
	if (section_ofds[PS_SLOPE_STRAIGHT_L_FC]->ShowDialog(this) ==::DialogResult::OK) {
		if (File::Exists(section_ofds[PS_SLOPE_STRAIGHT_L_FC]->FileName->Replace(".common.ovl", ".unique.ovl"))) {
			global::Extended->SlopeStraightLFC = MPathSection(section_ofds[PS_SLOPE_STRAIGHT_L_FC]->FileName);

			btn_slope_straight_l_fc->Text = "'SlopeStraightLFC' loaded.";
			btn_slope_straight_l_fc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
		}
		else {
			btn_slope_straight_l_fc->Text = "Load 'SlopeStraightLFC'.";
			btn_slope_straight_l_fc->BackgroundImage = GetResourceImage(IMG_BUTTON);
			global::Extended->SlopeStraightLFC = MPathSection("");
			MessageBox::Show("Couldn't locate matching unique OVL for path model.", "Load model error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	MainWindow::activeWindow->Ready = global::Basic->filled();
}

void ExtendedModelsControl::btn_slope_straight_l_bc_Click(System::Object^  sender, System::EventArgs^  e) {
	if (section_ofds[PS_SLOPE_STRAIGHT_L_BC]->ShowDialog(this) ==::DialogResult::OK) {
		if (File::Exists(section_ofds[PS_SLOPE_STRAIGHT_L_BC]->FileName->Replace(".common.ovl", ".unique.ovl"))) {
			global::Extended->SlopeStraightLBC = MPathSection(section_ofds[PS_SLOPE_STRAIGHT_L_BC]->FileName);

			btn_slope_straight_l_bc->Text = "'SlopeStraightLBC' loaded.";
			btn_slope_straight_l_bc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
		}
		else {
			btn_slope_straight_l_bc->Text = "Load 'SlopeStraightLBC'.";
			btn_slope_straight_l_bc->BackgroundImage = GetResourceImage(IMG_BUTTON);
			global::Extended->SlopeStraightLBC = MPathSection("");
			MessageBox::Show("Couldn't locate matching unique OVL for path model.", "Load model error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	MainWindow::activeWindow->Ready = global::Basic->filled();
}

void ExtendedModelsControl::btn_slope_straight_l_tc_Click(System::Object^  sender, System::EventArgs^  e) {
	if (section_ofds[PS_SLOPE_STRAIGHT_L_TC]->ShowDialog(this) ==::DialogResult::OK) {
		if (File::Exists(section_ofds[PS_SLOPE_STRAIGHT_L_TC]->FileName->Replace(".common.ovl", ".unique.ovl"))) {
			global::Extended->SlopeStraightLTC = MPathSection(section_ofds[PS_SLOPE_STRAIGHT_L_TC]->FileName);

			btn_slope_straight_l_tc->Text = "'SlopeStraightLTC' loaded.";
			btn_slope_straight_l_tc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
		}
		else {
			btn_slope_straight_l_tc->Text = "Load 'SlopeStraightLTC'.";
			btn_slope_straight_l_tc->BackgroundImage = GetResourceImage(IMG_BUTTON);
			global::Extended->SlopeStraightLTC = MPathSection("");
			MessageBox::Show("Couldn't locate matching unique OVL for path model.", "Load model error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	MainWindow::activeWindow->Ready = global::Basic->filled();
}

void ExtendedModelsControl::btn_slope_straight_r_fc_Click(System::Object^  sender, System::EventArgs^  e) {
	if (section_ofds[PS_SLOPE_STRAIGHT_R_FC]->ShowDialog(this) ==::DialogResult::OK) {
		if (File::Exists(section_ofds[PS_SLOPE_STRAIGHT_R_FC]->FileName->Replace(".common.ovl", ".unique.ovl"))) {
			global::Extended->SlopeStraightRFC = MPathSection(section_ofds[PS_SLOPE_STRAIGHT_R_FC]->FileName);

			btn_slope_straight_r_fc->Text = "'SlopeStraightRFC' loaded.";
			btn_slope_straight_r_fc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
		}
		else {
			btn_slope_straight_r_fc->Text = "Load 'SlopeStraightRFC'.";
			btn_slope_straight_r_fc->BackgroundImage = GetResourceImage(IMG_BUTTON);
			global::Extended->SlopeStraightRFC = MPathSection("");
			MessageBox::Show("Couldn't locate matching unique OVL for path model.", "Load model error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	MainWindow::activeWindow->Ready = global::Basic->filled();
}

void ExtendedModelsControl::btn_slope_straight_r_bc_Click(System::Object^  sender, System::EventArgs^  e) {
	if (section_ofds[PS_SLOPE_STRAIGHT_R_BC]->ShowDialog(this) ==::DialogResult::OK) {
		if (File::Exists(section_ofds[PS_SLOPE_STRAIGHT_R_BC]->FileName->Replace(".common.ovl", ".unique.ovl"))) {
			global::Extended->SlopeStraightRBC = MPathSection(section_ofds[PS_SLOPE_STRAIGHT_R_BC]->FileName);

			btn_slope_straight_r_bc->Text = "'SlopeStraightRBC' loaded.";
			btn_slope_straight_r_bc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
		}
		else {
			btn_slope_straight_r_bc->Text = "Load 'SlopeStraightRBC'.";
			btn_slope_straight_r_bc->BackgroundImage = GetResourceImage(IMG_BUTTON);
			global::Extended->SlopeStraightRBC = MPathSection("");
			MessageBox::Show("Couldn't locate matching unique OVL for path model.", "Load model error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	MainWindow::activeWindow->Ready = global::Basic->filled();
}

void ExtendedModelsControl::btn_slope_straight_r_tc_Click(System::Object^  sender, System::EventArgs^  e) {
	if (section_ofds[PS_SLOPE_STRAIGHT_R_TC]->ShowDialog(this) ==::DialogResult::OK) {
		if (File::Exists(section_ofds[PS_SLOPE_STRAIGHT_R_TC]->FileName->Replace(".common.ovl", ".unique.ovl"))) {
			global::Extended->SlopeStraightRTC = MPathSection(section_ofds[PS_SLOPE_STRAIGHT_R_TC]->FileName);

			btn_slope_straight_r_tc->Text = "'SlopeStraightRTC' loaded.";
			btn_slope_straight_r_tc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
		}
		else {
			btn_slope_straight_r_tc->Text = "Load 'SlopeStraightRTC'.";
			btn_slope_straight_r_tc->BackgroundImage = GetResourceImage(IMG_BUTTON);
			global::Extended->SlopeStraightRTC = MPathSection("");
			MessageBox::Show("Couldn't locate matching unique OVL for path model.", "Load model error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	MainWindow::activeWindow->Ready = global::Basic->filled();
}

void ExtendedModelsControl::btn_slope_mid_fc_Click(System::Object^  sender, System::EventArgs^  e) {
	if (section_ofds[PS_SLOPE_MID_FC]->ShowDialog(this) ==::DialogResult::OK) {
		if (File::Exists(section_ofds[PS_SLOPE_MID_FC]->FileName->Replace(".common.ovl", ".unique.ovl"))) {
			global::Extended->SlopeMidFC = MPathSection(section_ofds[PS_SLOPE_MID_FC]->FileName);

			btn_slope_mid_fc->Text = "'SlopeMidFC' loaded.";
			btn_slope_mid_fc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
		}
		else {
			btn_slope_mid_fc->Text = "Load 'SlopeMidFC'.";
			btn_slope_mid_fc->BackgroundImage = GetResourceImage(IMG_BUTTON);
			global::Extended->SlopeMidFC = MPathSection("");
			MessageBox::Show("Couldn't locate matching unique OVL for path model.", "Load model error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	MainWindow::activeWindow->Ready = global::Basic->filled();
}

void ExtendedModelsControl::btn_slope_mid_bc_Click(System::Object^  sender, System::EventArgs^  e) {
	if (section_ofds[PS_SLOPE_MID_BC]->ShowDialog(this) ==::DialogResult::OK) {
		if (File::Exists(section_ofds[PS_SLOPE_MID_BC]->FileName->Replace(".common.ovl", ".unique.ovl"))) {
			global::Extended->SlopeMidBC = MPathSection(section_ofds[PS_SLOPE_MID_BC]->FileName);

			btn_slope_mid_bc->Text = "'SlopeMidBC' loaded.";
			btn_slope_mid_bc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
		}
		else {
			btn_slope_mid_bc->Text = "Load 'SlopeMidBC'.";
			btn_slope_mid_bc->BackgroundImage = GetResourceImage(IMG_BUTTON);
			global::Extended->SlopeMidBC = MPathSection("");
			MessageBox::Show("Couldn't locate matching unique OVL for path model.", "Load model error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	MainWindow::activeWindow->Ready = global::Basic->filled();
}

void ExtendedModelsControl::btn_slope_mid_tc_Click(System::Object^  sender, System::EventArgs^  e) {
	if (section_ofds[PS_SLOPE_MID_TC]->ShowDialog(this) ==::DialogResult::OK) {
		if (File::Exists(section_ofds[PS_SLOPE_MID_TC]->FileName->Replace(".common.ovl", ".unique.ovl"))) {
			global::Extended->SlopeMidTC = MPathSection(section_ofds[PS_SLOPE_MID_TC]->FileName);

			btn_slope_mid_tc->Text = "'SlopeMidTC' loaded.";
			btn_slope_mid_tc->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
		}
		else {
			btn_slope_mid_tc->Text = "Load 'SlopeMidTC'.";
			btn_slope_mid_tc->BackgroundImage = GetResourceImage(IMG_BUTTON);
			global::Extended->SlopeMidTC = MPathSection("");
			MessageBox::Show("Couldn't locate matching unique OVL for path model.", "Load model error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	MainWindow::activeWindow->Ready = global::Basic->filled();
}

void ExtendedModelsControl::btn_paving_Click(System::Object^  sender, System::EventArgs^  e) {
	if (section_ofds[PS_PAVING]->ShowDialog(this) ==::DialogResult::OK) {
		if (File::Exists(section_ofds[PS_PAVING]->FileName->Replace(".common.ovl", ".unique.ovl"))) {
			global::Extended->Paving = section_ofds[PS_PAVING]->FileName;

			btn_paving->Text = "'Paving' loaded.";
			btn_paving->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
		}
		else {
			btn_paving->Text = "Load 'Paving'.";
			btn_paving->BackgroundImage = GetResourceImage(IMG_BUTTON);
			global::Extended->Paving = "";
			MessageBox::Show("Couldn't locate matching unique OVL for path model.", "Load model error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	MainWindow::activeWindow->Ready = global::Basic->filled();
}