#pragma once

#include "global.h"
#include "MainWindow.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace PathCreator {

	/// <summary>
	/// Summary for InfoControl
	/// </summary>
	public ref class InfoControl : public System::Windows::Forms::UserControl
	{
	private:
		static String^ allowedChars = "aAbBcCdDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz1234567890_-";
		System::Windows::Forms::TextBox^  txt_shortName;
		System::Windows::Forms::Label^  lbl_shortname;
		System::Windows::Forms::Label^  lbl_formats;
		System::Windows::Forms::TextBox^  txt_ingameName;
		System::Windows::Forms::Label^  lbl_ingamename;
		System::Windows::Forms::PictureBox^  pb_icon;
		System::Windows::Forms::Label^  lbl_icon;
		System::Windows::Forms::Button^  btn_loadicon;
		System::Windows::Forms::OpenFileDialog^  ofd_icon;

	public:
		static InfoControl^ activeInstance;

		InfoControl(void);

		void reset();
		void update(Rct3PathType type);

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~InfoControl();

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->txt_shortName = (gcnew System::Windows::Forms::TextBox());
			this->lbl_shortname = (gcnew System::Windows::Forms::Label());
			this->lbl_formats = (gcnew System::Windows::Forms::Label());
			this->txt_ingameName = (gcnew System::Windows::Forms::TextBox());
			this->lbl_ingamename = (gcnew System::Windows::Forms::Label());
			this->pb_icon = (gcnew System::Windows::Forms::PictureBox());
			this->lbl_icon = (gcnew System::Windows::Forms::Label());
			this->btn_loadicon = (gcnew System::Windows::Forms::Button());
			this->ofd_icon = (gcnew System::Windows::Forms::OpenFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_icon))->BeginInit();
			this->SuspendLayout();
			// 
			// txt_shortName
			// 
			this->txt_shortName->Location = System::Drawing::Point(103, 120);
			this->txt_shortName->Name = L"txt_shortName";
			this->txt_shortName->Size = System::Drawing::Size(182, 20);
			this->txt_shortName->TabIndex = 46;
			this->txt_shortName->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &InfoControl::txt_shortName_KeyPress);
			this->txt_shortName->Leave += gcnew System::EventHandler(this, &InfoControl::txt_shortName_Leave);
			// 
			// lbl_shortname
			// 
			this->lbl_shortname->AutoSize = true;
			this->lbl_shortname->Location = System::Drawing::Point(20, 123);
			this->lbl_shortname->Name = L"lbl_shortname";
			this->lbl_shortname->Size = System::Drawing::Size(64, 13);
			this->lbl_shortname->TabIndex = 45;
			this->lbl_shortname->Text = L"Short name:";
			// 
			// lbl_formats
			// 
			this->lbl_formats->AutoSize = true;
			this->lbl_formats->Enabled = false;
			this->lbl_formats->Location = System::Drawing::Point(101, 47);
			this->lbl_formats->Name = L"lbl_formats";
			this->lbl_formats->Size = System::Drawing::Size(142, 13);
			this->lbl_formats->TabIndex = 44;
			this->lbl_formats->Text = L"(Allowed formats: JPG, PNG)";
			// 
			// txt_ingameName
			// 
			this->txt_ingameName->Location = System::Drawing::Point(103, 80);
			this->txt_ingameName->Name = L"txt_ingameName";
			this->txt_ingameName->Size = System::Drawing::Size(182, 20);
			this->txt_ingameName->TabIndex = 43;
			this->txt_ingameName->Leave += gcnew System::EventHandler(this, &InfoControl::txt_ingameName_Leave);
			// 
			// lbl_ingamename
			// 
			this->lbl_ingamename->AutoSize = true;
			this->lbl_ingamename->Location = System::Drawing::Point(20, 83);
			this->lbl_ingamename->Name = L"lbl_ingamename";
			this->lbl_ingamename->Size = System::Drawing::Size(77, 13);
			this->lbl_ingamename->TabIndex = 42;
			this->lbl_ingamename->Text = L"In-game name:";
			// 
			// pb_icon
			// 
			this->pb_icon->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pb_icon->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pb_icon->Location = System::Drawing::Point(310, 20);
			this->pb_icon->Name = L"pb_icon";
			this->pb_icon->Size = System::Drawing::Size(80, 80);
			this->pb_icon->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pb_icon->TabIndex = 41;
			this->pb_icon->TabStop = false;
			// 
			// lbl_icon
			// 
			this->lbl_icon->AutoSize = true;
			this->lbl_icon->Location = System::Drawing::Point(20, 25);
			this->lbl_icon->Name = L"lbl_icon";
			this->lbl_icon->Size = System::Drawing::Size(31, 13);
			this->lbl_icon->TabIndex = 40;
			this->lbl_icon->Text = L"Icon:";
			// 
			// btn_loadicon
			// 
			this->btn_loadicon->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_loadicon->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_loadicon->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->btn_loadicon->Location = System::Drawing::Point(61, 20);
			this->btn_loadicon->Name = L"btn_loadicon";
			this->btn_loadicon->Size = System::Drawing::Size(224, 23);
			this->btn_loadicon->TabIndex = 39;
			this->btn_loadicon->Text = L"Click to load an icon.";
			this->btn_loadicon->UseVisualStyleBackColor = true;
			this->btn_loadicon->Click += gcnew System::EventHandler(this, &InfoControl::btn_loadicon_Click);
			// 
			// ofd_icon
			// 
			this->ofd_icon->Filter = L"PNG images|*.png|JPG images|*.jpg";
			this->ofd_icon->Title = L"Load Icon";
			// 
			// InfoControl
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->txt_shortName);
			this->Controls->Add(this->lbl_shortname);
			this->Controls->Add(this->lbl_formats);
			this->Controls->Add(this->txt_ingameName);
			this->Controls->Add(this->lbl_ingamename);
			this->Controls->Add(this->pb_icon);
			this->Controls->Add(this->lbl_icon);
			this->Controls->Add(this->btn_loadicon);
			this->Name = L"InfoControl";
			this->Size = System::Drawing::Size(411, 161);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_icon))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		void txt_shortName_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e);

		void btn_loadicon_Click(System::Object^  sender, System::EventArgs^  e);

		void txt_ingameName_Leave(System::Object^  sender, System::EventArgs^  e);

		void txt_shortName_Leave(System::Object^  sender, System::EventArgs^  e);
	};
}
