#include <stdlib.h>
#include <stdio.h>

typedef struct no No;

struct no{
    char letra;
    struct ponto *prox;
};

No *criar_no(){ //FUNCAO PARA CRIAR NO
    No *novo =(No *)malloc(sizeof(No)); // ALOCA UM NOVO NÓ NA MEMORIA
    return novo; // RETORNA O NOVO NÓ CRIADO
}

No *inserir(No *HEAD, char letra){
    No *novo_no = criar_no(); //CRIA UM NO VAZIO
    novo_no->letra = letra; // COLOCA A LETRA DIGITADA NESSE NO

    if(HEAD == NULL){ // VERIFICA SE A LISTA ESTÁ VAZIA
        HEAD = novo_no; // APONDANDO HEAD PARA O PRIMEIRO NO
        novo_no->prox = NULL; // DIZENDO QUE O PROXIMO É NULL
    }
    else{ // CASO A LISTA JÁ TENHA NOS
        novo_no->prox = HEAD; // FAZ COM QUE O NOVO NO APONTE PARA ONDE A LISTA ESTÁ APONTANDO
        HEAD = novo_no; // FAZ COM QUE O HEAD APONTE PARA O PRIMEIRO NO
    }

    return HEAD; // RETORNA A LISTA
}

void imprimir_lista(No *HEAD){ //IMPRIMIR LISTA
    No *temp = HEAD; // NUNCA PODE-SE MUDAR O HEAD DE POSIÇÃO, POR ISSO USE TEMP

    while(temp!= NULL){ // ENQUANTO TEMP FOR DIFERENTE DE NULL
        printf("%c", temp->letra); // PRINTA A LETRA
        temp = temp->prox; // PASSA PARA A PROXIMA POSIÇÃO
    }
}


int main(){

    No *HEAD = NULL; // CABEÇA DA LISTA, ELA VAI APONTAR O PRIMEIRO
    char letra = 'a';

    HEAD = inserir(HEAD, letra);
    imprimir_lista(HEAD);
}
