#include "Juego.h"
#include <cassert>

using namespace System;
using namespace System::Windows::Forms;

Juego::Juego() {
	srand(time(NULL));
	this->nivel = nivel;
	cantidadAliados = rand() % 3 + 1; // Entre 1 y 3
	cantidadEnemigos = rand() % 6 + 3;
	cantidadRecursos = rand() % 5 + 1;
	this->contaminacion = 0;
	enemigosDerrotados = 0;
	enemigoAireDerrotados = 0;
	enemigoTierraDerrotados = 0;
	enemigoFuegoDerrotados = 0;
	recursosRecolectados = 0;
	aguaTotalRecogida = 0;
	papelTotalRecogida = 0;
	semillasTotalRecogida = 0;
	nivelUltimoAlcanzado = 0;
	archivoPuntaje = new ArchivoPuntaje("datos/puntaje.txt");
	cargarPuntaje();
}

Juego::~Juego() {
	delete guardian;
	for (Proyectil* proyectil : proyectiles) {
		delete proyectil;
	}
	proyectiles.clear();
}

void Juego::crearAliados(int ancho, int alto, Graphics^ panel) {
	for (int i = 0; i < cantidadAliados; i++) {
		tipoAliado = rand() % 2 + 1;
		switch (tipoAliado) {
			// AliadoAtacar
			case 1: {
				AliadoAtacar* aliado = new AliadoAtacar(ancho, alto);
				int x, y;
				do {
					x = rand() % (int)(panel->VisibleClipBounds.Width - ancho);
					y = rand() % (int)(panel->VisibleClipBounds.Height - alto);
				} while (guardian->obtenerRectangulo().IntersectsWith(Rectangle(x, y, ancho, alto)));
				aliado->setX(x);
				aliado->setY(y);
				agregarAliado(aliado);
				break;
			}
			// AliadoVida
			case 2: {
				AliadoVida* aliadoVida = new AliadoVida(ancho, alto);
				int x, y;
				do {
					x = rand() % (int)(panel->VisibleClipBounds.Width - ancho);
					y = rand() % (int)(panel->VisibleClipBounds.Height - alto);
				} while (guardian->obtenerRectangulo().IntersectsWith(Rectangle(x, y, ancho, alto)));
				aliadoVida->setX(x);
				aliadoVida->setY(y);
				agregarAliado(aliadoVida);
				break;
			}
		}
	}
}

