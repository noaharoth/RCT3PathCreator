// MainWindow.h

#pragma once

#include "stdafx.h"
#include "global.h"
#include "TransparentLabel.h"
#include "HomeWindow.h"
#include "InfoControl.h"
#include "TextureControl.h"
#include "QueueTextureControl.h"
#include "ModelsControl.h"
#include "QueueModelsControl.h"
#include "ExtendedModelsControl.h"
#include "AboutWindow.h"
#include "ProgramSettingsWindow.h"

namespace PathCreator {

#define FORM_SIZE_DEFAULT System::Drawing::Size(434, 273)
#define FORM_STATUS_SIZE System::Drawing::Size(434, 273)

	/// <summary>
	/// Summary for MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	private:
		enum class Mode { Previous, Next };
		List<Control^> ^PanelControls;
		bool ready;

		Mode _mode;
		int _exitLeft;
		int _stopLeft;

		System::Windows::Forms::PictureBox^  bar_models;
	    System::Windows::Forms::PictureBox^  bar_textures;
	    System::Windows::Forms::PictureBox^  bar_info;
		System::Windows::Forms::StatusStrip^  statusStrip;
	    System::Windows::Forms::ToolStripProgressBar^  progress_status;
	    System::Windows::Forms::ToolStripStatusLabel^  lbl_status;
	    System::Windows::Forms::Button^  btn_create;
	    System::Windows::Forms::Button^  btn_next;
	    System::Windows::Forms::Button^  btn_previous;
	    System::Windows::Forms::Panel^  panel;
	    System::Windows::Forms::Label^  lbl_information;
		System::Windows::Forms::MenuStrip^  menuStrip;
	    System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	    System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	    System::Windows::Forms::ToolStripMenuItem^  saveAsToolStripMenuItem;

	    System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	    System::Windows::Forms::ToolStripMenuItem^  openProjectToolStripMenuItem;
	    System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;


	    System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	    System::Windows::Forms::ToolStripMenuItem^  editToolStripMenuItem;
	    System::Windows::Forms::ToolStripMenuItem^  clearAllFieldsToolStripMenuItem;
	    System::Windows::Forms::ToolStripMenuItem^  settingsToolStripMenuItem;

	    System::Windows::Forms::ToolStripMenuItem^  programSettingsToolStripMenuItem;
	    System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	    System::Windows::Forms::ToolStripMenuItem^  viewHelpToolStripMenuItem;
	    System::Windows::Forms::ToolStripSeparator^  toolStripSeparator4;
	    System::Windows::Forms::ToolStripMenuItem^  aboutRCT3PathCreatorToolStripMenuItem;
		System::ComponentModel::IContainer^  components;
		TransparentLabel^ tlbl_info;
		TransparentLabel^ tlbl_info_img;
		TransparentLabel^ tlbl_textures;
		TransparentLabel^ tlbl_textures_img;
		TransparentLabel^ tlbl_models;
		TransparentLabel^ tlbl_models_img;
		System::Windows::Forms::Timer^  panelTimer;
		System::Windows::Forms::SaveFileDialog^  sfd_saveProject;
		System::Windows::Forms::OpenFileDialog^  ofd_openProject;
		System::Windows::Forms::FolderBrowserDialog^  fbd_exportXmls;
		System::Windows::Forms::Timer^  animateTimer;
		System::ComponentModel::BackgroundWorker^  ovlWorker;
		System::Windows::Forms::FolderBrowserDialog^  fbd_pathSave;



	public:
		static MainWindow^ activeWindow;

		property bool Ready {
			bool get() {
				return ready;
			}
			void set(bool value) {
				ready = value;
                if (value) 
					btn_create->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
                else 
					btn_create->BackgroundImage = GetResourceImage(IMG_BUTTON_R);
			}
		}

		MainWindow(void);

