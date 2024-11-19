#pragma once
#include "JuegoForm.h"

namespace TRABAJOFINAL {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for PantallaNiveles
	/// </summary>
	public ref class PantallaNiveles : public System::Windows::Forms::Form
	{
	public:
		PantallaNiveles(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			BotonSalir = gcnew Bitmap("BotonSalir.png");
			BotonNivel1 = gcnew Bitmap("BotonNivel1.png");
			BotonNivel2 = gcnew Bitmap("BotonNivel2.png");
			BotonNivel3 = gcnew Bitmap("BotonNivel3.png");
			BotonNivel4 = gcnew Bitmap("BotonNivel4.png");
			FondoPantallaNiveles = gcnew Bitmap("PantallaNivele.png");
			LogoGuardianOfGaia = gcnew Bitmap("LogoGuardianOfGaia.png");
			juegoForm = gcnew JuegoForm(1);
			this->Paint += gcnew PaintEventHandler(this, &PantallaNiveles::PantallaNiveles_Paint);
			this->Paint += gcnew PaintEventHandler(this, &PantallaNiveles::PantallaNiveles_Paint_1);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PantallaNiveles()
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
		System::ComponentModel::Container^ components;
	private: System::Windows::Forms::Button^ btnNivel1;
	private: System::Windows::Forms::Button^ btnNivel2;
	private: System::Windows::Forms::Button^ btnNivel3;
	private: System::Windows::Forms::Button^ btnNivel4;
#pragma region Windows Form Designer generated code
		   Bitmap^ BotonSalir;
		   Bitmap^ FondoPantallaNiveles;
	private: System::Windows::Forms::Button^ btnSalir;
		   Bitmap^ LogoGuardianOfGaia;
		   JuegoForm^ juegoForm;
		   Bitmap^ BotonNivel1;
		   Bitmap^ BotonNivel2;
		   Bitmap^ BotonNivel3;
		   Bitmap^ BotonNivel4;
	private: System::Windows::Forms::Label^ lblTitulo;

		   /// <summary>
		   /// Required method for Designer support - do not modify
		   /// the contents of this method with the code editor.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->btnNivel1 = (gcnew System::Windows::Forms::Button());
			   this->btnNivel2 = (gcnew System::Windows::Forms::Button());
			   this->btnNivel3 = (gcnew System::Windows::Forms::Button());
			   this->btnNivel4 = (gcnew System::Windows::Forms::Button());
			   this->btnSalir = (gcnew System::Windows::Forms::Button());
			   this->lblTitulo = (gcnew System::Windows::Forms::Label());
			   this->SuspendLayout();
			   // 
			   // btnNivel1
			   // 
			   this->btnNivel1->BackColor = System::Drawing::Color::Transparent;
			   this->btnNivel1->FlatAppearance->BorderSize = 0;
			   this->btnNivel1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			   this->btnNivel1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			   this->btnNivel1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnNivel1->Location = System::Drawing::Point(179, 181);
			   this->btnNivel1->Name = L"btnNivel1";
			   this->btnNivel1->Size = System::Drawing::Size(100, 150);
			   this->btnNivel1->TabIndex = 0;
			   this->btnNivel1->Text = L"Nivel 1";
			   this->btnNivel1->UseVisualStyleBackColor = true;
			   this->btnNivel1->Click += gcnew System::EventHandler(this, &PantallaNiveles::btnNivel1_Click);
			   this->btnNivel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &PantallaNiveles::btnNivel1_Paint);
			   // 
			   // btnNivel2
			   // 
			   this->btnNivel2->BackColor = System::Drawing::Color::Transparent;
			   this->btnNivel2->FlatAppearance->BorderSize = 0;
			   this->btnNivel2->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			   this->btnNivel2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			   this->btnNivel2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnNivel2->Location = System::Drawing::Point(483, 181);
			   this->btnNivel2->Name = L"btnNivel2";
			   this->btnNivel2->Size = System::Drawing::Size(100, 150);
			   this->btnNivel2->TabIndex = 1;
			   this->btnNivel2->Text = L"Nivel 2";
			   this->btnNivel2->UseVisualStyleBackColor = true;
			   this->btnNivel2->Click += gcnew System::EventHandler(this, &PantallaNiveles::btnNivel2_Click);
			   this->btnNivel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &PantallaNiveles::btnNivel2_Paint);
			   // 
			   // btnNivel3
			   // 
			   this->btnNivel3->BackColor = System::Drawing::Color::Transparent;
			   this->btnNivel3->FlatAppearance->BorderSize = 0;
			   this->btnNivel3->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			   this->btnNivel3->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			   this->btnNivel3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnNivel3->Location = System::Drawing::Point(179, 366);
			   this->btnNivel3->Name = L"btnNivel3";
			   this->btnNivel3->Size = System::Drawing::Size(100, 150);
			   this->btnNivel3->TabIndex = 2;
			   this->btnNivel3->Text = L"Nivel 3";
			   this->btnNivel3->UseVisualStyleBackColor = true;
			   this->btnNivel3->Click += gcnew System::EventHandler(this, &PantallaNiveles::btnNivel3_Click);
			   this->btnNivel3->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &PantallaNiveles::btnNivel3_Paint);
			   // 
			   // btnNivel4
			   // 
			   this->btnNivel4->BackColor = System::Drawing::Color::Transparent;
			   this->btnNivel4->FlatAppearance->BorderSize = 0;
			   this->btnNivel4->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			   this->btnNivel4->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			   this->btnNivel4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnNivel4->Location = System::Drawing::Point(483, 366);
			   this->btnNivel4->Name = L"btnNivel4";
			   this->btnNivel4->Size = System::Drawing::Size(100, 150);
			   this->btnNivel4->TabIndex = 3;
			   this->btnNivel4->Text = L"Nivel 4";
			   this->btnNivel4->UseVisualStyleBackColor = true;
			   this->btnNivel4->Click += gcnew System::EventHandler(this, &PantallaNiveles::btnNivel4_Click);
			   this->btnNivel4->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &PantallaNiveles::btnNivel4_Paint);
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
			   this->btnSalir->Location = System::Drawing::Point(3, 725);
			   this->btnSalir->Name = L"btnSalir";
			   this->btnSalir->Size = System::Drawing::Size(200, 50);
			   this->btnSalir->TabIndex = 1;
			   this->btnSalir->Text = L"S";
			   this->btnSalir->UseVisualStyleBackColor = false;
			   this->btnSalir->Click += gcnew System::EventHandler(this, &PantallaNiveles::btnSalir_Click);
			   this->btnSalir->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &PantallaNiveles::btnSalir_Paint);
			   //
			   // lblTitulo
			   //
			   this->lblTitulo->AutoSize = true;
			   this->lblTitulo->BackColor = System::Drawing::Color::Transparent;
			   this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Century", 49.8F));
			   this->lblTitulo->Location = System::Drawing::Point(224, 29);
			   this->lblTitulo->Name = L"lblTitulo";
			   this->lblTitulo->Size = System::Drawing::Size(330, 100);
			   this->lblTitulo->TabIndex = 0;
			   this->lblTitulo->Text = L"Niveles";
			   // 
			   // PantallaNiveles
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1475, 823);
			   this->Controls->Add(this->lblTitulo);
			   this->Controls->Add(this->btnSalir);
			   this->Controls->Add(this->btnNivel4);
			   this->Controls->Add(this->btnNivel3);
			   this->Controls->Add(this->btnNivel2);
			   this->Controls->Add(this->btnNivel1);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			   this->Name = L"PantallaNiveles";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"PantallaNiveles";
			   this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &PantallaNiveles::PantallaNiveles_Paint_1);
			   this->ResumeLayout(false);
		   }
