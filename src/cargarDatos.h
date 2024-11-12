#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaStock.h"
#include"cargarDatos.h"

void cargarStocks(char *file, listaStock *entradas);
static void guardarStock(const char *atr, listaStock *lista_stocks);
void insertar(listaPersona *p, Persona nuevaPersona);