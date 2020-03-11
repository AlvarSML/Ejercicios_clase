#include<stdio.h>
#include<math.h>

/* RODRIGO PENDEJO */

void leerCoeficientes(float *a, float *b, float *c);
void calculaSoluciones(int,float,float,float);
int determinarTipo(float,float,float);
float calculaRadicando(float,float,float);
void mostrarResultados(int,float,float);

int main() {
  float a,b,c;
  int tipo;

  leerCoeficientes(&a, &b, &c);
  tipo = determinarTipo(a, b, c);
  calculaSoluciones(tipo,a,b,c);
  return 0;
}

void leerCoeficientes(float *a, float *b, float *c) {
  printf("introduce una ecuacion \"a b c\": ");
  scanf("%f %f %f",a,b,c);
}

int determinarTipo(float a, float b, float c){
  if (a == 0 && b == 0) {
    return 1;
  } else if (a == 0 && b != 0) {
    return 2;
  } else {
    float radicando = calculaRadicando(a,b,c);
    if (radicando == 0) {
      return 3;
    } else if (radicando >= 0) {
      return 4;
    } else {
      return 5;
    }
  }
}

float calculaRadicando(float a, float b, float c) {
  return pow(b,2) - 4*a*c;
}

void calculaSoluciones(int tipo, float a, float b, float c) {
  float d = calculaRadicando(a, b, c);
  float solucion, solucion2;

  switch(tipo){
    case 1:     
      break;
    case 2:
      solucion = -c/b;
      break;
    case 3:
      solucion = -b/a*2;
      break;
    case 4:      
      solucion = (-b + sqrt(d))/(a*2);
      solucion2 = (-b - sqrt(d))/(a*2);
      break;
    case 5:
      solucion = -b/a*2;
      solucion2 = d/a*2;
      break;
  }

  mostrarResultados(tipo, solucion, solucion2); 
}

void mostrarResultados(int tipo, float x1, float x2) {
  switch(tipo) {
    case 1:
      printf("La ecuacion esta degradada\n");
      break;
    case 2:
      printf("Ecuacion de primer grado\n");
      printf("Solucion: x = %f\n",x1);
      break;
    case 3:
      printf("Solo hay una raiz real\n");
      printf("Solucion: x = %f\n",x1);
      break;
    case 4:
      printf("Dos raices reales\n");
      printf("Solucion: x1 = %f, x2 = %f\n",x1, x2);
      break;
    case 5:
      printf("Dos raices complejas\n");
      printf("Solucion: x1 = %f, x2 = %f\n",x1, x2);
      break;
  }
}

