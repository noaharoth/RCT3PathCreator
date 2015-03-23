// QueueModelsControl.h

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

#define QS_PATH_COUNT 7
#define QS_STRAIGHT 0
#define QS_TURN_L 1
#define QS_TURN_R 2
#define QS_SLOPE_UP 3
#define QS_SLOPE_DOWN 4
#define QS_SLOPE_STRAIGHT1 5
#define QS_SLOPE_STRAIGHT2 6

	/// <summary>
	/// Summary for QueueModelsControl
	/// </summary>
	public ref class QueueModelsControl : public System::Windows::Forms::UserControl
	{
	private:
		array<OpenFileDialog^>^ section_ofds;
		System::Windows::Forms::LinkLabel^  link_auto;
		System::Windows::Forms::Button^  btn_slope_down;
		System::Windows::Forms::Button^  btn_straight;
		System::Windows::Forms::Label^  lbl_info_2;
		System::Windows::Forms::Label^  lbl_info_1;
		System::Windows::Forms::Button^  btn_turn_l;
		System::Windows::Forms::Button^  btn_turn_r;
		System::Windows::Forms::Button^  btn_slope_up;
		System::Windows::Forms::Button^  btn_slope_straight1;
		System::Windows::Forms::Button^  btn_slope_straight2;
		System::Windows::Forms::FolderBrowserDialog^  fbd_autoLoad;
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::GroupBox^  groupBox1;

	public:
		static QueueModelsControl^ activeInstance;

		QueueModelsControl(void);

		void reset();
		void update();

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~QueueModelsControl();

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->link_auto = (gcnew System::Windows::Forms::LinkLabel());
			this->btn_slope_down = (gcnew System::Windows::Forms::Button());
			this->btn_straight = (gcnew System::Windows::Forms::Button());
			this->lbl_info_2 = (gcnew System::Windows::Forms::Label());
			this->lbl_info_1 = (gcnew System::Windows::Forms::Label());
			this->btn_turn_l = (gcnew System::Windows::Forms::Button());
			this->btn_turn_r = (gcnew System::Windows::Forms::Button());
			this->btn_slope_up = (gcnew System::Windows::Forms::Button());
			this->btn_slope_straight1 = (gcnew System::Windows::Forms::Button());
			this->btn_slope_straight2 = (gcnew System::Windows::Forms::Button());
			this->fbd_autoLoad = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// link_auto
			// 
			this->link_auto->AutoSize = true;
			this->link_auto->Location = System::Drawing::Point(184, 21);
			this->link_auto->Name = L"link_auto";
			this->link_auto->Size = System::Drawing::Size(179, 13);
			this->link_auto->TabIndex = 118;
			this->link_auto->TabStop = true;
			this->link_auto->Text = L"Click to auto-load the queue models.";
			this->link_auto->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &QueueModelsControl::link_auto_LinkClicked);
			// 
			// btn_slope_down
			// 
			this->btn_slope_down->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_slope_down->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_slope_down->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->btn_slope_down->Location = System::Drawing::Point(217, 42);
			this->btn_slope_down->Name = L"btn_slope_down";
			this->btn_slope_down->Size = System::Drawing::Size(165, 23);
			this->btn_slope_down->TabIndex = 117;
			this->btn_slope_down->Text = L"Load \'SlopeDown\'.";
			this->btn_slope_down->UseVisualStyleBackColor = true;
			this->btn_slope_down->Click += gcnew System::EventHandler(this, &QueueModelsControl::btn_slope_down_Click);
			// 
			// btn_straight
			// 
			this->btn_straight->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_straight->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_straight->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->btn_straight->Location = System::Drawing::Point(27, 42);
			this->btn_straight->Name = L"btn_straight";
			this->btn_straight->Size = System::Drawing::Size(165, 23);
			this->btn_straight->TabIndex = 116;
			this->btn_straight->Text = L"Load \'Straight\'.";
			this->btn_straight->UseVisualStyleBackColor = true;
			this->btn_straight->Click += gcnew System::EventHandler(this, &QueueModelsControl::btn_straight_Click);
			// 
			// lbl_info_2
			// 
			this->lbl_info_2->AutoSize = true;
			this->lbl_info_2->Location = System::Drawing::Point(24, 21);
			this->lbl_info_2->Name = L"lbl_info_2";
			this->lbl_info_2->Size = System::Drawing::Size(161, 13);
			this->lbl_info_2->TabIndex = 115;
			this->lbl_info_2->Text = L"located in the \'Resources\' folder.";
			// 
			// lbl_info_1
			// 
			this->lbl_info_1->AutoSize = true;
			this->lbl_info_1->Location = System::Drawing::Point(24, 8);
			this->lbl_info_1->Name = L"lbl_info_1";
			this->lbl_info_1->Size = System::Drawing::Size(358, 13);
			this->lbl_info_1->TabIndex = 114;
			this->lbl_info_1->Text = L"All these models are required for a functional queue! Reference images are";
			// 
			// btn_turn_l
			// 
			this->btn_turn_l->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_turn_l->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_turn_l->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->btn_turn_l->Location = System::Drawing::Point(27, 71);
			this->btn_turn_l->Name = L"btn_turn_l";
			this->btn_turn_l->Size = System::Drawing::Size(165, 23);
			this->btn_turn_l->TabIndex = 119;
			this->btn_turn_l->Text = L"Load \'TurnL\'.";
			this->btn_turn_l->UseVisualStyleBackColor = true;
			this->btn_turn_l->Click += gcnew System::EventHandler(this, &QueueModelsControl::btn_turn_l_Click);
			// 
			// btn_turn_r
			// 
			this->btn_turn_r->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_turn_r->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_turn_r->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->btn_turn_r->Location = System::Drawing::Point(27, 100);
			this->btn_turn_r->Name = L"btn_turn_r";
			this->btn_turn_r->Size = System::Drawing::Size(165, 23);
			this->btn_turn_r->TabIndex = 120;
			this->btn_turn_r->Text = L"Load \'TurnR\'.";
			this->btn_turn_r->UseVisualStyleBackColor = true;
			this->btn_turn_r->Click += gcnew System::EventHandler(this, &QueueModelsControl::btn_turn_r_Click);
			// 
			// btn_slope_up
			// 
			this->btn_slope_up->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_slope_up->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_slope_up->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->btn_slope_up->Location = System::Drawing::Point(27, 129);
			this->btn_slope_up->Name = L"btn_slope_up";
			this->btn_slope_up->Size = System::Drawing::Size(165, 23);
			this->btn_slope_up->TabIndex = 121;
			this->btn_slope_up->Text = L"Load \'SlopeUp\'.";
			this->btn_slope_up->UseVisualStyleBackColor = true;
			this->btn_slope_up->Click += gcnew System::EventHandler(this, &QueueModelsControl::btn_slope_up_Click);
			// 
			// btn_slope_straight1
			// 
			this->btn_slope_straight1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_slope_straight1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_slope_straight1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(177)));
			this->btn_slope_straight1->Location = System::Drawing::Point(217, 71);
			this->btn_slope_straight1->Name = L"btn_slope_straight1";
			this->btn_slope_straight1->Size = System::Drawing::Size(165, 23);
			this->btn_slope_straight1->TabIndex = 122;
			this->btn_slope_straight1->Text = L"Load \'SlopeStraight\'.";
			this->btn_slope_straight1->UseVisualStyleBackColor = true;
			this->btn_slope_straight1->Click += gcnew System::EventHandler(this, &QueueModelsControl::btn_slope_straight1_Click);
			// 
			// btn_slope_straight2
			// 
			this->btn_slope_straight2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_slope_straight2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_slope_straight2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(177)));
			this->btn_slope_straight2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->btn_slope_straight2->Location = System::Drawing::Point(10, 19);
			this->btn_slope_straight2->Name = L"btn_slope_straight2";
			this->btn_slope_straight2->Size = System::Drawing::Size(165, 23);
			this->btn_slope_straight2->TabIndex = 123;
			this->btn_slope_straight2->Text = L"Load \'SlopeStraight2\'.";
			this->btn_slope_straight2->UseVisualStyleBackColor = true;
			this->btn_slope_straight2->Click += gcnew System::EventHandler(this, &QueueModelsControl::btn_slope_straight2_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->btn_slope_straight2);
			this->groupBox1->ForeColor = System::Drawing::SystemColors::ControlDark;
			this->groupBox1->Location = System::Drawing::Point(207, 100);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(185, 52);
			this->groupBox1->TabIndex = 124;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Optional";
			// 
			// QueueModelsControl
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->btn_slope_straight1);
			this->Controls->Add(this->btn_slope_up);
			this->Controls->Add(this->btn_turn_r);
			this->Controls->Add(this->btn_turn_l);
			this->Controls->Add(this->link_auto);
			this->Controls->Add(this->btn_slope_down);
			this->Controls->Add(this->btn_straight);
			this->Controls->Add(this->lbl_info_2);
			this->Controls->Add(this->lbl_info_1);
			this->Name = L"QueueModelsControl";
			this->Size = System::Drawing::Size(411, 161);
			this->groupBox1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		void btn_straight_Click(System::Object^  sender, System::EventArgs^  e);

		void btn_turn_l_Click(System::Object^  sender, System::EventArgs^  e);

		void btn_turn_r_Click(System::Object^  sender, System::EventArgs^  e);

		void btn_slope_up_Click(System::Object^  sender, System::EventArgs^  e);

		void btn_slope_down_Click(System::Object^  sender, System::EventArgs^  e);

		void btn_slope_straight1_Click(System::Object^  sender, System::EventArgs^  e);

		void btn_slope_straight2_Click(System::Object^  sender, System::EventArgs^  e);

		void link_auto_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e);

	};
}
