#pragma once

#include "stdafx.h"
#include "global.h"

namespace PathCreator {

	/// <summary>
	/// Summary for About
	/// </summary>
	public ref class About : public System::Windows::Forms::Form
	{
	public:
		About(void)
		{
			InitializeComponent();
			
			this->lbl_version->Text = global::Settings->CurrentVersion.ToString();
			this->btn_done->BackgroundImage = GetResourceImage(IMG_BUTTON);
			LinkLabel::Link^ link = gcnew LinkLabel::Link();
			link->LinkData = L"http://www.shyguysworld.com/index.php?action=profile;u=1881";
			this->linkLabel1->Links->Add(link);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~About()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btn_done;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  lbl_version;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::LinkLabel^  linkLabel1;


	protected:

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
			this->btn_done = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lbl_version = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->SuspendLayout();
			// 
			// btn_done
			// 
			this->btn_done->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btn_done->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_done->Location = System::Drawing::Point(12, 104);
			this->btn_done->Name = L"btn_done";
			this->btn_done->Size = System::Drawing::Size(244, 23);
			this->btn_done->TabIndex = 0;
			this->btn_done->Text = L"Done.";
			this->btn_done->UseVisualStyleBackColor = true;
			this->btn_done->Click += gcnew System::EventHandler(this, &About::btn_done_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 10);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(129, 15);
			this->label1->TabIndex = 1;
			this->label1->Text = L"RCT3 Path Creator 2.0";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(12, 30);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 15);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Version:";
			// 
			// lbl_version
			// 
			this->lbl_version->AutoSize = true;
			this->lbl_version->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_version->Location = System::Drawing::Point(61, 30);
			this->lbl_version->Name = L"lbl_version";
			this->lbl_version->Size = System::Drawing::Size(53, 15);
			this->lbl_version->TabIndex = 3;
			this->lbl_version->Text = L"EMPTY";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(13, 50);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(45, 15);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Author:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(61, 50);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(196, 15);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Noah Alex Roth (darkhorizon)";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(12, 71);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(51, 15);
			this->label6->TabIndex = 6;
			this->label6->Text = L"Contact:";
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->linkLabel1->LinkColor = System::Drawing::SystemColors::Highlight;
			this->linkLabel1->Location = System::Drawing::Point(61, 71);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->linkLabel1->Size = System::Drawing::Size(165, 15);
			this->linkLabel1->TabIndex = 7;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"shyguy\'s World Forum Profile";
			this->linkLabel1->VisitedLinkColor = System::Drawing::Color::PaleVioletRed;
			this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &About::linkLabel1_LinkClicked);
			// 
			// About
			// 
			this->AcceptButton = this->btn_done;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->btn_done;
			this->ClientSize = System::Drawing::Size(268, 139);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->lbl_version);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btn_done);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"About";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"RCT3 Path Creator 2.0 - About";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


		void btn_done_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			this->Close();
		}


		void linkLabel1_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) 
		{
			Process::Start(safe_cast<String^>(linkLabel1->Links[0]->LinkData));
		}
	};
}
