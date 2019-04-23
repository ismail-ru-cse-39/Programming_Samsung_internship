#include <stdio.h>

#define SZ 1000

int Path[SZ][SZ];
int Color[SZ];
int N,M;
int Test_cases, Case;
int Total_color;

void init_path()
{
    int i,j;

    for(i = 1; i <= N ; i++){
        for(j = 1 ; j <= N ; j++){
            Path[i][j] = 0;
        }
    }
}

void take_input()
{
    scanf("%d %d %d", &N,&M,&Total_color);

    for(int i = 0 ; i < M ; i++){
        int u,v;

        scanf("%d %d", &u,&v);

        Path[u][v] = 1;
        Path[v][u] = 1;
    }
}

void init_color()
{
    for(int i = 1 ; i <= N ; i++){
        Color[i] = 0;
    }
}

int is_safe(int u, int c)
{
    for(int i =1 ; i <= N ; i++){
        if(Path[u][i] && c == Color[i]){
            return 0;
        }
    }

    return 1;
}

int graph_color(int u)
{
    if(u == N+1){
        return 1;
    }

    for(int c = 1; c <= Total_color ; c++){

        if(is_safe(u,c)){
            Color[u] = c;
            if(graph_color(u+1) == 1){
                return 1;
            }

            Color[u] = 0;
        }
    }

    return 0;
}

void print_output()
{
    for(int i = 1 ; i <= N ; i++){

            printf(" %d",Color[i]);

    }

    printf("\n");
}

void solve()
{
    init_color();

    if(graph_color(1)){
        printf("M colourable.\n");
        print_output();
    }

    else{
        printf("Not M colourable.\n");
    }
}

int main()
{

    freopen("in.txt", "r", stdin);

    scanf("%d", &Test_cases);

    for(int i = 1; i <= Test_cases ; i++){

        take_input();
        solve();
    }
}
