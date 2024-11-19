#include "Aliado.h"

Aliado::Aliado(int ancho, int alto) {
	this->ancho = ancho;
	this->alto = alto;
	this->dx = 20;
	this->dy = 20;
	this->indiceX = 0;
	this->indiceY = 0;
	this->visibilidad = true;
}

Aliado::~Aliado() {

}

void Aliado::dibujar(Graphics^ panel, Bitmap^ imagenAliado) {
	Rectangle seccionAMostrar = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
	Rectangle areaADibujar = Rectangle(x, y, ancho, alto);
	panel->DrawImage(imagenAliado, areaADibujar, seccionAMostrar, GraphicsUnit::Pixel);
}

void Aliado::setVisibilidad(bool visibilidad) {
	this->visibilidad = visibilidad;
}

bool Aliado::getVisibilidad() {
	return this->visibilidad;
}

Rectangle Aliado::obtenerRectangulo() {
	return Rectangle(x, y, ancho, alto);
}

void Aliado::setX(int x) {
	this->x = x;
}

void Aliado::setY(int y) {
	this->y = y;
}