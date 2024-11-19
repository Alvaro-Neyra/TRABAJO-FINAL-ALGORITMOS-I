#pragma once
#include <vector>
#include "Proyectil.h"
#include <cmath>

using namespace std;

class BolaDeFuego : public Proyectil
{
private:
	float distancia;
	int velocidad;
	int objetivoX;
	int objetivoY;
	int tipoMovimiento;
	int tiempoDetenido;
	bool seDetuvo;
	bool dividido;
public:
	BolaDeFuego(int x, int y, int ancho, int alto);
	~BolaDeFuego();
	void dibujar(Graphics^ panel, Bitmap^ imagenProyectil) override;
	void mover(Graphics^ panel) override;
	void setObjetivoX(int objetivoX);
	void setObjetivoY(int objetivoY);
	void setVelocidad(int velocidad);
	vector<BolaDeFuego*> dividir();
	bool verificarSeDetuvo();
	bool verificarDividido();
	void setTipoDeMovimiento(int tipo);
};

