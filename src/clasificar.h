#ifndef CLASIFICAR_H
#define CLASIFICAR_H

#include "listaStock.h"
#include <stdlib.h>
#include <math.h>

void calcularDistancia(listaStock lista, t_stock per);
void seleccionarKNN(listaStock, tipoMaxMonticulo *, int k);

#endif