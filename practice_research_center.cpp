#include <stdio.h>

#define SZ 200
int Grid[SZ][SZ];
int Dist[SZ][SZ][7];
int X[7],Y[7];
int N,M,K;
int Test_cases,Case;
int Ans = 0;

void take_input()
{
    scanf("%d %d %d", &N,&M,&K);

    for(int i = 0 ; i< N; i++)
    {
        for(int j = 0; j < M ; j++)
        {
            scanf("%d",&Grid[i][j]);
        }
    }

    for(int i = 0 ; i < K ; i++)
    {
        scanf("%d %d",&X[i],&Y[i]);
    }
}


void print_grid()
{
    for(int i = 0; i < N ; i++){
        for(int j =0 ; j < M; j++){
            printf("%d ",Grid[i][j]);
        }
        printf("\n");
    }


    for(int c = 0;c < K ; c++){
        printf("%d %d\n",X[c],Y[c]);
    }
}

void dfs(int i, int j, int k, int cost)
{
    if(Dist[i][j][k] > cost)
    {
        Dist[i][j][k] = cost;
    }
    else
    {
        return;
    }

    //up

    if(i-1 >= 0 && Grid[i-1][j] == 1 )
    {
        dfs(i-1, j, k, cost+1);
    }

    //down
    if(i+1 < N && Grid[i+1][j] == 1)
    {
        dfs(i+1,j,k,cost+1);
    }

    //left

    if(j-1 >= 0 && Grid[i][j-1] == 1)
    {
        dfs(i,j-1,k,cost+1);
    }

    //right

    if(j+1 < M && Grid[i][j+1] == 1)
    {
        dfs(i,j+1,k,cost+1);
    }
}


void solve()
{
    int i,j,k,x,y;
    int centerdist,cardist;

    Ans = N*M;

    for(int i = 0 ; i< N ; i++)
    {
        for(int j = 0; j < M ; j++)
        {
            for(int c = 0; c< K ; c++)
            {
                Dist[i][j][c] =  N*M;
            }
        }
    }


    for(i = 0 ; i < K ; i++)
    {
        dfs(X[i],Y[i],i,0);
    }

   // marking

    for(i = 0 ; i < K ; i++)
    {
        Grid[X[i]][Y[i]] = 2;
    }



    for(i = 0 ; i < N ; i++)
    {
        for(j = 0; j < M ; j++)
        {
            if(Grid[i][j] == 1)
            {


                for(x = 0; x < N ; x++)
                {
                    for(y = 0 ; y < M ; y++)
                    {
                        if(Grid[x][y])
                        {
                            int mx = 0;

                            for(int c= 0 ; c < K ; c++)
                            {
                                centerdist = Dist[i][j][c];
                                cardist = Dist[x][y][c];

                                if(centerdist < cardist){
                                    if(centerdist > mx){
                                        mx = centerdist;
                                    }
                                }

                                else{
                                    if(cardist > mx){
                                        mx = cardist;
                                    }
                                }
                            }

                            if(mx < Ans){
                                Ans = mx;
                            }
                        }
                    }
                }
            }
        }
    }
}



void print_output()
{
    printf("#%d %d\n",Case,Ans);
}


int main()
{

    freopen("in_research_center.txt", "r", stdin);
    freopen("out_research_center.txt","w",stdout);

    scanf("%d", &Test_cases);

    for(Case = 1; Case <= Test_cases ; Case++)
    {
        take_input();
        solve();
        print_output();

       // print_grid();
    }
}

