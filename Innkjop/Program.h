#pragma once

namespace Innkjop {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for Program
	/// </summary>



	public ref class Program : public System::Windows::Forms::Form
	{
	public:
		int id_user;
		bool powodzenie = false;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::DataGridView^  dgMFlowers;
	public:
	public:
		String^ konfiguracja = L"datasource=localhost;port=3306;username=root;password=kolanko7;database=inn";
		Program(int uzytkownik)
		{
			InitializeComponent();
			id_user = uzytkownik;
			
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Program()
		{
			if (components)
			{
				delete components;
			}
		}

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dgMFlowers = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgMFlowers))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(21, 14);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(50, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Program::button1_Click);
			// 
			// dgMFlowers
			// 
			this->dgMFlowers->AllowUserToAddRows = false;
			this->dgMFlowers->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgMFlowers->Location = System::Drawing::Point(27, 55);
			this->dgMFlowers->Name = L"dgMFlowers";
			this->dgMFlowers->Size = System::Drawing::Size(529, 137);
			this->dgMFlowers->TabIndex = 1;
			// 
			// Program
			// 
			this->ClientSize = System::Drawing::Size(730, 427);
			this->Controls->Add(this->dgMFlowers);
			this->Controls->Add(this->button1);
			this->Name = L"Program";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgMFlowers))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: void szukaj_klientow(System::Windows::Forms::DataGridView^ siatka) {
		MySqlConnection^ laczBaze = gcnew MySqlConnection(konfiguracja);
		MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT * FROM flowers", laczBaze);
		try
		{
			laczBaze->Open();
			MySqlDataAdapter^ moja = gcnew MySqlDataAdapter();
			moja->SelectCommand = zapytanie;
			DataTable^ tabela = gcnew DataTable();
			moja->Fill(tabela);

			BindingSource^ zrodlo = gcnew BindingSource();
			zrodlo->DataSource = tabela;
			siatka->DataSource = zrodlo;
			laczBaze->Close();
		}
		catch (Exception^ komunikat) {
			MessageBox::Show(komunikat->Message);
		}
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		szukaj_klientow(dgMFlowers);
	}
	};
}
