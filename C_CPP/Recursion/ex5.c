#include <stdio.h>
int expoente(int b, int e);

int main()
{
    int i, j;
    printf("Digite respectivamente base e expoente:\n");
    scanf("%d %d", &i, &j);
    expoente(i, j);
    return 0;
}

int expoente(int b, int e)
{
    if (e == 0)
        return 1;
    else
    {
        int resultado;
        int cont = e;
        if (cont != 0)
        {
            resultado = b * expoente(b, e - 1);
        }
        return resultado;
    }
}