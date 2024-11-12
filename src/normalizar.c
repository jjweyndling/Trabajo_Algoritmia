#include "normalizar.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

t_stock iniciar(t_stock dato){
    dato.apertura = 0;
    dato.valor_max_dia = 0;
    dato.valor_min_dia = 0;
    dato.cierre = 0;
    dato.volumen = 0;
    dato.RSI_7 = 0;
    dato.RSI_14 = 0;
    dato.CCI_7 = 0;
    dato.CCI_14 = 0;
    dato.SMA_50 = 0;
    dato.EMA_50 = 0;
    dato.SMA_100 = 0;
    dato.EMA_100 = 0;
    dato.MACD = 0;
    dato.bollinger = 0;
    dato.TR = 0;
    dato.ATR_7 = 0;
    dato.ATR_14 = 0;
    dato.variacion = 0;
    return dato;
}

t_stock calcular_max(t_stock dato, t_stock dato_max){
    if(dato.apertura > dato_max.apertura)
        dato_max.apertura = dato.apertura;
    if(dato.valor_max_dia > dato_max.valor_max_dia)
        dato_max.valor_max_dia = dato.valor_max_dia;
    if(dato.valor_min_dia > dato_max.valor_min_dia)
        dato_max.valor_min_dia = dato.valor_min_dia;
    if(dato.cierre > dato_max.cierre)
        dato_max.cierre = dato.cierre;
    if(dato.volumen > dato_max.volumen)
        dato_max.volumen = dato.volumen;
    if(dato.RSI_7 > dato_max.RSI_7)
        dato_max.RSI_7 = dato.RSI_7;
    if(dato.RSI_14 > dato_max.RSI_14)
        dato_max.RSI_14 = dato.RSI_14;
    if(dato.CCI_7 > dato_max.CCI_7)
        dato_max.CCI_7 = dato.CCI_7;
    if(dato.CCI_14 > dato_max.CCI_14)
        dato_max.CCI_14 = dato.CCI_14;
    if(dato.SMA_50 > dato_max.SMA_50)
        dato_max.SMA_50 = dato.SMA_50;
    if(dato.EMA_50 > dato_max.EMA_50)
        dato_max.EMA_50 = dato.EMA_50;
    if(dato.SMA_100 > dato_max.SMA_100)
        dato_max.SMA_100 = dato.SMA_100;
    if(dato.EMA_100 > dato_max.EMA_100)
        dato_max.EMA_100 = dato.EMA_100;
    if(dato.MACD > dato_max.MACD)
        dato_max.MACD = dato.MACD;
    if(dato.bollinger > dato_max.bollinger)
        dato_max.bollinger = dato.bollinger;
    if(dato.TR > dato_max.TR)
        dato_max.TR = dato.TR;
    if(dato.ATR_7 > dato_max.ATR_7)
        dato_max.ATR_7 = dato.ATR_7;
    if(dato.ATR_14 > dato_max.ATR_14)
        dato_max.ATR_14 = dato.ATR_14;  
    return dato_max;
}

t_stock calcular_min(t_stock dato, t_stock dato_min){
    if(dato.apertura < dato_min.apertura)
        dato_min.apertura = dato.apertura;
    if(dato.valor_max_dia < dato_min.valor_max_dia)
        dato_min.valor_max_dia = dato.valor_max_dia;
    if(dato.valor_min_dia < dato_min.valor_min_dia)
        dato_min.valor_min_dia = dato.valor_min_dia;
    if(dato.cierre < dato_min.cierre)
        dato_min.cierre = dato.cierre;
    if(dato.volumen < dato_min.volumen)
        dato_min.volumen = dato.volumen;
    if(dato.RSI_7 < dato_min.RSI_7)
        dato_min.RSI_7 = dato.RSI_7;
    if(dato.RSI_14 < dato_min.RSI_14)
        dato_min.RSI_14 = dato.RSI_14;
    if(dato.CCI_7 < dato_min.CCI_7)
        dato_min.CCI_7 = dato.CCI_7;
    if(dato.CCI_14 < dato_min.CCI_14)
        dato_min.CCI_14 = dato.CCI_14;
    if(dato.SMA_50 < dato_min.SMA_50)
        dato_min.SMA_50 = dato.SMA_50;
    if(dato.EMA_50 < dato_min.EMA_50)
        dato_min.EMA_50 = dato.EMA_50;
    if(dato.SMA_100 < dato_min.SMA_100)
        dato_min.SMA_100 = dato.SMA_100;
    if(dato.EMA_100 < dato_min.EMA_100)
        dato_min.EMA_100 = dato.EMA_100;
    if(dato.MACD < dato_min.MACD)
        dato_min.MACD = dato.MACD;
    if(dato.bollinger < dato_min.bollinger)
        dato_min.bollinger = dato.bollinger;
    if(dato.TR < dato_min.TR)
        dato_min.TR = dato.TR;
    if(dato.ATR_7 < dato_min.ATR_7)
        dato_min.ATR_7 = dato.ATR_7;
    if(dato.ATR_14 < dato_min.ATR_14)
        dato_min.ATR_14 = dato.ATR_14;
    return dato_min;
}

listaStock normalizar(listaStock lista, t_stock dato_max, t_stock dato_min){
    celdaStock *aux = lista.ini;
    listaStock nueva;
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
    return lista;
}

