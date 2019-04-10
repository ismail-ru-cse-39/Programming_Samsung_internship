#include <stdio.h>

#define sc(a,b) scanf("%d %d",&a,&b)
#define sc1(a) scanf("%d",&a)
#define out(a) printf("%d",a)
#define space() printf(" ")
#define line() printf("\n")
#define SZ 26

int N,M;
int Path[SZ][SZ];
int Check[SZ][SZ];

void init()
{
    for(int i = 0 ; i< N ; i++){
        for(int j = 0; j< N ; j++){
            Path[i][j] = Check[i][j] = 0;

        }
    }
}

int solve(int i)
{
    int temp,Mx = 0,j;

    for(j = 0 ; j< N ; j++){
        if(!Check[i][j] && Path[i][j]){
            Check[i][j] = 1;
            Check[j][i] = 1;
            temp = solve(j);
            Check[i][j] = 0;
            Check[j][i] = 0;

            if(temp > Mx){
                Mx = temp;
            }
        }
    }

    return Mx+1;
}

void take_input()
{
    for(int i = 0 ; i < M ; i++){
        int x,y;
        sc(x,y);

        Path[x][y] = 1;
        Path[y][x] = 1;
    }
    int Mx = 0;
    int temp;

    for(int i = 0; i < N ; i++){
        temp = solve(i);

        if(temp > Mx){
            Mx = temp;
        }
    }

    printf("%d\n",Mx-1);
}
int main()
{

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    while(sc(N,M) == 2){
        if((N+M) == 0 ){
            return 0;
        }

        init();
        take_input();
    }
    return 0;
}
