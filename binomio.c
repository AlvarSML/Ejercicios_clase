/*----------------------------------------------+
|Nombre:   binomio.c                            |
|Sinopsis: El programa calcula el binomio de    |
| newton                                        |
|Descripción:                                   |
|          c:>10saludo                          |
|Directivas de compilación: compilador gcc      |
|Lista de códigos de salida del programa:       |
|  Devuelve 0.                                  |
|Organización: Universidad de Burgos            |
|Autor:   Alvar San Martin                      |
|Fecha:   18/03/2020                            |
|Versión: v1.0                                  |
+----------------------------------------------*/

/* Directivas del preprocesador */
#include<stdio.h>
#include <math.h>

/* Prototipos de las funciones */
int leeEntero();
unsigned leeEnteroPositivo();
void calculaResultado(int,int,unsigned,unsigned);
long binomial(unsigned,unsigned);
long factorial(int);

/* Funcion principal main*/
int main() {
  printf("Introduce a: ");
  int a = leeEntero();
  printf("Introduce b: ");
  int b = leeEntero();
  printf("Introduce n: ");
  int n = leeEntero();
  printf("Introduce k: ");
  int k = leeEntero();

  calculaResultado(a,b,n,k);
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
* Calcula el factorial de un numero usando una funcion recursiva
* @param n: numero del que se calcula el factorial
* @return facorial del numero
*/
long factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n-1);
  }
}

/**
* Calcula el binomial de un numero
* @param n
* @param m
* @return binomial del numero
*/
long binomial(unsigned n,unsigned k){
  return factorial(n) / factorial(k) * factorial(n - k);
}

/**
* Calcula el termino n
* @param a
* @param a
* @param a
* @param a
*/
void calculaResultado(int a, int b, unsigned n, unsigned k) {
  long termino;
  if (b > 0) {
    termino = binomial(n, k-1) * pow(a,n-(k-1)) * pow(b,k-1);
  } else if (b < 0) {
    termino = pow(-1,k-1) * pow(a,n-(k-1)) * pow(b,k-1);
  }
  printf("%li\n",termino);
}