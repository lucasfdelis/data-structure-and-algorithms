#include <stdio.h>
#include <stdlib.h>

int* uniao(int *v1, int n1, int *v2, int n2){
  int soma = n1+n2;
  int i = 0;
	int *v3 = (int *) malloc(soma * sizeof(int));
  for(int j = 0; j < n1; j++){
    v3[j] = v1[j];
    i++;
  }
  for(int j = 0; j < n2; j++){
    v3[i] = v2[j];
    i++;
  }
  return v3;
}

int main() {
  int v1[4] = {11, 13, 45, 7};
  int v2[6] = {24, 4, 16, 81, 10, 12};
  int *v3 = 0;
  v3 = uniao(v1, 4, v2, 6);
  //Como o valor foi declarado estaticamente, o valor de n1 e n2 também foi, nesse caso: 4 e 6.
  for(int i=0; i<(4+6); i++){
		printf("%d ", *(v3+i));
	}
  free(v3);
  return 0;
}
