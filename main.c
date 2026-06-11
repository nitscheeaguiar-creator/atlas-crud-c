#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define ARQUIVO_DADOS "dados.bin"

typedef struct
{
    char nome[50];
    char cpf[15];
    int  id;
} Pessoa;

// Define a estrutura base do projeto
Pessoa pessoas[MAX];
int total  = 0;
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
            return i;
    }
    return -1;
}

void salvarDados()
{
    FILE *arq = fopen(ARQUIVO_DADOS, "wb");

    if (arq == NULL)
    {
        printf("\nErro ao salvar os dados.\n");
        return;
    }

    fwrite(&total,  sizeof(int),    1,     arq);
    fwrite(&nextId, sizeof(int),    1,     arq);
    fwrite(pessoas, sizeof(Pessoa), total, arq);

    fclose(arq);
}

void carregarDados()
{
    FILE *arq = fopen(ARQUIVO_DADOS, "rb");

    if (arq == NULL)
        return;

    fread(&total,  sizeof(int),    1,     arq);
    fread(&nextId, sizeof(int),    1,     arq);
    fread(pessoas, sizeof(Pessoa), total, arq);

    fclose(arq);
}

void criar()
{
    if (total >= MAX)
    {
        printf("Limite de pessoas cadastradas atingido.\n");
        return;
    }

    Pessoa p;
    Pessoa *pPtr = &p;

    pPtr->id = nextId++;

    printf("\n---- Cadastro de Pessoa (ID: %d)----\n", pPtr->id);
    printf("Informe o nome da pessoa: ");
    getchar();
    fgets(pPtr->nome, sizeof(pPtr->nome), stdin);
    pPtr->nome[strcspn(pPtr->nome, "\n")] = '\0';
    printf("Informe o CPF: ");
    fgets(pPtr->cpf, sizeof(pPtr->cpf), stdin);
    pPtr->cpf[strcspn(pPtr->cpf, "\n")] = '\0';

    pessoas[total] = *pPtr;
    total++;

    salvarDados();
    printf("\n---- Pessoa cadastrada! ----\n");
}

void listar()
{
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
        Pessoa *p = &pessoas[i];

        printf("%-5d | %-20s | %-15s\n",
               p->id,
               p->nome,
               p->cpf);
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
        printf("\nPessoa com ID %d nao encontrada.\n", idBusca);
        return;
    }

    Pessoa *p = &pessoas[pos];

    printf("\n------- Lista da Pessoa Cadastrada -------\n");
    printf("%-5s | %-20s | %-15s\n", "ID", "NOME", "CPF");
    printf("--------------------------------------------\n");

    printf("%-5d | %-20s | %-15s\n",
           p->id,
           p->nome,
           p->cpf);
}

void editar()
{
    int idBusca;

    if (total == 0)
    {
        printf("\nNenhum registro encontrado.\n");
        return;
    }

    printf("\nInforme o ID que deseja editar: ");
    if (scanf("%d", &idBusca) != 1)
    {
        limparBuffer();
        return;
    }

    int pos = encontrarPorId(idBusca);

    if (pos == -1)
    {
        printf("\nPessoa com ID %d nao encontrada.\n", idBusca);
        return;
    }

    Pessoa *p = &pessoas[pos];

    printf("\n------- Lista da Pessoa Cadastrada -------\n");
    printf("%-5s | %-20s | %-15s\n", "ID", "NOME", "CPF");
    printf("--------------------------------------------\n");

    printf("%-5d | %-20s | %-15s\n",
           p->id,
           p->nome,
           p->cpf);

    printf("\nNovo nome: ");
    getchar();
    fgets(p->nome, sizeof(p->nome), stdin);
    p->nome[strcspn(p->nome, "\n")] = '\0';

    printf("Novo  CPF: ");
    fgets(p->cpf, sizeof(p->cpf), stdin);
    p->cpf[strcspn(p->cpf, "\n")] = '\0';

    salvarDados();
    printf("\n--------------------");
    printf("\nRegistro atualizado");
    printf("\n--------------------\n");
}

void excluir()
{
    int idBusca;

    if (total == 0)
    {
        printf("\nNenhum registro encontrado.\n");
        return;
    }

    printf(" ------- Excluir um ID ------- ");
    printf("\nInforme o ID da pessoa que quer deletar: ");
    if (scanf("%d", &idBusca) != 1)
    {
        limparBuffer();
        return;
    }

    int pos = encontrarPorId(idBusca);

    if (pos == -1)
    {
        printf("ID nao encontrado.\n");
        return;
    }

    Pessoa *p = &pessoas[pos];
    (void)p;

    for (int i = pos; i < total - 1; i++)
        pessoas[i] = pessoas[i + 1];

    --total;

    salvarDados();
    printf("\nRegistro excluido com sucesso!\n");
}

int main()
{
    int opcao   = -1;
    int *pOpcao = &opcao;

    carregarDados();

    while (*pOpcao != 0)
    {
        printf("\n---- Sistema de CRUD ----\n");
        printf("1 - Criar\n2 - Listar\n3 - Buscar\n4 - Editar\n5 - Excluir\n0 - Sair\n");
        printf("Escolha: ");

        if (scanf("%d", pOpcao) != 1)
        {
            printf("\nEntrada invalida! Digite um numero.\n");
            limparBuffer();
            continue;
        }

        switch (*pOpcao)
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

        case 5:
            excluir();
            break;

        case 0:
            printf("\nSaindo...\n");
            break;

        default:
            printf("\n---- Operacao invalida! ----\n");
            while (getchar() != '\n')
                ;
        }
    }

    return 0;
}
