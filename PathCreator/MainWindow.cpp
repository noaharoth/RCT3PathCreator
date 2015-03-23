// MainWindow.cpp

#include "StdAfx.h"
#include "MainWindow.h"

using namespace PathCreator;

MainWindow::MainWindow(void) {
	InitializeComponent();
	
	activeWindow = this;

	this->Text = global::ProjectName + " (" + global::Type.ToString() + ") - RCT3 Path Creator 2.0";
	saveToolStripMenuItem->Text = "Save " + global::ProjectName;
	saveAsToolStripMenuItem->Text = "Save " + global::ProjectName + " as...";
	
	sfd_saveProject->Title = "Save " + global::ProjectName;
	sfd_saveProject->FileName = global::ProjectName + ".cpath";

	menuStrip->BackgroundImage = GetResourceImage(IMG_BAR);
	statusStrip->BackgroundImage = GetResourceImage(IMG_BAR);

	btn_create->BackgroundImage = GetResourceImage(IMG_BUTTON_R);
	btn_next->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_previous->BackgroundImage = GetResourceImage(IMG_BUTTON);
	btn_next->Image = GetResourceImage(ICN_ARROW_R);
	btn_previous->Image = GetResourceImage(ICN_ARROW_L);

	bar_info->BackgroundImage = GetResourceImage(IMG_BAR_DECOR_B);
	bar_textures->BackgroundImage = GetResourceImage(IMG_BAR_DECOR);
	bar_models->BackgroundImage = GetResourceImage(IMG_BAR_DECOR);

	openProjectToolStripMenuItem->Image = GetResourceImage(ICN_FOLDER_OPEN);
	programSettingsToolStripMenuItem->Image = GetResourceImage(ICN_GEAR);
	viewHelpToolStripMenuItem->Image = GetResourceImage(ICN_QUESTION);
	saveToolStripMenuItem->Image = GetResourceImage(ICN_DISK);
	saveAsToolStripMenuItem->Image = GetResourceImage(ICN_DISK_PENCIL);
	clearAllFieldsToolStripMenuItem->Image = GetResourceImage(ICN_CROSS_SCRIPT);

	panel->HorizontalScroll->Enabled = false;

	tlbl_info = gcnew TransparentLabel();
	tlbl_info_img = gcnew TransparentLabel();
	tlbl_textures = gcnew TransparentLabel();
	tlbl_textures_img = gcnew TransparentLabel();
	tlbl_models = gcnew TransparentLabel();
	tlbl_models_img = gcnew TransparentLabel();

	// tlbl_info

	tlbl_info->AutoSize = true;
	tlbl_info->Location = System::Drawing::Point(76, 59);
	tlbl_info->Name = "tlbl_info";
	tlbl_info->Size = System::Drawing::Size(25, 13);
	tlbl_info->Text = "Info";

	// tlbl_info_img

	tlbl_info_img->AutoSize = true;
	tlbl_info_img->Image = GetResourceImage(ICN_INFORMATION);
	tlbl_info_img->Location = System::Drawing::Point(52, 55);
	tlbl_info_img->Name = "tlbl_info_img";
	tlbl_info_img->Padding = System::Windows::Forms::Padding(3);
	tlbl_info_img->Size = System::Drawing::Size(31, 19);
	tlbl_info_img->Text = "      ";

	// tlbl_textures

	tlbl_textures->AutoSize = true;
	tlbl_textures->Location = System::Drawing::Point(202, 59);
	tlbl_textures->Name = "tlbl_textures";
	tlbl_textures->Size = System::Drawing::Size(48, 13);
	tlbl_textures->Text = "Textures";

	// tlbl_textures_img

	tlbl_textures_img->AutoSize = true;
	tlbl_textures_img->Image = GetResourceImage(ICN_IMAGE);
	tlbl_textures_img->Location = System::Drawing::Point(181, 55);
	tlbl_textures_img->Name = "tlbl_textures_img";
	tlbl_textures_img->Padding = System::Windows::Forms::Padding(3);
	tlbl_textures_img->Size = System::Drawing::Size(25, 19);
	tlbl_textures_img->Text = "    ";

	// tlbl_textures

	tlbl_models->AutoSize = true;
	tlbl_models->Location = System::Drawing::Point(342, 59);
	tlbl_models->Name = "tlbl_models";
	tlbl_models->Size = System::Drawing::Size(41, 13);
	tlbl_models->Text = "Models";

	// tlbl_models_img

	tlbl_models_img->AutoSize = true;
	tlbl_models_img->Image = GetResourceImage(ICN_STAIRS);
	tlbl_models_img->Location = System::Drawing::Point(310, 56);
	tlbl_models_img->Name = "tlbl_models_img";
	tlbl_models_img->Padding = System::Windows::Forms::Padding(3);
	tlbl_models_img->Size = System::Drawing::Size(46, 19);
	tlbl_models_img->Text = "           ";

	if (global::Type == Rct3PathType::Queue)
		this->btn_create->Text = L"Create my queue!";
	else
		this->btn_create->Text = L"Create my path!";

	if (global::Type == Rct3PathType::Queue)
		this->lbl_information->Text = L"Here you can load your icon, texture, and models for your queue.";
	else
		this->lbl_information->Text = L"Here you can load your icon, textures, and models for your path.";


	this->Controls->Add(tlbl_info);
	this->Controls->Add(tlbl_info_img);
	this->Controls->Add(tlbl_textures);
	this->Controls->Add(tlbl_textures_img);
	this->Controls->Add(tlbl_models);
	this->Controls->Add(tlbl_models_img);

	tlbl_info->BringToFront();
	tlbl_info_img->BringToFront();
	tlbl_textures->BringToFront();
	tlbl_textures_img->BringToFront();
	tlbl_models->BringToFront();
	tlbl_models_img->BringToFront();

	if (global::Type == Rct3PathType::Basic)
	{
		InfoControl^ info = gcnew InfoControl();
		TextureControl^ texture = gcnew TextureControl();
		ModelsControl^ models = gcnew ModelsControl();

		PanelControls = gcnew List<Control^>(3);
		PanelControls->Add(info);
		PanelControls->Add(texture);
		PanelControls->Add(models);

		Control^ defaultPanel = PanelControls[0];
		defaultPanel->Left = panel->Width / 2 - defaultPanel->Width / 2;
		defaultPanel->Top = panel->Height / 2 - defaultPanel->Height / 2;
		panel->Controls->Add(defaultPanel);
	}
	else if (global::Type == Rct3PathType::Extended)
	{
		InfoControl^ info = gcnew InfoControl();
		TextureControl^ texture = gcnew TextureControl();
		ExtendedModelsControl^ models = gcnew ExtendedModelsControl();

		PanelControls = gcnew List<Control^>(3);
		PanelControls->Add(info);
		PanelControls->Add(texture);
		PanelControls->Add(models);

		Control^ defaultPanel = PanelControls[0];
		defaultPanel->Left = panel->Width / 2 - defaultPanel->Width / 2;
		defaultPanel->Top = panel->Height / 2 - defaultPanel->Height / 2;
		panel->Controls->Add(defaultPanel);

	}
	else
	{
		InfoControl^ info = gcnew InfoControl();
		QueueTextureControl^ texture = gcnew QueueTextureControl();
		QueueModelsControl^ models = gcnew QueueModelsControl();

		PanelControls = gcnew List<Control^>(3);
		PanelControls->Add(info);
		PanelControls->Add(texture);
		PanelControls->Add(models);

		Control^ defaultPanel = PanelControls[0];
		defaultPanel->Left = panel->Width / 2 - defaultPanel->Width / 2;
		defaultPanel->Top = panel->Height / 2 - defaultPanel->Height / 2;
		panel->Controls->Add(defaultPanel);
	}
}

