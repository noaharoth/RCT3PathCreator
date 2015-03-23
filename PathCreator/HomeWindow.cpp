// HomeWindow.cpp

#include "stdafx.h"
#include "HomeWindow.h"

using namespace PathCreator;

HomeWindow::HomeWindow(void) {
	InitializeComponent();

	activeWindow = this;

	textEmpty = true;
	menuStrip->BackgroundImage = GetResourceImage(IMG_BAR);
	btn_exit->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_begin->BackgroundImage = GetResourceImage(IMG_BUTTON_R);
	openProjectToolStripMenuItem->Image = GetResourceImage(ICN_FOLDER_OPEN);
	programSettingsToolStripMenuItem->Image = GetResourceImage(ICN_GEAR);
	viewHelpToolStripMenuItem->Image = GetResourceImage(ICN_QUESTION);

	// recent projects

	reloadRecents();

}

HomeWindow::~HomeWindow() {
	if (components)
	{
		delete components;
	}
}

void HomeWindow::reloadRecents()
{
	if (global::Settings->RecentProjects->Count)
	{
		listbox_recent->Items->Clear();

		for (int i = (global::Settings->RecentProjects->Count - 1); i >= 0; i--)
		{
			listbox_recent->Items->Add(global::Settings->RecentProjects[i]);
		}
	}
}

void HomeWindow::txt_projectName_Enter(System::Object^  sender, System::EventArgs^  e) {
	if (textEmpty) {
		txt_projectName->Clear();
		txt_projectName->ForeColor = Color::Black;
	}
}

void HomeWindow::txt_projectName_Leave(System::Object^  sender, System::EventArgs^  e) {
	if (txt_projectName->TextLength <= 0)
    {
        txt_projectName->ForeColor = Color::Gray;
        txt_projectName->Text = EMPTY_TEXT;
        textEmpty = true;
    }
	else 
		textEmpty = false;
}

void HomeWindow::txt_projectName_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	if (txt_projectName->TextLength > 0 && txt_projectName->ForeColor == Color::Black) 
		btn_begin->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
    else 
		btn_begin->BackgroundImage = GetResourceImage(IMG_BUTTON_R);
}

void HomeWindow::btn_exit_Click(System::Object^  sender, System::EventArgs^  e) {
	if (MessageBox::Show(this, "Are you sure you want to exit?", "Exit application?", MessageBoxButtons::YesNo, MessageBoxIcon::Question) ==::DialogResult::Yes) {
        Application::Exit();
    }
}

void HomeWindow::exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	if (MessageBox::Show("Are you sure you want to exit?", "Exit application?", MessageBoxButtons::YesNo, MessageBoxIcon::Question) ==::DialogResult::Yes) {
        Application::Exit();
    }
}

void HomeWindow::btn_begin_Click(System::Object^  sender, System::EventArgs^  e) {
	if (!textEmpty) {
		global::SavedDirectory = nullptr;
		global::ProjectName = txt_projectName->Text;

		if (rb_basic->Checked) {
			global::Type = Rct3PathType::Basic;
			global::Basic = gcnew BasicPath();
			global::Extended = nullptr;
			global::Queue = nullptr;
		}
		else if (rb_extended->Checked) {
			global::Type = Rct3PathType::Extended;
			global::Basic = gcnew BasicPath();
			global::Basic->Flags = RCT3Asset::PathFlags::Extended;
			global::Extended = gcnew ExtendedPath(global::Basic);
			global::Queue = nullptr;
		}
		else {
			global::Type = Rct3PathType::Queue;
			global::Queue = gcnew QueuePath();
			global::Basic = nullptr;
			global::Extended = nullptr;
		}

		MainWindow^ win = gcnew MainWindow();
		
		this->Hide();

		win->ShowDialog(this);
	}
}

void HomeWindow::programSettingsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
{
	ProgramSettingsWindow^ win = gcnew ProgramSettingsWindow();
	win->ShowDialog(this);
}

void HomeWindow::viewHelpToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	HelpWindow^ winHelp = gcnew HelpWindow();
	winHelp->ShowDialog(this);
}

