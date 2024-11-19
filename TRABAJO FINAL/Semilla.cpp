#include "Semilla.h"

Semilla::Semilla(int x, int y, int ancho, int alto)
    : Recurso(x, y, ancho, alto), etapa(-1) {
    escala = 1.0f;
    plantado = false; // Inicialmente no está plantada
    indiceX = 0; // Se inicia en el primer sprite
    this->quemado = false;
    this->vida = 500; // Se inicia con 50 de vida
}

Semilla::~Semilla() {}

void Semilla::dibujar(Graphics^ panel, Bitmap^ imagenPlanta) {
    // Ajustar el índice del sprite con base en la etapa
    if (indiceX < 6) {
        indiceX = etapa + 1; // Si etapa = -1, índice será 0 (primer sprite)
    }

    // Determinar la sección de la imagen que corresponde a la etapa actual
    Rectangle seccionAMostrar = Rectangle(indiceX * ancho, 0, ancho, alto);

    // Definir el área donde se dibujará la imagen
    Rectangle areaADibujar = Rectangle(x, y, ancho * escala, alto * escala);
    
    // Dibujar la imagen de la planta
    panel->DrawImage(imagenPlanta, areaADibujar, seccionAMostrar, GraphicsUnit::Pixel);
}

void Semilla::germinar() {
    etapa = 0; // Cambiar a la primera etapa visible (germinación)
    indiceX = 0;
}

void Semilla::avanzarEtapa() {
    if (!plantado) return; // No avanza si no está plantada
    if (etapa < 5) etapa++; // Incrementar etapa hasta un máximo de 5
}

void Semilla::quemarPlanta() {
    etapa = 6;
}

bool Semilla::obtenerQuemado() {
    return this->quemado;
}

void Semilla::setQuemado(bool _quemado) {
    this->quemado = _quemado;
}

void Semilla::setPlantado(bool _plantado) {
    this->plantado = _plantado;
}

bool Semilla::getPlantado() {
    return this->plantado;
}

int Semilla::getEtapa() {
    return etapa;
}

void Semilla::disminuirVida(int cantidad) {
    this->vida -= cantidad;
    if (this->vida < 0) {
        this->vida = 0;
    }
}

int Semilla::obtenerVida() {
    return this->vida;
}