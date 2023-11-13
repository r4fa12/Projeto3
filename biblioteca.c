#include "biblioteca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void limpar() { //função para limpar o buff
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
};


int criararquivo(Tarefa Main[], char nome_arquivo[]){ //função para criar o arquivo onde ficarão armazenadas as Tarefas
    FILE *arqtarefas = fopen(nome_arquivo,"wb"); //dei um nome para o arquivo e pedi para que escrevesse em binário
    if(arqtarefas == NULL){ //caso não haja nada no arquivo ele retorna falso ou 1
        return 1;
    }
    fwrite(&Main,sizeof(Tarefa),maxtarefas,arqtarefas); //escreve no arquivo //sera escrito todos os dados no arquivo criado com o tamanho do maxtarefas definido no .h
    fclose(arqtarefas); //fecho o arquivo
    return 0; //se tudo funcionar da maneira certa e o arquivo armazenar os dados retorna verdadeiro ou 0
}

int lerarquivo(Tarefa Main[], char nome_arquivo[]){ //função para ler os dados que foram escritos no arquivo criado na função anterior
    FILE *arqtarefas = fopen(nome_arquivo,"rb"); //seleciono o nome do arquivo que será lido e peço para ler em binário, já que este foi escrito também em binário
    if(arqtarefas == NULL){ //caso não haja nada no arquivo ele retorna falso ou 1
        return 1;
    }
    fread(&Main,sizeof(Tarefa),maxtarefas,arqtarefas); //le todas as informações do arquivo, seguindo os mesmos parâmetros de quando foi escrito
    fclose(arqtarefas); //fecha o arquivo depois de ler
    return 0; //se tudo funcionar da maneira certa e o arquivo armazenar os dados retorna verdadeiro ou 0
};

void Menu(){ //função do Menu principal
    Tarefa Lista[maxtarefas]; //struct com o tamanho definido pelo maxtarefas (100) e nomeei como Lista
    int cod;
    cod = lerarquivo(Lista, "arqtarefas"); //a Lista vai ler os dados presentes no arquivo criado anteriormente
    if(cod == 1){ //caso de erro e retorne falso ou 1
        printf("Nao foi possivel ler o arquivo!");
    }
    Tarefa *tarefa = malloc(sizeof(Tarefa));
    int opcao; //variavel para a opção que o usuário escolher no Menu principal
    do{
        printf(" --- MENU ---\n");
        printf("1 - Criar tarefa\n2 - Deletar tarefa\n3 - Listar tarefas\n4 - Alterar tarefas\n"
               "5 - Filtrar tarefas pela prioridade\n6 - Filtrar tarefas pelo estado\n7 - Filtrar tarefas pela categoria\n"
               "8 - Filtrar tarefas pela prioridade e pela categoria\n9 - Exportar tarefas pela prioridade\n"
               "10 - Exportar tarefas pela categoria\n11 - Exportar tarefas pela prioridade e categoria\n0 - Sair.\n");
        printf("Digite a operacao que deseja realizar: ");
        scanf("%d",&opcao);
        getchar();
        switch(opcao){
            case 1:
                CriarTarefa(Lista); //caso o usuário escolha a opção 1 a função CriaTarefa será chamada
                break;
            case 2:
                DeletarTarefa(Lista); //caso o usuário escolha a opção 2 a função DeletarTarefa será chamada
                break;
            case 3:
                ListarTarefas(Lista); //caso o usuário escolha a opção 3 a função ListarTarefas será chamada
                break;
            case 4:
                AlterarTarefas(Lista); //caso o usuário escolha a opção 4 a função CriaTarefa será chamada
                break;
            case 5:
                FiltrarTarefasPrioridade(Lista); //caso o usuário escolha a opção 5 a função FiltrarTarefasPrioridade será chamada
                break;
            case 6:
                FiltrarTarefasEstado(Lista); //caso o usuário escolha a opção 6 a função FiltrarTarefasEstado será chamada
                break;
            case 7:
                FiltrarTarefasCategoria(Lista); //caso o usuário escolha a opção 7 a função FiltrarTarefasCategoria será chamada
                break;
            case 8:
                FiltrarTarefasPC(Lista); //caso o usuário escolha a opção 8 a função FiltrarTarefasPC será chamada
                break;
            case 9:
                ExportarTarefasPrioridade(Lista); //caso o usuário escolha a opção 9 a função ExportarTarefasPrioridade será chamada
                break;
            case 10:
                ExportarTarefasCategoria(Lista); //caso o usuário escolha a opção 10 a função ExportarTarefasCategoria será chamada
                break;
            case 11:
                ExportarTarefasPC(Lista); //caso o usuário escolha a opção 11 a função ExportarTarefasPC será chamada
                break;
        };
    }while(opcao != 0);
    criararquivo(Lista, "arqtarefas"); //caso o usuário escolha a opção 0, tudo oq foi feito no programa será armazenado no arquivo

};

