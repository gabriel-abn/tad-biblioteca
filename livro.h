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

typedef struct livro{
    char ISBN[20];
    char titulo[100];
    char editora[100];
    char local[100];
    TData data_pub;
    char prim_autor[100];
    char seg_autor[100];
    int quantidade;
    int quant_emprestados;
}TLivro;

typedef struct biblioteca{
    TLivro vetor[100];
    int indice; 
}TBiblioteca;
