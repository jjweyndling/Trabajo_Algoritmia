#include <stdbool.h>
#include <stdio.h>
#include "listaStock.h"

// ESTRUCTURA: VECINO
typedef struct vecino {
    t_stock *s;               // Puntero al stock seleccionado
    float distancia;          // Distancia a este stock
} vecino;

typedef vecino tipoElementoMaxMonticulo;

// ESTRUCTURA: MAXMONTICULO
typedef struct tMM{
	tipoElementoMaxMonticulo* array; // Array con los k vecinos mas cercanos (el elemento máximo siendo el más lejano de ellos)
	int pos;
	int numEl;						 // Numero de vecinos (k)
}tipoMaxMonticulo;

void nuevoMaxMonticulo(tipoMaxMonticulo*, int);
void insertarMaxMonticulo(tipoMaxMonticulo *, tipoElementoMaxMonticulo);
void eliminarMaxMonticulo(tipoMaxMonticulo *, tipoElementoMaxMonticulo);
tipoElementoMaxMonticulo devolverRaiz(tipoMaxMonticulo);
void mostrarAnchura(tipoMaxMonticulo);
bool esVacio(tipoMaxMonticulo);
bool estaLleno(tipoMaxMonticulo);
void intercambio(tipoElementoMaxMonticulo *a, tipoElementoMaxMonticulo *b);