#include <stdio.h>
#include <math.h>

#define sc(a) scanf("%d",&a)
#define out(a) printf("%d",a)
#define outll(a) printf("%lld",a)
#define space() printf(" ")
#define line() printf("\n")

#define SZ 10020


int Arr_cube[SZ];
long long Dp[SZ];
int No_of_coins;
int Amount;
long long Res;

void make_coins()
{
    No_of_coins = 0;
    for(int i = 1 ; i <= 9261 ; i++)
    {
        if( i*i*i > 9261)
        {
            break;
        }
        Arr_cube[No_of_coins] = i*i*i;
        No_of_coins++;
    }

}

void init()
{
   Dp[0] = 1;

   for(int i = 0; i < No_of_coins ; i++)
    {
        for(int j = Arr_cube[i] ; j <= 10012; j++)
        {
            Dp[j] += Dp[j-Arr_cube[i]];
        }
    }
}






void print_output()
{
    outll(Res);
    line();
}


int main()
{
    make_coins();
    init();

    while(sc(Amount) == 1){
        Res = Dp[Amount];
        print_output();
    }

    return 0;
}
