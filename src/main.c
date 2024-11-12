#include "normalizar.h"
#include <stdio.h>
#include "listaStock.h"

int main(){
    

    listaStock lista;
    t_stock dato_max, dato_min;
    dato_max = iniciar(dato_max);
    dato_min = iniciar(dato_min);
    nuevaLista(&lista, 1);
    insertar(&lista, dato_max);
    insertar(&lista, dato_min);
    lista = normalizar(lista, dato_max, dato_min);
    mostrarLista(lista);
    return 0;
}