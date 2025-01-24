#ifndef MENU_H
#define MENU_H

#include "Inventario.hpp"
#include "PerfilUsuario.hpp"

class Menu {
private:
    Inventario inventario;
    PerfilUsuario usuario;

    //Pre: -
    //Post: Imprime por pantalla las opciones del menu.
    void imprimirMenu();

    //Pre: Opcion debe ser 1, 2, 3 o 4, salir false
    //Post: Realiza una accion en funcion a la opcion
    //      si pocion es 1 da de alta, 2 da de baja, 3 consulta, 4 guarda y sale.
    void procesarOpcion(int opcion, bool& esSalir);

public:
    //Pre: -
    //Post: constructor de la clase Menu
    Menu(Inventario inventario1);

    //Pre: -
    //Post: Bucle que corre el menu mientras que el usuario no elija la opcion salir
    void correrMenu();
};

#endif