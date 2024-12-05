#include <stdio.h> 
#include <math.h>
#include "normalizar.h"

#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

void iniciarMax(t_stock * dato){
    dato->apertura = 0.0;
    dato->valor_max_dia = 0.0;
    dato->valor_min_dia = 0.0;
    dato->cierre = 0.0;
    dato->volumen = 0.0;
    dato->RSI_7 = 0.0;
    dato->RSI_14 = 0.0;
    dato->CCI_7 = 0.0;
    dato->CCI_14 = 0.0;
    dato->SMA_50 = 0.0;
    dato->EMA_50 = 0.0;
    dato->SMA_100 = 0.0;
    dato->EMA_100 = 0.0;
    dato->MACD = 0.0;
    dato->bollinger = 0.0;
    dato->TR = 0.0;
    dato->ATR_7 = 0.0;
    dato->ATR_14 = 0.0;
    dato->variacion = 0.0;
}

void iniciarMin(t_stock * dato){
    dato->apertura = 100000000.0;
    dato->valor_max_dia = 100000000.0;
    dato->valor_min_dia = 100000000.0;
    dato->cierre = 100000000.0;
    dato->volumen = 1000000000000.0;
    dato->RSI_7 = 100000000.0;
    dato->RSI_14 = 100000000.0;
    dato->CCI_7 = 100000000.0;
    dato->CCI_14 = 100000000.0;
    dato->SMA_50 = 100000000.0;
    dato->EMA_50 = 100000000.0;
    dato->SMA_100 = 100000000.0;
    dato->EMA_100 = 100000000.0;
    dato->MACD = 100000000.0;
    dato->bollinger = 100000000.0;
    dato->TR = 100000000.0;
    dato->ATR_7 = 100000000.0;
    dato->ATR_14 = 100000000.0;
    dato->variacion = 100000000.0;
}

void calcular_max(t_stock dato, t_stock * dato_max){
    dato_max->apertura = MAX(dato.apertura, dato_max->apertura);
    dato_max->valor_max_dia = MAX(dato.valor_max_dia, dato_max->valor_max_dia);
    dato_max->valor_min_dia = MAX(dato.valor_min_dia, dato_max->valor_min_dia);
    dato_max->cierre = MAX(dato.cierre, dato_max->cierre);
    dato_max->volumen = MAX(dato.volumen, dato_max->volumen);
    dato_max->RSI_7 = MAX(dato.RSI_7, dato_max->RSI_7);
    dato_max->RSI_14 = MAX(dato.RSI_14, dato_max->RSI_14);
    dato_max->CCI_7 = MAX(dato.CCI_7, dato_max->CCI_7);
    dato_max->CCI_14 = MAX(dato.CCI_14, dato_max->CCI_14);
    dato_max->SMA_50 = MAX(dato.SMA_50, dato_max->SMA_50);
    dato_max->EMA_50 = MAX(dato.EMA_50, dato_max->EMA_50);
    dato_max->SMA_100 = MAX(dato.SMA_100, dato_max->SMA_100);
    dato_max->EMA_100 = MAX(dato.EMA_100, dato_max->EMA_100);
    dato_max->MACD = MAX(dato.MACD, dato_max->MACD);
    dato_max->bollinger = MAX(dato.bollinger, dato_max->bollinger);
    dato_max->TR = MAX(dato.TR, dato_max->TR);
    dato_max->ATR_7 = MAX(dato.ATR_7, dato_max->ATR_7);
    dato_max->ATR_14 = MAX(dato.ATR_14, dato_max->ATR_14);
}

