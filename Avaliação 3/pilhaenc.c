#include "pilhaenc.h"
#include <stdio.h>
#include <stdlib.h>

/* Criar uma pilha vazia */
void criarPilha( TPilhaEnc *pilha )
{
	*pilha = NULL;
}

/* Verificar se a pilha está vazia ou não */
int pilhaVazia( TPilhaEnc pilha )
{
	return pilha == NULL;
}

/* Tamanho da pilha */
int tamanhoPilha( TPilhaEnc pilha )
{
	int tamanho = 0;
	while( pilha != NULL ) {
		pilha = pilha->prox;
		tamanho++;
	}
	return tamanho;
}

/* Empilhar um elemento */
int empilhar( TPilhaEnc *pilha, int dado )
{
	TPilhaEnc novo;

	// aloca o no e testa pra ver se o SO alocou mesmo
	if( (novo = (no*) malloc(sizeof(no))) == NULL ) return 0;

	novo->dado = dado;
	novo->prox = *pilha;
	*pilha = novo;
	return 1;
}

/* Desempilhar um elemento */
int desempilhar( TPilhaEnc *pilha, int *dado )
{
	// se pilha está vazia
   	if ( pilhaVazia( *pilha ) ) return 0;

	TPilhaEnc aux;

	aux = *pilha;
	*dado = aux->dado;
	*pilha = (*pilha)->prox;
	
	// libera memória do nó desempilhado
	free( aux );

    return 1;
}


/* Consultar o topo pilha */
int elementoTopo( TPilhaEnc pilha, int *dado )
{
	if( pilhaVazia( pilha ) ) return 0;

	*dado = pilha->dado; // já que topo é igual ao primeiro no
	return 1;
}

/* Exibir todos os elementos da pilha */
int imprimir ( TPilhaEnc pilha )
{
	// se pilha está vazia
   	if ( pilhaVazia( pilha ) ) return 0;

    printf("Pilha=[ ");

	// varrendo todos os elementos
	while( !pilhaVazia(pilha) ){
		printf("%d ", pilha->dado);
		pilha = pilha->prox;
	}

    printf("]\n");
     return 1;
}

/* Clonar uma pilha */
int clonar (TPilhaEnc *origem, TPilhaEnc *destino)
{
    TPilhaEnc tmp;
    TPilhaEnc ptr; /* Ponteiro que percorrera a pilha "origem" */
    TPilhaEnc ptr2; /* Ponteiro que percorrera a pilha "destino" */
    
    criarPilha( &tmp);

    ptr = *origem;
    ptr2 = *destino;

    if (*origem == NULL)
    {
            return 1;
    }
    else
    {
        if ( *destino == NULL)
        {
            tmp = malloc( sizeof(TPilhaEnc) );
            tmp->dado = ptr->dado;
            tmp->prox = NULL;

            *destino = tmp;
            ptr = ptr->prox;
        }

        /* Copia para pilha temporaria */
        while(ptr != NULL)
        {
            tmp = malloc( sizeof(TPilhaEnc) );
            tmp->dado = ptr->dado;

            tmp->prox = *destino;
            *destino = tmp;

            ptr = ptr->prox;

        }

        ptr = NULL;
        ptr2 = NULL;
        /* Copia para a pilha "destino" */
        while(*destino != NULL)
        {
            if (ptr == NULL)
            {
                ptr = *destino;
                *destino = (*destino)->prox;
                ptr->prox = NULL; 
            }
            else
            {
                ptr2 = *destino;
                *destino= (*destino)->prox;
                ptr2->prox = ptr;
                ptr = ptr2;
            }
        }

        *destino = ptr;

    }

}