void CriarTarefa(Tarefa Main[]){ //função para criar uma nova tarefa
    char tarefa[100]; //variável onde será armazenada todos os nomes das Tarefas
    char descricao[300]; //variável onde será armazenada todas as descrições das Tarefas
    int prioridade; //variável onde será armazenada todas as prioridades das Tarefas
    char estado[100]; //variável onde será armazenada todos os estados das Tarefas
    char categoria[100]; //variável onde será armazenada todas as categorias das Tarefas
    size_t a;
    size_t b;
    size_t c;
    size_t d;
    printf("Digite sua tarefa: ");
    fgets(tarefa,sizeof(tarefa),stdin); //o fgets pega a informação digitada (que será uma string) e redireciona para a variável criada para os nomes das Tarefas
    a = strlen(tarefa);
    if (tarefa[a - 1] == '\n') tarefa[--a] = 0; //tira o barra n do fgets
    printf("Digite aqui a descricao desta tarefa: ");
    fgets(descricao,sizeof(descricao),stdin);
    b = strlen(descricao);
    if (descricao[b - 1] == '\n') descricao[--b] = 0; //tira o barra n do fgets
    printf("Digite aqui a prioridade desta tarefa: ");
    scanf("%d",&prioridade); //scanf para armzenar na variável criada anteriormente (nesse caso usei scanf porque será um numero inteiro e não uma string
    limpar(); //limpar o buff
    char novoestado[100]; //variável para armazenar o estado "Completo" como uma string
    sprintf(novoestado, "Completo");
    char novoestado2[100]; //variável para armazenar o estado "Em andamento" como uma string
    sprintf(novoestado2, "Em andamento");
    char novoestado3[100]; //variável para armazenar o estado "Nao iniciado" como uma string
    sprintf(novoestado3, "Nao iniciado");
    int comparacao; //variável para futuramente comparar 2 strings em relação ao estado da Tarefa
    int comparacao2; //variável para futuramente comparar 2 strings em relação ao estado da Tarefa
    int comparacao3; //variável para futuramente comparar 2 strings em relação ao estado da Tarefa
    do{
        printf("Digite qual o estado da Tarefa(Completo, Em andamento ou Nao iniciado): ");
        fgets(estado, sizeof(estado),stdin);
        d = strlen(estado);
        if (estado[d - 1] == '\n') estado[--d] = 0; //tira o barra n do fgets
        comparacao = strcmp(estado, novoestado);
        comparacao2 = strcmp(estado, novoestado2);
        comparacao3 = strcmp(estado, novoestado3);
    } while (comparacao != 0 && comparacao2 != 0 && comparacao3 != 0);
    char categoria1[15]; //variável para armazenar a categoria "Lazer" como uma string
    char categoria2[15]; //variável para armazenar a categoria "Estudos" como uma string
    char categoria3[15]; //variável para armazenar a categoria "Trabalho" como uma string
    char categoria4[15]; //variável para armazenar a categoria "Eventos" como uma string
    sprintf(categoria1, "Lazer");
    sprintf(categoria2, "Estudos");
    sprintf(categoria3, "Trabalho");
    sprintf(categoria4, "Eventos");
    int comparacao4; //variável para futuramente comparar 2 strings em relação a categoria da Tarefa
    int comparacao5; //variável para futuramente comparar 2 strings em relação a categoria da Tarefa
    int comparacao6; //variável para futuramente comparar 2 strings em relação a categoria da Tarefa
    int comparacao7; //variável para futuramente comparar 2 strings em relação a categoria da Tarefa
    do{
        printf("Digite qual categoria se encaixa na nova Tarefa (Lazer, Estudos, Trabalho ou Eventos): ");
        fgets(categoria, sizeof(categoria), stdin); //o fgets pega a informação digitada (que será uma string) e redireciona para a variável criada para as categorias das Tarefas
        c = strlen(categoria);
        if(categoria[c - 1] == '\n')categoria[--c] = 0; //tira o barra n do fgets
        comparacao4 = strcmp(categoria, categoria1);
        comparacao5 = strcmp(categoria, categoria2);
        comparacao6 = strcmp(categoria, categoria3);
        comparacao7 = strcmp(categoria, categoria4);
    }while (comparacao4 != 0 && comparacao5 != 0 && comparacao6 != 0 && comparacao7 != 0);
    for(int i = 0; i < maxtarefas; i++){ //laço for percorre por todas as linhas da lista e vai adicionando as informações abaixo
        if (Main[i].existe == 0){
            Main[i].posicao = 1;
            strcpy(Main[i].tarefa, tarefa); //copia o valor da string selecionada para a variável que deseja (nesse caso a variável tarefa)
            strcpy(Main[i].descricao, descricao); //copia o valor da string selecionada para a variável que deseja (nesse caso a variável descricao)
            Main[i].prioridade = prioridade; //o valor inteiro é enviado para a variável prioridade e ficam com o mesmo valor
            strcpy(Main[i].estado, estado); //copia o valor da string selecionada para a variável que deseja (nesse caso a variável estado)
            strcpy(Main[i].categoria, categoria); //copia o valor da string selecionada para a variável que deseja (nesse caso a variável categoria)
            Main[i].existe = 1; //para saber se tudo está dentro da lista
            break;
        };
    };
};

