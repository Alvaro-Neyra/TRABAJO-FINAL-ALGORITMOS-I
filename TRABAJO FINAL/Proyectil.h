#pragma once

using namespace System::Drawing;

class Proyectil
{
protected:
	int x;
	int y;
	int dx;
	int dy;
	int ancho;
	int alto;
	int indiceX;
	float escala;
	bool visibilidad;
public:
	Proyectil(int x, int y, int ancho, int alto);
	~Proyectil();
	virtual void dibujar(Graphics^ panel, Bitmap^ imagenArco) = 0;
	virtual void mover(Graphics^ panel) = 0;
	void setVisibilidad(bool _visibilidad);
	bool getVisibilidad();
	int obtenerX();
	int obtenerY();
	int obtenerXAncho();
	int obtenerYAlto();
	void setDx(int dx);
	void setDy(int dy);
	int getDx();
	int getDy();
	void setEscala(float escala);
	Rectangle obtenerRectangulo();
};

