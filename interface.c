#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "interface.h"
#include "livro.h"
#include "usuario.h"
#include "emprestimo.h"

void MSG_MENU()
{
    printf("\n\n\t >>>>>>>>>> MENU <<<<<<<<<< ");
    printf("\n\n\t1. GERENCIAMENTO DE LIVROS ");
    printf("\n\t2. GERENCIAMENTO DE USUARIO");
    printf("\n\t3. GERENCIAMENTO DE EMPRESTIMO");
    printf("\n\t4. SERVICOS");
    printf("\n\t5. SAIR");
}

void MSG_SUBMENU(int opcao)
{
    system("cls");
    switch (opcao)
    {
    case 1:
        printf("\n\n\t >>>>>>>>>> GERENCIAMENTO DE LIVROS <<<<<<<<<<");
        printf("\n\n\t1. CADASTRAR");
        printf("\n\t2. PESQUISAR");
        printf("\n\t3. ALTERAR");
        printf("\n\t4. EXCLUIR");
        printf("\n\t5. IMPRIMIR TODOS");
        printf("\n\t6. SAIR");
        break;
    case 2:
        printf("\n\n\t >>>>>>>>>> GERENCIAMENTO DE USUARIOS <<<<<<<<<<");
        printf("\n\n\t1. CADASTRAR");
        printf("\n\t2. PESQUISAR");
        printf("\n\t3. ALTERAR");
        printf("\n\t4. EXCLUIR");
        printf("\n\t5. IMPRIMIR TODOS");
        printf("\n\t6. SAIR");
        break;
    case 3:
        printf("\n\n\t >>>>>>>>>> GERENCIAMENTO DE EMPRESTIMOS <<<<<<<<<<");
        printf("\n\n\t1. CADASTRAR");
        printf("\n\t2. PESQUISAR");
        printf("\n\t3. ALTERAR");
        printf("\n\t4. EXCLUIR");
        printf("\n\t5. IMPRIMIR TODOS");
        printf("\n\t6. SAIR");
        break;
    case 4:
        printf("\n\n\t1. FAZER PAGAMENTO DE MULTA");
        printf("\n\t2. PESQUISAR");
        printf("\n\t3. ALTERAR");
        printf("\n\t4. EXCLUIR");
        printf("\n\t5. IMPRIMIR TODOS");
        printf("\n\t6. SAIR");
        break;
    default:
        break;
    }
}

