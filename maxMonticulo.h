#include <stdbool.h>
#include <stdio.h>
typedef int tipoElementoMaxMonticulo;

typedef struct tMM{
	tipoElementoMaxMonticulo* array;
	int pos;
	int numEl;
}tipoMaxMonticulo;

void nuevoMaxMonticulo(tipoMaxMonticulo*, int);

void insertarMaxMonticulo(tipoMaxMonticulo *, tipoElementoMaxMonticulo);

void eliminarMaxElemento(tipoMaxMonticulo *, tipoElementoMaxMonticulo);

tipoElementoMaxMonticulo devolverRaiz(tipoMaxMonticulo);

void mostrarAnchura(tipoMaxMonticulo);

bool esVacio(tipoMaxMonticulo);

bool estaLleno(tipoMaxMonticulo);

void intercambio(tipoElementoMaxMonticulo *a, tipoElementoMaxMonticulo *b);