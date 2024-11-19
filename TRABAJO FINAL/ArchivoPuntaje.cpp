#include "ArchivoPuntaje.h"

ArchivoPuntaje::ArchivoPuntaje(const string& nombreArchivo) {
    this->nombreArchivo = new string(nombreArchivo);
}


ArchivoPuntaje::~ArchivoPuntaje() {
    delete nombreArchivo;
}

void ArchivoPuntaje::guardarDatos(int* enemigosDerrotados, int* enemigoAireDerrotados, int* enemigoTierraDerrotados, int* enemigoFuegoDerrotados, int* recursosRecogidos, int* aguaTotalRecogida, int* papelTotalRecogida, int* semillasTotalRecogida, int* nivelMaximoAlcanzado) {
    ofstream archivoSalida(*nombreArchivo, ios::out);
    if (archivoSalida.is_open()) {
        archivoSalida << *enemigosDerrotados << endl;
        archivoSalida << *enemigoAireDerrotados << endl;
        archivoSalida << *enemigoTierraDerrotados << endl;
        archivoSalida << *enemigoFuegoDerrotados << endl;
        archivoSalida << *recursosRecogidos << endl;
        archivoSalida << *aguaTotalRecogida << endl;
        archivoSalida << *papelTotalRecogida << endl;
        archivoSalida << *semillasTotalRecogida << endl;
        archivoSalida << *nivelMaximoAlcanzado << endl;
        archivoSalida.close();
    }
    else {
        cout << "Error al abrir el archivo para guardar datos." << endl; 
    }
}

void ArchivoPuntaje::leerDatos(int* enemigosDerrotados, int* enemigoAireDerrotados, int* enemigoTierraDerrotados, int* enemigoFuegoDerrotados, int* recursosRecogidos, int* aguaTotalRecogida, int* papelTotalRecogida, int* semillasTotalRecogida, int* nivelMaximoAlcanzado) {
    ifstream archivoEntrada(*nombreArchivo, ios::in);
    if (archivoEntrada.is_open()) {
        archivoEntrada >> *enemigosDerrotados;
        archivoEntrada >> *enemigoAireDerrotados;
        archivoEntrada >> *enemigoTierraDerrotados;
        archivoEntrada >> *enemigoFuegoDerrotados;
        archivoEntrada >> *recursosRecogidos;
        archivoEntrada >> *aguaTotalRecogida;
        archivoEntrada >> *papelTotalRecogida;
        archivoEntrada >> *semillasTotalRecogida;
        archivoEntrada >> *nivelMaximoAlcanzado;
        archivoEntrada.close();
    }
    else {
        cout << "Error al abrir el archivo para leer datos." << endl;
    }
}
