//Uva 11470
//Squares sum

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
#define SZ 12

int Grid[SZ][SZ];
int N;


int row_total(int i){

    int sum = 0;

    for(int j = 0 ; j < N ; j++){
        sum += Grid[i][j];
        Grid[i][j] = 0;
    }

    return sum;
}

int col_total(int j){
    int sum = 0;

    for(int i = 0 ; i < N ; i++){
        sum += Grid[i][j];
        Grid[i][j] = 0;
    }

    return sum;
}

void take_input()

{
    int cases = 1;

    while(sc1(N) == 1){
        if(N == 0){
            return;
        }

        for(int i = 0 ; i < N ; i++){
            for(int j = 0; j < N ; j++){
                sc1(Grid[i][j]);
            }
        }
        int row;

        if(N%2 == 0){
            row = (N-1)/2;
        }
        else{
            row = N/2;
        }

        int sum = 0;

        printf("Case %d: ",cases);

        cases++;

        for(int i = 0 ; i <= row ; i++){
            sum = 0;

            sum += row_total(i);
            sum += row_total(N-i-1);

            sum += col_total(i);
            sum += col_total(N-i-1);

            out(sum);
            if(i != row)
            space();
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
