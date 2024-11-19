#pragma once
#include "Aliado.h"

class AliadoAtacar : public Aliado
{
public:
	AliadoAtacar(int ancho, int alto);
	~AliadoAtacar();
	void mover(Graphics^ panel) override;
};

