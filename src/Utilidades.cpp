#include "Utilidades.hpp"

using namespace std;

void Utilidades::separarLinea(string& linea, string& nombre, string& tipo){
    size_t posicion = linea.find(',');
    if(posicion != string::npos){
        nombre = linea.substr(0, posicion);
        tipo = linea.substr(posicion + 1);
    }
}

size_t Utilidades::posicionEncontrada(string nombre, Vector& items) {
    size_t posicion = NO_ENCONTRADO;
    size_t i = 0;
    bool seEncontro = false;
    while(i < items.tamanio() && !seEncontro){
        if(*items[i] == nombre){
            posicion = i;
            seEncontro = true;
        }
        i++;
    }
    return posicion;
}