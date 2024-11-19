#pragma once

namespace TRABAJOFINAL {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de PantallaHistoria
	/// </summary>
	public ref class PantallaHistoria : public System::Windows::Forms::Form
	{
	public:
		PantallaHistoria(void)
		{
			InitializeComponent();
			//
			//TODO: agregar c�digo de constructor aqu�
			//

			pnlCapitulo1->Visible = false;
			pnlCapitulo2->Visible = false;
			pnlCapitulo3->Visible = false;
			pnlCapitulo4->Visible = false;
			pnlCapitulo5->Visible = false;
			pnlCapitulo6->Visible = false;


			BotonSalir = gcnew Bitmap("BotonSalir.png");
			FondoHistoria = gcnew Bitmap("FondoHistoria.png");

		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~PantallaHistoria()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnCapitulo1;
	private: System::Windows::Forms::Button^ btnCapitulo2;
	private: System::Windows::Forms::Button^ btnCapitulo3;
	private: System::Windows::Forms::Button^ btnCapitulo4;
	private: System::Windows::Forms::Button^ btnCapitulo5;
	private: System::Windows::Forms::Button^ btnCapitulo6;
	private: System::Windows::Forms::Panel^ pnlCapitulo1;
	private: System::Windows::Forms::Label^ lblCapitulo1;


	protected:

	protected:






	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;
	private: System::Windows::Forms::Button^ btnSalir;

#pragma region Windows Form Designer generated code

		   Bitmap^ FondoHistoria;
	private: System::Windows::Forms::Panel^ pnlCapitulo2;
	private: System::Windows::Forms::Label^ lblCapitulo2;
	private: System::Windows::Forms::Panel^ pnlCapitulo3;
	private: System::Windows::Forms::Label^ lblCapitulo3;
	private: System::Windows::Forms::Panel^ pnlCapitulo4;
	private: System::Windows::Forms::Label^ lblCapitulo4;
	private: System::Windows::Forms::Panel^ pnlCapitulo5;
	private: System::Windows::Forms::Label^ lblCapitulo5;
	private: System::Windows::Forms::Panel^ pnlCapitulo6;
	private: System::Windows::Forms::Label^ lblCapitulo6;




		   Bitmap^ BotonSalir;

		   /// <summary>
		   /// M�todo necesario para admitir el Dise�ador. No se puede modificar
		   /// el contenido de este m�todo con el editor de c�digo.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->btnCapitulo1 = (gcnew System::Windows::Forms::Button());
			   this->btnCapitulo2 = (gcnew System::Windows::Forms::Button());
			   this->btnCapitulo3 = (gcnew System::Windows::Forms::Button());
			   this->btnCapitulo4 = (gcnew System::Windows::Forms::Button());
			   this->btnCapitulo5 = (gcnew System::Windows::Forms::Button());
			   this->btnCapitulo6 = (gcnew System::Windows::Forms::Button());
			   this->pnlCapitulo1 = (gcnew System::Windows::Forms::Panel());
			   this->lblCapitulo1 = (gcnew System::Windows::Forms::Label());
			   this->btnSalir = (gcnew System::Windows::Forms::Button());
			   this->pnlCapitulo2 = (gcnew System::Windows::Forms::Panel());
			   this->lblCapitulo2 = (gcnew System::Windows::Forms::Label());
			   this->pnlCapitulo3 = (gcnew System::Windows::Forms::Panel());
			   this->lblCapitulo3 = (gcnew System::Windows::Forms::Label());
			   this->pnlCapitulo4 = (gcnew System::Windows::Forms::Panel());
			   this->lblCapitulo4 = (gcnew System::Windows::Forms::Label());
			   this->pnlCapitulo5 = (gcnew System::Windows::Forms::Panel());
			   this->lblCapitulo5 = (gcnew System::Windows::Forms::Label());
			   this->pnlCapitulo6 = (gcnew System::Windows::Forms::Panel());
			   this->lblCapitulo6 = (gcnew System::Windows::Forms::Label());
			   this->pnlCapitulo1->SuspendLayout();
			   this->pnlCapitulo2->SuspendLayout();
			   this->pnlCapitulo3->SuspendLayout();
			   this->pnlCapitulo4->SuspendLayout();
			   this->pnlCapitulo5->SuspendLayout();
			   this->pnlCapitulo6->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // btnCapitulo1
			   // 
			   this->btnCapitulo1->Location = System::Drawing::Point(13, 13);
			   this->btnCapitulo1->Name = L"btnCapitulo1";
			   this->btnCapitulo1->Size = System::Drawing::Size(200, 40);
			   this->btnCapitulo1->TabIndex = 0;
			   this->btnCapitulo1->Text = L"Capitulo 1";
			   this->btnCapitulo1->UseVisualStyleBackColor = true;
			   this->btnCapitulo1->Click += gcnew System::EventHandler(this, &PantallaHistoria::btnCapitulo1_Click);
			   // 
			   // btnCapitulo2
			   // 
			   this->btnCapitulo2->Location = System::Drawing::Point(252, 13);
			   this->btnCapitulo2->Name = L"btnCapitulo2";
			   this->btnCapitulo2->Size = System::Drawing::Size(200, 40);
			   this->btnCapitulo2->TabIndex = 1;
			   this->btnCapitulo2->Text = L"Capitulo 2";
			   this->btnCapitulo2->UseVisualStyleBackColor = true;
			   this->btnCapitulo2->Click += gcnew System::EventHandler(this, &PantallaHistoria::btnCapitulo2_Click);
			   // 
			   // btnCapitulo3
			   // 
			   this->btnCapitulo3->Location = System::Drawing::Point(497, 13);
			   this->btnCapitulo3->Name = L"btnCapitulo3";
			   this->btnCapitulo3->Size = System::Drawing::Size(200, 40);
			   this->btnCapitulo3->TabIndex = 2;
			   this->btnCapitulo3->Text = L"Capitulo 3";
			   this->btnCapitulo3->UseVisualStyleBackColor = true;
			   this->btnCapitulo3->Click += gcnew System::EventHandler(this, &PantallaHistoria::btnCapitulo3_Click);
			   // 
			   // btnCapitulo4
			   // 
			   this->btnCapitulo4->Location = System::Drawing::Point(747, 13);
			   this->btnCapitulo4->Name = L"btnCapitulo4";
			   this->btnCapitulo4->Size = System::Drawing::Size(200, 40);
			   this->btnCapitulo4->TabIndex = 3;
			   this->btnCapitulo4->Text = L"Capitulo 4";
			   this->btnCapitulo4->UseVisualStyleBackColor = true;
			   this->btnCapitulo4->Click += gcnew System::EventHandler(this, &PantallaHistoria::btnCapitulo4_Click);
			   // 
			   // btnCapitulo5
			   // 
			   this->btnCapitulo5->Location = System::Drawing::Point(996, 12);
			   this->btnCapitulo5->Name = L"btnCapitulo5";
			   this->btnCapitulo5->Size = System::Drawing::Size(200, 40);
			   this->btnCapitulo5->TabIndex = 4;
			   this->btnCapitulo5->Text = L"Capitulo 5";
			   this->btnCapitulo5->UseVisualStyleBackColor = true;
			   this->btnCapitulo5->Click += gcnew System::EventHandler(this, &PantallaHistoria::btnCapitulo5_Click);
			   // 
			   // btnCapitulo6
			   // 
			   this->btnCapitulo6->Location = System::Drawing::Point(1245, 12);
			   this->btnCapitulo6->Name = L"btnCapitulo6";
			   this->btnCapitulo6->Size = System::Drawing::Size(200, 40);
			   this->btnCapitulo6->TabIndex = 5;
			   this->btnCapitulo6->Text = L"Capitulo 6";
			   this->btnCapitulo6->UseVisualStyleBackColor = true;
			   this->btnCapitulo6->Click += gcnew System::EventHandler(this, &PantallaHistoria::btnCapitulo6_Click);
			   // 
			   // pnlCapitulo1
			   // 
			   this->pnlCapitulo1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				   static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			   this->pnlCapitulo1->Controls->Add(this->lblCapitulo1);
			   this->pnlCapitulo1->Location = System::Drawing::Point(12, 69);
			   this->pnlCapitulo1->Name = L"pnlCapitulo1";
			   this->pnlCapitulo1->Size = System::Drawing::Size(1432, 639);
			   this->pnlCapitulo1->TabIndex = 6;
			   // 
			   // lblCapitulo1
			   // 
			   this->lblCapitulo1->AutoSize = true;
			   this->lblCapitulo1->BackColor = System::Drawing::Color::Transparent;
			   this->lblCapitulo1->Font = (gcnew System::Drawing::Font(L"Century", 18));
			   this->lblCapitulo1->ForeColor = System::Drawing::Color::White;
			   this->lblCapitulo1->Location = System::Drawing::Point(20, 20);
			   this->lblCapitulo1->Name = L"lblCapitulo1";
			   this->lblCapitulo1->Size = System::Drawing::Size(12655, 35);
			   this->lblCapitulo1->TabIndex = 0;
			   this->lblCapitulo1->Text = "Capítulo 1: Los Elegidos del Bosque\n El Bosque de Teralin había sido el corazón palpitante de la naturaleza durante siglos.\n Sin embargo, la humanidad, al alejarse de su conexión con la tierra, comenzó a destruir\n el equilibrio que una vez lo mantuvo vivo. La erosión avanzaba, los árboles caían y la\n vida del bosque se desvanecía. Pero, en las sombras del bosque, los Ancianos del Bosque\n decidieron intervenir. Eligieron a Terrakor, el Guardián del Bosque, quien, armado con\n una armadura mística y la capacidad de comunicarse con la naturaleza, era el único\n que podía restaurar el equilibrio.\n Terrakor fue acompañado por Lyraea, una joven guerrera con alas purpuras, cuya\n espada brillaba con energía divina. Lyraea había sido elegida no solo por su destreza\n en combate, sino también por su valentía. Juntos, se embarcaron en una misión para\n salvar al Bosque de Teralin de la destrucción.\n";
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
			   this->btnSalir->Click += gcnew System::EventHandler(this, &PantallaHistoria::btnSalir_Click);
			   this->btnSalir->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &PantallaHistoria::btnSalir_Paint);
			   // 
			   // pnlCapitulo2
			   // 
			   this->pnlCapitulo2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				   static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			   this->pnlCapitulo2->Controls->Add(this->lblCapitulo2);
			   this->pnlCapitulo2->Location = System::Drawing::Point(13, 69);
			   this->pnlCapitulo2->Name = L"pnlCapitulo2";
			   this->pnlCapitulo2->Size = System::Drawing::Size(1432, 636);
			   this->pnlCapitulo2->TabIndex = 7;
			   // 
			   // lblCapitulo2
			   // 
			   this->lblCapitulo2->AutoSize = true;
			   this->lblCapitulo2->BackColor = System::Drawing::Color::Transparent;
			   this->lblCapitulo2->Font = (gcnew System::Drawing::Font(L"Century", 15));
			   this->lblCapitulo2->ForeColor = System::Drawing::Color::White;
			   this->lblCapitulo2->Location = System::Drawing::Point(20, 20);
			   this->lblCapitulo2->Name = L"lblCapitulo2";
			   this->lblCapitulo2->Size = System::Drawing::Size(13288, 29);
			   this->lblCapitulo2->TabIndex = 0;
			   this->lblCapitulo2->Text = "Capítulo 2: La Tribu Zolghar\n El primer enemigo que enfrentaron fue Zolghar, un guerrero ancestral que,\n tras caer bajo la corrupción, fue transformado en un zombie. Zolghar no\n solo conservaba sus habilidades de combate, sino que también empuñaba\n una espada maldita, capaz de cortar incluso la esencia misma de la vida.\n Terrakor y Lyraea llegaron a las tierras pantanosas donde Zolghar y su tribu de\n muertos vivientes acechaban. La tribu atacó con ferocidad, pero Zolghar se destacó\n entre ellos, luchando con una destreza mortal gracias a su espada maldita. Lyraea,\n con su velocidad y habilidad con la espada, se enfrentó directamente a Zolghar,\n mientras Terrakor invocaba las fuerzas de la tierra para crear barreras y protegerse de los ataques.\n Zolghar utilizó su espada para desatar golpes letales, cortando los árboles a su alrededor y\n  enviando ondas de energía oscura. En un momento crítico, Lyraea logró desarmarlo, despojándolo\n de su espada. Sin la espada maldita, Zolghar perdió su mayor fuente de poder, y Terrakor lo destruyo\n con un golpe certero, restaurando la paz temporalmente en el pantano.\n";
			   // 
			   // pnlCapitulo3
			   // 
			   this->pnlCapitulo3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				   static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			   this->pnlCapitulo3->Controls->Add(this->lblCapitulo3);
			   this->pnlCapitulo3->Location = System::Drawing::Point(12, 69);
			   this->pnlCapitulo3->Name = L"pnlCapitulo3";
			   this->pnlCapitulo3->Size = System::Drawing::Size(1433, 639);
			   this->pnlCapitulo3->TabIndex = 8;
			   // 
			   // lblCapitulo3
			   // 
			   this->lblCapitulo3->AutoSize = true;
			   this->lblCapitulo3->BackColor = System::Drawing::Color::Transparent;
			   this->lblCapitulo3->Font = (gcnew System::Drawing::Font(L"Century", 15));
			   this->lblCapitulo3->ForeColor = System::Drawing::Color::White;
			   this->lblCapitulo3->Location = System::Drawing::Point(20, 20);
			   this->lblCapitulo3->Name = L"lblCapitulo3";
			   this->lblCapitulo3->Size = System::Drawing::Size(13698, 29);
			   this->lblCapitulo3->TabIndex = 0;
			   this->lblCapitulo3->Text = "Capítulo 3: La Fuerza de Taurus\n Después de la victoria sobre Zolghar, Terrakor y Lyraea se adentraron más en el bosque,\n solo para enfrentarse a Taurus, el Toro de Guerra. Taurus, una bestia de inmensa fuerza,\n portaba un tridente de poder antiguo, capaz de destrozar todo a su paso. Su poder era\n casi imparable, y su furia destructiva arrasaba con cualquier cosa que encontraba a su paso.\n Terrakor intentó enfrentarse a Taurus de manera directa, pero pronto se dio cuenta de que\n  el poder del tridente era mucho más peligroso de lo que imaginaba. Los ataques de Taurus\n  causaban explosiones en el suelo, haciendo que el terreno se abriera a su paso. Lyraea,\n usando su agilidad, intentó distraer al toro, pero su tamaño y poder eran abrumadores.\n La clave para derrotarlo fue la astucia de Lyraea. Aprovechando un momento en que\n Taurus se distrajo, ella logró acercarse lo suficiente para golpear los puntos débiles en\n su armadura. Mientras tanto, Terrakor, usando el poder de la tierra, hizo que el suelo bajo\n Taurus cediera, atrapándolo en un foso profundo. Sin su tridente y rodeado por las raíces\n del bosque, Taurus finalmente fue derrotado.\n";
			   // 
			   // pnlCapitulo4
			   // 
			   this->pnlCapitulo4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				   static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			   this->pnlCapitulo4->Controls->Add(this->lblCapitulo4);
			   this->pnlCapitulo4->Location = System::Drawing::Point(12, 69);
			   this->pnlCapitulo4->Name = L"pnlCapitulo4";
			   this->pnlCapitulo4->Size = System::Drawing::Size(1433, 639);
			   this->pnlCapitulo4->TabIndex = 9;
			   // 
			   // lblCapitulo4
			   // 
			   this->lblCapitulo4->AutoSize = true;
			   this->lblCapitulo4->BackColor = System::Drawing::Color::Transparent;
			   this->lblCapitulo4->Font = (gcnew System::Drawing::Font(L"Century", 15));
			   this->lblCapitulo4->ForeColor = System::Drawing::Color::White;
			   this->lblCapitulo4->Location = System::Drawing::Point(20, 20);
			   this->lblCapitulo4->Name = L"lblCapitulo4";
			   this->lblCapitulo4->Size = System::Drawing::Size(15515, 29);
			   this->lblCapitulo4->TabIndex = 0;
			   this->lblCapitulo4->Text = "Capítulo 4: El Minotauro Alado - Minnor\n La siguiente amenaza que enfrentaron fue Minnor, el Minotauro alado.\n Esta criatura no solo era increíblemente fuerte, sino que dominaba el fuego\n de una manera peligrosa. Cada vez que el fuego de Minnor colisionaba con algo,\n se dividía en cuatro llamas que volaban en direcciones aleatorias, lo que hacía\n que sus ataques fueran impredecibles y difíciles de esquivar.\n Minnor comenzó su ataque desde el aire, lanzando llamaradas que se dividían y\n se esparcían en todas direcciones. Las llamas tocaban árboles, rocas y el suelo,\n causando explosiones a cada momento. Lyraea, utilizando sus alas purpuras,\n voló rápidamente para esquivar el fuego, pero incluso ella tuvo dificultades para\n mantenerse al margen de las llamas erráticas.\n Terrakor, reconociendo la naturaleza impredecible de los ataques de Minnor,\n decidió utilizar su control sobre los elementos para contrarrestar el fuego.\n Invocó vientos poderosos que ayudaron a redirigir las llamas de Minnor, mientras que Lyraea,\n en el aire, atacaba al minotauro con velocidad. Finalmente, Terrakor usó su poder para crear\n un campo de raíces y plantas alrededor de Minnor, atrapándolo antes de que pudiera lanzar más llamas.\n Con un golpe certero, Minnor fue derrotado, cayendo al suelo con un estruendo.\n";
			   // 
			   // pnlCapitulo5
			   // 
			   this->pnlCapitulo5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				   static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			   this->pnlCapitulo5->Controls->Add(this->lblCapitulo5);
			   this->pnlCapitulo5->Location = System::Drawing::Point(12, 69);
			   this->pnlCapitulo5->Name = L"pnlCapitulo5";
			   this->pnlCapitulo5->Size = System::Drawing::Size(1433, 639);
			   this->pnlCapitulo5->TabIndex = 10;
			   // 
			   // lblCapitulo5
			   // 
			   this->lblCapitulo5->AutoSize = true;
			   this->lblCapitulo5->BackColor = System::Drawing::Color::Transparent;
			   this->lblCapitulo5->Font = (gcnew System::Drawing::Font(L"Century", 15));
			   this->lblCapitulo5->ForeColor = System::Drawing::Color::White;
			   this->lblCapitulo5->Location = System::Drawing::Point(20, 20);
			   this->lblCapitulo5->Name = L"lblCapitulo5";
			   this->lblCapitulo5->Size = System::Drawing::Size(12720, 29);
			   this->lblCapitulo5->TabIndex = 0;
			   this->lblCapitulo5->Text = "Capítulo 5: La Alianza Oscura\n Después de la derrota de tres de sus enemigos, Terrakor y Lyraea se sintieron victoriosos,\n pero su éxito fue corto. Los tres enemigos, Zolghar, Taurus y Minnor, se unieron en una\n  alianza oscura, jurando vengarse de aquellos que habían destruido sus cuerpos. Juntos,\n combinaron sus fuerzas y crearon una tormenta de caos y destrucción.\n Zolghar usaba su magia oscura para invocar más muertos vivientes, Taurus desataba su\n tridente con una furia incontrolable, y Minnor lanzaba llamas que se multiplicaban y se\n esparcían por todo el campo. Juntos, atacaron a Terrakor y Lyraea con una intensidad\n nunca antes vista.\n La batalla fue épica y agotadora. Terrakor y Lyraea lucharon con todo su poder,\n pero la unión de los tres enemigos los sobrepasaba. La corrupción de Zolghar,\n  la furia destructiva de Taurus y la imprevisibilidad del fuego de Minnor eran\n demasiado para resistir. Terrakor fue finalmente derrotado, atrapado por las\n llamas y la magia oscura. Lyraea luchó desesperadamente, pero la oscuridad\n parecía invencible.\n";
			   // 
			   // pnlCapitulo6
			   // 
			   this->pnlCapitulo6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				   static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			   this->pnlCapitulo6->Controls->Add(this->lblCapitulo6);
			   this->pnlCapitulo6->Location = System::Drawing::Point(12, 69);
			   this->pnlCapitulo6->Name = L"pnlCapitulo6";
			   this->pnlCapitulo6->Size = System::Drawing::Size(1433, 639);
			   this->pnlCapitulo6->TabIndex = 11;
			   // 
			   // lblCapitulo6
			   // 
			   this->lblCapitulo6->AutoSize = true;
			   this->lblCapitulo6->BackColor = System::Drawing::Color::Transparent;
			   this->lblCapitulo6->Font = (gcnew System::Drawing::Font(L"Century", 15));
			   this->lblCapitulo6->ForeColor = System::Drawing::Color::White;
			   this->lblCapitulo6->Location = System::Drawing::Point(20, 20);
			   this->lblCapitulo6->Name = L"lblCapitulo6";
			   this->lblCapitulo6->Size = System::Drawing::Size(7881, 29);
			   this->lblCapitulo6->TabIndex = 0;
			   this->lblCapitulo6->Text = "Capitulo 6: El Ultimo Combate:\n La Victoria del Guardián Renovado, Terrakor se levantó, llevando consigo la furia de la naturaleza.\n Con un rugido que sacudió la tierra, invocó la furia del bosque, desatando un torrente de energía\n  que purificó el aire y destruyó las fuerzas oscuras de Zolghar, Taurus y Minnor. Las raíces del bosque\n atraparon a los tres enemigos, mientras el fuego de Minnor fue extinguido por las aguas de la tierra.\n Con un golpe final, Terrakor destruyó la fuente de la corrupción y restauró el equilibrio,\n expulsando la oscuridad del Bosque de Teralin. La paz regresó, y el bosque, ahora más fuerte que nunca,\n fue restaurado a su antigua gloria.\n";
			   this->lblCapitulo6->Click += gcnew System::EventHandler(this, &PantallaHistoria::lblCapitulo6_Click);
			   // 
			   // PantallaHistoria
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1457, 776);
			   this->Controls->Add(this->pnlCapitulo6);
			   this->Controls->Add(this->pnlCapitulo5);
			   this->Controls->Add(this->pnlCapitulo4);
			   this->Controls->Add(this->pnlCapitulo3);
			   this->Controls->Add(this->pnlCapitulo2);
			   this->Controls->Add(this->btnSalir);
			   this->Controls->Add(this->pnlCapitulo1);
			   this->Controls->Add(this->btnCapitulo6);
			   this->Controls->Add(this->btnCapitulo5);
			   this->Controls->Add(this->btnCapitulo4);
			   this->Controls->Add(this->btnCapitulo3);
			   this->Controls->Add(this->btnCapitulo2);
			   this->Controls->Add(this->btnCapitulo1);
			   this->Name = L"PantallaHistoria";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"PantallaHistoria";
			   this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &PantallaHistoria::PantallaHistoria_Paint);
			   this->pnlCapitulo1->ResumeLayout(false);
			   this->pnlCapitulo1->PerformLayout();
			   this->pnlCapitulo2->ResumeLayout(false);
			   this->pnlCapitulo2->PerformLayout();
			   this->pnlCapitulo3->ResumeLayout(false);
			   this->pnlCapitulo3->PerformLayout();
			   this->pnlCapitulo4->ResumeLayout(false);
			   this->pnlCapitulo4->PerformLayout();
			   this->pnlCapitulo5->ResumeLayout(false);
			   this->pnlCapitulo5->PerformLayout();
			   this->pnlCapitulo6->ResumeLayout(false);
			   this->pnlCapitulo6->PerformLayout();
			   this->ResumeLayout(false);

		   }
