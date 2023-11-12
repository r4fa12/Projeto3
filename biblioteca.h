#define maxtarefas 100


typedef struct{
    char tarefa[100];
    char descricao[300];
    int prioridade;
    int existe;
    char estado[100];
    char categoria[100];
    int posicao;
}Tarefa;

void limpar();

void Menu();

void ListarTarefas2(Tarefa Main[]);

void CriarTarefa(Tarefa Main[]);

void DeletarTarefa(Tarefa Main[]);

void ListarTarefas(Tarefa Main[]);

int criararquivo(Tarefa Main[], char tarefasarq[]);

int lerarquivo(Tarefa Main[], char tarefasarq[]);

void AlterarTarefas(Tarefa Main[]);

void FiltrarTarefasPrioridade(Tarefa Main[]);

void FiltrarTarefasEstado(Tarefa Main[]);

void FiltrarTarefasCategoria(Tarefa Main[]);

void FiltrarTarefasPC(Tarefa Main[]);

void ExportarTarefasPrioridade(Tarefa Main[]);

void ExportarTarefasCategoria(Tarefa Main[]);

void ExportarTarefasPC(Tarefa Main[]);