MainWindow::~MainWindow() {
	if (components)
	{
		delete components;
	}
}

void MainWindow::ShowOrHideStatusBar() {
	animateTimer->Enabled = true;
}

void MainWindow::MainWindow_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
	activeWindow = nullptr;
	HomeWindow::activeWindow->Show();
}

void MainWindow::panelTimer_Tick(System::Object^  sender, System::EventArgs^  e) {
	if (_mode == Mode::Next) {
		if (_exitLeft <= panel->Controls[0]->Left)
			panel->Controls[0]->Left -= 50;

		if (_stopLeft <= panel->Controls[1]->Left)
			panel->Controls[1]->Left = panel->Controls[1]->Left - 50 < _stopLeft ? _stopLeft : panel->Controls[1]->Left - 50;

		if (_exitLeft >= panel->Controls[0]->Left && _stopLeft >= panel->Controls[1]->Left)
		{
			panel->Controls->RemoveAt(0);
			panelTimer->Enabled = false;
		}
	}
	else {
		if (_exitLeft >= panel->Controls[0]->Left)
			panel->Controls[0]->Left += 50;

		if (_stopLeft >= panel->Controls[1]->Left)
			panel->Controls[1]->Left = panel->Controls[1]->Left + 50 > _stopLeft ? _stopLeft : panel->Controls[1]->Left + 50;

		if (_exitLeft <= panel->Controls[0]->Left && _stopLeft <= panel->Controls[1]->Left)
		{
			panel->Controls->RemoveAt(0);
			panelTimer->Enabled = false;
		}
	}
}

