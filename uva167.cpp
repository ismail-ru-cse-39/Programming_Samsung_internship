//Sultan's successors
//Uva

#include <stdio.h>
#include <math.h>

#define sc(a,b) scanf("%d %d",&a,&b)
#define sc1(a) scanf("%d",&a)
#define out(a) printf("%d",a)
#define space() printf(" ")
#define line() printf("\n")
#define SZ 65


int K;
int Chess[SZ][SZ];
int Check[SZ][SZ];
int Mx = -1;


void init()
{
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
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

void solve(int col, int sum){

	if (col >= 8){
		if (sum > Mx){
			Mx = sum;
			//debug
			//out(Mx);
			//line();

			return ;
		}

		//return 0;
	}


	for (int i = 0; i < 8; i++){
		if (isSafe(i, col)){
			Check[i][col] = 1;

			solve(col + 1, sum + Chess[i][col]);
				//return 1

			//solve(col + 1, sum + Chess[i][col]);

			Check[i][col] = 0;
		}
	}

}

void take_input()
{
	sc1(K);

	for (int l = 1; l <= K; l++){

		for (int i = 0; i < 8; i++){
			for (int j = 0; j < 8; j++){
				sc1(Chess[i][j]);
			}
		}

		init();
		Mx = -1;

		solve(0, 0);
		printf("%5d", Mx);
			line();



	}
}


int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	take_input();

	return 0;
}
