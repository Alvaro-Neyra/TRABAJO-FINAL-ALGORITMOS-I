#include "AliadoVida.h"


AliadoVida::AliadoVida(int ancho, int alto) 
	:Aliado(ancho, alto)
{

}

AliadoVida::~AliadoVida() {

}

void AliadoVida::mover(Graphics^ panel) {
	if (x < 0 || x + ancho > panel->VisibleClipBounds.Width) {
		dx *= -1;
	}

	x += dx;

	if (dx > 0) {
		indiceY = 3;
	}
	else {
		indiceY = 1;
	}

	indiceX++;
	if (indiceX > 9) indiceX = 0;
}