// QueueModelsControl.cpp

#include "StdAfx.h"
#include "QueueModelsControl.h"

using namespace PathCreator;

#define INITOFD(num, title) section_ofds[num] = gcnew OpenFileDialog(); \
	section_ofds[num]->Title = title; \
	section_ofds[num]->Filter = "OVL Files|*.common.ovl"; \
	section_ofds[num]->SupportMultiDottedExtensions = true

QueueModelsControl::QueueModelsControl(void) {
	InitializeComponent();

	activeInstance = this;

	btn_slope_down->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_straight->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_turn_l->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_turn_r->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_slope_up->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_slope_straight1->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_slope_straight2->BackgroundImage = GetResourceImage(IMG_BUTTON);

	section_ofds = gcnew array<OpenFileDialog^>(QS_PATH_COUNT);

	INITOFD(QS_STRAIGHT, "Load 'Straight'.");
	INITOFD(QS_TURN_L, "Load 'TurnL'.");
	INITOFD(QS_TURN_R, "Load 'TurnR'.");
	INITOFD(QS_SLOPE_UP, "Load 'SlopeUp'.");
	INITOFD(QS_SLOPE_DOWN, "Load 'SlopeDown'.");
	INITOFD(QS_SLOPE_STRAIGHT1, "Load 'SlopeStraight'.");
	INITOFD(QS_SLOPE_STRAIGHT2, "Load 'SlopeStraight2'.");
}

QueueModelsControl::~QueueModelsControl() {
	if (components)
	{
		delete components;
	}
}

void QueueModelsControl::reset() {
	for (int i = 0; i < QS_PATH_COUNT; i++) 
	{
		section_ofds[i]->Reset();
	}

	global::Queue->Straight = "";
	btn_straight->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_straight->Text = "Load 'Straight'.";

	global::Queue->TurnL = "";
	btn_turn_l->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_turn_l->Text = "Load 'TurnL'.";

	global::Queue->TurnR = "";
	btn_turn_r->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_turn_r->Text = "Load 'TurnR'.";

	global::Queue->SlopeUp = "";
	btn_slope_up->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_slope_up->Text = "Load 'SlopeUp'.";

	global::Queue->SlopeDown = "";
	btn_slope_down->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_slope_down->Text = "Load 'SlopeDown'.";

	global::Queue->SlopeStraight1 = "";
	btn_slope_straight1->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_slope_straight1->Text = "Load 'SlopeStraight'.";

	global::Queue->SlopeStraight2 = "";
	btn_slope_straight2->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_slope_straight2->Text = "Load 'SlopeStraight2'.";
}

#define UPDATE(btn, name, name2) if (File::Exists(global::Queue->name) && File::Exists(global::Queue->name->Replace(".common.ovl", ".unique.ovl"))) { \
	btn->Text = "'"name2"' loaded."; \
	btn->BackgroundImage = GetResourceImage(IMG_BUTTON_G); \
}

void QueueModelsControl::update() {
	UPDATE(btn_slope_down, SlopeDown, "SlopeDown")
	UPDATE(btn_straight, Straight, "Straight")
	UPDATE(btn_turn_l, TurnL, "TurnL")
	UPDATE(btn_turn_r, TurnR, "TurnR")
	UPDATE(btn_slope_up, SlopeUp, "SlopeUp")
	UPDATE(btn_slope_straight1, SlopeStraight1, "SlopeStraight")
	UPDATE(btn_slope_straight2, SlopeStraight2, "SlopeStraight2")
}

