#include <stdio.h>
#include <algorithm>
#include <chrono>
#include <iostream>

#define SZ 200

using namespace std;
using namespace std::chrono;


int N;
int Test_cases, Case;
int Ans;
int Visited[SZ];



struct co_ordinate{
    int x,y;

};

co_ordinate Pos[SZ];


void take_input()
{
    scanf("%d", &N);

    int u,v;

    //office

    scanf("%d %d", &u,&v);

    Pos[1].x = u;
    Pos[1].y = v;

    //home


    scanf("%d %d", &u,&v);

    Pos[0].x = u;
    Pos[0].y = v;



    for(int i = 2 ; i <= N+1 ; i++){
        scanf("%d %d", &u,&v);

        Pos[i].x = u;
        Pos[i].y = v;
    }
}



void init_visited()
{
    for(int i = 0; i <= N+1 ; i++){
        Visited[i] = 0;
    }
}


int absdif(int a, int b)
{
   if(a > b){
    return a-b;
   }

   return b-a;
}

void fil(int level, int i, int cost)
{
    if(cost > Ans){
        return;
    }

    if(level == N+1){
        cost += absdif(Pos[i].x, Pos[0].x) + absdif(Pos[0].y,Pos[i].y);

        if(cost < Ans){
            Ans = cost;
        }

        else{
            return;
        }
    }


    for(int j = 2 ; j <= N+1; j++){
        if(Visited[j] == 0){
            Visited[j] = 1;

            fil(level+1, j, cost + absdif(Pos[i].x, Pos[j].x) + absdif(Pos[i].y,Pos[j].y));

            Visited[j] = 0;
        }
    }
}

void solve()
{
    Ans = 9999;

    init_visited();

    fil(1,1,0);
}

void print_output()
{
    printf("#%d %d\n",Case,Ans);
}

int main()
{
     auto start = high_resolution_clock::now();


    freopen("in_kim.txt", "r", stdin);
    freopen("out_kim.txt", "w", stdout);

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
