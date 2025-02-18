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

//Função 1 criada
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

//Função 2 criada
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


int main(){

	Lista * L;
	L = inicializaLista();

	L = inserir(L, 1000);
	L = inserir(L, 100);
	L = inserir(L, 10);

	imprimir(L);
	
	//Função 1 implementada
    pesquisar(L,1);
    
    /*Função 2 implementada, trocando o valor 100 armazenado por 1.
    Escolhi o valor 1 porque a função seguinte irá excluir o dado 
    da lista e imprimir logo em seguida a lista completa */
	alterar(L,100,1);
	
	L = remover(L, 1);
	
	imprimir(L);
	
	
	return 0;
}