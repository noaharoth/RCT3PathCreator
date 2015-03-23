// QueueTextureControl.cpp

#include "StdAfx.h"
#include "QueueTextureControl.h"

using namespace PathCreator;

QueueTextureControl::QueueTextureControl(void) {
	InitializeComponent();

	activeInstance = this;

	btn_loadtex->BackgroundImage = GetResourceImage(IMG_BUTTON);
	pb_tex->Image = GetResourceImage(IMG_NO_IMAGE_SELECTED);
	btn_shared->BackgroundImage = GetResourceImage(IMG_BUTTON);
}

QueueTextureControl::~QueueTextureControl() {
	if (components)
	{
		delete components;
	}
}

void QueueTextureControl::reset() {
	pb_tex->Image = GetResourceImage(IMG_NO_IMAGE_SELECTED);
	ofd_shared->Reset();
	btn_shared->Text = "Load shared texture file.";
	btn_loadtex->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_loadtex->Text = "Load texture.";

	cb_first->Checked = false;
	cb_second->Checked = false;
	cb_third->Checked = false;

	global::Queue->Texture = "";
	global::Queue->Shared = "";
	
	global::Queue->Recolor1 = false;
	global::Queue->Recolor2 = false;
	global::Queue->Recolor3 = false;
}

void QueueTextureControl::update() {
	if (File::Exists(global::Queue->Shared)  && File::Exists(global::Queue->Shared->Replace(".common.ovl", ".unique.ovl"))) {
		btn_shared->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
		btn_shared->Text = "Shared OVL loaded.";
	
	}
	else
	{
		btn_shared->BackgroundImage = GetResourceImage(IMG_BUTTON);
		btn_shared->Text = "Load shared texture file.";
	}

	cb_first->Checked = global::Queue->Recolor1;
	cb_second->Checked = global::Queue->Recolor2;
	cb_third->Checked = global::Queue->Recolor3;

	/*if (global::Queue->TextureRecolorability != RCT3Asset::RecolorOptions::None)
	{
		if (global::Queue->TextureRecolorability & RCT3Asset::RecolorOptions::FirstColor)
		{
			cb_first->Checked = true;
		}

		if (global::Queue->TextureRecolorability & RCT3Asset::RecolorOptions::SecondColor)
		{
			cb_second->Checked = true;
		}

		if (global::Queue->TextureRecolorability & RCT3Asset::RecolorOptions::ThirdColor)
		{
			cb_third->Checked = true;
		}
	}*/

	if (File::Exists(global::Queue->Texture)) {
		Image^ tex = Image::FromFile(global::Queue->Texture);

		if (tex->Width == tex->Height && IsPowerOfTwo(tex->Width)) {
			pb_tex->Image = tex;
			pb_tex->Refresh();

			if (tex->Width > 512) {
				btn_loadtex->Text = "Texture loaded. (W)";
                btn_loadtex->BackgroundImage = GetResourceImage(IMG_BUTTON_Y);
			}
			else {
				btn_loadtex->Text = "Texture loaded.";
                btn_loadtex->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
			}
		}
		else {
			pb_tex->Image = GetResourceImage(IMG_NO_IMAGE_SELECTED);
			btn_loadtex->Text = "Incorrect size!";
			btn_loadtex->BackgroundImage = GetResourceImage(IMG_BUTTON_R);
		}
	}
}

void QueueTextureControl::btn_shared_Click(System::Object^  sender, System::EventArgs^  e) {
	if (ofd_shared->ShowDialog(this) ==::DialogResult::OK) {
		if (File::Exists(ofd_shared->FileName->Replace(".common.ovl", ".unique.ovl"))) {
			global::Queue->Shared = ofd_shared->FileName;

			btn_shared->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
			btn_shared->Text = "Shared OVL loaded.";
		}
		else {
			btn_shared->BackgroundImage = GetResourceImage(IMG_BUTTON);
			btn_shared->Text = "Load shared texture file.";

			MessageBox::Show("Couldn't locate unique OVL for shared texture file.", "Shared texture error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		MainWindow::activeWindow->Ready = global::Queue->filled();
	}
}

void QueueTextureControl::btn_loadtex_Click(System::Object^  sender, System::EventArgs^  e) {
	if (ofd_tex->ShowDialog(this) ==::DialogResult::OK) {
		Image^ tex = Image::FromFile(ofd_tex->FileName);

		if (tex->Width == tex->Height && IsPowerOfTwo(tex->Width)) {

			global::Queue->Texture = ofd_tex->FileName;
			pb_tex->Image = tex;
			pb_tex->Refresh();

			if (tex->Width > 512) {
				btn_loadtex->Text = "Texture loaded. (W)";
                btn_loadtex->BackgroundImage = GetResourceImage(IMG_BUTTON_Y);
			}
			else {
				btn_loadtex->Text = "Texture loaded.";
                btn_loadtex->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
			}
		}
		else {
			pb_tex->Image = GetResourceImage(IMG_NO_IMAGE_SELECTED);
			btn_loadtex->Text = "Incorrect size!";
			btn_loadtex->BackgroundImage = GetResourceImage(IMG_BUTTON_R);
			MessageBox::Show("Texture image size must be a power of two (" + tex->Width.ToString()
				 + "x" + tex->Height.ToString() + ").", "Texture error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		MainWindow::activeWindow->Ready = global::Queue->filled();
	}
}

void QueueTextureControl::cb_first_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{

	global::Queue->Recolor1 = cb_first->Checked;

}

void QueueTextureControl::cb_second_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{

	global::Queue->Recolor2 = cb_second->Checked;

}

void QueueTextureControl::cb_third_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{

	global::Queue->Recolor3 = cb_third->Checked;

}