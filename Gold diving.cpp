#include <stdio.h>

#define sc(a,b) scanf("%d %d",&a,&b)
#define sc1(a) scanf("%d",&a)
#define out(a) printf("%d",a)
#define space() printf(" ")
#define line() printf("\n")
#define SZ 200+10

int T,W;
int N,Depth[SZ],Value[SZ];
int Bin[SZ],Path[SZ],Max =0;
int Flag;

void solve(int i , int cap);
void print();

//void init()
//{
//    for(int i = 0 ; i < SZ ; i++){
//
//    }
//}

void take_input()
{
    while(2 == sc(T,W)){

        sc1(N);

        for(int i = 0 ; i < N ; i++){
            sc(Depth[i],Value[i]);
        }

        Max = -1;
        Flag = 1;
        solve(0,T);
        print();

        getchar();
    }
}

void update()
{
    int i, sum = 0;
    for(i = 0 ; i < N ; i++){
        if(Bin[i]){
            sum+= Value[i];
        }

    }

     if(sum > Max){
            Max = sum;
            for(i  = 0 ; i < N ; i++){
                Path[i] = Bin[i];
            }
        }
}

void solve(int i , int cap){
    if(i == N){
        update();
        return;
    }
    Bin[i] = 0;
    solve(i+1, cap);
    Bin[i] = 1;

    if(cap >= 3*W*Depth[i]){
        solve(i+1, cap - 3*W*Depth[i]);
    }
}

void print()
{
    int i, cnt;

    if(!Flag){
        line();
    }
    else{
        Flag = 0;
    }

    out(Max);
    line();

    cnt = 0;

    for(i = 0 ; i < N ; i++){
        if(Path[i]){
            cnt++;
        }
    }

    out(cnt);
    line();

    for(i = 0; i < N ; i++){
        if(Path[i]){
            out(Depth[i]);
            space();

            out(Value[i]);
            //space();

            line();

        }
    }
    line();
}


int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt" , "w", stdout);

    take_input();


    return 0;
}