void MainWindow::LoadControl(Mode mode) {
	int currentIndex = PanelControls->IndexOf(panel->Controls[0]);
	int loadIndex = 0, exitLeft = 0, entranceLeft = 0, stopLeft = 0;

	if (mode == Mode::Next)
	{
		loadIndex = currentIndex == PanelControls->Count - 1 ? 0 : ++currentIndex;
		exitLeft = -((panel->Width / 2 - PanelControls[currentIndex]->Width / 2) + PanelControls[currentIndex]->Width);
		entranceLeft = panel->Width;
	}
	else
	{
		loadIndex = currentIndex == 0 ? PanelControls->Count - 1 : --currentIndex;
		exitLeft = panel->Width;
		entranceLeft = -panel->Width;
	}

	stopLeft = panel->Width / 2 - PanelControls[loadIndex]->Width / 2;

	PanelControls[loadIndex]->Left = entranceLeft;
	panel->Controls->Add(PanelControls[loadIndex]);

	this->_mode = mode;
	this->_exitLeft = exitLeft;
	this->_stopLeft = stopLeft;

	panelTimer->Enabled = true;
}

void MainWindow::btn_previous_Click(System::Object^  sender, System::EventArgs^  e) {
	if (panelTimer->Enabled)
		return;

	LoadControl(Mode::Previous);

	if (panel->Controls[0] == PanelControls[1])
	{
		bar_info->BackgroundImage = GetResourceImage(IMG_BAR_DECOR_B);
		bar_textures->BackgroundImage = GetResourceImage(IMG_BAR_DECOR);
		bar_models->BackgroundImage = GetResourceImage(IMG_BAR_DECOR);

		safe_cast<Control^>(tlbl_info_img)->Refresh();
		safe_cast<Control^>(tlbl_textures_img)->Refresh();
		safe_cast<Control^>(tlbl_info)->Refresh();
		safe_cast<Control^>(tlbl_textures)->Refresh();
	}
	else if (panel->Controls[0] == PanelControls[2])
	{
		bar_textures->BackgroundImage = GetResourceImage(IMG_BAR_DECOR_B);
		bar_models->BackgroundImage = GetResourceImage(IMG_BAR_DECOR);
		bar_info->BackgroundImage = GetResourceImage(IMG_BAR_DECOR);

		safe_cast<Control^>(tlbl_textures_img)->Refresh();
		safe_cast<Control^>(tlbl_models_img)->Refresh();
		safe_cast<Control^>(tlbl_models)->Refresh();
		safe_cast<Control^>(tlbl_textures)->Refresh();
	}
	else
	{
		bar_models->BackgroundImage = GetResourceImage(IMG_BAR_DECOR_B);
		bar_textures->BackgroundImage = GetResourceImage(IMG_BAR_DECOR);
		bar_info->BackgroundImage = GetResourceImage(IMG_BAR_DECOR);

		safe_cast<Control^>(tlbl_info)->Refresh();
		safe_cast<Control^>(tlbl_models)->Refresh();
		safe_cast<Control^>(tlbl_info_img)->Refresh();
		safe_cast<Control^>(tlbl_models_img)->Refresh();
	}
}

