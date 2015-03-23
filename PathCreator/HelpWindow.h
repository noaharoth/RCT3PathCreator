// HelpWindow.h

#pragma once

#include "stdafx.h"
#include "global.h"
#include "TransparentLabel.h"

namespace PathCreator {

#define HELP_TXT_OVERVIEW_KEY 0x642A48A4
#define HELP_TXT_MODELS_KEY 0x4237C351
#define HELP_TXT_TEXTURES_KEY 0
#define HELP_TXT_ICONSETTINGS_KEY 0
#define HELP_TXT_EXTENDED_KEY 0
#define HELP_TXT_QUEUE_KEY 0

	/// <summary>
	/// Summary for HelpWindow
	/// </summary>
	public ref class HelpWindow : public System::Windows::Forms::Form
	{
		System::Windows::Forms::PictureBox^  pb_topBar;
		System::Windows::Forms::Panel^  helpPanel;
		System::Windows::Forms::RichTextBox^  helpText;
		System::Windows::Forms::Label^  lblbtn_overview;
		System::Windows::Forms::Label^  lblbtn_models;
		System::Windows::Forms::Label^  lblbtn_textures;
		System::Windows::Forms::Label^  lblbtn_iconsSettings;


		System::ComponentModel::Container ^components;
		String^ currentFile;

	public:
		HelpWindow(void);

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~HelpWindow()
		{
			if (components)
			{
				delete components;
			}
		}

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(HelpWindow::typeid));
			this->pb_topBar = (gcnew System::Windows::Forms::PictureBox());
			this->helpPanel = (gcnew System::Windows::Forms::Panel());
			this->lblbtn_iconsSettings = (gcnew System::Windows::Forms::Label());
			this->lblbtn_textures = (gcnew System::Windows::Forms::Label());
			this->lblbtn_models = (gcnew System::Windows::Forms::Label());
			this->lblbtn_overview = (gcnew System::Windows::Forms::Label());
			this->helpText = (gcnew System::Windows::Forms::RichTextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_topBar))->BeginInit();
			this->helpPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// pb_topBar
			// 
			this->pb_topBar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pb_topBar->Location = System::Drawing::Point(-1, -1);
			this->pb_topBar->Name = L"pb_topBar";
			this->pb_topBar->Size = System::Drawing::Size(473, 26);
			this->pb_topBar->TabIndex = 0;
			this->pb_topBar->TabStop = false;
			// 
			// helpPanel
			// 
			this->helpPanel->BackColor = System::Drawing::SystemColors::ControlLight;
			this->helpPanel->Controls->Add(this->lblbtn_iconsSettings);
			this->helpPanel->Controls->Add(this->lblbtn_textures);
			this->helpPanel->Controls->Add(this->lblbtn_models);
			this->helpPanel->Controls->Add(this->lblbtn_overview);
			this->helpPanel->Location = System::Drawing::Point(-1, 25);
			this->helpPanel->Name = L"helpPanel";
			this->helpPanel->Size = System::Drawing::Size(163, 316);
			this->helpPanel->TabIndex = 1;
			// 
			// lblbtn_iconsSettings
			// 
			this->lblbtn_iconsSettings->AutoSize = true;
			this->lblbtn_iconsSettings->Location = System::Drawing::Point(24, 122);
			this->lblbtn_iconsSettings->Name = L"lblbtn_iconsSettings";
			this->lblbtn_iconsSettings->Padding = System::Windows::Forms::Padding(0, 4, 41, 4);
			this->lblbtn_iconsSettings->Size = System::Drawing::Size(136, 21);
			this->lblbtn_iconsSettings->TabIndex = 3;
			this->lblbtn_iconsSettings->Text = L"Icons and Settings";
			this->lblbtn_iconsSettings->Click += gcnew System::EventHandler(this, &HelpWindow::lblbtn_iconsSettings_Click);
			this->lblbtn_iconsSettings->MouseEnter += gcnew System::EventHandler(this, &HelpWindow::lblbtn_iconsSettings_MouseEnter);
			this->lblbtn_iconsSettings->MouseLeave += gcnew System::EventHandler(this, &HelpWindow::lblbtn_iconsSettings_MouseLeave);
			// 
			// lblbtn_textures
			// 
			this->lblbtn_textures->AutoSize = true;
			this->lblbtn_textures->Location = System::Drawing::Point(24, 89);
			this->lblbtn_textures->Name = L"lblbtn_textures";
			this->lblbtn_textures->Padding = System::Windows::Forms::Padding(0, 4, 88, 4);
			this->lblbtn_textures->Size = System::Drawing::Size(136, 21);
			this->lblbtn_textures->TabIndex = 2;
			this->lblbtn_textures->Text = L"Textures";
			this->lblbtn_textures->Click += gcnew System::EventHandler(this, &HelpWindow::lblbtn_textures_Click);
			this->lblbtn_textures->MouseEnter += gcnew System::EventHandler(this, &HelpWindow::lblbtn_textures_MouseEnter);
			this->lblbtn_textures->MouseLeave += gcnew System::EventHandler(this, &HelpWindow::lblbtn_textures_MouseLeave);
			// 
			// lblbtn_models
			// 
			this->lblbtn_models->AutoSize = true;
			this->lblbtn_models->Location = System::Drawing::Point(24, 56);
			this->lblbtn_models->Name = L"lblbtn_models";
			this->lblbtn_models->Padding = System::Windows::Forms::Padding(0, 4, 95, 4);
			this->lblbtn_models->Size = System::Drawing::Size(136, 21);
			this->lblbtn_models->TabIndex = 1;
			this->lblbtn_models->Text = L"Models";
			this->lblbtn_models->Click += gcnew System::EventHandler(this, &HelpWindow::lblbtn_models_Click);
			this->lblbtn_models->MouseEnter += gcnew System::EventHandler(this, &HelpWindow::lblbtn_models_MouseEnter);
			this->lblbtn_models->MouseLeave += gcnew System::EventHandler(this, &HelpWindow::lblbtn_models_MouseLeave);
			// 
			// lblbtn_overview
			// 
			this->lblbtn_overview->AutoSize = true;
			this->lblbtn_overview->BackColor = System::Drawing::Color::DarkGray;
			this->lblbtn_overview->Location = System::Drawing::Point(24, 23);
			this->lblbtn_overview->Name = L"lblbtn_overview";
			this->lblbtn_overview->Padding = System::Windows::Forms::Padding(0, 4, 22, 4);
			this->lblbtn_overview->Size = System::Drawing::Size(136, 21);
			this->lblbtn_overview->TabIndex = 0;
			this->lblbtn_overview->Text = L"Path Creator Overview";
			this->lblbtn_overview->Click += gcnew System::EventHandler(this, &HelpWindow::lblbtn_overview_Click);
			this->lblbtn_overview->MouseEnter += gcnew System::EventHandler(this, &HelpWindow::lblbtn_overview_MouseEnter);
			this->lblbtn_overview->MouseLeave += gcnew System::EventHandler(this, &HelpWindow::lblbtn_overview_MouseLeave);
			// 
			// helpText
			// 
			this->helpText->BackColor = System::Drawing::SystemColors::Window;
			this->helpText->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->helpText->Location = System::Drawing::Point(163, 26);
			this->helpText->Name = L"helpText";
			this->helpText->ReadOnly = true;
			this->helpText->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->helpText->Size = System::Drawing::Size(309, 314);
			this->helpText->TabIndex = 2;
			this->helpText->Text = L"";
			// 
			// HelpWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(471, 338);
			this->Controls->Add(this->helpText);
			this->Controls->Add(this->helpPanel);
			this->Controls->Add(this->pb_topBar);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"HelpWindow";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"RCT3 Path Creator - Help";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_topBar))->EndInit();
			this->helpPanel->ResumeLayout(false);
			this->helpPanel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion


		
		void lblbtn_overview_MouseEnter(System::Object^  sender, System::EventArgs^  e);

		void lblbtn_models_MouseEnter(System::Object^  sender, System::EventArgs^  e);

		void lblbtn_textures_MouseEnter(System::Object^  sender, System::EventArgs^  e);

		void lblbtn_iconsSettings_MouseEnter(System::Object^  sender, System::EventArgs^  e);

		void lblbtn_overview_MouseLeave(System::Object^  sender, System::EventArgs^  e);

		void lblbtn_models_MouseLeave(System::Object^  sender, System::EventArgs^  e);

		void lblbtn_textures_MouseLeave(System::Object^  sender, System::EventArgs^  e);

		void lblbtn_iconsSettings_MouseLeave(System::Object^  sender, System::EventArgs^  e);

		void lblbtn_overview_Click(System::Object^  sender, System::EventArgs^  e);

		void lblbtn_models_Click(System::Object^  sender, System::EventArgs^  e);

		void lblbtn_textures_Click(System::Object^  sender, System::EventArgs^  e);

		void lblbtn_iconsSettings_Click(System::Object^  sender, System::EventArgs^  e);

		
	};
}
