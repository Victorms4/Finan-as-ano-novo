#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    FILE *entrada, *saida;
    char comida[15], bebida[15], decoracao[15], outros[15], convidados[15];
    float total, porPessoa;

    setlocale(LC_ALL, "Portuguese");

    entrada = fopen("planilha.csv", "r");
    if(entrada == NULL)
        exit(1);

    fscanf(entrada,"%[^;]", comida);
    fseek(entrada,1,SEEK_CUR);
    fscanf(entrada,"%[^;]", bebida);
    fseek(entrada,1,SEEK_CUR);
    fscanf(entrada,"%[^;]", decoracao);
    fseek(entrada,1,SEEK_CUR);
    fscanf(entrada,"%[^;]", outros);
    fseek(entrada,1,SEEK_CUR);
    fscanf(entrada,"%[^\n]", convidados);
    fseek(entrada,1,SEEK_CUR);

    printf("%s\n", comida);
    printf("%s\n", bebida);
    printf("%s\n", decoracao);
    printf("%s\n", outros);
    printf("%s\n", convidados);

    saida = fopen("preco.csv", "w");
    if (saida == NULL)
        exit(1);

    while(!feof(entrada)){
        fscanf(entrada,"%[^;]", bebida);
        fseek(entrada,1,SEEK_CUR);
        fscanf(entrada,"%[^;]", comida);
        fseek(entrada,1,SEEK_CUR);
        fscanf(entrada,"%[^;]", decoracao);
        fseek(entrada,1,SEEK_CUR);
        fscanf(entrada,"%[^;]", outros);
        fseek(entrada,1,SEEK_CUR);
        fscanf(entrada,"%[^\n]", convidados);

        total = atof(bebida) + atof(comida) + atof(decoracao) + atof(outros);
        porPessoa = total / atof(convidados);

        if(!feof(entrada)){
            printf("%s\n", bebida);
            printf("%s\n", comida);
            printf("%s\n", decoracao);
            printf("%s\n", outros);
            printf("%s\n", convidados);
            printf("Preco = %5.2f\n\n", total);
            printf("Preco por pessoa = %5.2f\n\n", porPessoa);
            fprintf(saida, "%s;%5.2f;%5.2f", convidados, total, porPessoa);
        }
    }
    
    fclose(entrada);
    fclose(saida);

    }
