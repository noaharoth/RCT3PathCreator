// HomeWindow.h
// Home window.

#pragma once

#include "stdafx.h"
#include "global.h"
#include "HelpWindow.h"
#include "MainWindow.h"
#include "AboutWindow.h"
#include "ProgramSettingsWindow.h"
#include "UpdateWindow.h"

#define EMPTY_TEXT "Type in a name..."

namespace PathCreator {

	/// <summary>
	/// Summary for HomeWindow
	/// </summary>
	public ref class HomeWindow : public System::Windows::Forms::Form
	{
	private:
		bool textEmpty;

	    System::Windows::Forms::MenuStrip^  menuStrip;
	    System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	    System::Windows::Forms::ToolStripMenuItem^  settingsToolStripMenuItem;
	    System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	    System::Windows::Forms::ToolStripMenuItem^  openProjectToolStripMenuItem;
	    System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	    System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	    System::Windows::Forms::ToolStripMenuItem^  programSettingsToolStripMenuItem;
	    System::Windows::Forms::ToolStripMenuItem^  viewHelpToolStripMenuItem;
	    System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
	    System::Windows::Forms::ToolStripMenuItem^  aboutRCT3PathCreatorToolStripMenuItem;
	    System::Windows::Forms::Label^  lbl_type;
	    System::Windows::Forms::RadioButton^  rb_queue;
	    System::Windows::Forms::RadioButton^  rb_extended;
	    System::Windows::Forms::RadioButton^  rb_basic;
	    System::Windows::Forms::TextBox^  txt_projectName;
	    System::Windows::Forms::Label^  lbl_projname;
	    System::Windows::Forms::Button^  btn_begin;
	    System::Windows::Forms::Button^  btn_exit;
	    System::Windows::Forms::ListBox^  listbox_recent;
	    System::Windows::Forms::Label^  lbl_recent;
		System::Windows::Forms::OpenFileDialog^  ofd_openProject;
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::ToolStripMenuItem^  checkForUpdatesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator3;



	public:
		static HomeWindow^ activeWindow;

		HomeWindow(void);

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~HomeWindow();

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
	private:
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(HomeWindow::typeid));
			this->menuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openProjectToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->settingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->programSettingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viewHelpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->checkForUpdatesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->aboutRCT3PathCreatorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lbl_type = (gcnew System::Windows::Forms::Label());
			this->rb_queue = (gcnew System::Windows::Forms::RadioButton());
			this->rb_extended = (gcnew System::Windows::Forms::RadioButton());
			this->rb_basic = (gcnew System::Windows::Forms::RadioButton());
			this->txt_projectName = (gcnew System::Windows::Forms::TextBox());
			this->lbl_projname = (gcnew System::Windows::Forms::Label());
			this->btn_begin = (gcnew System::Windows::Forms::Button());
			this->btn_exit = (gcnew System::Windows::Forms::Button());
			this->listbox_recent = (gcnew System::Windows::Forms::ListBox());
			this->lbl_recent = (gcnew System::Windows::Forms::Label());
			this->ofd_openProject = (gcnew System::Windows::Forms::OpenFileDialog());
			this->menuStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip
			// 
			this->menuStrip->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->menuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->fileToolStripMenuItem,
					this->settingsToolStripMenuItem, this->helpToolStripMenuItem
			});
			this->menuStrip->Location = System::Drawing::Point(0, 0);
			this->menuStrip->Name = L"menuStrip";
			this->menuStrip->Size = System::Drawing::Size(402, 24);
			this->menuStrip->TabIndex = 0;
			this->menuStrip->Text = L"menu";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->openProjectToolStripMenuItem,
					this->toolStripSeparator1, this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openProjectToolStripMenuItem
			// 
			this->openProjectToolStripMenuItem->Name = L"openProjectToolStripMenuItem";
			this->openProjectToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->openProjectToolStripMenuItem->Text = L"Open project...";
			this->openProjectToolStripMenuItem->Click += gcnew System::EventHandler(this, &HomeWindow::openProjectToolStripMenuItem_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(149, 6);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &HomeWindow::exitToolStripMenuItem_Click);
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
			this->programSettingsToolStripMenuItem->Click += gcnew System::EventHandler(this, &HomeWindow::programSettingsToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->viewHelpToolStripMenuItem,
					this->toolStripSeparator2, this->checkForUpdatesToolStripMenuItem, this->toolStripSeparator3, this->aboutRCT3PathCreatorToolStripMenuItem
			});
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// viewHelpToolStripMenuItem
			// 
			this->viewHelpToolStripMenuItem->Name = L"viewHelpToolStripMenuItem";
			this->viewHelpToolStripMenuItem->Size = System::Drawing::Size(207, 22);
			this->viewHelpToolStripMenuItem->Text = L"View Help";
			this->viewHelpToolStripMenuItem->Click += gcnew System::EventHandler(this, &HomeWindow::viewHelpToolStripMenuItem_Click);
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(204, 6);
			// 
			// checkForUpdatesToolStripMenuItem
			// 
			this->checkForUpdatesToolStripMenuItem->Name = L"checkForUpdatesToolStripMenuItem";
			this->checkForUpdatesToolStripMenuItem->Size = System::Drawing::Size(207, 22);
			this->checkForUpdatesToolStripMenuItem->Text = L"Check for updates...";
			this->checkForUpdatesToolStripMenuItem->Click += gcnew System::EventHandler(this, &HomeWindow::checkForUpdatesToolStripMenuItem_Click);
			// 
			// toolStripSeparator3
			// 
			this->toolStripSeparator3->Name = L"toolStripSeparator3";
			this->toolStripSeparator3->Size = System::Drawing::Size(204, 6);
			// 
			// aboutRCT3PathCreatorToolStripMenuItem
			// 
			this->aboutRCT3PathCreatorToolStripMenuItem->Name = L"aboutRCT3PathCreatorToolStripMenuItem";
			this->aboutRCT3PathCreatorToolStripMenuItem->Size = System::Drawing::Size(207, 22);
			this->aboutRCT3PathCreatorToolStripMenuItem->Text = L"About RCT3 Path Creator";
			this->aboutRCT3PathCreatorToolStripMenuItem->Click += gcnew System::EventHandler(this, &HomeWindow::aboutRCT3PathCreatorToolStripMenuItem_Click);
			// 
			// lbl_type
			// 
			this->lbl_type->AutoSize = true;
			this->lbl_type->Location = System::Drawing::Point(175, 79);
			this->lbl_type->Name = L"lbl_type";
			this->lbl_type->Size = System::Drawing::Size(34, 13);
			this->lbl_type->TabIndex = 20;
			this->lbl_type->Text = L"Type:";
			// 
			// rb_queue
			// 
			this->rb_queue->AutoSize = true;
			this->rb_queue->Location = System::Drawing::Point(216, 123);
			this->rb_queue->Name = L"rb_queue";
			this->rb_queue->Size = System::Drawing::Size(57, 17);
			this->rb_queue->TabIndex = 19;
			this->rb_queue->TabStop = true;
			this->rb_queue->Text = L"Queue";
			this->rb_queue->UseVisualStyleBackColor = true;
			// 
			// rb_extended
			// 
			this->rb_extended->AutoSize = true;
			this->rb_extended->Location = System::Drawing::Point(216, 100);
			this->rb_extended->Name = L"rb_extended";
			this->rb_extended->Size = System::Drawing::Size(150, 17);
			this->rb_extended->TabIndex = 18;
			this->rb_extended->TabStop = true;
			this->rb_extended->Text = L"Path with extended pieces";
			this->rb_extended->UseVisualStyleBackColor = true;
			// 
			// rb_basic
			// 
			this->rb_basic->AutoSize = true;
			this->rb_basic->Checked = true;
			this->rb_basic->Location = System::Drawing::Point(216, 77);
			this->rb_basic->Name = L"rb_basic";
			this->rb_basic->Size = System::Drawing::Size(75, 17);
			this->rb_basic->TabIndex = 17;
			this->rb_basic->TabStop = true;
			this->rb_basic->Text = L"Basic path";
			this->rb_basic->UseVisualStyleBackColor = true;
			// 
			// txt_projectName
			// 
			this->txt_projectName->ForeColor = System::Drawing::Color::Gray;
			this->txt_projectName->Location = System::Drawing::Point(216, 48);
			this->txt_projectName->Name = L"txt_projectName";
			this->txt_projectName->Size = System::Drawing::Size(174, 20);
			this->txt_projectName->TabIndex = 16;
			this->txt_projectName->Text = L"Type in a name...";
			this->txt_projectName->TextChanged += gcnew System::EventHandler(this, &HomeWindow::txt_projectName_TextChanged);
			this->txt_projectName->Enter += gcnew System::EventHandler(this, &HomeWindow::txt_projectName_Enter);
			this->txt_projectName->Leave += gcnew System::EventHandler(this, &HomeWindow::txt_projectName_Leave);
			// 
			// lbl_projname
			// 
			this->lbl_projname->AutoSize = true;
			this->lbl_projname->Location = System::Drawing::Point(138, 51);
			this->lbl_projname->Name = L"lbl_projname";
			this->lbl_projname->Size = System::Drawing::Size(72, 13);
			this->lbl_projname->TabIndex = 15;
			this->lbl_projname->Text = L"Project name:";
			// 
			// btn_begin
			// 
			this->btn_begin->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_begin->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_begin->Location = System::Drawing::Point(138, 152);
			this->btn_begin->Name = L"btn_begin";
			this->btn_begin->Size = System::Drawing::Size(252, 23);
			this->btn_begin->TabIndex = 14;
			this->btn_begin->Text = L"Begin creating path!";
			this->btn_begin->UseVisualStyleBackColor = true;
			this->btn_begin->Click += gcnew System::EventHandler(this, &HomeWindow::btn_begin_Click);
			// 
			// btn_exit
			// 
			this->btn_exit->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_exit->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btn_exit->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_exit->Location = System::Drawing::Point(12, 152);
			this->btn_exit->Name = L"btn_exit";
			this->btn_exit->Size = System::Drawing::Size(120, 23);
			this->btn_exit->TabIndex = 13;
			this->btn_exit->Text = L"Exit application.";
			this->btn_exit->UseVisualStyleBackColor = true;
			this->btn_exit->Click += gcnew System::EventHandler(this, &HomeWindow::btn_exit_Click);
			// 
			// listbox_recent
			// 
			this->listbox_recent->BackColor = System::Drawing::SystemColors::Window;
			this->listbox_recent->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->listbox_recent->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listbox_recent->FormattingEnabled = true;
			this->listbox_recent->Location = System::Drawing::Point(12, 51);
			this->listbox_recent->Name = L"listbox_recent";
			this->listbox_recent->Size = System::Drawing::Size(120, 93);
			this->listbox_recent->TabIndex = 12;
			this->listbox_recent->DoubleClick += gcnew System::EventHandler(this, &HomeWindow::listbox_recent_DoubleClick);
			// 
			// lbl_recent
			// 
			this->lbl_recent->AutoSize = true;
			this->lbl_recent->Location = System::Drawing::Point(9, 32);
			this->lbl_recent->Name = L"lbl_recent";
			this->lbl_recent->Size = System::Drawing::Size(85, 13);
			this->lbl_recent->TabIndex = 11;
			this->lbl_recent->Text = L"Recent projects:";
			// 
			// ofd_openProject
			// 
			this->ofd_openProject->Filter = L"RCT3 Path Projects|*.cpath|All files|*.*";
			// 
			// HomeWindow
			// 
			this->AcceptButton = this->btn_begin;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->btn_exit;
			this->ClientSize = System::Drawing::Size(402, 186);
			this->Controls->Add(this->lbl_type);
			this->Controls->Add(this->rb_queue);
			this->Controls->Add(this->rb_extended);
			this->Controls->Add(this->rb_basic);
			this->Controls->Add(this->txt_projectName);
			this->Controls->Add(this->lbl_projname);
			this->Controls->Add(this->btn_begin);
			this->Controls->Add(this->btn_exit);
			this->Controls->Add(this->listbox_recent);
			this->Controls->Add(this->lbl_recent);
			this->Controls->Add(this->menuStrip);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->KeyPreview = true;
			this->MainMenuStrip = this->menuStrip;
			this->MaximizeBox = false;
			this->Name = L"HomeWindow";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"RCT3 Path Creator 2.0";
			this->Activated += gcnew System::EventHandler(this, &HomeWindow::HomeWindow_Activated);
			this->Load += gcnew System::EventHandler(this, &HomeWindow::HomeWindow_Load);
			this->Enter += gcnew System::EventHandler(this, &HomeWindow::HomeWindow_Enter);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &HomeWindow::HomeWindow_KeyDown);
			this->menuStrip->ResumeLayout(false);
			this->menuStrip->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		void txt_projectName_Enter(System::Object^  sender, System::EventArgs^  e);

		void txt_projectName_Leave(System::Object^  sender, System::EventArgs^  e);

		void txt_projectName_TextChanged(System::Object^  sender, System::EventArgs^  e);

		void btn_exit_Click(System::Object^  sender, System::EventArgs^  e);

		void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

		void btn_begin_Click(System::Object^  sender, System::EventArgs^  e);

		void programSettingsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

		void viewHelpToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

		void openProjectToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

		void HomeWindow_Load(System::Object^  sender, System::EventArgs^  e);

		void aboutRCT3PathCreatorToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

		void listbox_recent_DoubleClick(System::Object^  sender, System::EventArgs^  e);

		void reloadRecents();

		void HomeWindow_Activated(System::Object^  sender, System::EventArgs^  e);

		void HomeWindow_Enter(System::Object^  sender, System::EventArgs^  e);

		void HomeWindow_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);

		void checkForUpdatesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

	};
}