#include "Proyectil.h"

Proyectil::Proyectil(int x, int y, int ancho, int alto) {
	this->x = x;
	this->y = y;
	this->ancho = ancho;
	this->alto = alto;
	this->visibilidad = true;
	this->dx = 30;
	this->dy = 30;
	this->escala = 1.00;
}

Proyectil::~Proyectil() {

}

void Proyectil::setVisibilidad(bool _visibilidad) {
	this->visibilidad = _visibilidad;
}

bool Proyectil::getVisibilidad() {
	return this->visibilidad;
}

int Proyectil::obtenerX() {
	return this->x;
}

int Proyectil::obtenerY() {
	return this->y;
}

void Proyectil::setDx(int dx) {
	this->dx = dx;
}

void Proyectil::setDy(int dy) {
	this->dy = dy;
}

int Proyectil::getDx() {
	return this->dx;
}

int Proyectil::getDy() {
	return this->dy;
}

int Proyectil::obtenerXAncho() {
	return this->x + ancho * escala;
}

int Proyectil::obtenerYAlto() {
	return this->y + alto * escala;
}

void Proyectil::setEscala(float escala) {
	this->escala = escala;
}

Rectangle Proyectil::obtenerRectangulo() {
	return Rectangle(x, y, ancho * escala, alto * escala);
}