#include <stdio.h>
#include <stdlib.h>

typedef struct elemento TListaDupEnc;
struct elemento
{
  int data;
  TListaDupEnc *next;
  TListaDupEnc *prev;
  TListaDupEnc *head;
};

TListaDupEnc *inicio;
TListaDupEnc *fim;
int tamanho;

TListaDupEnc *criaLista()
{
  TListaDupEnc *l = (TListaDupEnc *)malloc(sizeof(TListaDupEnc));
  if (l != NULL)
  {
    l->head = NULL;
    return l;
  }
  return NULL;
}

TListaDupEnc *criaNodo(int data)
{
  TListaDupEnc *n = (TListaDupEnc *)malloc(sizeof(TListaDupEnc));
  if (n != NULL)
  {
    n->data = data;
    n->next = NULL;
    n->prev = NULL;
    return n;
  }
  return NULL;
}

int inserirInicio(TListaDupEnc *l, int data)
{
  if (l != NULL)
  {
    TListaDupEnc *n = criaNodo(data);
    if (l->head == NULL)
    {
      l->head = n;
      n->next = n->prev = n;
      return 1;
    }
    else
    {
      TListaDupEnc *last = l->head->next;
      n->prev = last->prev;
      l->head->next = n;
      n->next = last;
      last->prev = n;
      return 1;
    }
  }
}

int inserirFim(TListaDupEnc *l, int data)
{
  if (l != NULL)
  {
    TListaDupEnc *n = criaNodo(data);
    if (l->head == NULL)
    {
      l->head = n;
      n->next = n->prev = n;
      return 1;
    }
    else
    {
      TListaDupEnc *last = l->head->prev;
      n->next = last->next;
      l->head->prev = n;
      n->prev = last;
      last->next = n;
      return 1;
    }
  }
}

void display(TListaDupEnc *l)
{
  if (l != NULL && l->head != NULL)
  {
    TListaDupEnc *temp = l->head;
    while (temp->next != l->head)
    {
      printf("%d ", temp->data);
      temp = temp->next;
    }
    printf("%d ", temp->data);
  }
}