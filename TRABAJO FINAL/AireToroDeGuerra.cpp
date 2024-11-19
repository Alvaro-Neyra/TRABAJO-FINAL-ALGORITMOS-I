#include "AireToroDeGuerra.h"


AireToroDeGuerra::AireToroDeGuerra(int ancho, int alto) 
	: Enemigo(ancho, alto)
{
    this->escala = 1.00;
    this->velocidad = 10;
}

AireToroDeGuerra::~AireToroDeGuerra() {

}

void AireToroDeGuerra::dibujar(Graphics^ panel, Bitmap^ imagenEnemigo) {
	Rectangle seccionAMostrar = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
	Rectangle seccionADibujar = Rectangle(x, y, ancho * escala, alto * escala);
	panel->DrawImage(imagenEnemigo, seccionADibujar, seccionAMostrar, GraphicsUnit::Pixel);
}

void AireToroDeGuerra::mover(Graphics^ panel) {
    x += dx;
    y += dy;
    
    // Si llegan a los limites del panel, no dibujarlo y por lo tanto juego lo elimina del vector enemigo

    if (x <= 0 || x + ancho >= panel->VisibleClipBounds.Width) {
        dx *= -1;
    }
    if (y <= 0 || y + alto >= panel->VisibleClipBounds.Height) {
        dy *= -1;
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

void AireToroDeGuerra::setObjetivo(int x, int y) {
    objetivoX = x;
    objetivoY = y;

    float deltaX = objetivoX - this->x;
    float deltaY = objetivoY - this->y;
    float distancia = sqrt(deltaX * deltaX + deltaY * deltaY);

    if (distancia > 0) {
        dx = (deltaX / distancia) * velocidad;
        dy = (deltaY / distancia) * velocidad;
    }
    else {
        dx = dy = 0;
    }
}

void AireToroDeGuerra::invertirDireccion() {
    this->dx *= -1;
    this->dy *= -1;
}