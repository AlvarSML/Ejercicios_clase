/*----------------------------------------------+
|Nombre:   CentrosNumericos.c                   |
|Sinopsis: Calcula los centros numericos desde  |
| 1 hasta n                                     |
|Directivas de compilación: compilador gcc      |
|Lista de códigos de salida del programa:       |
|  Devuelve 0.                                  |
|Organización: Universidad de Burgos            |
|Autor:   Alvar San Martin                      |
|Fecha:   27/03/2020                            |
|Versión: v1.0                                  |
+----------------------------------------------*/

/* Directivas del preprocesador */
#define SALIR 0
#define CONTINUAR 1

#include <stdio.h>
#include <math.h>

/* Definicion de funciones */
int leeEntero();
void calcularCentros(int);
int calculaCentro(int);
int sumaAnteriores(int);
void mostrarCentro(int);
int calcularPosteriores(int, int);
int ultimo(int, int);
void mostrarNumerosHasta(int, int);
void mostrarNumeros(int, int);

/* Definicion de funciones */
int main() {

  int n, menu = CONTINUAR;
  char cont;

  do {
    printf("Introduce un entero(1-5000): ");
    n = leeEntero();
    if (n < 1 || n > 5000 ) {
      printf("Introduce un numero valido (INTRO para continuar)\n");
      //El primero captura el enter de la entrada anterior
      getchar();
      getchar();
    } else {
      calcularCentros(n);
      printf("Ejecucion terminada introduce n para salir o cualquier otra tecla para continuar: " );
      getchar();
      cont = getchar();
      menu = (cont == 'n')?SALIR:CONTINUAR; 
    }    
  } while (menu != SALIR);
  return 0;
}

/** 
* Lee un numero entero desde el input standard
* @return entero leido
*/
int leeEntero() {
  int i;
  scanf("%i",&i);
  return i;
}

/** 
* Calcula todos los centros de un numero n
* @param n 
*/
void calcularCentros(int n) {
  int nucleo;

  for (int i = 6; i <= n; i++) {
    int centro = calculaCentro(i);
    if (centro) {
      mostrarCentro(i);
    } 
  }
}

/** 
* Suma los numeros de 1 a n
* @param n
* @return suma de los numeros anteriores a n
*/
int sumaAnteriores(int n){
  return ((n * (n+1)) /2);
}

/*
* Obtiene el centro maximo de una lista de 1 a n
* @param n
* @return el nucleo si lo hay o 0 (FALSE)
*/
int calculaCentro(int n) {
  //float m = sqrt((n*n+n)/2);
  return calcularPosteriores(n+1, sumaAnteriores(n-1));
}

/*
* Muestra por pantalla detalladamente el centro de n con las listas
* @param n
* @param centro
* @return el nucleo si lo hay o 0 (FALSE)
*/
void mostrarCentro(int n) {
  int ult = ultimo(n, sumaAnteriores(n));

  printf("El centro %i y sus grupos son: \n",n);
  if (n < 50) {
    printf("\t-Izquierda: ");
    mostrarNumeros(1,n);
    printf("\t-Derecha: ");
    mostrarNumerosHasta(n,sumaAnteriores(n));
  } else {
    printf("\t-Izquierda: ");
    printf("1 2 ... %i %i\n", n -2, n-1);
    printf("\t-Derecha: ");
    printf("%i %i ... %i %i\n", n +1, n +2, ult -1, ult);
  }
  
  
}

/*
* Muestra por pantalla los numeros de n a m-1
* @param n
* @param m
*/
void mostrarNumeros(int n, int m) {
  for (n; n < m; n++) {
    printf("%i ",n);
  }
  printf("\n");
}

/*
* Muestra por pantalla los numeros de n hasta que sumen m
* @param n
* @param m
*/
void mostrarNumerosHasta(int n, int m) {
  int acc = n;

  while (acc < m) {
    n++;
    acc = acc + n;
    printf("%i ",n);
  }

  printf("\n");
}

/*
* Calcula los numeros posteriores a n hasta llegar a max
* @param n
* @param max
* @return 1 si llega hasta max 0 si se pasa
*/
int calcularPosteriores(int n, int max) {
  int acc = n;
  while (acc <= max) {
     
    if (acc == max) { 
      return 1;
    }

    n++;
    acc = acc + n;   
  }
  
  return 0;
}

/*
* Obtiene el ultimo numero de una serie desde n hasta que sumen m
* @param n
* @param m
* @return el ultimo numero de la serie
*/
int ultimo(int n, int m) {
  int acc = n;

  while (acc < m) {
    n++;
    acc = acc + n;
  }

  return n;
}