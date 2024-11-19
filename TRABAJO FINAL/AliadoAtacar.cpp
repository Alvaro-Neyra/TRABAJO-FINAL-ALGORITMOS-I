#include "AliadoAtacar.h"

AliadoAtacar::AliadoAtacar(int ancho, int alto) 
	: Aliado(ancho, alto)
{
}

AliadoAtacar::~AliadoAtacar() {

}

void AliadoAtacar::mover(Graphics^ panel) {
	if (y < 0 || y + alto > panel->VisibleClipBounds.Height) {
		dy *= -1;
	}

	if (dy > 0) {
		indiceY = 2;
	}
	else {
		indiceY = 0;
	}

	y += dy;

	indiceX++;
	if (indiceX > 9) indiceX = 0;
}