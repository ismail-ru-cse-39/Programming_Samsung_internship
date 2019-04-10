//Uva 11244
//Marcus

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


int M,N;
int Test_cases;
char Grid[SZ][SZ];

struct node{

    int x;
    int y;

};

node Pos[10];

void direct(node st, node lst ,int flag){
    int ud = st.x - lst.x;
    int lr = st.y - lst.y;

    for(int i = 0 ; i < ud; i++){
        if(i == 0 && flag == 1){
            flag = 0;
            goto spc;
        }

        space();

        spc:;

        printf("forth");
    }

    if(lr > 0){
        for(int i = 0; i < lr ; i++){
            if(i == 0 && flag == 1){
                flag = 1;
                goto spc1;
            }

            space();
            spc1:;

            printf("left");
        }
    }

    if(lr < 0){
        lr  = -1 *lr;

        for(int i = 0; i < lr ; i++){
            if(i == 0 && flag == 1){
                flag =  1;
                goto spc2;

            }

            space();
            spc2:;
            printf("right");
        }
    }

}

void take_input()
{
    sc1(Test_cases);

    for(int cases = 1 ; cases <= Test_cases ; cases++){
        sc(M,N);

        for(int j = 0; j < M ; j++){
            scs(Grid[j]);
        }

        for(int i = 0 ; i < M ; i++){
            for(int j = 0; j < N ; j++){
                if(Grid[i][j] == '@'){
                    Pos[0].x = i;
                    Pos[0].y = j;
                }

                if(Grid[i][j] == 'I'){
                    Pos[1].x = i;
                    Pos[1].y = j;
                }

                if(Grid[i][j] == 'E'){
                    Pos[2].x = i;
                    Pos[2].y = j;
                }

                if(Grid[i][j] == 'H'){
                    Pos[3].x = i;
                    Pos[3].y = j;
                }

                if(Grid[i][j] == 'O'){
                    Pos[4].x = i;
                    Pos[4].y = j;
                }

                if(Grid[i][j] == 'V'){
                    Pos[5].x = i;
                    Pos[5].y = j;
                }

                  if(Grid[i][j] == 'A'){
                    Pos[6].x = i;
                    Pos[6].y = j;
                }

                   if(Grid[i][j] == '#'){
                    Pos[7].x = i;
                    Pos[7].y = j;
                }
            }
        }

        for(int i = 0 ; i < 7 ; i++){
            direct(Pos[i], Pos[i+1], i+1);
        }

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
