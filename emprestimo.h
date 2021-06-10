#ifndef EMPRESTIMO_H_INCLUDED
#define EMPRESTIMO_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include "livro.h"

typedef struct TipoEmprestimo
{
    char CPF[15];
    char ISBN[20];
    TData data_emprestimo;
    TData data_entrega;
    TData data_devolucao;
}TEmprestimo;

int CadastroEmprestimo(TEmprestimo);
void ImprimirEmprestimo(TEmprestimo);

#endif