//Uva10336
//Rank the language


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

int H,W;
char Grid[SZ][SZ];
char Arr[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int k;

struct node
{
    char x;
    int y;
};

node store[26];
void init()
{
    for(int i = 0; i < 26 ; i++)
    {
        store[i].x ='0';
        store[i].y = 0;
    }
}

int boundary_check(int x, int y)
{
    if (x < 0 || y < 0)
    {
        return 0;
    }
    if (x >= H || y >= W)
    {
        return 0;
    }

    return 1;
}

void fil(int x, int y )
{


    Grid[x][y] = '*';

    if (boundary_check(x - 1, y) && Arr[k] == Grid[x - 1][y])
    {
        fil(x - 1, y);
    }


    if (boundary_check(x, y - 1) && Arr[k] == Grid[x][y - 1])
    {
        fil(x, y - 1);
    }

    if (boundary_check(x, y + 1) && Arr[k] == Grid[x][y + 1])
    {
        fil(x, y + 1);
    }


    if (boundary_check(x + 1, y) && Arr[k] == Grid[x + 1][y])
    {
        fil(x + 1, y);
    }



}

void sort_struct(int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = i+1 ; j < n ; j++)
        {
            if(store[i].y < store[j].y)
            {
                int tmpi;
                char tmpch;

                tmpi = store[j].y;
                tmpch = store[j].x;

                store[j].x = store[i].x;
                store[j].y = store[i].y;

                store[i].x = tmpch;
                store[i].y = tmpi;
            }

            if(store[i].y == store[j].y)
            {
                if(store[i].x > store[j].x)
                {
                    int tmpi;
                    char tmpch;

                    tmpi = store[j].y;
                    tmpch = store[j].x;

                    store[j].x = store[i].x;
                    store[j].y = store[i].y;

                    store[i].x = tmpch;
                    store[i].y = tmpi;

                }
            }
        }
    }
}


void take_input()
{
    int Test_cases;

    sc1(Test_cases);

    for(int cases = 1 ; cases <= Test_cases ; cases++)
    {

        sc(H,W);

        init();

        for(int i = 0 ; i < H ; i++)
        {
            scs(Grid[i]);
        }

        int l = 0;
        char ch;

        for(  k = 0 ; k < 26 ; k++)
        {

            int cnt = 0;
            //ch = Arr[k];
            int flag = 0;

            for(int i = 0 ; i < H ; i++)
            {
                for(int j = 0 ; j < W ; j++)
                {
                    if(Grid[i][j] == Arr[k])
                    {
                        // store[l].x = Arr[k];
                        ch = Arr[k];
                        flag = 1;
                        cnt++;
                        fil(i,j);
                    }
                }
            }

            if(flag == 1)
            {

                store[l].x = ch;
                store[l].y = cnt;
                l++;
            }
        }

        sort_struct(l);

        printf("World #%d\n",cases);

        for(int i = 0 ; i < l ; i++)
        {
            printf("%c: %d\n",store[i].x,store[i].y);
        }


    }
}


int main()
{

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    take_input();


    return 0;
}

