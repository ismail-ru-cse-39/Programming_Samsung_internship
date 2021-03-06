#include <stdio.h>
#include <algorithm>
#include <chrono>
#include <iostream>
#define SZ 1000

using namespace std;
using namespace std::chrono;

int Graph[SZ][SZ];
int Visited[SZ];
int Tmp[SZ];
int N,M;
int Cnt = 1;
int Flag = 0;
int Node_color;
int Test_cases,Case;


void init_graph()
{
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N ; j++){
            Graph[i][j] = 0;
        }
    }
}


void take_input()
{

    scanf("%d %d",&N, &M);

    init_graph();

    int u,v;

    for(int i = 1; i <= M ; i++){
        scanf("%d %d", &u,&v);

        Graph[u][v] = 1;
    }
}

void init_visited()
{
    for(int i = 1; i<= N ; i++){
        Visited[i] = 0;
    }
}

int dfs(int u){

    Visited[u] = Cnt++;

    for(int v = 1 ; v <= N ; v++){
        if(Graph[u][v] == 1){
            if(Visited[v] > 0){
                Node_color = Visited[v];
                return 1;
            }

            else if(Visited[v] == 0){
                if(dfs(v) == 1){
                    return 1;
                }
            }
        }
    }


    Visited[u] = -2;

    return 0;

}

void solve()
{
    Flag = 0;

    init_visited();
    Cnt = 1;

    for(int i = 1 ;  i <= N ; i++){
        if(Visited[i] == 0){
            if(dfs(i) == 1){
                Flag = 1;
                return;
            }
        }
    }
}


void init_tmp()
{
    for(int i = 1; i <= N ; i++){
        Tmp[i] = 0;
    }
}

void print_output()
{
    printf("#%d",Case);

    if(Flag == 0){
        printf(" 0\n");
        return;
    }

    init_tmp();

    for(int i  = 1 ; i <= N ; i++){
        if(Visited[i] >= Node_color){
            Tmp[i] = 1;
        }
    }

    for(int i = 1; i <= N ; i++){
        if(Tmp[i] == 1){
            printf(" %d",i);
        }
    }

    printf("\n");
}


int main()
{
    auto start = high_resolution_clock::now();
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    scanf("%d", &Test_cases);

    for(Case = 1; Case <= Test_cases; Case++){
        take_input();
        solve();

        print_output();
    }


     auto stop = high_resolution_clock::now();

      auto duration = duration_cast<microseconds>(stop - start);

      cout << "Time taken by function: "
         << (double)duration.count()/1000000.0 << " seconds" << endl;
}
