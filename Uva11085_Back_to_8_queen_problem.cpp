#include <stdio.h>

#define sc(a,b) scanf("%d %d",&a,&b)
#define sc1(a) scanf("%d",&a)
#define out(a) printf("%d",a)
#define space() printf(" ")
#define line() printf("\n")
#define SZ 200+10

int Chess[SZ];
int Check[SZ][SZ];
int Mn = 9999999;

void init()
{
    for(int i = 0 ; i < 8; i++){
        for(int j = 0 ; j< 8 ; j++){
            Check[i][j] = 0;
        }
    }
}

int isSafe(int row, int col){
	int i, j;


	for (i = 0; i < col; i++){
		if (Check[row][i]){
			return 0;
		}
	}

	for (i = row, j = col; i >= 0 && j >= 0; i--, j--){
		if (Check[i][j]){
			return 0;
		}
	}

	for (i = row, j = col; j >= 0 && i < 8; i++, j--){
		if (Check[i][j]){
			return 0;
		}
	}

	return 1;
}

void solve(int col, int cnt)
{
    if(col == 8){
        if(cnt <= Mn){
            Mn = cnt;

        }
//        out(cnt);
//        space();
//        out(Mn);
//        line();

         return;
    }

    for(int i = 0 ; i < 8 ; i++){
        if(isSafe(i,col)){
                Check[i][col] = 1 ;
                int a = 0 ;
                if(i != Chess[col]) a = 1 ;

                 solve(col+1 , cnt + a ) ;

                Check[i][col] = 0;

        }
    }
}

void take_input()
{
    int x1,x2,x3,x4,x5,x6,x7,x8;
    int i = 0;

    while(scanf("%d %d %d %d %d %d %d %d", &x1,&x2,&x3,&x4,&x5, &x6, &x7,&x8) == 8){

        i++;

        Chess[0] = x1-1;
        Chess[1] = x2-1;
        Chess[2] = x3-1;
        Chess[3] = x4-1;
        Chess[4] = x5-1;
        Chess[5] = x6-1;
        Chess[6] = x7-1;
        Chess[7] = x8-1;

        init();
        Mn = 9999999;

        solve(0,0);

        printf("Case %d: %d\n",i,Mn);


    }
}


int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    take_input();

    return 0;
}

