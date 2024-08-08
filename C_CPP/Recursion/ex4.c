#include <stdio.h>

int incrementar(int a, int b, int c);

int main()
{
    int a, b, c;
    printf("Digite um limite inferior,superior, e incrementação respectivamente:\n");
    scanf("%d %d %d", &a, &b, &c);
    incrementar(a, b, c);
    return 0;
}

int incrementar(int a, int b, int c)
{
    if (a > b)
    {
        return 1;
    }
    else if (a <= b)
    {
        printf("[%d] ", a);
    }
    return incrementar(a + c, b, c);
}