void MainWindow::btn_next_Click(System::Object^  sender, System::EventArgs^  e) {
	if (panelTimer->Enabled)
		return;

	LoadControl(Mode::Next);

	if (panel->Controls[0] == PanelControls[2])
	{
		bar_info->BackgroundImage = GetResourceImage(IMG_BAR_DECOR_B);
		bar_textures->BackgroundImage = GetResourceImage(IMG_BAR_DECOR);
		bar_models->BackgroundImage = GetResourceImage(IMG_BAR_DECOR);

		safe_cast<Control^>(tlbl_info_img)->Refresh();
		safe_cast<Control^>(tlbl_models_img)->Refresh();
		safe_cast<Control^>(tlbl_info)->Refresh();
		safe_cast<Control^>(tlbl_models)->Refresh();
	}
	else if (panel->Controls[0] == PanelControls[0])
	{
		bar_textures->BackgroundImage = GetResourceImage(IMG_BAR_DECOR_B);
		bar_models->BackgroundImage = GetResourceImage(IMG_BAR_DECOR);
		bar_info->BackgroundImage = GetResourceImage(IMG_BAR_DECOR);

		safe_cast<Control^>(tlbl_info)->Refresh();
		safe_cast<Control^>(tlbl_textures)->Refresh();
		safe_cast<Control^>(tlbl_info_img)->Refresh();
		safe_cast<Control^>(tlbl_textures_img)->Refresh();
	}
	else
	{
		bar_models->BackgroundImage = GetResourceImage(IMG_BAR_DECOR_B);
		bar_textures->BackgroundImage = GetResourceImage(IMG_BAR_DECOR);
		bar_info->BackgroundImage = GetResourceImage(IMG_BAR_DECOR);

		safe_cast<Control^>(tlbl_textures)->Refresh();
		safe_cast<Control^>(tlbl_models)->Refresh();
		safe_cast<Control^>(tlbl_textures_img)->Refresh();
		safe_cast<Control^>(tlbl_models_img)->Refresh();
	}
}

