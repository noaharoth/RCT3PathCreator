// AutoLoadDialog.h

#pragma once

#include "global.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace PathCreator {

	/// <summary>
	/// Summary for AutoLoadDialog
	/// </summary>
	public ref class AutoLoadDialog : public System::Windows::Forms::Form
	{
		System::Windows::Forms::Label^  lbl_note;
		System::Windows::Forms::Button^  btn_ok;
		System::Windows::Forms::Button^  btn_cancel;
		System::Windows::Forms::CheckBox^  cb_separated;
		System::Windows::Forms::CheckBox^  cb_underlined;
		System::Windows::Forms::CheckBox^  cb_complete;
		System::Windows::Forms::Label^  lbl_info;
		System::ComponentModel::Container ^components;

	public:
		AutoLoadDialog(void);

		bool complete();
		bool underlined();
		bool separated();

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AutoLoadDialog();

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lbl_note = (gcnew System::Windows::Forms::Label());
			this->btn_ok = (gcnew System::Windows::Forms::Button());
			this->btn_cancel = (gcnew System::Windows::Forms::Button());
			this->cb_separated = (gcnew System::Windows::Forms::CheckBox());
			this->cb_underlined = (gcnew System::Windows::Forms::CheckBox());
			this->cb_complete = (gcnew System::Windows::Forms::CheckBox());
			this->lbl_info = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lbl_note
			// 
			this->lbl_note->AutoSize = true;
			this->lbl_note->Enabled = false;
			this->lbl_note->Location = System::Drawing::Point(29, 100);
			this->lbl_note->Name = L"lbl_note";
			this->lbl_note->Size = System::Drawing::Size(162, 13);
			this->lbl_note->TabIndex = 90;
			this->lbl_note->Text = L"(Note: search is case-insensitive)";
			// 
			// btn_ok
			// 
			this->btn_ok->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_ok->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->btn_ok->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_ok->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(177)));
			this->btn_ok->Location = System::Drawing::Point(128, 123);
			this->btn_ok->Name = L"btn_ok";
			this->btn_ok->Size = System::Drawing::Size(80, 23);
			this->btn_ok->TabIndex = 89;
			this->btn_ok->Text = L"OK.";
			this->btn_ok->UseVisualStyleBackColor = true;
			this->btn_ok->Click += gcnew System::EventHandler(this, &AutoLoadDialog::btn_ok_Click);
			// 
			// btn_cancel
			// 
			this->btn_cancel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_cancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btn_cancel->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_cancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(177)));
			this->btn_cancel->Location = System::Drawing::Point(12, 123);
			this->btn_cancel->Name = L"btn_cancel";
			this->btn_cancel->Size = System::Drawing::Size(80, 23);
			this->btn_cancel->TabIndex = 88;
			this->btn_cancel->Text = L"Cancel.";
			this->btn_cancel->UseVisualStyleBackColor = true;
			this->btn_cancel->Click += gcnew System::EventHandler(this, &AutoLoadDialog::btn_cancel_Click);
			// 
			// cb_separated
			// 
			this->cb_separated->AutoSize = true;
			this->cb_separated->Checked = true;
			this->cb_separated->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cb_separated->Location = System::Drawing::Point(15, 78);
			this->cb_separated->Name = L"cb_separated";
			this->cb_separated->Size = System::Drawing::Size(146, 17);
			this->cb_separated->TabIndex = 87;
			this->cb_separated->Text = L"Separated (i.e. \'Turn-L-A\')";
			this->cb_separated->UseVisualStyleBackColor = true;
			// 
			// cb_underlined
			// 
			this->cb_underlined->AutoSize = true;
			this->cb_underlined->Checked = true;
			this->cb_underlined->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cb_underlined->Location = System::Drawing::Point(15, 55);
			this->cb_underlined->Name = L"cb_underlined";
			this->cb_underlined->Size = System::Drawing::Size(154, 17);
			this->cb_underlined->TabIndex = 86;
			this->cb_underlined->Text = L"Underlined (i.e. \'Turn_L_A\')";
			this->cb_underlined->UseVisualStyleBackColor = true;
			// 
			// cb_complete
			// 
			this->cb_complete->AutoSize = true;
			this->cb_complete->Checked = true;
			this->cb_complete->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cb_complete->Location = System::Drawing::Point(15, 32);
			this->cb_complete->Name = L"cb_complete";
			this->cb_complete->Size = System::Drawing::Size(135, 17);
			this->cb_complete->TabIndex = 85;
			this->cb_complete->Text = L"Complete (i.e. \'TurnLA\')";
			this->cb_complete->UseVisualStyleBackColor = true;
			// 
			// lbl_info
			// 
			this->lbl_info->AutoSize = true;
			this->lbl_info->Location = System::Drawing::Point(12, 11);
			this->lbl_info->Name = L"lbl_info";
			this->lbl_info->Size = System::Drawing::Size(192, 13);
			this->lbl_info->TabIndex = 84;
			this->lbl_info->Text = L"Select the naming style(s) to search for:";
			// 
			// AutoLoadDialog
			// 
			this->AcceptButton = this->btn_ok;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->btn_cancel;
			this->ClientSize = System::Drawing::Size(220, 153);
			this->Controls->Add(this->lbl_note);
			this->Controls->Add(this->btn_ok);
			this->Controls->Add(this->btn_cancel);
			this->Controls->Add(this->cb_separated);
			this->Controls->Add(this->cb_underlined);
			this->Controls->Add(this->cb_complete);
			this->Controls->Add(this->lbl_info);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->MaximizeBox = false;
			this->Name = L"AutoLoadDialog";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Auto-Load Models";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		void btn_cancel_Click(System::Object^  sender, System::EventArgs^  e);

		void btn_ok_Click(System::Object^  sender, System::EventArgs^  e);
	};
}
