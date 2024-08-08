#include <stdio.h>

int limite(int a, int b);

int main()
{
    int a, b;
    printf("Digite um limite inferior e superior respectivamente:\n");
    scanf("%d %d", &a, &b);
    limite(a, b);
    return 0;
}

int limite(int a, int b)
{
    if (a > b)
    {
        return 1;
    }
    else if (a <= b)
    {
        printf("[%d] ", a);
    }
    return limite(a + 1, b);
}
