#ifndef CLASIFICAR_H
#define CLASIFICAR_H

#include "maxMonticulo.h"

#define PESO_APERTURA 2
#define PESO_VALORMAX 2
#define PESO_VALORMIN 2
#define PESO_CIERRE 3
#define PESO_VOLUMEN 1
#define PESO_RSI7 0.5
#define PESO_RSI14 0.5
#define PESO_CCI7 0.5
#define PESO_CCI14 0.5
#define PESO_SMA50 1
#define PESO_EMA50 1
#define PESO_SMA100 1
#define PESO_EMA100 1
#define PESO_MACD 0.8
#define PESO_BOLLINGER 0.7
#define PESO_TR 0.6
#define PESO_ATR7 0.8
#define PESO_ATR14 0.8


void seleccionarKNN(listaStock, tipoMaxMonticulo *, t_stock);
int predecirClase(tipoMaxMonticulo);

#endif
