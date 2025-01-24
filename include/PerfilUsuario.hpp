#ifndef PERFILUSUARIO_H
#define PERFILUSUARIO_H

#include <string>
#include "Item.hpp"

const int PRIMER_OPCION = 1;
const int SEGUNDA_OPCION = 2;
const int TERCERA_OPCION = 3;
const int CUARTA_OPCION = 4;

class PerfilUsuario {
    //Pre: -
    //Post: Devuelve true si el tipo de PUZZLE, CURATIVO, MUNICION.
    bool esValidoTipo(std::string tipo);

public:
    //Pre: -
    //Post: Devuelve entero cargado con el numero ingresado por el usuario.
    int ingresarOpcion();

    //Pre: -
    //Post: Devuelve string cargado con el nombre ingresado por el usuario.
    std::string pedirNombre();

    //Pre: -
    //Post: Devuelve string cargado con el nombre ingresado por el usuario.
    std::string pedirTipo();
};

#endif
