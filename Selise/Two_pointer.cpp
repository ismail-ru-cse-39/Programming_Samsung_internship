#include <stdio.h>

#define SZ 1000

int Arr_sorted[SZ];
int N;
int X;
int L,R;

void take_input()
{
    scanf("%d", &N);

    for(int i =0 ; i < N ; i++){
        scanf("%d", &Arr_sorted[i]);
    }

    scanf("%d",&X);
}


int is_equal()
{
    int i = 0;
    int j = N-1;

    while( i < j){

        int tmp = (Arr_sorted[i] + Arr_sorted[j]) ;

        if(tmp == X){
            L = i;
            R = j;
            return 1;
        }

        else if(tmp < X){
            i++;
        }
        else{
            j--;
        }
    }


    return 0;
}

int main()
{
    take_input();
    int res = is_equal();

    if(res == 1){
        printf("Found %d %d\n",L+1,R+1);
    }

    else{
        printf("Not Found.\n");
    }


    return 0;
}
