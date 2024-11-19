#include "ResiduosReciclables.h"


ResiduosReciclables::ResiduosReciclables(int x, int y, int ancho, int alto, int tipo) 
	: Recurso(x, y, ancho, alto)
{
	this->tipo = tipo;
	this->escala = 0.5;
	this->indiceX = 0;
	this->indiceY = 0;
}

ResiduosReciclables::~ResiduosReciclables() {

}

int ResiduosReciclables::contaminar() {
	return rand() % 10 + 1;
}

void ResiduosReciclables::dibujar(Graphics^ panel, Bitmap^ imagen) {
	switch (tipo) {
	case 1: indiceX = 0; indiceY = 0; break;
	case 2: indiceX = 1; indiceY = 0; break;
	case 3: indiceX = 0; indiceY = 1; break;
	case 4: indiceX = 1; indiceY = 1; break;
	}


	Rectangle seccionAMostrar = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
	Rectangle areaADibujar = Rectangle(x, y, ancho * escala, alto * escala);
	panel->DrawImage(imagen, areaADibujar, seccionAMostrar, GraphicsUnit::Pixel);
}