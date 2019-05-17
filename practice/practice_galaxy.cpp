#include <stdio.h>

#define SZ 200

int X[SZ], Y[SZ];
int U[SZ], V[SZ];
int Cost[SZ],Visited[SZ];
int N, M, W, Ans;
int Test_cases, Case;


void init_visited()
{
    for(int i = 1; i <= W; i++)
    {
        Visited[i] = 0;
    }
}

void take_input()
{
    scanf("%d %d %d", &N, &M, &W);

    for(int i = 1; i <= M ; i++)
    {
        scanf("%d %d", &X[i], &Y[i]);
    }

    for(int i = 1 ; i <= W; i++)
    {
        scanf("%d %d %d",&U[i],&V[i], &Cost[i]);
    }
}


int absdif(int a, int b)
{
    if(a > b){
        return a-b;
    }

    return b - a;
}

void fil(int level, int r, int c, int cost)
{
    if(N-r+N-c+cost < Ans)
    {
        Ans = N-r+N-c+cost;
    }

    if(level == W)
    {
        return;
    }

    for(int i = 1; i <= W;  i++)
    {
        if(Visited[i] == 0)
        {
            Visited[i] = 1;

            int distu;
            int distv;

            distu = absdif(r, X[U[i]]) + absdif(c,Y[U[i]]);
            distv = absdif(r, X[V[i]]) + absdif(c, Y[V[i]]);

            if(distu < distv)
            {
                fil(level+1, X[V[i]], Y[V[i]], cost+distu+Cost[i]);
            }
            else
            {
                fil(level + 1 , X[U[i]], Y[U[i]], cost+distv+Cost[i]);
            }

            Visited[i] = 0;
        }
    }
}


void solve()
{
    init_visited();
    Ans = (N-1)*2;

    fil(0,1,1,0);
}

void print_output()
{
    printf("#%d %d\n",Case, Ans);
}

int main()
{
    freopen("in_warmhole.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    scanf("%d", &Test_cases);

    for(Case = 1; Case <= Test_cases; Case++)
    {
        take_input();
        solve();
        print_output();
    }
}
