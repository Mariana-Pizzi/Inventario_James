#include "PerfilUsuario.hpp"
#include <iostream>

using namespace std;

bool PerfilUsuario::esValidoTipo(std::string tipo) {
    return(tipo == TIPO_PUZZLE || tipo == TIPO_CURATIVO || tipo == TIPO_MUNICION);
}

int PerfilUsuario::ingresarOpcion() {
    int opcion;
    cout<<"Ingrese opcion: ";
    cin>>opcion;
    cout<<endl;
    return opcion;
}

string PerfilUsuario::pedirNombre() {
    string nombre;
    cout << "Nombre del item: ";
    getline(cin >> ws, nombre);
    return nombre;
}

string PerfilUsuario::pedirTipo() {
    string tipo;
    cout << endl << "Tipo del item: ";
    getline(cin >> ws, tipo);
    if(!esValidoTipo(tipo)){
        cout << endl << "El tipo ingresado no es valido" << endl;
        tipo = pedirTipo();
    }
    return tipo;
}