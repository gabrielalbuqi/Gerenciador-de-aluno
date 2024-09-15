#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUNOS 100

typedef struct {
    int matricula;
    char datadeNascimento[20];
    char curso[50];
    char turno[20];
} Aluno;

Aluno alunos[MAX_ALUNOS];
int totalAlunos = 0;

void cadastrarAluno() {
    if (totalAlunos >= MAX_ALUNOS) {
        printf("Limite de alunos atingidos.\n");
        return;
    }

    Aluno novoAluno;

    printf("Digite a matricula: ");
    scanf("%d", &novoAluno.matricula);

    printf("Digite a data de nascimento: ");
    scanf("%s", novoAluno.datadeNascimento);

    printf("Digite o curso: ");
    scanf("%s", novoAluno.curso);

    printf("Digite o turno: ");
    scanf("%s", novoAluno.turno);

    alunos[totalAlunos++] = novoAluno;

    printf("Aluno cadastrado com sucesso.\n");
}

void consultarAluno() {
    int matricula;
    printf("Digite a matricula do aluno: ");
    scanf("%d", &matricula);

    int i;
    for (i = 0; i < totalAlunos; i++) {
        if (alunos[i].matricula == matricula) {
            printf("Matricula: %d\n", alunos[i].matricula);
            printf("Data de Nascimento: %s\n", alunos[i].datadeNascimento);
            printf("Curso: %s\n", alunos[i].curso);
            printf("Turno: %s\n", alunos[i].turno);
            return;
        }
    }
    printf("Aluno não encontrado.\n");
}

void alterarAluno() {
    int matricula;
    printf("Digite a matricula do aluno que deseja alterar: ");
    scanf("%d", &matricula);

    int i;
    for (i = 0; i < totalAlunos; i++) {
        if (alunos[i].matricula == matricula) {
            printf("Digite a nova data de nascimento: ");
            scanf("%s", alunos[i].datadeNascimento);

            printf("Digite o novo curso: ");
            scanf("%s", alunos[i].curso);

            printf("Digite o novo turno: ");
            scanf("%s", alunos[i].turno);

            printf("Aluno alterado com sucesso.\n");
            return;
        }
    }
    printf("Aluno não encontrado.\n");
}

void excluirAluno() {
    int matricula;
    printf("Digite a matricula do aluno que deseja excluir: ");
    scanf("%d", &matricula);

    int i;
    for (i = 0; i < totalAlunos; i++) {
        if (alunos[i].matricula == matricula) {
            // Deslocar todos os alunos à frente deste na lista para uma posição anterior
            for (int j = i; j < totalAlunos - 1; j++) {
                alunos[j] = alunos[j + 1];
            }
            totalAlunos--;
            printf("Aluno excluído com sucesso.\n");
            return;
        }
    }
    printf("Aluno não encontrado.\n");
}

int main() {
    int opcao;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Cadastrar Aluno\n");
        printf("2. Consultar Aluno\n");
        printf("3. Alterar Aluno\n");
        printf("4. Excluir Aluno\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarAluno();
                break;
            case 2:
                consultarAluno();
                break;
            case 3:
                alterarAluno();
                break;
            case 4:
                excluirAluno();
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opcao != 5);

    return 0;
}