void Juego::crearEnemigos(int ancho, int alto, Graphics^ panel) {
	switch (nivel) {
		case 1:
			cantidadEnemigos = rand() % 3 + 1;
			for (int i = 0; i < cantidadEnemigos; i++) {
				AireToroDeGuerra* nuevoAireToro = new AireToroDeGuerra(ancho, alto);
				int x, y;
				do {
					x = rand() % (int)(panel->VisibleClipBounds.Width - ancho);
					y = rand() % (int)(panel->VisibleClipBounds.Height - alto);
				} while (guardian->obtenerRectangulo().IntersectsWith(Rectangle(x, y, ancho, alto)));
				nuevoAireToro->setX(x);
				nuevoAireToro->setY(y);
				enemigos.push_back(nuevoAireToro);
				ajustarContaminacion(5, false);
			}
			break;
		case 2: {
			TierraZombie* nuevoZombie = new TierraZombie(ancho, alto);
			int x, y;
			do {
				x = rand() % (int)(panel->VisibleClipBounds.Width - ancho);
				y = rand() % (int)(panel->VisibleClipBounds.Height - alto);
			} while (guardian->obtenerRectangulo().IntersectsWith(Rectangle(x, y, ancho, alto)));

			nuevoZombie->setX(x);
			nuevoZombie->setY(y);
			agregarEnemigo(nuevoZombie);
			ajustarContaminacion(5, false);
			break;
		}
		case 3:
			cantidadEnemigos = rand() % 2 + 1;
			for (int i = 0; i < cantidadEnemigos; i++) {
				enemigos.push_back(new FuegoMinotauro(ancho, alto, rand() % 2));
				ajustarContaminacion(5, false);
			}
			break;
		case 4: {
			cantidadEnemigos = rand() % 2 + 1;
			for (int i = 0; i < cantidadEnemigos; i++) {
				AireToroDeGuerra* nuevoAireToro = new AireToroDeGuerra(ancho, alto);
				int x, y;
				do {
					x = rand() % (int)(panel->VisibleClipBounds.Width - ancho);
					y = rand() % (int)(panel->VisibleClipBounds.Height - alto);
				} while (guardian->obtenerRectangulo().IntersectsWith(Rectangle(x, y, ancho, alto)));
				nuevoAireToro->setX(x);
				nuevoAireToro->setY(y);
				agregarEnemigo(nuevoAireToro);
				ajustarContaminacion(5, false);
			}
			cantidadEnemigos = rand() % 3 + 1;
			for (int i = 0; i < cantidadEnemigos; i++) {
				TierraZombie* nuevoZombie = new TierraZombie(ancho, alto);
				int x, y;
				do {
					x = rand() % (int)(panel->VisibleClipBounds.Width - ancho);
					y = rand() % (int)(panel->VisibleClipBounds.Height - alto);
				} while (guardian->obtenerRectangulo().IntersectsWith(Rectangle(x, y, ancho, alto)));
				nuevoZombie->setX(x);
				nuevoZombie->setY(y);
				agregarEnemigo(nuevoZombie);
				ajustarContaminacion(5, false);
			}
			cantidadEnemigos = rand() % 1 + 1;
			for (int i = 0; i < cantidadEnemigos; i++) {
				FuegoMinotauro* nuevoMinotauro = new FuegoMinotauro(ancho, alto, rand() % 2);
				int x, y;
				do {
					x = rand() % (int)(panel->VisibleClipBounds.Width - ancho);
					y = rand() % (int)(panel->VisibleClipBounds.Height - alto);
				} while (guardian->obtenerRectangulo().IntersectsWith(Rectangle(x, y, ancho, alto)));
				nuevoMinotauro->setX(x);
				nuevoMinotauro->setY(y);
				agregarEnemigo(nuevoMinotauro);
				ajustarContaminacion(5, false);
			}
			break;
		}
	}
}

void Juego::plantar(Bitmap^ imagenPlanta) {
	Semilla* nuevaSemilla = new Semilla(guardian->obtenerX(), guardian->obtenerY(), (imagenPlanta->Width / 8) - 1, imagenPlanta->Height);
	nuevaSemilla->germinar();
	nuevaSemilla->setPlantado(true);
	plantasPlantadas.push_back(nuevaSemilla);
	ajustarContaminacion(10, true);
}

