#include <stdio.h>
#include <stdlib.h>

typedef struct elemento TListaDupEnc;
struct elemento
{
  int valor;
  TListaDupEnc *proximo;
  TListaDupEnc *anterior;
};
//Criar 2 variáveis globais.
TListaDupEnc *inicio;
TListaDupEnc *fim;
int tamanho;

// Criando prototipos de função
void criaLista();
TListaDupEnc *aloca(int valor);
void insereInicio(int valor);
void insereFim(int valor);
void inserePosicao(int valor, int posicao);
void removeInicio();
void removeFim();
void imprimeLista();
void imprimeListaContrario();

//Criar 2 elemmentos nulos na lista.
void criaLista()
{
  inicio = NULL;
  fim = NULL;
  tamanho = 0;
}
//Alocar um dado, e como funciona o esquema do lista duplamente encadeada:
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
  TListaDupEnc *atual = inicio;
  inicio = atual->proximo;
  inicio->anterior = NULL;
  tamanho--;
}
void removeFim()
{
  TListaDupEnc *atual = fim;
  fim = atual->anterior;
  fim->proximo = NULL;
  tamanho--;
}

//Inserir no inicio da lista:
void insereInicio(int valor)
{
  TListaDupEnc *novo = aloca(valor); //criar novo elemento
  //verificar se o inicio for nulo, se sim, inicio recebe novo e o fim vai ser novo também, pois se os dois são nulos o inico e fim recebe o novo.
  if (inicio == NULL)
  {
    inicio = novo;
    fim = novo;

    //Se a lista já tiver dado se cria outro elemento e aponta o ant para o dado 2 e prox do dado 2 para o 1.
  }
  else
  {
    TListaDupEnc *atual; //criar novo elemento caso tenha dado no inicio da lista.
    atual = inicio;
    novo->proximo = atual;
    atual->anterior = novo;
    inicio = novo;
  }
  tamanho++;
}

//Inserir no fim da lista:
void insereFim(int valor)
{
  TListaDupEnc *novo = aloca(valor); //criar novo elemento
  //verificar se o inicio for nulo, se sim, inicio recebe novo e o fim vai ser novo também, pois se os dois são nulos o inico e fim recebe o novo.
  if (inicio == NULL)
  {
    inicio = novo;
    fim = novo;
    //Se a lista já tiver dado se cria outro elemento e aponta o ant para o dado 2 e prox do dado 2 para o 1.
  }
  else
  {
    TListaDupEnc *atual; //criar novo elemento caso tenha dado no inicio da lista.
    atual = fim;
    novo->anterior = atual;
    atual->proximo = novo;
    fim = novo;
  }
  tamanho++;
}

//Inserir no inicio da lista:

//Função para imprimir a lista:
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

//Função para imprimir a lista:
void imprimeListaContrario()
{
  TListaDupEnc *atual;
  atual = fim;
  while (atual)
  {
    printf("%d\n", atual->valor);
    atual = atual->anterior;
  }
}
