#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sstream>
using namespace std;

#define SZ 301

int Grid[SZ][SZ];
int N;
int Arr_cnt[SZ];
int Cnt;
int Curr_num;
int Mov_x[] = {+1 , 0,-1 , 0} ;
int Mov_y[] = { 0 ,+1,0 , -1} ;

void print_grid()
{
    printf("Grid...............\n");
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j<= N ; j++){
            printf("%d ",Grid[i][j]);
        }
        printf("\n");
    }
}

void init()
{
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= N ; j++){
            Grid[i][j] = N;
        }
    }
}

int check_count()
{
    for(int i =1 ; i <= N ; i++){
        Arr_cnt[i] = 0;
    }

    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j<= N; j++){
            Arr_cnt[Grid[i][j]]++;
        }
    }

//    printf("...........Cnt\n");
//    for(int i = 1 ;  i <= N ; i++){
//        printf("%d ",Arr_cnt[i]);
//    }
//    printf("\n");

    for(int i = 1 ; i <= N ; i++){
        if(Arr_cnt[i] !=  N){
           //printf("..wrong\n");
            return 1;
        }
    }

    return 0;
}
int boundary_check(int x, int y){

    if(x <1 || y < 1){
        return 0;
    }
    if(x > N && y > N){
        return 0;
    }

    return 1;

}

void fil(int x, int y){
    if(Grid[x][y] != Curr_num)
        return;

    Grid[x][y] = -1;


    for(int i = 0 ; i < 4 ; i++){
        int nx = x + Mov_x[i];
        int ny = y + Mov_y[i];

        if(boundary_check(nx, ny)){
            fil(nx, ny);
        }
    }


}

void solve()
{


    if(check_count()){
        printf("wrong\n");
        return;
    }
    Cnt = 0;

    for(int i = 1 ; i<= N ; i++){
        for(int j = 1 ; j<= N ; j++){
            if(Grid[i][j] != -1){
                Cnt++;
                Curr_num = Grid[i][j];
                fil(i,j);
            }
        }
    }

    if(Cnt == N){
        printf("good\n");
    }

    else{
        printf("wrong\n");
    }
}


int main()
{

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    while(scanf("%d" , &N) == 1){
        if(N == 0 ) break ;
        getchar() ;

        init() ;

        for(int i  = 1 ; i <= N-1 ; i++){
            char str[1000] ;
            gets(str) ;

            int a, b ;
            stringstream ss(str) ;

            while(ss>>a>>b){
                Grid[a][b] = i ;
            }
        }

        //print_grid();

        solve() ;

    }

    return 0;
}
