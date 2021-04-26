#include "listadupenc.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
  criaLista();
  int i;
  for (i = 0; i < 5; i++)
  {
    insereInicio(i);
  }
  imprimeLista();
  printf("------------\n");
  insereInicio(10);
  insereFim(20);
  imprimeLista();
  printf("------------\n");
  removeInicio();
  removeFim();
  imprimeLista();
}