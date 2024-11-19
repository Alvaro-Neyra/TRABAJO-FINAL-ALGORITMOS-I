#include "BolaDeFuego.h"


BolaDeFuego::BolaDeFuego(int x, int y, int ancho, int alto) 
	:Proyectil(x, y, ancho, alto)
{
    this->dividido = false;
	this->seDetuvo = false;
	this->velocidad = 5;
	this->escala = 0.3;
    this->tiempoDetenido = 0;
    this->tipoMovimiento = 1;
}

BolaDeFuego::~BolaDeFuego() {

}

void BolaDeFuego::dibujar(Graphics^ panel, Bitmap^ imagenProyectil) {
	panel->DrawImage(imagenProyectil, x, y, int(ancho * escala), int(alto * escala));
}

void BolaDeFuego::mover(Graphics^ panel) {
    if (tipoMovimiento == 1) {
        float dx = objetivoX - x;
        float dy = objetivoY - y;

        float distancia = sqrt(dx * dx + dy * dy);

        if (distancia > velocidad) {
            x += static_cast<int>((dx / distancia) * velocidad);
            y += static_cast<int>((dy / distancia) * velocidad);
        }
        else {
            if (!seDetuvo) {
                seDetuvo = true;
                tiempoDetenido = 0;
            }
            else {
                if (tiempoDetenido >= 2000) {  // 2 segundos
                    std::vector<BolaDeFuego*> nuevasBolas = dividir();
                    dividido = true;
                }
            }
        }
    }
    else {
        x += dx;
        y += dy;
    }
}

vector<BolaDeFuego*> BolaDeFuego::dividir() {
    vector<BolaDeFuego*> nuevasBolas;

    int nuevoAncho = static_cast<int>(ancho * escala);
    int nuevoAlto = static_cast<int>(alto * escala);

    BolaDeFuego* bola1 = new BolaDeFuego(x, y, nuevoAncho, nuevoAlto);
    bola1->setEscala(escala);
    bola1->setDx(5); bola1->setDy(5);
    bola1->setTipoDeMovimiento(0);

    BolaDeFuego* bola2 = new BolaDeFuego(x, y, nuevoAncho, nuevoAlto);
    bola2->setEscala(escala);
    bola2->setDx(-5); bola2->setDy(5);
    bola2->setTipoDeMovimiento(0);

    BolaDeFuego* bola3 = new BolaDeFuego(x, y, nuevoAncho, nuevoAlto);
    bola3->setEscala(escala);
    bola3->setDx(5); bola3->setDy(- 5);
    bola3->setTipoDeMovimiento(0);

    BolaDeFuego* bola4 = new BolaDeFuego(x, y, nuevoAncho, nuevoAlto);
    bola4->setEscala(escala);
    bola4->setDx(-5); bola4->setDy(-5);
    bola4->setTipoDeMovimiento(0);

    nuevasBolas.push_back(bola1);
    nuevasBolas.push_back(bola2);
    nuevasBolas.push_back(bola3);
    nuevasBolas.push_back(bola4);

    return nuevasBolas;
}



bool BolaDeFuego::verificarSeDetuvo() {
	return this->seDetuvo;
}

bool BolaDeFuego::verificarDividido() {
    return this->dividido;
}

void BolaDeFuego::setObjetivoX(int objetivoX) {
	this->objetivoX = objetivoX;
}

void BolaDeFuego::setObjetivoY(int objetivoY){
	this->objetivoY = objetivoY;
}

void BolaDeFuego::setVelocidad(int velocidad) {
	this->velocidad = velocidad;
}

void BolaDeFuego::setTipoDeMovimiento(int tipo) {
    this->tipoMovimiento = tipo;
}