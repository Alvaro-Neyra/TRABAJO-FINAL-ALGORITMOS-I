#include "FuegoMinotauro.h"

FuegoMinotauro::FuegoMinotauro(int ancho, int alto, int direccion) 
	: Enemigo(ancho, alto)
{
	this->direccion = direccion;
	int velocidadAElegir = rand() % 3; // del 0 al 2
	int danioFuego = rand() % 5 + 1; // del 1 al 5
	switch (velocidadAElegir) {
		case 0:
			this->velocidadBolaDeFuego = 30;
			break;
		case 1:
			this->velocidadBolaDeFuego = 20;
			break;
		case 2:
			this->velocidadBolaDeFuego = 15;
			break;
	}
	this->danioBolaDeFuego = 10 * danioFuego;
}

FuegoMinotauro::~FuegoMinotauro() {

}

void FuegoMinotauro::dibujar(Graphics^ panel, Bitmap^ imagenEnemigo) {
	Rectangle seccionAMostrar = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
	Rectangle seccionADibujar = Rectangle(x, y, ancho, alto);
	panel->DrawImage(imagenEnemigo, seccionADibujar, seccionAMostrar, GraphicsUnit::Pixel);
}

void FuegoMinotauro::mover(Graphics^ panel) {
	switch (direccion) {
		case 0:
			if (x < 0 || x + ancho > panel->VisibleClipBounds.Width) {
				dx *= -1;
			}

			if (dx > 0) {
				indiceY = 3;
			}
			else {
				indiceY = 1;
			}
			x += dx;
			break;
		case 1:
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
			break;
	}
	indiceX++;
	if (indiceX > 9) indiceX = 0;
}

BolaDeFuego* FuegoMinotauro::lanzarBolaDeFuego(int ancho, int alto, int objetivoX, int objetivoY) {
	BolaDeFuego* nuevaBola = new BolaDeFuego(obtenerXAnchoMitad(), obtenerYAltoMitad(), ancho, alto);
	nuevaBola->setVelocidad(velocidadBolaDeFuego);
	nuevaBola->setObjetivoX(objetivoX);
	nuevaBola->setObjetivoY(objetivoY);
	return nuevaBola;
}