void SubMenu_Modulo1(TModuloLivro *modulo, TLivro input)
{
    int opcao = 0;
    int index;
    do
    {
        MSG_SUBMENU(1);
        printf("\n\nDigite uma opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);
        switch (opcao)
        {
            case 1:
                LeituraLivro(&input);
                if (CadastrarLivro(modulo, input))
                {
                    printf("\n\n\tMSG: Livro cadastrado com sucesso!");
                    system("PAUSE");
                    printf("\n\n >>>>> MSG: Pressione uma tecla para continuar <<<<< ");
                }
                else
                {
                    printf("\n\n\tMSG: Erro no cadastro, Banco de dados cheio. ");
                    system("PAUSE");
                    printf("\n\n >>>>> MSG: Pressione uma tecla para continuar <<<<< ");
                }
                
                break;
            case 2:
                printf("\nInsira o ISBN a ser pesquisado: ");
                fflush(stdin);
                fgets(input.ISBN, 20, stdin);
                index = PesquisarLivro(*modulo, input);
                if (index != -1)
                {
                    printf("\nLivro encontrado!\n");
                    system("PAUSE");
                    printf("\n\n\t >>>>> MSG: Pressione uma tecla para continuar <<<<< \n\n\t");
                }
                else
                {
                    printf("\nLivro nao encontrado!\n");
                    system("PAUSE");
                    printf("\n\n\t >>>>> MSG: Pressione uma tecla para continuar <<<<< \n\n\t");
                }
                break;
            case 3:
                printf("\nInsira o ISBN a ser pesquisado: ");
                fflush(stdin);
                fgets(input.ISBN, 15, stdin);
                index = PesquisarLivro(*modulo, input);
                if (index != -1)
                {
                    LeituraLivro(&input);
                    if (AlterarLivro(modulo, input, index))
                    {
                        printf("\nLivro alterado com sucesso!\n");
                    }
                    else
                    {
                        printf("\nErro ao alterar livro!\n");
                    }
                }
                else
                {
                    printf("\nLivro nao encontrado!\n");
                }
                system("PAUSE");
                printf("\n\n\t >>>>> MSG: Pressione uma tecla para continuar <<<<< \n\n\t");
                break;
            case 4:
                printf("\nInsira o ISBN a ser pesquisado: ");
                fflush(stdin);
                fgets(input.ISBN, 20, stdin);
                index = PesquisarLivro(*modulo, input);
                if (index != -1)
                {
                    if (ExcluirLivro(modulo, index))
                    {
                        printf("\nLivro excluido com sucesso!\n");
                    }
                    else
                    {
                        printf("\nErro ao excluir livro!\n");
                    }
                }
                else
                {
                    printf("\nLivro nao encontrado!\n");
                }
                system("PAUSE");
                printf("\n\n\t >>>>> MSG: Pressione uma tecla para continuar <<<<< \n\n\t");
                break;
                break;
            case 5:
                ImprimirTodosLivros(*modulo);
                system("PAUSE");
                printf("\n\n\t >>>>> MSG: Pressione uma tecla para continuar <<<<< \n\n\t");
                break;
            case 6:
                system("cls");
                printf("\n\n\t >>>>> MSG: Saindo do modulo...!!! <<<<< \n\n\t");
                system("PAUSE");
                printf("\n\n\t >>>>> MSG: Pressione uma tecla para continuar <<<<< \n\n\t");
                break;
            
            default:
                system("cls");
                printf("\n\n\t >>>>> MSG: Digite uma opcao valida...!!! <<<<< \n\n\t");
                system("PAUSE");
                printf("\n\n\t >>>>> MSG: Pressione uma tecla para continuar <<<<< \n\n\t");
                break;
        }
    } while (opcao != 6);
    
}

void SubMenu_Modulo2(TModuloUsuario *modulo, TUsuario input)
{
    int opcao = 0;
    int index;
    do
    {
        MSG_SUBMENU(2);
        printf("\n\nDigite uma opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);
        switch (opcao)
        {
            case 1:
                LerUsuario(&input);
                if (CadastrarUsuario(modulo, input))
                {
                    printf("\n\nMSG: Usuario cadastrado com sucesso!");
                }
                else
                {
                    printf("\n\nMSG: Erro no cadastro, Banco de dados cheio.");
                }
                system("PAUSE");
                printf("\n\n\t >>>>> MSG: Pressione uma tecla para continuar <<<<< \n\n\t");
                break;
            case 2:
                printf("\nInsira o CPF a ser pesquisado: ");
                fflush(stdin);
                fgets(input.CPF, 15, stdin);
                index = PesquisaUsuario(*modulo, input);
                if (index != -1)
                {
                    ImprimirUsuario(modulo->vetor_usuario[index]);
                }
                else
                {
                    printf("\nUsuario nao encontrado!\n");
                }
                system("PAUSE");
                printf("\n\n\t >>>>> MSG: Pressione uma tecla para continuar <<<<< \n\n\t");
                break;
            case 3:
                printf("\nInsira o CPF a ser pesquisado: ");
                fflush(stdin);
                fgets(input.CPF, 15, stdin);
                index = PesquisaUsuario(*modulo, input);
                if (index != -1)
                {
                    LerUsuario(&input);
                    if (AlterarUsuario(modulo, input, index))
                    {
                        printf("\nUsuario alterado com sucesso!\n");
                    }
                    else
                    {
                        printf("\nErro ao alterar usuario!\n");
                    }
                }
                else
                {
                    printf("\nUsuario nao encontrado!\n");
                }
                system("PAUSE");
                printf("\n\n\t >>>>> MSG: Pressione uma tecla para continuar <<<<< \n\n\t");
                break;
            case 4:
                printf("\nInsira o CPF a ser pesquisado: ");
                fflush(stdin);
                fgets(input.CPF, 15, stdin);
                index = PesquisaUsuario(*modulo, input);
                if (index != -1)
                {
                    if (ExcluirUsuario(modulo, index))
                    {
                        printf("\nUsuario excluido com sucesso!\n");
                    }
                    else
                    {
                        printf("\nErro ao excluir usuario!\n");
                    }
                }
                else
                {
                    printf("\nUsuario nao encontrado!\n");
                }
                system("PAUSE");
                printf("\n\n\t >>>>> MSG: Pressione uma tecla para continuar <<<<< \n\n\t");
                break;
            case 5:
                ImprimirTodosUsuarios(*modulo);
                system("PAUSE");
                printf("\n\n\t >>>>> MSG: Pressione uma tecla para continuar <<<<< \n\n\t");
                break;
            case 6:
                system("cls");
                printf("\n\n\t >>>>> MSG: Saindo do modulo...!!! <<<<< \n\n\t");
                system("PAUSE");
                printf("\n\n\t >>>>> MSG: Pressione uma tecla para continuar <<<<< \n\n\t");
                break;
            
            default:
                system("cls");
                printf("\n\n\t >>>>> MSG: Digite uma opcao valida...!!! <<<<< \n\n\t");
                system("PAUSE");
                printf("\n\n\t >>>>> MSG: Pressione uma tecla para continuar <<<<< \n\n\t");
                break;
        }
    } while (opcao != 6);
    
}

void SubMenu_Modulo3(TModuloEmprestimo *modulo, TEmprestimo input)
{
    int opcao = 0;
    int opcao2 = 0;
    int index;
    do
    {
        MSG_SUBMENU(3);
        printf("\n\nDigite uma opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);
        switch (opcao)
        {
            case 1:
                LerEmprestimo(&input);
                if (CadastrarEmprestimo(modulo, input))
                {
                    printf("\n\nMSG: Emprestimo registrado com sucesso!");
                }
                else
                {
                    printf("\n\nMSG: Erro no registro, Banco de dados cheio.");
                }
                system("PAUSE");
                printf("\n\n\t >>>>> MSG: Pressione uma tecla para continuar <<<<< \n\n\t");
                break;
            case 2:
                printf("\n1 - CPF");
                printf("\n2 - ISBN");
                printf("\nInsira uma opcao: ");
                scanf("%d", &opcao2);
                do
                {
                    if (opcao2 == 1)
                    {
                        printf("\nInsira o CPF a ser pesquisado: ");
                        fflush(stdin);
                        fgets(input.CPF, 15, stdin);
                    } else
                    if (opcao2 == 2)
                    {
                        printf("\nInsira o ISBN a ser pesquisado: ");
                        fflush(stdin);
                        fgets(input.ISBN, 20, stdin);
                    } else
                        printf("\nMSG: Opcao invalida...\n");
                } while (opcao2 != 1 && opcao2 != 2);
                
                index = PesquisarEmprestimo(*modulo, input);
                if (index != -1)
                {
                    ImprimirEmprestimo(modulo->vetor_emprestimo[index]);
                }
                else
                {
                    printf("\nEmprestimo nao encontrado!\n");
                }
                
                system("PAUSE");
                printf("\n\n\t >>>>> MSG: Pressione uma tecla para continuar <<<<< \n\n\t");
                break;
            case 3:
                system("PAUSE");
                printf("\n\n\t >>>>> MSG: Pressione uma tecla para continuar <<<<< \n\n\t");
                break;
            case 4:
                system("PAUSE");
                printf("\n\n\t >>>>> MSG: Pressione uma tecla para continuar <<<<< \n\n\t");
                break;
            case 5:
                system("PAUSE");
                printf("\n\n\t >>>>> MSG: Pressione uma tecla para continuar <<<<< \n\n\t");
                break;
            case 6:
                system("cls");
                printf("\n\n\t >>>>> MSG: Saindo do modulo...!!! <<<<< \n\n\t");
                system("PAUSE");
                printf("\n\n\t >>>>> MSG: Pressione uma tecla para continuar <<<<< \n\n\t");
                break;
            
            default:
                system("cls");
                printf("\n\n\t >>>>> MSG: Digite uma opcao valida...!!! <<<<< \n\n\t");
                system("PAUSE");
                printf("\n\n\t >>>>> MSG: Pressione uma tecla para continuar <<<<< \n\n\t");
                break;
        }
    } while (opcao != 6);
    
}

