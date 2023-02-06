#include<stdio.h>
#include<stdlib.h>
#include "BBT_S02.c"
int main (){
    lista ptrl;
    Musica a;
    int escolha,posicao,b;
    char nome[20];
    lista_inicializar(&ptrl);
    do{
         Menu();
        printf("Digite uma opcao valida: ");
        scanf("%d", &escolha);
        fflush(stdin);
        system("cls");
        switch(escolha){
            case 0:;
            return 0;
            case 1:
                printf("Digite o nome da musica: ");
                gets(a.nome);
                fflush(stdin);
                printf("Digite o cantor da musica: ");
                gets(a.cantor);
                fflush(stdin);
                printf("Digite a duracao(min) da musica: ");
                scanf("%d", &a.duracao.min);
                fflush(stdin);
                printf("Digite a duracao(seg) da musica: ");
                scanf("%d", &a.duracao.seg);
                fflush(stdin);
                if(lista_inseririnicio(&ptrl,a)){
                    printf("Tudo certo\n");
                }else {
                    printf("Erro!Lista cheia\n");
                }
                break;
            case 2:
                printf("Digite o nome da musica :");
                gets(nome);
                posicao = pesquisarelemento(&ptrl, nome);
                    if(posicao != -1){
                        printf("A posicao da %s na lista eh %d", nome,posicao);
                    }else{
                        printf("Erro: Lista Vazia\n");
                    }
                    break;
            case 3:
                b = lista_removerfinal(&ptrl);
                if(b != -1){
                    printf("Elemento removido\n");
                }else{
                    printf("Erro: Lista vazia\n");
                }
                break;
            case 4:
                imprimirlista(&ptrl);
                    break;
                default: printf("Saindo\n");
    }
    }while(b!=5);
 return 0;
}