	protected:
		~MainWindow();

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
	private:
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainWindow::typeid));
			this->bar_models = (gcnew System::Windows::Forms::PictureBox());
			this->bar_textures = (gcnew System::Windows::Forms::PictureBox());
			this->bar_info = (gcnew System::Windows::Forms::PictureBox());
			this->statusStrip = (gcnew System::Windows::Forms::StatusStrip());
			this->progress_status = (gcnew System::Windows::Forms::ToolStripProgressBar());
			this->lbl_status = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->btn_create = (gcnew System::Windows::Forms::Button());
			this->btn_next = (gcnew System::Windows::Forms::Button());
			this->btn_previous = (gcnew System::Windows::Forms::Button());
			this->panel = (gcnew System::Windows::Forms::Panel());
			this->lbl_information = (gcnew System::Windows::Forms::Label());
			this->menuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveAsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->openProjectToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clearAllFieldsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->settingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->programSettingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viewHelpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator4 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->aboutRCT3PathCreatorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->panelTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->sfd_saveProject = (gcnew System::Windows::Forms::SaveFileDialog());
			this->ofd_openProject = (gcnew System::Windows::Forms::OpenFileDialog());
			this->fbd_exportXmls = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->animateTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->ovlWorker = (gcnew System::ComponentModel::BackgroundWorker());
			this->fbd_pathSave = (gcnew System::Windows::Forms::FolderBrowserDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bar_models))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bar_textures))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bar_info))->BeginInit();
			this->statusStrip->SuspendLayout();
			this->menuStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// bar_models
			// 
			this->bar_models->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->bar_models->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->bar_models->Location = System::Drawing::Point(285, 54);
			this->bar_models->Name = L"bar_models";
			this->bar_models->Size = System::Drawing::Size(137, 23);
			this->bar_models->TabIndex = 31;
			this->bar_models->TabStop = false;
			// 
			// bar_textures
			// 
			this->bar_textures->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->bar_textures->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->bar_textures->Location = System::Drawing::Point(147, 54);
			this->bar_textures->Name = L"bar_textures";
			this->bar_textures->Size = System::Drawing::Size(139, 23);
			this->bar_textures->TabIndex = 30;
			this->bar_textures->TabStop = false;
			// 
			// bar_info
			// 
			this->bar_info->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->bar_info->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->bar_info->Location = System::Drawing::Point(11, 54);
			this->bar_info->Name = L"bar_info";
			this->bar_info->Size = System::Drawing::Size(137, 23);
			this->bar_info->TabIndex = 29;
			this->bar_info->TabStop = false;
			// 
			// statusStrip
			// 
			this->statusStrip->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->statusStrip->Enabled = false;
			this->statusStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->progress_status,
					this->lbl_status
			});
			this->statusStrip->Location = System::Drawing::Point(0, 271);
			this->statusStrip->Name = L"statusStrip";
			this->statusStrip->Size = System::Drawing::Size(433, 22);
			this->statusStrip->SizingGrip = false;
			this->statusStrip->TabIndex = 28;
			this->statusStrip->Text = L"Status";
			this->statusStrip->Visible = false;
			// 
			// progress_status
			// 
			this->progress_status->Enabled = false;
			this->progress_status->MarqueeAnimationSpeed = 35;
			this->progress_status->Name = L"progress_status";
			this->progress_status->Size = System::Drawing::Size(100, 16);
			this->progress_status->Style = System::Windows::Forms::ProgressBarStyle::Marquee;
			// 
			// lbl_status
			// 
			this->lbl_status->Name = L"lbl_status";
			this->lbl_status->Size = System::Drawing::Size(88, 17);
			this->lbl_status->Text = L"Creating path...";
			// 
			// btn_create
			// 
			this->btn_create->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_create->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_create->Location = System::Drawing::Point(114, 240);
			this->btn_create->Name = L"btn_create";
			this->btn_create->Size = System::Drawing::Size(204, 23);
			this->btn_create->TabIndex = 27;
			this->btn_create->Text = L"Create my path!";
			this->btn_create->UseVisualStyleBackColor = true;
			this->btn_create->Click += gcnew System::EventHandler(this, &MainWindow::btn_create_Click);
			// 
			// btn_next
			// 
			this->btn_next->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_next->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_next->Location = System::Drawing::Point(372, 240);
			this->btn_next->Name = L"btn_next";
			this->btn_next->Size = System::Drawing::Size(50, 23);
			this->btn_next->TabIndex = 26;
			this->btn_next->UseVisualStyleBackColor = true;
			this->btn_next->Click += gcnew System::EventHandler(this, &MainWindow::btn_next_Click);
			// 
			// btn_previous
			// 
			this->btn_previous->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_previous->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_previous->Location = System::Drawing::Point(11, 240);
			this->btn_previous->Name = L"btn_previous";
			this->btn_previous->Size = System::Drawing::Size(50, 23);
			this->btn_previous->TabIndex = 25;
			this->btn_previous->UseVisualStyleBackColor = true;
			this->btn_previous->Click += gcnew System::EventHandler(this, &MainWindow::btn_previous_Click);
			// 
			// panel
			// 
			this->panel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel->Location = System::Drawing::Point(11, 76);
			this->panel->Name = L"panel";
			this->panel->Size = System::Drawing::Size(411, 161);
			this->panel->TabIndex = 24;
			// 
			// lbl_information
			// 
			this->lbl_information->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbl_information->AutoSize = true;
			this->lbl_information->Location = System::Drawing::Point(62, 33);
			this->lbl_information->Name = L"lbl_information";
			this->lbl_information->Size = System::Drawing::Size(308, 13);
			this->lbl_information->TabIndex = 23;
			this->lbl_information->Text = L"Here you can load your icon, textures, and models for your path.";
			// 
			// menuStrip
			// 
			this->menuStrip->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->menuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->fileToolStripMenuItem,
					this->editToolStripMenuItem, this->settingsToolStripMenuItem, this->helpToolStripMenuItem
			});
			this->menuStrip->Location = System::Drawing::Point(0, 0);
			this->menuStrip->Name = L"menuStrip";
			this->menuStrip->Size = System::Drawing::Size(434, 24);
			this->menuStrip->TabIndex = 22;
			this->menuStrip->Text = L"Menu";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->saveToolStripMenuItem,
					this->saveAsToolStripMenuItem, this->toolStripSeparator1, this->openProjectToolStripMenuItem, this->toolStripSeparator2, this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->saveToolStripMenuItem->Text = L"&Save...";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::saveToolStripMenuItem_Click);
			// 
			// saveAsToolStripMenuItem
			// 
			this->saveAsToolStripMenuItem->Name = L"saveAsToolStripMenuItem";
			this->saveAsToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->saveAsToolStripMenuItem->Text = L"Save as...";
			this->saveAsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::saveAsToolStripMenuItem_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(149, 6);
			// 
			// openProjectToolStripMenuItem
			// 
			this->openProjectToolStripMenuItem->Name = L"openProjectToolStripMenuItem";
			this->openProjectToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->openProjectToolStripMenuItem->Text = L"&Open project...";
			this->openProjectToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::openProjectToolStripMenuItem_Click);
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(149, 6);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->exitToolStripMenuItem->Text = L"&Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::exitToolStripMenuItem_Click);
			// 
			// editToolStripMenuItem
			// 
			this->editToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->clearAllFieldsToolStripMenuItem });
			this->editToolStripMenuItem->Name = L"editToolStripMenuItem";
			this->editToolStripMenuItem->Size = System::Drawing::Size(39, 20);
			this->editToolStripMenuItem->Text = L"Edit";
			// 
			// clearAllFieldsToolStripMenuItem
			// 
			this->clearAllFieldsToolStripMenuItem->Name = L"clearAllFieldsToolStripMenuItem";
			this->clearAllFieldsToolStripMenuItem->Size = System::Drawing::Size(147, 22);
			this->clearAllFieldsToolStripMenuItem->Text = L"Clear all fields";
			this->clearAllFieldsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::clearAllFieldsToolStripMenuItem_Click);
			// 
			// settingsToolStripMenuItem
			// 
			this->settingsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->programSettingsToolStripMenuItem });
			this->settingsToolStripMenuItem->Name = L"settingsToolStripMenuItem";
			this->settingsToolStripMenuItem->Size = System::Drawing::Size(61, 20);
			this->settingsToolStripMenuItem->Text = L"Settings";
			// 
			// programSettingsToolStripMenuItem
			// 
			this->programSettingsToolStripMenuItem->Name = L"programSettingsToolStripMenuItem";
			this->programSettingsToolStripMenuItem->Size = System::Drawing::Size(173, 22);
			this->programSettingsToolStripMenuItem->Text = L"Program settings...";
			this->programSettingsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::programSettingsToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->viewHelpToolStripMenuItem,
					this->toolStripSeparator4, this->aboutRCT3PathCreatorToolStripMenuItem
			});
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// viewHelpToolStripMenuItem
			// 
			this->viewHelpToolStripMenuItem->Name = L"viewHelpToolStripMenuItem";
			this->viewHelpToolStripMenuItem->Size = System::Drawing::Size(207, 22);
			this->viewHelpToolStripMenuItem->Text = L"&View Help";
			this->viewHelpToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::viewHelpToolStripMenuItem_Click);
			// 
			// toolStripSeparator4
			// 
			this->toolStripSeparator4->Name = L"toolStripSeparator4";
			this->toolStripSeparator4->Size = System::Drawing::Size(204, 6);
			// 
			// aboutRCT3PathCreatorToolStripMenuItem
			// 
			this->aboutRCT3PathCreatorToolStripMenuItem->Name = L"aboutRCT3PathCreatorToolStripMenuItem";
			this->aboutRCT3PathCreatorToolStripMenuItem->Size = System::Drawing::Size(207, 22);
			this->aboutRCT3PathCreatorToolStripMenuItem->Text = L"&About RCT3 Path Creator";
			this->aboutRCT3PathCreatorToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::aboutRCT3PathCreatorToolStripMenuItem_Click);
			// 
			// panelTimer
			// 
			this->panelTimer->Interval = 10;
			this->panelTimer->Tick += gcnew System::EventHandler(this, &MainWindow::panelTimer_Tick);
			// 
			// sfd_saveProject
			// 
			this->sfd_saveProject->Filter = L"RCT3 Path Projects|*.cpath|All files|*.*";
			// 
			// ofd_openProject
			// 
			this->ofd_openProject->Filter = L"RCT3 Path Projects|*.cpath|All files|*.*";
			// 
			// animateTimer
			// 
			this->animateTimer->Interval = 20;
			this->animateTimer->Tick += gcnew System::EventHandler(this, &MainWindow::animateTimer_Tick);
			// 
			// ovlWorker
			// 
			this->ovlWorker->WorkerReportsProgress = true;
			this->ovlWorker->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MainWindow::ovlWorker_DoWork);
			this->ovlWorker->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MainWindow::ovlWorker_RunWorkerCompleted);
			// 
			// fbd_pathSave
			// 
			this->fbd_pathSave->Description = L"Select a folder to save your path in.";
			// 
			// MainWindow
			// 
			this->AcceptButton = this->btn_create;
			this->ClientSize = System::Drawing::Size(434, 273);
			this->Controls->Add(this->bar_models);
			this->Controls->Add(this->bar_textures);
			this->Controls->Add(this->bar_info);
			this->Controls->Add(this->statusStrip);
			this->Controls->Add(this->btn_create);
			this->Controls->Add(this->btn_next);
			this->Controls->Add(this->btn_previous);
			this->Controls->Add(this->panel);
			this->Controls->Add(this->lbl_information);
			this->Controls->Add(this->menuStrip);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip;
			this->MaximizeBox = false;
			this->Name = L"MainWindow";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L" - RCT3 Path Creator 2.0";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainWindow::MainWindow_FormClosing);
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MainWindow::MainWindow_FormClosed);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bar_models))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bar_textures))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bar_info))->EndInit();
			this->statusStrip->ResumeLayout(false);
			this->statusStrip->PerformLayout();
			this->menuStrip->ResumeLayout(false);
			this->menuStrip->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		void ShowOrHideStatusBar();

		void MainWindow_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e);

		void panelTimer_Tick(System::Object^  sender, System::EventArgs^  e);

		void LoadControl(Mode mode);

		void btn_previous_Click(System::Object^  sender, System::EventArgs^  e);

		void btn_next_Click(System::Object^  sender, System::EventArgs^  e);

		void saveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

		void saveAsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

		void clearAllFieldsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

		void viewHelpToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

		void openProjectToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

		void animateTimer_Tick(System::Object^  sender, System::EventArgs^  e);

		void btn_create_Click(System::Object^  sender, System::EventArgs^  e);

		void ovlWorker_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e);

		void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

		void aboutRCT3PathCreatorToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			About^ about = gcnew About();
			about->ShowDialog(this);
		}

		void programSettingsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			ProgramSettingsWindow^ win = gcnew ProgramSettingsWindow();
			win->ShowDialog(this);
		}

		void MainWindow_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) 
		{
			if (e->CloseReason == CloseReason::UserClosing)
			{
				if (MessageBox::Show(this, "Do you really want to exit?", "Exit", 
					MessageBoxButtons::YesNo, MessageBoxIcon::Question) ==::DialogResult::Yes)
				{
					if (global::Settings->SaveOnExit)
						global::Settings->Save();

					Environment::Exit(0);
				}
				else
				{
					e->Cancel = true;
				}
			}
			else
			{
				e->Cancel = true;
			}
		}

		void ovlWorker_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e)
		{
			Application::UseWaitCursor = false;
			Application::DoEvents();
		}
	};
}
