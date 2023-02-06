#include<stdio.h>
#include<stdlib.h>
#define TAML 100

typedef struct sDuracao
{
    int min;
    int seg;
}Duracao;

typedef struct sMusica
{
    char nome[20];
    char cantor[20];
    Duracao duracao;
}Musica;

typedef struct slista
{
    Musica playlist[TAML];
    int n;
}lista;

void lista_inicializar(lista *ptrl)
{
    ptrl->n = -1;
}

int lista_cheia(lista *ptrl)
{
    if(ptrl->n+1 == TAML)
        return 1;
    else
        return 0;
}

int lista_vazia(lista *ptrl)
{
    if(ptrl->n == -1)
        return 1;
    else
        return 0;
}

int lista_inseririnicio(lista *ptrl, Musica elem)
{
    if(lista_cheia(ptrl)){
        printf("Erro! Lista cheia");
            return 1;
    }
    int i;
    ptrl->n++;
    for(i=ptrl->n;i>=1;i--){
        ptrl->playlist[i] = ptrl->playlist[i-1];
    }
    ptrl->playlist[0] = elem;
    return 1;
}

int pesquisarelemento(lista *ptrl, char nome[])
{
    if(lista_vazia(ptrl)){
        printf("Erro! Lista vazia");
            return -1;
    }
    int i;
    int retorno;
    for(i=0; i<=ptrl->n; i++){
        retorno = strcmp(ptrl->playlist[i].nome, nome);
        if(retorno == 0){
            return i;
        }
    }
    return -2;
}

int lista_removerfinal(lista *ptrl)
{   int removido;
    if(lista_vazia(ptrl)){
        printf("Erro lista vazia!");
            removido = -1;
        return removido;
    }
    ptrl->n--;
        return removido;
}

void imprimirlista(lista *ptrl)
{
    printf("Imprimir lista\n");
        if(lista_vazia(ptrl)){
            printf("Erro! A lista esta vazia");
            return 1;
    }
    int i;
    for(i=0; i<=ptrl->n; i++){
        printf(" %s - %s %d:%d\n", ptrl->playlist[i].nome, ptrl->playlist[i].cantor, ptrl->playlist[i].duracao.min, ptrl->playlist[i].duracao.seg);
    }
    printf("\n");

}

void Menu (){
printf("\n [1]- Cadastrar Musica\n");
printf("\n [2]- Pesquisar musica pelo nome\n");
printf("\n [3]- Remover musica\n");
printf("\n [4]- Imprimir lista\n");
}


