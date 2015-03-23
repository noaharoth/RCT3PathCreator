// ModelsControl.h

#pragma once

#include "global.h"
#include "MainWindow.h"
#include "AutoLoadDialog.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace PathCreator {

#define PS_BASIC_PATH_COUNT 19
#define PS_FLAT 0
#define PS_STRAIGHT_A 1
#define PS_STRAIGHT_B 2
#define PS_TURN_U 3
#define PS_TURN_LA 4
#define PS_TURN_LB 5
#define PS_TURN_TA 6
#define PS_TURN_TB 7
#define PS_TURN_TC 8
#define PS_TURN_X 9
#define PS_CORNER_A 10
#define PS_CORNER_B 11
#define PS_CORNER_C 12
#define PS_CORNER_D 13
#define PS_SLOPE 14
#define PS_SLOPE_STRAIGHT 15
#define PS_SLOPE_STRAIGHT_L 16
#define PS_SLOPE_STRAIGHT_R 17
#define PS_SLOPE_MID 18

	/// <summary>
	/// Summary for ModelsControl
	/// </summary>
	public ref class ModelsControl : public System::Windows::Forms::UserControl
	{
	private:
		array<OpenFileDialog^>^ section_ofds;
		System::Windows::Forms::LinkLabel^  link_auto;
		System::Windows::Forms::Label^  BLANK;
		System::Windows::Forms::Button^  btn_slopemid;
		System::Windows::Forms::Button^  btn_slopestraight_r;
		System::Windows::Forms::Button^  btn_slopestraight_l;
		System::Windows::Forms::Button^  btn_slopestraight;
		System::Windows::Forms::Button^  btn_slope;
		System::Windows::Forms::Button^  btn_cornerd;
		System::Windows::Forms::Button^  btn_cornerc;
		System::Windows::Forms::Button^  btn_cornerb;
		System::Windows::Forms::Button^  btn_cornera;
		System::Windows::Forms::Button^  btn_turnx;
		System::Windows::Forms::Button^  btn_turntc;
		System::Windows::Forms::Button^  btn_turntb;
		System::Windows::Forms::Button^  btn_turnta;
		System::Windows::Forms::Button^  btn_turnlb;
		System::Windows::Forms::Button^  btn_turnla;
		System::Windows::Forms::Button^  btn_turnu;
		System::Windows::Forms::Button^  btn_straightb;
		System::Windows::Forms::Button^  btn_straighta;
		System::Windows::Forms::Button^  btn_flat;
		System::Windows::Forms::Label^  lbl_info_2;
		System::Windows::Forms::Label^  lbl_info_1;
		System::Windows::Forms::FolderBrowserDialog^  fbd_autoLoad;
		System::ComponentModel::Container ^components;


	public:
		static ModelsControl^ activeInstance;

		ModelsControl(void);

		void reset();
		void update();

	protected:
		~ModelsControl();

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->link_auto = (gcnew System::Windows::Forms::LinkLabel());
			this->BLANK = (gcnew System::Windows::Forms::Label());
			this->btn_slopemid = (gcnew System::Windows::Forms::Button());
			this->btn_slopestraight_r = (gcnew System::Windows::Forms::Button());
			this->btn_slopestraight_l = (gcnew System::Windows::Forms::Button());
			this->btn_slopestraight = (gcnew System::Windows::Forms::Button());
			this->btn_slope = (gcnew System::Windows::Forms::Button());
			this->btn_cornerd = (gcnew System::Windows::Forms::Button());
			this->btn_cornerc = (gcnew System::Windows::Forms::Button());
			this->btn_cornerb = (gcnew System::Windows::Forms::Button());
			this->btn_cornera = (gcnew System::Windows::Forms::Button());
			this->btn_turnx = (gcnew System::Windows::Forms::Button());
			this->btn_turntc = (gcnew System::Windows::Forms::Button());
			this->btn_turntb = (gcnew System::Windows::Forms::Button());
			this->btn_turnta = (gcnew System::Windows::Forms::Button());
			this->btn_turnlb = (gcnew System::Windows::Forms::Button());
			this->btn_turnla = (gcnew System::Windows::Forms::Button());
			this->btn_turnu = (gcnew System::Windows::Forms::Button());
			this->btn_straightb = (gcnew System::Windows::Forms::Button());
			this->btn_straighta = (gcnew System::Windows::Forms::Button());
			this->btn_flat = (gcnew System::Windows::Forms::Button());
			this->lbl_info_2 = (gcnew System::Windows::Forms::Label());
			this->lbl_info_1 = (gcnew System::Windows::Forms::Label());
			this->fbd_autoLoad = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->SuspendLayout();
			// 
			// link_auto
			// 
			this->link_auto->AutoSize = true;
			this->link_auto->Location = System::Drawing::Point(179, 26);
			this->link_auto->Name = L"link_auto";
			this->link_auto->Size = System::Drawing::Size(170, 13);
			this->link_auto->TabIndex = 113;
			this->link_auto->TabStop = true;
			this->link_auto->Text = L"Click to auto-load the path models.";
			this->link_auto->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &ModelsControl::link_auto_LinkClicked);
			// 
			// BLANK
			// 
			this->BLANK->AutoSize = true;
			this->BLANK->Location = System::Drawing::Point(188, 338);
			this->BLANK->Name = L"BLANK";
			this->BLANK->Size = System::Drawing::Size(10, 13);
			this->BLANK->TabIndex = 112;
			this->BLANK->Text = L" ";
			// 
			// btn_slopemid
			// 
			this->btn_slopemid->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_slopemid->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_slopemid->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->btn_slopemid->Location = System::Drawing::Point(198, 283);
			this->btn_slopemid->Name = L"btn_slopemid";
			this->btn_slopemid->Size = System::Drawing::Size(165, 23);
			this->btn_slopemid->TabIndex = 111;
			this->btn_slopemid->Text = L"Load \'SlopeMid\'.";
			this->btn_slopemid->UseVisualStyleBackColor = true;
			this->btn_slopemid->Click += gcnew System::EventHandler(this, &ModelsControl::btn_slopemid_Click);
			// 
			// btn_slopestraight_r
			// 
			this->btn_slopestraight_r->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_slopestraight_r->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_slopestraight_r->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(177)));
			this->btn_slopestraight_r->Location = System::Drawing::Point(198, 254);
			this->btn_slopestraight_r->Name = L"btn_slopestraight_r";
			this->btn_slopestraight_r->Size = System::Drawing::Size(165, 23);
			this->btn_slopestraight_r->TabIndex = 110;
			this->btn_slopestraight_r->Text = L"Load \'SlopeStraightRight\'.";
			this->btn_slopestraight_r->UseVisualStyleBackColor = true;
			this->btn_slopestraight_r->Click += gcnew System::EventHandler(this, &ModelsControl::btn_slopestraight_r_Click);
			// 
			// btn_slopestraight_l
			// 
			this->btn_slopestraight_l->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_slopestraight_l->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_slopestraight_l->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(177)));
			this->btn_slopestraight_l->Location = System::Drawing::Point(198, 225);
			this->btn_slopestraight_l->Name = L"btn_slopestraight_l";
			this->btn_slopestraight_l->Size = System::Drawing::Size(165, 23);
			this->btn_slopestraight_l->TabIndex = 109;
			this->btn_slopestraight_l->Text = L"Load \'SlopeStraightLeft\'.";
			this->btn_slopestraight_l->UseVisualStyleBackColor = true;
			this->btn_slopestraight_l->Click += gcnew System::EventHandler(this, &ModelsControl::btn_slopestraight_l_Click);
			// 
			// btn_slopestraight
			// 
			this->btn_slopestraight->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_slopestraight->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_slopestraight->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(177)));
			this->btn_slopestraight->Location = System::Drawing::Point(198, 196);
			this->btn_slopestraight->Name = L"btn_slopestraight";
			this->btn_slopestraight->Size = System::Drawing::Size(165, 23);
			this->btn_slopestraight->TabIndex = 108;
			this->btn_slopestraight->Text = L"Load \'SlopeStraight\'.";
			this->btn_slopestraight->UseVisualStyleBackColor = true;
			this->btn_slopestraight->Click += gcnew System::EventHandler(this, &ModelsControl::btn_slopestraight_Click);
			// 
			// btn_slope
			// 
			this->btn_slope->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_slope->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_slope->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->btn_slope->Location = System::Drawing::Point(198, 167);
			this->btn_slope->Name = L"btn_slope";
			this->btn_slope->Size = System::Drawing::Size(165, 23);
			this->btn_slope->TabIndex = 107;
			this->btn_slope->Text = L"Load \'Slope\'.";
			this->btn_slope->UseVisualStyleBackColor = true;
			this->btn_slope->Click += gcnew System::EventHandler(this, &ModelsControl::btn_slope_Click);
			// 
			// btn_cornerd
			// 
			this->btn_cornerd->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_cornerd->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_cornerd->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->btn_cornerd->Location = System::Drawing::Point(198, 138);
			this->btn_cornerd->Name = L"btn_cornerd";
			this->btn_cornerd->Size = System::Drawing::Size(165, 23);
			this->btn_cornerd->TabIndex = 106;
			this->btn_cornerd->Text = L"Load \'CornerD\'.";
			this->btn_cornerd->UseVisualStyleBackColor = true;
			this->btn_cornerd->Click += gcnew System::EventHandler(this, &ModelsControl::btn_cornerd_Click);
			// 
			// btn_cornerc
			// 
			this->btn_cornerc->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_cornerc->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_cornerc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->btn_cornerc->Location = System::Drawing::Point(198, 109);
			this->btn_cornerc->Name = L"btn_cornerc";
			this->btn_cornerc->Size = System::Drawing::Size(165, 23);
			this->btn_cornerc->TabIndex = 105;
			this->btn_cornerc->Text = L"Load \'CornerC\'.";
			this->btn_cornerc->UseVisualStyleBackColor = true;
			this->btn_cornerc->Click += gcnew System::EventHandler(this, &ModelsControl::btn_cornerc_Click);
			// 
			// btn_cornerb
			// 
			this->btn_cornerb->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_cornerb->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_cornerb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->btn_cornerb->Location = System::Drawing::Point(198, 80);
			this->btn_cornerb->Name = L"btn_cornerb";
			this->btn_cornerb->Size = System::Drawing::Size(165, 23);
			this->btn_cornerb->TabIndex = 104;
			this->btn_cornerb->Text = L"Load \'CornerB\'.";
			this->btn_cornerb->UseVisualStyleBackColor = true;
			this->btn_cornerb->Click += gcnew System::EventHandler(this, &ModelsControl::btn_cornerb_Click);
			// 
			// btn_cornera
			// 
			this->btn_cornera->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_cornera->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_cornera->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->btn_cornera->Location = System::Drawing::Point(198, 51);
			this->btn_cornera->Name = L"btn_cornera";
			this->btn_cornera->Size = System::Drawing::Size(165, 23);
			this->btn_cornera->TabIndex = 103;
			this->btn_cornera->Text = L"Load \'CornerA\'.";
			this->btn_cornera->UseVisualStyleBackColor = true;
			this->btn_cornera->Click += gcnew System::EventHandler(this, &ModelsControl::btn_cornera_Click);
			// 
			// btn_turnx
			// 
			this->btn_turnx->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_turnx->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_turnx->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->btn_turnx->Location = System::Drawing::Point(107, 312);
			this->btn_turnx->Name = L"btn_turnx";
			this->btn_turnx->Size = System::Drawing::Size(165, 23);
			this->btn_turnx->TabIndex = 102;
			this->btn_turnx->Text = L"Load \'TurnX\'.";
			this->btn_turnx->UseVisualStyleBackColor = true;
			this->btn_turnx->Click += gcnew System::EventHandler(this, &ModelsControl::btn_turnx_Click);
			// 
			// btn_turntc
			// 
			this->btn_turntc->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_turntc->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_turntc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->btn_turntc->Location = System::Drawing::Point(17, 283);
			this->btn_turntc->Name = L"btn_turntc";
			this->btn_turntc->Size = System::Drawing::Size(165, 23);
			this->btn_turntc->TabIndex = 101;
			this->btn_turntc->Text = L"Load \'TurnTC\'.";
			this->btn_turntc->UseVisualStyleBackColor = true;
			this->btn_turntc->Click += gcnew System::EventHandler(this, &ModelsControl::btn_turntc_Click);
			// 
			// btn_turntb
			// 
			this->btn_turntb->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_turntb->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_turntb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->btn_turntb->Location = System::Drawing::Point(17, 254);
			this->btn_turntb->Name = L"btn_turntb";
			this->btn_turntb->Size = System::Drawing::Size(165, 23);
			this->btn_turntb->TabIndex = 100;
			this->btn_turntb->Text = L"Load \'TurnTB\'.";
			this->btn_turntb->UseVisualStyleBackColor = true;
			this->btn_turntb->Click += gcnew System::EventHandler(this, &ModelsControl::btn_turntb_Click);
			// 
			// btn_turnta
			// 
			this->btn_turnta->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_turnta->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_turnta->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->btn_turnta->Location = System::Drawing::Point(17, 225);
			this->btn_turnta->Name = L"btn_turnta";
			this->btn_turnta->Size = System::Drawing::Size(165, 23);
			this->btn_turnta->TabIndex = 99;
			this->btn_turnta->Text = L"Load \'TurnTA\'.";
			this->btn_turnta->UseVisualStyleBackColor = true;
			this->btn_turnta->Click += gcnew System::EventHandler(this, &ModelsControl::btn_turnta_Click);
			// 
			// btn_turnlb
			// 
			this->btn_turnlb->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_turnlb->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_turnlb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->btn_turnlb->Location = System::Drawing::Point(17, 196);
			this->btn_turnlb->Name = L"btn_turnlb";
			this->btn_turnlb->Size = System::Drawing::Size(165, 23);
			this->btn_turnlb->TabIndex = 98;
			this->btn_turnlb->Text = L"Load \'TurnLB\'.";
			this->btn_turnlb->UseVisualStyleBackColor = true;
			this->btn_turnlb->Click += gcnew System::EventHandler(this, &ModelsControl::btn_turnlb_Click);
			// 
			// btn_turnla
			// 
			this->btn_turnla->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_turnla->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_turnla->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->btn_turnla->Location = System::Drawing::Point(17, 167);
			this->btn_turnla->Name = L"btn_turnla";
			this->btn_turnla->Size = System::Drawing::Size(165, 23);
			this->btn_turnla->TabIndex = 97;
			this->btn_turnla->Text = L"Load \'TurnLA\'.";
			this->btn_turnla->UseVisualStyleBackColor = true;
			this->btn_turnla->Click += gcnew System::EventHandler(this, &ModelsControl::btn_turnla_Click);
			// 
			// btn_turnu
			// 
			this->btn_turnu->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_turnu->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_turnu->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->btn_turnu->Location = System::Drawing::Point(17, 138);
			this->btn_turnu->Name = L"btn_turnu";
			this->btn_turnu->Size = System::Drawing::Size(165, 23);
			this->btn_turnu->TabIndex = 96;
			this->btn_turnu->Text = L"Load \'TurnU\'.";
			this->btn_turnu->UseVisualStyleBackColor = true;
			this->btn_turnu->Click += gcnew System::EventHandler(this, &ModelsControl::btn_turnu_Click);
			// 
			// btn_straightb
			// 
			this->btn_straightb->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_straightb->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_straightb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->btn_straightb->Location = System::Drawing::Point(17, 109);
			this->btn_straightb->Name = L"btn_straightb";
			this->btn_straightb->Size = System::Drawing::Size(165, 23);
			this->btn_straightb->TabIndex = 95;
			this->btn_straightb->Text = L"Load \'StraightB\'.";
			this->btn_straightb->UseVisualStyleBackColor = true;
			this->btn_straightb->Click += gcnew System::EventHandler(this, &ModelsControl::btn_straightb_Click);
			// 
			// btn_straighta
			// 
			this->btn_straighta->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_straighta->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_straighta->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->btn_straighta->Location = System::Drawing::Point(17, 80);
			this->btn_straighta->Name = L"btn_straighta";
			this->btn_straighta->Size = System::Drawing::Size(165, 23);
			this->btn_straighta->TabIndex = 94;
			this->btn_straighta->Text = L"Load \'StraightA\'.";
			this->btn_straighta->UseVisualStyleBackColor = true;
			this->btn_straighta->Click += gcnew System::EventHandler(this, &ModelsControl::btn_straighta_Click);
			// 
			// btn_flat
			// 
			this->btn_flat->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_flat->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_flat->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->btn_flat->Location = System::Drawing::Point(17, 51);
			this->btn_flat->Name = L"btn_flat";
			this->btn_flat->Size = System::Drawing::Size(165, 23);
			this->btn_flat->TabIndex = 93;
			this->btn_flat->Text = L"Load \'Flat\'.";
			this->btn_flat->UseVisualStyleBackColor = true;
			this->btn_flat->Click += gcnew System::EventHandler(this, &ModelsControl::btn_flat_Click);
			// 
			// lbl_info_2
			// 
			this->lbl_info_2->AutoSize = true;
			this->lbl_info_2->Location = System::Drawing::Point(14, 26);
			this->lbl_info_2->Name = L"lbl_info_2";
			this->lbl_info_2->Size = System::Drawing::Size(161, 13);
			this->lbl_info_2->TabIndex = 92;
			this->lbl_info_2->Text = L"located in the \'Resources\' folder.";
			// 
			// lbl_info_1
			// 
			this->lbl_info_1->AutoSize = true;
			this->lbl_info_1->Location = System::Drawing::Point(14, 13);
			this->lbl_info_1->Name = L"lbl_info_1";
			this->lbl_info_1->Size = System::Drawing::Size(349, 13);
			this->lbl_info_1->TabIndex = 91;
			this->lbl_info_1->Text = L"All these models are required for a functional path! Reference images are";
			// 
			// ModelsControl
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->Controls->Add(this->link_auto);
			this->Controls->Add(this->BLANK);
			this->Controls->Add(this->btn_slopemid);
			this->Controls->Add(this->btn_slopestraight_r);
			this->Controls->Add(this->btn_slopestraight_l);
			this->Controls->Add(this->btn_slopestraight);
			this->Controls->Add(this->btn_slope);
			this->Controls->Add(this->btn_cornerd);
			this->Controls->Add(this->btn_cornerc);
			this->Controls->Add(this->btn_cornerb);
			this->Controls->Add(this->btn_cornera);
			this->Controls->Add(this->btn_turnx);
			this->Controls->Add(this->btn_turntc);
			this->Controls->Add(this->btn_turntb);
			this->Controls->Add(this->btn_turnta);
			this->Controls->Add(this->btn_turnlb);
			this->Controls->Add(this->btn_turnla);
			this->Controls->Add(this->btn_turnu);
			this->Controls->Add(this->btn_straightb);
			this->Controls->Add(this->btn_straighta);
			this->Controls->Add(this->btn_flat);
			this->Controls->Add(this->lbl_info_2);
			this->Controls->Add(this->lbl_info_1);
			this->Name = L"ModelsControl";
			this->Size = System::Drawing::Size(410, 160);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		void btn_flat_Click(System::Object^  sender, System::EventArgs^  e);

		void btn_straighta_Click(System::Object^  sender, System::EventArgs^  e);

		void btn_straightb_Click(System::Object^  sender, System::EventArgs^  e);

		void btn_turnu_Click(System::Object^  sender, System::EventArgs^  e);

		void btn_turnla_Click(System::Object^  sender, System::EventArgs^  e);

		void btn_turnlb_Click(System::Object^  sender, System::EventArgs^  e);

		void btn_turnta_Click(System::Object^  sender, System::EventArgs^  e);

		void btn_turntb_Click(System::Object^  sender, System::EventArgs^  e);

		void btn_turntc_Click(System::Object^  sender, System::EventArgs^  e);

		void btn_turnx_Click(System::Object^  sender, System::EventArgs^  e);

		void btn_cornera_Click(System::Object^  sender, System::EventArgs^  e);

		void btn_cornerb_Click(System::Object^  sender, System::EventArgs^  e);

		void btn_cornerc_Click(System::Object^  sender, System::EventArgs^  e);

		void btn_cornerd_Click(System::Object^  sender, System::EventArgs^  e);

		void btn_slope_Click(System::Object^  sender, System::EventArgs^  e);

		void btn_slopestraight_Click(System::Object^  sender, System::EventArgs^  e);

		void btn_slopestraight_l_Click(System::Object^  sender, System::EventArgs^  e);

		void btn_slopestraight_r_Click(System::Object^  sender, System::EventArgs^  e);

		void btn_slopemid_Click(System::Object^  sender, System::EventArgs^  e);

		void link_auto_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e);
	};
}
