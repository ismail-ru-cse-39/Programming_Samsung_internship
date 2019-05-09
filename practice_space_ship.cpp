#include <stdio.h>

#define SZ 200

int Grid[SZ][7];
int Ans = 0;
int N;
int Test_cases, Case;

void take_input()
{
    scanf("%d", &N);

    for(int i = 1;  i <= N ; i++){
        for(int j = 1; j <= 5; j++){
            scanf("%d",&Grid[i][j]);
        }
    }

}


int max_num(int a, int b)
{
    if(a > b){
        return a;
    }

    return b;
}


int fil(int x, int y, int cost, int b_r)
{
    if(x == 0){
        return cost;
    }

    if(Grid[x][y] == 1){
        cost++;
    }

    if(Grid[x][y] == 2){
        if(b_r == -1){
            b_r = x;
        }
        else if(b_r - x > 4){
            return cost;
        }
    }


    int ret;

    ret = fil(x-1, y, cost, b_r);

    if((y-1) >= 1){
        ret = max_num(ret, fil(x-1, y-1, cost, b_r));
    }

    if((y+1) <= 5){
        ret = max_num(ret, fil(x-1, y+1, cost, b_r));
    }


    return ret;
}


void solve()
{
    //padding

    for(int i =  1 ; i <= 5; i++){
        Grid[N+1][i] = 0;
    }


    Ans = fil(N+1,3,0, -1);
}

void print_output()
{
    printf("#%d %d\n",Case, Ans);
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    scanf("%d", &Test_cases);

    for(Case = 1 ; Case <= Test_cases; Case++){
        take_input();
        solve();
        print_output();
    }
}
