#include <stdio.h>

#define SZ 1000
int Grid[SZ][SZ];
int Cost[SZ][SZ];
int N,Mn;
int Test_cases,Case;

void take_input()
{
    scanf("%d", &N);

    for(int i = 0 ; i < N ; i++){
        for(int j = 0; j < N ; j++){
            scanf("%d", &Grid[i][j]);
            Cost[i][j] = 9999;
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


int min_num(int a, int b)
{
    if(a < b){
        return a;
    }

    return b;
}


void fil(int x, int y, int cnt, int mx)
{
    if(Grid[x][y] == 0){
        cnt++;
        mx = max_num(cnt,mx);
    }

    if(Grid[x][y] == 1){
        cnt = 0 ;
    }

    if(Grid[x][y] == 3){
        Mn = min_num(mx, Mn);
    }

    if(Cost[x][y] <= mx){
        return;
    }
    Cost[x][y] = mx;


    //left

    if((y-1) >= 0 && Grid[x][y-1] != 0){
        fil(x, y-1, 0, mx);
    }

    //right

    if((y+1) < N && Grid[x][y+1] != 0){
        fil(x, y+1, 0, mx);
    }

    //up

    if((x-1) >= 0 ){
        fil(x-1, y, cnt, mx);
    }

    //down

    if((x+1) < N){
        fil(x+1, y, cnt, mx);
    }
}


void solve()
{

    Mn =99999;

    fil(N-1,0,0,0);
}

void print_output()
{
    printf("#%d %d\n",Case, Mn);
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
