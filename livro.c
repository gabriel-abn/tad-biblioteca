#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "livro.h"

void IniciarVetorLivro(TModuloLivro *modulo_livro)
{
    modulo_livro->indice = 0;
}

void LeituraLivro(TLivro *livro)
{
    printf("\nDigite as informacoes para cadastro do livro:\n");
    printf("Titulo: ");
    fflush(stdin);
    fgets(livro->titulo, 100, stdin);
    printf("ISBN: ");
    fflush(stdin);
    fgets(livro->ISBN, 20, stdin);
    printf("Editora: ");
    fflush(stdin);
    fgets(livro->editora, 100, stdin);
    printf("Local: ");
    fflush(stdin);
    fgets(livro->local, 100, stdin);

    printf("Publicacao:\n");
    printf("Dia: ");
    fflush(stdin);
    scanf("%d", &(livro->data_pub.dia));
    printf("Mes: ");
    fflush(stdin);
    scanf("%d", &(livro->data_pub.mes));
    printf("Ano: ");
    fflush(stdin);
    scanf("%d", &(livro->data_pub.ano));

    printf("Primeiro autor: ");
    fflush(stdin);
    fgets(livro->prim_autor, 100, stdin);
    printf("Segundo autor: ");
    fflush(stdin);
    fgets(livro->seg_autor, 100, stdin);

    printf("Quantidade: ");
    fflush(stdin);
    scanf("%d", &(livro->quantidade));
}

int CadastrarLivro(TModuloLivro *modulo_livro, TLivro livro)
{
    if (modulo_livro->indice < 99)
    {
        modulo_livro->vetor_livro[modulo_livro->indice] = livro;
        modulo_livro->indice++;

        return 1;
    }
    else
    {
        return 0;
    }
}

void ImprimirLivro(TLivro livro)
{
    printf("Titulo: ");
    puts(livro.titulo);
    printf("ISBN: ");
    puts(livro.ISBN);
    printf("Editora: ");
    puts(livro.editora);
    printf("Local: ");
    puts(livro.local);

    printf("Publicacao: ");
    printf("%d/%d/%d", livro.data_pub.dia, livro.data_pub.mes, livro.data_pub.ano);

    printf("Primeiro autor: ");
    puts(livro.prim_autor);
    printf("Segundo autor: ");
    puts(livro.seg_autor);

    printf("Quantidade: %d\n", livro.quantidade - livro.quant_emprestados);
    printf("Quantidade emprestados: %d\n", livro.quant_emprestados);
}

void ImprimirTodosLivros(TModuloLivro modulo_livro)
{
    for (int i = 0; i < modulo_livro.indice; i++)
    {
        printf("\nLivro %d:\n", i);
        ImprimirLivro(modulo_livro.vetor_livro[i]);
        printf("\n-------------------------");
    }
}

int PesquisarLivro(TModuloLivro modulo_livro, TLivro livro)
{
    for (int i = 0; i < modulo_livro.indice; i++)
    {
        if (strcmp(modulo_livro.vetor_livro[i].ISBN, livro.ISBN) == 0)
        {
            ImprimirLivro(modulo_livro.vetor_livro[i]);
            return i;
        }
    }
    return -1;
}

int AlterarLivro(TModuloLivro *modulo, TLivro alter, int index)
{
    if (index != -1)
    {
        modulo->vetor_livro[index] = alter;
        return 1;
    }
    else
    {
        return 0;
    }
}


int ExcluirLivro(TModuloLivro *modulo, int index)
{
    char resp = 's';

    if (index != -1)
    {
        printf("\nLivro encontrado!\n");
        ImprimirLivro(modulo->vetor_livro[index]);
        printf("\nDeseja excluir livro do sistema? s para SIM - n para NAO\n");
        printf("Resposta: ");
        fflush(stdin);
        scanf("%c", &resp);

        if (resp == 's')
        {
            for (int j = index; j < modulo->indice; j++)
            {
                modulo->vetor_livro[j] = modulo->vetor_livro[j+1];
            }
            modulo->indice--;      
            return 1;
        } else
        if (resp == 'n')
        {
            system("PAUSE");
            printf("\n\n\t >>>>> MSG: Pressione uma tecla para continuar <<<<< \n\n\t");
            return 1;
        }
        else
        {
            printf("\n\n\t >>>>> MSG: Opcao invalida <<<<< \n\n\t");
            system("PAUSE");
            printf("\n\n\t >>>>> MSG: Pressione uma tecla para continuar <<<<< \n\n\t");
        }
        printf("\n");
    }
    return 0;
}