void Juego::crearRecursos(Graphics^ panel, Bitmap^ imagenPlanta, Bitmap^ imagenAgua, Bitmap^ imagenResiduosReciclables) {
	cantidadRecursos = rand() % 5 + 1;

	int contadorSemillas = 0;
	int contadorResiduosReciclables = 0;
	int contadorAgua = 0;


	for (int i = 0; i < cantidadRecursos; i++) {
		int tipoDeRecurso;
		do {
			tipoDeRecurso = rand() % 3;
		} while ((nivel == 1 || nivel == 2) && tipoDeRecurso == 2);

		int ancho, alto;
		switch (tipoDeRecurso) {
		case 0:
			ancho = (imagenPlanta->Width / 8 - 1);
			alto = (imagenPlanta->Height);
			contadorSemillas++;
			break;
		case 1:
			ancho = (imagenResiduosReciclables->Width / 2);
			alto = (imagenResiduosReciclables->Height / 2);
			contadorResiduosReciclables++;
			break;
		case 2:
			ancho = imagenAgua->Width * 0.09;
			alto = imagenAgua->Height * 0.09;
			contadorAgua++;
			break;
		}

		int x, y;
		bool colisiona;
		do {
			colisiona = false;
			x = rand() % (int)(panel->VisibleClipBounds.Width - ancho);
			y = rand() % (int)(panel->VisibleClipBounds.Height - alto);

			Rectangle nuevoRectangulo = Rectangle(x, y, ancho, alto);

			if (guardian->obtenerRectangulo().IntersectsWith(nuevoRectangulo)) {
				colisiona = true;
			}

			for each (Enemigo * enemigo in enemigos) {
				if (enemigo->obtenerRectangulo().IntersectsWith(nuevoRectangulo)) {
					colisiona = true;
					break;
				}
			}

			for each (Aliado * aliado in aliados) {
				if (aliado->obtenerRectangulo().IntersectsWith(nuevoRectangulo)) {
					colisiona = true;
					break;
				}
			}

			for each (Recurso * recurso in recursos) {
				if (recurso->obtenerRectangulo().IntersectsWith(nuevoRectangulo)) {
					colisiona = true;
					break;
				}
			}
		} while (colisiona);

		switch (tipoDeRecurso) {
			case 0: {
				Semilla* nuevaSemilla = new Semilla(x, y, ancho, alto);
				recursos.push_back(nuevaSemilla);
				break;
			}
			case 1: {// Residuos Reciclables
				ResiduosReciclables* nuevosResiduos = new ResiduosReciclables(x, y, ancho, alto, rand() % 4 + 1); // Tipo aleatorio
				recursos.push_back(nuevosResiduos);
				ajustarContaminacion(5, false);
				break;
			}
			case 2: {// Agua
				Agua* nuevaAgua = new Agua(x, y, ancho, alto);
				recursos.push_back(nuevaAgua);
				break;
			}
		}
	}
}



void Juego::agregarRecurso(Recurso* recurso) {
	if (Semilla* nuevaSemilla = dynamic_cast<Semilla*>(recurso)) {
		guardian->aumentarSemillas(1);
		semillasTotalRecogida++;
	}
	else if (ResiduosReciclables* residuosReciclables = dynamic_cast<ResiduosReciclables*>(recurso)) {
		guardian->aumentarResiduosReciclables(1);
		papelTotalRecogida++;
	}
	else if (Agua* agua = dynamic_cast<Agua*>(recurso)) {
		guardian->aumentarAgua(1);
		aguaTotalRecogida++;
	}
}

void Juego::agregarEnemigo(Enemigo* enemigo) {
	enemigos.push_back(enemigo);
}

void Juego::agregarAliado(Aliado* aliado) {
	aliados.push_back(aliado);
}

void Juego::agregarBolaDeFuego(BolaDeFuego* bola) {
	proyectiles.push_back(bola);
}

void Juego::agregarArco(Arco* arco) {
	if (guardian->obtenerCantidadFlechas() > 0)
	{
		proyectiles.push_back(arco);
		guardian->disminuirCantidadFlechas(1);
	}
}

void Juego::dibujarTodo(Graphics^ panel,Bitmap^ imagenGuardian, Bitmap^ imagenEnemigoFuego, Bitmap^ imagenEnemigoTierra, Bitmap^ imagenEnemigoAire, Bitmap^ imagenArco, Bitmap^ imagenBolaDeFuego, Bitmap^ imagenAliadoVida, Bitmap^ imagenAliadoAtacar, Bitmap^ imagenSemilla, Bitmap^ imagenResiduosReciclables, Bitmap^ imagenAgua) {
	guardian->dibujar(panel, imagenGuardian);

	for each (Recurso * recurso in recursos) {
		if (dynamic_cast<Semilla*>(recurso)) {
			recurso->dibujar(panel, imagenSemilla);
		}
		else if (dynamic_cast<ResiduosReciclables*>(recurso)) {
			recurso->dibujar(panel, imagenResiduosReciclables);
		}
		else if (dynamic_cast<Agua*>(recurso)) {
			recurso->dibujar(panel, imagenAgua);
		}
	}

	for each (Enemigo* enemigo in enemigos) {
		if (dynamic_cast<AireToroDeGuerra*>(enemigo)) {
			enemigo->dibujar(panel, imagenEnemigoAire);
		}
		else if (dynamic_cast<FuegoMinotauro*>(enemigo)) {
			enemigo->dibujar(panel, imagenEnemigoFuego);
		}
		else if (dynamic_cast<TierraZombie*>(enemigo)) {
			enemigo->dibujar(panel, imagenEnemigoTierra);
		}
	}

	for each (Proyectil* proyectil in proyectiles) {
		if (dynamic_cast<BolaDeFuego*>(proyectil)) {
			proyectil->dibujar(panel, imagenBolaDeFuego);
		}
		else if (dynamic_cast<Arco*>(proyectil)) {
			proyectil->dibujar(panel, imagenArco);
		}
	}

	for each (Aliado * aliado in aliados) {
		if (dynamic_cast<AliadoVida*>(aliado)) {
			aliado->dibujar(panel, imagenAliadoVida);
		}
		else if (dynamic_cast<AliadoAtacar*>(aliado)) {
			aliado->dibujar(panel, imagenAliadoAtacar);
		}
	}

	for each (Semilla * semilla in plantasPlantadas) {
		semilla->dibujar(panel, imagenSemilla);
	}
}

