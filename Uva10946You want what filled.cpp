//Uva 10946
//You want what filled

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
#define SZ 55

int X,Y;
char Grid[SZ][SZ];
int Cnt = 0;
int Mov_x[] = {-1, 0, 0, 1};
int Mov_y[] = {0, -1, 1, 0};

struct node
{
    char x;
    int y;
};

node store[SZ*SZ];

int boundary_check(int x, int y){

    if(x < 0 || y < 0){
        return 0;
    }

    if(x >= X || y >= Y){
        return 0;
    }

    return 1;

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


void fil(int x, int y, char ch)
{
    if(Grid[x][y] == ch){
        Cnt++;
        Grid[x][y] = '.';
    }

    for(int i = 0 ; i < 4; i++){

        int nx = x + Mov_x[i];
        int ny = y + Mov_y[i];

        if(boundary_check(nx, ny) && Grid[nx][ny] == ch){
            fil(nx, ny, ch);
        }
    }


}


void take_input()

{
    int cases = 1;

    while(sc(X,Y) == 2){
        if(X+Y == 0){
            return;
        }

        for(int i = 0 ; i < X ; i++){
            scanf("%s",Grid[i]);
        }

        int l = 0;
        //Cnt = 0

        for(int i = 0 ; i < X ; i++){
            for(int j = 0 ; j < Y ; j++){
                if(Grid[i][j] != '.'){
                    char ch = Grid[i][j];
                    Cnt = 0;
                    fil(i,j, ch);

                    store[l].x = ch;
                    store[l].y = Cnt;
                    l++;
                }
            }
        }

        sort_struct(l);

        printf("Problem %d:\n",cases++);

        for(int i = 0 ; i < l ; i++){
            printf("%c %d\n", store[i].x, store[i].y);
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
