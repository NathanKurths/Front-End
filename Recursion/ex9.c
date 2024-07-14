#include <stdio.h>

void vetor_reverso(int cont, int a, int *vetor);

int main()
{
    int t;
    printf("Digite o tamanho do vetor:\n");
    scanf("%d", &t);
    int vetor[t];

    for (int i = 0; i < t; i++)
    {
        printf("Digite o valor do vetor %d: \n", i);
        scanf("%d", &vetor[i]);
    }
    vetor_reverso(0, t, vetor);

    return 0;
}

void vetor_reverso(int cont, int a, int *vetor)
{
    int aux;
    if (cont < a)
    {
        aux = vetor[cont];
        vetor[cont] = vetor[a];
        vetor[a] = aux;
        vetor_reverso(cont + 1, a - 1, vetor);
    }
}
