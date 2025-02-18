#include<stdio.h>
#include<stdlib.h>


struct lista{
	int info;
	struct lista * next;
};


typedef struct lista Lista;

Lista * inicializaLista(){
	return NULL;
}


Lista * inserir(Lista * pL, int valor){
	Lista * novo;
	novo = (Lista *) malloc(sizeof(Lista));
	if(novo != NULL){
		novo->info = valor;
		novo->next = pL;
		return novo;
	}
	return pL;
}

void imprimir(Lista * pL){
	while(pL != NULL){
		printf("[%d] -> ", pL->info);
		pL = pL->next;
	}
	printf("\n");
	
}


void pesquisar(Lista * pL, int valor){
    int validado = 0;
    while(pL!=NULL){
        if(valor==pL->info){
        validado = 1;
        break;
        }
        pL = pL->next;
    }
    if(validado)
    printf("Valor pesquisado (%d): VERDADEIRO", valor);
    else
    printf("Valor pesquisado (%d): FALSO", valor);
    
    printf("\n");
}


void alterar(Lista *pL, int valor, int troca){
    while(pL!=NULL){
        
        if(valor==pL->info)
        pL->info = troca;
        
        pL = pL->next;
    }
}
Lista * remover(Lista * pL, int valor){
	Lista * ant = NULL;
	Lista * pAux = pL;
	while(pAux != NULL && pAux->info != valor){
		ant = pAux;
		pAux = pAux->next;

	}
	if(pAux == NULL)
		return pL;
	if(ant == NULL)
		pL = pL->next; 
	else
		ant->next = pAux->next;
	free(pAux);
	return pL;
	
	
}


Lista * separa(Lista * pL, int n) {
    Lista * pAux = pL;
    Lista * pL2 = NULL;

    if (pL == NULL) {
        return NULL;
    }

    while (pAux != NULL && pAux->info != n) {
        pAux = pAux->next;
    }

    if (pAux == NULL) {
        return NULL;
    }

    pL2 = pAux->next;
    pAux->next = NULL;

    return pL2;
}


int main(){

	Lista * L;
	L = inicializaLista();

	L = inserir(L, 1000);
	L = inserir(L, 100);
	L = inserir(L, 10);

	imprimir(L);
	
	Lista * L2 = separa(L, 100);
	
	imprimir(L);
	imprimir(L2);
	
	
	return 0;
}




