#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "salas.h"

struct lista { // Definição da lista
    int prox;
    struct salas Room[MAXSALAS]; // Vetor de salas com MAX posições
};

Lista* criaSala() {
    Lista* list = (Lista*)malloc(sizeof(Lista));
    if (list != NULL) {
        list->prox = 0;
    }
    return list;
}

int insereOrdenada(Lista* list, Salas room) {
    if (list == NULL || list->prox == MAXSALAS) {
        return 0;
    }

    int k, i = 0;
    while (i < list->prox && list->Room[i].capacidadeMaxima < room.capacidadeMaxima) {
        i++;
    }

    for (k = list->prox - 1; k >= i; k--) {
        list->Room[k + 1] = list->Room[k];
    }

    list->Room[i] = room;
    list->prox++;
    return 1;
}

void imprimeLista(Lista* list) {

    if (list == NULL)
        return;

    printf("\n\nDADOS DAS SALAS\n");
    printf("-------------------------------\n");
    for (int i = 0; i < list->prox; i++) {
        printf("\nBloco: %c", list->Room[i].bloco);
        printf("\nIdentificação: %d", list->Room[i].identificacao);
        printf("\nCapacidade Atual: %d", list->Room[i].capacidadeAtual);
        printf("\nCapacidade Máxima: %d", list->Room[i].capacidadeMaxima);
        printf("\nTipo da sala: %s", list->Room[i].tipoSala);
        printf("\n-------------------------------");
    }



  
}

void addSala(Lista* sala, Salas vetSalas[]) {
    if (sala->prox < MAXSALAS) {
        printf("\nInsira o bloco: ");
        scanf(" %c", &vetSalas[sala->prox].bloco);
        printf("Insira a identificação: ");
        scanf("%d", &vetSalas[sala->prox].identificacao);
        printf("Insira a capacidade máxima: ");
        scanf("%d", &vetSalas[sala->prox].capacidadeMaxima);
        printf("Insira a capacidade atual: ");
        scanf("%d", &vetSalas[sala->prox].capacidadeAtual); 
        printf("Tipo da sala: ");
        scanf("%s", vetSalas[sala->prox].tipoSala); 

        insereOrdenada(sala, vetSalas[sala->prox]);
    } else {
        printf("MAXIMO DE SALAS ATINGIDO\n");
    }
}


void taxaOcupacao(Lista* sala, Salas vetSalas[]) {
    char tipoDeSala[20];
    
    printf("Insira a sala que deseja consultar a taxa de ocupacao: ");
    scanf(" %s",&tipoDeSala);




    if (sala->prox > 0) {
        float ocupacaoMaximo = 0, ocupacaoAtual = 0, razao;
        for (int i = 0; i < sala->prox; i++) {
            if(strcmp(sala->Room[i].tipoSala,tipoDeSala)==0 ){
                ocupacaoMaximo += sala->Room[i].capacidadeMaxima;
                ocupacaoAtual += sala->Room[i].capacidadeAtual;
            }
            
        }
        razao = (ocupacaoAtual / ocupacaoMaximo) * 100;
        printf("A taxa de ocupação é de %.2f%%\n", razao);
    } else {
        printf("Não há salas cadastradas\n");
    }
}



void ocupacaoComputadores(Lista* sala, Salas vetSalas[]){
        int ocupacaoMaximo=0;
        int ocupacaoAtual=0;
        int menos;
    for (int i = 0; i < sala->prox; i++)
        {
            if(strcmp(sala->Room[i].tipoSala,"informatica")==0 ){
            ocupacaoMaximo+=sala->Room[i].capacidadeMaxima;
            ocupacaoAtual+=sala->Room[i].capacidadeAtual;
            }
        }
    menos = ocupacaoMaximo-ocupacaoAtual;
    printf("São necessarios %d computadores no campus, para atingir 100%%\n",menos);
    
}






