#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct lista{
       int info;
       struct lista * prox;
       struct lista * previous;
};

typedef struct lista Lista;

Lista* inicializaLista(){
       return NULL;       
}

bool vazia(Lista * pL){
     if(pL->info == NULL)
        return true;             
     else
         return false;
}

Lista * inserir(Lista * pL, int valor){
      Lista * novo = (Lista *) malloc(sizeof(Lista));
      if(novo != NULL){
         novo->info = valor;
         novo->prox = pL;
         novo->previous = NULL;
         
         if(pL!=NULL){
         pL->previous = novo;
         }
         printf("Lista[%d] \n", novo->info);
         return novo;        
      } 
}
void imprimir_ordem_padrao(Lista *pL) {
    printf("\nORDEM PADRÃO:\n");
    while (pL != NULL) {
        printf(" %d ", pL->info);
        pL = pL->prox;
    }
    printf("\nFim da Lista Encadeada!\n\n");
}

void imprimir_ordem_inversa(Lista *pL) {
    if (pL == NULL) {
        printf("\nA lista está vazia.\n");
        return;
    }

    while (pL->prox != NULL) {
        pL = pL->prox;
    }
    
    printf("\nORDEM INVERSA:\n");
    while (pL != NULL) {
        printf(" %d ", pL->info);
        pL = pL->previous;
    }
    printf("\nFim da Lista Encadeada!\n\n");
}

Lista * buscar_ordem_padrao(Lista *pL, int valor){
      while(pL != NULL){
            if(pL->info == valor)
               return pL;  
            else
                pL=pL->prox;
      }    
      return pL;
     }

Lista * buscar_ordem_inversa(Lista *pL, int valor){
         Lista * inversa = NULL;
         while(pL != NULL){
             inversa = pL;
             pL=pL->prox;
         }
         while(inversa != NULL){
             if(inversa->info == valor)
             return inversa;
             else
             inversa = inversa->previous;         
     }
     }

Lista * remover(Lista * pL, int valor){
     Lista *p = pL;
     
    while (p != NULL && p->info != valor) {
        p = p->prox;
    }

    if (p == NULL) {
        printf("\nElemento %d não encontrado na lista.\n", valor);
        return pL;
    }

    if (p->previous != NULL) { 
        p->previous->prox = p->prox;
    } else { 
        pL = p->prox;
    }

    if (p->prox != NULL) { 
        p->prox->previous = p->previous;
    }

    free(p); 
    return pL; 
}

void libera(Lista * pL){
     
     Lista * p = pL;
     Lista * t;
     
     while(p != NULL){
           t = p->prox; /* guarda refer?ncia para o pr?ximo elemento */
           free(p);     /* libera a mem?ria apontada por p */
           p = t;       /* faz p apontar para o pr?ximo */   
     }
}

void main(){

     /* declara uma lista n?o inicializada */ 
     Lista * L;
     Lista * Q;
     
     /* inicializa lista como vazia */                 
     L = inicializaLista();     
     
     /* Checa se a lista est? vazia */
     if(vazia(&L)){
         printf("Lista Vazia! \n");                        
     }
     else{
          printf("Lista com elementos! \n");     
     }
     
     L = inserir(L, 1000);  /* insere na lista o elemento 1000 */
     L = inserir(L, 100);   /* insere na lista o elemento 100 */
     L = inserir(L, 10);    /* insere na lista o elemento 10 */
     L = inserir(L, 1);     /* insere na lista o elemento 1 */
     
     /* imprime os elementos da lista */
     printf("Imprimindo a Lista... \n\n");
     imprimir_ordem_padrao(L);
     
     /* verifica se o elemento est? na lista encadeada*/
     Q = buscar_ordem_padrao(L, 10);
     if(Q != NULL){
          printf("\nElemento %d encontrado! \n", Q->info);     
     }
     else{
          printf("\nElemento nao encontrado! \n\n");     
     }
     
     /* retira um elemento da lista encadeada */      
     printf("Removendo um valor da Lista! \n");
     L = remover(L, 10);
     
     /* imprime os elementos da lista */
     printf("Imprimindo a Lista... \n\n");
     imprimir_ordem_inversa(L);
     
     /* libera as listas da mem?ria */    
     libera(L);
     
     system("PAUSE");     
}