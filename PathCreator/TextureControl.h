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
	/// Summary for TextureControl
	/// </summary>
	public ref class TextureControl : public System::Windows::Forms::UserControl
	{
	private:
		System::Windows::Forms::GroupBox^  grp_shared;
		System::Windows::Forms::Button^  btn_shared;

		System::Windows::Forms::Label^  lbl_info_3;
		System::Windows::Forms::Label^  lbl_info_2;
		System::Windows::Forms::Label^  lbl_info_1;
		System::Windows::Forms::Button^  btn_loadtexb;
		System::Windows::Forms::Button^  btn_loadtexa;
		System::Windows::Forms::PictureBox^  pb_texb;
		System::Windows::Forms::PictureBox^  pb_texa;
		System::Windows::Forms::OpenFileDialog^  ofd_texa;
		System::Windows::Forms::OpenFileDialog^  ofd_texb;
		System::Windows::Forms::OpenFileDialog^  ofd_shared;
		System::ComponentModel::Container ^components;

	public:
		static TextureControl^ activeInstance;

		TextureControl(void);
		void reset();
		void update();

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TextureControl();

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->grp_shared = (gcnew System::Windows::Forms::GroupBox());
			this->btn_shared = (gcnew System::Windows::Forms::Button());
			this->lbl_info_3 = (gcnew System::Windows::Forms::Label());
			this->lbl_info_2 = (gcnew System::Windows::Forms::Label());
			this->lbl_info_1 = (gcnew System::Windows::Forms::Label());
			this->btn_loadtexb = (gcnew System::Windows::Forms::Button());
			this->btn_loadtexa = (gcnew System::Windows::Forms::Button());
			this->pb_texb = (gcnew System::Windows::Forms::PictureBox());
			this->pb_texa = (gcnew System::Windows::Forms::PictureBox());
			this->ofd_texa = (gcnew System::Windows::Forms::OpenFileDialog());
			this->ofd_texb = (gcnew System::Windows::Forms::OpenFileDialog());
			this->ofd_shared = (gcnew System::Windows::Forms::OpenFileDialog());
			this->grp_shared->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_texb))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_texa))->BeginInit();
			this->SuspendLayout();
			// 
			// grp_shared
			// 
			this->grp_shared->Controls->Add(this->btn_shared);
			this->grp_shared->Controls->Add(this->lbl_info_3);
			this->grp_shared->Controls->Add(this->lbl_info_2);
			this->grp_shared->Controls->Add(this->lbl_info_1);
			this->grp_shared->Location = System::Drawing::Point(224, 12);
			this->grp_shared->Name = L"grp_shared";
			this->grp_shared->Size = System::Drawing::Size(175, 136);
			this->grp_shared->TabIndex = 40;
			this->grp_shared->TabStop = false;
			this->grp_shared->Text = L"Shared textures";
			// 
			// btn_shared
			// 
			this->btn_shared->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_shared->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_shared->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->btn_shared->Location = System::Drawing::Point(8, 82);
			this->btn_shared->Name = L"btn_shared";
			this->btn_shared->Size = System::Drawing::Size(158, 23);
			this->btn_shared->TabIndex = 26;
			this->btn_shared->Text = L"Load shared texture file.";
			this->btn_shared->UseVisualStyleBackColor = true;
			this->btn_shared->Click += gcnew System::EventHandler(this, &TextureControl::btn_shared_Click);
			// 
			// lbl_info_3
			// 
			this->lbl_info_3->AutoSize = true;
			this->lbl_info_3->Location = System::Drawing::Point(6, 43);
			this->lbl_info_3->Name = L"lbl_info_3";
			this->lbl_info_3->Size = System::Drawing::Size(67, 13);
			this->lbl_info_3->TabIndex = 2;
			this->lbl_info_3->Text = L"path models.";
			// 
			// lbl_info_2
			// 
			this->lbl_info_2->AutoSize = true;
			this->lbl_info_2->Location = System::Drawing::Point(6, 30);
			this->lbl_info_2->Name = L"lbl_info_2";
			this->lbl_info_2->Size = System::Drawing::Size(145, 13);
			this->lbl_info_2->TabIndex = 1;
			this->lbl_info_2->Text = L"a shared texture OVL for your";
			// 
			// lbl_info_1
			// 
			this->lbl_info_1->AutoSize = true;
			this->lbl_info_1->Location = System::Drawing::Point(6, 17);
			this->lbl_info_1->Name = L"lbl_info_1";
			this->lbl_info_1->Size = System::Drawing::Size(161, 13);
			this->lbl_info_1->TabIndex = 0;
			this->lbl_info_1->Text = L"It is recommended that you have";
			// 
			// btn_loadtexb
			// 
			this->btn_loadtexb->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_loadtexb->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_loadtexb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->btn_loadtexb->Location = System::Drawing::Point(118, 125);
			this->btn_loadtexb->Name = L"btn_loadtexb";
			this->btn_loadtexb->Size = System::Drawing::Size(100, 23);
			this->btn_loadtexb->TabIndex = 39;
			this->btn_loadtexb->Text = L"Load TextureB.";
			this->btn_loadtexb->UseVisualStyleBackColor = true;
			this->btn_loadtexb->Click += gcnew System::EventHandler(this, &TextureControl::btn_loadtexb_Click);
			// 
			// btn_loadtexa
			// 
			this->btn_loadtexa->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_loadtexa->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_loadtexa->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->btn_loadtexa->Location = System::Drawing::Point(12, 125);
			this->btn_loadtexa->Name = L"btn_loadtexa";
			this->btn_loadtexa->Size = System::Drawing::Size(100, 23);
			this->btn_loadtexa->TabIndex = 38;
			this->btn_loadtexa->Text = L"Load TextureA.";
			this->btn_loadtexa->UseVisualStyleBackColor = true;
			this->btn_loadtexa->Click += gcnew System::EventHandler(this, &TextureControl::btn_loadtexa_Click);
			// 
			// pb_texb
			// 
			this->pb_texb->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pb_texb->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pb_texb->Location = System::Drawing::Point(118, 19);
			this->pb_texb->Name = L"pb_texb";
			this->pb_texb->Size = System::Drawing::Size(100, 100);
			this->pb_texb->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pb_texb->TabIndex = 37;
			this->pb_texb->TabStop = false;
			// 
			// pb_texa
			// 
			this->pb_texa->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pb_texa->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pb_texa->Location = System::Drawing::Point(12, 19);
			this->pb_texa->Name = L"pb_texa";
			this->pb_texa->Size = System::Drawing::Size(100, 100);
			this->pb_texa->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pb_texa->TabIndex = 36;
			this->pb_texa->TabStop = false;
			// 
			// ofd_texa
			// 
			this->ofd_texa->Filter = L"PNG images (*.png)|*.png";
			this->ofd_texa->Title = L"Load TextureA";
			// 
			// ofd_texb
			// 
			this->ofd_texb->Filter = L"PNG images (*.png)|*.png";
			this->ofd_texb->Title = L"Load TextureB";
			// 
			// ofd_shared
			// 
			this->ofd_shared->Filter = L"OVL Files|*.common.ovl";
			this->ofd_shared->SupportMultiDottedExtensions = true;
			this->ofd_shared->Title = L"Load Shared Texture OVL";
			// 
			// TextureControl
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->grp_shared);
			this->Controls->Add(this->btn_loadtexb);
			this->Controls->Add(this->btn_loadtexa);
			this->Controls->Add(this->pb_texb);
			this->Controls->Add(this->pb_texa);
			this->Name = L"TextureControl";
			this->Size = System::Drawing::Size(411, 161);
			this->grp_shared->ResumeLayout(false);
			this->grp_shared->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_texb))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_texa))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private:

		void btn_loadtexa_Click(System::Object^  sender, System::EventArgs^  e);

		void btn_loadtexb_Click(System::Object^  sender, System::EventArgs^  e);

		void btn_shared_Click(System::Object^  sender, System::EventArgs^  e);
	};
}
