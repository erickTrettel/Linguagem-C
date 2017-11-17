#include <stdio.h>
#include <stdlib.h>

void func1(int n);
void func2(int *n);



int main(int argc, char *argv[])
{
  int num=10;
  
  func1(num);
  printf("\n%i", num);
  
  func2(&num);
  printf("\n%i", num);
  
  printf("\n");
  system("PAUSE");	
  return 0;
}

void func1(int n){
   n = n + 10;
}
void func2(int *n){
   *n = *n + 10;
}