void DeletarTarefa(Tarefa Main[]){ //função para deletar uma Tarefa já criada
    printf("Aqui esta sua lista!\n");
    ListarTarefas2(Main); //lista todas as tarefas já criadas e salvas para que o usuário veja qual ele deseja deletar
    int del; //variável onde vai ser armazenada qual tarefa será deletadac
    printf("Qual tarefa deseja excluir: ");
    scanf("%d", &del); //scanf manda o numero inteiro da tarefa que deseja deletar para a variável criada anteriormente
    int pos = del - 1; //deleta a tarefa a partir da sua posição
    Main[pos].existe = 0; //caso a variável existe retorne 0 siginifica que a tarefa selecionada nao foi encontrada, portanto foi exluida
    printf("Tarefa excluida com sucesso!"); //mensagem para o usuário saber que a Tarefa foi deletada
};

void ListarTarefas(Tarefa Main[]){ //função que lista todas as Tarefas, junto com sua descrição, prioridade, estado e categoria
    printf("--- LISTA DE TAREFAS ---\n");
    printf("\n");
    for(int i = 0; i < maxtarefas; i++){ //laço for percorre por todas as linhas da lista e printa todas as informaçoes sobre a Tarefa
        if(Main[i].existe == 1) {
            printf("Tarefa: %s\n", Main[i].tarefa); //a partir da posição em que está percorrendo, será printado o nome da tarefa
            printf("Descricao: %s\n", Main[i].descricao); //a partir da posição em que está percorrendo, será printado a descrição da tarefa
            printf("Prioridade: %d\n", Main[i].prioridade); //a partir da posição em que está percorrendo, será printado a prioridade da tarefa
            printf("Estado: %s\n", Main[i].estado); //a partir da posição em que está percorrendo, será printado o estado da tarefa
            printf("Categoria: %s\n", Main[i].categoria); //a partir da posição em que está percorrendo, será printado a categoria da tarefa
            printf("\n-----------------\n\n");
        }
    }
};

void ListarTarefas2(Tarefa Main[]){ //função para listar todas as Tarefas para as próximas funções
    for(int i = 0; i < maxtarefas; i++){
        if(Main[i].existe == 1) { //caso o existe seja 1 já printara tudo oq foi feito na função acima, mas no codigo ficará mais simplificado
            int num = i + 1;
            printf("Tarefa %d: %s\n",num, Main[i].tarefa);
        }
    }
};

