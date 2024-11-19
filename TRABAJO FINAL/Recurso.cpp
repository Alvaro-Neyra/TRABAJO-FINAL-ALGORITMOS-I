#include "Recurso.h"


Recurso::Recurso(int x, int y, int ancho, int alto) {
	this->x = x;
	this->y = y;
	this->ancho = ancho;
	this->alto = alto;
	this->visibilidad = true;
	this->indiceX = 0;
	this->indiceY = 0;
}

Recurso::~Recurso() {

}

int Recurso::obtenerX() {
	return this->x;
}

int Recurso::obtenerY() {
	return this->y;
}

int Recurso::obtenerAncho() {
	return this->ancho;
}

int Recurso::obtenerAlto() {
	return this->alto;
}

void Recurso::setX(int x) {
	this->x = x;
}

void Recurso::setY(int y) {
	this->y = y;
}

void Recurso::setAncho(int ancho) {
	this->ancho = ancho;
}

void Recurso::setAlto(int alto) {
	this->alto = alto;
}

void Recurso::setVisibilidad(bool _visibilidad) {
	this->visibilidad = _visibilidad;
}

bool Recurso::getVisibilidad() {
	return this->visibilidad;
}

Rectangle Recurso::obtenerRectangulo() {
	return Rectangle(x, y, ancho * escala, alto * escala);
}

Rectangle Recurso::areaDeRecogida() {
	return Rectangle(x + (ancho * escala / 2) - ((ancho * escala * 1.1) / 2), y + (alto * escala / 2) - ((alto * escala * 1.1) / 2), ancho * escala * 1.1, alto * escala * 1.1);
}