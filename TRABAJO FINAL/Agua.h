#pragma once
#include "Recurso.h"

class Agua : public Recurso
{
private:
	double cantidad;
public:
	Agua(int x, int y, int ancho, int alto);
	~Agua();
	int obtenerCantidad();
	void dibujar(Graphics^ panel, Bitmap^ imagen) override;
};