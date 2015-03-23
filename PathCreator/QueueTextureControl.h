// QueueTextureControl.h

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
	/// Summary for QueueTextureControl
	/// </summary>
	public ref class QueueTextureControl : public System::Windows::Forms::UserControl
	{
	private:
		System::Windows::Forms::GroupBox^  grp_shared;
		System::Windows::Forms::Button^  btn_shared;




		System::Windows::Forms::Button^  btn_loadtex;
		System::Windows::Forms::PictureBox^  pb_tex;
		System::Windows::Forms::OpenFileDialog^  ofd_tex;
		System::Windows::Forms::OpenFileDialog^  ofd_shared;
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::CheckBox^  cb_first;
	private: System::Windows::Forms::CheckBox^  cb_second;
	private: System::Windows::Forms::CheckBox^  cb_third;



	private: System::Windows::Forms::Label^  lbl_info_3;
	private: System::Windows::Forms::Label^  lbl_info_2;
	private: System::Windows::Forms::Label^  lbl_info_1;

	public:
		static QueueTextureControl^ activeInstance;

		QueueTextureControl(void);

		void reset();
		void update();

	protected:
		~QueueTextureControl();

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->grp_shared = (gcnew System::Windows::Forms::GroupBox());
			this->lbl_info_3 = (gcnew System::Windows::Forms::Label());
			this->lbl_info_2 = (gcnew System::Windows::Forms::Label());
			this->lbl_info_1 = (gcnew System::Windows::Forms::Label());
			this->btn_shared = (gcnew System::Windows::Forms::Button());
			this->btn_loadtex = (gcnew System::Windows::Forms::Button());
			this->pb_tex = (gcnew System::Windows::Forms::PictureBox());
			this->ofd_tex = (gcnew System::Windows::Forms::OpenFileDialog());
			this->ofd_shared = (gcnew System::Windows::Forms::OpenFileDialog());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->cb_first = (gcnew System::Windows::Forms::CheckBox());
			this->cb_second = (gcnew System::Windows::Forms::CheckBox());
			this->cb_third = (gcnew System::Windows::Forms::CheckBox());
			this->grp_shared->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_tex))->BeginInit();
			this->SuspendLayout();
			// 
			// grp_shared
			// 
			this->grp_shared->Controls->Add(this->lbl_info_3);
			this->grp_shared->Controls->Add(this->lbl_info_2);
			this->grp_shared->Controls->Add(this->lbl_info_1);
			this->grp_shared->Controls->Add(this->btn_shared);
			this->grp_shared->Location = System::Drawing::Point(224, 12);
			this->grp_shared->Name = L"grp_shared";
			this->grp_shared->Size = System::Drawing::Size(175, 136);
			this->grp_shared->TabIndex = 45;
			this->grp_shared->TabStop = false;
			this->grp_shared->Text = L"Shared textures";
			// 
			// lbl_info_3
			// 
			this->lbl_info_3->AutoSize = true;
			this->lbl_info_3->Location = System::Drawing::Point(8, 42);
			this->lbl_info_3->Name = L"lbl_info_3";
			this->lbl_info_3->Size = System::Drawing::Size(76, 13);
			this->lbl_info_3->TabIndex = 29;
			this->lbl_info_3->Text = L"queue models.";
			// 
			// lbl_info_2
			// 
			this->lbl_info_2->AutoSize = true;
			this->lbl_info_2->Location = System::Drawing::Point(8, 29);
			this->lbl_info_2->Name = L"lbl_info_2";
			this->lbl_info_2->Size = System::Drawing::Size(145, 13);
			this->lbl_info_2->TabIndex = 28;
			this->lbl_info_2->Text = L"a shared texture OVL for your";
			// 
			// lbl_info_1
			// 
			this->lbl_info_1->AutoSize = true;
			this->lbl_info_1->Location = System::Drawing::Point(8, 16);
			this->lbl_info_1->Name = L"lbl_info_1";
			this->lbl_info_1->Size = System::Drawing::Size(161, 13);
			this->lbl_info_1->TabIndex = 27;
			this->lbl_info_1->Text = L"It is recommended that you have";
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
			this->btn_shared->Click += gcnew System::EventHandler(this, &QueueTextureControl::btn_shared_Click);
			// 
			// btn_loadtex
			// 
			this->btn_loadtex->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_loadtex->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_loadtex->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->btn_loadtex->Location = System::Drawing::Point(14, 124);
			this->btn_loadtex->Name = L"btn_loadtex";
			this->btn_loadtex->Size = System::Drawing::Size(100, 23);
			this->btn_loadtex->TabIndex = 43;
			this->btn_loadtex->Text = L"Load texture.";
			this->btn_loadtex->UseVisualStyleBackColor = true;
			this->btn_loadtex->Click += gcnew System::EventHandler(this, &QueueTextureControl::btn_loadtex_Click);
			// 
			// pb_tex
			// 
			this->pb_tex->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pb_tex->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pb_tex->Location = System::Drawing::Point(14, 19);
			this->pb_tex->Name = L"pb_tex";
			this->pb_tex->Size = System::Drawing::Size(100, 100);
			this->pb_tex->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pb_tex->TabIndex = 41;
			this->pb_tex->TabStop = false;
			// 
			// ofd_tex
			// 
			this->ofd_tex->Filter = L"PNG images (*.png)|*.png";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(120, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(73, 13);
			this->label1->TabIndex = 46;
			this->label1->Text = L"Recolorability:";
			// 
			// cb_first
			// 
			this->cb_first->AutoSize = true;
			this->cb_first->Location = System::Drawing::Point(123, 40);
			this->cb_first->Name = L"cb_first";
			this->cb_first->Size = System::Drawing::Size(71, 17);
			this->cb_first->TabIndex = 47;
			this->cb_first->Text = L"First color";
			this->cb_first->UseVisualStyleBackColor = true;
			this->cb_first->CheckedChanged += gcnew System::EventHandler(this, &QueueTextureControl::cb_first_CheckedChanged);
			// 
			// cb_second
			// 
			this->cb_second->AutoSize = true;
			this->cb_second->Location = System::Drawing::Point(123, 70);
			this->cb_second->Name = L"cb_second";
			this->cb_second->Size = System::Drawing::Size(89, 17);
			this->cb_second->TabIndex = 48;
			this->cb_second->Text = L"Second color";
			this->cb_second->UseVisualStyleBackColor = true;
			this->cb_second->CheckedChanged += gcnew System::EventHandler(this, &QueueTextureControl::cb_second_CheckedChanged);
			// 
			// cb_third
			// 
			this->cb_third->AutoSize = true;
			this->cb_third->Location = System::Drawing::Point(123, 100);
			this->cb_third->Name = L"cb_third";
			this->cb_third->Size = System::Drawing::Size(76, 17);
			this->cb_third->TabIndex = 49;
			this->cb_third->Text = L"Third color";
			this->cb_third->UseVisualStyleBackColor = true;
			this->cb_third->CheckedChanged += gcnew System::EventHandler(this, &QueueTextureControl::cb_third_CheckedChanged);
			// 
			// QueueTextureControl
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->cb_third);
			this->Controls->Add(this->cb_second);
			this->Controls->Add(this->cb_first);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->grp_shared);
			this->Controls->Add(this->btn_loadtex);
			this->Controls->Add(this->pb_tex);
			this->Name = L"QueueTextureControl";
			this->Size = System::Drawing::Size(411, 161);
			this->grp_shared->ResumeLayout(false);
			this->grp_shared->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_tex))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		void btn_shared_Click(System::Object^  sender, System::EventArgs^  e);

		void btn_loadtex_Click(System::Object^  sender, System::EventArgs^  e);

		void cb_first_CheckedChanged(System::Object^  sender, System::EventArgs^  e);

		void cb_second_CheckedChanged(System::Object^  sender, System::EventArgs^  e);

		void cb_third_CheckedChanged(System::Object^  sender, System::EventArgs^  e);

	};
}
