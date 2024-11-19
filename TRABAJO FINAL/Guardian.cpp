#include "Guardian.h"


Guardian::Guardian(int ancho, int alto) {
	this->ancho = ancho;
	this->alto = alto;
	this->vida = 3;
	this->x = 70;
	this->y = 70;
	this->dx = 10;
	this->dy = 10;
	this->indiceX = 0;
	this->indiceY = 2;
	this->direccion = 'S';
	this->arma = 1;
	this->salud = 100;
	this->atacando = false;
	this->recogerRecurso = false;
	this->cantidadDeAgua = false;
	this->cantidadDeSemillas = false;
	this->cantidadDeResiduosReciclables = false;
	this->resistenciaZombieTierra = 20;
	this->germinarPlanta = false;
	this->vidaAnterior = -1;
	this->cantidadFlechas = 30;
	this->vidaMaxima = 3;
}

Guardian::~Guardian() {

}

void Guardian::volverALaPosicionInicial() {
	this->x = 70;
	this->y = 70;
}

void Guardian::dibujar(Graphics^ panel, Bitmap^ guardianImagen) {
	Rectangle seccionAMostrar = Rectangle(indiceX * ancho - 5, indiceY * alto, ancho, alto);
	Rectangle areaADibujar = Rectangle(x, y, ancho, alto);
	panel->DrawImage(guardianImagen, areaADibujar, seccionAMostrar, GraphicsUnit::Pixel);
}

void Guardian::mover(Graphics^ panel, char tecla) {
	this->atacando = false;
	this->recogerRecurso = false;

	switch (tecla) {
		case 'W':
			if (y > 0) {
				y -= dy;
				direccion = 'W';
				indiceY = 0;
			}
			break;
		case 'S':
			if (y + alto < panel->VisibleClipBounds.Height) {
				y += dy;
				direccion = 'S';
				indiceY = 2;
			}
			break;
		case 'A':
			if (x > 0) {
				x -= dx;
				direccion = 'A';
				indiceY = 1;
			}
			break;
		case 'D':
			if (x + ancho < panel->VisibleClipBounds.Width) {
				x += dx;
				direccion = 'D';
				indiceY = 3;
			}
			break;
	}

	indiceX++;
	if (indiceX > 8) indiceX = 0;
}

int Guardian::obtenerX() {
	return this->x;
}

int Guardian::obtenerY() {
	return this->y;
}

int Guardian::obtenerXAnchoMitad() {
	return this->x + (ancho / 2);
}
int Guardian::obtenerYAltoMitad() {
	return this->y + (alto / 2);
}

char Guardian::obtenerDireccion() {
	return this->direccion;
}

void Guardian::setX(int x) {
	this->x = x;
}
void Guardian::setY(int y) {
	this->y = y;
}

void Guardian::aumentarSalud(int cantidad) {
	this->salud += cantidad;
	if (this->salud > 100) {
		this->salud = 100;
	}
}

int Guardian::obtenerSalud() {
	return this->salud;
}

void Guardian::setVidas(int cantidad) {
	this->vidaAnterior = this->vida;
	this->vida = cantidad;
}

void Guardian::setSalud(int cantidad) {
	this->vida = cantidad;
	if (this->vida > this->vidaMaxima) {
		this->vida = this->vidaMaxima;
	}
	if (this->vida < 0) {
		this->vida = 0;
	}
}

Rectangle Guardian::obtenerRectangulo() {
	return Rectangle(x, y, ancho, alto);
}

void Guardian::setArma(int _arma) {
	this->arma = _arma;
}

int Guardian::getArma() {
	return this->arma;
}

void Guardian::setAtacando(bool _atacando) {
	this->atacando = _atacando;
}

bool Guardian::obtenerAtacando() {
	return this->atacando;
}

void Guardian::setGerminarPlanta(bool _germinar) {
	this->germinarPlanta = _germinar;
}

bool Guardian::obtenerGerminarPlanta() {
	return this->germinarPlanta;
}

Proyectil* Guardian::disparar(int ancho, int alto) {
	return new Arco(obtenerXAnchoMitad(), obtenerYAltoMitad(), ancho, alto, direccion);
}

void Guardian::aumentarVidas(int cantidad) {
	this->vida += cantidad;
	if (this->vida > this->vidaMaxima) {
		this->vida = this->vidaMaxima;
	}
}
void Guardian::disminuirVidas(int cantidad) {
	this->vidaAnterior = this->vida;
	vida = max(0, vida - cantidad);
	if (vida == 0) {
		salud = 0;
	}
}


int Guardian::obtenerVidas() {
	return this->vida;
}

void Guardian::setRecogerRecurso(bool _recogerRecurso) {
	this->recogerRecurso = _recogerRecurso;
}

bool Guardian::obtenerRecogerRecurso() {
	return this->recogerRecurso;
}

void Guardian::aumentarSemillas(int cantidad) {
	this->cantidadDeSemillas += cantidad;
}
void Guardian::disminuirSemillas(int cantidad) {
	this->cantidadDeSemillas -= cantidad;
}
void Guardian::setCantidadSemillas(int _semillas) {
	this->cantidadDeSemillas = _semillas;
}
int Guardian::obtenerCantidadSemillas() {
	return this->cantidadDeSemillas;
}
void Guardian::aumentarResiduosReciclables(int _cantidad) {
	this->cantidadDeResiduosReciclables += _cantidad;
}
void Guardian::setCantidadResiduosReciclables(int _residuos) {
	this->cantidadDeResiduosReciclables = _residuos;
}
int Guardian::obtenerCantidadResiduosReciclables() {
	return this->cantidadDeResiduosReciclables;
}
void Guardian::aumentarAgua(int cantidad) {
	this->cantidadDeAgua += cantidad;
}
void Guardian::setCantidadDeAgua(int cantidadDeAgua) {
	this->cantidadDeAgua = cantidadDeAgua;
}
int Guardian::obtenerCantidadDeAgua() {
	return this->cantidadDeAgua;
}

void Guardian::disminuirAgua(int cantidad) {
	this->cantidadDeAgua -= cantidad;
	if (this->cantidadDeAgua <= 0) {
		this->cantidadDeAgua = 0;
	}
}

void Guardian::disminuirResistenciaZombie() {
	this->resistenciaZombieTierra--;
}

int Guardian::obtenerResistenciaZombie() {
	return this->resistenciaZombieTierra;
}

void Guardian::setResistenciaZombie(int cantidad) {
	this->resistenciaZombieTierra = cantidad;
}

bool Guardian::cambioVida() {
	if (vidaAnterior != vida) {
		vidaAnterior = vida;
		return true;
	}
	return false;
}

void Guardian::setCantidadFlechas(int _cantidad) {
	this->cantidadFlechas = _cantidad;
}
void Guardian::disminuirCantidadFlechas(int _cantidad) {
	this->cantidadFlechas -= _cantidad;
	if (cantidadFlechas < 0) {
		cantidadFlechas = 0;
	}
}
int Guardian::obtenerCantidadFlechas() {
	return this->cantidadFlechas;
}

void Guardian::generarFlechas() {
	if (cantidadDeResiduosReciclables >= 1) {
		cantidadFlechas = 20;
		cantidadDeResiduosReciclables -= 1;
	}
}

void Guardian::reducirSalud(int cantidad) {
	salud = max(0, salud - cantidad);

	if (salud == 0 && vida > 0) {
		disminuirVidas(1);
		if (vida > 0) {
			salud = 100;
		}
	}
}