void Juego::colisionar(Graphics^ panel) {
	// Colision de los recursos
	for (int r = 0; r < recursos.size(); r++) {
		if (recursos[r]->areaDeRecogida().IntersectsWith(guardian->obtenerRectangulo()) && guardian->obtenerRecogerRecurso()) {
			agregarRecurso(recursos[r]);
			recursos[r]->setVisibilidad(false);
			ajustarContaminacion(5, true);
			recursosRecolectados++;
		}
	}

	for (int p = 0; p < plantasPlantadas.size(); p++) {
		if (plantasPlantadas[p]->obtenerRectangulo().IntersectsWith(guardian->obtenerRectangulo()) && guardian->obtenerCantidadDeAgua() > 0 && guardian->obtenerGerminarPlanta()) {
			if (plantasPlantadas[p]->obtenerQuemado()) {
				plantasPlantadas[p]->setQuemado(false);
				plantasPlantadas[p]->germinar();
				ajustarContaminacion(10, true);
				guardian->disminuirAgua(1);
			}
			else {
				plantasPlantadas[p]->avanzarEtapa();
			}
		}
	}

	// Colision de los enemigos
	for (int i = 0; i < enemigos.size(); i++) {
		for (int j = 0; j < proyectiles.size(); j++) {
			if (dynamic_cast<Arco*>(proyectiles[j])) {
				if (enemigos[i]->obtenerRectangulo().IntersectsWith(proyectiles[j]->obtenerRectangulo())) {
					if (dynamic_cast<AireToroDeGuerra*>(enemigos[i]) && nivel == 4) {
						enemigos[i]->setVisibilidad(false);
						proyectiles[j]->setVisibilidad(false);
						ajustarContaminacion(5, true);
						enemigoAireDerrotados++;
					}
					else {
						enemigos[i]->reducirVida(50);
						proyectiles[j]->setVisibilidad(false);
						ajustarContaminacion(5, true);
						enemigoAireDerrotados++;
					}

					if (dynamic_cast<TierraZombie*>(enemigos[i])) {
						enemigoTierraDerrotados++;
					}

					if (dynamic_cast<FuegoMinotauro*>(enemigos[i])) {
						enemigoFuegoDerrotados++;
					}
					enemigosDerrotados++;
				}
			}
		}
	}

	// Colision de los proyectiles
	for (int j = 0; j < proyectiles.size(); j++) {
		if (dynamic_cast<Arco*>(proyectiles[j])) {
			if (proyectiles[j]->obtenerX() <= 0 || proyectiles[j]->obtenerXAncho() >= panel->VisibleClipBounds.Width ||
				proyectiles[j]->obtenerY() <= 0 || proyectiles[j]->obtenerYAlto() >= panel->VisibleClipBounds.Height) {
				proyectiles[j]->setVisibilidad(false);
			}
		}
		else if (dynamic_cast<BolaDeFuego*>(proyectiles[j])) {
			if (proyectiles[j]->obtenerRectangulo().IntersectsWith(guardian->obtenerRectangulo())) {
				proyectiles[j]->setVisibilidad(false);
				if (nivel == 4) {
					guardian->reducirSalud(10);
				}
				else {
					guardian->reducirSalud(20);
				}
			}

			for (int i = 0; i < plantasPlantadas.size(); i++) {
				if (proyectiles[j]->obtenerRectangulo().IntersectsWith(plantasPlantadas[i]->obtenerRectangulo())) {
					if (!plantasPlantadas[i]->obtenerQuemado()) {
						plantasPlantadas[i]->quemarPlanta();
						plantasPlantadas[i]->setQuemado(true);
						ajustarContaminacion(10, false);
					}
				}
			}
		}
	}

	// Si chocan los enemigos de aire con el guardian invierten su direccion y le bajan vida, igualmente con el de zombie tierra;
	for (int i = 0; i < enemigos.size(); i++) {
		if (AireToroDeGuerra* toro = dynamic_cast<AireToroDeGuerra*>(enemigos[i])) {
			// restar vida al guardian
			if (toro->obtenerRectangulo().IntersectsWith(guardian->obtenerRectangulo())) {
				toro->invertirDireccion();
				if (nivel == 4) {
					guardian->reducirSalud(5);
				}
				else {
					guardian->reducirSalud(10);
				}
			}
		}
		if (TierraZombie* zombie = dynamic_cast<TierraZombie*>(enemigos[i])) {
			if (zombie->obtenerRectangulo().IntersectsWith(guardian->obtenerRectangulo())) {
				guardian->disminuirResistenciaZombie();
				if (guardian->obtenerResistenciaZombie() <= 0) {
					guardian->setResistenciaZombie(20);
					zombie->setVisibilidad(false);
					if (nivel == 4) {
						guardian->reducirSalud(5);
					}
					else {
						guardian->reducirSalud(10);
					}
				}
			}

			for (int i = 0; i < plantasPlantadas.size(); i++) {
				if (zombie->obtenerRectangulo().IntersectsWith(plantasPlantadas[i]->obtenerRectangulo())) {
					plantasPlantadas[i]->disminuirVida(10);
					if (plantasPlantadas[i]->obtenerVida() <= 0) {
						plantasPlantadas[i]->setVisibilidad(false);
						zombie->setVisibilidad(false);
						ajustarContaminacion(5, false);
					}
				}
			}
		}
	}

	// Colision de los aliados
	for (int a = 0; a < aliados.size(); a++) {
		if (AliadoVida* aliado = dynamic_cast<AliadoVida*>(aliados[a])) {
			// Aumentar vida a guardian
			if (aliado->obtenerRectangulo().IntersectsWith(guardian->obtenerRectangulo())) {
				if (nivel == 4) {
					guardian->aumentarSalud(80);
				}
				else {
					guardian->aumentarSalud(50);
				}
				aliado->setVisibilidad(false);
			}
		}

		if (AliadoAtacar* aliadoAtacar = dynamic_cast<AliadoAtacar*>(aliados[a])) {
			for (int i = 0; i < enemigos.size(); i++) {
				if (aliadoAtacar->obtenerRectangulo().IntersectsWith(enemigos[i]->obtenerRectangulo())) {
					aliadoAtacar->setVisibilidad(false);
					enemigos[i]->setVisibilidad(false);
				}
			}
		}
	}

	for (int i = 0; i < enemigos.size(); i++) {
		if (!enemigos[i]->getVisibilidad()) {
			enemigos.erase(enemigos.begin() + i);
		}
		else if (enemigos[i]->getVida() <= 0) {
			enemigos.erase(enemigos.begin() + i);
		}
	}

	for (int j = 0; j < proyectiles.size(); j++) {
		if (!proyectiles[j]->getVisibilidad()) {
			proyectiles.erase(proyectiles.begin() + j);
		}
	}

	for (int a = 0; a < aliados.size(); a++) {
		if (!aliados[a]->getVisibilidad()) {
			aliados.erase(aliados.begin() + a);
		}
	}

	for (int r = 0; r < recursos.size(); r++) {
		if (!recursos[r]->getVisibilidad()) {
			recursos.erase(recursos.begin() + r);
		}
	}

	for (int p = 0; p < plantasPlantadas.size(); p++) {
		if (!plantasPlantadas[p]->getVisibilidad()) {
			plantasPlantadas.erase(plantasPlantadas.begin() + p);
		}
	}
}

