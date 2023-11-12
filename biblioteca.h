#define maxtarefas 100

typedef struct{
    char tarefa[100];
    char descricao[300];
    int prioridade;
    int existe;
}Tarefa;


void Menu();

void ListarTarefas2();

void CriarTarefa();

void DeletarTarefa();

void ListarTarefas();

int criararquivo();

int lerarquivo();

void AlterarTarefas(Tarefa Main[]);

void FiltrarTarefasPrioridade(Tarefa Main[]);

void FiltrarTarefasEstado(Tarefa Main[]);

void FiltrarTarefasCategoria(Tarefa Main[]);

void FiltrarTarefasPC(Tarefa Main[]);