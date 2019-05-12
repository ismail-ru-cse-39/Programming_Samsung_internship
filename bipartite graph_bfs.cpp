#include <stdio.h>
#include <algorithm>
#include <chrono>
#include <iostream>
#define SZ 200+10
using namespace std;
using namespace std::chrono;

int Graph[SZ][SZ];
int Colored[SZ];
int M,N;
int Flag = 0;
int left1, right1;

struct q_struct{
    int x;
};

q_struct Q[SZ*SZ];



void init_q()
{
    left1 = right1 = 0;
}

void push(int u)
{
    Q[right1].x = u;
    right1++;
}

int pop()
{
    return Q[left1++].x;
}

int isempty()
{
    if(left1 == right1){
        return 1;
    }
    else{
        return 0;
    }
}

void init_graph()
{
    for(int i = 0; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            Graph[i][j] = 0;
        }
    }
}

void take_input()
{
    scanf("%d", &M);

    init_graph();
    int u,v;

    for(int i = 1 ; i <= M ; i++){
        scanf("%d %d", &u,&v);
        Graph[u][v] = 1;
        Graph[v][u] = 1;
    }
}


void init_colored()
{
    for(int i =0; i < N; i++){
        Colored[i] = -1;
    }
}


void solve()
{
    Flag = 0;

    init_colored();
    init_q();

    for(int i = 0; i < N ; i++){
        if(Colored[i] == -1){
            Colored[i] = 1;

            push(i);

            while(!isempty()){
                int u = pop();

                for(int v = 0; v < N ; v++){
                    if(Graph[u][v] == 1 || Graph[v][u] == 1 ){
                        if(Colored[v] == -1){
                            Colored[v] = 1- Colored[u];
                            push(v);
                        }

                        else if(Colored[v] == Colored[u]){
                            Flag = 1;
                            return;
                        }
                    }
                }
            }
        }
    }
}



void print_output()
{
    if(Flag == 1){
        printf("NOT BICOLORABLE.\n");
    }

    else{
        printf("BICOLORABLE.\n");
    }
}


int main()
{

    auto start = high_resolution_clock::now();

    freopen("in.txt", "r", stdin);
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