void Juego::moverTodo(Graphics^ panel) {
	for each (Enemigo * enemigo in enemigos) {
		enemigo->mover(panel);
	}

	for each (Proyectil * proyectil in proyectiles) {
		proyectil->mover(panel);
	}

	for each (Aliado * aliado in aliados) {
		aliado->mover(panel);
	}
}

void Juego::expandirProyectiles() {
	if (nivel == 3 || nivel == 4) {
		vector<BolaDeFuego*> nuevasBolasDeFuego;
		for (int i = 0; i < proyectiles.size(); i++) {
			BolaDeFuego* bola = dynamic_cast<BolaDeFuego*>(proyectiles[i]);
			if (bola && bola->verificarSeDetuvo() && !bola->verificarDividido()) {
				vector<BolaDeFuego*> nuevas = bola->dividir();
				nuevasBolasDeFuego.insert(nuevasBolasDeFuego.end(), nuevas.begin(), nuevas.end());
				proyectiles.erase(proyectiles.begin() + i);
				ajustarContaminacion(5, false);
			}
		}
		proyectiles.insert(proyectiles.end(), nuevasBolasDeFuego.begin(), nuevasBolasDeFuego.end());
	}
}

void Juego::actualizar() {
	if (nivel == 2 || nivel == 4) {
		for (int i = 0; i < enemigos.size(); i++) {
			if (TierraZombie* zombie = dynamic_cast<TierraZombie*>(enemigos[i])) {
				int objetivoX = guardian->obtenerX();
				int objetivoY = guardian->obtenerY();
				if (!plantasPlantadas.empty()) {
					int objetivo = rand() % 2;
					switch (objetivo) {
					case 0: {
						break;
					}
					case 1: {
						int plantaElegida = rand() % plantasPlantadas.size();
						objetivoX = plantasPlantadas[plantaElegida]->obtenerX();
						objetivoY = plantasPlantadas[plantaElegida]->obtenerY();
						break;
					}
					default:
						break;
					}
				}
				zombie->setObjetivo(objetivoX, objetivoY);
			}
		}
	}
}

