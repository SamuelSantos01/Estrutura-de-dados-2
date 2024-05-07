#include <stdio.h>
#include <stdlib.h>

#include <locale.h>
#include "definicao.h"


Nodo* criarNo(int chave){
    Nodo* novoNo = (Nodo*)malloc(sizeof(Nodo));
    if(novoNo){
        novoNo->chave = chave;
        novoNo->direito = NULL;
        novoNo->esquerdo = NULL;
    }
    return novoNo;
}

void percorrer(Nodo* raiz){
    
    if(raiz != NULL){
        printf("%d, ",raiz->chave);
        percorrer(raiz->esquerdo);
        percorrer(raiz->direito);
    }
}

void adicionarNumero(Nodo**raiz, int chave){
    Nodo*novoNo = criarNo(chave);

    if(*raiz == NULL){
        *raiz = novoNo;
    }
    else{
        Nodo *atual = *raiz;
        Nodo *pai = NULL;

        while(atual != NULL){
            pai = atual;
            if(chave <= atual->chave){
                atual = atual->esquerdo;
            }else{
                atual = atual->direito;
            }
        }
        
        if(chave <= pai->chave){
            pai->esquerdo = novoNo;
        }else{
            pai->direito = novoNo;
        }
    }
}

int main(){

    int sentinela = 0, adicionar;
    Nodo* raiz = NULL;
    printf("Arvore binaria\n");

    do{

        printf("Que operação deseja fazer:\n1- Adicionar elemento na arvore\n2-percorrer a arvore\n3-Ecerrar a aplicação\n");
        scanf("%d", &sentinela);

        switch (sentinela)
        {
        case 1:
            printf("Digite o número que deseja adicionar: ");
            scanf("%d",&adicionar);
            adicionarNumero(&raiz, adicionar);
            break;
        case 2:
            printf("Vamos percorrer a arvore:\n\n");
            percorrer(raiz);
        default:
            break;
        }
    }while(sentinela != 3);

    return 0;
}