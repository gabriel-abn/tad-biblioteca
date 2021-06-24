#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "emprestimo.h"

void IniciarVetorEmprestimo(TModuloEmprestimo *modulo_emprestimo)
{
    modulo_emprestimo->indice = 0;
}

int LerEmprestimo(TEmprestimo *emprestimo)
{
    printf("\nCPF do usuario: \n");
    fflush(stdin);
    fgets(emprestimo->CPF, 15, stdin);
    printf("\nISBN do livro: \n");
    fflush(stdin);
    fgets(emprestimo->ISBN, 20, stdin);

    printf("\nData de emprestimo: \n");
    printf("Dia: ");
    fflush(stdin);
    scanf("%d", &(emprestimo->data_emprestimo.dia));
    printf("Mes: ");
    fflush(stdin);
    scanf("%d", &(emprestimo->data_emprestimo.mes));
    printf("Ano: ");
    fflush(stdin);
    scanf("%d", &(emprestimo->data_emprestimo.ano));

    printf("\nData de entrega: \n");
    printf("Dia: ");
    fflush(stdin);
    scanf("%d", &(emprestimo->data_entrega.dia));
    printf("Mes: ");
    fflush(stdin);
    scanf("%d", &(emprestimo->data_entrega.mes));
    printf("Ano: ");
    fflush(stdin);
    scanf("%d", &(emprestimo->data_entrega.ano));
}

int CadastrarEmprestimo(TModuloEmprestimo *modulo_emprestimo, TEmprestimo input)
{
    if (modulo_emprestimo->indice < 99)
    {
        modulo_emprestimo->vetor_emprestimo[modulo_emprestimo->indice] = input;
        return 1;
    }
    
    return 0;
}

void ImprimirEmprestimo(TEmprestimo emprestimo)
{
    printf("\nCPF do usuario: \n");
    puts(emprestimo.CPF);
    printf("\nISBN do livro: \n");
    puts(emprestimo.ISBN);

    printf("\nData de emprestimo: \n");
    printf("\n%d/%d/%d\n", emprestimo.data_emprestimo.dia, emprestimo.data_emprestimo.mes, emprestimo.data_emprestimo.ano);

    printf("\nData de entrega: \n");
    printf("\n%d/%d/%d\n", emprestimo.data_entrega.dia, emprestimo.data_entrega.mes, emprestimo.data_entrega.ano);
}

void ImprimirTodosEmprestimos(TModuloEmprestimo moduloEmprestimo)
{
    for (int i = 0; i < moduloEmprestimo.indice; i++)
    {
        printf("\nEmprestimo %d\n");
        ImprimirEmprestimo(moduloEmprestimo.vetor_emprestimo[i]);
        printf("\n");
    }
    
}

int PesquisarEmprestimo(TModuloEmprestimo modulo_emprestimo, TEmprestimo search)
{
    for (int i = 0; i < modulo_emprestimo.indice; i++)
    {
        if (strcmp(modulo_emprestimo.vetor_emprestimo[i].CPF, search.CPF) == 0 ||
        strcmp(modulo_emprestimo.vetor_emprestimo[i].ISBN, search.ISBN) == 0)
        {
            printf("\nEmprestimo encontrado!\n");
            ImprimirEmprestimo(modulo_emprestimo.vetor_emprestimo[i]);
            return 1;
        }
    }
    printf("\nEmprestimo nao encontrado!\n");
    return 0;
}