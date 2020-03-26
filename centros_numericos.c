/* Directivas del preprocesador */
#include <stdio.h>
#include <math.h>

int leeEntero();
void calcularCentros(int);
int calculaCentro(int);
int sumaAnteriores(int);
void mostrarCentro(int);
int calcularPosteriores(int, int);

void mostrarNumerosHasta(int, int);
void mostrarNumeros(int, int);

int main() {

  int n;

  printf("Introduce un entero (1-5000): ");
  n = leeEntero();
  //printf("%i\n",calculaCentro(n));
  //printf("%i\n",sumaAnteriores(n-1));
  //printf("%i\n",sumaAnteriores(n-1));
  //printf("%f",sqrt((n*n+n)/2));
  //mostrarNumeros(1,5);
  calcularCentros(n);
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
  if (n == 1) {
    return 1;
  } else {
    return n + sumaAnteriores(n-1);
  }
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
  printf("El centro %i y sus grupos son: \n",n);
  printf("\t-Izquierda: ");
  mostrarNumeros(1,n);
  printf("\t-Derecha: ");
  mostrarNumerosHasta(n,sumaAnteriores(n));
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