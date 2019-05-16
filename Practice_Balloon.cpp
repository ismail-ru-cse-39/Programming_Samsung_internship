#include<stdio.h>

#define SZ 1000

int Dp[SZ][SZ];
int Balloon[SZ];
int N;
int Test_cases, Case;

void take_input()
{
    scanf("%d", &N);

    for(int i = 0 ; i < N ; i++){
        scanf("%d", &Balloon[i]);
    }
}


void init_dp()
{
    for(int i = 0 ; i < N ; i++){
        for(int j = 0; j < N ; j++){
            Dp[i][j] = 0;
        }
    }
}

void solve()
{
     int len,i,j,k;
     int left,right,before,after;

     init_dp();

     for(len = 1 ; len <= N ; len++){
        for(i = 0 ; i <= N - len ; i++){
            j = i+len-1;

            for(k = i ; k <= j ; k++){

                left= right = 1;

                if(i!=0){
                    left = Balloon[i-1];
                }

                if(j != N-1){
                    right = Balloon[j+1];
                }

                before = after = 0;

                if(i!=k){
                    before = Dp[i][k-1];
                }

                if(j!=k){
                    after = Dp[k+1][j];
                }

                int tmp = before + left*right + after;

                if(tmp > Dp[i][j]){
                    Dp[i][j] = tmp;
                }
            }
        }
     }
}


void print_output()
{
    printf("#%d %d\n", Case, Dp[0][N-1]-1);
}

int main()
{

    freopen("in_ballooon.txt", "r", stdin);
    freopen("out_balloon.txt", "w", stdout);

    scanf("%d",&Test_cases);

    for(Case = 1; Case <= Test_cases ; Case++){
        take_input();
        solve();
        print_output();
    }
}

