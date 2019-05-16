#include <stdio.h>

#define SZ 200
int X[SZ],Y[SZ];
int U[SZ],V[SZ];
int Cost[SZ];
int Visited[SZ];
int N,M,W;
int Ans;
int Test_cases, Case;

void take_input()
{
    scanf("%d %d %d", &N,&M,&W);

    for(int i = 1 ;  i <= M ;i++){
        scanf("%d %d", &X[i],&Y[i]);
    }

    for(int i =1 ; i <= W ; i++){
        scanf("%d %d %d", &U[i], &V[i], &Cost[i]);
    }
}


void init_visited()
{
    for(int i = 1; i <= W; i++){
        Visited[i] = 0;
    }
}

int absdif(int a, int b){

    if(a > b){
        return a-b;
    }

    return b-a;
}

void fil(int level, int r, int c,int cost)
{
    if(N-r+N-c+cost < Ans){
        Ans = N-r+N-c+cost;
    }



    if(level == W+1){
        return;
    }


    for(int i = 1; i <= W; i++){
        if(Visited[i] == 0){

            Visited[i] = 1;

            int distu = absdif(r, X[U[i]]) + absdif(c, Y[U[i]]);
            int distv = absdif(r,X[V[i]]) + absdif(c, Y[V[i]]);

            if(distu < distv){
                fil(level+1, X[V[i]], Y[V[i]], cost+distu+Cost[i]);
            }
            else{
                fil(level+1, X[U[i]], Y[U[i]], cost+distv+Cost[i]);
            }

             Visited[i] = 0;
        }


    }
}

void solve()
{
    Ans = (N-1)*2;

    init_visited();

    fil(1,1,1,0);
}


void print_output()
{
    printf("#%d %d\n",Case, Ans);
}

int main()
{
    freopen("in_warmhole.txt", "r", stdin);
    freopen("out_warmhole.txt", "w", stdout);

    scanf("%d", &Test_cases);

    for(Case = 1; Case <= Test_cases; Case++){
        take_input();
        solve();
        print_output();
    }
}
