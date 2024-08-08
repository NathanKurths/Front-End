#include <stdio.h>

int soma(int n);

int main()
{
    int a;
    scanf("%d", &a);
    int x = soma(a);
    printf("%d\n", x);
    return 0;
}

int soma(int n)
{
    int resultado;
    if (n <= 1)
        return 1;
    else
    {
        resultado = n + soma(n - 1);
        return resultado;
    }
}