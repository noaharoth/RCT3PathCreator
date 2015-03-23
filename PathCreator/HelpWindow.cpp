// HelpWindow.cpp

#include "StdAfx.h"
#include "HelpWindow.h"

using namespace PathCreator;

HelpWindow::HelpWindow(void) {
	InitializeComponent();

	pb_topBar->BackgroundImage = GetResourceImage(IMG_BAR);

	helpText->LoadFile(Assembly::GetExecutingAssembly()->GetManifestResourceStream("Help-Overview.rtf"),
		RichTextBoxStreamType::RichText);

	currentFile = "Help-Overview.rtf";
}

void HelpWindow::lblbtn_overview_MouseEnter(System::Object^  sender, System::EventArgs^  e) 
{
	if (currentFile != "Help-Overview.rtf")
		lblbtn_overview->BackColor = Color::LightGray;
}

void HelpWindow::lblbtn_models_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
	if (currentFile != "Help-Models.rtf")
		lblbtn_models->BackColor = Color::LightGray;
}

void HelpWindow::lblbtn_textures_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
	if (currentFile != "Help-Textures.rtf")
		lblbtn_textures->BackColor = Color::LightGray;
}

void HelpWindow::lblbtn_iconsSettings_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
	if (currentFile != "Help-Icons.rtf")
		lblbtn_iconsSettings->BackColor = Color::LightGray;
}

void HelpWindow::lblbtn_overview_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	if (currentFile != "Help-Overview.rtf")
		lblbtn_overview->BackColor = SystemColors::ControlLight;
}

void HelpWindow::lblbtn_models_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	if (currentFile != "Help-Models.rtf")
		lblbtn_models->BackColor = SystemColors::ControlLight;
}

void HelpWindow::lblbtn_textures_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	if (currentFile != "Help-Textures.rtf")
		lblbtn_textures->BackColor = SystemColors::ControlLight;
}

void HelpWindow::lblbtn_iconsSettings_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	if (currentFile != "Help-Icons.rtf")
		lblbtn_iconsSettings->BackColor = SystemColors::ControlLight;
}

void HelpWindow::lblbtn_overview_Click(System::Object^  sender, System::EventArgs^  e) {
	lblbtn_overview->BackColor = Color::DarkGray;

	helpText->LoadFile(Assembly::GetExecutingAssembly()->GetManifestResourceStream("Help-Overview.rtf"), 
		RichTextBoxStreamType::RichText);

	currentFile = "Help-Overview.rtf";

	lblbtn_models->BackColor = SystemColors::ControlLight;
	lblbtn_textures->BackColor = SystemColors::ControlLight;
	lblbtn_iconsSettings->BackColor = SystemColors::ControlLight;
}

void HelpWindow::lblbtn_models_Click(System::Object^  sender, System::EventArgs^  e) {
	lblbtn_models->BackColor = Color::DarkGray;

	helpText->LoadFile(Assembly::GetExecutingAssembly()->GetManifestResourceStream("Help-Models.rtf"),
		RichTextBoxStreamType::RichText);

	currentFile = "Help-Models.rtf";

	lblbtn_overview->BackColor = SystemColors::ControlLight;
	lblbtn_textures->BackColor = SystemColors::ControlLight;
	lblbtn_iconsSettings->BackColor = SystemColors::ControlLight;
}

void HelpWindow::lblbtn_textures_Click(System::Object^  sender, System::EventArgs^  e) {
	lblbtn_textures->BackColor = Color::DarkGray;

	helpText->LoadFile(Assembly::GetExecutingAssembly()->GetManifestResourceStream("Help-Textures.rtf"),
		RichTextBoxStreamType::RichText);

	currentFile = "Help-Textures.rtf";

	lblbtn_overview->BackColor = SystemColors::ControlLight;
	lblbtn_models->BackColor = SystemColors::ControlLight;
	lblbtn_iconsSettings->BackColor = SystemColors::ControlLight;
}

void HelpWindow::lblbtn_iconsSettings_Click(System::Object^  sender, System::EventArgs^  e) {
	lblbtn_iconsSettings->BackColor = Color::DarkGray;

	helpText->LoadFile(Assembly::GetExecutingAssembly()->GetManifestResourceStream("Help-Icons.rtf"),
		RichTextBoxStreamType::RichText);

	currentFile = "Help-Icons.rtf";

	lblbtn_overview->BackColor = SystemColors::ControlLight;
	lblbtn_models->BackColor = SystemColors::ControlLight;
	lblbtn_textures->BackColor = SystemColors::ControlLight;
}