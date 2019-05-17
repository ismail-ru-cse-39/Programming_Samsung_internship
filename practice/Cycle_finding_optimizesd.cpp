#include <stdio.h>

#define SZ 1000

int Graph[SZ][SZ];
int Color[SZ];
int Flag = 0;
int N,M;
int Cnt = 0;
int track_color;
int Test_cases, Case;
int Flag1;


void init_graph()
{
    for(int i = 1 ; i <= N; i++){
        for(int j = 1; j <= N ; j++){
            Graph[i][j] = 0;
        }
    }
}


void take_input()
{
    scanf("%d %d", &N,&M);

    init_graph();

    for(int i = 0 ; i < M ; i++){
        int u,v;

        scanf("%d %d", &u,&v);

        Graph[u][v] = 1;
    }
}

void init_color()
{
    for(int i = 1; i <= N ; i++){
        Color[i] = 0;
    }
}


int dfs(int u)
{

    if(Flag1 == 1){
        return 1;
    }

    Color[u] = Cnt++;

    for(int i = 1;  i <= N ; i++){
        if(Graph[u][i] == 1){
            if(Color[i] == 0){
                if(dfs(i) == 1){
                    Flag1= 1;
                    return 1;
                }
            }

            else if(Color[i] > 0){
                track_color = Color[i];
                Flag1= 1;
                return 1;
            }
        }
    }


    Color[u] = -1;

    return 0;
}


void solve()
{
    Flag = 0;
    Flag1 = 0;

    init_color();

    for(int i = 1; i <= N ; i++){
        if(Color[i] == 0){
            Cnt = 1;
            if(1 == dfs(i)){
                Flag = 1;
                return;
            }
        }
    }
}



void print_output()
{
    printf("#%d",Case);
    if(Flag == 0)
    {

        printf(" -1\n");
        return;
    }

    int mark[SZ];

    for(int i =1 ; i <= N ; i++){
        mark[i] = 0;
    }

    for(int i = 1; i <= N ; i++){
        if(Color[i] >= track_color){
            mark[i] = 1;
        }
    }


    for(int i = 1; i <= N ;i++){
        if(mark[i] > 0){
            printf(" %d",i);
        }
    }

    printf("\n");
}

int  main()
{
    freopen("in.txt", "r", stdin);


    scanf("%d",&Test_cases);

    for(Case = 1; Case <= Test_cases; Case++){
        take_input();
        solve();
        print_output();
    }
}
