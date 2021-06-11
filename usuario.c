#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "usuario.h"

void IniciarVetorUsuario(TModuloUsuario *modulo_usuario)
{
    modulo_usuario->indice = 0;
}

void LerUsuario(TUsuario *usuario)
{
    printf("\nCadastro de usuario:\n");
    printf("\nNome: ");
    fflush(stdin);
    fgets(usuario->nome, 30, stdin);
    printf("\nSobrenome: ");
    fflush(stdin);
    fgets(usuario->sobrenome, 30, stdin);
    printf("\nCPF: ");
    fflush(stdin);
    fgets(usuario->CPF, 15, stdin);
    printf("\nIdentidade: ");
    fflush(stdin);
    fgets(usuario->ID, 15, stdin);

    printf("Data de Nascimento:\n");
    printf("Dia: ");
    fflush(stdin);
    scanf("%d", &(usuario->data_nascimento.dia));
    printf("Mes: ");
    fflush(stdin);
    scanf("%d", &(usuario->data_nascimento.mes));
    printf("Ano: ");
    fflush(stdin);
    scanf("%d", &(usuario->data_nascimento.ano));

    printf("\nEndereco:\n");
    printf("Logradouro: ");
    fflush(stdin);
    fgets(usuario->endereco.logradouro, 100, stdin);
    printf("\nNumero: ");
    fflush(stdin);
    scanf("%d", &usuario->endereco.numero);
    printf("\nBairro: ");
    fflush(stdin);
    fgets(usuario->endereco.bairro, 100, stdin);
    printf("\nCidade: ");
    fflush(stdin);
    fgets(usuario->endereco.cidade, 100, stdin);
    printf("\nCEP: ");
    fflush(stdin);
    fgets(usuario->endereco.CEP, 10, stdin);

    printf("\nTipo de usuario: ");
    fflush(stdin);
    scanf("%d", &(usuario->tipo_usuario));
    printf("\nLocal de atuacao: ");
    fflush(stdin);
    fgets(usuario->nome, 40, stdin);
}

int CadastrarUsuario(TModuloUsuario *modulo_usuario, TUsuario usuario)
{
    if (modulo_usuario->indice < 99)
    {
        modulo_usuario->vetor_usuario[modulo_usuario->indice] = usuario;
        return 1;
    }
    return 0;
}

void ImprimirUsuario(TUsuario usuario)
{
    printf("\nCadastro de usuario:\n");
    printf("\nNome: ");
    puts(usuario.nome);
    printf("\nSobrenome: ");
    puts(usuario.sobrenome);
    printf("\nCPF: ");
    puts(usuario.CPF);
    printf("\nIdentidade: ");
    puts(usuario.ID);

    printf("Data de Nascimento:\n");
    printf("\n%d/%d/%d\n", usuario.data_nascimento.dia, usuario.data_nascimento.mes, usuario.data_nascimento.ano);

    printf("\nEndereco:\n");
    printf("\nLogradouro: ");
    puts(usuario.endereco.logradouro);
    printf("\nNumero: %d\n", usuario.endereco.numero);
    printf("\nBairro: ");
    puts(usuario.endereco.bairro);
    printf("\nCidade: ");
    puts(usuario.endereco.cidade);
    printf("\nCEP: ");
    puts(usuario.endereco.CEP);

    printf("\nTipo de usuario: %d", usuario.tipo_usuario);
    printf("\nLocal de atuacao: ");
    puts(usuario.nome);
}

void ImprimirTodosUsuarios(TModuloUsuario modulo_usuario)
{
    for (int i = 0; i < modulo_usuario.indice; i++)
    {
        printf("\nUsuario %d:\n");
        ImprimirUsuario(modulo_usuario.vetor_usuario[i]);
        printf("\n");
    }
    
}

int PesquisaUsuario(TModuloUsuario modulo_usario, TUsuario search)
{
    for (int i = 0; i < modulo_usario.indice; i++)
    {
        if (strcmp(modulo_usario.vetor_usuario[i].CPF, search.CPF) == 0)
        {
            printf("\nUsuario encontrado!\n");
            ImprimirUsuario(modulo_usario.vetor_usuario[i]);
            printf("\n");
            return 1;
        }
    }
    printf("\nUsuario nao encontrado!\n");
    return 0;
}