void HomeWindow::openProjectToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	if (ofd_openProject->ShowDialog(this) ==::DialogResult::OK) {
		if (!global::openCpathProject(ofd_openProject->FileName))
			return;

		MainWindow^ winMain = gcnew MainWindow();

		switch (global::Type) {
			case Rct3PathType::Basic:
				InfoControl::activeInstance->update(Rct3PathType::Basic);
				TextureControl::activeInstance->update();
				ModelsControl::activeInstance->update();
				break;
			case Rct3PathType::Extended:
				InfoControl::activeInstance->update(Rct3PathType::Extended);
				TextureControl::activeInstance->update();
				ExtendedModelsControl::activeInstance->update();
				break;
			case Rct3PathType::Queue:
				InfoControl::activeInstance->update(Rct3PathType::Queue);
				QueueTextureControl::activeInstance->update();
				QueueModelsControl::activeInstance->update();
				break;
		}

		this->Hide();

		winMain->ShowDialog(this);
	}
}

void HomeWindow::HomeWindow_Load(System::Object^  sender, System::EventArgs^  e)
{
	if (global::PreInitMessage != nullptr)
	{
		MessageBox::Show(global::PreInitMessage, "RCT3 Path Creator 2.0 (Pre-Initializer) - Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

	if (global::Settings->UpdateCheckFreq != UpdateFrequency::Manually)
	{
		DateTime current = DateTime::Now;

		TimeSpan span = current - global::Settings->LastUpdateCheck;

		if (global::Settings->UpdateCheckFreq == UpdateFrequency::EveryWeek)
		{
			if (span.Days >= 7)
			{
				String^ downloadUrl;
				VersionInfo info = CheckForUpdates(downloadUrl);

				if (info.ToString() != global::Settings->CurrentVersion.ToString())
				{
					UpdateWindow^ win = gcnew UpdateWindow(downloadUrl, info);
					win->ShowDialog(this);
				}

				global::Settings->LastUpdateCheck = current;
				global::Settings->SaveOnExit = true;
			}
		}
		else
		{
			if (span.Days >= 30)
			{
				String^ downloadUrl;
				VersionInfo info = CheckForUpdates(downloadUrl);

				if (info.ToString() != global::Settings->CurrentVersion.ToString())
				{
					UpdateWindow^ win = gcnew UpdateWindow(downloadUrl, info);
					win->ShowDialog(this);
				}

				global::Settings->LastUpdateCheck = current;
				global::Settings->SaveOnExit = true;
			}
		}
	}
}

void HomeWindow::aboutRCT3PathCreatorToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	About^ about = gcnew About();
	about->ShowDialog(this);
}

void HomeWindow::listbox_recent_DoubleClick(System::Object^  sender, System::EventArgs^  e)
{
	if (listbox_recent->SelectedItem != nullptr)
	{

		RecentProject proj = safe_cast<RecentProject>(listbox_recent->SelectedItem);

		if (!global::openCpathProject(proj.FileName))
			return;

		MainWindow^ winMain = gcnew MainWindow();

		switch (global::Type) {
		case Rct3PathType::Basic:
			InfoControl::activeInstance->update(Rct3PathType::Basic);
			TextureControl::activeInstance->update();
			ModelsControl::activeInstance->update();
			break;
		case Rct3PathType::Extended:
			InfoControl::activeInstance->update(Rct3PathType::Extended);
			TextureControl::activeInstance->update();
			ExtendedModelsControl::activeInstance->update();
			break;
		case Rct3PathType::Queue:
			InfoControl::activeInstance->update(Rct3PathType::Queue);
			QueueTextureControl::activeInstance->update();
			QueueModelsControl::activeInstance->update();
			break;
		}

		this->Hide();

		winMain->ShowDialog(this);

	}
}

void HomeWindow::HomeWindow_Activated(System::Object^  sender, System::EventArgs^  e)
{
	reloadRecents();
}

void HomeWindow::HomeWindow_Enter(System::Object^  sender, System::EventArgs^  e)
{
	reloadRecents();
}

void HomeWindow::HomeWindow_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
{
#if 0
	if ((e->Modifiers == Keys::Control) && (e->KeyCode == Keys::H))
	{
		global::IsDarkHorizons = 0xFFFFFFFF;
		MessageBox::Show(this, "Special settings set.");
	}
#endif
}

void HomeWindow::checkForUpdatesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	String^ downloadUrl;
	VersionInfo info = CheckForUpdates(downloadUrl);

	if (info.ToString() != global::Settings->CurrentVersion.ToString())
	{
		UpdateWindow^ win = gcnew UpdateWindow(downloadUrl, info);
		win->ShowDialog(this);
	}
	else
	{
		MessageBox::Show(this, "RCT3 Path Creator is up to date!", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

	global::Settings->LastUpdateCheck = DateTime::Now;
	global::Settings->SaveOnExit = true;
}