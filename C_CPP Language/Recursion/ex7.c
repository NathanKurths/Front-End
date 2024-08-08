#include <stdio.h>

int imprime_vetor(int cont, int tam, int *vetor);

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
    imprime_vetor(0, t, vetor);
    return 0;
}

int imprime_vetor(int cont, int tam, int *vetor)
{
    if(cont==tam) return 1;
    else
    {
        printf("[%d] ", vetor[cont]);
    }
    return imprime_vetor(cont + 1, tam, vetor);
}
