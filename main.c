#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TAREFAS 100

void criarTarefa(char tarefas[][2][100], int *numTarefas, int categoria[][2]);
void listarTarefas(char tarefas[][2][100], int numTarefas, int categoria[][2]);
void editarTarefa(char tarefas[][2][100], int numTarefas, int categoria[][2]);
void excluirTarefa(char tarefas[][2][100], int *numTarefas, int categoria[][2]);

void salvarTarefasEmArquivo(char tarefas[][2][100], int numTarefas, int categoria[][2]) {
    FILE *arquivo = fopen("tarefas.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }
    for (int i = 0; i < numTarefas; i++) {
        fprintf(arquivo, "\nTarefa %d:\n", i + 1);
        fprintf(arquivo, "\nNome: %s", tarefas[i][0]);
        fprintf(arquivo, "\nDescricao: %s", tarefas[i][1]);
        fprintf(arquivo, "\nPrioridade: %d\n", categoria[i][0]);
        fprintf(arquivo, "\nStatus: %d\n", categoria[i][1]);
    }
    fclose(arquivo);
    printf("Tarefas salvas com sucesso no arquivo 'tarefas.txt'.\n");
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int opc;
    char tarefas[MAX_TAREFAS][2][100];
    int numTarefas = 0;
    int categoria[MAX_TAREFAS][2];

    do {
        printf("=== VaptVupt ===\n");
        printf("1- Crie uma tarefa\n");
        printf("2- Listar Tarefas\n");
        printf("3- Editar Tarefa\n");
        printf("4- Excluir Tarefa\n");
        printf("5- Salvar Tarefas em Arquivo\n");
        printf("6- Sair\n");
        printf("O que deseja fazer? Digite o numero da opcao: ");
        if (scanf("%d", &opc) != 1) {
            printf("Entrada invalida. Tente novamente.\n");
            while(getchar() != '\n');
            continue;
        }
        while(getchar() != '\n');

        switch (opc) {
            case 1:
                criarTarefa(tarefas, &numTarefas, categoria);
                break;
            case 2:
                listarTarefas(tarefas, numTarefas, categoria);
                break;
            case 3:
                editarTarefa(tarefas, numTarefas, categoria);
                break;
            case 4:
                excluirTarefa(tarefas, &numTarefas, categoria);
                break;
            case 5:
                salvarTarefasEmArquivo(tarefas, numTarefas, categoria);
                break;
            case 6:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opc != 6);

    return 0;
}

void criarTarefa(char tarefas[][2][100], int *numTarefas , int categoria[][2]) {
    if (*numTarefas >= MAX_TAREFAS) {
        printf("Limite de tarefas atingido!!!!!\n");
        return;
    }
    int prioridade;
    int status;

    printf("Criando tarefa...\n");
    printf("Digite o nome da tarefa: ");
    fgets(tarefas[*numTarefas][0], 100, stdin);
    strtok(tarefas[*numTarefas][0], "\n"); // remove \n
    printf("Digite a descricao da tarefa: ");
    fgets(tarefas[*numTarefas][1], 100, stdin);
    strtok(tarefas[*numTarefas][1], "\n"); // remove \n
    printf("Digite o seu nivel de prioridade para esta tarefa(1-3): ");
    if (scanf("%d", &prioridade) != 1) {
        printf("Entrada invalida! Atribuindo prioridade 1.\n");
        prioridade = 1;
        while(getchar() != '\n');
    }
    if (prioridade < 1 || prioridade > 3) {
        printf("Prioridade invalida! Atribuindo prioridade 1.\n");
        prioridade = 1;
    }

    printf("O status da tarefa em numero (1- Pendente, 2- Em Andamento, 3- Concluida): ");
    if (scanf("%d", &status) != 1) {
        printf("Entrada invalida! Atribuindo status Pendente.\n");
        status = 1;
        while(getchar() != '\n');
    }
    if (status < 1 || status > 3) {
        printf("Status invalido! Atribuindo status Pendente.\n");
        status = 1;
    }
    while(getchar() != '\n');

    categoria[*numTarefas][0] = prioridade;
    categoria[*numTarefas][1] = status;
    (*numTarefas)++;
    printf("Tarefa criada com sucesso!\n");
}

void listarTarefas(char tarefas[][2][100], int numTarefas, int categoria[][2]) {
    if (numTarefas == 0) {
        printf("Nenhuma tarefa cadastrada.\n");
        return;
    }
    int opc2;
    printf("Deseja ver as tarefas por prioridade, status ou todas de uma vez(1-Prioridade 2-Status  3-Todas): \n");
    if (scanf("%d", &opc2) != 1) {
        printf("Entrada invalida. Listando todas as tarefas.\n");
        opc2 = 3;
        while(getchar() != '\n');
    }
    while(getchar() != '\n');
    if(opc2 < 1 || opc2 > 3) {
        printf("Opcao invalida! Listando todas as tarefas.\n");
        opc2 = 3;
    }

    for (int i = 0; i < numTarefas; i++) {
        int prio = categoria[i][0];
        int stat = categoria[i][1];

        if ((opc2 == 1 && (prio < 1 || prio > 3)) || (opc2 == 2 && (stat < 1 || stat > 3))) {
            continue;
        }

        printf("Nome: %s\n", tarefas[i][0]);
        printf("Descricao: %s\n", tarefas[i][1]);
        printf("Prioridade: %d\n", prio);

        if (opc2 == 2 || opc2 == 3) {
            if (stat == 1)
                printf("Status da tarefa: Pendente\n");
            else if (stat == 2)
                printf("Status da tarefa: Em andamento\n");
            else if (stat == 3)
                printf("Status da tarefa: Concluida\n");
        } else {
            printf("Status da tarefa: %d\n", stat);
        }
        printf("-------------------------\n");
    }
    printf("========================\n");
}

void editarTarefa(char tarefas[][2][100], int numTarefas, int categoria[][2]) {
    if (numTarefas == 0) {
        printf("Nenhuma tarefa cadastrada.\n");
        return;
    }
    int indice;
    printf("Digite o numero da tarefa que deseja editar (1 a %d): ", numTarefas);
    if (scanf("%d", &indice) != 1) {
        printf("Entrada invalida!\n");
        while(getchar() != '\n');
        return;
    }
    while(getchar() != '\n');
    if (indice < 1 || indice > numTarefas) {
        printf("Indice invalido!\n");
        return;
    }
    indice--;
    printf("Editando tarefa %d:\n", indice + 1);
    printf("Nome atual: %s\n", tarefas[indice][0]);
    printf("Digite o novo nome da tarefa: ");
    fgets(tarefas[indice][0], 100, stdin);
    strtok(tarefas[indice][0], "\n");

    printf("Descricao atual: %s\n", tarefas[indice][1]);
    printf("Digite a nova descricao da tarefa: ");
    fgets(tarefas[indice][1], 100, stdin);
    strtok(tarefas[indice][1], "\n");

    printf("Prioridade atual: %d\n", categoria[indice][0]);
    printf("Digite a nova prioridade da tarefa (1-3): ");
    if (scanf("%d", &categoria[indice][0]) != 1 || categoria[indice][0] < 1 || categoria[indice][0] > 3) {
        printf("Prioridade invalida! Atribuindo prioridade 1.\n");
        categoria[indice][0] = 1;
        while(getchar() != '\n');
    }

    printf("Status atual: %d\n", categoria[indice][1]);
    printf("Digite o novo status da tarefa (1- Pendente, 2- Em Andamento, 3- Concluida): ");
    if (scanf("%d", &categoria[indice][1]) != 1 || categoria[indice][1] < 1 || categoria[indice][1] > 3) {
        printf("Status invalido! Atribuindo status Pendente.\n");
        categoria[indice][1] = 1;
        while(getchar() != '\n');
    }
    while(getchar() != '\n');
    printf("Tarefa editada com sucesso!\n");
}

void excluirTarefa(char tarefas[][2][100], int *numTarefas, int categoria[][2]) {
    if (*numTarefas == 0) {
        printf("Nenhuma tarefa cadastrada.\n");
        return;
    }
    int indice;
    printf("Digite o numero da tarefa que deseja excluir (1 a %d): ", *numTarefas);
    if (scanf("%d", &indice) != 1) {
        printf("Entrada invalida!\n");
        while(getchar() != '\n');
        return;
    }
    while(getchar() != '\n');
    if (indice < 1 || indice > *numTarefas) {
        printf("Indice invalido!\n");
        return;
    }
    indice--;
    for (int i = indice; i < *numTarefas - 1; i++) {
        strcpy(tarefas[i][0], tarefas[i + 1][0]);
        strcpy(tarefas[i][1], tarefas[i + 1][1]);
        categoria[i][0] = categoria[i + 1][0];
        categoria[i][1] = categoria[i + 1][1];
    }
    (*numTarefas)--;
    printf("Tarefa excluida com sucesso!\n");
}

