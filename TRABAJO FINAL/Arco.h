#pragma once
#include "Proyectil.h"

using namespace System::Drawing;

class Arco : public Proyectil
{
private:
	char direccion;
	int capacidadFlechas;
	int cantidadFlechas;
public:
	Arco(int x, int y, int ancho, int alto, char direccion);
	~Arco();
	void dibujar(Graphics^ panel, Bitmap^ imagenProyectil) override;
	void mover(Graphics^ panel) override;
};

