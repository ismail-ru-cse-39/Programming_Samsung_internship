#include <stdio.h>

#define SZ 200

int Grid[SZ][SZ];
int Visit_cost[SZ][SZ];
int N;
int Mn;
int Ans = 0;
int Test_cases,Case;


void take_input()
{
    scanf("%d", &N);

    for(int i = 0; i < N ; i++)
    {
        for(int j = 0 ; j < N ; j++){
            scanf("%d", &Grid[i][j]);
            Visit_cost[i][j] = 99999;
        }
    }
}

int max_num(int a, int b)
{
    if(a > b)
    {
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

void fil(int i, int j, int cnt, int mx)
{
    if(Grid[i][j] == 0){
        cnt++;
        mx = max_num(mx,cnt);
    }

    if(Grid[i][j] == 1){
        cnt = 0;
    }

    if(Grid[i][j] == 3){
        Mn = min_num(Mn,mx);
    }

    if(Visit_cost[i][j] <= mx){
        return;
    }

    Visit_cost[i][j] = mx;



    //left

    if((j-1) >= 0 && Grid[i][j-1] != 0){
        fil(i,j-1,0,mx);
    }

    //right

    if((j+1) < N  && Grid[i][j+1] != 0){
        fil(i,j+1,0,mx);
    }

    //up

    if((i-1) >= 0)
    {
        fil(i-1,j,cnt,mx);
    }

    //down

    if((i+1) < N){
        fil(i+1,j,cnt,mx);
    }
}

void solve()
{
    Mn = 99999;

    fil(N-1,0,0,0);
}


void print_output()
{
    printf("#%d %d\n",Case,Mn);
}


int main()
{
    freopen("in_rock.txt", "r", stdin);
    freopen("out_rock.txt", "w", stdout);

    scanf("%d", &Test_cases);

    for(Case = 1; Case <= Test_cases ; Case++){
        take_input();
        solve();
        print_output();
    }
}
