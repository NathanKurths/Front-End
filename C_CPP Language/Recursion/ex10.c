#include <stdio.h>

int mult(int a, int b);

int main()
{
    int x = mult(9,10);
    return 0;
}


int mult(int a,int b){
    if(a==0 || b==0) return 0;
    else if(a==1) return b;
    else if(b==1) return a;
    else return a+mult(a,b-1);
}