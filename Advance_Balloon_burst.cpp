#include <stdio.h>

#define SZ 1000

int Dp[SZ][SZ];
int Balloon[SZ];
int N;
int Test_cases, Case;


void print_arr()
{
    for(int i = 0; i < N ; i++){
        printf("%d ",Balloon[i]);
    }

    printf("\n\n");
}

void init_dp()
{
    for(int i = 0 ; i < N ; i++){
        for(int j = 0; j < N ; j++){
            Dp[i][j] = 0;
        }
    }
}

void take_input()
{
    scanf("%d", &N);

    for(int i = 0 ; i < N ; i++){
        scanf("%d", &Balloon[i]);
    }
}

void solve()
{
    int i,j,k,before,after;

    init_dp();

    for(int len = 1 ; len <= N ; len++){
        for(i = 0 ; i <= N-len ; i++){
            j = len+i-1;

            for(k = i ; k <= j ; k++){
                int left_value = 1;
                int right_value = 1;

                if(i!=0){
                    left_value = Balloon[i-1];
                }
                if(j != N-1){
                    right_value = Balloon[j+1];
                }

                before = 0;
                after = 0;

                if(i != k){
                    before = Dp[i][k-1];
                }

                if(j != k){
                    after = Dp[k+1][j];
                }

                 int tmp = before + left_value * right_value + after;

                 if(tmp > Dp[i][j]){
                    Dp[i][j] = tmp;
                 }
            }
        }
    }
}


void print_output()
{
    printf("#%d %d\n",Case,Dp[0][N-1]-1);
}


int main()
{
    freopen("in.txt", "r", stdin);

    scanf("%d",&Test_cases);

    for(Case = 1 ; Case <= Test_cases ; Case++)
    {
        take_input();
        //print_arr();
        solve();
        print_output();
    }
}
