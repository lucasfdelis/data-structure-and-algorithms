#include "listadupenc.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
  TListaDupEnc *l1 = criaLista();
  TListaDupEnc *l2 = criaLista();
  //Tentando remover dados de uma lista vazia, o que ocasiona numa mensagem de erro.
  removeInicio(l1);
  removeFim(l1);
  printf("\n");
  //Inserindo dados
  insereFim(2, l1);
  insereFim(4, l1);
  insereFim(1, l1);
  insereFim(7, l2);
  insereFim(3, l2);
  insereFim(9, l2);
  //Exibindo listas com os dados inseridos
  printf("LISTA 1:\n");
  imprimeLista(l1);
  printf("\n");
  printf("LISTA 2:\n");
  imprimeLista(l2);
  printf("\n");
  //Inserindo dados no início e no fim da lista
  insereInicio(100, l1);
  insereFim(200, l1);
  insereInicio(300, l2);
  insereFim(400, l2);
  printf("Lista 1 após a adição de valores no início e no fim dela:\n");
  imprimeLista(l1);
  printf("\n");
  printf("Lista 2 após a adição de valores no início e no fim dela:\n");
  imprimeLista(l2);
  printf("\n");
  //Removendo dados no início e no fim da lista
  removeInicio(l1);
  removeFim(l1);
  removeInicio(l2);
  removeFim(l2);
  printf("Lista 1 após a remoção de valores no início e no fim dela:\n");
  imprimeLista(l1);
  printf("\n");
  printf("Lista 2 após a remoção de valores no início e no fim dela:\n");
  imprimeLista(l2);
  printf("\n");
  //Exibindo número de ocorrencias do valor 4 na lista 1
  numOcorrencias(4, l1);
  printf("\n");
  //Gerando uma nova lista a partir da intercalação de nós das outras duas listas.
  printf("Lista 3, formada pela intercalação de nós das duas listas:\n");
  TListaDupEnc *l3 = merge(l1, l2);
  imprimeLista(l3);
  printf("\n");
}