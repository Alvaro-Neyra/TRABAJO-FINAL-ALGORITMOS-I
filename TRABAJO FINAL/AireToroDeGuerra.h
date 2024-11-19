#pragma once
#include "Enemigo.h"
class AireToroDeGuerra : public Enemigo
{
private:
	int velocidad;
	int objetivoX;
	int objetivoY;
public:
	AireToroDeGuerra(int ancho, int alto);
	~AireToroDeGuerra();
	void dibujar(Graphics^ panel, Bitmap^ imagenEnemigo) override;
	void mover(Graphics^ panel) override;
	void setObjetivo(int x, int y);
	void invertirDireccion();
};