void Juego::actualizarCrecimientoPlantas() {
	for (int i = 0; i < plantasPlantadas.size(); i++) {
		if (plantasPlantadas[i]->getPlantado() && !plantasPlantadas[i]->obtenerQuemado()) {
			ajustarContaminacion(plantasPlantadas[i]->getEtapa() * 3, true);
			plantasPlantadas[i]->avanzarEtapa();
		}

		if (plantasPlantadas[i]->obtenerQuemado()) {
			plantasPlantadas[i]->disminuirVida(100);
			ajustarContaminacion(10, false);
			if (plantasPlantadas[i]->obtenerVida() <= 0) {
				plantasPlantadas[i]->setVisibilidad(false);
			}
		}
	}
}

void Juego::crearGuardian(int ancho, int alto) {
	guardian = new Guardian(ancho, alto);
}

Guardian* Juego::obtenerGuardian() {
	return this->guardian;
}

void Juego::disparoAleatorio(int ancho, int alto) {
	vector<FuegoMinotauro*> minotauros;
	for (Enemigo* enemigo: enemigos) {
		if (FuegoMinotauro* minotauro = dynamic_cast<FuegoMinotauro*>(enemigo)) {
			minotauros.push_back(minotauro);
		}
	}

	if (minotauros.empty()) return;

	int indiceAleatorio = rand() % minotauros.size();

	FuegoMinotauro* minotaurioSeleccionado = minotauros[indiceAleatorio];

	int objetivoAleatorio = 0;

	int cantidadDePlantasQuemadas = 0;

	if (!plantasPlantadas.empty()) {
		objetivoAleatorio = rand() % 2;
	}

	for (int i = 0; i < plantasPlantadas.size(); i++) {
		if (plantasPlantadas[i]->obtenerQuemado()) {
			cantidadDePlantasQuemadas++;
		}
	}

	if (cantidadDePlantasQuemadas <= 0) {
		objetivoAleatorio = 0;
	}

	switch (objetivoAleatorio) {
		case 0: {
			BolaDeFuego* bola = minotaurioSeleccionado->lanzarBolaDeFuego(ancho, alto, guardian->obtenerX(), guardian->obtenerY());
			agregarBolaDeFuego(bola);
			ajustarContaminacion(4, false);
			break;
		}
		case 1: {
			int plantaAleatoria = rand() % plantasPlantadas.size();
			int objetivoPlantaX = plantasPlantadas[plantaAleatoria]->obtenerX();
			int objetivoPlantaY = plantasPlantadas[plantaAleatoria]->obtenerY();
			BolaDeFuego* bola = minotaurioSeleccionado->lanzarBolaDeFuego(ancho, alto, objetivoPlantaX, objetivoPlantaY);
			agregarBolaDeFuego(bola);
			ajustarContaminacion(4, false);
			break;
		}
		default:
			break;
	}
}

