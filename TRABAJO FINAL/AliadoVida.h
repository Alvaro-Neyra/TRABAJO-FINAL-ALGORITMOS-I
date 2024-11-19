#pragma once
#include "Aliado.h"

using namespace System::Drawing;

class AliadoVida : public Aliado
{
public:
	AliadoVida(int ancho, int alto);
	~AliadoVida();
	void mover(Graphics^ panel) override;
};

