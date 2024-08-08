#include <stdio.h>

int soma_vetor(int tam, int *vetor);

int main()
{
    int t;
    printf("Digite o tamanho do vetor:\n");
    scanf("%d", &t);
    int vetor[t];

    for (int i = 1; i <= t; i++)
    {
        printf("Digite o valor do vetor %d: \n", i);
        scanf("%d", &vetor[i]);
    }

    soma_vetor(t, vetor);
}

int soma_vetor(int tam, int *vetor)
{
    if (tam == 0)
    {
        return 0;
    }
    else
    {
        int resultado;
        if (tam != 0)
        {
            resultado = vetor[tam] + soma_vetor(tam - 1, vetor);
        }
        return resultado;
    }
}
