#include "Agua.h"
#include <iostream>

Agua::Agua(int x, int y, int ancho, int alto) 
	: Recurso(x, y, ancho, alto)
{
	this->cantidad = rand() % 100 + 1;
	this->escala = 0.9;
}

Agua::~Agua() {

}

int Agua::obtenerCantidad() {
	return this->cantidad;
}

void Agua::dibujar(Graphics^ panel, Bitmap^ imagen) {
	panel->DrawImage(imagen, static_cast<float>(x), static_cast<float>(y), static_cast<float>(ancho * escala), static_cast<float>(alto * escala));
}