void AlterarTarefas(Tarefa Main[]){ //função para alterar as Tarefas já existentes
    char tarefanew[100]; //variável para armazenar a alteração do nome da Tarefa
    char descricaonew[100]; //variável para armazenar a alteração da descrição da Tarefa
    int prioridadenew; //variável para armazenar a alteração da prioridade da Tarefa
    char estadonew[100]; //variável para armazenar a alteração do estado da Tarefa
    char categorianew[100]; //variável para armazenar a alteração da categoria da Tarefa
    int posicao; //variável para a posição da Tarefa na lista
    int alterado; //variável para a escolha da Tarefa que será alterada assim que a lista for printada
    int opcao; //variável da opção que o usuário escolher alterar
    ListarTarefas2(Main); //chamei a segunda função para listar as Tarefas já criadas
    printf("Digite a tarefa que deseja alterar: ");
    scanf("%d", &alterado); //scanf para armazenar a tarefa escolhida como um numero inteiro na variável "alterado"
    posicao = alterado - 1;
    printf("1. Tarefa\n2. Descricao\n3. Prioridade\n4.Estado\n");
    printf("Digite qual opcao deseja alterar: ");
    scanf("%d", &opcao); //scanf para armazenar qual operação o usuário deseja alterar na sua Tarefa
    limpar(); //limpa o buff
    if (opcao == 1){ //caso a opção seja 1 (alterar o nome da Tarefa)
        size_t a;
        printf("Digite o novo nome da Tarefa: ");
        fgets(tarefanew,sizeof (tarefanew), stdin); //usuário digita o novo nome da Tarefa e o fgets armazena na variável "tarefanew"
        a = strlen(tarefanew);
        if (tarefanew[a - 1] == '\n')tarefanew[--a] = 0; //serve para tirar o \n
        sprintf(Main[posicao].tarefa,tarefanew); //substitui a string antiga armazenada na variável "tarefa" pela que foi  alterada
        printf("\nO nome da Tarefa foi alterado!\n\n");
    }

    if (opcao == 2){ //caso a opção seja 2 (alterar a descrição da Tarefa)
        size_t a;
        printf("Digite uma nova descricao para a Tarefa: ");
        fgets(descricaonew, sizeof(descricaonew), stdin); //usuário digita a nova descrição da Tarefa e o fgets armazena na variável "descaonew"
        a = strlen(descricaonew);
        if (descricaonew[a - 1] == '\n')descricaonew[--a] = 0; //serve para tirar o \n
        sprintf(Main[posicao].descricao,descricaonew); //substitui a string antiga armazenada na variável "descricao" pela que foi alterada
        printf("\nA descricao foi alterada!\n\n");
    }

    if (opcao == 3){ //caso a opção seja 3 (alterar a prioridade da Tarefa)
        printf("Digite uma nova prioridade para a Tarefa: ");
        scanf("%d", &prioridadenew); //usuário digita a nova prioridade da Tarefa e o scanf armazena na variável "prioridadenew"
        Main[posicao].prioridade = prioridadenew; //substitui o valor antigo armazenada na variável "prioridade" pelo nova que foi alterada
        printf("\nA prioridade foi alterada!\n\n");
    }

    if (opcao == 4){ //caso a opção seja 4 (alterar o estado da Tarefa)
        size_t a;
        printf("Digite o novo estado da Tarefa(Completo, Em andamento ou Nao iniciado): ");
        fgets(estadonew, sizeof(estadonew), stdin); //usuário digita o nova estado da Tarefa e o fgets armazena na variável "estadonew"
        a = strlen(descricaonew);
        if (descricaonew[a - 1] == '\n')descricaonew[--a] = 0; //serve para tirar o \n
        sprintf(Main[posicao].estado, estadonew); //substitui a string antiga armazenada na variável "estado" pela que foi nova que foi alterada
        printf("\nO estado da Tarefa foi alterado!\n\n");
    }

    if (opcao == 5){ //caso a opção seja 5 (alterar a categoria da Tarefa)
        size_t a;
        printf("Digite a nova categoria da Tarefa(Lazer, Estudos, Trabalho ou Eventos)");
        fgets(categorianew, sizeof(categorianew), stdin); //usuário digita a nova categoria da Tarefa e o fgets armazena na variável "categorianew"
        a = strlen(descricaonew);
        if (descricaonew[a - 1] == '\n')descricaonew[--a] = 0; //serve para tirar o \n
        sprintf(Main[posicao].categoria, categorianew); //substitui a string antiga armazenada na variável "estado" pela que foi nova que foi alterada
        printf("\nA categoria da Tarefa foi alterada!");
    }
};

