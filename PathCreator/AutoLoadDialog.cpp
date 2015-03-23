// AutoLoadDialog.cpp

#include "StdAfx.h"
#include "AutoLoadDialog.h"

using namespace PathCreator;

AutoLoadDialog::AutoLoadDialog(void) {
	InitializeComponent();
			
	btn_ok->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_cancel->BackgroundImage = GetResourceImage(IMG_BUTTON);
}

AutoLoadDialog::~AutoLoadDialog() {
	if (components)
	{
		delete components;
	}
}

bool AutoLoadDialog::complete() {
	return cb_complete->Checked;
}

bool AutoLoadDialog::underlined() {
	return cb_underlined->Checked;
}

bool AutoLoadDialog::separated() {
	return cb_separated->Checked;
}

void AutoLoadDialog::btn_cancel_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Close();
}

void AutoLoadDialog::btn_ok_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Close();
}