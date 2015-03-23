#pragma once

#include "stdafx.h"
#include "global.h"
#include "images.h"

using namespace System::Security;
using namespace System::Security::Permissions;

namespace PathCreator {

	/// <summary>
	/// Summary for ProgramSettingsWindow
	/// </summary>
	public ref class ProgramSettingsWindow : public System::Windows::Forms::Form
	{
	public:
		ProgramSettingsWindow(void)
		{
			InitializeComponent();
			
			btn_save->BackgroundImage = GetResourceImage(IMG_BUTTON_G);
			btn_clearRecents->BackgroundImage = GetResourceImage(IMG_BUTTON);
			btn_reset->BackgroundImage = GetResourceImage(IMG_BUTTON);

			txt_install->Text = global::Settings->RCT3InstallDirectory;
			cb_enableDebugging->Checked = global::Settings->DebugLog;

			switch (global::Settings->UpdateCheckFreq)
			{
				case UpdateFrequency::EveryWeek:
					list_updates->SelectedIndex = 0;
					break;
				case UpdateFrequency::EveryMonth:
					list_updates->SelectedIndex = 1;
					break;
				case UpdateFrequency::Manually:
					list_updates->SelectedIndex = 2;
					break;
				default:
					list_updates->SelectedIndex = 0;
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ProgramSettingsWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btn_save;
	private: System::Windows::Forms::Button^  btn_clearRecents;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  txt_install;
	private: System::Windows::Forms::CheckBox^  cb_enableDebugging;
	private: System::Windows::Forms::Button^  btn_reset;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ComboBox^  list_updates;



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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ProgramSettingsWindow::typeid));
			this->btn_save = (gcnew System::Windows::Forms::Button());
			this->btn_clearRecents = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txt_install = (gcnew System::Windows::Forms::TextBox());
			this->cb_enableDebugging = (gcnew System::Windows::Forms::CheckBox());
			this->btn_reset = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->list_updates = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// btn_save
			// 
			this->btn_save->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_save->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_save->Location = System::Drawing::Point(133, 100);
			this->btn_save->Name = L"btn_save";
			this->btn_save->Size = System::Drawing::Size(179, 23);
			this->btn_save->TabIndex = 0;
			this->btn_save->Text = L"Save.";
			this->btn_save->UseVisualStyleBackColor = true;
			this->btn_save->Click += gcnew System::EventHandler(this, &ProgramSettingsWindow::btn_save_Click);
			// 
			// btn_clearRecents
			// 
			this->btn_clearRecents->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_clearRecents->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_clearRecents->Location = System::Drawing::Point(15, 73);
			this->btn_clearRecents->Name = L"btn_clearRecents";
			this->btn_clearRecents->Size = System::Drawing::Size(115, 23);
			this->btn_clearRecents->TabIndex = 1;
			this->btn_clearRecents->Text = L"Clear recent projects.";
			this->btn_clearRecents->UseVisualStyleBackColor = true;
			this->btn_clearRecents->Click += gcnew System::EventHandler(this, &ProgramSettingsWindow::btn_clearRecents_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(113, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"RCT3 Install Directory:";
			// 
			// txt_install
			// 
			this->txt_install->Location = System::Drawing::Point(133, 17);
			this->txt_install->Name = L"txt_install";
			this->txt_install->Size = System::Drawing::Size(179, 20);
			this->txt_install->TabIndex = 3;
			// 
			// cb_enableDebugging
			// 
			this->cb_enableDebugging->AutoSize = true;
			this->cb_enableDebugging->Location = System::Drawing::Point(146, 77);
			this->cb_enableDebugging->Name = L"cb_enableDebugging";
			this->cb_enableDebugging->Size = System::Drawing::Size(153, 17);
			this->cb_enableDebugging->TabIndex = 5;
			this->cb_enableDebugging->Text = L"Enable OVL log debugging";
			this->cb_enableDebugging->UseVisualStyleBackColor = true;
			// 
			// btn_reset
			// 
			this->btn_reset->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_reset->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_reset->Location = System::Drawing::Point(15, 100);
			this->btn_reset->Name = L"btn_reset";
			this->btn_reset->Size = System::Drawing::Size(115, 23);
			this->btn_reset->TabIndex = 6;
			this->btn_reset->Text = L"Reset to defaults.";
			this->btn_reset->UseVisualStyleBackColor = true;
			this->btn_reset->Click += gcnew System::EventHandler(this, &ProgramSettingsWindow::btn_reset_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 46);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(105, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Check for updates if:";
			// 
			// list_updates
			// 
			this->list_updates->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->list_updates->FormattingEnabled = true;
			this->list_updates->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"It\'s been more than 7 days", L"It\'s been more than 30 days",
					L"Check for updates manually"
			});
			this->list_updates->Location = System::Drawing::Point(133, 43);
			this->list_updates->Name = L"list_updates";
			this->list_updates->Size = System::Drawing::Size(179, 21);
			this->list_updates->TabIndex = 8;
			// 
			// ProgramSettingsWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(324, 135);
			this->Controls->Add(this->list_updates);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->btn_reset);
			this->Controls->Add(this->cb_enableDebugging);
			this->Controls->Add(this->txt_install);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btn_clearRecents);
			this->Controls->Add(this->btn_save);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ProgramSettingsWindow";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"RCT3 Path Creator 2.0 - Settings";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


		void btn_save_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			global::Settings->DebugLog = cb_enableDebugging->Checked;
			global::Settings->SaveOnExit = true;

			unsigned int updateIndex = list_updates->SelectedIndex;

			switch (updateIndex)
			{
				case 0:
					global::Settings->UpdateCheckFreq = UpdateFrequency::EveryWeek;
					break;
				case 1:
					global::Settings->UpdateCheckFreq = UpdateFrequency::EveryMonth;
					break;
				case 2:
					global::Settings->UpdateCheckFreq = UpdateFrequency::Manually;
					break;
			}

			if (txt_install->Text != global::Settings->RCT3InstallDirectory)
			{
				if (!Directory::Exists(txt_install->Text))
				{
					MessageBox::Show(this, "RCT3 Install Directory does not exist...", "Error", MessageBoxButtons::OK,
						MessageBoxIcon::Error);
					return;
				}

				// check for permissions

				PermissionSet^ permissionSet = gcnew PermissionSet(PermissionState::None);
				FileIOPermission^ writePermission = gcnew FileIOPermission(FileIOPermissionAccess::Write, txt_install->Text);
				permissionSet->AddPermission(writePermission);

				if (!permissionSet->IsSubsetOf(AppDomain::CurrentDomain->PermissionSet))
				{
					MessageBox::Show(this, "RCT3 Path Creator does not have sufficient privileges "
						"to write to the specified install directory!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}

				global::Settings->RCT3InstallDirectory = txt_install->Text;
			}

			MessageBox::Show(this, "Your settings have been saved.", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
			this->Close();
		}

		void btn_reset_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			String^ msg;

			ProgramSettings^ settings = ProgramSettings::CreateDefault(msg);
			global::Settings = settings;

			if (msg != nullptr)
			{
				MessageBox::Show(this, msg, "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}

			txt_install->Text = global::Settings->RCT3InstallDirectory;
			cb_enableDebugging->Checked = global::Settings->DebugLog;

			MessageBox::Show(this, "Your settings have been reverted back to default.", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}

		void btn_clearRecents_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			global::Settings->RecentProjects->Clear();
			global::Settings->SaveOnExit = true;
			MessageBox::Show(this, "Your recent projects have been cleared.", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	};
}
