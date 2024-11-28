#ifndef CLASIFICAR_H
#define CLASIFICAR_H

#include <stdlib.h>
#include "listaStock.h"
#include "maxMonticulo.h"

void seleccionarKNN(listaStock, tipoMaxMonticulo *, int, t_stock);
void predecirClase(tipoMaxMonticulo);

#endif