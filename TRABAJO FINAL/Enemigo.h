#pragma once
#include "iostream"
using namespace System::Drawing;
using namespace std;

class Enemigo
{
protected:
	int x;
	int y;
	int dx;
	int dy;
	int indiceX;
	int indiceY;
	int ancho;
	int alto;
	float escala;
	int vida;
	bool visibilidad;
	int direccion;
public:
	Enemigo(int ancho, int alto);
	~Enemigo();
	void setVisibilidad(bool _visibilidad);
	bool getVisibilidad();
	void setX(int x);
	void setY(int y);
	virtual void dibujar(Graphics^ panel, Bitmap^ imagenEnemigo) = 0;
	virtual void mover(Graphics^ panel) = 0;
	int obtenerXAnchoMitad();
	int obtenerYAltoMitad();
	void setVida(int cantidad);
	int getVida();
	void reducirVida(int cantidad);
	Rectangle obtenerRectangulo();
};

