#include "listadupenc.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
  criaLista();
  //Tentando remover dados de uma lista vazia.
  removeInicio();
  removeFim();
  //Inserindo dados
  int i;
  for (i = 0; i < 5; i++)
  {
    insereInicio(i);
  }
  //Exibindo lista com os dados inseridos
  printf("Lista original:\n");
  imprimeLista();
  printf("\n");
  insereInicio(10);
  insereFim(20);
  printf("Lista após a adição de valores no início e no fim dela:\n");
  imprimeLista();
  printf("\n");
  removeInicio();
  removeFim();
  printf("Lista após a remoção de valores no início e no fim dela:\n");
  imprimeLista();
  printf("\n");
  //Exibindo número de ocorrencias do valor 3
  numOcorrencias(3);
}