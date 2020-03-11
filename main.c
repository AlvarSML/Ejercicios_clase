#include <stdio.h>

void LeerFraccion(int * num, int * den);
void EscribirFraccion(int num, int den);
void SumarFracciones(int num1, int den1, int num2, int den2, int * numr, int * denr);
void RestarFracciones(int num1, int den1, int num2, int den2, int * numr, int* denr);
void MultiplicarFracciones(int num1, int den1, int num2, int den2, int * numr, int * denr);
void DividirFracciones(int num1, int den1, int num2, int den2, int * numr, int* denr);

int gcd(int,int);
int lcm(int,int);

int main(void) {
  int num, den;
  int num1, num2, den1, den2;

  int opt = 0;

  printf("Introduce la freaccion 1 \"n n\"): ");
  LeerFraccion(&num1, &den1);
  printf("Introduce la freaccion 2 \"n n\"): ");
  LeerFraccion(&num2, &den2);

  while (opt != -1) {
    printf("¿Que quieres hacer?\n");
    printf("\t1.- %i/%i + %i/%i\n",num1, den1, num2, den2);
    printf("\t2.- %i/%i - %i/%i\n",num1, den1, num2, den2);
    printf("\t3.- %i/%i * %i/%i\n",num1, den1, num2, den2);
    printf("\t4.- %i/%i / %i/%i\n",num1, den1, num2, den2);
    printf("\t0.- Salir\n");

    scanf("%i",&opt);

    switch(opt) {
      case 1:
        SumarFracciones(num1, den1, num2, den2, &num, &den);        
        break;
      case 2:
        RestarFracciones(num1, den1, num2, den2, &num, &den);   
        break;
      case 3:
        MultiplicarFracciones(num1, den1, num2, den2, &num, &den);   
        break;
      case 4:
        DividirFracciones(num1, den1, num2, den2, &num, &den);   
        break;
      case 0:
        opt = -1;
      default:
        printf("Intentalo otra vez\n\n");

    }
    EscribirFraccion(num, den);

  } 

  //RestarFracciones(num1, den1, num2, den2, &num, &den);
  MultiplicarFracciones(num1, den1, num2, den2, &num, &den);
  EscribirFraccion(num, den);
  return 0;
}

/* Funciones */
void LeerFraccion(int * num, int * den) {
  scanf("%i/%i",num,den);
}

void EscribirFraccion(int num, int den){
  printf("%i/%i\n",num,den);
}

void SumarFracciones(int num1, int den1, int num2, int den2, int * numr, int * denr){
  *denr = lcm(den1,den2);
  *numr = (num1 * (*denr/den1)) + (num2 * (*denr/den2));
}

void RestarFracciones(int num1, int den1, int num2, int den2, int * numr, int* denr){
  *denr = lcm(den1,den2);
  *numr = (num1 * (*denr/den1)) - (num2 * (*denr/den2));
}

void MultiplicarFracciones(int num1, int den1, int num2, int den2, int * numr, int * denr) {
  *denr = den1 * den2;
  *numr = num1 * num2;
}

void DividirFracciones(int num1, int den1, int num2, int den2, int * numr, int* denr) {
  *denr = num2 * den1;
  *numr = num1 * den2;
}

/* Funciones auxiliares */
int gcd(int a, int b) {  
  if (a == 0) 
    return b;  
  return gcd(b % a, a);  
}  

int lcm(int a, int b) {  
  return (a*b)/gcd(a, b);  
}  