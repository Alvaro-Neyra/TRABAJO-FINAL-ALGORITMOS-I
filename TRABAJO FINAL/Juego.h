#pragma once
#include <iostream>
#include "Guardian.h"
#include "Enemigo.h"
#include "Arco.h"
#include "BolaDeFuego.h"
#include "Proyectil.h"
#include "FuegoMinotauro.h"
#include "AireToroDeGuerra.h"
#include "TierraZombie.h"
#include "Aliado.h"
#include "AliadoAtacar.h"
#include "AliadoVida.h"
#include "Recurso.h"
#include "Agua.h"
#include "ResiduosReciclables.h"
#include "Semilla.h"
#include <vector>
#include "ArchivoPuntaje.h"

using namespace std;

class Juego
{
private:
	Guardian* guardian;
	vector<Aliado*> aliados;
	vector<Proyectil*> proyectiles;
	vector<Enemigo*> enemigos;
	vector<Recurso*> recursos;
	int contaminacion;
	int tipoAliado;
	int cantidadEnemigos;
	int cantidadAliados;
	int cantidadRecursos;
	int nivel;
	int descontaminacion;
	vector<Semilla*> plantasPlantadas;
	ArchivoPuntaje* archivoPuntaje;
	int enemigosDerrotados,enemigoAireDerrotados,enemigoTierraDerrotados,enemigoFuegoDerrotados, recursosRecolectados, aguaTotalRecogida, papelTotalRecogida, semillasTotalRecogida, nivelUltimoAlcanzado;
public:
	Juego();
	~Juego();
	void crearRecursos(Graphics^ panel, Bitmap^ imagenPlanta, Bitmap^ imagenAgua, Bitmap^ imagenResiduosReciclables);
	void crearAliados(int ancho, int alto, Graphics^ panel);
	void crearEnemigos(int ancho, int alto, Graphics^ panel);
	void plantar(Bitmap^ imagenPlanta);
	bool puedePlantar(Bitmap^ imagenPlanta, Graphics^ panel);
	void agregarAliado(Aliado* aliado);
	void agregarEnemigo(Enemigo* enemigo);
	void agregarArco(Arco* arco);
	void agregarRecurso(Recurso* recurso);
	void agregarBolaDeFuego(BolaDeFuego* bola);
	void dibujarTodo(Graphics^ panel, Bitmap^ imagenGuardian, Bitmap^ imagenEnemigoFuego, Bitmap^ imagenEnemigoTierra, Bitmap^ imagenEnemigoAire, Bitmap^ imagenArco, Bitmap^ imagenBolaDeFuego, Bitmap^ imagenAliadoVida, Bitmap^ imagenAliadoAtacar, Bitmap^ imagenSemilla, Bitmap^ imagenResiduosReciclables, Bitmap^ imagenAgua);
	void colisionar(Graphics^ panel);
	void moverTodo(Graphics^ panel);
	void crearGuardian(int ancho, int alto);
	void disparoAleatorio(int ancho, int alto);
	void expandirProyectiles();
	void actualizar();
	void reiniciarNivel(Graphics^ panel, int tipoNivel, Bitmap^ imagenGuardian, Bitmap^ imagenEnemigo, Bitmap^ imagenAliado);
	Guardian* obtenerGuardian();
	void setNivel(int nivel);
	bool aliadosEliminados();
	bool juegoTerminado();
	bool recursosRecogidos();
	void reiniciarJuego();
	void actualizarCrecimientoPlantas();
	void ajustarContaminacion(float porcentaje, bool esDescontaminacion);
	int obtenerContaminacion();
	void ajustarDificultadEnemigos(int nivel);
	int obtenerCantidadEnemigosActuales();
	void guardarPuntaje();
	void cargarPuntaje();
	int obtenerEnemigosDerrotados();
	int obtenerEnemigoAireDerrotados();
	int obtenerEnemigoTierraDerrotados();
	int obtenerEnemigoFuegoDerrotados();
	int obtenerRecursosRecolectados();
	int obtenerAguaTotalRecogida();
	int obtenerPapelTotalRecogida();
	int obtenerSemillasTotalRecogida();
	int obtenerNivelUltimoAlcanzado();
	void setEnemigosDerrotados(int cantidad);
	void setEnemigoAireDerrotados(int cantidad);
	void setEnemigoTierraDerrotados(int cantidad);
	void setEnemigoFuegoDerrotados(int cantidad);
	void setRecursosRecolectados(int cantidad);
	void setAguaTotalRecogida(int cantidad);
	void setPapelTotalRecogida(int cantidad);
	void setSemillasTotalRecogida(int cantidad);
	void setNivelUltimoAlcanzado(int nivel);
	void actualizarEstadoGuardian();
};

