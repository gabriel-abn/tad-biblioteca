#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "livro.h"

void IniciarVetor(TBiblioteca *vetor)
{
    vetor->indice = 0;
}

int Cadastrar(TBiblioteca *vetorLivro, TLivro livro)
{
    if (vetorLivro->indice < 99)
    {
        printf("\nDigite as informacoes para cadastro do livro:\n");
        printf("\nTitulo: ");
        fflush(stdin);
        fgets(livro.titulo, 100, stdin);
        printf("\nISBN: ");
        fflush(stdin);
        fgets(livro.ISBN, 20, stdin);
        printf("\nEditora: ");
        fflush(stdin);
        fgets(livro.editora, 100, stdin);
        printf("\nLocal: ");
        fflush(stdin);
        fgets(livro.local, 100, stdin);

        printf("Publicacao:\n");
        printf("Dia: ");
        fflush(stdin);
        scanf("%d", &livro.data_pub.dia);
        printf("Mes: ");
        fflush(stdin);
        scanf("%d", &livro.data_pub.mes);
        printf("Ano: ");
        fflush(stdin);
        scanf("%d", &livro.data_pub.ano);

        printf("\nPrimeiro autor: ");
        fflush(stdin);
        fgets(livro.prim_autor, 100, stdin);
        printf("\nSegundo autor: ");
        fflush(stdin);
        fgets(livro.seg_autor, 100, stdin);

        printf("Quantidade: ");
        fflush(stdin);
        scanf("%d", &livro.quantidade);

        vetorLivro->vetor[vetorLivro->indice] = livro;
        vetorLivro->indice++;

        return 1;
    }
    else
    {
        return 0;
    }
}

void Imprimir(TLivro livro)
{
    printf("\nTitulo: ");
    puts(livro.titulo);
    printf("\nISBN: ");
    puts(livro.ISBN);
    printf("\nEditora: ");
    puts(livro.editora);
    printf("\nLocal: ");
    puts(livro.local);

    printf("\nPublicacao:\n");
    printf("%d/%d/%d", livro.data_pub.dia, livro.data_pub.mes, livro.data_pub.ano);

    printf("\nPrimeiro autor: ");
    puts(livro.prim_autor);
    printf("\nSegundo autor: ");
    puts(livro.seg_autor);

    printf("Quantidade: %d\n", livro.quantidade - livro.quant_emprestados);
    printf("Quantidade emprestados: %d\n", livro.quant_emprestados);
}