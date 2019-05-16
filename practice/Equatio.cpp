#include<stdio.h>

long long A,B,C,X;
long long Test_cases,Case;
long long Ans = 0;


void take_input()
{
    scanf("%lld %lld %lld %lld", &A,&B,&C,&X);
}



long long log(long long n)
{
    double d = (double)n;
    long long cnt = 0;

    while(d >= 2.71828){
        d /=2.71828;
        cnt++;
    }

    return cnt;
}


void solve()
{
    Ans = 0;

    long long h,l = 0;

    if(C == 0){
        h = X/A;
    }
    else{
        h = 100000+10;
    }

    while(h > l){
        long long mid = (h+l)/2;

        long long tmp = A *mid + B* log(mid) + C*mid*mid*mid;

        if(tmp == X){
            Ans = mid;

            return;
        }

        else if(tmp > X){
            h = mid;
        }

        else{
            l = mid+1;
        }
    }
}


void print_output()
{

    printf("#%lld %lld\n",Case,Ans);
}


int main()
{
    freopen("in_equation.txt", "r", stdin);
    freopen("out_equation.txt", "w", stdout);

    scanf("%lld",&Test_cases);

    for(Case = 1 ; Case <= Test_cases ; Case++){
        take_input();
        solve();
        print_output();
    }
}
