#ifndef UTILIDADES_H
#define UTILIDADES_H

#include "Vector.hpp"

const int NO_ENCONTRADO = 100;

class Utilidades {
public:
    //Pre: Linea de forma palabra,palabra
    //Pos: Carga nombre con la palabra que se encuentra en linea antes
    //     de la , y tipo cargada con la palabra que se encuentra despues
    void separarLinea(std::string& linea, std::string& nombre, std::string& tipo);

    //Pre: nombre cargada
    //Pos: devuelve la posicion en la que se encuentra la palabra buscada
    //     si no se encuentra devuelve NO_ENCONTRADO
    size_t posicionEncontrada(std::string nombre, Vector& items);
};

#endif