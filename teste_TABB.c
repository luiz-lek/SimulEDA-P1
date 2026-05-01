#include "TABB.h"

int main(void){
  TABB *a = TABB_inicializa(); 
  int n;

  while(1){
    scanf("%d", &n);
    if(n < 0) break;
    a = TABB_insere(a, n);
  }
  TABB_imp_ident(a);
  int sz;
  //int* vet = maioresN(a, 5, &sz);
  //printv(vet, sz);

  while(1){
    scanf("%d", &n);
    if(n < 0) break;
    a = TABB_retira(a, n);
    TABB_imp_ident(a);
  }

  encadeador(a);
  imprime_lista(a);
  
  TABB_libera(a);
  return 0;
} 
