#include <stdio.h>
#include <algorithm>
#include <chrono>
#include <iostream>

#define SZ 200

using namespace std;
using namespace std::chrono;


double Graph[SZ][SZ];
int N,M,Time;
double Ans,Mx;
int Node;
int Test_cases, Case;


void init_graph()
{
    for(int i = 1; i <= N ; i++){
        for(int j = 1; j <= N ; j++){
            Graph[i][j] = 0.0;
        }
    }
}

void take_input()
{
    scanf("%d %d %d", &N,&M,&Time);

    init_graph();

    for(int i = 0 ; i < M ; i++){
        int u,v;
        double w;

        scanf("%d %d %lf", &u,&v,&w);
        //printf("%lf\n",w);

        Graph[u][v] = w;
    }
}


void print_graph()
{
    for(int i = 1; i <= N ; i++){
        for(int j = 1;  j<= N ; j++){
            printf("%lf ", Graph[i][j]);
        }
        printf("\n");
    }

}

void solve()
{
    double current[SZ];
    double tmp[SZ];

    Mx = 0.0;

    current[1] = 1.0;

    for(int i = 2 ; i <= N ; i++){
        current[i] = 0.0;
    }


    for(int t = 1 ; t <= Time/10 ; t++){

        for(int i = 1 ; i <= N ; i++){
            tmp[i] = 0.0;
        }



        for(int u = 1; u <= N ; u++)
        {
            for(int v = 1; v <= N ; v++){

                    tmp[v] += current[u] * Graph[u][v];


            }
        }

        for(int u = 1; u <= N ; u++){
            current[u] = tmp[u];

        }
    }


    for(int u = 1; u <= N ; u++){
        if(current[u] - Mx > 0.0){
            Mx = current[u];
            Node = u;

        }
    }
}

void print_output()
{
    printf("#%d %d %lf\n", Case, Node,Mx );
}


int main()
{
    auto start = high_resolution_clock::now();


    //freopen("in_probability.txt", "r", stdin);
    //freopen("out_probability.txt", "w", stdout);

    scanf("%d", &Test_cases);

    for(Case = 1 ; Case <= Test_cases; Case++){
        take_input();
        solve();
        print_output();
        //print_graph();
    }


        auto stop = high_resolution_clock::now();

      auto duration = duration_cast<microseconds>(stop - start);

      cout << "Time taken by function: "
         <<(double) duration.count()/1000000.0 << " seconds" << endl;


}
