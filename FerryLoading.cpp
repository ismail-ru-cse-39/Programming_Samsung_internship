#include <stdio.h>

#define sc(a,b) scanf("%d %d",&a,&b)
#define sc1(a) scanf("%d",&a)
#define out(a) printf("%d",a)
#define space() printf(" ")
#define line() printf("\n")
#define SZ 200+10

int Test_cases,F_length,Car_arr[SZ];
int N;
int M;
int Path[SZ],Bin[SZ];

void solve(int i , int left, int right)
{
    int j;

    if(i == N)
    {
        return;
    }
    if(i > M)
    {
        M = i;
        for( j = 0 ; j < i ; j++)
        {
            Path[j] = Bin[j];
        }
    }

    if(left + Car_arr[i] <= F_length)
    {
        Bin[i] = 0;
        solve(i+1, left+Car_arr[i], right);
    }

    if(right + Car_arr[i] <= F_length)
    {
        Bin[i] = 1;
        solve(i+1, left, right+Car_arr[i]);
    }

}

void print(int m)
{
    out(m);
    line();


    for(int i = 0; i < m ; i++)
    {
        //out(Path[i]);

        //line();
        if(Path[i])
        {
            printf("Port\n");
        }
        else
        {
            printf("Starboard\n");
        }
    }
}

void take_input()
{
    sc1(Test_cases);
    getchar();

    for(int i = 1 ; i<= Test_cases ; i++)
    {
        getchar();
        sc1(F_length);

        F_length *= 100;

        N= 0;

        while(1)
        {
            int car;

            sc1(car);

            if(car == 0)
            {
                break;
            }

            Car_arr[N++] = car;

        }

        M = 0;
        solve(0,0,0);
        print(M);
        line();
    }

}


int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    take_input();

    return 0;
}

