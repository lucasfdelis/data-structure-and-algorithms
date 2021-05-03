#include "listadupenc.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
  TListaDupEnc *l1 = criaLista();
  TListaDupEnc *l2 = criaLista();
  //Tentando remover dados de uma lista vazia.
  removeInicio(l1);
  removeFim(l1);
  //Inserindo dados
  int i;
  for (i = 0; i < 5; i++)
  {
    insereInicio(i, l1);
  }
  //Exibindo lista com os dados inseridos
  insereInicio(100, l2);
  printf("Lista original:\n");
  imprimeLista(l1);
  printf("\n");
  insereInicio(10, l1);
  insereFim(20, l1);
  printf("Lista após a adição de valores no início e no fim dela:\n");
  imprimeLista(l1);
  printf("\n");
  removeInicio(l1);
  removeFim(l1);
  printf("Lista após a remoção de valores no início e no fim dela:\n");
  imprimeLista(l1);
  imprimeLista(l2);
  printf("\n");
  //Exibindo número de ocorrencias do valor 3
  numOcorrencias(3, l1);
}