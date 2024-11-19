#pragma once
#include "PantallaCreditos.h"
#include "PantallaRanking.h"
#include "PantallaNiveles1.h"
#include "PantallaHistoria1.h"

namespace TRABAJOFINAL {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for InicioForm
	/// </summary>
	public ref class InicioForm : public System::Windows::Forms::Form
	{
	public:
		InicioForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//


			FondoInicio = gcnew Bitmap("FondoInicio.png");
			BotonIniciar = gcnew Bitmap("BotonIniciar.png");
			BotonRanking = gcnew Bitmap("BotonRanking.png");
			BotonCreditos = gcnew Bitmap("BotonCreditos.png");
			BotonSalir = gcnew Bitmap("BotonSalir.png");
			BotonHistoria = gcnew Bitmap("BotonHistoria.png");
			this->Paint += gcnew PaintEventHandler(this, &InicioForm::Form1_Paint);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~InicioForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblTitulo;
	private: System::Windows::Forms::Button^ btnSalir;
	private: System::Windows::Forms::Button^ btnIniciar;
	private: System::Windows::Forms::Button^ btnCreditos;
	private: System::Windows::Forms::Button^ btnHistoria;
	private: System::Windows::Forms::Button^ btnRankig;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		Bitmap^ FondoInicio;
		Bitmap^ BotonIniciar;
		Bitmap^ BotonSalir;
		Bitmap^ BotonCreditos;
		Bitmap^ BotonHistoria;
		Bitmap^ BotonRanking;

		void InitializeComponent(void)
		{
			this->lblTitulo = (gcnew System::Windows::Forms::Label());
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			this->btnIniciar = (gcnew System::Windows::Forms::Button());
			this->btnCreditos = (gcnew System::Windows::Forms::Button());
			this->btnHistoria = (gcnew System::Windows::Forms::Button());
			this->btnRankig = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lblTitulo
			// 
			this->lblTitulo->AutoSize = true;
			this->lblTitulo->BackColor = System::Drawing::Color::Transparent;
			this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 50, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTitulo->ForeColor = System::Drawing::Color::Black;
			this->lblTitulo->Location = System::Drawing::Point(373, 19);
			this->lblTitulo->Name = L"lblTitulo";
			this->lblTitulo->Size = System::Drawing::Size(723, 95);
			this->lblTitulo->TabIndex = 0;
			this->lblTitulo->Text = L"Guardians of Gaia";
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
			this->btnSalir->Click += gcnew System::EventHandler(this, &InicioForm::btnSalir_Click);
			this->btnSalir->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &InicioForm::btnSalir_Paint);
			// 
			// btnIniciar
			// 
			this->btnIniciar->BackColor = System::Drawing::Color::Transparent;
			this->btnIniciar->FlatAppearance->BorderSize = 0;
			this->btnIniciar->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnIniciar->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnIniciar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnIniciar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnIniciar->Location = System::Drawing::Point(389, 625);
			this->btnIniciar->Name = L"btnIniciar";
			this->btnIniciar->Size = System::Drawing::Size(100, 150);
			this->btnIniciar->TabIndex = 2;
			this->btnIniciar->Text = L"I";
			this->btnIniciar->UseVisualStyleBackColor = false;
			this->btnIniciar->Click += gcnew System::EventHandler(this, &InicioForm::btnIniciar_Click);
			this->btnIniciar->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &InicioForm::btnIniciar_Paint);
			// 
			// btnCreditos
			// 
			this->btnCreditos->BackColor = System::Drawing::Color::Transparent;
			this->btnCreditos->FlatAppearance->BorderSize = 0;
			this->btnCreditos->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnCreditos->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnCreditos->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCreditos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCreditos->Location = System::Drawing::Point(853, 625);
			this->btnCreditos->Name = L"btnCreditos";
			this->btnCreditos->Size = System::Drawing::Size(100, 150);
			this->btnCreditos->TabIndex = 3;
			this->btnCreditos->Text = L"C";
			this->btnCreditos->UseVisualStyleBackColor = false;
			this->btnCreditos->Click += gcnew System::EventHandler(this, &InicioForm::btnCreditos_Click);
			this->btnCreditos->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &InicioForm::btnCreditos_Paint);
			// 
			// btnHistoria
			// 
			this->btnHistoria->BackColor = System::Drawing::Color::Transparent;
			this->btnHistoria->FlatAppearance->BorderSize = 0;
			this->btnHistoria->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnHistoria->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnHistoria->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnHistoria->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnHistoria->Location = System::Drawing::Point(552, 625);
			this->btnHistoria->Name = L"btnHistoria";
			this->btnHistoria->Size = System::Drawing::Size(100, 150);
			this->btnHistoria->TabIndex = 4;
			this->btnHistoria->Text = L"H";
			this->btnHistoria->UseVisualStyleBackColor = false;
			this->btnHistoria->Click += gcnew System::EventHandler(this, &InicioForm::btnHistoria_Click);
			this->btnHistoria->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &InicioForm::btnHistoria_Paint);
			// 
			// btnRankig
			// 
			this->btnRankig->BackColor = System::Drawing::Color::Transparent;
			this->btnRankig->FlatAppearance->BorderSize = 0;
			this->btnRankig->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnRankig->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnRankig->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRankig->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRankig->Location = System::Drawing::Point(712, 625);
			this->btnRankig->Name = L"btnRankig";
			this->btnRankig->Size = System::Drawing::Size(100, 150);
			this->btnRankig->TabIndex = 5;
			this->btnRankig->Text = L"R";
			this->btnRankig->UseVisualStyleBackColor = false;
			this->btnRankig->Click += gcnew System::EventHandler(this, &InicioForm::btnRankig_Click);
			this->btnRankig->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &InicioForm::btnRankig_Paint);
			// 
			// InicioForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1475, 823);
			this->Controls->Add(this->lblTitulo);
			this->Controls->Add(this->btnSalir);
			this->Controls->Add(this->btnHistoria);
			this->Controls->Add(this->btnRankig);
			this->Controls->Add(this->btnIniciar);
			this->Controls->Add(this->btnCreditos);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"InicioForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Form1";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &InicioForm::Form1_Paint);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		if (FondoInicio != nullptr) {
			e->Graphics->DrawImage(FondoInicio, 0, 0, this->ClientSize.Width, this->ClientSize.Height);
		}
	}
	private: System::Void btnSalir_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		if (BotonSalir != nullptr) {
			e->Graphics->DrawImage(BotonSalir, 0, 0, btnSalir->Width, btnSalir->Height);
		}
	}
	private: System::Void btnIniciar_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		if (BotonIniciar != nullptr) {
			e->Graphics->DrawImage(BotonIniciar, 0, 0, btnIniciar->Width, btnIniciar->Height);
		}
	}
	private: System::Void btnCreditos_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		if (BotonCreditos != nullptr) {
			e->Graphics->DrawImage(BotonCreditos, 0, 0, btnCreditos->Width, btnCreditos->Height);
		}
	}
	private: System::Void btnHistoria_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		if (BotonHistoria != nullptr) {
			e->Graphics->DrawImage(BotonHistoria, 0, 0, btnHistoria->Width, btnHistoria->Height);
		}
	}
	private: System::Void btnRankig_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		if (BotonRanking != nullptr) {
			e->Graphics->DrawImage(BotonRanking, 0, 0, btnRankig->Width, btnRankig->Height);
		}
	}
		   //
		   // Clicks xd
		   //
	private: System::Void btnIniciar_Click(System::Object^ sender, System::EventArgs^ e) {
		TRABAJOFINAL::PantallaNiveles^ pantallaNiveles = gcnew TRABAJOFINAL::PantallaNiveles();
		pantallaNiveles->Show();
	}
	private: System::Void btnHistoria_Click(System::Object^ sender, System::EventArgs^ e) {
		TRABAJOFINAL::PantallaHistoria^ PantallaHistoria = gcnew TRABAJOFINAL::PantallaHistoria();
		PantallaHistoria->ShowDialog();
	}
	private: System::Void btnCreditos_Click(System::Object^ sender, System::EventArgs^ e) {
		TRABAJOFINAL::PantallaCreditos^ PantallaCreditos = gcnew TRABAJOFINAL::PantallaCreditos();
		PantallaCreditos->ShowDialog();
	}
	private: System::Void btnRankig_Click(System::Object^ sender, System::EventArgs^ e) {
		TRABAJOFINAL::PantallaRanking^ PantallaRanking = gcnew TRABAJOFINAL::PantallaRanking();
		PantallaRanking->ShowDialog();
	}
	private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	};
}
