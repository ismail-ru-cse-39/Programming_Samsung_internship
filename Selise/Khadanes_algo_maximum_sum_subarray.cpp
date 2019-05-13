#include <stdio.h>

#define SZ 1000

int N;
int Arr[SZ];
int Mx = 0;

void take_input()
{
    scanf("%d", &N);

    for(int i =1; i <= N ; i++){
        scanf("%d",&Arr[i]);
    }
}

int max_num(int a, int b)
{
    if(a > b){
        return a;
    }

    return b;
}


void solve()
{
    Mx = Arr[1];
    int mx_local = 0;
    for(int i = 1; i <= N ; i++){
        mx_local = max_num(Arr[i], mx_local+Arr[i]);

        Mx = max_num(mx_local, Mx);
    }
}


int main()
{
    take_input();
    solve();
    printf("%d\n",Mx);

    return 0;
}
