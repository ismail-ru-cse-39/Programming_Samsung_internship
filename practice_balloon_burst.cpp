#include <stdio.h>

#define SZ 1000

int Dp[SZ][SZ];
int Balloon[SZ];
int N;
int Test_cases,Case;

void init_dp()
{
    for(int i = 0 ; i <= N+2 ; i++){
        for(int j = 0 ; j <= N+2 ; j++){
            Dp[i][j] = 0;
        }
    }
}


/*void print_dp()
{
    for(int i = 0 ;i < N+2 ; i++){
        for(int j = 0 ;j < N+2 ; j++){
            printf("%d ",Dp[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");
}

void print_balloon()
{
    printf("%d\n\n",N);
    for(int i = 0 ; i< N ; i++){
        printf("%d ",Balloon[i]);
    }

    printf("\n\n");
}
*/


void solve()
{
    int i,j,k,len;

    init_dp();

    for(len = 1; len <= N ; len++){
        for(i = 0; i <= N-len ; i++){
            j = len+i-1;

            for(k = i ; k <= j ; k++){
                int left = 1;
                int right = 1;

                if(i!= 0){
                    left = Balloon[i-1];
                }

                if(j != N-1){
                    right = Balloon[j+1];
                }

                int before = 0;
                int after = 0;

                if(i != k){
                    before = Dp[i][k-1];
                }
                if(j != k){
                    after = Dp[k+1][j];
                }


                int tmp = before + left * right + after;

                if(tmp > Dp[i][j]){
                    Dp[i][j] = tmp;
                }
            }
        }
    }
}

void take_input()
{
    scanf("%d",&N);

    for(int i = 0 ; i < N ; i++){
        scanf("%d",&Balloon[i]);
    }

}

void print_output()
{

    printf("#%d %d\n",Case, Dp[0][N-1]-1);
}

int main()
{
    freopen("in.txt", "r", stdin);
    scanf("%d",&Test_cases);

    for(Case = 1 ; Case <= Test_cases; Case++){
        take_input();
        solve();
        //print_dp();
        //print_balloon();

        print_output();
    }
}
