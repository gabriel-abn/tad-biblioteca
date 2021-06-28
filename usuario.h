#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include"livro.h"

typedef struct endereco{
    char logradouro[100];
    int numero;
    char bairro[100];
    char cidade[100];
    char CEP[10];
}TEndereco;

typedef struct TipoUsuario
{
    char CPF[15];
    char nome[30];
    char sobrenome[30];
    char ID[15];
    TEndereco endereco;
    TData data_nascimento;
    int tipo_usuario;
    char local_atuacao[40];
    float debito;
    int livros_obtidos;
}TUsuario;

typedef struct ModuloUsuario
{
    TUsuario vetor_usuario[100];
    int indice;
}TModuloUsuario;

void IniciarVetorUsuario(TModuloUsuario *);
void LerUsuario(TUsuario *);
int CadastrarUsuario(TModuloUsuario*, TUsuario);
void ImprimirUsuario(TUsuario);
void ImprimirTodosUsuarios(TModuloUsuario);
int PesquisaUsuario(TModuloUsuario, TUsuario);
int AlterarUsuario(TModuloUsuario *, TUsuario, int);
int ExcluirUsuario(TModuloUsuario *, int);

#endif