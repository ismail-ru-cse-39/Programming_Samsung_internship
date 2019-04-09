#include <stdio.h>

#define sc(a,b) scanf("%d %d",&a,&b)
#define sc1(a) scanf("%d",&a)
#define out(a) printf("%d",a)
#define space() printf(" ")
#define line() printf("\n")
#define SZ 10

int Arr[SZ];
int Check[SZ];


void init()
{
    for(int i = 0 ; i < SZ ; i++)
    {
        Check[i] = 0;
    }
}

int solve(int level, int total)
{
    int i;

    if(level == 5 && total == 23)
    {
        return 1;
    }

    for( i = 0; i < 5; i++)
    {
        if(!Check[i])
        {
            Check[i] = 1;

            if(solve(level+1, total+Arr[i]))
            {
                return 1;
            }
            if(solve(level+1, total-Arr[i]))
            {
                return 1;
            }

            if(solve(level+1, total * Arr[i]))
            {
                return 1;
            }

            Check[i] = 0;
        }


    }

    return 0;
}

void take_input()
{


    init();

    for(int i = 0 ; i  < 5 ; i++)
    {
        Check[i] = 1;
        if(solve(1,Arr[i]))
        {
            printf("Possible\n");
            return;
        }
        Check[i] = 0;
    }

    printf("Impossible\n");
}


int main()
{

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    while(scanf("%d %d %d %d %d", &Arr[0], &Arr[1], &Arr[2],&Arr[3],&Arr[4]) == 5)
    {
        if(Arr[0] == 0 && Arr[1] ==0 && Arr[2] == 0 && Arr[3] == 0 && Arr[4] == 0)
        {
            return 0;
        }
        take_input();
    }

    return 0;
}
