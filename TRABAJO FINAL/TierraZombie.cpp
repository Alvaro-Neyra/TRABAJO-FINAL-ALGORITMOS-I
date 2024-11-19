#include "TierraZombie.h"

TierraZombie::TierraZombie(int ancho, int alto) 
	:Enemigo(ancho, alto)
{
    this->velocidad = 20;
}

TierraZombie::~TierraZombie() {

}

void TierraZombie::dibujar(Graphics^ panel, Bitmap^ imagenEnemigo) {
	Rectangle seccionAMostrar = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
	Rectangle areaADibujar = Rectangle(x, y, ancho, alto);
	panel->DrawImage(imagenEnemigo, areaADibujar, seccionAMostrar, GraphicsUnit::Pixel);
}

void TierraZombie::mover(Graphics^ panel) {
    int dx = objetivoX - x;
    int dy = objetivoY - y;

    float distancia = sqrt(dx * dx + dy * dy);

    if (distancia > 1.0f) {
        x += static_cast<int>(velocidad * (dx / distancia));
        y += static_cast<int>(velocidad * (dy / distancia));
    }

    if (dx > 0) {
        indiceY = 3;
    }
    else {
        indiceY = 1;
    }

    if (dy > 0) {
        indiceY = 2;
    }
    else {
        indiceY = 0;
    }
    indiceX++;
    if (indiceX > 9) indiceX = 0;
}

void TierraZombie::setObjetivo(int x, int y) {
	this->objetivoX = x;
	this->objetivoY = y;
}
