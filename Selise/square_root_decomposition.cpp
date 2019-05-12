#include <bits/stdc++.h>

using namespace std;

#define SZ 1000

int Ar[SZ];
int Sum[SZ];
int Total;
int L,R;
int N;
int Test_cases, Case;


void take_input()
{
    scanf("%d", &N);

    for(int i = 0 ; i < N; i++)
    {
        scanf("%d",&Ar[i]);
    }


}


void calculate_sum()
{
    int len = (int)sqrt(N*1.0)+1;


    for(int i =0 ; i < N ; i++)
    {
        Sum[i/len] += Ar[i];
    }
}


void quary()
{
    int len = (int)sqrt(N*1.0)+1;

    for(int i = L ; i<= R;)
    {
        if((i%len) == 0 && i+len-1 <= R)
        {
            Total += Sum[i%len];

            i = i+len;
        }

        else
        {
            Total += Ar[i];
            ++i;
        }
    }
}


void solve()
{


    Total = 0;

    quary();
}


void print_output()
{
    printf("%d\n",Total);
}


int main()
{



    take_input();

    calculate_sum();

    scanf("%d", &Test_cases);

    for(Case = 1 ; Case <= Test_cases; Case++)
    {

        scanf("%d %d", &L,&R);
        L--;
        R--;


        solve();

        print_output();

    }
    return 0;
}
