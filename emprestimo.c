#include<stdio.h>
#include<stdlib.h>
#include "emprestimo.h"

int CadastroEmprestimo(TEmprestimo emprestimo)
{
    printf("\nCPF do usuario: \n");
    fflush(stdin);
    fgets(emprestimo.CPF, 15, stdin);
    printf("\nISBN do livro: \n");
    fflush(stdin);
    fgets(emprestimo.ISBN, 20, stdin);

    printf("\nData de emprestimo: \n");
    printf("Dia: ");
    fflush(stdin);
    scanf("%d", &emprestimo.data_emprestimo.dia);
    printf("Mes: ");
    fflush(stdin);
    scanf("%d", &emprestimo.data_emprestimo.mes);
    printf("Ano: ");
    fflush(stdin);
    scanf("%d", &emprestimo.data_emprestimo.ano);

    printf("\nData de entrega: \n");
    printf("Dia: ");
    fflush(stdin);
    scanf("%d", &emprestimo.data_entrega.dia);
    printf("Mes: ");
    fflush(stdin);
    scanf("%d", &emprestimo.data_entrega.mes);
    printf("Ano: ");
    fflush(stdin);
    scanf("%d", &emprestimo.data_entrega.ano);
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