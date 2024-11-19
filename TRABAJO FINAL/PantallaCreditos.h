#pragma once

namespace TRABAJOFINAL {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for PantallaCreditos
	/// </summary>
	public ref class PantallaCreditos : public System::Windows::Forms::Form
	{
	public:
		PantallaCreditos(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			Perfil1 = gcnew Bitmap("perfil1.png");
			Perfil2 = gcnew Bitmap("perfil2.png");
			Perfil3 = gcnew Bitmap("perfil3.png");
			BotonSalir = gcnew Bitmap("BotonSalir.png");
			FondoCreditos = gcnew Bitmap("FondoCreditos.jpeg");
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PantallaCreditos()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ lblTitulo;
	private: System::Windows::Forms::Label^ lblName1;
	private: System::Windows::Forms::Label^ lblName2;
	private: System::Windows::Forms::Label^ lblName3;
	private: System::Windows::Forms::Panel^ pnlPerfil1;
	private: System::Windows::Forms::Panel^ pnlPerfil2;
	private: System::Windows::Forms::Panel^ pnlPerfil3;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		Bitmap^ Perfil1;
		Bitmap^ Perfil2;
		Bitmap^ Perfil3;
	private: System::Windows::Forms::Button^ btnSalir;
		   Bitmap^ FondoCreditos;
		   Bitmap^ BotonSalir;
		   /// <summary>
		   /// Required method for Designer support - do not modify
		   /// the contents of this method with the code editor.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->lblTitulo = (gcnew System::Windows::Forms::Label());
			   this->lblName1 = (gcnew System::Windows::Forms::Label());
			   this->lblName2 = (gcnew System::Windows::Forms::Label());
			   this->lblName3 = (gcnew System::Windows::Forms::Label());
			   this->pnlPerfil1 = (gcnew System::Windows::Forms::Panel());
			   this->pnlPerfil2 = (gcnew System::Windows::Forms::Panel());
			   this->pnlPerfil3 = (gcnew System::Windows::Forms::Panel());
			   this->btnSalir = (gcnew System::Windows::Forms::Button());
			   this->SuspendLayout();
			   // 
			   // lblTitulo
			   // 
			   this->lblTitulo->AutoSize = true;
			   this->lblTitulo->BackColor = System::Drawing::Color::Transparent;
			   this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Century", 49.8F));
			   this->lblTitulo->ForeColor = System::Drawing::Color::White;
			   this->lblTitulo->Location = System::Drawing::Point(74, 97);
			   this->lblTitulo->Name = L"lblTitulo";
			   this->lblTitulo->Size = System::Drawing::Size(367, 100);
			   this->lblTitulo->TabIndex = 0;
			   this->lblTitulo->Text = L"Creditos";
			   // 
			   // lblName1
			   // 
			   this->lblName1->AutoSize = true;
			   this->lblName1->BackColor = System::Drawing::Color::Transparent;
			   this->lblName1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblName1->ForeColor = System::Drawing::Color::White;
			   this->lblName1->Location = System::Drawing::Point(1107, 461);
			   this->lblName1->Name = L"lblName1";
			   this->lblName1->Size = System::Drawing::Size(225, 20);
			   this->lblName1->TabIndex = 1;
			   this->lblName1->Text = L"Alvaro Alberto Neyra Salazar";
			   // 
			   // lblName2
			   // 
			   this->lblName2->AutoSize = true;
			   this->lblName2->BackColor = System::Drawing::Color::Transparent;
			   this->lblName2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblName2->ForeColor = System::Drawing::Color::White;
			   this->lblName2->Location = System::Drawing::Point(140, 461);
			   this->lblName2->Name = L"lblName2";
			   this->lblName2->Size = System::Drawing::Size(219, 20);
			   this->lblName2->TabIndex = 2;
			   this->lblName2->Text = L"Joao David Jimenez Abarca";
			   // 
			   // lblName3
			   // 
			   this->lblName3->AutoSize = true;
			   this->lblName3->BackColor = System::Drawing::Color::Transparent;
			   this->lblName3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblName3->ForeColor = System::Drawing::Color::White;
			   this->lblName3->Location = System::Drawing::Point(1107, 135);
			   this->lblName3->Name = L"lblName3";
			   this->lblName3->Size = System::Drawing::Size(208, 20);
			   this->lblName3->TabIndex = 3;
			   this->lblName3->Text = L"Ivan Leonardo Carrillo Alor";
			   // 
			   // pnlPerfil1
			   // 
			   this->pnlPerfil1->Location = System::Drawing::Point(1148, 531);
			   this->pnlPerfil1->Name = L"pnlPerfil1";
			   this->pnlPerfil1->Size = System::Drawing::Size(150, 100);
			   this->pnlPerfil1->TabIndex = 4;
			   this->pnlPerfil1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &PantallaCreditos::pnlPerfil1_Paint);
			   // 
			   // pnlPerfil2
			   // 
			   this->pnlPerfil2->Location = System::Drawing::Point(168, 531);
			   this->pnlPerfil2->Name = L"pnlPerfil2";
			   this->pnlPerfil2->Size = System::Drawing::Size(150, 100);
			   this->pnlPerfil2->TabIndex = 5;
			   this->pnlPerfil2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &PantallaCreditos::pnlPerfil2_Paint);
			   // 
			   // pnlPerfil3
			   // 
			   this->pnlPerfil3->Location = System::Drawing::Point(1148, 182);
			   this->pnlPerfil3->Name = L"pnlPerfil3";
			   this->pnlPerfil3->Size = System::Drawing::Size(150, 100);
			   this->pnlPerfil3->TabIndex = 6;
			   this->pnlPerfil3->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &PantallaCreditos::pnlPerfil3_Paint);
			   // 
			   // btnSalir
			   // 
			   this->btnSalir->BackColor = System::Drawing::Color::Transparent;
			   this->btnSalir->FlatAppearance->BorderSize = 0;
			   this->btnSalir->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			   this->btnSalir->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			   this->btnSalir->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnSalir->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->btnSalir->Location = System::Drawing::Point(12, 714);
			   this->btnSalir->Name = L"btnSalir";
			   this->btnSalir->Size = System::Drawing::Size(200, 50);
			   this->btnSalir->TabIndex = 1;
			   this->btnSalir->Text = L"S";
			   this->btnSalir->UseVisualStyleBackColor = false;
			   this->btnSalir->Click += gcnew System::EventHandler(this, &PantallaCreditos::btnSalir_Click);
			   this->btnSalir->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &PantallaCreditos::btnSalir_Paint);
			   // 
			   // PantallaCreditos
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1457, 776);
			   this->Controls->Add(this->btnSalir);
			   this->Controls->Add(this->pnlPerfil3);
			   this->Controls->Add(this->pnlPerfil2);
			   this->Controls->Add(this->pnlPerfil1);
			   this->Controls->Add(this->lblName3);
			   this->Controls->Add(this->lblName2);
			   this->Controls->Add(this->lblName1);
			   this->Controls->Add(this->lblTitulo);
			   this->Name = L"PantallaCreditos";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"PantallaCreditos";
			   this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &PantallaCreditos::PantallaCreditos_Paint);
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
		   // Dibujos 
	private: System::Void pnlPerfil1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		if (Perfil1 != nullptr) {
			e->Graphics->DrawImage(Perfil1, 0, 0, pnlPerfil1->ClientSize.Width, pnlPerfil1->ClientSize.Height);
		}
	}
	private: System::Void pnlPerfil2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		if (Perfil2 != nullptr) {
			e->Graphics->DrawImage(Perfil2, 0, 0, pnlPerfil2->ClientSize.Width, pnlPerfil2->ClientSize.Height);
		}
	}
	private: System::Void pnlPerfil3_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		if (Perfil3 != nullptr) {
			e->Graphics->DrawImage(Perfil3, 0, 0, pnlPerfil3->ClientSize.Width, pnlPerfil3->ClientSize.Height);
		}
	}
	private: System::Void btnSalir_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		if (BotonSalir != nullptr) {
			e->Graphics->DrawImage(BotonSalir, 0, 0, btnSalir->Width, btnSalir->Height);
		}
	}
	private: System::Void PantallaCreditos_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		if (FondoCreditos != nullptr) {
			e->Graphics->DrawImage(FondoCreditos, 0, 0, this->ClientSize.Width, this->ClientSize.Height);
		}
		// Clicks xd
	}

	private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	};
}
