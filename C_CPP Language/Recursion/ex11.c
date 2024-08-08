#include <stdio.h>

int mdc(int x, int y);

int main()
{
    int x = mdc(10,60);
    return 0;
}


int mdc(int x,int y){
    if(y==0) return x;
    return mdc(y,x%y);
}