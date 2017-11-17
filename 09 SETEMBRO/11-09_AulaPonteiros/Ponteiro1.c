#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  
  int num1, num2;
  int *ptr;
  
  scanf("%i", &num1);
  ptr = &num1;
  printf("\n%i", *ptr);
  printf("\n%i\n", ptr);
  
  scanf("%i", &num2);
  ptr = &num2;
  printf("\n%i", *ptr);
  printf("\n%i",  ptr);
  
  
  printf("\n");
  system("PAUSE");	
  return 0;
}
