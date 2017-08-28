#pragma once
#include "Program.h"

namespace Innkjop {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for Login
	/// </summary>
	public ref class Login : public System::Windows::Forms::Form
	{
	public:
		Login(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Login()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  txtLUser;
	private: System::Windows::Forms::TextBox^  txtLPass;
	protected:

	private: System::Windows::Forms::Button^  btnLogin;
	private: System::Windows::Forms::Button^  btnCancel;

	protected:

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
			this->txtLUser = (gcnew System::Windows::Forms::TextBox());
			this->txtLPass = (gcnew System::Windows::Forms::TextBox());
			this->btnLogin = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// txtLUser
			// 
			this->txtLUser->Location = System::Drawing::Point(54, 61);
			this->txtLUser->Name = L"txtLUser";
			this->txtLUser->Size = System::Drawing::Size(176, 20);
			this->txtLUser->TabIndex = 0;
			this->txtLUser->Text = L"admin";
			// 
			// txtLPass
			// 
			this->txtLPass->Location = System::Drawing::Point(54, 105);
			this->txtLPass->Name = L"txtLPass";
			this->txtLPass->PasswordChar = '*';
			this->txtLPass->Size = System::Drawing::Size(175, 20);
			this->txtLPass->TabIndex = 1;
			this->txtLPass->Text = L"123";
			// 
			// btnLogin
			// 
			this->btnLogin->Location = System::Drawing::Point(54, 145);
			this->btnLogin->Name = L"btnLogin";
			this->btnLogin->Size = System::Drawing::Size(175, 33);
			this->btnLogin->TabIndex = 2;
			this->btnLogin->Text = L"Login";
			this->btnLogin->UseVisualStyleBackColor = true;
			this->btnLogin->Click += gcnew System::EventHandler(this, &Login::btnLogin_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->Location = System::Drawing::Point(54, 184);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(175, 33);
			this->btnCancel->TabIndex = 3;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &Login::btnCancel_Click);
			// 
			// Login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnLogin);
			this->Controls->Add(this->txtLPass);
			this->Controls->Add(this->txtLUser);
			this->Name = L"Login";
			this->Text = L"Login";
			this->Load += gcnew System::EventHandler(this, &Login::Login_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Login_Load(System::Object^  sender, System::EventArgs^  e) {
	}

private: System::Void btnCancel_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Close();
}
private: System::Void btnLogin_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ konfiguracja = L"datasource=localhost;port=3306;username=root;password=kolanko7;database=inn";
	MySqlConnection^ laczBaze = gcnew MySqlConnection(konfiguracja);
	MySqlCommand^ zapytanie = gcnew MySqlCommand("select user_id from users where user_name='" + txtLUser->Text + "' and password= PASSWORD('" + txtLPass->Text + "');", laczBaze);

	MySqlDataReader^ odczytanie;
	try {
		laczBaze->Open();
		odczytanie = zapytanie->ExecuteReader();
		if (odczytanie->Read()) {
			int id_user = odczytanie->GetInt32(0);
			this->Hide();
			Program^ program = gcnew Program(id_user);
			program->ShowDialog();
			this->Close();
		}
		else
		{
			MessageBox::Show("Błędna nazwa użytkownika lub niepoprawne hasło");
		}
	}
	catch (Exception^ ex) {
		MessageBox::Show(ex->Message);
	}
	laczBaze->Close();
}
};
}
