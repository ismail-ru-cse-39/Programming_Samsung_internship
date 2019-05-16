#include<stdio.h>

#define SZ 1000

int Grid[SZ][SZ];
int N,M,K;
int Ans =0;
int Test_cases,Case;


void take_input()
{
    scanf("%d %d %d", &N,&M,&K);

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M ; j++)
        {
            scanf("%d", &Grid[i][j]);
        }
    }
}

int cnt_zero(int u)
{
    int cnt =0 ;

    for(int i = 1; i <= M; i++)
    {
        if(Grid[u][i] == 0)
        {
            cnt++;
        }
    }

    return cnt;
}

int isSame(int i,int j)
{
    for(int k = 1; k <= M ; k++){
        if(Grid[i][k] != Grid[j][k]){
            return 0;
        }
    }

    return 1;
}

void solve()
{
    Ans= 0;

    for(int i = 1; i <= N ; i++)
    {

        int no_zero = cnt_zero(i);

        if(no_zero <= K && (K-no_zero) %2 == 0)
        {
            int cnt = 1;
            for(int j = i+1; j<= N ; j++)
            {
                if(isSame(i,j))
                {
                    cnt++;
                }
            }

            if(cnt > Ans){
                Ans = cnt;
            }
        }

    }
}


void print_output()
{
    printf("#%d %d\n",Case, Ans);
}


int main()
{
    freopen("in_bit.txt", "r", stdin);
    freopen("out_bit.txt", "w", stdout);

    scanf("%d", &Test_cases);

    for(Case = 1; Case <=Test_cases ; Case++)
    {
        take_input();
        solve();
        print_output();
    }
}
