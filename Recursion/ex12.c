#include <stdio.h>

int palindromo(char *str, int tam);

int main()
{
    char frase[4] = "anao";
    palindromo(frase,4);
    return 0;
}

int palindromo(char *str, int tam) {
    if (tam <= 1) return 1; 
    else if (str[0] != str[tam-1]) return 0;
    return palindromo(str++, tam-2);
}