void calcular_min(t_stock dato, t_stock * dato_min){
    dato_min->apertura = MIN(dato.apertura, dato_min->apertura);
    dato_min->valor_max_dia = MIN(dato.valor_max_dia, dato_min->valor_max_dia);
    dato_min->valor_min_dia = MIN(dato.valor_min_dia, dato_min->valor_min_dia);
    dato_min->cierre = MIN(dato.cierre, dato_min->cierre);
    dato_min->volumen = MIN(dato.volumen, dato_min->volumen);
    dato_min->RSI_7 = MIN(dato.RSI_7, dato_min->RSI_7);
    dato_min->RSI_14 = MIN(dato.RSI_14, dato_min->RSI_14);
    dato_min->CCI_7 = MIN(dato.CCI_7, dato_min->CCI_7);
    dato_min->CCI_14 = MIN(dato.CCI_14, dato_min->CCI_14);
    dato_min->SMA_50 = MIN(dato.SMA_50, dato_min->SMA_50);
    dato_min->EMA_50 = MIN(dato.EMA_50, dato_min->EMA_50);
    dato_min->SMA_100 = MIN(dato.SMA_100, dato_min->SMA_100);
    dato_min->EMA_100 = MIN(dato.EMA_100, dato_min->EMA_100);
    dato_min->MACD = MIN(dato.MACD, dato_min->MACD);
    dato_min->bollinger = MIN(dato.bollinger, dato_min->bollinger);
    dato_min->TR = MIN(dato.TR, dato_min->TR);
    dato_min->ATR_7 = MIN(dato.ATR_7, dato_min->ATR_7);
    dato_min->ATR_14 = MIN(dato.ATR_14, dato_min->ATR_14);    
}

void normalizarStock(t_stock *stock, t_stock min, t_stock max) {
    stock->apertura = (stock->apertura - min.apertura) / (max.apertura - min.apertura);
    stock->valor_max_dia = (stock->valor_max_dia - min.valor_max_dia) / (max.valor_max_dia - min.valor_max_dia);
    stock->valor_min_dia = (stock->valor_min_dia - min.valor_min_dia) / (max.valor_min_dia - min.valor_min_dia);
    stock->cierre = (stock->cierre - min.cierre) / (max.cierre - min.cierre);
    stock->volumen = (stock->volumen - min.volumen) / (max.volumen - min.volumen);
    stock->RSI_7 = (stock->RSI_7 - min.RSI_7) / (max.RSI_7 - min.RSI_7);
    stock->RSI_14 = (stock->RSI_14 - min.RSI_14) / (max.RSI_14 - min.RSI_14);
    stock->CCI_7 = (stock->CCI_7 - min.CCI_7) / (max.CCI_7 - min.CCI_7);
    stock->CCI_14 = (stock->CCI_14 - min.CCI_14) / (max.CCI_14 - min.CCI_14);
    stock->SMA_50 = (stock->SMA_50 - min.SMA_50) / (max.SMA_50 - min.SMA_50);
    stock->EMA_50 = (stock->EMA_50 - min.EMA_50) / (max.EMA_50 - min.EMA_50);
    stock->SMA_100 = (stock->SMA_100 - min.SMA_100) / (max.SMA_100 - min.SMA_100);
    stock->EMA_100 = (stock->EMA_100 - min.EMA_100) / (max.EMA_100 - min.EMA_100);
    stock->MACD = (stock->MACD - min.MACD) / (max.MACD - min.MACD);
    stock->bollinger = (stock->bollinger - min.bollinger) / (max.bollinger - min.bollinger);
    stock->TR = (stock->TR - min.TR) / (max.TR - min.TR);
    stock->ATR_7 = (stock->ATR_7 - min.ATR_7) / (max.ATR_7 - min.ATR_7);
    stock->ATR_14 = (stock->ATR_14 - min.ATR_14) / (max.ATR_14 - min.ATR_14);
}

void normalizarLista(listaStock * lista, t_stock * dato_max, t_stock * dato_min) {
    celdaStock *aux = lista->ini;
    iniciarMin(dato_min);
    iniciarMax(dato_max);
    while(aux != NULL) {
        calcular_min(*aux->s, dato_min);
        calcular_max(*aux->s, dato_max);
        aux = aux->sig;
    }
    aux = lista->ini;
    while(aux != NULL) {
        normalizarStock(aux->s, *dato_min, *dato_max);
        aux = aux->sig;
    } 
}