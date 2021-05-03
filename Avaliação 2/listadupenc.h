
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

TListaDupEnc *criaLista();
TListaDupEnc *aloca(int valor);
void removeInicio(TListaDupEnc *l);
void removeFim(TListaDupEnc *l);
void insereInicio(int valor, TListaDupEnc *l);
void insereFim(int valor, TListaDupEnc *l);
void imprimeLista(TListaDupEnc *l);
void numOcorrencias(int search, TListaDupEnc *l);
int tamanhoLista(TListaDupEnc *l);
TListaDupEnc *merge(TListaDupEnc *lst1, TListaDupEnc *lst2);