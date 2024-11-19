#pragma once
#include "Juego.h"

namespace TRABAJOFINAL {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de PantallaGanaste
	/// </summary>
	public ref class PantallaGanaste : public System::Windows::Forms::Form
	{
	public:
		PantallaGanaste(void)
		{
			InitializeComponent();
			juego = new Juego();
			FondoFinal = gcnew Bitmap("FondoFinal.jpg");
			BotonSalir = gcnew Bitmap("BotonSalir.png");
			ImagenGuardianDerrota = gcnew Bitmap("Victoria.png");

			timerPerdiste->Interval = 459;
			timerPerdiste->Tick += gcnew EventHandler(this, &PantallaGanaste::MoverSprite);
			timerPerdiste->Start();

			this->pnlAnimacionVictoria->BackColor = Color::FromArgb(128, Color::Black);

			this->btnSalir->TabStop = false;
			this->btnSalir->BackColor = System::Drawing::Color::Transparent;
			this->btnSalir->FlatAppearance->BorderSize = 0;
			this->btnSalir->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnSalir->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnSalir->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSalir->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
		}

	protected:
		~PantallaGanaste()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::ComponentModel::IContainer^ components;
		Bitmap^ FondoFinal;
		Bitmap^ ImagenGuardianDerrota;
		Bitmap^ BotonSalir;
		Juego* juego;
		int guardianParte = 0;

#pragma region Windows Form Designer generated code

	private: System::Windows::Forms::Panel^ pnlAnimacionVictoria;
	private: System::Windows::Forms::Timer^ timerPerdiste;
	private: System::Windows::Forms::Button^ btnSalir;
	private: System::Windows::Forms::Panel^ pnlEstadisticasFinal;
	private: System::Windows::Forms::Label^ lblEnemigoTotalDerrotado;
	private: System::Windows::Forms::Label^ lblEnemigoAireDerrotados;
	private: System::Windows::Forms::Label^ lblEnemigoTierraDerrotados;
	private: System::Windows::Forms::Label^ lblEnemigoFuegoDerrotado;
	private: System::Windows::Forms::Label^ lblRecursosTotalRecogidos;
	private: System::Windows::Forms::Label^ lblAguaTotalrecogida;
	private: System::Windows::Forms::Label^ lblPapelTotalRecogido;
	private: System::Windows::Forms::Label^ lblSemillasTotalRecogidas;
	private: System::Windows::Forms::Label^ lblNivelMaximoAlcanzado;

	private: System::Windows::Forms::Label^ lblEnemigosTotalDerrotadosNumero;
	private: System::Windows::Forms::Label^ lblEnemigoAireDerrotadosNumero;
	private: System::Windows::Forms::Label^ lblEnemigoTierraDerrotadoNumero;
	private: System::Windows::Forms::Label^ lblEnemigoFuegoDerrotadoNumero;
	private: System::Windows::Forms::Label^ lblRecursoTotalRecogidoNumero;
	private: System::Windows::Forms::Label^ lblAguaTotalRecogidoNumero;
	private: System::Windows::Forms::Label^ lblPapelTotalRecogidoNumero;
	private: System::Windows::Forms::Label^ lblSemillasTotalRecogidasNumero;
	private: System::Windows::Forms::Label^ lblNivelMaximoAlcanzadoNumero;


		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   this->pnlAnimacionVictoria = (gcnew System::Windows::Forms::Panel());
			   this->timerPerdiste = (gcnew System::Windows::Forms::Timer(this->components));
			   this->btnSalir = (gcnew System::Windows::Forms::Button());
			   this->pnlEstadisticasFinal = (gcnew System::Windows::Forms::Panel());
			   this->lblEnemigoTotalDerrotado = (gcnew System::Windows::Forms::Label());
			   this->lblEnemigoAireDerrotados = (gcnew System::Windows::Forms::Label());
			   this->lblPapelTotalRecogido = (gcnew System::Windows::Forms::Label());
			   this->lblAguaTotalRecogidoNumero = (gcnew System::Windows::Forms::Label());
			   this->lblRecursoTotalRecogidoNumero = (gcnew System::Windows::Forms::Label());
			   this->lblEnemigoFuegoDerrotadoNumero = (gcnew System::Windows::Forms::Label());
			   this->lblAguaTotalrecogida = (gcnew System::Windows::Forms::Label());
			   this->lblSemillasTotalRecogidas = (gcnew System::Windows::Forms::Label());
			   this->lblNivelMaximoAlcanzadoNumero = (gcnew System::Windows::Forms::Label());
			   this->lblRecursosTotalRecogidos = (gcnew System::Windows::Forms::Label());
			   this->lblEnemigoTierraDerrotados = (gcnew System::Windows::Forms::Label());
			   this->lblEnemigoTierraDerrotadoNumero = (gcnew System::Windows::Forms::Label());
			   this->lblEnemigosTotalDerrotadosNumero = (gcnew System::Windows::Forms::Label());
			   this->lblPapelTotalRecogidoNumero = (gcnew System::Windows::Forms::Label());
			   this->lblSemillasTotalRecogidasNumero = (gcnew System::Windows::Forms::Label());
			   this->lblNivelMaximoAlcanzado = (gcnew System::Windows::Forms::Label());
			   this->lblEnemigoAireDerrotadosNumero = (gcnew System::Windows::Forms::Label());
			   this->lblEnemigoFuegoDerrotado = (gcnew System::Windows::Forms::Label());
			   this->pnlEstadisticasFinal->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // pnlAnimacionVictoria
			   // 
			   this->pnlAnimacionVictoria->Location = System::Drawing::Point(146, 369);
			   this->pnlAnimacionVictoria->Name = L"pnlAnimacionVictoria";
			   this->pnlAnimacionVictoria->Size = System::Drawing::Size(162, 193);
			   this->pnlAnimacionVictoria->TabIndex = 0;
			   this->pnlAnimacionVictoria->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &PantallaGanaste::pnlAnimacionVictoria_Paint);
			   // 
			   // btnSalir
			   // 
			   this->btnSalir->Location = System::Drawing::Point(349, 591);
			   this->btnSalir->Name = L"btnSalir";
			   this->btnSalir->Size = System::Drawing::Size(139, 47);
			   this->btnSalir->TabIndex = 1;
			   this->btnSalir->Text = L"s";
			   this->btnSalir->UseVisualStyleBackColor = true;
			   this->btnSalir->Click += gcnew System::EventHandler(this, &PantallaGanaste::btnSalir_Click);
			   this->btnSalir->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &PantallaGanaste::btnSalir_Paint);
			   // 
			   // pnlEstadisticasFinal
			   // 
			   this->pnlEstadisticasFinal->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)),
				   static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			   this->pnlEstadisticasFinal->Controls->Add(this->lblEnemigoTotalDerrotado);
			   this->pnlEstadisticasFinal->Controls->Add(this->lblEnemigoAireDerrotados);
			   this->pnlEstadisticasFinal->Controls->Add(this->lblPapelTotalRecogido);
			   this->pnlEstadisticasFinal->Controls->Add(this->lblAguaTotalRecogidoNumero);
			   this->pnlEstadisticasFinal->Controls->Add(this->lblRecursoTotalRecogidoNumero);
			   this->pnlEstadisticasFinal->Controls->Add(this->lblEnemigoFuegoDerrotadoNumero);
			   this->pnlEstadisticasFinal->Controls->Add(this->lblAguaTotalrecogida);
			   this->pnlEstadisticasFinal->Controls->Add(this->lblSemillasTotalRecogidas);
			   this->pnlEstadisticasFinal->Controls->Add(this->lblNivelMaximoAlcanzadoNumero);
			   this->pnlEstadisticasFinal->Controls->Add(this->lblRecursosTotalRecogidos);
			   this->pnlEstadisticasFinal->Controls->Add(this->lblEnemigoTierraDerrotados);
			   this->pnlEstadisticasFinal->Controls->Add(this->lblEnemigoTierraDerrotadoNumero);
			   this->pnlEstadisticasFinal->Controls->Add(this->lblEnemigosTotalDerrotadosNumero);
			   this->pnlEstadisticasFinal->Controls->Add(this->lblPapelTotalRecogidoNumero);
			   this->pnlEstadisticasFinal->Controls->Add(this->lblSemillasTotalRecogidasNumero);
			   this->pnlEstadisticasFinal->Controls->Add(this->lblNivelMaximoAlcanzado);
			   this->pnlEstadisticasFinal->Controls->Add(this->lblEnemigoAireDerrotadosNumero);
			   this->pnlEstadisticasFinal->Controls->Add(this->lblEnemigoFuegoDerrotado);
			   this->pnlEstadisticasFinal->Location = System::Drawing::Point(54, 44);
			   this->pnlEstadisticasFinal->Name = L"pnlEstadisticasFinal";
			   this->pnlEstadisticasFinal->Size = System::Drawing::Size(393, 280);
			   this->pnlEstadisticasFinal->TabIndex = 2;
			   // 
			   // lblEnemigoTotalDerrotado
			   // 
			   this->lblEnemigoTotalDerrotado->AutoSize = true;
			   this->lblEnemigoTotalDerrotado->BackColor = System::Drawing::Color::Transparent;
			   this->lblEnemigoTotalDerrotado->ForeColor = System::Drawing::Color::White;
			   this->lblEnemigoTotalDerrotado->Location = System::Drawing::Point(30, 27);
			   this->lblEnemigoTotalDerrotado->Name = L"lblEnemigoTotalDerrotado";
			   this->lblEnemigoTotalDerrotado->Size = System::Drawing::Size(172, 16);
			   this->lblEnemigoTotalDerrotado->TabIndex = 2;
			   this->lblEnemigoTotalDerrotado->Text = L"Enemigo Total Derrotados: ";
			   // 
			   // lblEnemigoAireDerrotados
			   // 
			   this->lblEnemigoAireDerrotados->AutoSize = true;
			   this->lblEnemigoAireDerrotados->BackColor = System::Drawing::Color::Transparent;
			   this->lblEnemigoAireDerrotados->ForeColor = System::Drawing::Color::White;
			   this->lblEnemigoAireDerrotados->Location = System::Drawing::Point(30, 52);
			   this->lblEnemigoAireDerrotados->Name = L"lblEnemigoAireDerrotados";
			   this->lblEnemigoAireDerrotados->Size = System::Drawing::Size(165, 16);
			   this->lblEnemigoAireDerrotados->TabIndex = 3;
			   this->lblEnemigoAireDerrotados->Text = L"Enemigo Aire Derrotados: ";
			   // 
			   // lblPapelTotalRecogido
			   // 
			   this->lblPapelTotalRecogido->AutoSize = true;
			   this->lblPapelTotalRecogido->BackColor = System::Drawing::Color::Transparent;
			   this->lblPapelTotalRecogido->ForeColor = System::Drawing::Color::White;
			   this->lblPapelTotalRecogido->Location = System::Drawing::Point(30, 177);
			   this->lblPapelTotalRecogido->Name = L"lblPapelTotalRecogido";
			   this->lblPapelTotalRecogido->Size = System::Drawing::Size(190, 16);
			   this->lblPapelTotalRecogido->TabIndex = 8;
			   this->lblPapelTotalRecogido->Text = L"Residuos Totales Recogidos: ";
			   // 
			   // lblAguaTotalRecogidoNumero
			   // 
			   this->lblAguaTotalRecogidoNumero->AutoSize = true;
			   this->lblAguaTotalRecogidoNumero->BackColor = System::Drawing::Color::Transparent;
			   this->lblAguaTotalRecogidoNumero->ForeColor = System::Drawing::Color::White;
			   this->lblAguaTotalRecogidoNumero->Location = System::Drawing::Point(295, 152);
			   this->lblAguaTotalRecogidoNumero->Name = L"lblAguaTotalRecogidoNumero";
			   this->lblAguaTotalRecogidoNumero->Size = System::Drawing::Size(14, 16);
			   this->lblAguaTotalRecogidoNumero->TabIndex = 16;
			   this->lblAguaTotalRecogidoNumero->Text = L"0";
			   // 
			   // lblRecursoTotalRecogidoNumero
			   // 
			   this->lblRecursoTotalRecogidoNumero->AutoSize = true;
			   this->lblRecursoTotalRecogidoNumero->BackColor = System::Drawing::Color::Transparent;
			   this->lblRecursoTotalRecogidoNumero->ForeColor = System::Drawing::Color::White;
			   this->lblRecursoTotalRecogidoNumero->Location = System::Drawing::Point(295, 127);
			   this->lblRecursoTotalRecogidoNumero->Name = L"lblRecursoTotalRecogidoNumero";
			   this->lblRecursoTotalRecogidoNumero->Size = System::Drawing::Size(14, 16);
			   this->lblRecursoTotalRecogidoNumero->TabIndex = 15;
			   this->lblRecursoTotalRecogidoNumero->Text = L"0";
			   // 
			   // lblEnemigoFuegoDerrotadoNumero
			   // 
			   this->lblEnemigoFuegoDerrotadoNumero->AutoSize = true;
			   this->lblEnemigoFuegoDerrotadoNumero->BackColor = System::Drawing::Color::Transparent;
			   this->lblEnemigoFuegoDerrotadoNumero->ForeColor = System::Drawing::Color::White;
			   this->lblEnemigoFuegoDerrotadoNumero->Location = System::Drawing::Point(295, 102);
			   this->lblEnemigoFuegoDerrotadoNumero->Name = L"lblEnemigoFuegoDerrotadoNumero";
			   this->lblEnemigoFuegoDerrotadoNumero->Size = System::Drawing::Size(14, 16);
			   this->lblEnemigoFuegoDerrotadoNumero->TabIndex = 14;
			   this->lblEnemigoFuegoDerrotadoNumero->Text = L"0";
			   // 
			   // lblAguaTotalrecogida
			   // 
			   this->lblAguaTotalrecogida->AutoSize = true;
			   this->lblAguaTotalrecogida->BackColor = System::Drawing::Color::Transparent;
			   this->lblAguaTotalrecogida->ForeColor = System::Drawing::Color::White;
			   this->lblAguaTotalrecogida->Location = System::Drawing::Point(30, 152);
			   this->lblAguaTotalrecogida->Name = L"lblAguaTotalrecogida";
			   this->lblAguaTotalrecogida->Size = System::Drawing::Size(142, 16);
			   this->lblAguaTotalrecogida->TabIndex = 7;
			   this->lblAguaTotalrecogida->Text = L"Agua Total Recogida: ";
			   // 
			   // lblSemillasTotalRecogidas
			   // 
			   this->lblSemillasTotalRecogidas->AutoSize = true;
			   this->lblSemillasTotalRecogidas->BackColor = System::Drawing::Color::Transparent;
			   this->lblSemillasTotalRecogidas->ForeColor = System::Drawing::Color::White;
			   this->lblSemillasTotalRecogidas->Location = System::Drawing::Point(30, 202);
			   this->lblSemillasTotalRecogidas->Name = L"lblSemillasTotalRecogidas";
			   this->lblSemillasTotalRecogidas->Size = System::Drawing::Size(169, 16);
			   this->lblSemillasTotalRecogidas->TabIndex = 9;
			   this->lblSemillasTotalRecogidas->Text = L"Semillas Total Recogidas: ";
			   // 
			   // lblNivelMaximoAlcanzadoNumero
			   // 
			   this->lblNivelMaximoAlcanzadoNumero->AutoSize = true;
			   this->lblNivelMaximoAlcanzadoNumero->BackColor = System::Drawing::Color::Transparent;
			   this->lblNivelMaximoAlcanzadoNumero->ForeColor = System::Drawing::Color::White;
			   this->lblNivelMaximoAlcanzadoNumero->Location = System::Drawing::Point(295, 227);
			   this->lblNivelMaximoAlcanzadoNumero->Name = L"lblNivelMaximoAlcanzadoNumero";
			   this->lblNivelMaximoAlcanzadoNumero->Size = System::Drawing::Size(14, 16);
			   this->lblNivelMaximoAlcanzadoNumero->TabIndex = 19;
			   this->lblNivelMaximoAlcanzadoNumero->Text = L"0";
			   // 
			   // lblRecursosTotalRecogidos
			   // 
			   this->lblRecursosTotalRecogidos->AutoSize = true;
			   this->lblRecursosTotalRecogidos->BackColor = System::Drawing::Color::Transparent;
			   this->lblRecursosTotalRecogidos->ForeColor = System::Drawing::Color::White;
			   this->lblRecursosTotalRecogidos->Location = System::Drawing::Point(30, 127);
			   this->lblRecursosTotalRecogidos->Name = L"lblRecursosTotalRecogidos";
			   this->lblRecursosTotalRecogidos->Size = System::Drawing::Size(168, 16);
			   this->lblRecursosTotalRecogidos->TabIndex = 6;
			   this->lblRecursosTotalRecogidos->Text = L"Recurso Total Recogidos: ";
			   // 
			   // lblEnemigoTierraDerrotados
			   // 
			   this->lblEnemigoTierraDerrotados->AutoSize = true;
			   this->lblEnemigoTierraDerrotados->BackColor = System::Drawing::Color::Transparent;
			   this->lblEnemigoTierraDerrotados->ForeColor = System::Drawing::Color::White;
			   this->lblEnemigoTierraDerrotados->Location = System::Drawing::Point(30, 77);
			   this->lblEnemigoTierraDerrotados->Name = L"lblEnemigoTierraDerrotados";
			   this->lblEnemigoTierraDerrotados->Size = System::Drawing::Size(177, 16);
			   this->lblEnemigoTierraDerrotados->TabIndex = 4;
			   this->lblEnemigoTierraDerrotados->Text = L"Enemigo Tierra Derrotados: ";
			   // 
			   // lblEnemigoTierraDerrotadoNumero
			   // 
			   this->lblEnemigoTierraDerrotadoNumero->AutoSize = true;
			   this->lblEnemigoTierraDerrotadoNumero->BackColor = System::Drawing::Color::Transparent;
			   this->lblEnemigoTierraDerrotadoNumero->ForeColor = System::Drawing::Color::White;
			   this->lblEnemigoTierraDerrotadoNumero->Location = System::Drawing::Point(295, 77);
			   this->lblEnemigoTierraDerrotadoNumero->Name = L"lblEnemigoTierraDerrotadoNumero";
			   this->lblEnemigoTierraDerrotadoNumero->Size = System::Drawing::Size(14, 16);
			   this->lblEnemigoTierraDerrotadoNumero->TabIndex = 13;
			   this->lblEnemigoTierraDerrotadoNumero->Text = L"0";
			   // 
			   // lblEnemigosTotalDerrotadosNumero
			   // 
			   this->lblEnemigosTotalDerrotadosNumero->AutoSize = true;
			   this->lblEnemigosTotalDerrotadosNumero->BackColor = System::Drawing::Color::Transparent;
			   this->lblEnemigosTotalDerrotadosNumero->ForeColor = System::Drawing::Color::White;
			   this->lblEnemigosTotalDerrotadosNumero->Location = System::Drawing::Point(295, 27);
			   this->lblEnemigosTotalDerrotadosNumero->Name = L"lblEnemigosTotalDerrotadosNumero";
			   this->lblEnemigosTotalDerrotadosNumero->Size = System::Drawing::Size(14, 16);
			   this->lblEnemigosTotalDerrotadosNumero->TabIndex = 11;
			   this->lblEnemigosTotalDerrotadosNumero->Text = L"0";
			   // 
			   // lblPapelTotalRecogidoNumero
			   // 
			   this->lblPapelTotalRecogidoNumero->AutoSize = true;
			   this->lblPapelTotalRecogidoNumero->BackColor = System::Drawing::Color::Transparent;
			   this->lblPapelTotalRecogidoNumero->ForeColor = System::Drawing::Color::White;
			   this->lblPapelTotalRecogidoNumero->Location = System::Drawing::Point(295, 177);
			   this->lblPapelTotalRecogidoNumero->Name = L"lblPapelTotalRecogidoNumero";
			   this->lblPapelTotalRecogidoNumero->Size = System::Drawing::Size(14, 16);
			   this->lblPapelTotalRecogidoNumero->TabIndex = 17;
			   this->lblPapelTotalRecogidoNumero->Text = L"0";
			   // 
			   // lblSemillasTotalRecogidasNumero
			   // 
			   this->lblSemillasTotalRecogidasNumero->AutoSize = true;
			   this->lblSemillasTotalRecogidasNumero->BackColor = System::Drawing::Color::Transparent;
			   this->lblSemillasTotalRecogidasNumero->ForeColor = System::Drawing::Color::White;
			   this->lblSemillasTotalRecogidasNumero->Location = System::Drawing::Point(295, 202);
			   this->lblSemillasTotalRecogidasNumero->Name = L"lblSemillasTotalRecogidasNumero";
			   this->lblSemillasTotalRecogidasNumero->Size = System::Drawing::Size(14, 16);
			   this->lblSemillasTotalRecogidasNumero->TabIndex = 18;
			   this->lblSemillasTotalRecogidasNumero->Text = L"0";
			   // 
			   // lblNivelMaximoAlcanzado
			   // 
			   this->lblNivelMaximoAlcanzado->AutoSize = true;
			   this->lblNivelMaximoAlcanzado->BackColor = System::Drawing::Color::Transparent;
			   this->lblNivelMaximoAlcanzado->ForeColor = System::Drawing::Color::White;
			   this->lblNivelMaximoAlcanzado->Location = System::Drawing::Point(30, 227);
			   this->lblNivelMaximoAlcanzado->Name = L"lblNivelMaximoAlcanzado";
			   this->lblNivelMaximoAlcanzado->Size = System::Drawing::Size(149, 16);
			   this->lblNivelMaximoAlcanzado->TabIndex = 10;
			   this->lblNivelMaximoAlcanzado->Text = L"Nivel Ultimo Alcanzado:";
			   // 
			   // lblEnemigoAireDerrotadosNumero
			   // 
			   this->lblEnemigoAireDerrotadosNumero->AutoSize = true;
			   this->lblEnemigoAireDerrotadosNumero->BackColor = System::Drawing::Color::Transparent;
			   this->lblEnemigoAireDerrotadosNumero->ForeColor = System::Drawing::Color::White;
			   this->lblEnemigoAireDerrotadosNumero->Location = System::Drawing::Point(295, 52);
			   this->lblEnemigoAireDerrotadosNumero->Name = L"lblEnemigoAireDerrotadosNumero";
			   this->lblEnemigoAireDerrotadosNumero->Size = System::Drawing::Size(14, 16);
			   this->lblEnemigoAireDerrotadosNumero->TabIndex = 12;
			   this->lblEnemigoAireDerrotadosNumero->Text = L"0";
			   // 
			   // lblEnemigoFuegoDerrotado
			   // 
			   this->lblEnemigoFuegoDerrotado->AutoSize = true;
			   this->lblEnemigoFuegoDerrotado->BackColor = System::Drawing::Color::Transparent;
			   this->lblEnemigoFuegoDerrotado->ForeColor = System::Drawing::Color::White;
			   this->lblEnemigoFuegoDerrotado->Location = System::Drawing::Point(30, 102);
			   this->lblEnemigoFuegoDerrotado->Name = L"lblEnemigoFuegoDerrotado";
			   this->lblEnemigoFuegoDerrotado->Size = System::Drawing::Size(180, 16);
			   this->lblEnemigoFuegoDerrotado->TabIndex = 5;
			   this->lblEnemigoFuegoDerrotado->Text = L"Enemigo Fuego Derrotados: ";
			   // 
			   // PantallaGanaste
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(500, 650);
			   this->Controls->Add(this->pnlEstadisticasFinal);
			   this->Controls->Add(this->btnSalir);
			   this->Controls->Add(this->pnlAnimacionVictoria);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			   this->Name = L"PantallaGanaste";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"PantallaVictoria";
			   this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &PantallaGanaste::PantallaGanaste_FormClosing);
			   this->Load += gcnew System::EventHandler(this, &PantallaGanaste::PantallaGanaste_Load);
			   this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &PantallaGanaste::PantallaVictoria_Paint);
			   this->pnlEstadisticasFinal->ResumeLayout(false);
			   this->pnlEstadisticasFinal->PerformLayout();
			   this->ResumeLayout(false);

		   }
