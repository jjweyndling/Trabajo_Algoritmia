#ifndef NORMALIZAR_H
#define NORMALIZAR_H

#include "listaStock.h"

void normalizarStock(t_stock *stock, t_stock min, t_stock max);
void normalizarLista(listaStock * lista, t_stock * max, t_stock * min);

#endif
