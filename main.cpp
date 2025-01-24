#include "Inventario.hpp"
#include "Menu.hpp"

int main() {

    Inventario inventario;

    Menu menu(inventario);

    menu.correrMenu();

    return 0;
}