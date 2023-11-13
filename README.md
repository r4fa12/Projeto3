Projeto 3

Este projeto tem como objetivo criar um sistema que armazena tarefas, podendo escolher seu nome, uma descrição, um nível de prioridade, um estado atual para a tarefa e uma categoria em que essa tarefa se encaixa. O sistema possui diversas funções que serão apresentadas a seguir. Ao iniciar o código é exibido no terminal um menu principal com 11 funções principais do programa, sendo elas: 

1. Criar Tarefa: essa função cria novas tarefas para serem adicionadas ao arquivo do programa, na criação é possível criar o nome da tarefa, uma breve descrição sobre o que se trata, uma categoria em que ela pode ser encaixada (lazer, estudos, trabalho ou eventos), o estado atual em que essa tarefa se encontra (concluído, em andamento ou não iniciado) e um nível de prioridade. Essas informações serão armazenadas num arquivo para que estajam salvas mesmo que o programa seja fechado.

2. Deletar Tarefa: essa função é capaz de deletar tarefas já criadas anteriormente pelo usuário. Assim que o usuário escolhe a função é exibido no terminal uma lista com todas as tarefas já criadas, basta escolher qual delas deseja deletar.

3. Listar Tarefas: essa função tem por objetivo listar todas as tarefas criadas, assim como sua prioridade, estado, categoria e descrição.

4. Alterar Tarefas: essa função permite que o usuário altere qualquer coisa de uma tarefa. Assim que o usuário escolhe essa função é exibido no terminal uma lista de todas as tarefas já existentes, o usuário seleciona a tarefa que deseja alterar e em seguida seleciona qual parte específica da tarefa ele deseja alterar seja seu nome, sua descrição, categoria, prioridade ou estado. Assim que a tarefa sofre a alteração é exibida uma mensagem no terminal dizendo que a alteração foi realizada com sucesso.

5. Filtrar Tarefas pela Prioridade: essa função é capaz de selecionar todas as tarefas que estão no arquivo do programa digitando apenas o nível de prioridade, assim o sistema percorre por todo o arquivo e seleciona as tarefas que possuem o nível de prioridade (número inteiro) igual ao digitado pelo usuário e as exibe no terminal.

6. Filtrar Tarefas pelo Estado: basicamente é a mesma coisa que a função acima, mas o diferencal é que ao invés do sistema percorrer por todo o arquivo e selecionar o nível de prioridade (um número inteiro), vai selecionar as tarefas que possuem o mesmo estado (sendo uma string) digitado pelo usuário e exibe as tarefas no terminal.

7. Filtrar Tarefas pela Categoria: essa função filtra todas as tarefas que possuem a categoria digitada pelo usuário. O sistema percorre por todo os arquivo e exibe no terminal apenas as tarefas que possuem a mesma categoria digitada (sendo essa uma string).

8. Filtrar Tarefas pela Prioridade e Categoria: essa função pede que o usuário digite a prioridade e a categoria de alguma tarefa, ou seja, o sistema vai percorrer por todo o arquivo e selecionar apenas as tarefas que contém aquela prioridade e categoria específicos digitados pelo usuário, logo uma tarefa que possua a mesma prioridade e categoria diferente ou vice-versa não será exibido no terminal.

9. Exportar Tarefas pela Prioridade: essa função cria um arquivo.txt e exibe nesse arquivo todas as tarefas que possuem a prioridade digitada pelo usuário. É semelhante a função Filtrar Tarefa pela Prioridade, o diferencial é que a tarefa que possui o mesmo nível de prioridade é exibido no arquivo.txt e não no terminal.

10. Exportar Tarefas pela Categoria: essa função cria um arquivo.txt e exibe nesse arquivo todas as tarefas que possuem a mesma categoria digitada pelo usuário. Também é semelhante a função Filtrar Função pela Categoria, mas exibe as tarefas de mesma categoria diretamente no arquivo.txt e não no terminal.

11. Exportar Tarefas pela Prioridade e pela Categoria: essa função também cria um arquivo.txt e exibe nele apenas as tarefas que possuem a mesma prioridade e mesma categoria digitadas pelo usuário. Vale ressaltar que prioridades iguais mas categorias diferentes e vice-versa não são exibidas no arquivo dessa função.
