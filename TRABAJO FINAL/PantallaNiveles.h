#pragma once

namespace CppCLR_WinFormsProject1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de PantallaNiveles
	/// </summary>
	public ref class PantallaNiveles : public System::Windows::Forms::Form
	{
	public:
		PantallaNiveles(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			BotonSalir = gcnew Bitmap("BotonSalir.png");
			FondoPantallaNiveles = gcnew Bitmap("PantallaNivele.png");
			LogoGuardianOfGaia = gcnew Bitmap("LogoGuardianOfGaia.png");
			this->Paint += gcnew PaintEventHandler(this, &PantallaNiveles::PantallaNiveles_Paint);
			this->Paint += gcnew PaintEventHandler(this, &PantallaNiveles::PantallaNiveles_Paint_1);
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
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
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::Button^ btnNivel1;
	private: System::Windows::Forms::Button^ btnNivel2;
	private: System::Windows::Forms::Button^ btnNivel3;
	private: System::Windows::Forms::Button^ btnNivel4;






#pragma region Windows Form Designer generated code
			Bitmap^ BotonSalir;
			Bitmap^ FondoPantallaNiveles;
	private: System::Windows::Forms::Button^ btnSalir;
			Bitmap^ LogoGuardianOfGaia;

		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnNivel1 = (gcnew System::Windows::Forms::Button());
			this->btnNivel2 = (gcnew System::Windows::Forms::Button());
			this->btnNivel3 = (gcnew System::Windows::Forms::Button());
			this->btnNivel4 = (gcnew System::Windows::Forms::Button());
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnNivel1
			// 
			this->btnNivel1->Location = System::Drawing::Point(179, 181);
			this->btnNivel1->Name = L"btnNivel1";
			this->btnNivel1->Size = System::Drawing::Size(100, 30);
			this->btnNivel1->TabIndex = 0;
			this->btnNivel1->Text = L"Nivel 1";
			this->btnNivel1->UseVisualStyleBackColor = true;
			this->btnNivel1->Click += gcnew System::EventHandler(this, &PantallaNiveles::btnNivel1_Click);
			// 
			// btnNivel2
			// 
			this->btnNivel2->Location = System::Drawing::Point(483, 181);
			this->btnNivel2->Name = L"btnNivel2";
			this->btnNivel2->Size = System::Drawing::Size(100, 30);
			this->btnNivel2->TabIndex = 1;
			this->btnNivel2->Text = L"Nivel 2";
			this->btnNivel2->UseVisualStyleBackColor = true;
			this->btnNivel2->Click += gcnew System::EventHandler(this, &PantallaNiveles::btnNivel2_Click);
			// 
			// btnNivel3
			// 
			this->btnNivel3->Location = System::Drawing::Point(179, 366);
			this->btnNivel3->Name = L"btnNivel3";
			this->btnNivel3->Size = System::Drawing::Size(100, 30);
			this->btnNivel3->TabIndex = 2;
			this->btnNivel3->Text = L"Nivel 3";
			this->btnNivel3->UseVisualStyleBackColor = true;
			this->btnNivel3->Click += gcnew System::EventHandler(this, &PantallaNiveles::btnNivel3_Click);
			// 
			// btnNivel4
			// 
			this->btnNivel4->Location = System::Drawing::Point(483, 366);
			this->btnNivel4->Name = L"btnNivel4";
			this->btnNivel4->Size = System::Drawing::Size(100, 30);
			this->btnNivel4->TabIndex = 3;
			this->btnNivel4->Text = L"Nivel 4";
			this->btnNivel4->UseVisualStyleBackColor = true;
			this->btnNivel4->Click += gcnew System::EventHandler(this, &PantallaNiveles::btnNivel4_Click);
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
			// PantallaNiveles
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1475, 823);
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
		   // Clicks xd

	private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void btnNivel1_Click(System::Object^ sender, System::EventArgs^ e) {
	//
	// pa nivel 1
	//
	}

	private: System::Void btnNivel2_Click(System::Object^ sender, System::EventArgs^ e) {
	//
	// pa nivel 2
	//
	}

	private: System::Void btnNivel3_Click(System::Object^ sender, System::EventArgs^ e) {
	//
	// pa nivel 3
	//
	}

	private: System::Void btnNivel4_Click(System::Object^ sender, System::EventArgs^ e) {
	//
	// pa nivel 4
	//
	}

};
}