void imprimeListaOrdenada(Lista* list) {
    if (list == NULL)
     return;

    int tipoSalaImpressa = 0;

    for (int i = 0; i < list->prox; i++) {
        int tipoSalaJaImpressa = 0;

        for (int k = 0; k < i; k++) {
            if (strcmp(list->Room[i].tipoSala, list->Room[k].tipoSala) == 0) {
                tipoSalaJaImpressa = 1;
                break;
            }
        }

        if (!tipoSalaJaImpressa) {
            printf("\n\nDADOS DAS SALAS %s \n", list->Room[i].tipoSala);

            for (int j = 0; j < list->prox; j++) {
                if (strcmp(list->Room[i].tipoSala, list->Room[j].tipoSala) == 0) {
                    printf("\nBloco: %c", list->Room[j].bloco);
                    printf("\nIdentificação: %d", list->Room[j].identificacao);
                    printf("\nCapacidade Atual: %d", list->Room[j].capacidadeAtual);
                    printf("\nCapacidade Máxima: %d", list->Room[j].capacidadeMaxima);
                    printf("\nTipo da sala: %s", list->Room[j].tipoSala);
                    printf("\n-------------------------------");
                }
            }
        }
    }
}


void insereAutomatico(Lista* salas){




    char BlocoSala[]="FFE";
    int identificacaoSala[]={2,1,1};
    int CapAtualSala[]={40,35,27};
    int capMaximaSala[]={40,40,40};
    char tipoSala[100][100] = {"teorica","informatica","teorica"};


    if (salas->prox < MAXSALAS) {
       for (int i = 0; i < 3; i++)
       {
        salas->Room[i].bloco=BlocoSala[i];
        salas->Room[i].capacidadeAtual=CapAtualSala
        [i];
        salas->Room[i].capacidadeMaxima=capMaximaSala
        [i];
        salas->Room[i].identificacao=identificacaoSala[i];
        strcpy(salas->Room[i].tipoSala, tipoSala[i]);

        insereOrdenada(salas, salas->Room[i]);

       }

    } 




    
}

void imprimeListaTipo(Lista* Salas){
    char tipoSala[20];

    printf("Insira a sala que deseja buscar: ");
    scanf("%s",&tipoSala);
    for (int i = 0; i < Salas->prox; i++)
    {
        if(strcmp(Salas->Room[i].tipoSala,tipoSala)==0){
             printf("\nBloco: %c", Salas->Room[i].bloco);
                    printf("\nIdentificação: %d", Salas->Room[i].identificacao);
                    printf("\nCapacidade Atual: %d", Salas->Room[i].capacidadeAtual);
                    printf("\nCapacidade Máxima: %d", Salas->Room[i].capacidadeMaxima);
                    printf("\nTipo da sala: %s", Salas->Room[i].tipoSala);
                    printf("\n-------------------------------");
        }
    }
    
}








void tela() {
    Salas vetSalas[MAXSALAS];
    Lista* Salas = criaSala();

    int num;

    do {
        printf("\n[1] Cadastrar Sala");
        printf("\n[2] taxa de Ocupacao");
        printf("\n[3] Taxa de Ocupacao - computadores");
        printf("\n[4] Imprimir espaços fisicos-todos");
        printf("\n[5] Inserir automatico");
        printf("\n[6] Imprimir espaços fisicos-seleciona");
        printf("\n[7] Sair");
        printf("\nDigite sua opção: ");
        scanf("%d", &num);

        switch (num) {
        case 1:
            printf("\nDADOS SALAS\n");
            addSala(Salas, vetSalas);
            break;

        case 2:
            taxaOcupacao(Salas, vetSalas);
            break;

        case 3:
            ocupacaoComputadores(Salas,vetSalas);
            break;
        
        case 4:
           imprimeListaOrdenada(Salas); 
            break;
        case 5:
            insereAutomatico(Salas);
            break;

        case 6: 
            imprimeListaTipo(Salas);
            break;    
        }
    } while (num != 7);

   

 
}
