#include <stdio.h>

#define SZ 1000

int Path[SZ][SZ];
int Colored[SZ];
int Test_cases,Case;
int N,M;


void init_color()
{
    for(int i = 1 ; i <= N ; i++){
        Colored[i] = 0;
    }
}


void init_path()
{
    for(int i = 1; i <= N ; i++){
        for(int j = 1; j <= N ; j++){
            Path[i][j] = 0;
        }
    }
}


void take_input()
{
    scanf("%d %d", &N, &M);

    init_path();

    for(int i = 1 ; i<= M ; i++){
        int u,v;

        scanf("%d %d", &u, &v);

        Path[u][v] = 1;
        Path[v][u] = 1;
    }
}


int dfs(int u, int cur_color)
{
    Colored[u] = cur_color;

    for(int i = 1; i <= N ; i++){
        if(Path[u][i]){
            if(!Colored[i]){
                if(dfs(i,3-cur_color)){
                    return 1;
                }
            }

            if(cur_color == Colored[i]){
                return 0;
            }
        }
    }

    return 1;
}

void solve()
{
    init_color();

    if(dfs(1,1)){
        printf("Bipartite\n");
    }
    else{
        printf("Not bipartite.\n");
    }
}

int main()
{
    freopen("in.txt", "r", stdin);

    scanf("%d",&Test_cases);

    for(Case = 1; Case <= Test_cases ; Case++){
        take_input();
        solve();
    }
}
