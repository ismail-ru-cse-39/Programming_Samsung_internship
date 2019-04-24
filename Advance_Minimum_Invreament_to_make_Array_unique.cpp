#include <stdio.h>

#define SZ 100000

int Arr[SZ];
int Count[SZ];
int Ans = 0;
int Test_cases,Case;
int N;

void init()
{
    for(int i = 0 ; i < SZ ; i++){
        Count[i] = 0;
    }
}

void take_input()
{
    scanf("%d", &N);

    for(int i = 0 ; i < N ; i++){
        scanf("%d",&Arr[i]);
    }
}

void count_arr()
{
    for(int  i= 0 ; i < N ; i++){
        Count[Arr[i]]++;
    }
}


void solve()
{
    init();
    count_arr();

    Ans = 0;
    int taken = 0;

    for(int i = 0; i < SZ ; i++){
      if(Count[i] >= 2){
        taken += Count[i] - 1;
        Ans -= i * (Count[i] - 1);
      }
      else if(taken > 0 && Count[i] == 0){
        taken--;
        Ans += i;
      }
    }
}


void print_output()
{
    printf("#%d %d\n",Case, Ans);
}

int main()
{
    freopen("in.txt", "r", stdin);

    scanf("%d", &Test_cases);

    for(Case = 1 ; Case <= Test_cases ; Case++){
        take_input();
        solve();
        print_output();

    }
}
