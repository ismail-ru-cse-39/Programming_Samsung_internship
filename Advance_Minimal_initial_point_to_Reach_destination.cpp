#include <stdio.h>

#define SZ 100

int Grid[SZ][SZ];
int Dp[SZ][SZ];
int Test_cases,Case;
int Row,Col;


void take_input()
{
    scanf("%d %d", &Row, &Col);

    for(int i = 0 ; i< Row ; i++){
        for(int j = 0 ; j < Col ; j++){
            scanf("%d", &Grid[i][j]);
        }
    }
}

int Max(int a, int b)
{
    if(a > b){
        return a;
    }
    else{
        return b;
    }
}

int Min(int a, int b)
{
    if(a > b){
        return b;
    }
    return a;
}

void solve()
{

    //init_dp();

    int m = Row , n = Col;

    if(Grid[m-1][n-1] > 0){
        Dp[m-1][n-1] = 1;
    }
    else{
        Dp[m-1][n-1] = (Grid[m-1][n-1] *(-1))+1;
    }



    for(int i = m-2 ; i >= 0 ; i--){

        Dp[i][n-1] = Max(Dp[i+1][n-1] - Grid[i][n-1], 1);
    }

    for(int j = n-2 ; j >= 0 ; j--){
        Dp[m-1][j] = Max(Dp[m-1][j+1] - Grid[m-1][j], 1);
    }


    for(int i = m- 2 ; i >= 0 ; i--){
        for(int j = n - 2 ; j >= 0 ; j--){
            int min_point = Min(Dp[i+1][j], Dp[i][j+1]);
            Dp[i][j] = Max(min_point - Grid[i][j], 1);
        }
    }



}

void print_output()
{
    printf("#%d %d\n",Case, Dp[0][0]);
}

int main()
{

    freopen("in.txt", "r", stdin);

    scanf("%d",&Test_cases);

    for(Case = 1; Case <= Test_cases ; Case++){
        take_input();
        solve();

        print_output();
    }
}
