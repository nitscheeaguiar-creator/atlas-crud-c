#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct
{
    char nome[50];
    char cpf[15];
    int id;
} Pessoa;

// Define a estrutura base do projeto
Pessoa pessoas[MAX];
int total = 0;
int nextId = 1;

void limparBuffer()
{
    while (getchar() != '\n')
        ;
}

int encontrarPorId(int id)
{
    for (int i = 0; i < total; i++)
    {
        if (pessoas[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

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
    fgets(p.cpf, 15, stdin);
    p.cpf[strcspn(p.cpf, "\n")] = '\0';

    pessoas[total] = p;
    total++;

    printf("\n---- Pessoa cadastrada! ----\n");
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

        printf("%-5d | %-20s | %-15s\n",
               pessoas[i].id,
               pessoas[i].nome,
               pessoas[i].cpf);
    }
}

void buscar()
{
    int idBusca;

    if (total == 0)
    {
        printf("\nNenhum registro encontrado.\n");
        return;
    }

    printf("\nInforme o ID que deseja buscar: ");
    if (scanf("%d", &idBusca) != 1)
    {
        limparBuffer();
        return;
    }

    int pos = encontrarPorId(idBusca);

    if (pos == -1)
    {
        printf("\nPessoa com ID %d não encontrada encontrado.\n", idBusca);
        return;
    }
    {

        printf("\n------- Lista da Pessoa Cadastrada -------\n");
        printf("%-5s | %-20s | %-15s\n", "ID", "NOME", "CPF");
        printf("--------------------------------------------\n");

        printf("%-5d | %-20s | %-15s\n",
               pessoas[pos].id,
               pessoas[pos].nome,
               pessoas[pos].cpf);
    }

}
// Focar aquifklfsklfsdfsdfsajhfçhsfasçkhgafskhgdasflhgsdfklhgdsfklhgsdkghslkfgshgskfghdlghsjhdkjghkfhgdskkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk
void editar()

{

    int idBusca;

    if (total == 0)
    {
        printf("\nNenhum registro encontrado.\n");
        return;
    }

    printf("\nInforme o ID que deseja editar: ");
    scanf("%d", &idBusca);

    int pos = -1;

    for (int i = 0; i < total; i++)

    {
        if (pessoas[i].id == idBusca)

        {
            pos = i;
            break;
        }
    }

    if (pos == -1)
    {

        printf("\nPessoa com ID %d não encontrada.\n", idBusca);
        return;
    }
    printf("\n------- Lista da Pessoa Cadastrada -------\n");
    printf("%-5s | %-20s | %-15s\n", "ID", "NOME", "CPF");
    printf("--------------------------------------------\n");

    printf("%-5d | %-20s | %-15s\n",
           pessoas[pos].id,
           pessoas[pos].nome,
           pessoas[pos].cpf);

    printf("\nNovo nome: ");
    getchar();
    fgets(pessoas[pos].nome, 50, stdin);
    pessoas[pos].nome[strcspn(pessoas[pos].nome, "\n")] = '\0';
    printf("Novo  CPF: ");

    scanf("%lld", &pessoas[pos].cpf);

    printf("\n--------------------");
    printf("\nRegistro atualizado");
    printf("\n--------------------");
}

int main()
{

    int opcao = -1;

    // Mantem o programa funcioando ate o usuario encerrar
    while (opcao != 0)
    {

        printf("\n---- Sistema de CRUD ----\n");
        printf("1 - Criar\n2 - Listar\n3 - Buscar\n4 - Editar\n0 - Sair\n");
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

        case 3:
            buscar();
            break;

        case 4:
            editar();
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
