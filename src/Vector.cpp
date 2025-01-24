#include "Vector.hpp"

using namespace std;

Vector::Vector(){
    cantidadDatos = 0;
    tamanioMaximo = 0;
    datos = nullptr;
}

void Vector::redimensionarAlta(){
    if(vacio()){
        tamanioMaximo = 1;
        datos = new Item*[tamanioMaximo];
    }else{
        Item** viejosDatos = datos;
        tamanioMaximo *= 2;
        datos = new Item*[tamanioMaximo];
        for(size_t i = 0; i < cantidadDatos; i++){
            datos[i] = viejosDatos[i];
        }
        delete[] viejosDatos;
    }
}

void Vector::redimensionarBaja(){
    if(vacio()){
        tamanioMaximo = 0;
        delete[] datos;
        datos = nullptr;
    }else{
        Item** viejosDatos = datos;
        tamanioMaximo /= 2;
        datos = new Item*[tamanioMaximo];
        for(size_t i = 0; i < cantidadDatos; i++){
            datos[i] = viejosDatos[i];
        }
        delete[] viejosDatos;
    }
}

void Vector::alta(Item* dato){
    if(cantidadDatos == tamanioMaximo){
        redimensionarAlta();
    }
    datos[cantidadDatos] = dato;
    cantidadDatos++;
}

void Vector::alta(Item* dato, size_t indice){
    if(indice > cantidadDatos){
        throw VectorException();
    }else if(indice == cantidadDatos){
        alta(dato);
    }else{
        if(cantidadDatos == tamanioMaximo){
            redimensionarAlta();
        }
        for(size_t i = cantidadDatos; i > indice; i--){
            datos[i] = datos[i - 1];
        }
        datos[indice] = dato;
        cantidadDatos++;
    }
}

Item* Vector::baja(){
    if(vacio()){
        throw VectorException();
    }else{
        Item* datoEliminado = datos[cantidadDatos - 1];
        cantidadDatos--;
        if(cantidadDatos <= (tamanioMaximo/2)){
            redimensionarBaja();
        }
        return datoEliminado;
    }
}

Item* Vector::baja(size_t indice){
    if(vacio() || indice >= cantidadDatos){
        throw VectorException();
    }else{
        Item* datoEliminado = datos[indice];
        for(size_t i = indice; i < cantidadDatos - 1; i++){
            datos[i] = datos[i + 1];
        }
        cantidadDatos--;
        if(cantidadDatos <= (tamanioMaximo/2)){
            redimensionarBaja();
        }
        return datoEliminado;
    }
}

bool Vector::vacio(){
    return cantidadDatos == 0;
}

size_t Vector::tamanio(){
    return cantidadDatos;
}

Item*& Vector::operator[](size_t indice) {
    if(vacio() || indice >= cantidadDatos){
        throw VectorException();
    }else{
        return datos[indice];
    }
}

Vector::~Vector(){
    if(cantidadDatos > 0){
        delete[] datos;
    }
}