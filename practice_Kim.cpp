#include <stdio.h>

#define SZ 1000

int Visited[SZ];
int N,Ans;
int Test_cases, Case;

struct co_ordinate_struct{
    int x,y;

};

co_ordinate_struct Pos[SZ];


void init_visited()
{
    for(int i = 1;  i <= N+1; i++){
        Visited[i] = 0;
    }
}

void take_input()
{
    scanf("%d", &N);

    int u,v;

    //office
    scanf("%d %d",&u, &v);

    Pos[1].x = u;
    Pos[1].y = v;

    //home
    scanf("%d %d", &u,&v);

    Pos[0].x = u;
    Pos[0].y = v;

    for(int i = 2; i <= N+1; i++){
        scanf("%d %d", &u, &v);

        Pos[i].x = u;
        Pos[i].y = v;
    }




}


int absdif(int a, int b)
{
    if(a > b){
        return a - b;
    }

    return b - a;
}

void fil(int level, int i, int cost)
{
    if(level == N+1){
        cost += absdif(Pos[i].x,Pos[0].x) + absdif(Pos[i].y, Pos[0].y);

        if(cost < Ans){
            Ans = cost;
        }
        else{
           return;
        }

    }

    for(int j = 2; j <= N+1; j++){
        if(Visited[j] == 0){
            Visited[j] = 1;
            fil(level+1, j, cost+absdif(Pos[i].x, Pos[j].x) + absdif(Pos[i].y, Pos[j].y));
            Visited[j] = 0;
        }
    }
}

void solve()
{

    init_visited();

    Ans = 9999;

    fil(1,1,0);

}

void print_output()
{
    printf("#%d %d\n",Case,Ans);
}

int main()
{
    freopen("in.txt", "r", stdin);

    scanf("%d", &Test_cases);

    for(Case = 1 ; Case <= Test_cases; Case++){
        take_input();


        solve();

        print_output();
    }
}
