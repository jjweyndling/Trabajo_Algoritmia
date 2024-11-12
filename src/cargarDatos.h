#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaStock.h"

#define MAX_BUF_SIZE 1024

void cargarStocks(char *file, listaStock *entradas);
static void guardarStock(const char *atr, listaStock *lista_stocks);
void insertar(listaStock *p, t_stock nuevaPersona);
void imprimirLista(listaStock lista);