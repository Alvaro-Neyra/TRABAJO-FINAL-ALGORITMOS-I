#pragma once
#include "Proyectil.h"
#include "Arco.h"
#include <iostream>

using namespace System::Drawing;
using namespace std;

class Guardian
{
private:
	int x;
	int y;
	int xAnterior;
	int yAnterior;
	int dx;
	int dy;
	int ancho;
	int alto;
	int indiceX;
	int indiceY;
	char direccion;
	int arma;
	int vida;
	int vidaAnterior;
	int salud;
	bool recogerRecurso;
	bool atacando;
	bool germinarPlanta;
	int cantidadDeAgua;
	int cantidadDeSemillas;
	int cantidadDeResiduosReciclables;
	int resistenciaZombieTierra;
	int cantidadFlechas;
	int vidaMaxima;
public:
	Guardian(int ancho, int alto);
	~Guardian();
	void volverALaPosicionInicial();
	void setArma(int _arma);
	int getArma();
	void setAtacando(bool _atacando);
	bool obtenerAtacando();
	void dibujar(Graphics^ panel, Bitmap^ guardianImagen);
	void mover(Graphics^ panel, char tecla);
	void setX(int x);
	void setY(int y);
	int obtenerX();
	int obtenerY();
	int obtenerXAnchoMitad();
	int obtenerYAltoMitad();
	char obtenerDireccion();
	void reducirSalud(int cantidad);
	void aumentarSalud(int cantidad);
	void aumentarVidas(int cantidad);
	int obtenerSalud();
	void setSalud(int cantidad);
	void disminuirVidas(int cantidad);
	int obtenerVidas();
	void setVidas(int cantidad);
	void aumentarSemillas(int cantidad);
	void setCantidadSemillas(int _semillas);
	int obtenerCantidadSemillas();
	void disminuirSemillas(int cantidad);
	void aumentarResiduosReciclables(int cantidad);
	void setCantidadResiduosReciclables(int _residuos);
	int obtenerCantidadResiduosReciclables();
	void aumentarAgua(int cantidad);
	void setCantidadDeAgua(int cantiddAgua);
	int obtenerCantidadDeAgua();
	void disminuirAgua(int cantidad);
	void setRecogerRecurso(bool _recogerRecurso);
	bool obtenerRecogerRecurso();
	bool obtenerGerminarPlanta();
	void setGerminarPlanta(bool _germinar);
	Rectangle obtenerRectangulo();
	void disminuirResistenciaZombie();
	int obtenerResistenciaZombie();
	void setResistenciaZombie(int cantidad);
	Proyectil* disparar(int ancho, int alto);
	bool cambioVida();
	void setCantidadFlechas(int _cantidad);
	void disminuirCantidadFlechas(int _cantidad);
	int obtenerCantidadFlechas();
	void generarFlechas();
};

