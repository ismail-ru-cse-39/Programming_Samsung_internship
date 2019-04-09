//Should solve
//uva 216

#include <stdio.h>
#include <math.h>

#define sc(a,b) scanf("%d %d",&a,&b)
#define sc1(a) scanf("%d",&a)
#define scdouble2(a,b) scanf("%lf %lf",&a,&b)
#define out(a) printf("%d",a)
#define outdouble1(a) printf("%lf",a)
#define space() printf(" ")
#define line() printf("\n")
#define SZ 10

int N,Arr[SZ],Path[SZ],Check[SZ];
double Mn = 9999999;

struct cable
{
    double x;
    double y;
};

struct cable co_ordinate[SZ];

void init()
{
    for(int i = 0 ; i < SZ ; i++)
    {
        Arr[i] = 0;
        Path[i] = 0;
        Check[i] = 0;
    }
}


void input_cases()
{
    int i;


    for(i = 0; i < N ; i++)
    {
        double x,y;
        //scdouble2(x,y);

        scanf("%lf %lf",&x,&y);

//        printf("%d ",(int)x);
//        outdouble1(x);
//        space();

        co_ordinate[i].x = x;
        co_ordinate[i].y = y;

//        outdouble1(co_ordinate[i].x);
//        space();
//        outdouble1(co_ordinate[i].y);
//        line();
    }
}

double calculate(int i,int j)
{
    double tmp = (co_ordinate[i].x-co_ordinate[j].x) * (co_ordinate[i].x-co_ordinate[j].x) +
                 (co_ordinate[i].y - co_ordinate[j].y) * (co_ordinate[i].y - co_ordinate[j].y);

   /* out(tmp);
    space();
    outdouble1(co_ordinate[0].x-co_ordinate[1].x);
    line();*/

    return sqrt(tmp);
}

void update()
{
    double sum = 0;
    // int j = 0;

    sum += calculate(0,Arr[0]);

    for(int i = 0; i< N-1 ; i++)
    {
        sum+= calculate(Arr[i],Arr[i+1]);

        /*out(sum);
        space();*/

        //j++;
    }

    line();

    if(sum > Mn)
    {
        Mn = sum;

        for(int i = 0 ; i < N-1 ; i++)
        {
            Path[i] = Arr[i];

//             out(Arr[i]);
//            space();
        }
    }


    /*//debug

    for(int i = 0 ; i < N-1 ; i++){
        out(Arr[i]);
        space();
    }
    line();*/
}

void solve( int i)
{
    int j;

    if(i == N-1)
    {
        update();
        return;
    }

    for(j = 1 ; j < N ; j++)
    {
        Arr[i] = j;

        if(Check[j] != 1)
        {
            Check[j] = 1;
            solve(i+1);
            Check[j] = 0;
        }
    }

}

void print()
{
       printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",(int)co_ordinate[0].x,
               (int)co_ordinate[0].y,(int)co_ordinate[Path[0]].x,(int)co_ordinate[Path[0]].y ,calculate(0,Path[0]));


      for(int i = 0; i< N-1 ; i++)
    {
        printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",(int)co_ordinate[Path[i]].x,
               (int)co_ordinate[Path[i]].y,(int)co_ordinate[Path[i+1]].x,(int)co_ordinate[Path[i+1]].y,
               calculate(Path[i],Path[i+1]));
        //j++;
    }

    printf("Number of feet of cable required is %lf.\n",Mn);
}

void solve_cases()
{
    int i = 1;
    while(sc1(N) == 1)
    {
        if(N == 0)
        {
            return;
        }

        input_cases();
        Mn = 999999;
        solve(0);
        printf("**********************************************************\n");
        printf("Network #%d\n",i++);

        //print();



    }
}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt" , "w", stdout);

    init();
    solve_cases();

    /*double x,y;
        //scdouble2(x,y);
        scanf("%lf %lf",&x,&y);

        printf("%lf\n",x);

    // N = 6;

    //solve(0);*/
}
