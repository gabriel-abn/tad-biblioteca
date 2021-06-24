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
    printf("Nome: ");
    fflush(stdin);
    fgets(usuario->nome, 30, stdin);
    printf("Sobrenome: ");
    fflush(stdin);
    fgets(usuario->sobrenome, 30, stdin);
    printf("CPF: ");
    fflush(stdin);
    fgets(usuario->CPF, 15, stdin);
    printf("Identidade: ");
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
    printf("Numero: ");
    fflush(stdin);
    scanf("%d", &usuario->endereco.numero);
    printf("Bairro: ");
    fflush(stdin);
    fgets(usuario->endereco.bairro, 100, stdin);
    printf("Cidade: ");
    fflush(stdin);
    fgets(usuario->endereco.cidade, 100, stdin);
    printf("CEP: ");
    fflush(stdin);
    fgets(usuario->endereco.CEP, 10, stdin);

    printf("Tipo de usuario: ");
    fflush(stdin);
    scanf("%d", &(usuario->tipo_usuario));
    printf("Local de atuacao: ");
    fflush(stdin);
    fgets(usuario->nome, 40, stdin);
}

int CadastrarUsuario(TModuloUsuario *modulo_usuario, TUsuario usuario)
{
    if (modulo_usuario->indice < 99)
    {
        modulo_usuario->vetor_usuario[modulo_usuario->indice] = usuario;
        modulo_usuario->indice++;
        return 1;
    }
    return 0;
}

void ImprimirUsuario(TUsuario usuario)
{
    printf("Nome: ");
    puts(usuario.nome);
    printf("Sobrenome: ");
    puts(usuario.sobrenome);
    printf("CPF: ");
    puts(usuario.CPF);
    printf("Identidade: ");
    puts(usuario.ID);

    printf("Data de Nascimento: ");
    printf("%d/%d/%d", usuario.data_nascimento.dia, usuario.data_nascimento.mes, usuario.data_nascimento.ano);

    printf("\nEndereco:\n");
    printf("Logradouro: ");
    puts(usuario.endereco.logradouro);
    printf("Numero: %d\n", usuario.endereco.numero);
    printf("Bairro: ");
    puts(usuario.endereco.bairro);
    printf("Cidade: ");
    puts(usuario.endereco.cidade);
    printf("CEP: ");
    puts(usuario.endereco.CEP);

    printf("\nTipo de usuario: %d\n", usuario.tipo_usuario);
    printf("Local de atuacao: ");
    puts(usuario.nome);
}

void ImprimirTodosUsuarios(TModuloUsuario modulo_usuario)
{
    for (int i = 0; i < modulo_usuario.indice; i++)
    {
        printf("\nUsuario %d\n", i);
        ImprimirUsuario(modulo_usuario.vetor_usuario[i]);
        printf("-----------------------------");
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
            return i;
        }
    }
    return -1;
}

int AlterarUsuario(TModuloUsuario *modulo, TUsuario alter, int index)
{
    if (index != -1)
    {
        modulo->vetor_usuario[index] = alter;
        return 1;
    }
    else
    {
        return 0;
    }
}

int ExcluirUsuario(TModuloUsuario *modulo, int index)
{
    char resp = 's';

    if (index != -1)
    {
        printf("\nUsuario encontrado!\n");
        ImprimirUsuario(modulo->vetor_usuario[index]);
        printf("\nDeseja excluir usuario do sistema? s para SIM - n para NAO\n");
        printf("Resposta: ");
        fflush(stdin);
        scanf("%c", &resp);

        if (resp == 's')
        {
            for (int j = index; j < modulo->indice; j++)
            {
                modulo->vetor_usuario[j] = modulo->vetor_usuario[j+1];
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