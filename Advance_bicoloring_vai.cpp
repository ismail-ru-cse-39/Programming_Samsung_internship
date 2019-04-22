//Ashrafvai
//Uva10004
//Bicoloring


#include <stdio.h>

#define SIZE 202

int Path[SIZE][SIZE];
int Color[SIZE];
int N,L;
int Ans;

void readCase()
{
	int i,j,x,y;

	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			Path[i][j] = 0;
		}
	}


	while (L--){
		scanf("%d %d", &x, &y);
		Path[x][y] = Path[y][x] = 1;
	}
}

void fil(int x, int curColor)
{
	int y;
	Color[x] = curColor;

	for (y = 0; y < N; y++){
		if (Path[x][y]){
			if (0 == Color[y]){
				fil(y, 3 - curColor);
			}
			else if (curColor == Color[y]){
				Ans = 0;
			}
		}
	}
}

void solveCase()
{
	int i;
	Ans = 1;

	for (i = 0; i < N; i++){
		Color[i] = 0;
	}

	for (i = 0; i < N; i++){
		if (0 == Color[i]){
			fil(i, 1);
		}
	}

}

void printCase()
{
	if (Ans){
		printf("BICOLORABLE.\n");
	}
	else{
		printf("NOT BICOLORABLE.\n");
	}
}

int main()
{
	freopen("in.txt", "r", stdin);

	while (1 == scanf("%d", &N) && N){

		readCase();
		solveCase();
		printCase();
	}
}
