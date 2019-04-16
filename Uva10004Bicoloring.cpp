//Uva10004
//will solve

#include <stdio.h>
#include <math.h>


#define sc1(a) scanf("%d",&a)
#define out(a) printf("%d",a)
#define space() printf(" ")
#define line() printf("\n")

#define SZ 210

int N;
int Graph[SZ][SZ];
int Visited[SZ];
//int Color = 0;
int Grap_color[SZ];
int Flag = 0;

void init_graph()
{
    for (int i = 0; i < SZ; i++)
    {
        for (int j = 0; j < SZ; j++)
        {
            Graph[i][j] = 0;
        }
    }
}

void init()
{
    for (int i = 0; i < SZ; i++)
    {
        Visited[i] = 0;
        Grap_color[i] = 0;
    }
}

void take_input()
{
    int edges;

    sc1(edges);

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        sc1(u);
        sc1(v);

        Graph[u][v] = 1;
        Graph[v][u] = 1;
    }
}

void dfs(int u )
{
    int Color ;
    if(Grap_color[u] == 1)
    {
        Color = 2;
    }
    else if(Grap_color[u] == 2)
    {
        Color = 1;
    }


    Visited[u] = 1;

/*
    printf("--- > %d Color ::%d next color ::%d\n" , u , Grap_color[u] , Color) ;
    for(int i  =0 ; i < N  ; i++)
        printf(" %d" , Grap_color[i]) ;
    printf("\n") ;
*/

    for(int v = 0 ; v < N ; v++)
    {

        if( Visited[v] && Grap_color[u] == Grap_color[v] && Graph[u][v])
        {
            Flag = 1;
        }
        if(Graph[u][v] && Visited[v] == 0)
        {
            Grap_color[v] = Color;

            dfs(v);

        }


/*
        if(Graph[u][v] == 1){
            if(Visited[v] == 1){
                if(Grap_color[v] == Grap_color[u]){
                    Flag = 1 ;
                }
            }
            else{
                Grap_color[v] = Color ;
                dfs(v) ;
            }
        }
*/
    }



}


void solve()
{
//    Color = 1;
    Flag = 0;
    Grap_color[0] = 1;

    dfs(0);
}


void print_output()
{
    if(Flag == 1)
    {
        printf("NOT BICOLORABLE.\n");
    }
    else
    {
        printf("BICOLORABLE.\n");
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);


    while (sc1(N) == 1)
    {
        if (N == 0)
        {
            return 0;
        }
        init();
        init_graph();
        take_input();


        solve();

        print_output();
    }
}