void MainWindow::saveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	if (global::SavedDirectory == nullptr) {

		if (sfd_saveProject->ShowDialog(this) ==::DialogResult::OK) {
			global::SavedDirectory = sfd_saveProject->FileName;

			RecentProject proj;
			proj.FileName = global::SavedDirectory;
			proj.ProjectName = global::ProjectName;
			global::Settings->AddRecentProject(proj);

			switch (global::Type) {
				case Rct3PathType::Basic:

					if (global::Basic->saveAsCpath(global::SavedDirectory, global::IsDarkHorizons))
					{
						MessageBox::Show("Project successfully saved.", "Success!", MessageBoxButtons::OK, MessageBoxIcon::Information);
					}

					break;
				case Rct3PathType::Extended:

					if (global::Extended->saveAsCpath(global::SavedDirectory, global::IsDarkHorizons))
					{
						MessageBox::Show("Project successfully saved.", "Success!", MessageBoxButtons::OK, MessageBoxIcon::Information);
					}

					break;
				case Rct3PathType::Queue:

					if (global::Queue->saveAsCpath(global::SavedDirectory, global::IsDarkHorizons))
					{
						MessageBox::Show("Project successfully saved.", "Success!", MessageBoxButtons::OK, MessageBoxIcon::Information);
					}

					break;
			}
		}
	}
	else {

		RecentProject proj;
		proj.FileName = global::SavedDirectory;
		proj.ProjectName = global::ProjectName;
		global::Settings->AddRecentProject(proj);

		switch (global::Type) {
		case Rct3PathType::Basic:

			if (global::Basic->saveAsCpath(global::SavedDirectory, global::IsDarkHorizons))
			{
				MessageBox::Show("Project successfully saved.", "Success!", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}

			break;
		case Rct3PathType::Extended:

			if (global::Extended->saveAsCpath(global::SavedDirectory, global::IsDarkHorizons))
			{
				MessageBox::Show("Project successfully saved.", "Success!", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}

			break;
		case Rct3PathType::Queue:

			if (global::Queue->saveAsCpath(global::SavedDirectory, global::IsDarkHorizons))
			{
				MessageBox::Show("Project successfully saved.", "Success!", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}

			break;
		}
	}
}

void MainWindow::saveAsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	if (sfd_saveProject->ShowDialog(this) ==::DialogResult::OK) {
		global::SavedDirectory = sfd_saveProject->FileName;

		RecentProject proj;
		proj.FileName = global::SavedDirectory;
		proj.ProjectName = global::ProjectName;
		global::Settings->AddRecentProject(proj);

		switch (global::Type) {
			case Rct3PathType::Basic:

				if (global::Basic->saveAsCpath(global::SavedDirectory, global::IsDarkHorizons))
					MessageBox::Show("Project successfully saved.", "Success!", MessageBoxButtons::OK, MessageBoxIcon::Information);

				break;
			case Rct3PathType::Extended:

				if (global::Extended->saveAsCpath(global::SavedDirectory, global::IsDarkHorizons))
					MessageBox::Show("Project successfully saved.", "Success!", MessageBoxButtons::OK, MessageBoxIcon::Information);

				break;
			case Rct3PathType::Queue:

				if (global::Queue->saveAsCpath(global::SavedDirectory, global::IsDarkHorizons))
					MessageBox::Show("Project successfully saved.", "Success!", MessageBoxButtons::OK, MessageBoxIcon::Information);

				break;
		}
	}
}

void MainWindow::clearAllFieldsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	switch (global::Type) {
		case Rct3PathType::Basic:
			InfoControl::activeInstance->reset();
			TextureControl::activeInstance->reset();
			ModelsControl::activeInstance->reset();
			return;
		case Rct3PathType::Extended:
			InfoControl::activeInstance->reset();
			TextureControl::activeInstance->reset();
			ExtendedModelsControl::activeInstance->reset();
			return;
		case Rct3PathType::Queue:
			InfoControl::activeInstance->reset();
			QueueTextureControl::activeInstance->reset();
			QueueModelsControl::activeInstance->reset();
			return;
	}
}

void MainWindow::viewHelpToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	HelpWindow^ winHelp = gcnew HelpWindow();
	winHelp->ShowDialog(this);
}

