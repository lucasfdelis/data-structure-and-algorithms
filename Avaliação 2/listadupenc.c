#include "listadupenc.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
  //Tentando remover dados de uma lista vazia.
  TListaDupEnc *l1 = criaLista(1);
  TListaDupEnc *l2 = criaLista(2);
  insereInicio(10, l1);
  insereInicio(20, l2);
  imprimeLista(l1);
  imprimeLista(l2);
  numOcorrencias(10, l1);
  //removeInicio(l1);
  imprimeLista(l1);
}