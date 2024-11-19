#pragma once
#include "Recurso.h"

class Semilla : public Recurso
{
private:
	int etapa;
	bool plantado;
	int vida;
	bool quemado;
public:
	Semilla(int x, int y, int ancho, int alto);
	~Semilla();
	void germinar();
	void dibujar(Graphics^ panel, Bitmap^ imagenRecurso) override;
	void avanzarEtapa();
	void setPlantado(bool _plantado);
	bool getPlantado();
	int getEtapa();
	void disminuirVida(int cantidad);
	int obtenerVida();
	void quemarPlanta();
	bool obtenerQuemado();
	void setQuemado(bool _quemado);
};

