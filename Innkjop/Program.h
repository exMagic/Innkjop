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
	private: System::Windows::Forms::DataGridView^  dgOrder;


	private: System::Windows::Forms::DataGridView^  dgOrders;


	public:
		String^ order_nr;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::DataGridView^  dgAvvik;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;






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
			showOrders(dgOrders);
			dgOrders->Columns[0]->Visible = false;
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
			this->dgOrder = (gcnew System::Windows::Forms::DataGridView());
			this->dgOrders = (gcnew System::Windows::Forms::DataGridView());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->dgAvvik = (gcnew System::Windows::Forms::DataGridView());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgMFlowers))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgOrder))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgOrders))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAvvik))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(23, 15);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(50, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"All";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Program::button1_Click);
			// 
			// dgMFlowers
			// 
			this->dgMFlowers->AllowUserToAddRows = false;
			this->dgMFlowers->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgMFlowers->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgMFlowers->Location = System::Drawing::Point(23, 60);
			this->dgMFlowers->Name = L"dgMFlowers";
			this->dgMFlowers->Size = System::Drawing::Size(1121, 443);
			this->dgMFlowers->TabIndex = 1;
			this->dgMFlowers->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Program::dgMFlowers_CellContentClick);
			// 
			// dgOrder
			// 
			this->dgOrder->AllowUserToAddRows = false;
			this->dgOrder->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgOrder->Location = System::Drawing::Point(376, 56);
			this->dgOrder->Name = L"dgOrder";
			this->dgOrder->Size = System::Drawing::Size(529, 137);
			this->dgOrder->TabIndex = 3;
			this->dgOrder->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Program::dgOrder_CellContentClick);
			// 
			// dgOrders
			// 
			this->dgOrders->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgOrders->Location = System::Drawing::Point(922, 56);
			this->dgOrders->Name = L"dgOrders";
			this->dgOrders->Size = System::Drawing::Size(96, 318);
			this->dgOrders->TabIndex = 4;
			this->dgOrders->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Program::dgOrders_CellClick);
			this->dgOrders->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Program::dgOrders_CellContentClick);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(376, 40);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(31, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"order";
			this->label3->Click += gcnew System::EventHandler(this, &Program::label3_Click);
			// 
			// dgAvvik
			// 
			this->dgAvvik->AllowUserToAddRows = false;
			this->dgAvvik->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgAvvik->Location = System::Drawing::Point(376, 237);
			this->dgAvvik->Name = L"dgAvvik";
			this->dgAvvik->Size = System::Drawing::Size(529, 137);
			this->dgAvvik->TabIndex = 7;
			this->dgAvvik->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Program::dgAvvik_CellContentClick);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(373, 221);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(34, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Avvik";
			this->label4->Click += gcnew System::EventHandler(this, &Program::label4_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(919, 30);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(53, 13);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Orders list";
			this->label5->Click += gcnew System::EventHandler(this, &Program::label5_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(12, 28);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1196, 564);
			this->tabControl1->TabIndex = 10;
			this->tabControl1->SelectedIndexChanged += gcnew System::EventHandler(this, &Program::tabControl1_SelectedIndexChanged);
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->dgMFlowers);
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1188, 538);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Flowers base";
			this->tabPage1->UseVisualStyleBackColor = true;
			this->tabPage1->Click += gcnew System::EventHandler(this, &Program::tabPage1_Click);
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->dgOrders);
			this->tabPage2->Controls->Add(this->label5);
			this->tabPage2->Controls->Add(this->dgOrder);
			this->tabPage2->Controls->Add(this->label4);
			this->tabPage2->Controls->Add(this->label3);
			this->tabPage2->Controls->Add(this->dgAvvik);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(1188, 538);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Orders";
			this->tabPage2->UseVisualStyleBackColor = true;
			this->tabPage2->Click += gcnew System::EventHandler(this, &Program::tabPage2_Click);
			// 
			// Program
			// 
			this->ClientSize = System::Drawing::Size(1220, 647);
			this->Controls->Add(this->tabControl1);
			this->Name = L"Program";
			this->Load += gcnew System::EventHandler(this, &Program::Program_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgMFlowers))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgOrder))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgOrders))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAvvik))->EndInit();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
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
	private: void showOrders(System::Windows::Forms::DataGridView^ siatka) {
		MySqlConnection^ laczBaze = gcnew MySqlConnection(konfiguracja);
		MySqlCommand^ zapytanie = gcnew MySqlCommand("select DISTINCT order_nr from orders;", laczBaze);
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
	private: void showOrder(System::Windows::Forms::DataGridView^ siatka) {
		MySqlConnection^ laczBaze = gcnew MySqlConnection(konfiguracja);
		MySqlCommand^ zapytanie = gcnew MySqlCommand("select flowers.variety, flowers.lenght, orders.boxes, orders.order_nr  from orders, flowers where orders.flowers_id = flowers.fl_id and orders.order_nr = '0011';", laczBaze);
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
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

	}
	private: System::Void dgOrders_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		if (e->RowIndex >= 0) {
			order_nr = Convert::ToString(dgOrders->Rows[e->RowIndex]->Cells[0]->Value);

			MySqlConnection^ laczBaze = gcnew MySqlConnection(konfiguracja);
			MySqlCommand^ zapytanie = gcnew MySqlCommand("select flowers.variety, flowers.lenght, orders.boxes, orders.order_nr  from orders, flowers where orders.flowers_id = flowers.fl_id and orders.order_nr = '" + order_nr + "';", laczBaze);
			MySqlCommand^ zapytanie2 = gcnew MySqlCommand("select flowers.variety, flowers.lenght, orders.boxes, orders.order_nr  from orders, flowers where orders.flowers_id = flowers.fl_id and orders.order_nr = '" + order_nr + "';", laczBaze);

			try
			{
				laczBaze->Open();
				
				MySqlDataAdapter^ moja = gcnew MySqlDataAdapter();
				moja->SelectCommand = zapytanie;
				DataTable^ tabela = gcnew DataTable();
				moja->Fill(tabela);
				BindingSource^ zrodlo = gcnew BindingSource();
				zrodlo->DataSource = tabela;

				MySqlDataAdapter^ moja2 = gcnew MySqlDataAdapter();
				moja2->SelectCommand = zapytanie2;
				DataTable^ tabela2 = gcnew DataTable();
				moja2->Fill(tabela2);
				BindingSource^ zrodlo2 = gcnew BindingSource();
				zrodlo2->DataSource = tabela2;
				
				dgOrder->DataSource = zrodlo;
				dgAvvik->DataSource = zrodlo2;

				
				laczBaze->Close();
			}
			catch (Exception^ komunikat) {
				MessageBox::Show(komunikat->Message);
			}


		}


	}
//////////////////////////////////////////////////////////////
	private: System::Void Program_Load(System::Object^  sender, System::EventArgs^  e) {
	}
/////////////////////////////////////////////////////////////



private: System::Void tabPage2_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void dgMFlowers_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
}
private: System::Void dgOrder_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
}
private: System::Void dgOrders_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
}
private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void dgAvvik_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
}
private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label5_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void tabControl1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void tabPage1_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