void FiltrarTarefasPrioridade(Tarefa Main[]){ //função para filtrar as Tarefas a partir da prioridade
    int p; //variável para armazenar como número inteiro a prioridade que será escolhida pelo usuário
    printf("Digite a prioridade da Tarefa que deseja filtrar: ");
    scanf("%d", &p); //scanf para pegar o número que o usuário digitou e armazenar na variável "p"
    for(int i = 0; i < maxtarefas; i++){ //laço for vai percorrer pelas posições da lista de acordo com o número da prioridade, caso ache um número de prioridade igual ele vai printar na tela
        if (Main[i].prioridade == p)
            printf("Tarefas filtradas com essa prioridade: %s\n", Main[i].tarefa);
    }
};

void FiltrarTarefasEstado(Tarefa Main[]){ //função para filtrar as Tarefas a partir do estado
    int num; //contador
    size_t a;
    char e[20];
    int x; //variável para futuramente comparar 2 strings em relação ao estado da Tarefa
    int x2; //variável para futuramente comparar 2 strings em relação ao estado da Tarefa
    int x3; //variável para futuramente comparar 2 strings em relação ao estado da Tarefa
    int x4; //variável para futuramente comparar 2 strings em relação ao estado da Tarefa
    char novoestado[20]; //variável para armazenar o estado "Completo" como uma string
    sprintf(novoestado, "Completo");
    char novoestado2[20]; //variável para armazenar o estado "Em andamento" como uma string
    sprintf(novoestado2, "Em andamento");
    char novoestado3[20]; //variável para armazenar o estado "Nao iniciado" como uma string
    sprintf(novoestado3, "Nao iniciado");
    do{
        printf("Digite qual o estado da Tarefa(Completo, Em andamento ou Nao iniciado): ");
        fgets(e, sizeof(e),stdin); //fgets vai pegar o estado que u usuário digitou e vai armazenar na variável "e" que suporta string
        a = strlen(e);
        if (e[a - 1] == '\n') e[--a] = 0; //serve para tirar o \n
        x = strcmp(e, novoestado);
        x2 = strcmp(e, novoestado2);
        x3 = strcmp(e, novoestado3);
    } while (x != 0 && x2 != 0 && x3 != 0);
    printf("Tarefas filtradas com esse estado: \n");
    for(int i = 0; i < maxtarefas; i++){ //laço for vai percorrer toda a lista de acordo com o estado selecionado armazenado em "e", caso ache uma estado (string) igual vai ser printado na tela
        x4 = strcmp(e, Main[i].estado);
        if (x4 == 0){
            num = num + 1;
            printf("\n%s\n", Main[i].tarefa);
        }
    }
}


