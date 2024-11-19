#pragma once
#include "Recurso.h"
#include <iostream>

class ResiduosReciclables : public Recurso
{
private:
	int tipo;
public:
	ResiduosReciclables(int x, int y, int ancho, int alto, int tipo);
	~ResiduosReciclables();
	int contaminar();
	void dibujar(Graphics^ panel, Bitmap^ imagen) override;
};

