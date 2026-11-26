#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* ============ Estruturas ============ */

typedef struct
{
    char titulo[31]; /* 30 + '\0' */
    char autor[16];  /* 15 + '\0' */
    int ano;
    char genero[31];
} Livro;

typedef struct
{
    char descricao[31];
} Genero;

/* ============ Funções auxiliares ============ */

/* Limpa o buffer do teclado (usado após scanf) */
void limpar_buffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

/* Lê uma string com espaços, removendo o '\n' final */
void ler_string(char *destino, int tamanho)
{
    fgets(destino, tamanho, stdin);
    destino[strcspn(destino, "\n")] = '\0';
}

/* ============ Cadastro de gênero ============ */

void cadastrar_genero(Genero generos[], int *qtd_generos)
{
    if (*qtd_generos >= 100)
    {
        printf("\nLimite de generos atingido!\n");
        return;
    }

    printf("\n--- Cadastro de Genero ---\n");
    printf("Descricao: ");
    ler_string(generos[*qtd_generos].descricao, 31);

    (*qtd_generos)++;
    printf("Genero cadastrado com sucesso!\n");
}

/* ============ Cadastro de livro ============ */

void cadastrar_livro(Livro livros[], int *qtd_livros)
{
    if (*qtd_livros >= 5)
    {
        printf("\nLimite de 5 livros atingido!\n");
        return;
    }

    printf("\n--- Cadastro de Livro (%d/5) ---\n", *qtd_livros + 1);

    printf("Titulo: ");
    ler_string(livros[*qtd_livros].titulo, 31);

    printf("Autor: ");
    ler_string(livros[*qtd_livros].autor, 16);

    printf("Ano: ");
    scanf("%d", &livros[*qtd_livros].ano);
    limpar_buffer();

    printf("Genero: ");
    ler_string(livros[*qtd_livros].genero, 31);

    (*qtd_livros)++;
    printf("Livro cadastrado com sucesso!\n");
}

/* ============ Exibição ============ */

void exibir_livro(Livro l)
{
    printf("  Titulo: %s\n", l.titulo);
    printf("  Autor:  %s\n", l.autor);
    printf("  Ano:    %d\n", l.ano);
    printf("  Genero: %s\n", l.genero);
    printf("  -----------------------------\n");
}

/* ============ Pesquisa por título ============ */

void pesquisar_por_titulo(Livro livros[], int qtd_livros)
{
    if (qtd_livros == 0)
    {
        printf("\nNenhum livro cadastrado ainda.\n");
        return;
    }

    char busca[31];
    printf("\n--- Pesquisa por Titulo ---\n");
    printf("Digite o titulo: ");
    ler_string(busca, 31);

    int encontrados = 0;
    for (int i = 0; i < qtd_livros; i++)
    {
        /* strcmp devolve 0 quando as strings sao iguais */
        if (strcmp(livros[i].titulo, busca) == 0)
        {
            if (encontrados == 0)
            {
                printf("\nLivros encontrados:\n");
            }
            exibir_livro(livros[i]);
            encontrados++;
        }
    }

    if (encontrados == 0)
    {
        printf("\nNenhum livro com o titulo \"%s\" foi encontrado.\n", busca);
    }
    else
    {
        printf("\nTotal: %d livro(s) encontrado(s).\n", encontrados);
    }
}

/* ============ Pesquisa por gênero ============ */

/* Verifica se o genero existe no vetor de generos (strcmp) */
int genero_existe(Genero generos[], int qtd_generos, const char *descricao)
{
    for (int i = 0; i < qtd_generos; i++)
    {
        if (strcmp(generos[i].descricao, descricao) == 0)
        {
            return 1;
        }
    }
    return 0;
}

void pesquisar_por_genero(Livro livros[], int qtd_livros,
                          Genero generos[], int qtd_generos)
{
    if (qtd_livros == 0)
    {
        printf("\nNenhum livro cadastrado ainda.\n");
        return;
    }

    char busca[31];
    printf("\n--- Pesquisa por Genero ---\n");
    printf("Digite o genero: ");
    ler_string(busca, 31);

    /* 1) Verifica se o genero existe no vetor de generos */
    if (!genero_existe(generos, qtd_generos, busca))
    {
        printf("\nO genero \"%s\" nao esta cadastrado.\n", busca);
        return;
    }

    /* 2) Procura todos os livros desse genero */
    int encontrados = 0;
    for (int i = 0; i < qtd_livros; i++)
    {
        if (strcmp(livros[i].genero, busca) == 0)
        {
            if (encontrados == 0)
            {
                printf("\nLivros do genero \"%s\":\n", busca);
            }
            exibir_livro(livros[i]);
            encontrados++;
        }
    }

    if (encontrados == 0)
    {
        printf("\nNenhum livro cadastrado com o genero \"%s\".\n", busca);
    }
    else
    {
        printf("\nTotal: %d livro(s) encontrado(s).\n", encontrados);
    }
}

/* ============ Menu ============ */

void exibir_menu(void)
{
    printf("\n========= BIBLIOTECA =========\n");
    printf("1 - Cadastrar livro\n");
    printf("2 - Cadastrar genero\n");
    printf("3 - Pesquisar por titulo\n");
    printf("4 - Pesquisar por genero\n");
    printf("0 - Encerrar\n");
    printf("==============================\n");
    printf("Opcao: ");
}

/* ============ main ============ */

int main(void)
{
    Livro livros[5];
    Genero generos[100];

    int qtd_livros = 0;
    int qtd_generos = 0;
    int opcao;

    do
    {
        exibir_menu();
        scanf("%d", &opcao);
        limpar_buffer();

        switch (opcao)
        {
        case 1:
            cadastrar_livro(livros, &qtd_livros);
            break;
        case 2:
            cadastrar_genero(generos, &qtd_generos);
            break;
        case 3:
            pesquisar_por_titulo(livros, qtd_livros);
            break;
        case 4:
            pesquisar_por_genero(livros, qtd_livros, generos, qtd_generos);
            break;
        case 0:
            printf("\nEncerrando...\n");
            break;
        default:
            printf("\nOpcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}