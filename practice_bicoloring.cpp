#include <stdio.h>

#define SZ 200+10

int Graph[SZ][SZ];
int Colored[SZ];
int N,M;
int Ans = 0;
int Test_cases, Case;


void init_graph()
{
    for(int i =0 ;  i< N ; i++)
    {
        for(int j = 0; j < N ; j++)
        {
            Graph[i][j] = 0;
        }
    }
}



void init_colored()
{
    for(int i = 0; i < N ; i++)
    {
        Colored[i] = 0;
    }
}

void dfs(int u, int curcolor)
{
    Colored[u] = curcolor;

    for(int v = 0;  v < N ; v++)
    {
        if(Graph[u][v])
        {
            if(Colored[v] == 0)
            {
                dfs(v,3-curcolor);
            }
            else if(Colored[v] == curcolor)
            {
                Ans = 1;
            }
        }
    }
}

void solve()
{
    init_colored();
    Ans = 0;

    for(int i = 0 ; i <  N  ; i++)
    {
        if(Colored[i] == 0)
        {
            dfs(i,1);
        }
    }
}


void print_case()
{

    /*if(Ans == 1){
        printf("#%d -1",Case);
    }

    else{
        printf("#%d",Case);

        for(int i = 1; i <= N ; i++){
            if(Colored[i] != 0){}
        }
    }*/


    if(Ans == 1)
    {
        printf("NOT BICOLORABLE.\n");
    }
    else
    {
        printf("BICOLORABLE.\n");
    }
}



void take_input()
{
    while(scanf("%d", &N ) == 1)
    {
        if(N==0)
        {
            return;
        }

        scanf("%d", &M);

        init_graph();

        for(int i = 0; i < M ; i++)
        {
            int u,v;

            scanf("%d %d", &u, &v);

            Graph[u][v] = 1;
            Graph[v][u] = 1;
        }


        solve();
        print_case();

        //print_graph();


    }
}


int main()
{

    freopen("in.txt", "r", stdin);
    freopen("out.txt","w", stdout);

    take_input();


}
