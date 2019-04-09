//Should solve
//uva 216

#include <stdio.h>
#include <math.h>

#define sc(a,b) scanf("%d %d",&a,&b)
#define sc1(a) scanf("%d",&a)
#define out(a) printf("%d",a)
#define space() printf(" ")
#define line() printf("\n")
#define SZ 10

int N;
int Check[SZ];
int Arr_path[SZ];
int MX = 0;
int Bin[SZ];
int Arr[SZ];
double Mn = 9999999;
int track[SZ];

void init();
void print();
void solve(int level, int i, double cost);

struct Cable
{
//    int x;
//    int y;

double x;
double y;
};

struct Cable Co_ordinate_cable[SZ];

struct Cable Path_cable[SZ];

void init()
{
    for (int i = 0; i < SZ; i++)
    {
        Check[i] = 0;
        Bin[i] = 0;
        Arr[i] = 0;
    }
}


void take_input()
{
    //int flag = 0;
    int cases = 1;

    while (sc1(N) == 1)
    {

        if(N == 0){
            return;
        }

        for (int i = 0; i < N; i++)
        {
            double x, y;

            //sc(x, y);
            scanf("%lf %lf",&x,&y);

            Co_ordinate_cable[i].x = x;
            Co_ordinate_cable[i].y = y;
        }
        printf("**********************************************************\n");
        printf("Network #%d\n",cases++);


        Mn = 9999999;
        init();
        solve(0,0,0.0);
       // print();

    }
}

double calculate(int i, int j)
{
    double res;
    double temp;

    temp = Co_ordinate_cable[i].x - Co_ordinate_cable[j].x* Co_ordinate_cable[i].x - Co_ordinate_cable[j].x +
           Co_ordinate_cable[i].y-Co_ordinate_cable[j].y*(Co_ordinate_cable[i].y-Co_ordinate_cable[j].y);

    res = sqrt(temp);

    return Arr_path[i] = res;
}

/*void update()
{
    int i;
    int sum = 0;

    for(i = 0 ; i< N ; i++){
        if(Check[i] == 0){
            sum += Arr_path[i];
        }
    }

    if(sum > Mx){
        Mx = sum;

        for(i = 0 ; i < N ; i++){
            if(Check [i] == 0){
                Bin[i] = 1;
            }
        }
    }
}*/


void solve(int level , int i, double cost)
{
    int j;
    if(level == N)
    {
        //update(i,j);

      /*  if(Mn > cost)
        {
            for(int k = 0; k < N ; k++){
                track[k] = Arr[k];
            }
            Mn = cost;
        }
        return;
        */
        print();
    }

    for(j = 1 ; j < N ; j++)
    {
        Arr[i] = j;
        if(Check[j] == 0)
        {
            Check[j] = 1;
            solve(level+1, j, cost+calculate(i,j));
            Check[j] = 0;
        }
    }
}

void print()
{
    //printf("Cable requirement to connect (%d,%d)",Co_ordinate_cable[0].x, Co_ordinate_cable[0].y);

   /* for(int i = 0 ; i < N-1 ; i++)
    {
        double temp;

        temp = Co_ordinate_cable[track[i]].x - Co_ordinate_cable[track[i+1]].x* Co_ordinate_cable[track[i]].x - Co_ordinate_cable[track[i+1]].x +
               Co_ordinate_cable[track[i]].y-Co_ordinate_cable[track[i+1]].y*(Co_ordinate_cable[track[i]].y-Co_ordinate_cable[track[i+1]].y);

        temp = sqrt(temp);

        printf("Cable requirement to connect (%d,%d) to (%d,%d) is %lf feet.\n",Co_ordinate_cable[i].x, Co_ordinate_cable[i].y, Co_ordinate_cable[i+1].x, Co_ordinate_cable[i+1].y, temp);
    }

    printf("Number of feet of cable required is %lf.\n", Mn+(double)(N-1)*16.0);*/

    for(int i = 0; i < N ; i++){
        out(Arr[i]);
        space();
    }
    line();

     for(int i = 0; i < N ; i++){
        out(track[i]);
        space();
    }


}


int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    take_input();

    return 0;
}
