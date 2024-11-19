#pragma once
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class ArchivoPuntaje {
public:
    ArchivoPuntaje(const string& nombreArchivo);
    ~ArchivoPuntaje();

    void guardarDatos(int* enemigosDerrotados, int* enemigoAireDerrotados, int* enemigoTierraDerrotados, int* enemigoFuegoDerrotados, int* recursosRecogidos, int* aguaTotalRecogida, int* papelTotalRecogida, int* semillasTotalRecogida, int* nivelMaximoAlcanzado);
    void leerDatos(int* enemigosDerrotados, int* enemigoAireDerrotados, int* enemigoTierraDerrotados, int* enemigoFuegoDerrotados, int* recursosRecogidos, int* aguaTotalRecogida, int* papelTotalRecogida, int* semillasTotalRecogida, int* nivelMaximoAlcanzado);

private:
    string* nombreArchivo;
};
