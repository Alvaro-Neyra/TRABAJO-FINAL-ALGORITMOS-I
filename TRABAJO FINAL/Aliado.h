#pragma once

using namespace System::Drawing;

class Aliado
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
	bool visibilidad;
	int tipoMovimiento;
public:
	Aliado(int ancho, int alto);
	~Aliado();
	void setVisibilidad(bool visibilidad);
	bool getVisibilidad();
	void dibujar(Graphics^ panel, Bitmap^ imagenAliado);
	virtual void mover(Graphics^ panel) = 0;
	void setX(int x);
	void setY(int y);
	Rectangle obtenerRectangulo();
};