void MainWindow::openProjectToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	if (ofd_openProject->ShowDialog(this) ==::DialogResult::OK) 
	{
		if (!global::openCpathProject(ofd_openProject->FileName))
			return;

		PanelControls->Clear();

		panel->Controls->RemoveAt(0);

		bar_textures->BackgroundImage = GetResourceImage(IMG_BAR_DECOR);
		bar_models->BackgroundImage = GetResourceImage(IMG_BAR_DECOR);
		bar_info->BackgroundImage = GetResourceImage(IMG_BAR_DECOR_B);

		String^ typeString = global::Type.ToString();

		this->Text = global::ProjectName + " (" + typeString + ") - RCT3 Path Creator 2.0";
		saveToolStripMenuItem->Text = "Save " + global::ProjectName;
		saveAsToolStripMenuItem->Text = "Save " + global::ProjectName + " as...";
	
		sfd_saveProject->Title = "Save " + global::ProjectName;
		sfd_saveProject->FileName = global::ProjectName + ".cpath";

		switch (global::Type) {
			case Rct3PathType::Basic: {
				InfoControl^ info = gcnew InfoControl();
				TextureControl^ texture = gcnew TextureControl();
				ModelsControl^ models = gcnew ModelsControl();

				info->update(Rct3PathType::Basic);
				texture->update();
				models->update();

				PanelControls = gcnew List<Control^>(3);
				PanelControls->Add(info);
				PanelControls->Add(texture);
				PanelControls->Add(models);

				Control^ defaultPanel = PanelControls[0];
				defaultPanel->Left = panel->Width / 2 - defaultPanel->Width / 2;
				defaultPanel->Top = panel->Height / 2 - defaultPanel->Height / 2;
				panel->Controls->Add(defaultPanel);
				}
				break;
			case Rct3PathType::Extended: {
				InfoControl^ info = gcnew InfoControl();
				TextureControl^ texture = gcnew TextureControl();
				ExtendedModelsControl^ models = gcnew ExtendedModelsControl();

				info->update(Rct3PathType::Extended);
				texture->update();
				models->update();

				PanelControls = gcnew List<Control^>(3);
				PanelControls->Add(info);
				PanelControls->Add(texture);
				PanelControls->Add(models);

				Control^ defaultPanel = PanelControls[0];
				defaultPanel->Left = panel->Width / 2 - defaultPanel->Width / 2;
				defaultPanel->Top = panel->Height / 2 - defaultPanel->Height / 2;
				panel->Controls->Add(defaultPanel);
				}
				break;
			case Rct3PathType::Queue: {
				InfoControl^ info = gcnew InfoControl();
				QueueTextureControl^ texture = gcnew QueueTextureControl();
				QueueModelsControl^ models = gcnew QueueModelsControl();

				info->update(Rct3PathType::Queue);
				texture->update();
				models->update();

				PanelControls = gcnew List<Control^>(3);
				PanelControls->Add(info);
				PanelControls->Add(texture);
				PanelControls->Add(models);

				Control^ defaultPanel = PanelControls[0];
				defaultPanel->Left = panel->Width / 2 - defaultPanel->Width / 2;
				defaultPanel->Top = panel->Height / 2 - defaultPanel->Height / 2;
				panel->Controls->Add(defaultPanel);
				}
				break;
		}
	}
}

void MainWindow::animateTimer_Tick(System::Object^  sender, System::EventArgs^  e) {
	if (!statusStrip->Visible) {
		while (this->Height != 330)
		{
			this->Height++;
		}
		animateTimer->Enabled = false;
		statusStrip->Visible = true;
	}
	else
	{
		statusStrip->Visible = false;
		while (this->Height != 311)
		{
			this->Height--;
		}
		animateTimer->Enabled = false;
	}
}

