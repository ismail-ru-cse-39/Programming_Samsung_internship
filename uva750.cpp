#include <stdio.h>

#define sc(a,b) scanf("%d %d",&a,&b)
#define sc1(a) scanf("%d",&a)
#define out(a) printf("%d",a)
#define space() printf(" ")
#define line() printf("\n")
#define SZ 200+10

int N, X,Y,Test_cases;
int Check[SZ][SZ];
int Cnt = 0;

void init()
{
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){

				Check[i][j] = 0;
		}
	}
}


void print()
{
	int i, j;
	printf("%2d      ", Cnt);
	for (i = 0; i < 8; i++){
		for (j = 0; j < 8; j++){
			if (Check[j][i] == 1){
				out(j + 1);
			}
		}
		if(i!=7)space();
	}
}


int isSafe(int row, int col){
	int i, j;

	if (col == Y - 1){
		if (row != X - 1){
			return 0;
		}
	}

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

void solve(int col){

	if (col == 8){

		Cnt++;
		print();
		//out(2);
		//init();
		line();
		return;

		//return 0;
	}


	for (int i = 0; i < 8; i++){
		if (isSafe(i, col)){
			Check[i][col] = 1;

			solve(col + 1);
			//return 1

			//solve(col + 1, sum + Chess[i][col]);

			Check[i][col] = 0;
		}
	}

}

void take_input()
{
	sc1(Test_cases);

	for (int i = 1; i <= Test_cases; i++){
		sc(X, Y);

		init();

		if (i != 1) printf("\n");
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");

		Cnt = 0;
		solve(0);
	}



}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	take_input();

	return 0;
}