void FiltrarTarefasCategoria(Tarefa Main[]){ //função para filtrar as Tarefas de acordo com a categoria
    char c[15];
    char categoria1[15]; //variável para armazenar a categoria "Lazer" como uma string
    char categoria2[15]; //variável para armazenar a categoria "Estudos" como uma string
    char categoria3[15]; //variável para armazenar a categoria "Trabalho" como uma string
    char categoria4[15]; //variável para armazenar a categoria "Eventos" como uma string
    sprintf(categoria1, "Lazer");
    sprintf(categoria2, "Estudos");
    sprintf(categoria3, "Trabalho");
    sprintf(categoria4, "Eventos");
    int x1; //variável para futuramente comparar 2 strings em relação ao estado da Tarefa
    int x2; //variável para futuramente comparar 2 strings em relação ao estado da Tarefa
    int x3; //variável para futuramente comparar 2 strings em relação ao estado da Tarefa
    int x4; //variável para futuramente comparar 2 strings em relação ao estado da Tarefa
    int x5; //variável para futuramente comparar 2 strings em relação ao estado da Tarefa
    size_t b;
    int num; //contador
    do{
        printf("Digite a categoria da Tarefa que deseja filtrar(Lazer, Estudos, Trabalho ou Eventos): ");
        fgets(c, sizeof(c), stdin);
        b = strlen(c);
        if(c[b - 1] == '\n')c[--b] = 0; //serve para tirar o \n
        x1 = strcmp(c, categoria1);
        x2 = strcmp(c, categoria2);
        x3 = strcmp(c, categoria3);
        x4 = strcmp(c, categoria4);
    }while (x1 != 0 && x2 != 0 && x3 != 0 && x4 != 0);
    printf("Tarefas filtradas com essa categoria: \n");
    for(int i = 0; i < maxtarefas; i++){ //laço for percorre por toda a lista
        x5 = strcmp(c, Main[i].categoria); //comparação entre as duas strings da categoria
        if (x5 == 0){
            num = num + 1;
            printf("\n%s\n", Main[i].tarefa); //printa a tarefa que possui a categoria igual a digitada pelo usuário

        }
    }
    if(num == 0){ //caso o contador seja 0 então não há Tarefas com aquela categoria e será printada a mensagem abaixo
        printf("Nao existe tarefa com esta categoria!\n");
    }
}

void FiltrarTarefasPC(Tarefa Main[]){
    int p;
    char c[15];
    char categoria1[15]; //variável para armazenar a categoria "Lazer" como uma string
    char categoria2[15]; //variável para armazenar a categoria "Estudos" como uma string
    char categoria3[15]; //variável para armazenar a categoria "Trabalho" como uma string
    char categoria4[15]; //variável para armazenar a categoria "Eventos" como uma string
    sprintf(categoria1, "Lazer");
    sprintf(categoria2, "Estudos");
    sprintf(categoria3, "Trabalho");
    sprintf(categoria4, "Eventos");
    int x1; //variável para futuramente comparar 2 strings em relação a categoria da Tarefa
    int x2; //variável para futuramente comparar 2 strings em relação a categoria da Tarefa
    int x3; //variável para futuramente comparar 2 strings em relação a categoria da Tarefa
    int x4; //variável para futuramente comparar 2 strings em relação a categoria da Tarefa
    int x5; //variável para futuramente comparar 2 strings em relação a categoria da Tarefa
    size_t b;
    int num; //contador
    do{
        printf("Digite a prioridade: ");
        scanf("%d", &p);
        limpar();
        printf("Digite a categoria da Tarefa que deseja filtrar(Lazer, Estudos, Trabalho ou Eventos): ");
        fgets(c, sizeof(c), stdin);
        b = strlen(c);
        if(c[b - 1] == '\n')c[--b] = 0; //serve para tirar o \n
        x1 = strcmp(c, categoria1);
        x2 = strcmp(c, categoria2);
        x3 = strcmp(c, categoria3);
        x4 = strcmp(c, categoria4);
    }while (x1 != 0 && x2 != 0 && x3 != 0 && x4 != 0);
    printf("Tarefas filtradas com essa prioridade e categoria: \n");
    for(int i = 0; i < maxtarefas; i++){ //laço for percorre por toda a lista
        x5 = strcmp(c, Main[i].categoria); //compara para ver se oq o usuário digitou condiz com oq já está na lista
        if (x5 == 0 && Main[i].prioridade == p){ //caso os parâmetros sejam iguais, tanto oq o usuário digitou quanto oq já está na lista, será printado a Tarefa com a prioridade e categoria selecionados
            num = num + 1;
            printf("\n%s\n", Main[i].tarefa);
        }
    }
}

