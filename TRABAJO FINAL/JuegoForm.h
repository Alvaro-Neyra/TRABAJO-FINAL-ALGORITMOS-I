#pragma once
#include "PantallaGanaste.h"
#include "PantallaPerdiste.h"
#include "Juego.h"

namespace TRABAJOFINAL {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for JuegoForm
	/// </summary>
	public ref class JuegoForm : public System::Windows::Forms::Form
	{
	public:
		JuegoForm(int nivel)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			panel = pnlCanvas->CreateGraphics();
			contexto = BufferedGraphicsManager::Current;
			buffer = contexto->Allocate(panel, pnlCanvas->ClientRectangle);
			// Panel barra de contaminacion
			panelBarra = pnlBarraContaminacion->CreateGraphics();
			contextoBarra = BufferedGraphicsManager::Current;
			bufferBarra = contextoBarra->Allocate(panelBarra, pnlBarraContaminacion->ClientRectangle);
			imagenBarra = gcnew Bitmap("barra_de_contaminacion.jpg");
			imagenFondo = gcnew Bitmap("Zona de juego.jpg");
			imagenFuegoMinotauro = gcnew Bitmap("EnemigoFuego.png");
			imagenEnemigoTierra = gcnew Bitmap("EnemigoTierra.png");
			imagenEnemigoAire = gcnew Bitmap("EnemigoAire.png");
			imagenArco = gcnew Bitmap("flecha.png");
			imagenGuardianEspada = gcnew Bitmap("GuardianEspadaCaminar.png");
			imagenGuardianCaminar = gcnew Bitmap("GuardianCaminar.png");
			imagenGuardian = imagenGuardianCaminar;
			imagenBolaDeFuego = gcnew Bitmap("BolaDeFuegoColicion.png");
			imagenAliadoVida = gcnew Bitmap("AliadoMover.png");
			imagenAliadoAtacar = gcnew Bitmap("AliadoMoverEspada.png");
			imagenSemillas = gcnew Bitmap("planta.png");
			imagenResiduosReciclables = gcnew Bitmap("Residuos Reciclables.png");
			imagenAgua = gcnew Bitmap("botellaDeAgua.png");
			fondoJuego = gcnew Bitmap("FondoJuego.png");
			imagenModoAtacar = gcnew Bitmap("imagenModoAtacar.png");
			imagenModoInteractuar = gcnew Bitmap("imagenModoRecoger.png");
			imagenCorazon = gcnew Bitmap("corazon.png");
			juego = new Juego();
			juego->crearGuardian(imagenGuardian->Width / 9, imagenGuardian->Height / 4);
			tipoNivel = nivel;
			juego->setNivel(tipoNivel);
			switch (tipoNivel) {
				case 1:
					juego->crearEnemigos(imagenEnemigoAire->Width / 9 + 1, imagenEnemigoAire->Height / 4, buffer->Graphics);
					break;
				case 2:
					juego->crearEnemigos(imagenEnemigoTierra->Width / 9 + 1, imagenEnemigoTierra->Height / 4, buffer->Graphics);
					break;
				case 3:
					juego->crearEnemigos(imagenFuegoMinotauro->Width / 9 + 1, imagenFuegoMinotauro->Height / 4, buffer->Graphics);
					break;
				case 4:
					juego->crearEnemigos(imagenFuegoMinotauro->Width / 9 + 1, imagenFuegoMinotauro->Height / 4, buffer->Graphics);
					break;
			}
			juego->crearAliados(imagenAliadoAtacar->Width / 9 + 1, imagenAliadoVida->Height / 4, buffer->Graphics);
			imagenModoActual = imagenModoInteractuar;
			juego->ajustarContaminacion(20, false);

			if (tipoNivel == 4) {
				ajustarTimersNivel4();
			}
			
			// Iniciando temporizador para el juego de 5 minutos
			inicializarTemporizador(2);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~JuegoForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ pnlCanvas;
	protected:
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		Graphics^ panel;
		BufferedGraphicsContext^ contexto;
		BufferedGraphics^ buffer;
		Graphics^ panelBarra;
		BufferedGraphicsContext^ contextoBarra;
		BufferedGraphics^ bufferBarra;
		Bitmap^ imagenBarra;
		Bitmap^ imagenFondo;
		Bitmap^ imagenGuardian;
		Bitmap^ imagenGuardianCaminar;
		Bitmap^ imagenGuardianEspada;
		Bitmap^ imagenFuegoMinotauro;
		Bitmap^ imagenEnemigoTierra;
		Bitmap^ imagenEnemigoAire;
		Bitmap^ imagenArco;
		Bitmap^ imagenBolaDeFuego;
		Bitmap^ imagenAliadoVida;
		Bitmap^ imagenAliadoAtacar;
		Bitmap^ imagenSemillas;
		Bitmap^ imagenResiduosReciclables;
		Bitmap^ imagenAgua;
		Bitmap^ fondoJuego;
		Bitmap^ imagenModoActual;
		Bitmap^ imagenModoAtacar;
		Bitmap^ imagenModoInteractuar;
		Bitmap^ imagenCorazon;
		int tipoNivel;
		bool enemigosEnPausa = false;
		int tiempoEsperado = 0;
		int tiempoRestanteMilisegundos = 0;
		bool juegoFinalizado = false;
	private: System::Windows::Forms::Timer^ timerAireMinotauro;
	private: System::Windows::Forms::Timer^ timerZombieTierra;


	private: System::Windows::Forms::Timer^ timerAliados;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lvlVidasGuardian;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ lblSalud;
	private: System::Windows::Forms::Timer^ timerRecursos;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ lblResiduosReciclables;

	private: System::Windows::Forms::Label^ lblAgua;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ lblSemillas;
	private: System::Windows::Forms::Timer^ timerCrecimientoPlantas;
	private: System::Windows::Forms::Timer^ timerFuegoMinotauros;
	private: System::Windows::Forms::Label^ label5;
private: System::Windows::Forms::Label^ lblContaminacion;


private: System::Windows::Forms::Label^ label6;
private: System::Windows::Forms::Panel^ pnlBarraContaminacion;
private: System::Windows::Forms::Panel^ pnlModoGuardian;
private: System::Windows::Forms::Panel^ pnlStats;
private: System::Windows::Forms::Panel^ pnlProgressBarBack;
private: System::Windows::Forms::Label^ label10;
private: System::Windows::Forms::Label^ lblNivel;
private: System::Windows::Forms::Label^ label8;
private: System::Windows::Forms::Panel^ pnlCorazones;
private: System::Windows::Forms::Panel^ pnlCantidadFlechas;

private: System::Windows::Forms::Label^ label9;
private: System::Windows::Forms::Label^ lblCantidadFlechas;
private: System::Windows::Forms::Timer^ timerPausaEnemigos;
private: System::Windows::Forms::Timer^ timerEsperaReactivacion;
private: System::Windows::Forms::Panel^ panel1;
private: System::Windows::Forms::Label^ lblGameTime;
private: System::Windows::Forms::Timer^ timerSeconds;
















		   Juego* juego;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->pnlCanvas = (gcnew System::Windows::Forms::Panel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerAireMinotauro = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerZombieTierra = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerAliados = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lvlVidasGuardian = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lblSalud = (gcnew System::Windows::Forms::Label());
			this->timerRecursos = (gcnew System::Windows::Forms::Timer(this->components));
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->lblResiduosReciclables = (gcnew System::Windows::Forms::Label());
			this->lblAgua = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->lblSemillas = (gcnew System::Windows::Forms::Label());
			this->timerCrecimientoPlantas = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerFuegoMinotauros = (gcnew System::Windows::Forms::Timer(this->components));
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->lblContaminacion = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->pnlBarraContaminacion = (gcnew System::Windows::Forms::Panel());
			this->pnlModoGuardian = (gcnew System::Windows::Forms::Panel());
			this->pnlStats = (gcnew System::Windows::Forms::Panel());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->lblNivel = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->pnlProgressBarBack = (gcnew System::Windows::Forms::Panel());
			this->pnlCorazones = (gcnew System::Windows::Forms::Panel());
			this->pnlCantidadFlechas = (gcnew System::Windows::Forms::Panel());
			this->lblCantidadFlechas = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->timerPausaEnemigos = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerEsperaReactivacion = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->lblGameTime = (gcnew System::Windows::Forms::Label());
			this->timerSeconds = (gcnew System::Windows::Forms::Timer(this->components));
			this->pnlStats->SuspendLayout();
			this->pnlProgressBarBack->SuspendLayout();
			this->pnlCantidadFlechas->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pnlCanvas
			// 
			this->pnlCanvas->Location = System::Drawing::Point(0, 0);
			this->pnlCanvas->Name = L"pnlCanvas";
			this->pnlCanvas->Size = System::Drawing::Size(1550, 860);
			this->pnlCanvas->TabIndex = 0;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &JuegoForm::timer1_Tick);
			// 
			// timerAireMinotauro
			// 
			this->timerAireMinotauro->Enabled = true;
			this->timerAireMinotauro->Interval = 5000;
			this->timerAireMinotauro->Tick += gcnew System::EventHandler(this, &JuegoForm::timerAireMinotauro_Tick);
			// 
			// timerZombieTierra
			// 
			this->timerZombieTierra->Enabled = true;
			this->timerZombieTierra->Interval = 1000;
			this->timerZombieTierra->Tick += gcnew System::EventHandler(this, &JuegoForm::timerZombieTierra_Tick);
			// 
			// timerAliados
			// 
			this->timerAliados->Enabled = true;
			this->timerAliados->Interval = 10000;
			this->timerAliados->Tick += gcnew System::EventHandler(this, &JuegoForm::timerAliados_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(27, 115);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(168, 25);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Vidas Guardian:";
			// 
			// lvlVidasGuardian
			// 
			this->lvlVidasGuardian->AutoSize = true;
			this->lvlVidasGuardian->BackColor = System::Drawing::Color::Transparent;
			this->lvlVidasGuardian->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->lvlVidasGuardian->ForeColor = System::Drawing::Color::White;
			this->lvlVidasGuardian->Location = System::Drawing::Point(201, 115);
			this->lvlVidasGuardian->Name = L"lvlVidasGuardian";
			this->lvlVidasGuardian->Size = System::Drawing::Size(23, 25);
			this->lvlVidasGuardian->TabIndex = 2;
			this->lvlVidasGuardian->Text = L"0";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(27, 77);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(204, 25);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Salud del Guardian:";
			// 
			// lblSalud
			// 
			this->lblSalud->AutoSize = true;
			this->lblSalud->BackColor = System::Drawing::Color::Transparent;
			this->lblSalud->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblSalud->ForeColor = System::Drawing::Color::White;
			this->lblSalud->Location = System::Drawing::Point(255, 77);
			this->lblSalud->Name = L"lblSalud";
			this->lblSalud->Size = System::Drawing::Size(24, 25);
			this->lblSalud->TabIndex = 4;
			this->lblSalud->Text = L"0";
			// 
			// timerRecursos
			// 
			this->timerRecursos->Enabled = true;
			this->timerRecursos->Interval = 8000;
			this->timerRecursos->Tick += gcnew System::EventHandler(this, &JuegoForm::timerRecursos_Tick);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(25, 250);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(224, 25);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Residuos Reciclables:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(25, 293);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(70, 25);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Agua:";
			// 
			// lblResiduosReciclables
			// 
			this->lblResiduosReciclables->AutoSize = true;
			this->lblResiduosReciclables->BackColor = System::Drawing::Color::Transparent;
			this->lblResiduosReciclables->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblResiduosReciclables->ForeColor = System::Drawing::Color::White;
			this->lblResiduosReciclables->Location = System::Drawing::Point(255, 250);
			this->lblResiduosReciclables->Name = L"lblResiduosReciclables";
			this->lblResiduosReciclables->Size = System::Drawing::Size(24, 25);
			this->lblResiduosReciclables->TabIndex = 7;
			this->lblResiduosReciclables->Text = L"0";
			// 
			// lblAgua
			// 
			this->lblAgua->AutoSize = true;
			this->lblAgua->BackColor = System::Drawing::Color::Transparent;
			this->lblAgua->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblAgua->ForeColor = System::Drawing::Color::White;
			this->lblAgua->Location = System::Drawing::Point(132, 293);
			this->lblAgua->Name = L"lblAgua";
			this->lblAgua->Size = System::Drawing::Size(24, 25);
			this->lblAgua->TabIndex = 8;
			this->lblAgua->Text = L"0";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::White;
			this->label7->Location = System::Drawing::Point(25, 335);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(101, 25);
			this->label7->TabIndex = 9;
			this->label7->Text = L"Semillas:";
			// 
			// lblSemillas
			// 
			this->lblSemillas->AutoSize = true;
			this->lblSemillas->BackColor = System::Drawing::Color::Transparent;
			this->lblSemillas->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblSemillas->ForeColor = System::Drawing::Color::White;
			this->lblSemillas->Location = System::Drawing::Point(132, 335);
			this->lblSemillas->Name = L"lblSemillas";
			this->lblSemillas->Size = System::Drawing::Size(24, 25);
			this->lblSemillas->TabIndex = 10;
			this->lblSemillas->Text = L"0";
			// 
			// timerCrecimientoPlantas
			// 
			this->timerCrecimientoPlantas->Interval = 10000;
			this->timerCrecimientoPlantas->Tick += gcnew System::EventHandler(this, &JuegoForm::timerCrecimientoPlantas_Tick);
			// 
			// timerFuegoMinotauros
			// 
			this->timerFuegoMinotauros->Enabled = true;
			this->timerFuegoMinotauros->Interval = 5000;
			this->timerFuegoMinotauros->Tick += gcnew System::EventHandler(this, &JuegoForm::timerFuegoMinotauros_Tick);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::White;
			this->label5->Location = System::Drawing::Point(16, 16);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(204, 25);
			this->label5->TabIndex = 11;
			this->label5->Text = L"CONTAMINACION:";
			// 
			// lblContaminacion
			// 
			this->lblContaminacion->AutoSize = true;
			this->lblContaminacion->BackColor = System::Drawing::Color::Transparent;
			this->lblContaminacion->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblContaminacion->ForeColor = System::Drawing::SystemColors::Control;
			this->lblContaminacion->Location = System::Drawing::Point(1463, 16);
			this->lblContaminacion->Name = L"lblContaminacion";
			this->lblContaminacion->Size = System::Drawing::Size(24, 25);
			this->lblContaminacion->TabIndex = 12;
			this->lblContaminacion->Text = L"0";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::SystemColors::Control;
			this->label6->Location = System::Drawing::Point(1507, 16);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(31, 25);
			this->label6->TabIndex = 14;
			this->label6->Text = L"%";
			// 
			// pnlBarraContaminacion
			// 
			this->pnlBarraContaminacion->Location = System::Drawing::Point(238, 878);
			this->pnlBarraContaminacion->Name = L"pnlBarraContaminacion";
			this->pnlBarraContaminacion->Size = System::Drawing::Size(1202, 45);
			this->pnlBarraContaminacion->TabIndex = 15;
			this->pnlBarraContaminacion->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &JuegoForm::pnlBarraContaminacion_Paint);
			// 
			// pnlModoGuardian
			// 
			this->pnlModoGuardian->BackColor = System::Drawing::Color::Transparent;
			this->pnlModoGuardian->Location = System::Drawing::Point(1685, 685);
			this->pnlModoGuardian->Name = L"pnlModoGuardian";
			this->pnlModoGuardian->Size = System::Drawing::Size(132, 137);
			this->pnlModoGuardian->TabIndex = 16;
			this->pnlModoGuardian->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &JuegoForm::pnlModoGuardian_Paint);
			// 
			// pnlStats
			// 
			this->pnlStats->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->pnlStats->Controls->Add(this->label10);
			this->pnlStats->Controls->Add(this->lblNivel);
			this->pnlStats->Controls->Add(this->label8);
			this->pnlStats->Controls->Add(this->lblResiduosReciclables);
			this->pnlStats->Controls->Add(this->lblAgua);
			this->pnlStats->Controls->Add(this->label4);
			this->pnlStats->Controls->Add(this->label3);
			this->pnlStats->Controls->Add(this->lvlVidasGuardian);
			this->pnlStats->Controls->Add(this->lblSemillas);
			this->pnlStats->Controls->Add(this->label1);
			this->pnlStats->Controls->Add(this->label2);
			this->pnlStats->Controls->Add(this->label7);
			this->pnlStats->Controls->Add(this->lblSalud);
			this->pnlStats->Location = System::Drawing::Point(1586, 34);
			this->pnlStats->Name = L"pnlStats";
			this->pnlStats->Size = System::Drawing::Size(307, 393);
			this->pnlStats->TabIndex = 17;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::Transparent;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold));
			this->label10->ForeColor = System::Drawing::Color::White;
			this->label10->Location = System::Drawing::Point(25, 204);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(136, 29);
			this->label10->TabIndex = 13;
			this->label10->Text = L"Recursos:";
			// 
			// lblNivel
			// 
			this->lblNivel->AutoSize = true;
			this->lblNivel->BackColor = System::Drawing::Color::Transparent;
			this->lblNivel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold));
			this->lblNivel->ForeColor = System::Drawing::Color::White;
			this->lblNivel->Location = System::Drawing::Point(130, 18);
			this->lblNivel->Name = L"lblNivel";
			this->lblNivel->Size = System::Drawing::Size(37, 39);
			this->lblNivel->TabIndex = 12;
			this->lblNivel->Text = L"0";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold));
			this->label8->ForeColor = System::Drawing::Color::White;
			this->label8->Location = System::Drawing::Point(25, 18);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(109, 39);
			this->label8->TabIndex = 11;
			this->label8->Text = L"Nivel:";
			// 
			// pnlProgressBarBack
			// 
			this->pnlProgressBarBack->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->pnlProgressBarBack->Controls->Add(this->label5);
			this->pnlProgressBarBack->Controls->Add(this->lblContaminacion);
			this->pnlProgressBarBack->Controls->Add(this->label6);
			this->pnlProgressBarBack->Location = System::Drawing::Point(12, 871);
			this->pnlProgressBarBack->Name = L"pnlProgressBarBack";
			this->pnlProgressBarBack->Size = System::Drawing::Size(1552, 64);
			this->pnlProgressBarBack->TabIndex = 18;
			// 
			// pnlCorazones
			// 
			this->pnlCorazones->BackColor = System::Drawing::Color::Transparent;
			this->pnlCorazones->Location = System::Drawing::Point(1571, 459);
			this->pnlCorazones->Name = L"pnlCorazones";
			this->pnlCorazones->Size = System::Drawing::Size(341, 181);
			this->pnlCorazones->TabIndex = 19;
			this->pnlCorazones->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &JuegoForm::pnlCorazones_Paint);
			// 
			// pnlCantidadFlechas
			// 
			this->pnlCantidadFlechas->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->pnlCantidadFlechas->Controls->Add(this->lblCantidadFlechas);
			this->pnlCantidadFlechas->Controls->Add(this->label9);
			this->pnlCantidadFlechas->Location = System::Drawing::Point(1586, 855);
			this->pnlCantidadFlechas->Name = L"pnlCantidadFlechas";
			this->pnlCantidadFlechas->Size = System::Drawing::Size(326, 137);
			this->pnlCantidadFlechas->TabIndex = 17;
			this->pnlCantidadFlechas->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &JuegoForm::pnlCantidadFlechas_Paint);
			// 
			// lblCantidadFlechas
			// 
			this->lblCantidadFlechas->BackColor = System::Drawing::Color::Transparent;
			this->lblCantidadFlechas->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCantidadFlechas->ForeColor = System::Drawing::SystemColors::Control;
			this->lblCantidadFlechas->Location = System::Drawing::Point(72, 70);
			this->lblCantidadFlechas->Name = L"lblCantidadFlechas";
			this->lblCantidadFlechas->Size = System::Drawing::Size(95, 55);
			this->lblCantidadFlechas->TabIndex = 21;
			this->lblCantidadFlechas->Text = L"0";
			// 
			// label9
			// 
			this->label9->BackColor = System::Drawing::Color::Transparent;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::SystemColors::Control;
			this->label9->Location = System::Drawing::Point(16, 86);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(41, 39);
			this->label9->TabIndex = 20;
			this->label9->Text = L"X";
			// 
			// timerPausaEnemigos
			// 
			this->timerPausaEnemigos->Enabled = true;
			this->timerPausaEnemigos->Interval = 500;
			this->timerPausaEnemigos->Tick += gcnew System::EventHandler(this, &JuegoForm::verificarEliminacionEnemigos);
			// 
			// timerEsperaReactivacion
			// 
			this->timerEsperaReactivacion->Tick += gcnew System::EventHandler(this, &JuegoForm::reactivarTimers);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->panel1->Controls->Add(this->lblGameTime);
			this->panel1->Location = System::Drawing::Point(12, 952);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(411, 62);
			this->panel1->TabIndex = 20;
			// 
			// lblGameTime
			// 
			this->lblGameTime->BackColor = System::Drawing::Color::Transparent;
			this->lblGameTime->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblGameTime->ForeColor = System::Drawing::SystemColors::Control;
			this->lblGameTime->Location = System::Drawing::Point(23, 12);
			this->lblGameTime->Name = L"lblGameTime";
			this->lblGameTime->Size = System::Drawing::Size(368, 39);
			this->lblGameTime->TabIndex = 20;
			this->lblGameTime->Text = L"0:00";
			// 
			// timerSeconds
			// 
			this->timerSeconds->Enabled = true;
			this->timerSeconds->Interval = 1000;
			this->timerSeconds->Tick += gcnew System::EventHandler(this, &JuegoForm::timerSeconds_Tick);
			// 
			// JuegoForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1924, 1026);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->pnlCantidadFlechas);
			this->Controls->Add(this->pnlCorazones);
			this->Controls->Add(this->pnlModoGuardian);
			this->Controls->Add(this->pnlBarraContaminacion);
			this->Controls->Add(this->pnlCanvas);
			this->Controls->Add(this->pnlStats);
			this->Controls->Add(this->pnlProgressBarBack);
			this->Name = L"JuegoForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"JuegoForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &JuegoForm::JuegoForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &JuegoForm::JuegoForm_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &JuegoForm::JuegoForm_Paint);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &JuegoForm::JuegoForm_KeyDown);
			this->pnlStats->ResumeLayout(false);
			this->pnlStats->PerformLayout();
			this->pnlProgressBarBack->ResumeLayout(false);
			this->pnlProgressBarBack->PerformLayout();
			this->pnlCantidadFlechas->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (buffer != nullptr && panel != nullptr) {
			buffer->Graphics->Clear(Color::White);
			buffer->Graphics->DrawImage(imagenFondo, 0, 0, pnlCanvas->Width, pnlCanvas->Height);
			juego->colisionar(buffer->Graphics);
			juego->actualizar();
			juego->expandirProyectiles();
			juego->dibujarTodo(buffer->Graphics, imagenGuardian, imagenFuegoMinotauro, imagenEnemigoTierra, imagenEnemigoAire, imagenArco, imagenBolaDeFuego, imagenAliadoVida, imagenAliadoAtacar, imagenSemillas, imagenResiduosReciclables, imagenAgua);
			juego->moverTodo(buffer->Graphics);

			if (juego->aliadosEliminados() && !timerAliados->Enabled) {
				timerAliados->Enabled = true;
			}
			if (juego->recursosRecogidos() && !timerRecursos->Enabled) {
				timerRecursos->Enabled = true;
			}
			if (juego->obtenerGuardian()->obtenerCantidadSemillas() > 0) {
				timerCrecimientoPlantas->Enabled = true;
			}

			this->lvlVidasGuardian->Text = juego->obtenerGuardian()->obtenerVidas().ToString();
			this->lblSalud->Text = juego->obtenerGuardian()->obtenerSalud().ToString();
			this->lblAgua->Text = juego->obtenerGuardian()->obtenerCantidadDeAgua().ToString();
			this->lblResiduosReciclables->Text = juego->obtenerGuardian()->obtenerCantidadResiduosReciclables().ToString();
			this->lblSemillas->Text = juego->obtenerGuardian()->obtenerCantidadSemillas().ToString();
			lblContaminacion->Text = juego->obtenerContaminacion().ToString();
			
			if (juego->obtenerGuardian()->cambioVida()) {
				pnlCorazones->Invalidate();
			}

			bufferBarra->Graphics->Clear(Color::Transparent);
			int contaminacion = juego->obtenerContaminacion();
			dibujarBarraContaminacion(bufferBarra->Graphics, 10, 10, contaminacion);
			bufferBarra->Render(panelBarra);

			int cantidadActual = juego->obtenerGuardian()->obtenerCantidadFlechas();
			if (lblCantidadFlechas->Text != cantidadActual.ToString()) {
				lblCantidadFlechas->Text = cantidadActual.ToString();
			}
			if (buffer != nullptr) {
				buffer->Render(panel);
			}

			juego->actualizarEstadoGuardian();

			if (juego->obtenerGuardian()->obtenerVidas() == 0) {
				timer1->Enabled = false;
				this->Close();
			}
		}
	}
	private: System::Void JuegoForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode) {
			case Keys::A:
				juego->obtenerGuardian()->mover(buffer->Graphics, 'A');
				juego->obtenerGuardian()->setAtacando(false);
				juego->obtenerGuardian()->setRecogerRecurso(false);
				juego->obtenerGuardian()->setGerminarPlanta(false);
				break;
			case Keys::D:
				juego->obtenerGuardian()->mover(buffer->Graphics, 'D');
				juego->obtenerGuardian()->setAtacando(false);
				juego->obtenerGuardian()->setRecogerRecurso(false);
				juego->obtenerGuardian()->setGerminarPlanta(false);
				break;
			case Keys::S:
				juego->obtenerGuardian()->mover(buffer->Graphics, 'S');
				juego->obtenerGuardian()->setAtacando(false);
				juego->obtenerGuardian()->setRecogerRecurso(false);
				juego->obtenerGuardian()->setGerminarPlanta(false);
				break;
			case Keys::W:
				juego->obtenerGuardian()->mover(buffer->Graphics, 'W');
				juego->obtenerGuardian()->setAtacando(false);
				juego->obtenerGuardian()->setRecogerRecurso(false);
				juego->obtenerGuardian()->setGerminarPlanta(false);
				break;
			case Keys::D1:
				juego->obtenerGuardian()->setArma(1);
				juego->obtenerGuardian()->setAtacando(false);
				juego->obtenerGuardian()->setRecogerRecurso(false);
				juego->obtenerGuardian()->setGerminarPlanta(false);
				imagenModoActual = imagenModoInteractuar;
				pnlModoGuardian->Invalidate();
				imagenGuardian = imagenGuardianCaminar;
				break;
			case Keys::D2:
				juego->obtenerGuardian()->setArma(2);
				juego->obtenerGuardian()->setAtacando(false);
				juego->obtenerGuardian()->setRecogerRecurso(false);
				juego->obtenerGuardian()->setGerminarPlanta(false);
				imagenModoActual = imagenModoAtacar;
				pnlModoGuardian->Invalidate();
				imagenGuardian = imagenGuardianEspada;
				break;
			case Keys::Space:
				if (juego->obtenerGuardian()->getArma() == 2) {
					juego->agregarArco(new Arco(juego->obtenerGuardian()->obtenerXAnchoMitad(), juego->obtenerGuardian()->obtenerYAltoMitad(), imagenArco->Width, imagenArco->Height, juego->obtenerGuardian()->obtenerDireccion()));
				}
				juego->obtenerGuardian()->setRecogerRecurso(false);
				juego->obtenerGuardian()->setAtacando(true);
				juego->obtenerGuardian()->setGerminarPlanta(false);
				break;
			case Keys::F:
				if (juego->obtenerGuardian()->getArma() == 1) {
					juego->obtenerGuardian()->setRecogerRecurso(true);
					juego->obtenerGuardian()->setGerminarPlanta(false);
				}
				break;
			case Keys::E:
				if (juego->obtenerGuardian()->getArma() == 1 && juego->obtenerGuardian()->obtenerCantidadSemillas () > 0) {
					juego->plantar(imagenSemillas);
					juego->obtenerGuardian()->disminuirSemillas(1);
				}

				if (juego->obtenerGuardian()->getArma() == 1 && juego->obtenerGuardian()->obtenerCantidadDeAgua() > 0) {
					juego->obtenerGuardian()->setGerminarPlanta(true);
				}
				break;
			case Keys::Q:
				juego->obtenerGuardian()->generarFlechas();
				juego->obtenerGuardian()->setAtacando(false);
				juego->obtenerGuardian()->setRecogerRecurso(false);
				juego->obtenerGuardian()->setGerminarPlanta(false);
				break;
			default:
				juego->obtenerGuardian()->setAtacando(false);
				juego->obtenerGuardian()->setRecogerRecurso(false);
				juego->obtenerGuardian()->setGerminarPlanta(false);
				break;
		}
	}
	// Timer enemigos aire
	private: System::Void timerAireMinotauro_Tick(System::Object^ sender, System::EventArgs^ e) { // 5 segundos
		if (timer1->Enabled) {
			if (tipoNivel == 1 || tipoNivel == 4) {
				if (tipoNivel == 4 && juego->obtenerCantidadEnemigosActuales() >= 10) {
					pausarTimersEnemigos();
					return;
				}

				if (!enemigosEnPausa) {
					if (tipoNivel == 4) {
						juego->ajustarDificultadEnemigos(tipoNivel);
					}
					juego->crearEnemigos(imagenEnemigoAire->Width / 9 + 1, imagenEnemigoAire->Height / 4, buffer->Graphics);
				}
			}	
		}
	}
	// Timer enemigos tierra zombie
	private: System::Void timerZombieTierra_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (timer1->Enabled) {
			if (tipoNivel == 2 || tipoNivel == 4) {
				if (tipoNivel == 4 && juego->obtenerCantidadEnemigosActuales() >= 10) {
					pausarTimersEnemigos();
					return;
				}
				if (!enemigosEnPausa) {
					if (tipoNivel == 4) {
						juego->ajustarDificultadEnemigos(tipoNivel);
					}
					juego->crearEnemigos(imagenEnemigoTierra->Width / 9 + 1, imagenEnemigoTierra->Height / 4, buffer->Graphics);
				}
			}
		}
	}
	// Timer aliados
	private: System::Void timerAliados_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (timer1->Enabled) {
			if (juego->aliadosEliminados()) {
				juego->crearAliados(imagenAliadoAtacar->Width / 9 + 1, imagenAliadoAtacar->Height / 4 + 2, buffer->Graphics);
			}
			timerAliados->Enabled = false;
		}
	}
	// Timer recursos
	private: System::Void timerRecursos_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (timer1->Enabled) {
			if (juego->recursosRecogidos()) {
				juego->crearRecursos(buffer->Graphics, imagenSemillas, imagenAgua, imagenResiduosReciclables);
			}
			timerRecursos->Enabled = false;
		}
	}
	
	private: System::Void JuegoForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		timer1->Enabled = false;
		if (timerSeconds != nullptr) timerSeconds->Enabled = false;
		if (timerAliados != nullptr) timerAliados->Enabled = false;
		if (timerRecursos != nullptr) timerRecursos->Enabled = false;
		if (timerAireMinotauro != nullptr) timerAireMinotauro->Enabled = false;
		if (timerZombieTierra != nullptr) timerZombieTierra->Enabled = false;
		if (timerCrecimientoPlantas != nullptr) timerCrecimientoPlantas->Enabled = false;
		if (timerFuegoMinotauros != nullptr) timerFuegoMinotauros->Enabled = false;

		if (buffer != nullptr) {
			delete buffer;
			buffer = nullptr;
		}

		if (contexto != nullptr) {
			delete contexto;
			contexto = nullptr;
		}

		if (bufferBarra != nullptr) {
			delete bufferBarra;
			bufferBarra = nullptr;
		}

		if (contextoBarra != nullptr) {
			delete contextoBarra;
			contextoBarra = nullptr;
		}

		if (imagenBarra != nullptr) delete imagenBarra;
		if (imagenFondo != nullptr) delete imagenFondo;
		if (imagenGuardian != nullptr) delete imagenGuardian;
		if (imagenGuardianCaminar != nullptr) delete imagenGuardianCaminar;
		if (imagenGuardianEspada != nullptr) delete imagenGuardianEspada;
		if (imagenFuegoMinotauro != nullptr) delete imagenFuegoMinotauro;
		if (imagenEnemigoTierra != nullptr) delete imagenEnemigoTierra;
		if (imagenEnemigoAire != nullptr) delete imagenEnemigoAire;
		if (imagenArco != nullptr) delete imagenArco;
		if (imagenBolaDeFuego != nullptr) delete imagenBolaDeFuego;
		if (imagenAliadoVida != nullptr) delete imagenAliadoVida;
		if (imagenAliadoAtacar != nullptr) delete imagenAliadoAtacar;
		if (imagenSemillas != nullptr) delete imagenSemillas;
		if (imagenResiduosReciclables != nullptr) delete imagenResiduosReciclables;
		if (imagenAgua != nullptr) delete imagenAgua;
		if (fondoJuego != nullptr) delete fondoJuego;
		if (imagenModoAtacar != nullptr) delete imagenModoAtacar;
		if (imagenModoInteractuar != nullptr) delete imagenModoInteractuar;
		if (imagenCorazon != nullptr) delete imagenCorazon;
	}
	private: System::Void JuegoForm_Load(System::Object^ sender, System::EventArgs^ e) {
		juego->reiniciarJuego();
	}
	// Timer de crecimiento
	private: System::Void timerCrecimientoPlantas_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (timer1->Enabled) {
			juego->actualizarCrecimientoPlantas();
		}
	}
	// Timer fuego minotauro
	private: System::Void timerFuegoMinotauros_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (timer1->Enabled) {
			if (tipoNivel == 3 || tipoNivel == 4) {
				if (tipoNivel == 4 && juego->obtenerCantidadEnemigosActuales() >= 10) {
					pausarTimersEnemigos();
					return;
				}
				if (!enemigosEnPausa) {
					if (tipoNivel == 4) {
						juego->ajustarDificultadEnemigos(tipoNivel);
					}
					juego->crearEnemigos(imagenFuegoMinotauro->Width / 9 + 1, imagenFuegoMinotauro->Height / 4, buffer->Graphics);
					juego->disparoAleatorio(imagenBolaDeFuego->Width, imagenBolaDeFuego->Height);
				}
			}
		}
	}
	private: System::Void pnlBarraContaminacion_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		bufferBarra->Graphics->Clear(Color::Transparent);
		int contaminacion = juego->obtenerContaminacion();
		dibujarBarraContaminacion(bufferBarra->Graphics, 0, 0, contaminacion);

		bufferBarra->Render(panelBarra);
	}


   void dibujarBarraContaminacion(Graphics^ g, int x, int y, int contaminacion) {

	   g->DrawImage(imagenBarra, x - 10, y - 10, pnlBarraContaminacion->Width, pnlBarraContaminacion->Height);

	   int anchoMaxBarra = imagenBarra->Width + 50; // Restar margen
	   int altoBarra = imagenBarra->Height - 70;
	   int anchoDinamico = (contaminacion * anchoMaxBarra) / 100;

	   Brush^ colorBarra;
	   if (contaminacion < 30) colorBarra = Brushes::Green;
	   else if (contaminacion < 70) colorBarra = Brushes::Yellow;
	   else colorBarra = Brushes::Red;

	   g->FillRectangle(Brushes::Gray, x, y, anchoMaxBarra, altoBarra);
	   g->FillRectangle(colorBarra, x, y, anchoDinamico, altoBarra);
	   g->DrawRectangle(Pens::Black, x, y, anchoMaxBarra, altoBarra);
   }
