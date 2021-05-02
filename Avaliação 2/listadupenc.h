#include <stdio.h>
#include <stdlib.h>

typedef struct elemento TListaDupEnc;
struct elemento
{
  int valor;
  TListaDupEnc *proximo;
  TListaDupEnc *anterior;
};

TListaDupEnc *inicio;
TListaDupEnc *fim;
int tamanho;

TListaDupEnc *criaLista(int valor)
{
  TListaDupEnc *novo = (TListaDupEnc *)malloc(sizeof(TListaDupEnc));
  novo->valor = valor;
  novo->anterior = NULL;
  novo->proximo = NULL;
  return novo;
}

void removeInicio(TListaDupEnc *teste)
{
  if (tamanho == 0)
  {
    printf("A LISTA ESTÁ VAZIA. IMPOSSÍVEL REMOVER PRIMEIRO ELEMENTO. \n");
  }
  else
  {
    TListaDupEnc *teste = inicio;
    inicio = teste->proximo;
    inicio->anterior = NULL;
    tamanho--;
  }
}
void removeFim(TListaDupEnc *teste)
{
  if (tamanho == 0)
  {
    printf("A LISTA ESTÁ VAZIA. IMPOSSÍVEL REMOVER ÚLTIMO ELEMENTO. \n");
  }
  else
  {
    TListaDupEnc *atual = fim;
    fim = atual->anterior;
    fim->proximo = NULL;
    tamanho--;
  }
}

void insereInicio(int valor, TListaDupEnc *teste)
{
  TListaDupEnc *aux = teste;
  if (teste->proximo == NULL && teste->anterior == NULL)
  {
    TListaDupEnc *nova = criaLista(valor);
    nova->anterior = teste;
    teste->proximo = nova;
  }
  else
  {
    while (aux->proximo != NULL)
    {
      aux = aux->proximo;
    }
    TListaDupEnc *nova = criaLista(valor);
    nova->proximo = aux;
    aux->anterior = nova;
  }
  tamanho++;
}

void insereFim(int valor, TListaDupEnc *teste)
{
  TListaDupEnc *aux = teste;
  if (teste->proximo == NULL && teste->anterior == NULL)
  {
    TListaDupEnc *nova = criaLista(valor);
    nova->anterior = teste;
    teste->proximo = nova;
  }
  else
  {
    while (aux->proximo != NULL)
    {
      aux = aux->proximo;
    }
    TListaDupEnc *nova = criaLista(valor);
    nova->anterior = aux;
    aux->proximo = nova;
  }
  tamanho++;
}

void imprimeLista(TListaDupEnc *teste)
{
  TListaDupEnc *aux = teste;
  while (aux != NULL)
  {
    printf("%d, ", aux->valor);
    aux = aux->proximo;
  }
  printf("\n\n");
}

void numOcorrencias(int search, TListaDupEnc *teste)
{
  TListaDupEnc *aux = teste;
  int count = 0;
  while (aux != NULL)
  {
    if (aux->valor == search)
    {
      count++;
    }
    aux = aux->proximo;
  }
  printf("Número de vezes que o valor %d apareceu: %d\n", search, count);
}