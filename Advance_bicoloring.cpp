#include <stdio.h>

#define SZ 1000

int Path[SZ][SZ];
int Colored[SZ];
int N,M;
int Flag;
int Test_case, Case;

void init_path()
{
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= N ; j++){
            Path[i][j] = 0;
        }
    }
}

void init_colored()
{
    for(int i = 1; i <= N ; i++){
        Colored[i] = 0;
    }
}


void take_input()
{
    scanf("%d %d",&N,&M);

    init_path();

    for(int i = 1 ; i <= M ; i++){
        int u,v;

        scanf("%d %d",&u,&v);

        Path[u][v]= Path[v][u] = 1;
    }
}

void dfs(int u, int cur_color)
{

    Colored[u] = cur_color;

    for(int v = 1 ; v <= N ; v++){
        if(Path[u][v]){
            if(Colored[v] == 0){
                dfs(v, 3-cur_color);
            }

            else if(cur_color == Colored[v]){
                Flag = -1;
            }
        }
    }
}

void solve()
{
    init_colored();
    Flag = 0;

    for(int i = 1 ; i <= N ; i++){
        if(Colored[i] == 0){
            dfs(i,1);
        }
    }
}

void print_output()
{
    printf("#%d",Case);
    if(Flag == -1){
        printf("-1\n");
        return;
    }

    for(int i = 1; i <= N; i++){
        if(Colored[i] == 1){
            printf(" W");
        }
        if(Colored[i] == 2){
            printf(" B");
        }
    }

    printf("\n");
}

int main()
{

    freopen("in.txt", "r", stdin);

    scanf("%d", &Test_case);

    for(Case = 1 ; Case <= Test_case ; Case++){

        take_input();
        solve();
        print_output();
    }
}