void ExportarTarefasPrioridade(Tarefa Main[]){
    int num; //contador
    int p; //variável onde será armazenada a prioridade da Tarefa escolhida pelo usuário
    printf("Digite a prioridade da Tarefa que deseja exportar: ");
    scanf("%d", &p); //scanf vai mandar o valor inteiro digitado pelo usuário para a variável "p"
    FILE *arqprioridade = fopen("tarefas.txt", "w"); //abre e escreve no arquivo onde será exportado as Tarefas
    fprintf(arqprioridade, "Tarefas com a prioridade: %d\n", p); //vai printar no arquivo a prioridade escolhida pelu usuário
    fprintf(arqprioridade, "\n--- Tarefas ---\n");
    fprintf(arqprioridade, "\n");
    for (int i = 0; i < maxtarefas; i++){ //laço for vai percorrer
        if(Main[i].prioridade == p && Main[i].existe == 1){
            num = num + 1;
            fprintf(arqprioridade, "Tarefa: %s -> Prioridade: %d, Categoria: %s, Estado: %s, Descricao: %s\n", Main[i].tarefa, Main[i].prioridade, Main[i].categoria, Main[i].estado, Main[i].descricao);
        } //printa no arquivo a Tarefa filtrada a partir da prioridade escolhida e todas as suas informações

    }
    if (num == 0){ //caso o contador retorne 0 significa que não há Tarefas com essa prioridade, e a mensagem abaixo será printada
        printf("Nao existem Tarefas com essa prioridade!\n");
        fprintf(arqprioridade, "Nao existem Tarefas com a prioridade %d!\n", p);
    }
    fclose(arqprioridade);  //fecha o arquivo
}

void ExportarTarefasCategoria(Tarefa Main[]){
    char c[15];
    char categoria1[15]; //variável para armazenar a categoria "Lazer" como uma string
    char categoria2[15]; //variável para armazenar a categoria "Estudos" como uma string
    char categoria3[15]; //variável para armazenar a categoria "Trabalho" como uma string
    char categoria4[15]; //variável para armazenar a categoria "Eventos" como uma string
    sprintf(categoria1, "Lazer");
    sprintf(categoria2, "Estudos");
    sprintf(categoria3, "Trabalho");
    sprintf(categoria4, "Eventos");
    int x1; //variável para futuramente comparar 2 strings em relação a categoria da Tarefa
    int x2; //variável para futuramente comparar 2 strings em relação a categoria da Tarefa
    int x3; //variável para futuramente comparar 2 strings em relação a categoria da Tarefa
    int x4; //variável para futuramente comparar 2 strings em relação a categoria da Tarefa
    int x5; //variável para futuramente comparar 2 strings em relação a categoria da Tarefa
    size_t b;
    int num; //contador
    do{
        printf("Digite a categoria da Tarefa que deseja filtrar(Lazer, Estudos, Trabalho ou Eventos): ");
        fgets(c, sizeof(c), stdin);
        b = strlen(c);
        if(c[b - 1] == '\n')c[--b] = 0; //serve para tirar o \n
        x1 = strcmp(c, categoria1);
        x2 = strcmp(c, categoria2);
        x3 = strcmp(c, categoria3);
        x4 = strcmp(c, categoria4);
    }while (x1 != 0 && x2 != 0 && x3 != 0 && x4 != 0);
    FILE *arqcategoria = fopen("tarefas.txt", "w"); //abre e escreve no arquivo onde será exportado as Tarefas
    fprintf(arqcategoria, "Tarefas com a categoria %s\n", c); //sera printado no "tarefas.txt"
    fprintf(arqcategoria, "\n--- Tarefas ---\n"); //sera printado no "tarefas.txt"
    fprintf(arqcategoria, "\n");
    for(int z = 0; z < maxtarefas; z++){ //laço for percorre por toda a lista, sendo z como parâmetro para a posição
        for(int i = 0; i < maxtarefas; i++){ //outro laço que percorre dentro daquele que foi chamado antes
            x5 = strcmp(c, Main[i].categoria);
            if (x5 == 0 && Main[i].prioridade == z && Main[i].existe == 1){ //caso o valor da prioridade ja existente seja igual ao digitado pelo usuário, a comparação das duas strins retorne 0 e exista dentro da lista fará oq está abaixo
                num = num + 1; //contador para ver se existe uma tarefa com a categoria desejada, caso exista vai adicinador 1 ao num
                printf("Tarefa: %s\n", Main[i].tarefa);
                fprintf(arqcategoria, "Tarefa: %s -> Prioridade: %d, Categoria: %s, Estado: %s, Descricao: %s\n", Main[i].tarefa, Main[i].prioridade, Main[i].categoria, Main[i].estado, Main[i].descricao);
            } //printa no arquivo a Tarefa filtrada a partir da prioridade escolhida e todas as suas informações
            }
        }
    if (num == 0){ //caso o contador retorne 0 significa que não há Tarefas com essa categoria, e a mensagem abaixo será printada
        printf("Nao existem Tarefas com essa categora!\n");
        fprintf(arqcategoria, "Nao existem Tarefas com a categoria %s!\n", c);
    }
    fclose(arqcategoria);  //fecha o arquivo
}

