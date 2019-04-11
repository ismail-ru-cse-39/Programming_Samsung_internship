//Uva 260
//Il Gioco dell'X
#include <stdio.h>
#include <string.h>

#define sc(a,b) scanf("%d %d",&a,&b)
#define scchar2(a,b) scanf("%c %c",&a,&b)
#define scchar(a) scanf("%c",&a)
#define sc1(a) scanf("%d",&a)
#define scs(a) scanf("%s",&a)
#define out(a) printf("%d",a)
#define space() printf(" ")
#define line() printf("\n")
#define SZ 210

int N;
char Grid[SZ][SZ];
int Check[SZ][SZ];
int Mov_x[] = {-1, -1, 0, 0, 1, 1};
int Mov_y[] = {-1, 0, -1, 1, 0, 1};

void init()
{
    for(int i = 0; i < N ; i++)
    {
        for(int j = 0 ; j < N ; j++)
        {
            Check[i][j] = 0;
        }
    }
}

int boundary_check(int x, int y)
{
    if(x < 0 || y < 0)
    {
        return 0;
    }

    if(x >= N  || y >= N)
    {
        return 0;
    }

    return 1;

}

void fil(int x, int y, char ch)
{

    Check[x][y] = 1;

    for(int i = 0 ; i < 6 ; i++)
    {

        int nx = x + Mov_x[i];
        int ny = y + Mov_y[i];

        if(boundary_check(nx, ny) && Check[nx][ny] == 0 && Grid[nx][ny] == ch)
        {
            fil(nx, ny, ch);
        }
    }

}

void print_grid()
{
    for(int i = 0 ; i< N ; i++)
    {
        for(int j = 0 ; j < N ; j++)
        {
            printf("%c", Grid[i][j]);
        }

        line();
    }
}

void take_input()

{
    int cases = 1;
    while(sc1(N) == 1)
    {
        if(N == 0)
        {
            return;
        }

        for(int i = 0 ;  i< N ; i++)
        {
            scanf("%s",Grid[i]);
        }

        init();

        //print_grid();

        for(int j = 0; j < N ; j++)
        {
            if(Grid[0][j] == 'b')
            {
                char ch = Grid[0][j];
                fil(0,j, ch);
            }
        }
        int flag = 0;
        for(int j = 0 ; j < N ; j++)
        {
            if(Check[N-1][j] == 1)
            {
                flag = 1;
            }
        }

        if(flag == 1)
        {
            printf("%d B\n",cases);
            //continue;
        }

        else{
            printf("%d W\n",cases);
        }

       /* if(flag == 0)
        {
            init();

            for(int j = 0; j < N ; j++)
            {
                if(Grid[j][0] == 'w')
                {
                    char ch = Grid[j][0];
                    fil(j,0, ch);
                }
            }

            for(int j = 0 ; j < N ; j++)
            {
                if(Check[N-1][j] == 1)
                {
                    flag = 1;
                }
            }

            if(flag == 1)
            {
                printf("%d W\n",cases);
                //continue;
            }
        }*/


        cases++;
    }
}


int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    take_input();

    return 0;
}
