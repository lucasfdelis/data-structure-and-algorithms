#include "pilhaenc.h"
#include <stdio.h>

int main (void) {
	
	// cria uma pilha sequencial diretamente na memória
	TPilhaEnc pilha;
	TPilhaEnc pilha2;

    // coloca a pilha num estado válido (e consistente)
    criarPilha( &pilha );
    criarPilha( &pilha2);

    if( pilhaVazia( pilha ) ) printf( "Esta vazia! \n" );
    
    // atribuir dados a pilha 1
	empilhar( &pilha, 10 );
    empilhar( &pilha, 20 );
    empilhar( &pilha, 30 );
	
	// imprimir a primeira pilha
	printf( "Pilha 1:\n" );
    imprimir(pilha);
    
    // clona a primeira pilha e envia seus dados para a pilha 2
	clonar(&pilha, &pilha2);
	
	// imprimir a pilha 2
	printf( "Pilha 2:\n" );
	imprimir(pilha2);
	return 0;
}