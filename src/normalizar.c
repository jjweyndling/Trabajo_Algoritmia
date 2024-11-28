#include "normalizar.h"
#include <stdio.h>
#include <math.h>

#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

void iniciar(t_stock * dato){
    dato->apertura = 0;
    dato->valor_max_dia = 0;
    dato->valor_min_dia = 0;
    dato->cierre = 0;
    dato->volumen = 0;
    dato->RSI_7 = 0;
    dato->RSI_14 = 0;
    dato->CCI_7 = 0;
    dato->CCI_14 = 0;
    dato->SMA_50 = 0;
    dato->EMA_50 = 0;
    dato->SMA_100 = 0;
    dato->EMA_100 = 0;
    dato->MACD = 0;
    dato->bollinger = 0;
    dato->TR = 0;
    dato->ATR_7 = 0;
    dato->ATR_14 = 0;
    dato->variacion = 0;
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

void normalizar(listaStock * lista){
    celdaStock *aux = lista->ini;
    listaStock nueva;
    t_stock dato_min, dato_max;
    iniciar(&dato_min);
    iniciar(&dato_max);
    while(aux != NULL) {
        calcular_min(*aux->s, &dato_min);
        calcuar_max(aux->s, &dato_max);
        aux = aux->sig;
    }
    aux = lista->ini; 
    while(aux != NULL){
        aux->s->apertura = (aux->s->apertura - dato_min.apertura) / (dato_max.apertura - dato_min.apertura);
        aux->s->valor_max_dia = (aux->s->valor_max_dia - dato_min.valor_max_dia) / (dato_max.valor_max_dia - dato_min.valor_max_dia);
        aux->s->valor_min_dia = (aux->s->valor_min_dia - dato_min.valor_min_dia) / (dato_max.valor_min_dia - dato_min.valor_min_dia);
        aux->s->cierre = (aux->s->cierre - dato_min.cierre) / (dato_max.cierre - dato_min.cierre);
        aux->s->volumen = (aux->s->volumen - dato_min.volumen) / (dato_max.volumen - dato_min.volumen);
        aux->s->RSI_7 = (aux->s->RSI_7 - dato_min.RSI_7) / (dato_max.RSI_7 - dato_min.RSI_7);
        aux->s->RSI_14 = (aux->s->RSI_14 - dato_min.RSI_14) / (dato_max.RSI_14 - dato_min.RSI_14);
        aux->s->CCI_7 = (aux->s->CCI_7 - dato_min.CCI_7) / (dato_max.CCI_7 - dato_min.CCI_7);
        aux->s->CCI_14 = (aux->s->CCI_14 - dato_min.CCI_14) / (dato_max.CCI_14 - dato_min.CCI_14);
        aux->s->SMA_50 = (aux->s->SMA_50 - dato_min.SMA_50) / (dato_max.SMA_50 - dato_min.SMA_50);
        aux->s->EMA_50 = (aux->s->EMA_50 - dato_min.EMA_50) / (dato_max.EMA_50 - dato_min.EMA_50);
        aux->s->SMA_100 = (aux->s->SMA_100 - dato_min.SMA_100) / (dato_max.SMA_100 - dato_min.SMA_100);
        aux->s->EMA_100 = (aux->s->EMA_100 - dato_min.EMA_100) / (dato_max.EMA_100 - dato_min.EMA_100);
        aux->s->MACD = (aux->s->MACD - dato_min.MACD) / (dato_max.MACD - dato_min.MACD);
        aux->s->bollinger = (aux->s->bollinger - dato_min.bollinger) / (dato_max.bollinger - dato_min.bollinger);
        aux->s->TR = (aux->s->TR - dato_min.TR) / (dato_max.TR - dato_min.TR);
        aux->s->ATR_7 = (aux->s->ATR_7 - dato_min.ATR_7) / (dato_max.ATR_7 - dato_min.ATR_7);
        aux->s->ATR_14 = (aux->s->ATR_14 - dato_min.ATR_14) / (dato_max.ATR_14 - dato_min.ATR_14);
        aux = aux->sig;
    }
}
