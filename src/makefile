all: main

main: main.c cargarDatos clasificar 
	gcc main.c -o main *.o -lm -g -Wall

cargarDatos: cargarDatos.c normalizar
	gcc -c cargarDatos.c -Wall

normalizar: normalizar.c listaStock
	gcc -c normalizar.c -Wall

listaStock: listaStock.c
	gcc -c listaStock.c -Wall

clasificar: clasificar.c maxMonticulo
	gcc -c clasificar.c -Wall

maxMonticulo: maxMonticulo.c
	gcc -c maxMonticulo.c -Wall

clean:
	rm *.o main