void QueueModelsControl::btn_straight_Click(System::Object^  sender, System::EventArgs^  e) {
	if (section_ofds[QS_STRAIGHT]->ShowDialog(this) ==::DialogResult::OK) {
		if (File::Exists(section_ofds[QS_STRAIGHT]->FileName->Replace(".common.ovl", ".unique.ovl"))) {
			global::Queue->Straight = section_ofds[QS_STRAIGHT]->FileName;

			btn_straight->Text = "'Straight' loaded.";
			btn_straight->BackgroundImage = GetResourceImage(IMG_BUTTON_G);

			MainWindow::activeWindow->Ready = global::Queue->filled();
		}
		else {
			btn_straight->Text = "Load 'Straight'.";
			btn_straight->BackgroundImage = GetResourceImage(IMG_BUTTON);
			global::Queue->Straight = "";
			MessageBox::Show("Couldn't locate matching unique OVL for queue model.", "Load model error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}

void QueueModelsControl::btn_turn_l_Click(System::Object^  sender, System::EventArgs^  e) {
	if (section_ofds[QS_TURN_L]->ShowDialog(this) ==::DialogResult::OK) {
		if (File::Exists(section_ofds[QS_TURN_L]->FileName->Replace(".common.ovl", ".unique.ovl"))) {
			global::Queue->TurnL = section_ofds[QS_TURN_L]->FileName;

			btn_turn_l->Text = "'TurnL' loaded.";
			btn_turn_l->BackgroundImage = GetResourceImage(IMG_BUTTON_G);

			MainWindow::activeWindow->Ready = global::Queue->filled();
		}
		else {
			btn_turn_l->Text = "Load 'TurnL'.";
			btn_turn_l->BackgroundImage = GetResourceImage(IMG_BUTTON);
			global::Queue->TurnL = "";
			MessageBox::Show("Couldn't locate matching unique OVL for queue model.", "Load model error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}

void QueueModelsControl::btn_turn_r_Click(System::Object^  sender, System::EventArgs^  e) {
	if (section_ofds[QS_TURN_R]->ShowDialog(this) ==::DialogResult::OK) {
		if (File::Exists(section_ofds[QS_TURN_R]->FileName->Replace(".common.ovl", ".unique.ovl"))) {
			global::Queue->TurnR = section_ofds[QS_TURN_R]->FileName;

			btn_turn_r->Text = "'TurnR' loaded.";
			btn_turn_r->BackgroundImage = GetResourceImage(IMG_BUTTON_G);

			MainWindow::activeWindow->Ready = global::Queue->filled();
		}
		else {
			btn_turn_r->Text = "Load 'TurnR'.";
			btn_turn_r->BackgroundImage = GetResourceImage(IMG_BUTTON);
			global::Queue->TurnR = "";
			MessageBox::Show("Couldn't locate matching unique OVL for queue model.", "Load model error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}

void QueueModelsControl::btn_slope_up_Click(System::Object^  sender, System::EventArgs^  e) {
	if (section_ofds[QS_SLOPE_UP]->ShowDialog(this) ==::DialogResult::OK) {
		if (File::Exists(section_ofds[QS_SLOPE_UP]->FileName->Replace(".common.ovl", ".unique.ovl"))) {
			global::Queue->SlopeUp = section_ofds[QS_SLOPE_UP]->FileName;

			btn_slope_up->Text = "'SlopeUp' loaded.";
			btn_slope_up->BackgroundImage = GetResourceImage(IMG_BUTTON_G);

			MainWindow::activeWindow->Ready = global::Queue->filled();
		}
		else {
			btn_slope_up->Text = "Load 'SlopeUp'.";
			btn_slope_up->BackgroundImage = GetResourceImage(IMG_BUTTON);
			global::Queue->SlopeUp = "";
			MessageBox::Show("Couldn't locate matching unique OVL for queue model.", "Load model error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}

void QueueModelsControl::btn_slope_down_Click(System::Object^  sender, System::EventArgs^  e) {
	if (section_ofds[QS_SLOPE_DOWN]->ShowDialog(this) ==::DialogResult::OK) {
		if (File::Exists(section_ofds[QS_SLOPE_DOWN]->FileName->Replace(".common.ovl", ".unique.ovl"))) {
			global::Queue->SlopeDown = section_ofds[QS_SLOPE_DOWN]->FileName;

			btn_slope_down->Text = "'SlopeDown' loaded.";
			btn_slope_down->BackgroundImage = GetResourceImage(IMG_BUTTON_G);

			MainWindow::activeWindow->Ready = global::Queue->filled();
		}
		else {
			btn_slope_down->Text = "Load 'SlopeDown'.";
			btn_slope_down->BackgroundImage = GetResourceImage(IMG_BUTTON);
			global::Queue->SlopeDown = "";
			MessageBox::Show("Couldn't locate matching unique OVL for queue model.", "Load model error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}

void QueueModelsControl::btn_slope_straight1_Click(System::Object^  sender, System::EventArgs^  e) {
	if (section_ofds[QS_SLOPE_STRAIGHT1]->ShowDialog(this) ==::DialogResult::OK) {
		if (File::Exists(section_ofds[QS_SLOPE_STRAIGHT1]->FileName->Replace(".common.ovl", ".unique.ovl"))) {
			global::Queue->SlopeStraight1 = section_ofds[QS_SLOPE_STRAIGHT1]->FileName;

			btn_slope_straight1->Text = "'SlopeStraight' loaded.";
			btn_slope_straight1->BackgroundImage = GetResourceImage(IMG_BUTTON_G);

			MainWindow::activeWindow->Ready = global::Queue->filled();
		}
		else {
			btn_slope_straight1->Text = "Load 'SlopeStraight'.";
			btn_slope_straight1->BackgroundImage = GetResourceImage(IMG_BUTTON);
			global::Queue->SlopeStraight1 = "";
			MessageBox::Show("Couldn't locate matching unique OVL for queue model.", "Load model error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}

void QueueModelsControl::btn_slope_straight2_Click(System::Object^  sender, System::EventArgs^  e) {
	if (section_ofds[QS_SLOPE_STRAIGHT2]->ShowDialog(this) ==::DialogResult::OK) {
		if (File::Exists(section_ofds[QS_SLOPE_STRAIGHT2]->FileName->Replace(".common.ovl", ".unique.ovl"))) {
			global::Queue->SlopeStraight2 = section_ofds[QS_SLOPE_STRAIGHT2]->FileName;

			btn_slope_straight2->Text = "'SlopeStraight2' loaded.";
			btn_slope_straight2->BackgroundImage = GetResourceImage(IMG_BUTTON_G);

			MainWindow::activeWindow->Ready = global::Queue->filled();
		}
		else {
			btn_slope_straight2->Text = "Load 'SlopeStraight2'.";
			btn_slope_straight2->BackgroundImage = GetResourceImage(IMG_BUTTON);
			global::Queue->SlopeStraight2 = "";
			MessageBox::Show("Couldn't locate matching unique OVL for queue model.", "Load model error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}

void QueueModelsControl::link_auto_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e)
{
	AutoLoadDialog^ autod = gcnew AutoLoadDialog();

	if (fbd_autoLoad->ShowDialog(this) == ::DialogResult::OK)
	{
		if (autod->ShowDialog(this) == ::DialogResult::OK)
		{

			array<String^>^ ovls = Directory::GetFiles(fbd_autoLoad->SelectedPath, "*.common.ovl");

			if (ovls->Length <= 0)
			{
				MessageBox::Show("Selected folder doesn't contain any OVL files!", "Error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			String^ currFile;

			for (int i = 0; i < ovls->Length; i++)
			{
				currFile = ovls[i]->Split('\\')[ovls[i]->Split('\\')->Length - 1];

				if (autod->complete())
				{
					if (StringContains(currFile, "TurnL", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Queue->TurnL = ovls[i];
						btn_turn_l->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_turn_l->Text = "'TurnLeft' model loaded!";
					}
					else if (StringContains(currFile, "TurnR", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Queue->TurnR = ovls[i];
						btn_turn_r->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_turn_r->Text = "'TurnRight' model loaded!";
					}
					else if (StringContains(currFile, "SlopeUp", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Queue->SlopeUp = ovls[i];
						btn_slope_up->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_up->Text = "'SlopeUp' model loaded!";
					}
					else if (StringContains(currFile, "SlopeDown", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Queue->SlopeDown = ovls[i];
						btn_slope_down->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_down->Text = "'SlopeDown' model loaded!";
					}
					else if (StringContains(currFile, "SlopeStraight", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Queue->SlopeStraight1 = ovls[i];
						btn_slope_straight1->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_straight1->Text = "'SlopeStraight' model loaded!";
					}
					else if (StringContains(currFile, "SlopeStraight2", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Queue->SlopeStraight2 = ovls[i];
						btn_slope_straight2->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_straight2->Text = "'SlopeStraight2' model loaded!";
					}
					else if (StringContains(currFile, "Straight", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Queue->Straight = ovls[i];
						btn_straight->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_straight->Text = "'Straight' model loaded!";
					}
				}

				if (autod->underlined())
				{
					if (StringContains(currFile, "Turn_L", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Queue->TurnL = ovls[i];
						btn_turn_l->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_turn_l->Text = "'TurnLeft' model loaded!";
					}
					else if (StringContains(currFile, "Turn_R", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Queue->TurnR = ovls[i];
						btn_turn_r->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_turn_r->Text = "'TurnRight' model loaded!";
					}
					else if (StringContains(currFile, "Slope_Up", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Queue->SlopeUp = ovls[i];
						btn_slope_up->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_up->Text = "'SlopeUp' model loaded!";
					}
					else if (StringContains(currFile, "Slope_Down", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Queue->SlopeDown = ovls[i];
						btn_slope_down->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_down->Text = "'SlopeDown' model loaded!";
					}
					else if (StringContains(currFile, "Slope_Straight", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Queue->SlopeStraight1 = ovls[i];
						btn_slope_straight1->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_straight1->Text = "'SlopeStraight' model loaded!";
					}
					else if (StringContains(currFile, "Slope_Straight_2", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Queue->SlopeStraight2 = ovls[i];
						btn_slope_straight2->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_straight2->Text = "'SlopeStraight2' model loaded!";
					}
					else if (StringContains(currFile, "Straight", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Queue->Straight = ovls[i];
						btn_straight->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_straight->Text = "'Straight' model loaded!";
					}
				}

				if (autod->separated())
				{
					if (StringContains(currFile, "Turn-L", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Queue->TurnL = ovls[i];
						btn_turn_l->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_turn_l->Text = "'TurnLeft' model loaded!";
					}
					else if (StringContains(currFile, "Turn-R", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Queue->TurnR = ovls[i];
						btn_turn_r->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_turn_r->Text = "'TurnRight' model loaded!";
					}
					else if (StringContains(currFile, "Slope-Up", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Queue->SlopeUp = ovls[i];
						btn_slope_up->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_up->Text = "'SlopeUp' model loaded!";
					}
					else if (StringContains(currFile, "Slope-Down", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Queue->SlopeDown = ovls[i];
						btn_slope_down->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_down->Text = "'SlopeDown' model loaded!";
					}
					else if (StringContains(currFile, "Slope-Straight", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Queue->SlopeStraight1 = ovls[i];
						btn_slope_straight1->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_straight1->Text = "'SlopeStraight' model loaded!";
					}
					else if (StringContains(currFile, "Slope-Straight-2", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Queue->SlopeStraight2 = ovls[i];
						btn_slope_straight2->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_slope_straight2->Text = "'SlopeStraight2' model loaded!";
					}
					else if (StringContains(currFile, "Straight", System::StringComparison::CurrentCultureIgnoreCase))
					{
						global::Queue->Straight = ovls[i];
						btn_straight->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
						btn_straight->Text = "'Straight' model loaded!";
					}
				}
			}
		}
	}

	MainWindow::activeWindow->Ready = global::Queue->filled();
}