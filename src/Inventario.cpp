#include <iostream>
#include <fstream>
#include "Inventario.hpp"

using namespace std;

Inventario::Inventario() = default;

void Inventario::cargar() {
    ifstream archivo(RUTA);
    if(!archivo.is_open()){
        cout << "No se pudo abrir archivo" << endl;
        return;
    }
    string linea;
    while(getline(archivo, linea)){
        string nombre;
        string tipo;
        utilidad.separarLinea(linea, nombre, tipo);
        Item* item = new Item(nombre, tipo); //liberar
        darAlta(item);
    }
    archivo.close();
}

void Inventario::darAlta(Item* itemAgregar) {
    if(!estaLleno()){
        items.alta(itemAgregar);
    }else{
        cout << "El inventario esta lleno" << endl;
    }
}

void Inventario::darBaja(string nombreEliminar) {
    size_t posicion = utilidad.posicionEncontrada(nombreEliminar, items);
    if(posicion != NO_ENCONTRADO){
        Item* itemEliminado = items.baja(posicion);
        delete itemEliminado;
    }else{
        cout << "El elemento " << nombreEliminar << " no se encuentra en el inventario" << endl;
    }
}

void Inventario::consultar(){
    if(items.vacio()){
        cout << "El inventario esta vacio" << endl;
    }else{
        for(size_t i = 0; i < items.tamanio(); i++){
            cout << (i+1) << ". ";
            items[i]->listarInformacion();
            cout << endl;
        }
    }
}

bool Inventario::estaLleno() {
    return (items.tamanio() > MAX_ELEMENTOS);
}

void Inventario::guardar() {
    ofstream archivo(RUTA);
    if(!archivo.is_open()){
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }else{
        for(size_t i = 0; i < items.tamanio(); i++){
            archivo << *items[i] << endl;
        }
        archivo.close();
    }
}

Inventario::~Inventario(){
    for(size_t i = 0; i < items.tamanio(); i++){
        delete items[i];
    }
}