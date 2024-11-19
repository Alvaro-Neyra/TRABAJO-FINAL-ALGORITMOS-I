#pragma once
#include "Enemigo.h"
#include "BolaDeFuego.h"

class FuegoMinotauro : public Enemigo
{
private:
	int velocidadBolaDeFuego;
	int danioBolaDeFuego;
	int direccion;
public:
	FuegoMinotauro(int ancho, int alto, int direccion);
	~FuegoMinotauro();
	void dibujar(Graphics^ panel, Bitmap^ imagenEnemigo) override;
	void mover(Graphics^ panel) override;
	BolaDeFuego* lanzarBolaDeFuego(int ancho, int alto, int objetivoX, int objetivoY);
};