#pragma endregion

	private:System::Void PantallaVictoria_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		if (FondoFinal != nullptr) {
			e->Graphics->DrawImage(FondoFinal, 0, 0, this->ClientSize.Width, this->ClientSize.Height);
		}
	}
	private:System::Void btnSalir_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		if (BotonSalir != nullptr) {
			e->Graphics->DrawImage(BotonSalir, 0, 0, btnSalir->Width, btnSalir->Height);
		}
	}
	private:System::Void pnlAnimacionVictoria_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		if (ImagenGuardianDerrota != nullptr) {
			int ancho = ImagenGuardianDerrota->Width / 7;
			int alto = ImagenGuardianDerrota->Height;

			Rectangle sPGuardian = Rectangle(guardianParte * ancho, 0, ancho, alto);

			Rectangle pIGuardian = Rectangle(0, 0, pnlAnimacionVictoria->Width, pnlAnimacionVictoria->Height);

			e->Graphics->DrawImage(ImagenGuardianDerrota, pIGuardian, sPGuardian, GraphicsUnit::Pixel);
		}
	}

	private:System::Void MoverSprite(System::Object^ sender, System::EventArgs^ e) {
		guardianParte = (guardianParte + 1) % 7;

		pnlAnimacionVictoria->Invalidate();
	}

	private:System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	private: System::Void PantallaGanaste_Load(System::Object^ sender, System::EventArgs^ e) {
		this->pnlAnimacionVictoria->Select();

		juego->cargarPuntaje();

		lblEnemigosTotalDerrotadosNumero->Text = juego->obtenerEnemigosDerrotados().ToString();
		lblEnemigoAireDerrotadosNumero->Text = juego->obtenerEnemigoAireDerrotados().ToString();
		lblEnemigoTierraDerrotadoNumero->Text = juego->obtenerEnemigoTierraDerrotados().ToString();
		lblEnemigoFuegoDerrotadoNumero->Text = juego->obtenerEnemigoFuegoDerrotados().ToString();
		lblRecursoTotalRecogidoNumero->Text = juego->obtenerRecursosRecolectados().ToString();
		lblAguaTotalRecogidoNumero->Text = juego->obtenerAguaTotalRecogida().ToString();
		lblPapelTotalRecogidoNumero->Text = juego->obtenerPapelTotalRecogida().ToString();
		lblSemillasTotalRecogidasNumero->Text = juego->obtenerSemillasTotalRecogida().ToString();
		lblNivelMaximoAlcanzadoNumero->Text = juego->obtenerNivelUltimoAlcanzado().ToString();
	}
private: System::Void PantallaGanaste_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	if (timerPerdiste != nullptr) {
		timerPerdiste->Stop();
		delete timerPerdiste;
		timerPerdiste = nullptr;
	}

	if (FondoFinal != nullptr) delete FondoFinal;
	if (BotonSalir != nullptr) delete BotonSalir;
	if (ImagenGuardianDerrota != nullptr) delete ImagenGuardianDerrota;
}
};
}
