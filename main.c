#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct
{
    char nome[50];
    long long cpf;
    int id;
} Pessoa;

// Define a estrutura base do projeto
Pessoa pessoas[MAX];
int total = 0;
int nextId = 1;

void criar()
{
    if (total >= MAX)
    {
        printf("Limite de pessoas cadastradas atingido.\n");
        return;
    }

    Pessoa p;
    p.id = nextId++;

    printf("\n---- Cadastro de Pessoa (ID: %d)----\n", p.id);
    printf("Informe o nome da pessoa: ");
    getchar();
    fgets(p.nome, 50, stdin);
    p.nome[strcspn(p.nome, "\n")] = '\0';
    printf("Informe o CPF: ");
    scanf("%lld", &p.cpf);

    pessoas[total] = p;
    total++;

    printf("\n---- Pessoa cadastrada! ----\n");
    getchar();
}

void listar()
{

    // Verifica se a base de dados está vazia antes de iniciar
    if (total == 0)
    {
        printf("\nNenhum registro encontrado.\n");
        return;
    }
    printf("\n------- Lista de Pessoas Cadastradas -------\n");
    printf("%-5s | %-20s | %-15s\n", "ID", "NOME", "CPF");
    printf("--------------------------------------------\n");

    for (int i = 0; i < total; i++)
    {
        // Exibição de dados ativos

        printf("%-5d | %-20s | %-15lld\n",
               pessoas[i].id,
               pessoas[i].nome,
               pessoas[i].cpf);
    }
}

int main()
{

    int opcao = -1;

    // Mantem o programa funcioando ate o usuario encerrar
    while (opcao != 0)
    {

        printf("\n---- Sistema de CRUD ----\n");
        printf("1 - Criar\n2 - Listar\n0 - Sair\n");
        printf("Escolha: ");

        // Verificação para entrada de numero
        if (scanf("%d", &opcao) != 1)
        {
        }
        // Direciona a funcionalidade escolhida pelo usuario
        switch (opcao)
        {
        case 1:

            criar();
            break;

        case 2:

            listar();
            break;

        case 0:

            printf("\nSaindo...\n");
            break;

        default:

            printf("\n---- Operação invalida! ----\n");

            while (getchar() != '\n')
                ;
        }
    }

    return 0;
}
