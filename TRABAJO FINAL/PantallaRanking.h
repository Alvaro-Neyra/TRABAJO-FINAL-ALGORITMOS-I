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
	/// Resumen de PantallaRanking
	/// </summary>
	public ref class PantallaRanking : public System::Windows::Forms::Form
	{
	public:
		PantallaRanking(void)
		{
			InitializeComponent();
			//
			//TODO: agregar c�digo de constructor aqu�
			//
			juego = new Juego();
			FondoRanking = gcnew Bitmap("FondoRanking.jpeg");
			BotonSalir = gcnew Bitmap("BotonSalir.png");
			SoldadoRanking = gcnew Bitmap("SoldadoRanking.png");
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~PantallaRanking()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;
	private: System::Windows::Forms::Button^ btnSalir;

#pragma region Windows Form Designer generated code

	private: System::Windows::Forms::Label^ lblTitulo;
	private: System::Windows::Forms::Label^ lblEnemigoTotalDerrotado;
	private: System::Windows::Forms::Label^ lblEnemigoAireDerrotados;
	private: System::Windows::Forms::Label^ lblEnemigoTierraDerrotados;
	private: System::Windows::Forms::Label^ lblEnemigoFuegoDerrotado;
	private: System::Windows::Forms::Label^ lblRecursosTotalRecogidos;
	private: System::Windows::Forms::Label^ lblAguaTotalrecogida;
	private: System::Windows::Forms::Label^ lblPapelTotalRecogido;
	private: System::Windows::Forms::Label^ lblSemillasTotalRecogidas;
	private: System::Windows::Forms::Label^ lblNivelUltimoAlcanzado;

	private: System::Windows::Forms::Label^ lblEnemigosTotalDerrotadosNumero;
	private: System::Windows::Forms::Label^ lblEnemigoAireDerrotadosNumero;
	private: System::Windows::Forms::Label^ lblEnemigoTierraDerrotadoNumero;
	private: System::Windows::Forms::Label^ lblEnemigoFuegoDerrotadoNumero;
	private: System::Windows::Forms::Label^ lblRecursoTotalRecogidoNumero;
	private: System::Windows::Forms::Label^ lblAguaTotalRecogidoNumero;
	private: System::Windows::Forms::Label^ lblPapelTotalRecogidoNumero;
	private: System::Windows::Forms::Label^ lblSemillasTotalRecogidasNumero;
	private: System::Windows::Forms::Label^ lblNivelMaximoAlcanzadoNumero;

	private: System::Windows::Forms::Panel^ pnlRanking;
	private: System::Windows::Forms::Panel^ pnlSoldadoRanking;






		   Juego* juego;
		   Bitmap^ FondoRanking;
		   Bitmap^ SoldadoRanking;
		   Bitmap^ BotonSalir;

		   /// <summary>
		   /// M�todo necesario para admitir el Dise�ador. No se puede modificar
		   /// el contenido de este m�todo con el editor de c�digo.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->btnSalir = (gcnew System::Windows::Forms::Button());
			   this->lblTitulo = (gcnew System::Windows::Forms::Label());
			   this->lblEnemigoTotalDerrotado = (gcnew System::Windows::Forms::Label());
			   this->lblEnemigoAireDerrotados = (gcnew System::Windows::Forms::Label());
			   this->lblEnemigoTierraDerrotados = (gcnew System::Windows::Forms::Label());
			   this->lblEnemigoFuegoDerrotado = (gcnew System::Windows::Forms::Label());
			   this->lblRecursosTotalRecogidos = (gcnew System::Windows::Forms::Label());
			   this->lblAguaTotalrecogida = (gcnew System::Windows::Forms::Label());
			   this->lblPapelTotalRecogido = (gcnew System::Windows::Forms::Label());
			   this->lblSemillasTotalRecogidas = (gcnew System::Windows::Forms::Label());
			   this->lblNivelUltimoAlcanzado = (gcnew System::Windows::Forms::Label());
			   this->lblEnemigosTotalDerrotadosNumero = (gcnew System::Windows::Forms::Label());
			   this->lblEnemigoAireDerrotadosNumero = (gcnew System::Windows::Forms::Label());
			   this->lblEnemigoTierraDerrotadoNumero = (gcnew System::Windows::Forms::Label());
			   this->lblEnemigoFuegoDerrotadoNumero = (gcnew System::Windows::Forms::Label());
			   this->lblRecursoTotalRecogidoNumero = (gcnew System::Windows::Forms::Label());
			   this->lblAguaTotalRecogidoNumero = (gcnew System::Windows::Forms::Label());
			   this->lblPapelTotalRecogidoNumero = (gcnew System::Windows::Forms::Label());
			   this->lblSemillasTotalRecogidasNumero = (gcnew System::Windows::Forms::Label());
			   this->lblNivelMaximoAlcanzadoNumero = (gcnew System::Windows::Forms::Label());
			   this->pnlRanking = (gcnew System::Windows::Forms::Panel());
			   this->pnlSoldadoRanking = (gcnew System::Windows::Forms::Panel());
			   this->pnlRanking->SuspendLayout();
			   this->SuspendLayout();
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
			   this->btnSalir->Click += gcnew System::EventHandler(this, &PantallaRanking::btnSalir_Click);
			   this->btnSalir->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &PantallaRanking::btnSalir_Paint);
			   // 
			   // lblTitulo
			   // 
			   this->lblTitulo->AutoSize = true;
			   this->lblTitulo->BackColor = System::Drawing::Color::Transparent;
			   this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Century", 49.8F));
			   this->lblTitulo->ForeColor = System::Drawing::Color::White;
			   this->lblTitulo->Location = System::Drawing::Point(498, 34);
			   this->lblTitulo->Name = L"lblTitulo";
			   this->lblTitulo->Size = System::Drawing::Size(370, 100);
			   this->lblTitulo->TabIndex = 0;
			   this->lblTitulo->Text = L"Ranking";
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
			   // lblNivelUltimoAlcanzado
			   // 
			   this->lblNivelUltimoAlcanzado->AutoSize = true;
			   this->lblNivelUltimoAlcanzado->BackColor = System::Drawing::Color::Transparent;
			   this->lblNivelUltimoAlcanzado->ForeColor = System::Drawing::Color::White;
			   this->lblNivelUltimoAlcanzado->Location = System::Drawing::Point(30, 227);
			   this->lblNivelUltimoAlcanzado->Name = L"lblNivelUltimoAlcanzado";
			   this->lblNivelUltimoAlcanzado->Size = System::Drawing::Size(146, 16);
			   this->lblNivelUltimoAlcanzado->TabIndex = 10;
			   this->lblNivelUltimoAlcanzado->Text = L"Nivel Ultimo Alcanzado";
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
			   // pnlRanking
			   // 
			   this->pnlRanking->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				   static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			   this->pnlRanking->Controls->Add(this->lblEnemigoTotalDerrotado);
			   this->pnlRanking->Controls->Add(this->lblEnemigoAireDerrotados);
			   this->pnlRanking->Controls->Add(this->lblPapelTotalRecogido);
			   this->pnlRanking->Controls->Add(this->lblAguaTotalRecogidoNumero);
			   this->pnlRanking->Controls->Add(this->lblRecursoTotalRecogidoNumero);
			   this->pnlRanking->Controls->Add(this->lblEnemigoFuegoDerrotadoNumero);
			   this->pnlRanking->Controls->Add(this->lblAguaTotalrecogida);
			   this->pnlRanking->Controls->Add(this->lblSemillasTotalRecogidas);
			   this->pnlRanking->Controls->Add(this->lblNivelMaximoAlcanzadoNumero);
			   this->pnlRanking->Controls->Add(this->lblRecursosTotalRecogidos);
			   this->pnlRanking->Controls->Add(this->lblEnemigoTierraDerrotados);
			   this->pnlRanking->Controls->Add(this->lblEnemigoTierraDerrotadoNumero);
			   this->pnlRanking->Controls->Add(this->lblEnemigosTotalDerrotadosNumero);
			   this->pnlRanking->Controls->Add(this->lblPapelTotalRecogidoNumero);
			   this->pnlRanking->Controls->Add(this->lblSemillasTotalRecogidasNumero);
			   this->pnlRanking->Controls->Add(this->lblNivelUltimoAlcanzado);
			   this->pnlRanking->Controls->Add(this->lblEnemigoAireDerrotadosNumero);
			   this->pnlRanking->Controls->Add(this->lblEnemigoFuegoDerrotado);
			   this->pnlRanking->Location = System::Drawing::Point(823, 269);
			   this->pnlRanking->Name = L"pnlRanking";
			   this->pnlRanking->Size = System::Drawing::Size(335, 271);
			   this->pnlRanking->TabIndex = 20;
			   // 
			   // pnlSoldadoRanking
			   // 
			   this->pnlSoldadoRanking->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)),
				   static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			   this->pnlSoldadoRanking->Location = System::Drawing::Point(297, 279);
			   this->pnlSoldadoRanking->Name = L"pnlSoldadoRanking";
			   this->pnlSoldadoRanking->Size = System::Drawing::Size(202, 261);
			   this->pnlSoldadoRanking->TabIndex = 21;
			   this->pnlSoldadoRanking->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &PantallaRanking::pnlSoldadoRanking_Paint);
			   // 
			   // PantallaRanking
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1457, 776);
			   this->Controls->Add(this->pnlSoldadoRanking);
			   this->Controls->Add(this->pnlRanking);
			   this->Controls->Add(this->lblTitulo);
			   this->Controls->Add(this->btnSalir);
			   this->Name = L"PantallaRanking";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"PantallaRanking";
			   this->Load += gcnew System::EventHandler(this, &PantallaRanking::PantallaRanking_Load);
			   this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &PantallaRanking::PantallaRanking_Paint);
			   this->pnlRanking->ResumeLayout(false);
			   this->pnlRanking->PerformLayout();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	private: System::Void PantallaRanking_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		if (FondoRanking != nullptr) {
			e->Graphics->DrawImage(FondoRanking, 0, 0, this->ClientSize.Width, this->ClientSize.Height);
		}
	}
	private: System::Void btnSalir_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		if (BotonSalir != nullptr) {
			e->Graphics->DrawImage(BotonSalir, 0, 0, btnSalir->Width, btnSalir->Height);
		}
	}
	private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void pnlSoldadoRanking_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		if (SoldadoRanking != nullptr) {
			e->Graphics->DrawImage(SoldadoRanking, 0, 0, pnlSoldadoRanking->Width, pnlSoldadoRanking->Height);
		}
	}
	private: System::Void PantallaRanking_Load(System::Object^ sender, System::EventArgs^ e) {
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
};
}