void MainWindow::btn_create_Click(System::Object^  sender, System::EventArgs^  e) {
	if (!Ready) {
		String^ errors;

		switch (global::Type) {
			case Rct3PathType::Basic:
			case Rct3PathType::Extended:
				errors = global::Basic->incomplete();

				MessageBox::Show(errors, "Error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			case Rct3PathType::Queue:
				errors = global::Queue->incomplete();

				MessageBox::Show(errors, "Error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
		}
	}

	if (!ovlWorker->IsBusy) {

		String^ folder = "";
		
		if (global::Type == Rct3PathType::Queue)
			folder = "My Queues\\";
		else
			folder = "My Paths\\";

		if (!Directory::Exists(folder))
			Directory::CreateDirectory(folder);

		Application::UseWaitCursor = true;
		Application::DoEvents();

		ovlWorker->RunWorkerAsync(folder);
	}
}

void MainWindow::ovlWorker_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
	String^ folder = safe_cast<String^>(e->Argument);

	RCT3Debugging::OutputLog log;

	log.Info("Path Creator 2.0: Initializing...");
	
	if (global::Settings->DebugLog)
		log.EnableDebugging();

	switch (global::Type) {
		case Rct3PathType::Basic: 
		{
			String^ dir = folder + global::Basic->Name + "\\";

			if (Directory::Exists(dir))
				Directory::Delete(dir, true);

			Directory::CreateDirectory(dir);

			global::Basic->CreateTextureOVL(dir + global::Basic->Name + "_Texture", log);
			global::Basic->CreateIconOVL(dir + global::Basic->Name + "_Icon", log);
			global::Basic->CreateStubOVL(dir + global::Basic->Name + "_Stub", log);
			global::Basic->CreateBlankOVL(dir + global::Basic->Name, log);
			global::Basic->copyFilesTo(dir);

			if (log.ErrorCount())
			{
				MessageBox::Show(this, "There were error(s) creating your path.\n"
					+ marshal_as<String^>(log.GetErrors()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				break;
			}

			if (Directory::Exists(global::Settings->RCT3InstallDirectory))
			{
				if (MessageBox::Show(this, "Path successfully created!"
					" Would you like to install?", "Install?", MessageBoxButtons::YesNo, MessageBoxIcon::Question)
					== ::DialogResult::Yes)
				{
					String^ dest = global::Settings->RCT3InstallDirectory;
					try
					{

						if (!dest->EndsWith("\\"))
							dest += "\\";

						String^ installDest = dest + "Path\\" + global::Basic->Name;

						if (Directory::Exists(installDest))
							Directory::Delete(installDest, true);

						Microsoft::VisualBasic::Devices::Computer^ comp = gcnew Microsoft::VisualBasic::Devices::Computer();

						comp->FileSystem->CopyDirectory(dir, installDest);

						MessageBox::Show(this, "Path successfully installed!", "Success",
							MessageBoxButtons::OK, MessageBoxIcon::Information);
					}
					catch (Exception^ ex)
					{
						String^ msg = "Couldn't copy path files to \""
							+ dest + "\": ";

						if (ex->Message->Contains("Access") && ex->Message->Contains("denied"))
						{
							msg += "Path Creator doesn't have sufficient provileges to access"
								" this directory. Try running the program as an Administrator.";

						}
						else
							msg += ex->Message;

						MessageBox::Show(this, msg, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					}
				}
			}
			else
			{
				MessageBox::Show(this, "Path successfully created!"
					" You can find your created path in the \"My Paths\" folder"
					" in the Path Creator folder.", "Finished", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}

			log.Info("Path Creator 2.0: Path successfully created.");
		}
			break;
		case Rct3PathType::Extended: 
		{

			String^ dir = folder + global::Extended->Base->Name + "\\";

			if (Directory::Exists(dir))
				Directory::Delete(dir, true);

			Directory::CreateDirectory(dir);

			global::Extended->CreateTextureOVL(dir + global::Extended->Base->Name + "_Texture", log);
			global::Extended->CreateIconOVL(dir + global::Extended->Base->Name + "_Icon", log);
			global::Extended->CreateStubOVL(dir + global::Extended->Base->Name + "_Stub", log);
			global::Extended->CreateBlankOVL(dir + global::Extended->Base->Name, log);
			global::Extended->copyFilesTo(dir);

			if (log.ErrorCount())
			{
				MessageBox::Show(this, "There were error(s) creating your path.\n"
					+ marshal_as<String^>(log.GetErrors()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				break;
			}

			if (Directory::Exists(global::Settings->RCT3InstallDirectory))
			{
				if (MessageBox::Show(this, "Path successfully created!"
					" Would you like to install?", "Install?", MessageBoxButtons::YesNo, MessageBoxIcon::Question)
					== ::DialogResult::Yes)
				{
					String^ dest = global::Settings->RCT3InstallDirectory;
					try
					{

						if (!dest->EndsWith("\\"))
							dest += "\\";

						String^ installDest = dest + "Path\\" + global::Extended->Base->Name;

						if (Directory::Exists(installDest))
							Directory::Delete(installDest, true);

						Microsoft::VisualBasic::Devices::Computer^ comp = gcnew Microsoft::VisualBasic::Devices::Computer();

						comp->FileSystem->CopyDirectory(dir, installDest);

						MessageBox::Show(this, "Path successfully installed!", "Success",
							MessageBoxButtons::OK, MessageBoxIcon::Information);
					}
					catch (Exception^ ex)
					{
						String^ msg = "Couldn't copy path files to \""
							+ dest + "\": ";

						if (ex->Message->Contains("Access") && ex->Message->Contains("denied"))
						{
							msg += "Path Creator doesn't have sufficient provileges to access"
								" this directory. Try running the program as an Administrator.";

						}
						else
							msg += ex->Message;

						MessageBox::Show(this, msg, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					}
				}
			}
			else
			{
				MessageBox::Show(this, "Path successfully created!"
					" You can find your created path in the \"My Paths\" folder"
					" in the Path Creator folder.", "Finished", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}

			log.Info("Path Creator 2.0: Path successfully created.");
		}
			break;
		case Rct3PathType::Queue: 
		{

			String^ dir = folder + global::Queue->Name + "\\";

			if (Directory::Exists(dir))
				Directory::Delete(dir, true);

			Directory::CreateDirectory(dir);

			global::Queue->CreateTextureOVL(dir + global::Queue->Name + "_Texture", log);
			global::Queue->CreateIconOVL(dir + global::Queue->Name + "_Icon", log);
			global::Queue->CreateStubOVL(dir + global::Queue->Name + "_Stub", log);
			global::Queue->CreateBlankOVL(dir + global::Queue->Name, log);
			global::Queue->copyFilesTo(dir);

			if (log.ErrorCount())
			{
				MessageBox::Show(this, "There were error(s) creating your queue.\n"
					+ marshal_as<String^>(log.GetErrors()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				break;
			}

			if (Directory::Exists(global::Settings->RCT3InstallDirectory))
			{
				if (MessageBox::Show(this, "Queue successfully created!"
					" Would you like to install?", "Install?", MessageBoxButtons::YesNo, MessageBoxIcon::Question)
					== ::DialogResult::Yes)
				{
					String^ dest = global::Settings->RCT3InstallDirectory;
					try
					{

						if (!dest->EndsWith("\\"))
							dest += "\\";

						String^ installDest = dest + "Queue\\" + global::Queue->Name;

						if (Directory::Exists(installDest))
							Directory::Delete(installDest, true);

						Microsoft::VisualBasic::Devices::Computer^ comp = gcnew Microsoft::VisualBasic::Devices::Computer();

						comp->FileSystem->CopyDirectory(dir, installDest);

						MessageBox::Show(this, "Queue successfully installed!", "Success",
							MessageBoxButtons::OK, MessageBoxIcon::Information);
					}
					catch (Exception^ ex)
					{
						String^ msg = "Couldn't copy queue files to \""
							+ dest + "\": ";

						if (ex->Message->Contains("Access") && ex->Message->Contains("denied"))
						{
							msg += "Path Creator doesn't have sufficient provileges to access"
								" this directory. Try running the program as an Administrator.";

						}
						else
							msg += ex->Message;

						MessageBox::Show(this, msg, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					}
				}
			}
			else
			{
				MessageBox::Show(this, "Queue successfully created!"
					" You can find your created queue in the \"My Queues\" folder"
					" in the Path Creator folder.", "Finished", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}

			log.Info("Path Creator 2.0: Queue successfully created.");
		}
			break;
	}
	String^ logSave = folder + global::ProjectName + ".log";
	log.SaveToFile(marshal_as<std::string>(logSave));
}

void MainWindow::exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (MessageBox::Show(this, "Are you sure you want to exit?", "Exit application?", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == ::DialogResult::Yes) 
	{
		if (global::Settings->SaveOnExit)
			global::Settings->Save();

		Environment::Exit(0);
	}
}