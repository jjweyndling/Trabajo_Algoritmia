#ifndef NORMALIZAR_H
#define NORMALIZAR_H

#include "listaStock.h"
#include <stdlib.h>

t_stock calcular_max ( t_stock dato, t_stock dato_max);
t_stock calcular_min(t_stock dato, t_stock dato_min);
t_stock iniciar(t_stock dato);
listaStock normalizar(listaStock lista, t_stock dato_max, t_stock dato_min);
