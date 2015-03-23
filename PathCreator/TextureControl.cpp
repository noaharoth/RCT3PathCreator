// TextureControl.cpp

#include "StdAfx.h"
#include "TextureControl.h"

using namespace PathCreator;

TextureControl::TextureControl(void) {
	InitializeComponent();
	
	activeInstance = this;

	btn_loadtexa->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_loadtexb->BackgroundImage = GetResourceImage(IMG_BUTTON);
	pb_texa->Image = GetResourceImage(IMG_NO_IMAGE_SELECTED);
	pb_texb->Image = GetResourceImage(IMG_NO_IMAGE_SELECTED);
	btn_shared->BackgroundImage = GetResourceImage(IMG_BUTTON);
}

TextureControl::~TextureControl() {
	if (components)
	{
		delete components;
	}
}

void TextureControl::reset() {
	pb_texa->Image = GetResourceImage(IMG_NO_IMAGE_SELECTED);
	pb_texb->Image = GetResourceImage(IMG_NO_IMAGE_SELECTED);
	pb_texa->Refresh();
	pb_texb->Refresh();
	ofd_texa->Reset();
	ofd_texb->Reset();
	ofd_shared->Reset();
	btn_shared->Text = "Load shared texture file.";
	btn_loadtexa->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_loadtexa->Text = "Load TextureA.";
	btn_loadtexb->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_loadtexb->Text = "Load TextureB.";

	global::Basic->TextureA = "";
	global::Basic->TextureB = "";
	global::Basic->Shared = "";

	MainWindow::activeWindow->Ready = global::Basic->filled();
}

void TextureControl::update() {
	if (File::Exists(global::Basic->Shared) && File::Exists(global::Basic->Shared->Replace(".common.ovl", ".unique.ovl"))) {
		btn_shared->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
		btn_shared->Text = "Shared OVL loaded.";
	}
	else
	{
		btn_shared->BackgroundImage = GetResourceImage(IMG_BUTTON);
		btn_shared->Text = "Load shared texture file.";
	}

	if (File::Exists(global::Basic->TextureA)) {
		Image^ texA = Image::FromFile(global::Basic->TextureA);

		if (texA->Width == texA->Height && IsPowerOfTwo(texA->Width)) {
			pb_texa->Image = texA;
			pb_texa->Refresh();

			if (texA->Width > 512) {
				btn_loadtexa->Text = "TexA loaded. (W)";
                btn_loadtexa->BackgroundImage = GetResourceImage(IMG_BUTTON_Y);
			}
			else {
				btn_loadtexa->Text = "TextureA loaded.";
                btn_loadtexa->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
			}
		}
		else {
			pb_texa->Image = GetResourceImage(IMG_NO_IMAGE_SELECTED);
			btn_loadtexa->Text = "Incorrect size!";
			btn_loadtexa->BackgroundImage = GetResourceImage(IMG_BUTTON_R);
		}
	}

	if (File::Exists(global::Basic->TextureB)) {
		Image^ texB = Image::FromFile(global::Basic->TextureB);

		if (texB->Width == texB->Height && IsPowerOfTwo(texB->Width)) {
			pb_texb->Image = texB;
			pb_texb->Refresh();

			if (texB->Width > 512) {
				btn_loadtexb->Text = "TexB loaded. (W)";
                btn_loadtexb->BackgroundImage = GetResourceImage(IMG_BUTTON_Y);
			}
			else {
				btn_loadtexb->Text = "TextureB loaded.";
                btn_loadtexb->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
			}
		}
		else {
			pb_texb->Image = GetResourceImage(IMG_NO_IMAGE_SELECTED);
			btn_loadtexb->Text = "Incorrect size!";
			btn_loadtexb->BackgroundImage = GetResourceImage(IMG_BUTTON_R);
		}
	}

	MainWindow::activeWindow->Ready = global::Basic->filled();
}

void TextureControl::btn_loadtexa_Click(System::Object^  sender, System::EventArgs^  e) {
	if (ofd_texa->ShowDialog(this) ==::DialogResult::OK) {
		Image^ texA = Image::FromFile(ofd_texa->FileName);

		if (texA->Width == texA->Height && IsPowerOfTwo(texA->Width)) {

			global::Basic->TextureA = ofd_texa->FileName;
			pb_texa->Image = texA;
			pb_texa->Refresh();

			if (texA->Width > 512) {
				btn_loadtexa->Text = "TexA loaded. (W)";
                btn_loadtexa->BackgroundImage = GetResourceImage(IMG_BUTTON_Y);
			}
			else {
				btn_loadtexa->Text = "TextureA loaded.";
                btn_loadtexa->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
			}
		}
		else {
			pb_texa->Image = GetResourceImage(IMG_NO_IMAGE_SELECTED);
			btn_loadtexa->Text = "Incorrect size!";
			btn_loadtexa->BackgroundImage = GetResourceImage(IMG_BUTTON_R);
			MessageBox::Show("TextureA image size must be a power of two (" + texA->Width.ToString()
				 + "x" + texA->Height.ToString() + ").", "TextureA error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		MainWindow::activeWindow->Ready = global::Basic->filled();
	}
}

void TextureControl::btn_loadtexb_Click(System::Object^  sender, System::EventArgs^  e) {
	if (ofd_texb->ShowDialog(this) ==::DialogResult::OK) {
		Image^ texB = Image::FromFile(ofd_texb->FileName);

		if (texB->Width == texB->Height && IsPowerOfTwo(texB->Width)) {

			global::Basic->TextureB = ofd_texb->FileName;
			pb_texb->Image = texB;
			pb_texb->Refresh();

			if (texB->Width > 512) {
				btn_loadtexb->Text = "TexB loaded. (W)";
                btn_loadtexb->BackgroundImage = GetResourceImage(IMG_BUTTON_Y);
			}
			else {
				btn_loadtexb->Text = "TextureB loaded.";
                btn_loadtexb->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
			}
		}
		else {
			pb_texb->Image = GetResourceImage(IMG_NO_IMAGE_SELECTED);
			btn_loadtexb->Text = "Incorrect size!";
			btn_loadtexb->BackgroundImage = GetResourceImage(IMG_BUTTON_R);
			MessageBox::Show("TextureB image size must be a power of two (" + texB->Width.ToString()
				 + "x" + texB->Height.ToString() + ").", "TextureB error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		MainWindow::activeWindow->Ready = global::Basic->filled();
	}
}

void TextureControl::btn_shared_Click(System::Object^  sender, System::EventArgs^  e) {
	if (ofd_shared->ShowDialog(this) ==::DialogResult::OK) {
		if (File::Exists(ofd_shared->FileName->Replace(".common.ovl", ".unique.ovl"))) {
			global::Basic->Shared = ofd_shared->FileName;

			btn_shared->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
			btn_shared->Text = "Shared OVL loaded.";

			MainWindow::activeWindow->Ready = global::Basic->filled();
		}
		else {
			btn_shared->BackgroundImage = GetResourceImage(IMG_BUTTON);
			btn_shared->Text = "Load shared texture file.";

			MessageBox::Show("Couldn't locate unique OVL for shared texture file.", "Shared texture error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	MainWindow::activeWindow->Ready = global::Basic->filled();
}