private: System::Void JuegoForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	if (fondoJuego != nullptr) {
		e->Graphics->DrawImage(fondoJuego, 0, 0, this->ClientSize.Width, this->ClientSize.Height);
	}
	this->lblNivel->Text = tipoNivel.ToString();
}

private: System::Void pnlModoGuardian_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	if (imagenModoActual != nullptr) {
		e->Graphics->DrawImage(imagenModoActual, 0, 0, pnlModoGuardian->Width, pnlModoGuardian->Height);
	}
}
	void dibujarCorazones(Graphics^ g, int vidas, int xInicial, int yInicial, int espacioEntreCorazones, int anchoCorazon, int altoCorazon) {
		   for (int i = 0; i < vidas; i++) {
			   g->DrawImage(imagenCorazon, xInicial + i * (anchoCorazon + espacioEntreCorazones), yInicial, anchoCorazon, altoCorazon);
		   }
	}

	private: System::Void pnlCorazones_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		int vidasGuardian = juego->obtenerGuardian()->obtenerVidas();
		dibujarCorazones(e->Graphics, vidasGuardian, 20, 30, 10, 70, 70);
	}

   void dibujarFlechaRotada(Graphics^ g, Bitmap^ imagenFlecha, int x, int y, int ancho, int alto, float angulo) {
	   Drawing2D::Matrix^ estadoOriginal = g->Transform;

	   g->TranslateTransform(x + ancho / 2.0f, y + alto / 2.0f);

	   g->RotateTransform(angulo);

	   g->DrawImage(imagenFlecha, static_cast<float>(-ancho) / 2.0f, static_cast<float>(-alto) / 2.0f, static_cast<float>(ancho), static_cast<float>(alto));

	   g->Transform = estadoOriginal;
   }

   private: System::Void pnlCantidadFlechas_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	   int x = 150;
	   int y = (pnlCantidadFlechas->Height - 100) / 2;
	   int ancho = 50;
	   int alto = 100;

	   dibujarFlechaRotada(e->Graphics, imagenArco, x, y, ancho, alto, -45.0f);
   }

	private: System::Void ajustarTimersNivel4() {
		if (tipoNivel == 4) {
			this->timerFuegoMinotauros->Interval = 6000;
			this->timerZombieTierra->Interval = 5000;
			this->timerAireMinotauro->Interval = 8000;
		}
	}

