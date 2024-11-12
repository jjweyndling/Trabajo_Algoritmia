#include <stdbool.h>

typedef struct t_stock{
    float apertura;
    float valor_max_dia;
    float valor_min_dia;
    float cierre;
    long int volumen;
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
}t_stock;

typedef struct celdaP {
    t_stock *s;         // Puntero a la Stock
    struct celdaP *sig; // Stock siguiente en la lista
} celdaStock;

// ESTRUCTURA: VECINO
typedef struct vecino {
    t_stock *s;      // Puntero al Stock seleccionado
    float distancia; // Distancia a este Stock
} vecino;

// ESTRUCTURA: LISTA DE Stocks (es una lista de celdas Stock)
typedef struct listaP {
    celdaStock *ini;          // Primer Stock de la lista
    celdaStock *fin;          // Último Stock de la lista
    vecino *vecinosMasCercanos; // Array con los k vecinos más cercanos
} listaStock;

void nuevaLista(listaStock *, int);
void insertar(listaStock *, t_stock);
bool esNulaLista(listaStock);
void mostrarLista(listaStock);
void calcularVecinosMasCercanos(listaStock, t_stock, int);
void vaciarLista(listaStock *);
float calcularDistancia(t_stock, t_stock);
float calcularDistancia(t_stock, t_stock);