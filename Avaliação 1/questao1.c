#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

struct Ponto{
  float X;
  float Y;
};

struct Circulo{
  char Nome;
  struct Ponto Centro;
  float Raio;
};

struct Circulo* criaCirculo(char *a, float x, float y, float raio){
  struct Circulo *ptr = (struct Circulo *)malloc(sizeof(struct Circulo));
  strcpy(&ptr->Nome,a);
  ptr->Centro.X = x;
  ptr->Centro.Y = y;
  ptr->Raio = raio;
  return ptr;
}

int contem(struct Circulo *p, struct Circulo *s){
  double dist;
  float x1, x2, y1, y2, raio1, raio2;
  x1 = p->Centro.X;
  y1 = p->Centro.Y;
  x2 = s->Centro.X;
  y2 = s->Centro.Y;
  raio1 = p->Raio;
  raio2 = s->Raio;
  dist = sqrt((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1));
  if(dist+raio2 <= raio1){
    return 1;
  }
  else{
    return 0;
  }
}

int main(void)  {
  struct Circulo *c1, *c2, *c3;  
  c1 = criaCirculo("Circulo01",3.0,4.0,2.0);  
  c2 = criaCirculo("Circulo02",3.0,3.0,1.0);  
  c3 = criaCirculo("Circulo03",1.0,5.0,1.0);  
  printf("%d\n",contem(c1,c2));  
  printf("%d\n",contem(c1,c3)); 
  free(c1);  
  free(c2);  
  free(c3);  
  return 0;  
}