void ExportarTarefasPC(Tarefa Main[]){
    char c[15];
    char categoria1[15]; //variável para armazenar a categoria "Lazer" como uma string
    char categoria2[15]; //variável para armazenar a categoria "Estudos" como uma string
    char categoria3[15]; //variável para armazenar a categoria "Trabalho" como uma string
    char categoria4[15]; //variável para armazenar a categoria "Eventos" como uma string
    sprintf(categoria1, "Lazer");
    sprintf(categoria2, "Estudos");
    sprintf(categoria3, "Trabalho");
    sprintf(categoria4, "Eventos");
    int x1; //variável para futuramente comparar 2 strings em relação a categoria da Tarefa
    int x2; //variável para futuramente comparar 2 strings em relação a categoria da Tarefa
    int x3; //variável para futuramente comparar 2 strings em relação a categoria da Tarefa
    int x4; //variável para futuramente comparar 2 strings em relação a categoria da Tarefa
    int x5; //variável para futuramente comparar 2 strings em relação a categoria da Tarefa
    size_t b;
    int num; //contador
    int p;
    do{
        printf("Digite a prioridade da Tarefa que deseja exportar: ");
        scanf("%d", &p);
        limpar();
        printf("Digite a categoria da Tarefa que deseja filtrar(Lazer, Estudos, Trabalho ou Eventos): ");
        fgets(c, sizeof(c), stdin);
        b = strlen(c);
        if(c[b - 1] == '\n')c[--b] = 0; //serve para tirar o \n
        x1 = strcmp(c, categoria1);
        x2 = strcmp(c, categoria2);
        x3 = strcmp(c, categoria3);
        x4 = strcmp(c, categoria4);
    }while (x1 != 0 && x2 != 0 && x3 != 0 && x4 != 0);
    FILE *arqPC = fopen("tarefas.txt", "w"); //abre e escreve no arquivo onde será exportado as Tarefas
    fprintf(arqPC, "Tarefas com a prioridade %d e categoria %s\n", p, c); //sera printado no "tarefas.txt" a prioridade e a categoria escolhidas pela usuário
    fprintf(arqPC, "\n--- Tarefas ---\n");
    fprintf(arqPC, "\n");
    for (int i = 0; i < maxtarefas; i++){ //laço for vai percorrer por toda a lista
        x5 = strcmp(c, Main[i].categoria);
        if (Main[i].prioridade == p && x5 == 0 && Main[i].existe == 1){ //caso o valor da prioridade ja existente seja igual ao digitado pelo usuário, a comparação das duas strins retorne 0 e exista dentro da lista fará oq está abaixo
            num = num + 1;
            printf("Tarefa: %s\n", Main[i].tarefa);
            fprintf(arqPC, "Tarefa: %s -> Prioridade: %d, Categoria: %s, Estado: %s, Descricao: %s\n", Main[i].tarefa, Main[i].prioridade, Main[i].categoria, Main[i].estado, Main[i].descricao);
        } //printa no arquivo a Tarefa filtrada a partir da prioridade escolhida e todas as suas informações
    }
    if (num == 0){ //caso o contador retorne 0 significa que não há Tarefas com essa prioridade e categoria, e a mensagem abaixo será printada
        printf("Nao existem Tarefas com essa prioridade e categora!\n");
        fprintf(arqPC, "Nao existem Tarefas com a prioridade %d e categoria %s!\n", p, c);
    }
    fclose(arqPC); //fecha o arquivo
}