private: System::Void pausarTimersEnemigos() {
	if (!enemigosEnPausa) {
		enemigosEnPausa = true;
		this->timerFuegoMinotauros->Enabled = false;
		this->timerZombieTierra->Enabled = false;
		this->timerAireMinotauro->Enabled = false;

		this->timerPausaEnemigos->Enabled = true;
	}
}

private: System::Void verificarEliminacionEnemigos(System::Object^ sender, System::EventArgs^ e) {
	const int TIEMPO_MAXIMO_PAUSA = 30000;

	tiempoEsperado += this->timerPausaEnemigos->Interval;

	if (juego->obtenerCantidadEnemigosActuales() == 0 || tiempoEsperado >= TIEMPO_MAXIMO_PAUSA) {
		tiempoEsperado = 0;
		this->timerPausaEnemigos->Enabled = false;
		iniciarEsperaReactivacion();
	}
}

private: System::Void iniciarEsperaReactivacion() {
    this->timerEsperaReactivacion->Interval = 5000;
    this->timerEsperaReactivacion->Enabled = true;
}

private: System::Void reactivarTimers(System::Object^ sender, System::EventArgs^ e) {
    this->timerFuegoMinotauros->Enabled = true;
    this->timerZombieTierra->Enabled = true;
    this->timerAireMinotauro->Enabled = true;

    enemigosEnPausa = false;

    this->timerEsperaReactivacion->Enabled = false;
}

