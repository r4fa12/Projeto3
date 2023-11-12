#include "biblioteca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Tarefa Lista[maxtarefas];

int criararquivo(){
    FILE*arqtarefas = fopen("arqtarefas","wb");
  if(arqtarefas == NULL){
    return 1;
  }
    fwrite(&Lista,sizeof(Tarefa),maxtarefas,arqtarefas);
    fclose(arqtarefas);
    return 0;
}

#include "biblioteca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void limpar() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
};


int criararquivo(Tarefa Main[], char nome_arquivo[]){
    FILE *arqtarefas = fopen(nome_arquivo,"wb");
    if(arqtarefas == NULL){
        return 1;
    }
    fwrite(&Main,sizeof(Tarefa),maxtarefas,arqtarefas);
    fclose(arqtarefas);
    return 0;
}

int lerarquivo(Tarefa Main[], char nome_arquivo[]){
    FILE *arqtarefas = fopen(nome_arquivo,"rb");
    if(arqtarefas == NULL){
        return 1;
    }
    fread(&Main,sizeof(Tarefa),maxtarefas,arqtarefas);
    fclose(arqtarefas);
    return 0;
};

void Menu(){
    Tarefa Lista[maxtarefas];
    int cod;
    cod = lerarquivo(Lista, "arqtarefas");
    if(cod == 1){
        printf("Nao foi possivel ler o arquivo!");
    }
    Tarefa *tarefa = malloc(sizeof(Tarefa));
    int opcao;
    do{
        printf(" --- MENU ---\n");
        printf("1 - Criar tarefa\n2 - Deletar tarefa\n3 - Listar tarefas\n4 - Alterar tarefas\n
        "5 - Filtrar tarefas pela prioridade\n6 - Filtrar tarefas pelo estado\n7 - Filtrar tarefas pela categoria\n"
               "8 - Filtrar tarefas pela prioridade e pela categoria\n0 - Sair.\n");
        printf("Digite a operacao que deseja realizar: ");
        scanf("%d",&opcao);
        getchar();
        switch(opcao){
            case 1:
                CriarTarefa(Lista);
                break;
            case 2:
                DeletarTarefa(Lista);
                break;
            case 3:
                ListarTarefas(Lista);
                break;
            case 4:
                AlterarTarefas(Lista);
                break;
            case 5:
                FiltrarTarefasPrioridade(Lista);
                break;
            case 6:
                FiltrarTarefasEstado(Lista);
                break;
            case 7:
                FiltrarTarefasCategoria(Lista);
                break;
            case 8:
                FiltrarTarefasPC(Lista);
                break;

void CriarTarefa(){
    char tarefa[100];
    char descricao[300];
    int prioridade;
    printf("Digite sua tarefa: ");
    fgets(tarefa,sizeof(tarefa),stdin);        
    printf("Digite aqui a descricao desta tarefa: ");           
    fgets(descricao,sizeof(descricao),stdin);       
    printf("Digite aqui a prioridade desta tarefa: ");
    scanf("%d",&prioridade);
    for(int i = 0; i < maxtarefas; i++){
        if (Lista[i].existe == 0){
            strcpy(Lista[i].tarefa, tarefa);                
            strcpy(Lista[i].descricao, descricao);
            Lista[i].prioridade = prioridade;
            Lista[i].existe = 1;
            break;
        };
    };
};
void DeletarTarefa(){
    printf("Aqui está sua lista!\n");               
    ListarTarefas2();                                     
    int del;                                                
    printf("Qual tarefa deseja excluir: ");
    scanf("%d", &del);
    int pos = del - 1;
    Lista[pos].existe = 0;
    printf("Tarefa excluida com sucesso!");
};
void ListarTarefas(){
    printf("--- LISTA DE TAREFAS ---\n");               
    printf("\n");                                       
    for(int i = 0; i < maxtarefas; i++){
        if(Lista[i].existe == 1) {
            printf("Tarefa: %s", Lista[i].tarefa);
            printf("Descricao: %s", Lista[i].descricao);
            printf("Prioridade: %d", Lista[i].prioridade);
            printf("\n-----------------\n");
        }
    }
};

void ListarTarefas2(){
    for(int i = 0; i < maxtarefas; i++){            
        if(Lista[i].existe == 1) {
            int num = i + 1;
            printf("Tarefa %d: %s\n",num, Lista[i].tarefa);
        }
    }
};

void AlterarTarefas(Tarefa Main[]){
    char tarefanew[100];
    char descricaonew[100];
    int prioridadenew;
    char estadonew[100];
    char categorianew[100];
    int posicao;
    int alterado;
    int opcao;
    ListarTarefas2(Main);
    printf("Digite a tarefa que deseja alterar: ");
    scanf("%d", &alterado);
    posicao = alterado - 1;
    printf("1. Tarefa\n2. Descricao\n3. Prioridade\n4.Estado\n");
    printf("Digite qual opcao deseja alterar: ");
    scanf("%d", &opcao);
    limpar();
    if (opcao == 1){
        size_t a;
        printf("Digite o novo nome da Tarefa: ");
        fgets(tarefanew,sizeof (tarefanew), stdin);
        a = strlen(tarefanew);
        if (tarefanew[a - 1] == '\n')tarefanew[--a] = 0;
        sprintf(Main[posicao].tarefa,tarefanew);
        printf("\nO nome da Tarefa foi alterado!\n\n");
    }

    if (opcao == 2){
        size_t a;
        printf("Digite uma nova descricao para a Tarefa: ");
        fgets(descricaonew, sizeof(descricaonew), stdin);
        a = strlen(descricaonew);
        if (descricaonew[a - 1] == '\n')descricaonew[--a] = 0;
        sprintf(Main[posicao].descricao,descricaonew);
        printf("\nA descricao foi alterada!\n\n");
    }

    if (opcao == 3){
        printf("Digite uma nova prioridade para a Tarefa: ");
        scanf("%d", &prioridadenew);
        Main[posicao].prioridade = prioridadenew;
        printf("\nA prioridade foi alterada!\n\n");
    }

    if (opcao == 4){
        size_t a;
        printf("Digite o novo estado da Tarefa(Completo, Em andamento ou Nao iniciado): ");
        fgets(estadonew, sizeof(estadonew), stdin);
        a = strlen(descricaonew);
        if (descricaonew[a - 1] == '\n')descricaonew[--a] = 0;
        sprintf(Main[posicao].estado, estadonew);
        printf("\nO estado da Tarefa foi alterado!\n\n");
    }

    if (opcao == 5){
        size_t a;
        printf("Digite a nova categoria da Tarefa(Lazer, Estudos, Trabalho ou Eventos)");
        fgets(categorianew, sizeof(categorianew), stdin);
        a = strlen(descricaonew);
        if (descricaonew[a - 1] == '\n')descricaonew[--a] = 0;
        sprintf(Main[posicao].categoria, categorianew);
        printf("\nA categoria da Tarefa foi alterada!");
    }
};

void FiltrarTarefasPrioridade(Tarefa Main[]){
    int p;
    printf("Digite a prioridade da Tarefa que deseja filtrar: ");
    scanf("%d", &p);
    for(int i = 0; i < maxtarefas; i++){
        if (Main[i].prioridade == p)
            printf("Tarefas filtradas com essa prioridade: %s\n", Main[i].tarefa);
    }
};

void FiltrarTarefasEstado(Tarefa Main[]){
    int num;
    size_t a;
    char e[20];
    int x;
    int x2;
    int x3;
    int x4;
    char novoestado[20];
    sprintf(novoestado, "Completo");
    char novoestado2[20];
    sprintf(novoestado2, "Em andamento");
    char novoestado3[20];
    sprintf(novoestado3, "Nao iniciado");
    do{
        printf("Digite qual o estado da Tarefa(Completo, Em andamento ou Nao iniciado): ");
        fgets(e, sizeof(e),stdin);
        a = strlen(e);
        if (e[a - 1] == '\n') e[--a] = 0;
        x = strcmp(e, novoestado);
        x2 = strcmp(e, novoestado2);
        x3 = strcmp(e, novoestado3);
    } while (x != 0 && x2 != 0 && x3 != 0);
    printf("Tarefas filtradas com esse estado: \n");
    for(int i = 0; i < maxtarefas; i++){
        x4 = strcmp(e, Main[i].estado);
        if (x4 == 0){
            num = num + 1;
            printf("\n%s\n", Main[i].tarefa);
        }
    }
}


void FiltrarTarefasCategoria(Tarefa Main[]){
    char c[15];
    char categoria1[15];
    char categoria2[15];
    char categoria3[15];
    char categoria4[15];
    sprintf(categoria1, "Lazer");
    sprintf(categoria2, "Estudos");
    sprintf(categoria3, "Trabalho");
    sprintf(categoria4, "Eventos");
    int x1;
    int x2;
    int x3;
    int x4;
    int x5;
    size_t b;
    int num;
    do{
        printf("Digite a categoria da Tarefa que deseja filtrar(Lazer, Estudos, Trabalho ou Eventos): ");
        fgets(c, sizeof(c), stdin);
        b = strlen(c);
        if(c[b - 1] == '\n')c[--b] = 0;
        x1 = strcmp(c, categoria1);
        x2 = strcmp(c, categoria2);
        x3 = strcmp(c, categoria3);
        x4 = strcmp(c, categoria4);
    }while (x1 != 0 && x2 != 0 && x3 != 0 && x4 != 0);
    printf("Tarefas filtradas com essa categoria: \n");
    for(int i = 0; i < maxtarefas; i++){
        x5 = strcmp(c, Main[i].categoria);
        if (x5 == 0){
            num = num + 1;
            printf("\n%s\n", Main[i].tarefa);

        }
    }
    if(num == 0){
        printf("Nao existe tarefa com esta categoria!\n");
    }
}

void FiltrarTarefasPC(Tarefa Main[]){
    int p;
    char c[15];
    char categoria1[15];
    char categoria2[15];
    char categoria3[15];
    char categoria4[15];
    sprintf(categoria1, "Lazer");
    sprintf(categoria2, "Estudos");
    sprintf(categoria3, "Trabalho");
    sprintf(categoria4, "Eventos");
    int x1;
    int x2;
    int x3;
    int x4;
    int x5;
    size_t b;
    int num;
    do{
        printf("Digite a prioridade: ");
        scanf("%d", &p);
        limpar();
        printf("Digite a categoria da Tarefa que deseja filtrar(Lazer, Estudos, Trabalho ou Eventos): ");
        fgets(c, sizeof(c), stdin);
        b = strlen(c);
        if(c[b - 1] == '\n')c[--b] = 0;
        x1 = strcmp(c, categoria1);
        x2 = strcmp(c, categoria2);
        x3 = strcmp(c, categoria3);
        x4 = strcmp(c, categoria4);
    }while (x1 != 0 && x2 != 0 && x3 != 0 && x4 != 0);
    printf("Tarefas filtradas com essa prioridade e categoria: \n");
    for(int i = 0; i < maxtarefas; i++){
        x5 = strcmp(c, Main[i].categoria);
        if (x5 == 0 && Main[i].prioridade == p){
            num = num + 1;
            printf("\n%s\n", Main[i].tarefa);
        }
    }
}

int lerarquivo(){
    FILE*arqtarefas = fopen("arqtarefas","rb");
  if(arqtarefas == NULL){
    return 1;
  } 
    fread(&Lista,sizeof(Tarefa),maxtarefas,arqtarefas);
    fclose(arqtarefas);
    return 0;
};