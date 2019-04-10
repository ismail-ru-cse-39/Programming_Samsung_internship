//Uva 11953
//Battleship

#include <stdio.h>
#include <string.h>

#define sc(a,b) scanf("%d %d",&a,&b)
#define scchar2(a,b) scanf("%c %c",&a,&b)
#define scchar(a) scanf("%c",&a)
#define scs(s) scanf("%s",&s)
#define sc1(a) scanf("%d",&a)
#define out(a) printf("%d",a)
#define space() printf(" ")
#define line() printf("\n")
#define SZ 102

int R,C;
char Grid[SZ][SZ];

int boundary_check(int x, int y)
{
    if (x < 0 || y < 0)
    {
        return 0;
    }
    if (x >= R || y >= C)
    {
        return 0;
    }

    return 1;
}

void take_input()
{
    while(sc(R,C) == 2)
    {
        if((R+C)== 0)
        {
            return;
        }

        for(int i = 0; i < R ; i++)
        {
            scs(Grid[i]);
        }

        int ans = 0;

        for(int x = 0; x < R ; x++)
        {
            for(int y = 0 ; y< C ; y++)

            {
                int a = 1;
                if(Grid[x][y] == '*')
                {
                    if (boundary_check(x-1, y-1))
                    {
                        if ('*' == Grid[x - 1][y - 1])
                        {
                            a = 0;
                        }
                    }

                    if (boundary_check(x - 1, y) && '*' == Grid[x - 1][y])
                    {
                        a = 0;
                    }

                    if (boundary_check(x - 1, y + 1) && '*' == Grid[x - 1][y + 1])
                    {
                        a = 0;
                    }

                    if (boundary_check(x, y - 1) && '*' == Grid[x][y - 1])
                    {
                       a = 0;
                    }

                    if (boundary_check(x, y + 1) && '*' == Grid[x][y + 1])
                    {
                       a = 0;
                    }

                    if (boundary_check(x + 1, y - 1) && '*' == Grid[x + 1][y - 1])
                    {
                        a = 0;
                    }

                    if (boundary_check(x + 1, y) && '*' == Grid[x + 1][y])
                    {
                        a = 0;
                    }

                    if (boundary_check(x + 1, y + 1) && '*' == Grid[x + 1][y + 1])
                    {
                        a = 0;
                    }

                    ans += a;

                }

            }
        }

        out(ans);
        line();
    }


}


int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    take_input();

    return 0;
}