#pragma endregion
	private: System::Void btnSalir_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		if (BotonSalir != nullptr) {
			e->Graphics->DrawImage(BotonSalir, 0, 0, btnSalir->Width, btnSalir->Height);
		}
	}
	private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void PantallaHistoria_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		if (FondoHistoria != nullptr) {
			e->Graphics->DrawImage(FondoHistoria, 0, 0, this->ClientSize.Width, this->ClientSize.Height);
		}
	}
	private: System::Void btnCapitulo1_Click(System::Object^ sender, System::EventArgs^ e) {

		pnlCapitulo2->Visible = false;
		pnlCapitulo3->Visible = false;
		pnlCapitulo4->Visible = false;
		pnlCapitulo5->Visible = false;
		pnlCapitulo6->Visible = false;

		pnlCapitulo1->Visible = true;
	}
	private: System::Void btnCapitulo2_Click(System::Object^ sender, System::EventArgs^ e) {
		pnlCapitulo1->Visible = false;
		pnlCapitulo3->Visible = false;
		pnlCapitulo4->Visible = false;
		pnlCapitulo5->Visible = false;
		pnlCapitulo6->Visible = false;

		pnlCapitulo2->Visible = true;
	}
	private: System::Void btnCapitulo3_Click(System::Object^ sender, System::EventArgs^ e) {
		pnlCapitulo1->Visible = false;
		pnlCapitulo2->Visible = false;
		pnlCapitulo4->Visible = false;
		pnlCapitulo5->Visible = false;
		pnlCapitulo6->Visible = false;

		pnlCapitulo3->Visible = true;
	}
	private: System::Void btnCapitulo4_Click(System::Object^ sender, System::EventArgs^ e) {
		pnlCapitulo1->Visible = false;
		pnlCapitulo2->Visible = false;
		pnlCapitulo3->Visible = false;
		pnlCapitulo5->Visible = false;
		pnlCapitulo6->Visible = false;

		pnlCapitulo4->Visible = true;
	}
	private: System::Void btnCapitulo5_Click(System::Object^ sender, System::EventArgs^ e) {
		pnlCapitulo1->Visible = false;
		pnlCapitulo2->Visible = false;
		pnlCapitulo3->Visible = false;
		pnlCapitulo4->Visible = false;
		pnlCapitulo6->Visible = false;

		pnlCapitulo5->Visible = true;
	}
	private: System::Void btnCapitulo6_Click(System::Object^ sender, System::EventArgs^ e) {
		pnlCapitulo1->Visible = false;
		pnlCapitulo2->Visible = false;
		pnlCapitulo3->Visible = false;
		pnlCapitulo4->Visible = false;
		pnlCapitulo5->Visible = false;

		pnlCapitulo6->Visible = true;
	}
	private: System::Void lblCapitulo6_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}