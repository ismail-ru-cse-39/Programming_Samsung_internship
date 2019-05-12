
#include <stdio.h>
#include <algorithm>
#include <chrono>
#include <iostream>

#define SZ 200+10

using namespace std;
using namespace std::chrono;

int Graph[SZ][SZ];
int Colored[SZ];
int N,M;
int Flag = 0;

void init_graph()
{
    for(int i = 0; i <= N ; i++){
        for(int j = 0; j <= N ; j++){
            Graph[i][j] = 0;
        }
    }
}


void take_input()
{
    scanf("%d", &M);
    init_graph();

    for(int i = 1; i <= M ; i++){
        int u,v;

        scanf("%d %d", &u,&v);

        Graph[u][v] = 1;
        Graph[u][v] = 1;
    }
}

void init_colored()
{
    for(int i =0; i <= N ; i++){
        Colored[i] = 0;
    }
}


void dfs(int u, int curcolor)
{
    Colored[u] = curcolor;

    if(Flag == 1){
        return;
    }

    for(int v = 0; v < N ; v++){
        if(Graph[u][v] == 1 || Graph[v][u] == 1){
            if(Colored[v] == 0){
                dfs(v, 3-curcolor);
            }

            else if(Colored[v] == curcolor){
                Flag = 1;
                return;
            }
        }
    }
}

void solve()
{
    Flag = 0;

    init_colored();

    for(int  i =0; i < N ; i++){
        if(Colored[i] == 0){
            dfs(i,1);
        }
    }
}

void print_output()
{
    if(Flag == 1){
        printf("NOT BICOLORABLE.\n");
        return;
    }

    printf("BICOLORABLE.\n");
}

int main()
{
    auto start = high_resolution_clock::now();


    freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    while(scanf("%d", &N) == 1){
        if(N == 0){
             auto stop = high_resolution_clock::now();

      auto duration = duration_cast<microseconds>(stop - start);

      cout << "Time taken by function: "
         << (double)duration.count()/1000000.00 << " seconds" << endl;


            return 0;
        }

        take_input();

        solve();
        print_output();

    }


}
