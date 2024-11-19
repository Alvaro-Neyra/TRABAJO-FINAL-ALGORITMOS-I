#include "Enemigo.h"


Enemigo::Enemigo(int ancho, int alto) {
	this->ancho = ancho;
	this->alto = alto;
	this->x = rand() % 900;
	this->y = rand() % 200;
	this->dx = 30;
	this->dy = 30;
	this->vida = 100;
	this->visibilidad = true;
	this->indiceX = 0;
	this->indiceY = 0;
	this->escala = 1.00;
}

Enemigo::~Enemigo() {

}

void Enemigo::setX(int x) {
	this->x = x;
}

void Enemigo::setY(int y) {
	this->y = y;
}

void Enemigo::setVida(int cantidad) {
	this->vida = 100;
}

int Enemigo::getVida() {
	return this->vida;
}

void Enemigo::setVisibilidad(bool _visibilidad) {
	this->visibilidad = _visibilidad;
}
bool Enemigo::getVisibilidad() {
	return this->visibilidad;
}

int Enemigo::obtenerXAnchoMitad() {
	return this->x + (ancho / 2);
}
int Enemigo::obtenerYAltoMitad() {
	return this->y + (alto / 2);
}

void Enemigo::reducirVida(int cantidad) {
	this->vida -= cantidad;
}

Rectangle Enemigo::obtenerRectangulo() {
	return Rectangle(x, y, ancho * escala, alto * escala);
}