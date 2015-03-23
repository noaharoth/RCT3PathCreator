// ExtendedModelsControl.h

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

#define PS_EXT_PATH_COUNT 36
#define PS_FLAT_FC 19
#define PS_SLOPE_FC 20
#define PS_SLOPE_BC 21
#define PS_SLOPE_TC 22
#define PS_SLOPE_STRAIGHT_FC 23
#define PS_SLOPE_STRAIGHT_BC 24
#define PS_SLOPE_STRAIGHT_TC 25
#define PS_SLOPE_STRAIGHT_L_FC 26
#define PS_SLOPE_STRAIGHT_L_BC 27
#define PS_SLOPE_STRAIGHT_L_TC 28
#define PS_SLOPE_STRAIGHT_R_FC 29
#define PS_SLOPE_STRAIGHT_R_BC 30
#define PS_SLOPE_STRAIGHT_R_TC 31
#define PS_SLOPE_MID_FC 32
#define PS_SLOPE_MID_BC 33
#define PS_SLOPE_MID_TC 34
#define PS_PAVING 35

	/// <summary>
	/// Summary for ExtendedModelsControl
	/// </summary>
	public ref class ExtendedModelsControl : public System::Windows::Forms::UserControl
	{
	private:
		array<OpenFileDialog^>^ section_ofds;
		System::Windows::Forms::LinkLabel^  link_auto;
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
		System::Windows::Forms::GroupBox^  extendedGroup;
		System::Windows::Forms::Button^  btn_flat_fc;
		System::Windows::Forms::Button^  btn_slope_tc;
		System::Windows::Forms::Button^  btn_slope_bc;
		System::Windows::Forms::Button^  btn_slope_fc;
		System::Windows::Forms::Button^  btn_slope_straight_tc;
		System::Windows::Forms::Button^  btn_slope_straight_bc;
		System::Windows::Forms::Button^  btn_slope_straight_fc;
		System::Windows::Forms::Button^  btn_slope_straight_l_bc;
		System::Windows::Forms::Button^  btn_slope_straight_l_fc;
		System::Windows::Forms::Button^  btn_slope_straight_l_tc;
		System::Windows::Forms::Button^  btn_slope_straight_r_tc;
		System::Windows::Forms::Button^  btn_slope_straight_r_bc;
		System::Windows::Forms::Button^  btn_slope_straight_r_fc;
		System::Windows::Forms::Button^  btn_paving;
		System::Windows::Forms::Button^  btn_slope_mid_tc;
		System::Windows::Forms::Button^  btn_slope_mid_bc;
		System::Windows::Forms::Button^  btn_slope_mid_fc;
		System::Windows::Forms::Label^  BLANK;
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::FolderBrowserDialog^  fbd_autoLoad;


	public:
		static ExtendedModelsControl^ activeInstance;

		ExtendedModelsControl(void);

		void reset();
		void update();

	protected:
		~ExtendedModelsControl();

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->link_auto = (gcnew System::Windows::Forms::LinkLabel());
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
			this->extendedGroup = (gcnew System::Windows::Forms::GroupBox());
			this->btn_paving = (gcnew System::Windows::Forms::Button());
			this->btn_slope_mid_tc = (gcnew System::Windows::Forms::Button());
			this->btn_slope_mid_bc = (gcnew System::Windows::Forms::Button());
			this->btn_slope_mid_fc = (gcnew System::Windows::Forms::Button());
			this->btn_slope_straight_r_tc = (gcnew System::Windows::Forms::Button());
			this->btn_slope_straight_r_bc = (gcnew System::Windows::Forms::Button());
			this->btn_slope_straight_r_fc = (gcnew System::Windows::Forms::Button());
			this->btn_slope_straight_l_tc = (gcnew System::Windows::Forms::Button());
			this->btn_slope_straight_l_bc = (gcnew System::Windows::Forms::Button());
			this->btn_slope_straight_l_fc = (gcnew System::Windows::Forms::Button());
			this->btn_slope_straight_tc = (gcnew System::Windows::Forms::Button());
			this->btn_slope_straight_bc = (gcnew System::Windows::Forms::Button());
			this->btn_slope_straight_fc = (gcnew System::Windows::Forms::Button());
			this->btn_slope_tc = (gcnew System::Windows::Forms::Button());
			this->btn_slope_bc = (gcnew System::Windows::Forms::Button());
			this->btn_slope_fc = (gcnew System::Windows::Forms::Button());
			this->btn_flat_fc = (gcnew System::Windows::Forms::Button());
			this->BLANK = (gcnew System::Windows::Forms::Label());
			this->fbd_autoLoad = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->extendedGroup->SuspendLayout();
			this->SuspendLayout();
			// 
			// link_auto
			// 
			this->link_auto->AutoSize = true;
			this->link_auto->Location = System::Drawing::Point(180, 26);
			this->link_auto->Name = L"link_auto";
			this->link_auto->Size = System::Drawing::Size(170, 13);
			this->link_auto->TabIndex = 136;
			this->link_auto->TabStop = true;
			this->link_auto->Text = L"Click to auto-load the path models.";
			this->link_auto->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &ExtendedModelsControl::link_auto_LinkClicked);
			// 
			// btn_slopemid
			// 
			this->btn_slopemid->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_slopemid->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_slopemid->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->btn_slopemid->Location = System::Drawing::Point(199, 283);
			this->btn_slopemid->Name = L"btn_slopemid";
			this->btn_slopemid->Size = System::Drawing::Size(165, 23);
			this->btn_slopemid->TabIndex = 134;
			this->btn_slopemid->Text = L"Load \'SlopeMid\'.";
			this->btn_slopemid->UseVisualStyleBackColor = true;
			this->btn_slopemid->Click += gcnew System::EventHandler(this, &ExtendedModelsControl::btn_slopemid_Click);
			// 
			// btn_slopestraight_r
			// 
			this->btn_slopestraight_r->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_slopestraight_r->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_slopestraight_r->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(177)));
			this->btn_slopestraight_r->Location = System::Drawing::Point(199, 254);
			this->btn_slopestraight_r->Name = L"btn_slopestraight_r";
			this->btn_slopestraight_r->Size = System::Drawing::Size(165, 23);
			this->btn_slopestraight_r->TabIndex = 133;
			this->btn_slopestraight_r->Text = L"Load \'SlopeStraightRight\'.";
			this->btn_slopestraight_r->UseVisualStyleBackColor = true;
			this->btn_slopestraight_r->Click += gcnew System::EventHandler(this, &ExtendedModelsControl::btn_slopestraight_r_Click);
			// 
			// btn_slopestraight_l
			// 
			this->btn_slopestraight_l->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_slopestraight_l->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_slopestraight_l->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(177)));
			this->btn_slopestraight_l->Location = System::Drawing::Point(199, 225);
			this->btn_slopestraight_l->Name = L"btn_slopestraight_l";
			this->btn_slopestraight_l->Size = System::Drawing::Size(165, 23);
			this->btn_slopestraight_l->TabIndex = 132;
			this->btn_slopestraight_l->Text = L"Load \'SlopeStraightLeft\'.";
			this->btn_slopestraight_l->UseVisualStyleBackColor = true;
			this->btn_slopestraight_l->Click += gcnew System::EventHandler(this, &ExtendedModelsControl::btn_slopestraight_l_Click);
			// 
			// btn_slopestraight
			// 
			this->btn_slopestraight->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_slopestraight->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_slopestraight->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(177)));
			this->btn_slopestraight->Location = System::Drawing::Point(199, 196);
			this->btn_slopestraight->Name = L"btn_slopestraight";
			this->btn_slopestraight->Size = System::Drawing::Size(165, 23);
			this->btn_slopestraight->TabIndex = 131;
			this->btn_slopestraight->Text = L"Load \'SlopeStraight\'.";
			this->btn_slopestraight->UseVisualStyleBackColor = true;
			this->btn_slopestraight->Click += gcnew System::EventHandler(this, &ExtendedModelsControl::btn_slopestraight_Click);
			// 
			// btn_slope
			// 
			this->btn_slope->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_slope->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_slope->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->btn_slope->Location = System::Drawing::Point(199, 167);
			this->btn_slope->Name = L"btn_slope";
			this->btn_slope->Size = System::Drawing::Size(165, 23);
			this->btn_slope->TabIndex = 130;
			this->btn_slope->Text = L"Load \'Slope\'.";
			this->btn_slope->UseVisualStyleBackColor = true;
			this->btn_slope->Click += gcnew System::EventHandler(this, &ExtendedModelsControl::btn_slope_Click);
			// 
			// btn_cornerd
			// 
			this->btn_cornerd->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_cornerd->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_cornerd->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->btn_cornerd->Location = System::Drawing::Point(199, 138);
			this->btn_cornerd->Name = L"btn_cornerd";
			this->btn_cornerd->Size = System::Drawing::Size(165, 23);
			this->btn_cornerd->TabIndex = 129;
			this->btn_cornerd->Text = L"Load \'CornerD\'.";
			this->btn_cornerd->UseVisualStyleBackColor = true;
			this->btn_cornerd->Click += gcnew System::EventHandler(this, &ExtendedModelsControl::btn_cornerd_Click);
			// 
			// btn_cornerc
			// 
			this->btn_cornerc->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_cornerc->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_cornerc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->btn_cornerc->Location = System::Drawing::Point(199, 109);
			this->btn_cornerc->Name = L"btn_cornerc";
			this->btn_cornerc->Size = System::Drawing::Size(165, 23);
			this->btn_cornerc->TabIndex = 128;
			this->btn_cornerc->Text = L"Load \'CornerC\'.";
			this->btn_cornerc->UseVisualStyleBackColor = true;
			this->btn_cornerc->Click += gcnew System::EventHandler(this, &ExtendedModelsControl::btn_cornerc_Click);
			// 
			// btn_cornerb
			// 
			this->btn_cornerb->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_cornerb->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_cornerb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->btn_cornerb->Location = System::Drawing::Point(199, 80);
			this->btn_cornerb->Name = L"btn_cornerb";
			this->btn_cornerb->Size = System::Drawing::Size(165, 23);
			this->btn_cornerb->TabIndex = 127;
			this->btn_cornerb->Text = L"Load \'CornerB\'.";
			this->btn_cornerb->UseVisualStyleBackColor = true;
			this->btn_cornerb->Click += gcnew System::EventHandler(this, &ExtendedModelsControl::btn_cornerb_Click);
			// 
			// btn_cornera
			// 
			this->btn_cornera->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_cornera->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_cornera->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->btn_cornera->Location = System::Drawing::Point(199, 51);
			this->btn_cornera->Name = L"btn_cornera";
			this->btn_cornera->Size = System::Drawing::Size(165, 23);
			this->btn_cornera->TabIndex = 126;
			this->btn_cornera->Text = L"Load \'CornerA\'.";
			this->btn_cornera->UseVisualStyleBackColor = true;
			this->btn_cornera->Click += gcnew System::EventHandler(this, &ExtendedModelsControl::btn_cornera_Click);
			// 
			// btn_turnx
			// 
			this->btn_turnx->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_turnx->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_turnx->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->btn_turnx->Location = System::Drawing::Point(109, 312);
			this->btn_turnx->Name = L"btn_turnx";
			this->btn_turnx->Size = System::Drawing::Size(165, 23);
			this->btn_turnx->TabIndex = 125;
			this->btn_turnx->Text = L"Load \'TurnX\'.";
			this->btn_turnx->UseVisualStyleBackColor = true;
			this->btn_turnx->Click += gcnew System::EventHandler(this, &ExtendedModelsControl::btn_turnx_Click);
			// 
			// btn_turntc
			// 
			this->btn_turntc->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_turntc->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_turntc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->btn_turntc->Location = System::Drawing::Point(18, 283);
			this->btn_turntc->Name = L"btn_turntc";
			this->btn_turntc->Size = System::Drawing::Size(165, 23);
			this->btn_turntc->TabIndex = 124;
			this->btn_turntc->Text = L"Load \'TurnTC\'.";
			this->btn_turntc->UseVisualStyleBackColor = true;
			this->btn_turntc->Click += gcnew System::EventHandler(this, &ExtendedModelsControl::btn_turntc_Click);
			// 
			// btn_turntb
			// 
			this->btn_turntb->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_turntb->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_turntb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->btn_turntb->Location = System::Drawing::Point(18, 254);
			this->btn_turntb->Name = L"btn_turntb";
			this->btn_turntb->Size = System::Drawing::Size(165, 23);
			this->btn_turntb->TabIndex = 123;
			this->btn_turntb->Text = L"Load \'TurnTB\'.";
			this->btn_turntb->UseVisualStyleBackColor = true;
			this->btn_turntb->Click += gcnew System::EventHandler(this, &ExtendedModelsControl::btn_turntb_Click);
			// 
			// btn_turnta
			// 
			this->btn_turnta->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_turnta->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_turnta->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->btn_turnta->Location = System::Drawing::Point(18, 225);
			this->btn_turnta->Name = L"btn_turnta";
			this->btn_turnta->Size = System::Drawing::Size(165, 23);
			this->btn_turnta->TabIndex = 122;
			this->btn_turnta->Text = L"Load \'TurnTA\'.";
			this->btn_turnta->UseVisualStyleBackColor = true;
			this->btn_turnta->Click += gcnew System::EventHandler(this, &ExtendedModelsControl::btn_turnta_Click);
			// 
			// btn_turnlb
			// 
			this->btn_turnlb->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_turnlb->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_turnlb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->btn_turnlb->Location = System::Drawing::Point(18, 196);
			this->btn_turnlb->Name = L"btn_turnlb";
			this->btn_turnlb->Size = System::Drawing::Size(165, 23);
			this->btn_turnlb->TabIndex = 121;
			this->btn_turnlb->Text = L"Load \'TurnLB\'.";
			this->btn_turnlb->UseVisualStyleBackColor = true;
			this->btn_turnlb->Click += gcnew System::EventHandler(this, &ExtendedModelsControl::btn_turnlb_Click);
			// 
			// btn_turnla
			// 
			this->btn_turnla->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_turnla->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_turnla->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->btn_turnla->Location = System::Drawing::Point(18, 167);
			this->btn_turnla->Name = L"btn_turnla";
			this->btn_turnla->Size = System::Drawing::Size(165, 23);
			this->btn_turnla->TabIndex = 120;
			this->btn_turnla->Text = L"Load \'TurnLA\'.";
			this->btn_turnla->UseVisualStyleBackColor = true;
			this->btn_turnla->Click += gcnew System::EventHandler(this, &ExtendedModelsControl::btn_turnla_Click);
			// 
			// btn_turnu
			// 
			this->btn_turnu->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_turnu->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_turnu->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->btn_turnu->Location = System::Drawing::Point(18, 138);
			this->btn_turnu->Name = L"btn_turnu";
			this->btn_turnu->Size = System::Drawing::Size(165, 23);
			this->btn_turnu->TabIndex = 119;
			this->btn_turnu->Text = L"Load \'TurnU\'.";
			this->btn_turnu->UseVisualStyleBackColor = true;
			this->btn_turnu->Click += gcnew System::EventHandler(this, &ExtendedModelsControl::btn_turnu_Click);
			// 
			// btn_straightb
			// 
			this->btn_straightb->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_straightb->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_straightb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->btn_straightb->Location = System::Drawing::Point(18, 109);
			this->btn_straightb->Name = L"btn_straightb";
			this->btn_straightb->Size = System::Drawing::Size(165, 23);
			this->btn_straightb->TabIndex = 118;
			this->btn_straightb->Text = L"Load \'StraightB\'.";
			this->btn_straightb->UseVisualStyleBackColor = true;
			this->btn_straightb->Click += gcnew System::EventHandler(this, &ExtendedModelsControl::btn_straightb_Click);
			// 
			// btn_straighta
			// 
			this->btn_straighta->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_straighta->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_straighta->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->btn_straighta->Location = System::Drawing::Point(18, 80);
			this->btn_straighta->Name = L"btn_straighta";
			this->btn_straighta->Size = System::Drawing::Size(165, 23);
			this->btn_straighta->TabIndex = 117;
			this->btn_straighta->Text = L"Load \'StraightA\'.";
			this->btn_straighta->UseVisualStyleBackColor = true;
			this->btn_straighta->Click += gcnew System::EventHandler(this, &ExtendedModelsControl::btn_straighta_Click);
			// 
			// btn_flat
			// 
			this->btn_flat->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_flat->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_flat->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->btn_flat->Location = System::Drawing::Point(18, 51);
			this->btn_flat->Name = L"btn_flat";
			this->btn_flat->Size = System::Drawing::Size(165, 23);
			this->btn_flat->TabIndex = 116;
			this->btn_flat->Text = L"Load \'Flat\'.";
			this->btn_flat->UseVisualStyleBackColor = true;
			this->btn_flat->Click += gcnew System::EventHandler(this, &ExtendedModelsControl::btn_flat_Click);
			// 
			// lbl_info_2
			// 
			this->lbl_info_2->AutoSize = true;
			this->lbl_info_2->Location = System::Drawing::Point(15, 26);
			this->lbl_info_2->Name = L"lbl_info_2";
			this->lbl_info_2->Size = System::Drawing::Size(161, 13);
			this->lbl_info_2->TabIndex = 115;
			this->lbl_info_2->Text = L"located in the \'Resources\' folder.";
			// 
			// lbl_info_1
			// 
			this->lbl_info_1->AutoSize = true;
			this->lbl_info_1->Location = System::Drawing::Point(15, 13);
			this->lbl_info_1->Name = L"lbl_info_1";
			this->lbl_info_1->Size = System::Drawing::Size(349, 13);
			this->lbl_info_1->TabIndex = 114;
			this->lbl_info_1->Text = L"All these models are required for a functional path! Reference images are";
			// 
			// extendedGroup
			// 
			this->extendedGroup->Controls->Add(this->btn_paving);
			this->extendedGroup->Controls->Add(this->btn_slope_mid_tc);
			this->extendedGroup->Controls->Add(this->btn_slope_mid_bc);
			this->extendedGroup->Controls->Add(this->btn_slope_mid_fc);
			this->extendedGroup->Controls->Add(this->btn_slope_straight_r_tc);
			this->extendedGroup->Controls->Add(this->btn_slope_straight_r_bc);
			this->extendedGroup->Controls->Add(this->btn_slope_straight_r_fc);
			this->extendedGroup->Controls->Add(this->btn_slope_straight_l_tc);
			this->extendedGroup->Controls->Add(this->btn_slope_straight_l_bc);
			this->extendedGroup->Controls->Add(this->btn_slope_straight_l_fc);
			this->extendedGroup->Controls->Add(this->btn_slope_straight_tc);
			this->extendedGroup->Controls->Add(this->btn_slope_straight_bc);
			this->extendedGroup->Controls->Add(this->btn_slope_straight_fc);
			this->extendedGroup->Controls->Add(this->btn_slope_tc);
			this->extendedGroup->Controls->Add(this->btn_slope_bc);
			this->extendedGroup->Controls->Add(this->btn_slope_fc);
			this->extendedGroup->Controls->Add(this->btn_flat_fc);
			this->extendedGroup->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->extendedGroup->Location = System::Drawing::Point(11, 341);
			this->extendedGroup->Name = L"extendedGroup";
			this->extendedGroup->Size = System::Drawing::Size(361, 290);
			this->extendedGroup->TabIndex = 137;
			this->extendedGroup->TabStop = false;
			this->extendedGroup->Text = L"Extended Models (optional)";
			// 
			// btn_paving
			// 
			this->btn_paving->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_paving->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_paving->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->btn_paving->ForeColor = System::Drawing::SystemColors::ControlText;
			this->btn_paving->Location = System::Drawing::Point(188, 225);
			this->btn_paving->Name = L"btn_paving";
			this->btn_paving->Size = System::Drawing::Size(165, 23);
			this->btn_paving->TabIndex = 155;
			this->btn_paving->Text = L"Load \'Paving\'.";
			this->btn_paving->UseVisualStyleBackColor = true;
			this->btn_paving->Click += gcnew System::EventHandler(this, &ExtendedModelsControl::btn_paving_Click);
			// 
			// btn_slope_mid_tc
			// 
			this->btn_slope_mid_tc->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_slope_mid_tc->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_slope_mid_tc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(177)));
			this->btn_slope_mid_tc->ForeColor = System::Drawing::SystemColors::ControlText;
			this->btn_slope_mid_tc->Location = System::Drawing::Point(188, 195);
			this->btn_slope_mid_tc->Name = L"btn_slope_mid_tc";
			this->btn_slope_mid_tc->Size = System::Drawing::Size(165, 23);
			this->btn_slope_mid_tc->TabIndex = 154;
			this->btn_slope_mid_tc->Text = L"Load \'SlopeMidTC\'.";
			this->btn_slope_mid_tc->UseVisualStyleBackColor = true;
			this->btn_slope_mid_tc->Click += gcnew System::EventHandler(this, &ExtendedModelsControl::btn_slope_mid_tc_Click);
			// 
			// btn_slope_mid_bc
			// 
			this->btn_slope_mid_bc->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_slope_mid_bc->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_slope_mid_bc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(177)));
			this->btn_slope_mid_bc->ForeColor = System::Drawing::SystemColors::ControlText;
			this->btn_slope_mid_bc->Location = System::Drawing::Point(188, 165);
			this->btn_slope_mid_bc->Name = L"btn_slope_mid_bc";
			this->btn_slope_mid_bc->Size = System::Drawing::Size(165, 23);
			this->btn_slope_mid_bc->TabIndex = 153;
			this->btn_slope_mid_bc->Text = L"Load \'SlopeMidBC\'.";
			this->btn_slope_mid_bc->UseVisualStyleBackColor = true;
			this->btn_slope_mid_bc->Click += gcnew System::EventHandler(this, &ExtendedModelsControl::btn_slope_mid_bc_Click);
			// 
			// btn_slope_mid_fc
			// 
			this->btn_slope_mid_fc->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_slope_mid_fc->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_slope_mid_fc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(177)));
			this->btn_slope_mid_fc->ForeColor = System::Drawing::SystemColors::ControlText;
			this->btn_slope_mid_fc->Location = System::Drawing::Point(188, 136);
			this->btn_slope_mid_fc->Name = L"btn_slope_mid_fc";
			this->btn_slope_mid_fc->Size = System::Drawing::Size(165, 23);
			this->btn_slope_mid_fc->TabIndex = 152;
			this->btn_slope_mid_fc->Text = L"Load \'SlopeMidFC\'.";
			this->btn_slope_mid_fc->UseVisualStyleBackColor = true;
			this->btn_slope_mid_fc->Click += gcnew System::EventHandler(this, &ExtendedModelsControl::btn_slope_mid_fc_Click);
			// 
			// btn_slope_straight_r_tc
			// 
			this->btn_slope_straight_r_tc->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_slope_straight_r_tc->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_slope_straight_r_tc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(177)));
			this->btn_slope_straight_r_tc->ForeColor = System::Drawing::SystemColors::ControlText;
			this->btn_slope_straight_r_tc->Location = System::Drawing::Point(188, 107);
			this->btn_slope_straight_r_tc->Name = L"btn_slope_straight_r_tc";
			this->btn_slope_straight_r_tc->Size = System::Drawing::Size(165, 23);
			this->btn_slope_straight_r_tc->TabIndex = 151;
			this->btn_slope_straight_r_tc->Text = L"Load \'SlopeStraightRTC\'.";
			this->btn_slope_straight_r_tc->UseVisualStyleBackColor = true;
			this->btn_slope_straight_r_tc->Click += gcnew System::EventHandler(this, &ExtendedModelsControl::btn_slope_straight_r_tc_Click);
			// 
			// btn_slope_straight_r_bc
			// 
			this->btn_slope_straight_r_bc->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_slope_straight_r_bc->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_slope_straight_r_bc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(177)));
			this->btn_slope_straight_r_bc->ForeColor = System::Drawing::SystemColors::ControlText;
			this->btn_slope_straight_r_bc->Location = System::Drawing::Point(188, 78);
			this->btn_slope_straight_r_bc->Name = L"btn_slope_straight_r_bc";
			this->btn_slope_straight_r_bc->Size = System::Drawing::Size(165, 23);
			this->btn_slope_straight_r_bc->TabIndex = 150;
			this->btn_slope_straight_r_bc->Text = L"Load \'SlopeStraightRBC\'.";
			this->btn_slope_straight_r_bc->UseVisualStyleBackColor = true;
			this->btn_slope_straight_r_bc->Click += gcnew System::EventHandler(this, &ExtendedModelsControl::btn_slope_straight_r_bc_Click);
			// 
			// btn_slope_straight_r_fc
			// 
			this->btn_slope_straight_r_fc->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_slope_straight_r_fc->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_slope_straight_r_fc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(177)));
			this->btn_slope_straight_r_fc->ForeColor = System::Drawing::SystemColors::ControlText;
			this->btn_slope_straight_r_fc->Location = System::Drawing::Point(188, 48);
			this->btn_slope_straight_r_fc->Name = L"btn_slope_straight_r_fc";
			this->btn_slope_straight_r_fc->Size = System::Drawing::Size(165, 23);
			this->btn_slope_straight_r_fc->TabIndex = 149;
			this->btn_slope_straight_r_fc->Text = L"Load \'SlopeStraightRFC\'.";
			this->btn_slope_straight_r_fc->UseVisualStyleBackColor = true;
			this->btn_slope_straight_r_fc->Click += gcnew System::EventHandler(this, &ExtendedModelsControl::btn_slope_straight_r_fc_Click);
			// 
			// btn_slope_straight_l_tc
			// 
			this->btn_slope_straight_l_tc->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_slope_straight_l_tc->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_slope_straight_l_tc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(177)));
			this->btn_slope_straight_l_tc->ForeColor = System::Drawing::SystemColors::ControlText;
			this->btn_slope_straight_l_tc->Location = System::Drawing::Point(188, 19);
			this->btn_slope_straight_l_tc->Name = L"btn_slope_straight_l_tc";
			this->btn_slope_straight_l_tc->Size = System::Drawing::Size(165, 23);
			this->btn_slope_straight_l_tc->TabIndex = 148;
			this->btn_slope_straight_l_tc->Text = L"Load \'SlopeStraightLTC\'.";
			this->btn_slope_straight_l_tc->UseVisualStyleBackColor = true;
			this->btn_slope_straight_l_tc->Click += gcnew System::EventHandler(this, &ExtendedModelsControl::btn_slope_straight_l_tc_Click);
			// 
			// btn_slope_straight_l_bc
			// 
			this->btn_slope_straight_l_bc->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_slope_straight_l_bc->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_slope_straight_l_bc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(177)));
			this->btn_slope_straight_l_bc->ForeColor = System::Drawing::SystemColors::ControlText;
			this->btn_slope_straight_l_bc->Location = System::Drawing::Point(97, 255);
			this->btn_slope_straight_l_bc->Name = L"btn_slope_straight_l_bc";
			this->btn_slope_straight_l_bc->Size = System::Drawing::Size(166, 23);
			this->btn_slope_straight_l_bc->TabIndex = 147;
			this->btn_slope_straight_l_bc->Text = L"Load \'SlopeStraightLBC\'.";
			this->btn_slope_straight_l_bc->UseVisualStyleBackColor = true;
			this->btn_slope_straight_l_bc->Click += gcnew System::EventHandler(this, &ExtendedModelsControl::btn_slope_straight_l_bc_Click);
			// 
			// btn_slope_straight_l_fc
			// 
			this->btn_slope_straight_l_fc->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_slope_straight_l_fc->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_slope_straight_l_fc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(177)));
			this->btn_slope_straight_l_fc->ForeColor = System::Drawing::SystemColors::ControlText;
			this->btn_slope_straight_l_fc->Location = System::Drawing::Point(6, 225);
			this->btn_slope_straight_l_fc->Name = L"btn_slope_straight_l_fc";
			this->btn_slope_straight_l_fc->Size = System::Drawing::Size(166, 23);
			this->btn_slope_straight_l_fc->TabIndex = 146;
			this->btn_slope_straight_l_fc->Text = L"Load \'SlopeStraightLFC\'.";
			this->btn_slope_straight_l_fc->UseVisualStyleBackColor = true;
			this->btn_slope_straight_l_fc->Click += gcnew System::EventHandler(this, &ExtendedModelsControl::btn_slope_straight_l_fc_Click);
			// 
			// btn_slope_straight_tc
			// 
			this->btn_slope_straight_tc->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_slope_straight_tc->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_slope_straight_tc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(177)));
			this->btn_slope_straight_tc->ForeColor = System::Drawing::SystemColors::ControlText;
			this->btn_slope_straight_tc->Location = System::Drawing::Point(6, 195);
			this->btn_slope_straight_tc->Name = L"btn_slope_straight_tc";
			this->btn_slope_straight_tc->Size = System::Drawing::Size(166, 23);
			this->btn_slope_straight_tc->TabIndex = 145;
			this->btn_slope_straight_tc->Text = L"Load \'SlopeStraightTC\'.";
			this->btn_slope_straight_tc->UseVisualStyleBackColor = true;
			this->btn_slope_straight_tc->Click += gcnew System::EventHandler(this, &ExtendedModelsControl::btn_slope_straight_tc_Click);
			// 
			// btn_slope_straight_bc
			// 
			this->btn_slope_straight_bc->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_slope_straight_bc->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_slope_straight_bc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(177)));
			this->btn_slope_straight_bc->ForeColor = System::Drawing::SystemColors::ControlText;
			this->btn_slope_straight_bc->Location = System::Drawing::Point(6, 165);
			this->btn_slope_straight_bc->Name = L"btn_slope_straight_bc";
			this->btn_slope_straight_bc->Size = System::Drawing::Size(166, 23);
			this->btn_slope_straight_bc->TabIndex = 144;
			this->btn_slope_straight_bc->Text = L"Load \'SlopeStraightBC\'.";
			this->btn_slope_straight_bc->UseVisualStyleBackColor = true;
			this->btn_slope_straight_bc->Click += gcnew System::EventHandler(this, &ExtendedModelsControl::btn_slope_straight_bc_Click);
			// 
			// btn_slope_straight_fc
			// 
			this->btn_slope_straight_fc->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_slope_straight_fc->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_slope_straight_fc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(177)));
			this->btn_slope_straight_fc->ForeColor = System::Drawing::SystemColors::ControlText;
			this->btn_slope_straight_fc->Location = System::Drawing::Point(6, 136);
			this->btn_slope_straight_fc->Name = L"btn_slope_straight_fc";
			this->btn_slope_straight_fc->Size = System::Drawing::Size(166, 23);
			this->btn_slope_straight_fc->TabIndex = 143;
			this->btn_slope_straight_fc->Text = L"Load \'SlopeStraightFC\'.";
			this->btn_slope_straight_fc->UseVisualStyleBackColor = true;
			this->btn_slope_straight_fc->Click += gcnew System::EventHandler(this, &ExtendedModelsControl::btn_slope_straight_fc_Click);
			// 
			// btn_slope_tc
			// 
			this->btn_slope_tc->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_slope_tc->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_slope_tc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->btn_slope_tc->ForeColor = System::Drawing::SystemColors::ControlText;
			this->btn_slope_tc->Location = System::Drawing::Point(6, 107);
			this->btn_slope_tc->Name = L"btn_slope_tc";
			this->btn_slope_tc->Size = System::Drawing::Size(166, 23);
			this->btn_slope_tc->TabIndex = 142;
			this->btn_slope_tc->Text = L"Load \'SlopeTC\'.";
			this->btn_slope_tc->UseVisualStyleBackColor = true;
			this->btn_slope_tc->Click += gcnew System::EventHandler(this, &ExtendedModelsControl::btn_slope_tc_Click);
			// 
			// btn_slope_bc
			// 
			this->btn_slope_bc->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_slope_bc->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_slope_bc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->btn_slope_bc->ForeColor = System::Drawing::SystemColors::ControlText;
			this->btn_slope_bc->Location = System::Drawing::Point(6, 77);
			this->btn_slope_bc->Name = L"btn_slope_bc";
			this->btn_slope_bc->Size = System::Drawing::Size(166, 23);
			this->btn_slope_bc->TabIndex = 141;
			this->btn_slope_bc->Text = L"Load \'SlopeBC\'.";
			this->btn_slope_bc->UseVisualStyleBackColor = true;
			this->btn_slope_bc->Click += gcnew System::EventHandler(this, &ExtendedModelsControl::btn_slope_bc_Click);
			// 
			// btn_slope_fc
			// 
			this->btn_slope_fc->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_slope_fc->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_slope_fc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->btn_slope_fc->ForeColor = System::Drawing::SystemColors::ControlText;
			this->btn_slope_fc->Location = System::Drawing::Point(6, 48);
			this->btn_slope_fc->Name = L"btn_slope_fc";
			this->btn_slope_fc->Size = System::Drawing::Size(166, 23);
			this->btn_slope_fc->TabIndex = 140;
			this->btn_slope_fc->Text = L"Load \'SlopeFC\'.";
			this->btn_slope_fc->UseVisualStyleBackColor = true;
			this->btn_slope_fc->Click += gcnew System::EventHandler(this, &ExtendedModelsControl::btn_slope_fc_Click);
			// 
			// btn_flat_fc
			// 
			this->btn_flat_fc->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_flat_fc->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_flat_fc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->btn_flat_fc->ForeColor = System::Drawing::SystemColors::ControlText;
			this->btn_flat_fc->Location = System::Drawing::Point(6, 19);
			this->btn_flat_fc->Name = L"btn_flat_fc";
			this->btn_flat_fc->Size = System::Drawing::Size(166, 23);
			this->btn_flat_fc->TabIndex = 138;
			this->btn_flat_fc->Text = L"Load \'FlatFC\'.";
			this->btn_flat_fc->UseVisualStyleBackColor = true;
			this->btn_flat_fc->Click += gcnew System::EventHandler(this, &ExtendedModelsControl::btn_flat_fc_Click);
			// 
			// BLANK
			// 
			this->BLANK->AutoSize = true;
			this->BLANK->Location = System::Drawing::Point(372, 635);
			this->BLANK->Name = L"BLANK";
			this->BLANK->Size = System::Drawing::Size(19, 13);
			this->BLANK->TabIndex = 138;
			this->BLANK->Text = L"    ";
			// 
			// ExtendedModelsControl
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->AutoScrollMinSize = System::Drawing::Size(20, 20);
			this->Controls->Add(this->BLANK);
			this->Controls->Add(this->extendedGroup);
			this->Controls->Add(this->link_auto);
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
			this->Name = L"ExtendedModelsControl";
			this->Size = System::Drawing::Size(410, 160);
			this->extendedGroup->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		void link_auto_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e);

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

		void btn_flat_fc_Click(System::Object^  sender, System::EventArgs^  e);

		void btn_slope_fc_Click(System::Object^  sender, System::EventArgs^  e);

		void btn_slope_bc_Click(System::Object^  sender, System::EventArgs^  e);

		void btn_slope_tc_Click(System::Object^  sender, System::EventArgs^  e);

		void btn_slope_straight_fc_Click(System::Object^  sender, System::EventArgs^  e);

		void btn_slope_straight_bc_Click(System::Object^  sender, System::EventArgs^  e);

		void btn_slope_straight_tc_Click(System::Object^  sender, System::EventArgs^  e);

		void btn_slope_straight_l_fc_Click(System::Object^  sender, System::EventArgs^  e);

		void btn_slope_straight_l_bc_Click(System::Object^  sender, System::EventArgs^  e);

		void btn_slope_straight_l_tc_Click(System::Object^  sender, System::EventArgs^  e);

		void btn_slope_straight_r_fc_Click(System::Object^  sender, System::EventArgs^  e);

		void btn_slope_straight_r_bc_Click(System::Object^  sender, System::EventArgs^  e);

		void btn_slope_straight_r_tc_Click(System::Object^  sender, System::EventArgs^  e);

		void btn_slope_mid_fc_Click(System::Object^  sender, System::EventArgs^  e);

		void btn_slope_mid_bc_Click(System::Object^  sender, System::EventArgs^  e);

		void btn_slope_mid_tc_Click(System::Object^  sender, System::EventArgs^  e);

		void btn_paving_Click(System::Object^  sender, System::EventArgs^  e);
		 
	};
}
