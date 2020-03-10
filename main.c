#include <stdio.h>

void LeerFracción(int * num, int * den);
void EscribirFraccion(int num, int den);
void SumarFracciones(int num1, int den1, int num2, int den2, int * numr, int * denr);
void RestarFracciones(int num1, int den1, int num2, int den2, int * numr, int* denr);
void MultiplicarFracciones(int num1, int den1, int num2, int den2, int * numr, int * denr);
void DividirFracciones(int num1, int den1, int num2, int den2, int * numr, int* denr);

int gcd(int,int);
int lcm(int,int);

int main(void) {
  int num, den;
  SumarFracciones(2, 5, 3, 7, &num, &den);
  EscribirFraccion(num, den);
  return 0;
}

void LeerFraccion(int * num, int * den) {
  scanf("%i/%i\n",num,den);
}

void EscribirFraccion(int num, int den){
  printf("%i/%i\n",num,den);
}

void SumarFracciones(int num1, int den1, int num2, int den2, int * numr, int * denr){
  *denr = lcm(den1,den2);
  *numr = (num1 * (*denr/den1)) + (num2 * (*denr/den2));
}

int gcd(int a, int b) {  
  if (a == 0) 
    return b;  
  return gcd(b % a, a);  
}  

int lcm(int a, int b) {  
  return (a*b)/gcd(a, b);  
}  