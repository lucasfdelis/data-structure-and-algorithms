#include <stdio.h>
#include <stdlib.h>

//LUCAS ALVES FIDELIS ARAÚJO

typedef struct elemento TListaDupEnc;
struct elemento
{
  int valor;
  TListaDupEnc *proximo;
  TListaDupEnc *anterior;
  TListaDupEnc *inicio;
  TListaDupEnc *fim;
  TListaDupEnc *tamanho;
};

int tamanho;

TListaDupEnc *criaLista()
{
  TListaDupEnc *novo = (TListaDupEnc *)malloc(sizeof(TListaDupEnc));
  novo->inicio = NULL;
  novo->fim = NULL;
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

void removeInicio(TListaDupEnc *l)
{
  if (tamanho == 0)
  {
    printf("A LISTA ESTÁ VAZIA. IMPOSSÍVEL REMOVER PRIMEIRO ELEMENTO. \n");
  }
  else
  {
    TListaDupEnc *atual;
    atual = l->inicio;
    l->inicio = atual->proximo;
    l->inicio->anterior = NULL;
    tamanho--;
  }
}
void removeFim(TListaDupEnc *l)
{
  if (tamanho == 0)
  {
    printf("A LISTA ESTÁ VAZIA. IMPOSSÍVEL REMOVER ÚLTIMO ELEMENTO. \n");
  }
  else
  {
    TListaDupEnc *atual;
    atual = l->fim;
    l->fim = atual->anterior;
    l->fim->proximo = NULL;
    tamanho--;
  }
}

void insereInicio(int valor, TListaDupEnc *l)
{

  TListaDupEnc *novo = aloca(valor);

  if (l->inicio == NULL)
  {
    l->inicio = novo;
    l->fim = novo;
  }
  else
  {
    TListaDupEnc *atual;
    atual = l->inicio;
    novo->proximo = atual;
    atual->anterior = novo;
    l->inicio = novo;
  }
  tamanho++;
}

void insereFim(int valor, TListaDupEnc *l)
{
  TListaDupEnc *novo = aloca(valor);

  if (l->inicio == NULL)
  {
    l->inicio = novo;
    l->fim = novo;
  }
  else
  {
    TListaDupEnc *atual;
    atual = l->fim;
    novo->anterior = atual;
    atual->proximo = novo;
    l->fim = novo;
  }
  tamanho++;
}

void imprimeLista(TListaDupEnc *l)
{
  TListaDupEnc *atual;
  atual = l->inicio;
  while (atual)
  {
    printf("%d ", atual->valor);
    atual = atual->proximo;
  }
  printf("\n");
}

void numOcorrencias(int search, TListaDupEnc *l)
{
  TListaDupEnc *atual;
  int count = 0;
  atual = l->inicio;
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

int tamanhoLista(TListaDupEnc *l)
{
  TListaDupEnc *atual;
  atual = l->inicio;
  int tamanho = 0;
  while (atual != NULL)
  {
    atual = atual->proximo;
    tamanho++;
  }
  return tamanho;
}

TListaDupEnc *merge(TListaDupEnc *lst1, TListaDupEnc *lst2)
{
  TListaDupEnc *uniao = criaLista();
  int tamLst1 = tamanhoLista(lst1);
  int tamLst2 = tamanhoLista(lst2);
  TListaDupEnc *atual;
  atual = lst1->inicio;
  TListaDupEnc *atual2;
  atual2 = lst2->inicio;
  if (tamLst1 > tamLst2)
  {
    while (atual)
    {
      if (atual != NULL)
      {
        insereFim(atual->valor, uniao);
        atual = atual->proximo;
      }

      if (atual2 != NULL)
      {
        insereFim(atual2->valor, uniao);
        atual2 = atual2->proximo;
      }
    }
  }
  else
  {
    while (atual2)
    {
      if (atual != NULL)
      {
        insereFim(atual->valor, uniao);
        atual = atual->proximo;
      }

      if (atual2 != NULL)
      {
        insereFim(atual2->valor, uniao);
        atual2 = atual2->proximo;
      }
    }
  }
  return uniao;
}