#include <stdio.h>

int N,M;

int GCD(int a, int b)
{
    if(a == 0)
    {
        return b;
    }

    if(b == 0)
    {
        return a;
    }

    if(a == b)
    {
        return a;
    }

    if(a > b)
        return GCD(a-b,b);

    return GCD(a, b-a);
}


int main()
{
    scanf("%d %d", &N, &M);

    int g = GCD(N,M);

    printf("%d\n",g);

    return 0;
}
