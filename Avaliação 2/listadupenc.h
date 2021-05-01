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

void criaLista();
TListaDupEnc *aloca(int valor);
void insereInicio(int valor);
void insereFim(int valor);
void removeInicio();
void removeFim();
void imprimeLista();

void criaLista()
{
  inicio = NULL;
  fim = NULL;
  tamanho = 0;
}

TListaDupEnc *aloca(int valor)
{
  TListaDupEnc *novo = (TListaDupEnc *)malloc(sizeof(TListaDupEnc));
  novo->valor = valor;
  novo->anterior = NULL;
  novo->proximo = NULL;
  return novo;
}

void removeInicio()
{
  if (tamanho == 0)
  {
    printf("A LISTA ESTÁ VAZIA. IMPOSSÍVEL REMOVER PRIMEIRO ELEMENTO. \n");
  }
  else
  {
    TListaDupEnc *atual = inicio;
    inicio = atual->proximo;
    inicio->anterior = NULL;
    tamanho--;
  }
}
void removeFim()
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

void insereInicio(int valor)
{
  TListaDupEnc *novo = aloca(valor);

  if (inicio == NULL)
  {
    inicio = novo;
    fim = novo;
  }
  else
  {
    TListaDupEnc *atual;
    atual = inicio;
    novo->proximo = atual;
    atual->anterior = novo;
    inicio = novo;
  }
  tamanho++;
}

void insereFim(int valor)
{
  TListaDupEnc *novo = aloca(valor);

  if (inicio == NULL)
  {
    inicio = novo;
    fim = novo;
  }
  else
  {
    TListaDupEnc *atual;
    atual = fim;
    novo->anterior = atual;
    atual->proximo = novo;
    fim = novo;
  }
  tamanho++;
}

void imprimeLista()
{
  TListaDupEnc *atual;
  atual = inicio;
  while (atual)
  {
    printf("%d\n", atual->valor);
    atual = atual->proximo;
  }
}

void numOcorrencias(int search)
{
  TListaDupEnc *atual;
  int count = 0;
  atual = inicio;
  while (atual)
  {
    if (atual->valor == search)
    {
      count++;
    }
    atual = atual->proximo;
  }
  printf("Número de vezes que o valor %d apareceu: %d\n", search, count);
}