void Juego::reiniciarNivel(Graphics^ panel ,int tipoNivel, Bitmap^ imagenGuardian, Bitmap^ imagenEnemigo,Bitmap ^ imagenAliado) {
    this->nivel = tipoNivel;
    enemigos.clear();
    aliados.clear();
    proyectiles.clear();
    crearGuardian(imagenGuardian->Width, imagenGuardian->Height);                                                                                                                                                                                                                                                                                                                                                                                                                
    crearEnemigos(imagenEnemigo->Width, imagenEnemigo->Height, panel);
    crearAliados(imagenAliado->Width, imagenAliado->Height, panel);
}

bool Juego::puedePlantar(Bitmap^ imagenPlanta, Graphics^ panel) {
	int ancho = (imagenPlanta->Width / 8) - 1;
	int alto = imagenPlanta->Height;
	Rectangle rectPlanta(guardian->obtenerX(), guardian->obtenerY(), ancho, alto);

	if (rectPlanta.X < 0 || rectPlanta.Y < 0 ||
		rectPlanta.Right > panel->VisibleClipBounds.Width ||
		rectPlanta.Bottom > panel->VisibleClipBounds.Height) {
		return false;
	}

	for (Enemigo* enemigo : enemigos) {
		if (enemigo->obtenerRectangulo().IntersectsWith(rectPlanta)) return false;
	}
	for (Aliado* aliado : aliados) {
		if (aliado->obtenerRectangulo().IntersectsWith(rectPlanta)) return false;
	}
	for (Recurso* recurso : recursos) {
		if (recurso->obtenerRectangulo().IntersectsWith(rectPlanta)) return false;
	}

	return true;
}

void Juego::setNivel(int nivel) {
	this->nivel = nivel;
}

bool Juego::aliadosEliminados() {
	return this->aliados.empty();
}

bool Juego::recursosRecogidos() {
	return this->recursos.empty();
}

bool Juego::juegoTerminado() {
	assert((guardian->obtenerVidas() <= 0) == (guardian->obtenerSalud() <= 0));
	return guardian->obtenerVidas() <= 0;
}

void Juego::reiniciarJuego() {
	obtenerGuardian()->setSalud(100);
	obtenerGuardian()->setVidas(3);
	guardian->volverALaPosicionInicial();
}

void Juego::ajustarContaminacion(float porcentaje, bool esDescontaminacion) {
	int ajuste = (int)(porcentaje);

	if (esDescontaminacion) {
		contaminacion -= ajuste;
	}
	else {
		contaminacion += ajuste;
	}

	if (contaminacion < 0) contaminacion = 0;
	if (contaminacion > 100) contaminacion = 100;
}


