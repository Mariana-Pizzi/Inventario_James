#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "Item.hpp"
#include "Vector.hpp"
#include "Utilidades.hpp"

const std::string RUTA = "archivo.csv";
const int MAX_ELEMENTOS = 15;

class Inventario {
private:
    Vector items;
    Utilidades utilidad;

public:
    //Constructor
    //Pre:-
    //Pos: Crea un inventario default.
    Inventario();

    //Pre: -
    //Post: Carga los datos en el vector que se encuentran en el archivo.csv
    void cargar();

    //Pre: El item no puede estar vacio.
    //Post: Agrega un item recogido por el jugador.
    void darAlta(Item* item);

    //Pre: El inventario no puede estar vacio.
    //Post: Elimina un item que el juegador decida usar.
    void darBaja(std::string nombre);

    //Pre: -
    //Post: Muestra su contenido por pantalla.
    void consultar();

    //Pre: -
    //Post: Devuelve true si el inventario llego a su capacidad maxima.
    bool estaLleno();

    //Pre: -
    //Post: Guarda en un archivo.csv el vector con los items con la forma nombre,tipo.
    void guardar();

    //Pre: -
    //Post: Destructor.
    ~Inventario();
};

#endif