#pragma endregion
		   // Dibbujos Fondo

	private: System::Void PantallaNiveles_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		if (FondoPantallaNiveles != nullptr) {
			e->Graphics->DrawImage(FondoPantallaNiveles, 0, 0, this->ClientSize.Width, this->ClientSize.Height);
		}
	}
	private: System::Void PantallaNiveles_Paint_1(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		if (LogoGuardianOfGaia != nullptr) {
			e->Graphics->DrawImage(LogoGuardianOfGaia, 130, 390, 300, 200);
		}
	}
	private: System::Void btnSalir_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		if (BotonSalir != nullptr) {
			e->Graphics->DrawImage(BotonSalir, 0, 0, btnSalir->Width, btnSalir->Height);
		}
	}
	private: System::Void btnNivel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		if (BotonNivel1 != nullptr) {
			e->Graphics->DrawImage(BotonNivel1, 0, 0, btnNivel1->Width, btnNivel1->Height);
		}
	}
	private: System::Void btnNivel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		if (BotonNivel2 != nullptr) {
			e->Graphics->DrawImage(BotonNivel2, 0, 0, btnNivel2->Width, btnNivel2->Height);
		}
	}
	private: System::Void btnNivel3_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		if (BotonNivel3 != nullptr) {
			e->Graphics->DrawImage(BotonNivel3, 0, 0, btnNivel3->Width, btnNivel3->Height);
		}
	}
	private: System::Void btnNivel4_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		if (BotonNivel4 != nullptr) {
			e->Graphics->DrawImage(BotonNivel4, 0, 0, btnNivel4->Width, btnNivel4->Height);
		}
	}
		   // Clicks xd

	private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void btnNivel1_Click(System::Object^ sender, System::EventArgs^ e) {
		//
		// pa nivel 1
		//
		juegoForm = gcnew JuegoForm(1);
		juegoForm->ShowDialog();
	}
	private: System::Void btnNivel2_Click(System::Object^ sender, System::EventArgs^ e) {
		//
		// pa nivel 2
		//
		juegoForm = gcnew JuegoForm(2);
		juegoForm->ShowDialog();
	}
	private: System::Void btnNivel3_Click(System::Object^ sender, System::EventArgs^ e) {
		//
		// pa nivel 3
		//
		juegoForm = gcnew JuegoForm(3);
		juegoForm->ShowDialog();
	}
	private: System::Void btnNivel4_Click(System::Object^ sender, System::EventArgs^ e) {
		//
		// pa nivel 4
		//
		juegoForm = gcnew JuegoForm(4);
		juegoForm->ShowDialog();
	}
	};
}