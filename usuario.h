typedef struct data{
    int dia;
    int mes;
    int ano;
}TData;

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
    char tipo_usuario;
    char local_atuação[20];
}TUsuario;
