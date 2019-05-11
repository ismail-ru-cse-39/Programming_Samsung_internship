#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("out.txt", "w", stdout);
    int cnt = 0;
    int u[1100],v[1100];


    for(int i = 1 ; i <= 100 ; i++)
    {
        cnt = 0;
        for(int i = 1 ; i <= 1000; i++)
        {

            u[i] = rand()%100;
            v[i] = rand()%100;

            if(u[i]!= v[i])
            {
                cnt++;

                //printf("%d %d\n",u,v);
            }
        }

        printf("80 %d\n", cnt);

        for(int i = 1 ; i <= 1000; i++){
            if(u[i] != v[i]){
                printf("%d %d\n",u[i],v[i]);
            }
        }

        printf("\n");
       // printf("%d\n\n",cnt);

    }
}
