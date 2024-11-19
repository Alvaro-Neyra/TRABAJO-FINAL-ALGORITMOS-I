#include "Arco.h"


Arco::Arco(int x, int y, int ancho, int alto, char direccion) 
	: Proyectil(x, y, ancho, alto)
{
	this->direccion = direccion;
	this->cantidadFlechas = 10;
	this->capacidadFlechas = 10;
	this->escala = 0.1;
}

Arco::~Arco() {

}

void Arco::dibujar(Graphics^ panel, Bitmap^ imagenProyectil) {
	float angulo = 0.0f;
	float escalaX = 1.0f;
	float escalaY = 1.0f;

	switch (direccion) {
	case 'W':
		angulo = 0.0f;
		break;
	case 'A':
		angulo = 270.0f;
		escalaX = -1.0f;
		break;
	case 'S':
		angulo = 180.0f;
		break;
	case 'D':
		angulo = 90.0f;
		escalaX = -1.0f;
		break;
	}

	panel->TranslateTransform(x, y);
	panel->RotateTransform(angulo);
	panel->ScaleTransform(escalaX, escalaY);

	int dibujarAncho = static_cast<int>(ancho * escala);
	int dibujarAlto = static_cast<int>(alto * escala);
	Rectangle seccionAMostrar = Rectangle(0, 0, imagenProyectil->Width, imagenProyectil->Height);
	Rectangle seccionADibujar = Rectangle(-dibujarAncho / 2, -dibujarAlto / 2, dibujarAncho, dibujarAlto);
	panel->DrawImage(imagenProyectil, seccionADibujar, seccionAMostrar, GraphicsUnit::Pixel);

	panel->ResetTransform();
}

void Arco::mover(Graphics^ panel) {
	if (direccion == 'W' && y >= 0) {
		y -= dy;
	}
	if (direccion == 'S' && y + alto * escala <= panel->VisibleClipBounds.Height) {
		y += dy;
	}
	if (direccion == 'A' && x >= 0) {
		x -= dx;
	}
	if (direccion == 'D' && x + ancho * escala <= panel->VisibleClipBounds.Width) {
		x += dx;
	}
}