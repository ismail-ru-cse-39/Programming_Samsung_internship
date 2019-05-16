#include <stdio.h>

#define SZ 1000

int Graph[SZ][SZ];
int N,M;
int Flag = 0;
int Color[SZ];


struct qstruct{
    int x;
};

qstruct Q[SZ*SZ];

int frnt, rear;

void init_q()
{
    frnt = rear = 0;
}

void push(int x)
{
    Q[rear].x = x;
    rear++;
}


int  pop()
{
    return Q[frnt++].x;
}


int isEmpty()
{
    if(frnt == rear){
        return 1;
    }

    return 0;
}

void init_graph()
{
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            Graph[i][j] = 0;

        }
    }
}


void init_color()
{
    for(int i =0 ; i < N ; i++){
        Color[i] = -1;
    }
}


void Bfs()
{
    int cur_color;

    init_q();

    for(int i = 0 ; i< N ; i++){
        if(Color[i] == -1){
            push(i);
            Color[i] = 0;
            cur_color = 0;


            while(!isEmpty()){
                int u = pop();
                cur_color = Color[u];

                for(int v = 0 ; v < N ; v++){
                    if(Graph[u][v] == 1 || Graph[v][u] == 1){
                        if(Color[v] == -1){
                            push(v);
                            Color[v] = (1-cur_color);
                        }

                        else if(Color[v] == cur_color){
                            Flag = 1;
                            return;
                        }
                    }
                }
            }
        }
    }
}


void print_output()
{
    if(Flag == 1){
        printf("NOT BICOLORABLE.\n");
    }

    else{
        printf("BICOLORABLE.\n");
    }
}


int main()

{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    while(scanf("%d",&N) == 1){
        if(N == 0){
            return 0;
        }

        scanf("%d", &M);
        init_graph();

        for(int i = 0 ; i < M ; i++){
            int x,y;

            scanf("%d %d", &x,&y);

            Graph[x][y] = 1;
            Graph[y][x] = 1;


        }

        Flag = 0;
        init_color();

        Bfs();

        print_output();
    }


    return 0;
}

