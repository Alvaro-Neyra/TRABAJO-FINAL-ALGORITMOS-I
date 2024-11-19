#pragma once
#include "Enemigo.h"

class TierraZombie : public Enemigo
{
private:
	int velocidad;
	int objetivoX;
	int objetivoY;
public:
	TierraZombie(int ancho, int alto);
	~TierraZombie();
	void dibujar(Graphics^ panel, Bitmap^ imagenEnemigo) override;
	void mover(Graphics^ panel) override;
	void setObjetivo(int x, int y);
};

