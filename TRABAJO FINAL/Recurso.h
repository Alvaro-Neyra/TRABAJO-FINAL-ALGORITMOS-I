#pragma once

using namespace System::Drawing;

class Recurso
{
protected:
	int x;
	int y;
	int ancho;
	int alto;
	int tipo;
	float escala;
	int indiceX;
	int indiceY;
	bool visibilidad;
public:
	Recurso(int x, int y, int ancho, int alto);
	~Recurso();
	int obtenerX();
	int obtenerY();
	int obtenerAncho();
	int obtenerAlto();
	void setX(int x);
	void setY(int y);
	void setAncho(int ancho);
	void setAlto(int alto);
	void setVisibilidad(bool _visibilidad);
	bool getVisibilidad();
	virtual void dibujar(Graphics^ panel, Bitmap^ imagenRecurso) = 0;
	Rectangle obtenerRectangulo();
	Rectangle areaDeRecogida();
};

