#ifndef LISTA_STOCK_H
#define LISTA_STOCK_H

#include <stdbool.h>

#define DECRECE -1
#define NEUTRO 0
#define CRECE 1

// TIPO DE DATO: STOCK
typedef struct t_stock{
    float apertura;
    float valor_max_dia;
    float valor_min_dia;
    float cierre;
    double volumen;
    float RSI_7;
    float RSI_14;
    float CCI_7;
    float CCI_14;
    float SMA_50;
    float EMA_50;
    float SMA_100;
    float EMA_100;
    float MACD;
    float bollinger;
    float TR;
    float ATR_7;
    float ATR_14;
    int variacion; // -1: Decreciente, 0: Neutral, 1: Creciente
}t_stock;

typedef struct celdaS {
    t_stock *s;               // Puntero al stock
    struct celdaS *sig;       // Stock siguiente en la lista
} celdaStock;

// ESTRUCTURA: LISTA DE STOCKS (es una lista de celdaStock)
typedef struct listaS {
    celdaStock *ini;          // Primer stock de la lista
    celdaStock *fin;          // Último stock de la lista
} listaStock;

void nuevaLista(listaStock *);
void insertar(listaStock *, t_stock);
void eliminarPrimero(listaStock *);
t_stock * obtenerPrimero(listaStock );
bool esNulaLista(listaStock);
void mostrarLista(listaStock);
void vaciarLista(listaStock *);

#endif