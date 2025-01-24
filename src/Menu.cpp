#include <iostream>
#include "Menu.hpp"

using namespace std;

Menu::Menu(Inventario inventario1) {
    inventario = inventario1;
}

void Menu::correrMenu() {
    inventario.cargar();
    bool esSalir = false;
    do{
        imprimirMenu();
        int opcion = usuario.ingresarOpcion();
        procesarOpcion(opcion, esSalir);
    }while(!esSalir);
}

void Menu::imprimirMenu() {
    cout << "-------------MENU--------------" << endl;
    cout << "Presione:\n1 - Alta\n2 - Baja\n3 - Consulta\n4 - Salir" << endl;
    cout << "-------------------------------" << endl;
}

void Menu::procesarOpcion(int opcion, bool& esSalir) {
    if(opcion == PRIMER_OPCION){
        string nombre = usuario.pedirNombre();
        string tipo = usuario.pedirTipo();
        Item* nuevoItem = new Item(nombre, tipo);
        inventario.darAlta(nuevoItem);
    }else if(opcion == SEGUNDA_OPCION){
        string nombre = usuario.pedirNombre();
        inventario.darBaja(nombre);
    }else if(opcion == TERCERA_OPCION){
        inventario.consultar();
    }else if(opcion == CUARTA_OPCION){
        inventario.guardar();
        esSalir = true;
    }else{
        cout << "Ingrese opcion valida" << endl;
    }
}


