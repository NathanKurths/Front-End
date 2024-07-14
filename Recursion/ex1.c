#include <stdio.h>
int fatorial(int n);

int main()
{
    int n;
    scanf("%d", &n);
    fatorial(n);
    return 0;
}

int fatorial(int n)
{
    int resultado;
    if (n <= 1)
        return 1;
    else
    {
        resultado = n * fatorial(n - 1);
        return resultado;
    }
}