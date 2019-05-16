#include <stdio.h>

int Arr[7][7];
int Res_ar[5][5];
int Mx;

void take_input()
{
    for (int i = 1; i <= 6; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            scanf("%d", &Arr[i][j]);
        }
    }
}

void solve()
{
    int tmp[5][5];

    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            int sum = 0;
            for (int k = i; k < i + 3; k++)
            {
                for (int l = j; l < j + 3; l++)
                {
                    if ((k % 2 == 0 && i%2 == 1) || (k%2 == 1 && i%2 == 0))
                    {
                        sum += Arr[k][l + 1];
                        break;
                    }
                    else
                    {
                        sum += Arr[k][l];
                    }
                }


            }
            if (sum > Mx)
            {
                Mx = sum;
            }

            tmp[i][j] = sum;
        }
    }


    //debug
    for(int i = 1 ; i<= 4; i++){
        for(int j = 1 ; j<= 4 ; j++){
            printf("%d ",tmp[i][j]);
        }

        printf("\n");
    }
}

int main()
{
    freopen("in.txt", "r",stdin);

    take_input();
    Mx = -63;
    solve();
    printf("%d\n", Mx);
}

