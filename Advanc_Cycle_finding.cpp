#include <stdio.h>

#define SZ 1000

int Path[SZ][SZ];
int Visited[SZ];
int N,M;
int Test_cases, Case;
int Ans = 1;


void init_visited()
{
    int i;
    for(i = 1; i <= N; i++){
        Visited[i] = 0;
    }
}

void init_path()
{
    int i,j;

    for(i = 1 ; i <= N ; i++){
        for(j = 1 ; j<= N ; j++){
            Path[i][j] = 0;
        }
    }
}

void take_input()
{
    int i,j;
    int u,v;

    scanf("%d %d", &N,&M);

    init_path();

    for(i = 0 ; i < M ; i++){

        scanf("%d %d", &u,&v);

        Path[u][v] = 1;
    }

}

int dfs(int src, int u)
{
    int v;

    Visited[u] = 1;

    for(v = 1 ; v <= N ; v++){
        if(Path[u][v]){
            if(0 == Visited[v]){
                if(1 == dfs(src,v)){
                    return 1;
                }
            }
            else if(v == src){
                return 1;
            }
        }
    }

    Visited[u] = 0;

    return 0;
}

void solve()
{
    init_visited();
    Ans = 1;

    int src;
    int i;

    for(i = 1; i <= N ; i++){
        if(0 == Visited[i]){

            if(1 == dfs(i, i)){
                Ans = 0;
                break;
            }
        }
    }
}


void print_output()
{
    int i;

    printf("#%d ",Case);

    if(Ans == 0){
        for(i = 1; i <= N ; i++){
            if(1 == Visited[i]){
                printf(" %d",i);
            }
        }
        printf("\n");
        return;
    }

    printf("-1\n");
}


int main()
{
    freopen("in.txt", "r", stdin);

    scanf("%d", &Test_cases);

    for(Case = 1;  Case <= Test_cases ; Case++){
        take_input();
        solve();
        print_output();
    }
}