int Juego::obtenerContaminacion() {
	int contaminacionBase = this->contaminacion;

	int contaminacionPorEnemigos = enemigos.size() * 5;

	int contaminacionPorPlantas = plantasPlantadas.size() * 2;

	int contaminacionPorResiduos = 0;
	for (Recurso* recurso : recursos) {
		if (dynamic_cast<ResiduosReciclables*>(recurso)) {
			contaminacionPorResiduos += 3;
		}
	}

	int contaminacionTotal = contaminacionBase + contaminacionPorEnemigos + contaminacionPorPlantas + contaminacionPorResiduos;

	if (contaminacionTotal > 100) contaminacionTotal = 100;

	return contaminacionTotal;
}

void Juego::ajustarDificultadEnemigos(int nivel) {
	for each (Enemigo * enemigo in enemigos) {
		if (nivel == 4) {
			enemigo->setVida(enemigo->getVida() / 2);
		}
	}
}

int Juego::obtenerCantidadEnemigosActuales() {
	return enemigos.size();
}

void Juego::guardarPuntaje() {
	archivoPuntaje->guardarDatos(&enemigosDerrotados,&enemigoAireDerrotados, &enemigoTierraDerrotados, &enemigoFuegoDerrotados, &papelTotalRecogida, &aguaTotalRecogida, &papelTotalRecogida, &semillasTotalRecogida, &nivelUltimoAlcanzado);
}

void Juego::cargarPuntaje() {
	archivoPuntaje->leerDatos(&enemigosDerrotados, &enemigoAireDerrotados, &enemigoTierraDerrotados, &enemigoFuegoDerrotados, &papelTotalRecogida, &aguaTotalRecogida, &papelTotalRecogida, &semillasTotalRecogida, &nivelUltimoAlcanzado);
}
int Juego::obtenerEnemigosDerrotados() {
	return enemigosDerrotados;
}

int Juego::obtenerEnemigoAireDerrotados() {
	return enemigoAireDerrotados;
}

int Juego::obtenerEnemigoTierraDerrotados() {
	return enemigoTierraDerrotados;
}

int Juego::obtenerEnemigoFuegoDerrotados() {
	return enemigoFuegoDerrotados;
}

int Juego::obtenerRecursosRecolectados() {
	return recursosRecolectados;
}

int Juego::obtenerAguaTotalRecogida() {
	return aguaTotalRecogida;
}

int Juego::obtenerPapelTotalRecogida() {
	return papelTotalRecogida;
}

int Juego::obtenerSemillasTotalRecogida() {
	return semillasTotalRecogida;
}

int Juego::obtenerNivelUltimoAlcanzado() {
	return nivelUltimoAlcanzado;
}

void Juego::setEnemigosDerrotados(int cantidad) {
	enemigosDerrotados = cantidad;
}

void Juego::setEnemigoAireDerrotados(int cantidad) {
	enemigoAireDerrotados = cantidad;
}

void Juego::setEnemigoTierraDerrotados(int cantidad) {
	enemigoTierraDerrotados = cantidad;
}

void Juego::setEnemigoFuegoDerrotados(int cantidad) {
	enemigoFuegoDerrotados = cantidad;
}

void Juego::setRecursosRecolectados(int cantidad) {
	recursosRecolectados = cantidad;
}

void Juego::setAguaTotalRecogida(int cantidad) {
	aguaTotalRecogida = cantidad;
}

void Juego::setPapelTotalRecogida(int cantidad) {
	papelTotalRecogida = cantidad;
}

void Juego::setSemillasTotalRecogida(int cantidad) {
	semillasTotalRecogida = cantidad;
}

void Juego::setNivelUltimoAlcanzado(int nivel) {
	nivelUltimoAlcanzado = nivel;
}

void Juego::actualizarEstadoGuardian() {
	if (guardian->obtenerSalud() <= 0) {
		if (guardian->obtenerVidas() > 0) {
			guardian->disminuirVidas(1);
			guardian->setSalud(100);
		}
	}
}
