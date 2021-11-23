#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int generate(int type);
int save_key();
void about(void);

// DECLARAÇÃO DE VETORES E INICIALIZAÇÃO
int vetor_numerico[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

char vetor_caracteres[52] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w',
                              'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
                              'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
                            };

char vetor_especiais[17] = { '_', '.', '-', '$', '%', '/', '&', '(', ')', '[', ']', '?', '!', '@', '=', '+', '*' };

int main(void)
{
    int opcao;
    int opcao1;
    int opcao_tipo1 = 1;
    int opcao_tipo2 = 2;
    int opcao_tipo3 = 3;
    int opcao_tipo4 = 4;

    printf("GERADOR DE SENHAS [nnilux]\n");
    printf("\n");
    printf("SELECIONE UMA OPÇÃO\n");
    printf("\n");
    printf("[1] GERAR SENHA\n");
    printf("[2] SOBRE O GERADOR DE SENHAS\n");
    printf("[3] SAIR\n");
    scanf("%d", &opcao);

    if(opcao == 1)
    {
        printf("SELECIONE UMA OPÇÃO\n");
        printf("[1] GERAR SENHA COM LETRAS\n");
        printf("[2] GERAR SENHA COM NUMEROS\n");
        printf("[3] GERAR SENHA COM LETRAS E NUMEROS\n");
        printf("[4] GERAR SENHA COM LETRAS - NUMEROS - CARACTERES ESPECIAIS\n");
        scanf("%d", &opcao1);


        if(opcao1 == 1)
            generate(opcao_tipo1);

        if(opcao1 == 2)
            generate(opcao_tipo2);

        if(opcao1 == 3)
            generate(opcao_tipo3);

        if(opcao1 == 4)
            generate(opcao_tipo4);
    }

    if(opcao == 2)
        about();

    if(opcao == 3)
        exit(0);

    return(0);
}

int generate(int type)
{
    char *password;
    int quantidade_caracteres;
    int resultado;
    int n;

    srand(time(0));
    password = (char *) malloc(sizeof(char));

    if(type == 1)
    {
        printf("DIGITE A QUANTIDADE DE CARACTERES A SEREM UTILIZADOS NA SENHA.\n");
        scanf("%d", &quantidade_caracteres);

        for(n = 0; n < quantidade_caracteres; n++)
        {

            printf("%c", vetor_caracteres[rand()%53]);
            sleep(1);
        }
        printf("\n");
        printf("SENHA GERADA COM SUCESSO\n");

    }

    if(type == 2)
    {
        printf("DIGITE A QUANTIDADE DE CARACTERES A SEREM UTILIZADOS NA SENHA.\n");
        scanf("%d", &quantidade_caracteres);

        for(n = 0; n < quantidade_caracteres; n++)
        {
            printf("%d", vetor_numerico[rand()%11]);
            sleep(1);
        }
        printf("\n");
        printf("SENHA GERADA COM SUCESSO\n");

    }

    if(type == 3)
    {
        printf("DIGITE A QUANTIDADE DE CARACTERES A SEREM UTILIZADOS NA SENHA.\n");
        scanf("%d", &quantidade_caracteres);
        resultado = quantidade_caracteres/2;

        for(n = 0; n < quantidade_caracteres; n++)
        {
            printf("%c", vetor_caracteres[rand()%53]);
            printf("%d", vetor_numerico[rand()%11]);
            if(n % 2 == 0)
            {
                if((rand()%11) % 2 == 0)
                    printf("%c", vetor_caracteres[rand()%53]);
                printf("%d", vetor_numerico[rand()%11]);
            }

            else
                printf("%d", vetor_numerico[rand()%11]);

            sleep(1);
        }
        printf("\n");
        printf("\n");
        printf("SENHA GERADA COM SUCESSO\n");
    }

    if(type == 4)
    {
        printf("DIGITE A QUANTIDADE DE CARACTERES A SEREM UTILIZADOS NA SENHA.\n");
        scanf("%d", &quantidade_caracteres);
        resultado = quantidade_caracteres / 2;

        for(n = 0; n <=resultado; n++)
        {
            printf("%c", vetor_caracteres[rand()%57]);

            if(n % 2 == 0)
            {
                if((rand()%11) % 2 == 0)
                    printf("%c", vetor_especiais[rand()%18]);

                else
                    printf("%d", vetor_numerico[rand()%11]);
            }

            else
                printf("%d", vetor_numerico[rand()%11]);

            sleep(1);
        }
        printf("\n");
    }

    free(password);
    return(0);
}

void about(void)
{
    printf("Gerador de Senha [nnilux] versao 1.0\n");

}