private: System::Void inicializarTemporizador(int minutosIniciales) {
	tiempoRestanteMilisegundos = minutosIniciales * 60 * 1000;
	lblGameTime->Text = formatearTiempo(tiempoRestanteMilisegundos);
	timerSeconds->Start();
}

private: System::String^ formatearTiempo(int tiempoEnMilisegundos) {
	int tiempoEnSegundos = tiempoEnMilisegundos / 1000;
	int minutos = tiempoEnSegundos / 60;
	int segundos = tiempoEnSegundos % 60;

	return String::Format("{0} minutos: {1:D2}:{2:D2}", minutos, minutos, segundos);
}

	private: System::Void timerSeconds_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (tiempoRestanteMilisegundos > 0) {
			tiempoRestanteMilisegundos -= 1000;
			lblGameTime->Text = formatearTiempo(tiempoRestanteMilisegundos);
		}
		else {
			lblGameTime->Text = "0 minutos: 0:00";
			timerSeconds->Stop();
			manejarFinDelJuego(juego->obtenerContaminacion() < 30);
		}
	}
   private: void manejarFinDelJuego(bool ganaste) {
	   if (juegoFinalizado) return;
	   juegoFinalizado = true;
	   timer1->Enabled = false;
	   timerSeconds->Enabled = false;
	   juego->setNivelUltimoAlcanzado(tipoNivel);
	   if (timerAliados != nullptr) timerAliados->Enabled = false;
	   if (timerRecursos != nullptr) timerRecursos->Enabled = false;
	   if (timerAireMinotauro != nullptr) timerAireMinotauro->Enabled = false;
	   if (timerZombieTierra != nullptr) timerZombieTierra->Enabled = false;
	   if (timerCrecimientoPlantas != nullptr) timerCrecimientoPlantas->Enabled = false;
	   if (timerFuegoMinotauros != nullptr) timerFuegoMinotauros->Enabled = false;
	   juego->guardarPuntaje();
	   if (ganaste) {
		   TRABAJOFINAL::PantallaGanaste^ pantallaGanaste = gcnew TRABAJOFINAL::PantallaGanaste();
		   pantallaGanaste->ShowDialog();
	   }
	   else {
		   TRABAJOFINAL::PantallaPerdiste^ pantallaPerdiste = gcnew TRABAJOFINAL::PantallaPerdiste();
		   pantallaPerdiste->ShowDialog();
	   }
   }
}
#pragma endregion
;
}
