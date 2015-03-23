#pragma once

#include "stdafx.h"
#include "global.h"

namespace PathCreator {

	/// <summary>
	/// Summary for UpdateWindow
	/// </summary>
	public ref class UpdateWindow : public System::Windows::Forms::Form
	{
	public:
		UpdateWindow(String^ url, VersionInfo info)
		{
			InitializeComponent();
			
			DownloadUrl = url;

			btn_download->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
			btn_skip->BackgroundImage = GetResourceImage(IMG_BUTTON);
			rtf_patchNotes->Rtf = info.VersionInformationText;
			lbl_currentVersion->Text = global::Settings->CurrentVersion.ToString();
			lbl_version->Text = info.ToString();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~UpdateWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::Label^  lbl_version;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  lbl_currentVersion;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::RichTextBox^  rtf_patchNotes;
	private: System::Windows::Forms::Button^  btn_skip;
	private: System::Windows::Forms::Button^  btn_download;

		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

	public:
		String^ DownloadUrl;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(UpdateWindow::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lbl_version = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lbl_currentVersion = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->rtf_patchNotes = (gcnew System::Windows::Forms::RichTextBox());
			this->btn_skip = (gcnew System::Windows::Forms::Button());
			this->btn_download = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(15, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(134, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"A new update is available: ";
			// 
			// lbl_version
			// 
			this->lbl_version->AutoSize = true;
			this->lbl_version->Location = System::Drawing::Point(142, 13);
			this->lbl_version->Name = L"lbl_version";
			this->lbl_version->Size = System::Drawing::Size(67, 13);
			this->lbl_version->TabIndex = 1;
			this->lbl_version->Text = L"<VERSION>";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(15, 30);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(105, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Your current version:";
			// 
			// lbl_currentVersion
			// 
			this->lbl_currentVersion->AutoSize = true;
			this->lbl_currentVersion->Location = System::Drawing::Point(142, 30);
			this->lbl_currentVersion->Name = L"lbl_currentVersion";
			this->lbl_currentVersion->Size = System::Drawing::Size(67, 13);
			this->lbl_currentVersion->TabIndex = 3;
			this->lbl_currentVersion->Text = L"<VERSION>";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(15, 57);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(98, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"New version notes:";
			// 
			// rtf_patchNotes
			// 
			this->rtf_patchNotes->BackColor = System::Drawing::SystemColors::Window;
			this->rtf_patchNotes->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->rtf_patchNotes->Location = System::Drawing::Point(15, 74);
			this->rtf_patchNotes->Name = L"rtf_patchNotes";
			this->rtf_patchNotes->ReadOnly = true;
			this->rtf_patchNotes->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->rtf_patchNotes->Size = System::Drawing::Size(228, 120);
			this->rtf_patchNotes->TabIndex = 5;
			this->rtf_patchNotes->Text = L"";
			// 
			// btn_skip
			// 
			this->btn_skip->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_skip->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btn_skip->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_skip->Location = System::Drawing::Point(14, 200);
			this->btn_skip->Name = L"btn_skip";
			this->btn_skip->Size = System::Drawing::Size(99, 23);
			this->btn_skip->TabIndex = 6;
			this->btn_skip->Text = L"Skip this version.";
			this->btn_skip->UseVisualStyleBackColor = true;
			this->btn_skip->Click += gcnew System::EventHandler(this, &UpdateWindow::btn_skip_Click);
			// 
			// btn_download
			// 
			this->btn_download->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_download->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_download->Location = System::Drawing::Point(148, 200);
			this->btn_download->Name = L"btn_download";
			this->btn_download->Size = System::Drawing::Size(95, 23);
			this->btn_download->TabIndex = 7;
			this->btn_download->Text = L"Download.";
			this->btn_download->UseVisualStyleBackColor = true;
			this->btn_download->Click += gcnew System::EventHandler(this, &UpdateWindow::btn_download_Click);
			// 
			// UpdateWindow
			// 
			this->AcceptButton = this->btn_download;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->btn_skip;
			this->ClientSize = System::Drawing::Size(255, 231);
			this->Controls->Add(this->btn_download);
			this->Controls->Add(this->btn_skip);
			this->Controls->Add(this->rtf_patchNotes);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->lbl_currentVersion);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->lbl_version);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"UpdateWindow";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Update Available";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


		void btn_skip_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			this->Close();
		}

		void btn_download_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			Process::Start(DownloadUrl);
		}
	};
}
