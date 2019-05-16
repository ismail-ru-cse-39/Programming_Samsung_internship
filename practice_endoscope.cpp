#include <stdio.h>

#define SZ 2000

int Grid[SZ][SZ];
int Visited[SZ][SZ];
int N,M,R,C,L;
int Ans;
int Test_cases,Case;

struct q_struct{
int x,y,l;
};

q_struct Q[SZ*SZ];

int frnt,rear;

void init_q()
{
    frnt = rear = 0;
}

void push(int x, int y, int l)
{
    Q[rear].x = x;
    Q[rear].y = y;
    Q[rear].l = l;

    rear++;
}


q_struct pop()
{
    return Q[frnt++];
}

int isEmpty()
{
    if(rear == frnt){
        return 1;
    }
    return 0;
}

void take_input()
{
    scanf("%d %d %d %d %d", &N,&M,&R,&C,&L);

    for(int i = 0; i < N ; i++){
        for(int j = 0; j < M ; j++){
            scanf("%d", &Grid[i][j]);

            if(Grid[i][j]){
                Visited[i][j] = 0;
            }

            else{
                Visited[i][j] = 1;
            }
        }
    }
}

int is_up(int n)
{
    if(n == 1 || n == 2 || n == 4 || n == 7){
        return 1;
    }

    return 0;
}

int is_down(int n)
{
    if(n == 1 || n== 2 || n == 5 || n ==  6)
    {
        return 1;
    }


    return 0;
}

int is_left(int n)
{
    if(n == 1 || n == 3 || n == 6 || n == 7){
        return 1;
    }

    return 0;
}

int is_right(int n)
{
    if(n == 1 || n == 3 || n == 4 || n == 5){
        return 1;
    }

    return 0;
}

void solve()
{
   init_q();

    Ans = 0;

    if(Grid[R][C]!=0){
        //printf("_______>>");
        Visited[R][C] = 1;
        push(R,C,1);
        Ans++;
    }
    //printf("----> %d %d\n",frnt,rear);

 //printf("_______>>");
    while(!isEmpty())
    {
        // printf("_______>>");
        q_struct q;

        q = pop();

        int x,y,l;

        x = q.x;
        y = q.y;
        l = q.l;
        int n = Grid[x][y];


        if(l < L){
            //up


            if((x-1) >= 0 && Visited[x-1][y] == 0 && is_up(n)){
                if(is_down(Grid[x-1][y])){
                    Ans++;
                    Visited[x-1][y] = 1;
                    push(x-1,y,l+1);
                }
            }


            //down
            if((x+1) < N  && Visited[x+1][y] == 0 && is_down(n) == 1){
                if(is_up(Grid[x+1][y]) == 1){
                    Ans++;
                    Visited[x+1][y] = 1;
                    push(x+1,y,l+1);
                }
            }

            //left
            if((y-1) >= 0 && Visited[x][y-1] == 0 && is_left(n) == 1){
                if(is_right(Grid[x][y-1]) == 1){
                    Ans++;
                    Visited[x][y-1] = 1;
                    push(x,y-1,l+1);
                }
            }


            //right

            if((y+1) < M && Visited[x][y+1] == 0 && is_right(n) == 1){
                if(is_left(Grid[x][y+1]) == 1){
                    Ans++;
                    Visited[x][y+1] = 1;
                    push(x,y+1,l+1);
                }
            }
        }
    }
}


void print_output()
{
    printf("%d\n",Ans);
}

int main()
{
    freopen("in_endoscope.txt", "r", stdin);

    scanf("%d",&Test_cases);

    for(Case = 1; Case <= Test_cases; Case++){
        take_input();
        solve();
        print_output();
    }
}

