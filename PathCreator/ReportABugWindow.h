#pragma once

#include "global.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Net::Mail;

namespace PathCreator {

	/// <summary>
	/// Summary for ReportABugWindow
	/// </summary>
	public ref class ReportABugWindow : public System::Windows::Forms::Form
	{
	public:
		ReportABugWindow(void)
		{
			InitializeComponent();
			
			btn_exit->BackgroundImage = GetResourceImage(IMG_BUTTON);
			btn_send->BackgroundImage = GetResourceImage(IMG_BUTTON_R);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ReportABugWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  lbl_name;
	private: System::Windows::Forms::Label^  lbl_email;
	private: System::Windows::Forms::TextBox^  txt_name;
	private: System::Windows::Forms::TextBox^  txt_email;
	private: System::Windows::Forms::TextBox^  txt_description;
	private: System::Windows::Forms::Label^  lbl_description;
	protected: 

	protected: 







	private: System::Windows::Forms::Button^  btn_exit;
	private: System::Windows::Forms::Button^  btn_send;


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
			this->lbl_name = (gcnew System::Windows::Forms::Label());
			this->lbl_email = (gcnew System::Windows::Forms::Label());
			this->txt_name = (gcnew System::Windows::Forms::TextBox());
			this->txt_email = (gcnew System::Windows::Forms::TextBox());
			this->txt_description = (gcnew System::Windows::Forms::TextBox());
			this->lbl_description = (gcnew System::Windows::Forms::Label());
			this->btn_exit = (gcnew System::Windows::Forms::Button());
			this->btn_send = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lbl_name
			// 
			this->lbl_name->AutoSize = true;
			this->lbl_name->Location = System::Drawing::Point(12, 9);
			this->lbl_name->Name = L"lbl_name";
			this->lbl_name->Size = System::Drawing::Size(85, 13);
			this->lbl_name->TabIndex = 0;
			this->lbl_name->Text = L"Name (required):";
			// 
			// lbl_email
			// 
			this->lbl_email->AutoSize = true;
			this->lbl_email->Location = System::Drawing::Point(12, 35);
			this->lbl_email->Name = L"lbl_email";
			this->lbl_email->Size = System::Drawing::Size(81, 13);
			this->lbl_email->TabIndex = 1;
			this->lbl_email->Text = L"Email (optional):";
			// 
			// txt_name
			// 
			this->txt_name->Location = System::Drawing::Point(103, 6);
			this->txt_name->Name = L"txt_name";
			this->txt_name->Size = System::Drawing::Size(169, 20);
			this->txt_name->TabIndex = 2;
			// 
			// txt_email
			// 
			this->txt_email->Location = System::Drawing::Point(103, 32);
			this->txt_email->Name = L"txt_email";
			this->txt_email->Size = System::Drawing::Size(169, 20);
			this->txt_email->TabIndex = 3;
			// 
			// txt_description
			// 
			this->txt_description->Location = System::Drawing::Point(15, 80);
			this->txt_description->MaxLength = 400;
			this->txt_description->Multiline = true;
			this->txt_description->Name = L"txt_description";
			this->txt_description->Size = System::Drawing::Size(257, 145);
			this->txt_description->TabIndex = 4;
			// 
			// lbl_description
			// 
			this->lbl_description->AutoSize = true;
			this->lbl_description->Location = System::Drawing::Point(12, 64);
			this->lbl_description->Name = L"lbl_description";
			this->lbl_description->Size = System::Drawing::Size(124, 13);
			this->lbl_description->TabIndex = 5;
			this->lbl_description->Text = L"Please describe the bug:";
			// 
			// btn_exit
			// 
			this->btn_exit->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_exit->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btn_exit->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_exit->Location = System::Drawing::Point(15, 231);
			this->btn_exit->Name = L"btn_exit";
			this->btn_exit->Size = System::Drawing::Size(120, 23);
			this->btn_exit->TabIndex = 14;
			this->btn_exit->Text = L"Cancel.";
			this->btn_exit->UseVisualStyleBackColor = true;
			this->btn_exit->Click += gcnew System::EventHandler(this, &ReportABugWindow::btn_exit_Click);
			// 
			// btn_send
			// 
			this->btn_send->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_send->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_send->Location = System::Drawing::Point(152, 231);
			this->btn_send->Name = L"btn_send";
			this->btn_send->Size = System::Drawing::Size(120, 23);
			this->btn_send->TabIndex = 15;
			this->btn_send->Text = L"Send.";
			this->btn_send->UseVisualStyleBackColor = true;
			this->btn_send->Click += gcnew System::EventHandler(this, &ReportABugWindow::btn_send_Click);
			// 
			// ReportABugWindow
			// 
			this->AcceptButton = this->btn_send;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->btn_exit;
			this->ClientSize = System::Drawing::Size(284, 266);
			this->Controls->Add(this->btn_send);
			this->Controls->Add(this->btn_exit);
			this->Controls->Add(this->lbl_description);
			this->Controls->Add(this->txt_description);
			this->Controls->Add(this->txt_email);
			this->Controls->Add(this->txt_name);
			this->Controls->Add(this->lbl_email);
			this->Controls->Add(this->lbl_name);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->MaximizeBox = false;
			this->Name = L"ReportABugWindow";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Report a Bug";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		void btn_exit_Click(System::Object^  sender, System::EventArgs^  e) {
			this->Close();
		}

		void btn_send_Click(System::Object^  sender, System::EventArgs^  e) {
			if (txt_name->TextLength <= 0) {
				MessageBox::Show("Please specify your name.");
				return;
			}

			if (txt_description->TextLength <= 0) {
				MessageBox::Show("Please describe the bug.");
				return;
			}

			String^ message = "Name: " + txt_name->Text;
			
			if (txt_email->TextLength > 0)
				message += "\nEmail: " + txt_email->Text;


		}
	};
}
