#include <bits/stdc++.h>

using namespace std;
#define SZ 10000

int N;

int prime[SZ];

void seive_of_eratosthenes()
{
    //vector<int >prime;

//    memset(prime, 1, sizeof(prime));

    for(int i = 1 ;  i<= N ; i++)
    {
        prime[i] = 1;
    }

    for(int i = 2 ; i*i <= N; i++ )
    {
        if(prime[i]  == 1)
        {
            //printf("-------------\n");
            for(int j = i*i ; j <= N ; j += i)
            {
                prime[j] = 0;
            }
        }
    }


    for(int i = 2 ; i <= N; i++)
    {
        if(prime[i])
        {
            printf("%d ", i);
        }
    }

    printf("\n");
}



int main()

{
    scanf("%d", &N);

    seive_of_eratosthenes();

    return 0;
}
