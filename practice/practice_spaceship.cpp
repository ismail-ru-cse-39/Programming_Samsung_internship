#include <stdio.h>
#include <algorithm>
#include <chrono>
#include <iostream>

#define SZ 2000

using namespace std;
using namespace std::chrono;


int Grid[SZ][7];

int N;
int Ans;
int Test_cases,Case;


void take_input()
{
    scanf("%d", &N);



    for(int i = 1 ; i<= N ; i++){
        for(int j = 1; j <= 5 ; j++){
            scanf("%d", &Grid[i][j]);
        }
    }
}


int max_num(int a, int b){
    if(a > b){
        return a;
    }

    return b;

}

int fil(int r,int c,int cnt, int b_r )
{
    if(r == 0){
        return cnt;
    }

    if(Grid[r][c] == 1){
        cnt++;
    }

    if(Grid[r][c] == 2){
        if(b_r == -1){
            b_r = r;
        }

        else if(b_r- r > 4){
            return cnt;
        }
    }


    int ret = fil(r-1,c,cnt,b_r);

    if(c-1 > 0){
        ret = max_num(ret, fil(r-1,c-1,cnt,b_r));
    }

    if(c+1 <= 5){
        ret = max_num(ret, fil(r-1, c+1, cnt, b_r));
    }


    return ret;
}


void solve()
{
    Ans = 0;

    //padding

    for(int i = 1; i <= 5 ; i++){
        Grid[N+1][i] = 0;
    }

    Ans = fil(N+1,3,0,-1);
}


void print_output()

{
    printf("#%d %d\n",Case,Ans);
}


int main()
{

     auto start = high_resolution_clock::now();

    freopen("in_spaceship.txt", "r", stdin);
    //freopen("out_spaceship.txt", "w", stdout);

    scanf("%d", &Test_cases);

    for(Case = 1; Case <= Test_cases ; Case++){
        take_input();
        solve();
        print_output();

    }


     auto stop = high_resolution_clock::now();

      auto duration = duration_cast<microseconds>(stop - start);

      cout << "Time taken by function: "
         << (double)duration.count()/ 1000000.0 << " seconds" << endl;
}
