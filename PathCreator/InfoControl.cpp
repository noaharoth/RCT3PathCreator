// InfoControl.cpp

#include "StdAfx.h"
#include "InfoControl.h"

using namespace PathCreator;

InfoControl::InfoControl(void) {
	InitializeComponent();
			
	activeInstance = this;

	pb_icon->Image = GetResourceImage(IMG_NO_IMAGE_SELECTED);
	btn_loadicon->BackgroundImage = GetResourceImage(IMG_BUTTON);
}

InfoControl::~InfoControl() {
	if (components)
	{
		delete components;
	}
}

void InfoControl::reset() {
	txt_shortName->ResetText();
	txt_ingameName->ResetText();
	ofd_icon->Reset();
	pb_icon->Image = GetResourceImage(IMG_NO_IMAGE_SELECTED);
	pb_icon->Refresh();
	btn_loadicon->Text = "Click to load an icon.";
    btn_loadicon->BackgroundImage = GetResourceImage(IMG_BUTTON);

	switch (global::Type) {
		case Rct3PathType::Basic:
		case Rct3PathType::Extended:
			global::Basic->Name = "";
			global::Basic->IngameName = "";
			global::Basic->Icon = "";
			MainWindow::activeWindow->Ready = global::Basic->filled();
			break;
		case Rct3PathType::Queue:
			global::Queue->Name = "";
			global::Queue->IngameName = "";
			global::Queue->Icon = "";
			MainWindow::activeWindow->Ready = global::Queue->filled();
			break;
	}
}

void InfoControl::update(Rct3PathType type) {
	switch (type) {
		case Rct3PathType::Basic:
		case Rct3PathType::Extended:
			txt_shortName->Text = global::Basic->Name;
			txt_ingameName->Text = global::Basic->IngameName;
			
			if (File::Exists(global::Basic->Icon)) {
				ofd_icon->Reset();
				ofd_icon->FileName = global::Basic->Icon;
				Image^ icon = Image::FromFile(global::Basic->Icon);
				if (icon->Width == 64 && icon->Height == 64) {
					pb_icon->Image = icon;
					pb_icon->Refresh();
					btn_loadicon->Text = "Icon loaded.";
					btn_loadicon->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
				}
				else {
					pb_icon->Image = GetResourceImage(IMG_NO_IMAGE_SELECTED);
					btn_loadicon->Text = "Icon size not 64x64!";
					btn_loadicon->BackgroundImage = GetResourceImage(IMG_BUTTON_R);
					global::Basic->Icon = "";
				}
			}

			MainWindow::activeWindow->Ready = global::Basic->filled();
			break;
		case Rct3PathType::Queue:
			txt_shortName->Text = global::Queue->Name;
			txt_ingameName->Text = global::Queue->IngameName;
			
			if (File::Exists(global::Queue->Icon)) {
				ofd_icon->Reset();
				ofd_icon->FileName = global::Queue->Icon;
				Image^ icon = Image::FromFile(global::Queue->Icon);
				if (icon->Width == 64 && icon->Height == 64) {
					pb_icon->Image = icon;
					pb_icon->Refresh();
					btn_loadicon->Text = "Icon loaded.";
					btn_loadicon->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
				}
				else {
					pb_icon->Image = GetResourceImage(IMG_NO_IMAGE_SELECTED);
					btn_loadicon->Text = "Icon size not 64x64!";
					btn_loadicon->BackgroundImage = GetResourceImage(IMG_BUTTON_R);
					global::Queue->Icon = "";
				}
			}

			MainWindow::activeWindow->Ready = global::Queue->filled();
			break;
	}
}

void InfoControl::txt_shortName_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
	if (!System::Linq::Enumerable::Contains<wchar_t>(allowedChars, e->KeyChar) && e->KeyChar != (wchar_t)8) {
		e->Handled = true;
	}
}

void InfoControl::btn_loadicon_Click(System::Object^  sender, System::EventArgs^  e) {
	if (ofd_icon->ShowDialog(this) ==::DialogResult::OK) {
		Bitmap^ icon = safe_cast<Bitmap^>(Image::FromFile(ofd_icon->FileName));

		if (icon->Height == 64 && icon->Width == 64) {

			switch (global::Type) {
				case Rct3PathType::Basic:
				case Rct3PathType::Extended:
					global::Basic->Icon = ofd_icon->FileName;

					MainWindow::activeWindow->Ready = global::Basic->filled();
					break;
				case Rct3PathType::Queue:
					global::Queue->Icon = ofd_icon->FileName;

					MainWindow::activeWindow->Ready = global::Queue->filled();
					break;
			}

			pb_icon->Image = icon;
			btn_loadicon->Text = "Icon loaded.";
			btn_loadicon->BackgroundImage = GetResourceImage(IMG_BUTTON_G);

		}
		else {
			pb_icon->Image = GetResourceImage(IMG_NO_IMAGE_SELECTED);
			btn_loadicon->Text = "Icon size not 64x64!";
			btn_loadicon->BackgroundImage = GetResourceImage(IMG_BUTTON_R);
			MessageBox::Show("Icon size must be 64x64.", "Icon error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}

void InfoControl::txt_ingameName_Leave(System::Object^  sender, System::EventArgs^  e) {
	switch (global::Type) {
		case Rct3PathType::Basic:
		case Rct3PathType::Extended:
			global::Basic->IngameName = txt_ingameName->Text;

			MainWindow::activeWindow->Ready = global::Basic->filled();
			break;
		case Rct3PathType::Queue:
			global::Queue->IngameName = txt_ingameName->Text;

			MainWindow::activeWindow->Ready = global::Queue->filled();
			break;
	}
}

void InfoControl::txt_shortName_Leave(System::Object^  sender, System::EventArgs^  e) {
	switch (global::Type) {
		case Rct3PathType::Basic:
		case Rct3PathType::Extended:
			global::Basic->Name = txt_shortName->Text;

			MainWindow::activeWindow->Ready = global::Basic->filled();
			break;
		case Rct3PathType::Queue:
			global::Queue->Name = txt_shortName->Text;

			MainWindow::activeWindow->Ready = global::Queue->filled();
			break;
	}
}