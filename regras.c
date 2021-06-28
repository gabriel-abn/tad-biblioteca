#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "regras.h"
#include "usuario.h"
#include "emprestimo.h"
#include "livro.h"

int VerificarQtdLivros(TLivro *livro)
{
    if (livro->quant_emprestados <= livro->quantidade * 0.1)
    {
        livro->quant_emprestados++;
        return 1;
    }
    else
    {
        return 0;
    }
}

int VerificarMulta(TUsuario usuario)
{
    if (usuario.debito == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

int ValidarEmprestimo(TModuloLivro *modulo_livro, 
    TModuloUsuario *modulo_usuario, TEmprestimo emprestimo)
{
    int index1, index2;
    TLivro search_livro;
    TUsuario search_usuario;
    
    strcpy(search_livro.ISBN, emprestimo.ISBN);
    strcpy(search_usuario.CPF, emprestimo.CPF);

    index1 = PesquisarLivro(*modulo_livro, search_livro);
    index2 = PesquisaUsuario(*modulo_usuario, search_usuario);
    
    if (index1 != -1 && index2 != -1)
    {
        if (VerificarQtdLivros(&(modulo_livro->vetor_livro[index1])))
        {
            if (VerificarMulta(modulo_usuario->vetor_usuario[index2]))
            {    
                printf("\nEmprestimo realizado com sucesso!\n");
                modulo_usuario->vetor_usuario[index2].livros_obtidos++;
                return 1;
            }
            else
            {
                printf("\nUsuario incapacitado para fazer emprestimo! Multa: %.2f\n", modulo_usuario->vetor_usuario[index2].debito);
                return 0;
            }
        }
        else
        {
            printf("\nLivro indisponivel para emprestimo!\n");
            return 0;
        }
    } else
    if (index1 == -1)
    {
        printf("\nLivro nao encontrado!\n");
    }
    if (index2 == -1)
    {
        printf("\nUsuario nao encontrado!\n");
    }
    return 0;
}

void AplicarMulta(TUsuario *usuario)
{
    usuario->debito = usuario->debito + 2;
}
