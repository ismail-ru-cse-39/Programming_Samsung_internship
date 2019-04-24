//Advance
//pipe
//solved

#include <stdio.h>

#define SZ 1000

int Grid[SZ][SZ];
int M, N, Sx, Sy, L;
int Test_cases, Case;
int Cnt;


void init_grid()
{
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			Grid[i][j] = 0;
		}
	}
}

void print_grid()
{
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			printf("%d ", Grid[i][j]);
		}

		printf("\n");
	}

	printf("\n");
}


void solve(int x, int y, int move){

	//print_grid();
	int tmp = Grid[x][y];

	if (move == L){
		return;
	}

	//Up

	if ((1 == Grid[x][y] || 2 == Grid[x][y] || 4 == Grid[x][y] || 7 == Grid[x][y])){
		if ((x - 1) >= 0){
			if (1 == Grid[x - 1][y] || 2 == Grid[x - 1][y] || 5 == Grid[x - 1][y] || 6 == Grid[x - 1][y]){
				Grid[x][y] = -1;
				Cnt++;
				solve(x - 1, y, move+1);
				Grid[x][y] = tmp;
			}
		}
	}


	//Down

	if (1 == Grid[x][y] || 2 == Grid[x][y] || 5 == Grid[x][y] || 6 == Grid[x][y]){
		if (x + 1 < N){
			if (1 == Grid[x + 1][y] || 2 == Grid[x + 1][y] || 4 == Grid[x + 1][y] || 7 == Grid[x + 1][y]){
				Grid[x][y] = -1;
				Cnt++;
				solve(x + 1, y, move+1);
				Grid[x][y] = tmp;
			}
		}
	}

	//Left

	if (1 == Grid[x][y] || 3 == Grid[x][y] || 7 == Grid[x][y] || 6 == Grid[x][y]){
		if (y - 1 >= 0){
			if (1 == Grid[x][y - 1] || 3 == Grid[x][y - 1] || 4 == Grid[x][y - 1] || 5 == Grid[x][y - 1]){
				Grid[x][y] = -1;
				Cnt++;
				solve(x, y - 1, move+1);
				Grid[x][y] = tmp;
			}
		}
	}


	//Right

	if (1 == Grid[x][y] || 3 == Grid[x][y] || 4 == Grid[x][y] || 5 == Grid[x][y]){
		if (y + 1 < M){
			if (1 == Grid[x][y + 1] || 3 == Grid[x][y + 1] || 6 == Grid[x][y + 1] || 7 == Grid[x][y + 1]){
				Grid[x][y] = -1;
				Cnt++;
				solve(x, y + 1, move+1);
			}
		}
	}

}

void take_input()
{
	scanf("%d %d %d %d %d", &N, &M, &Sx, &Sy, &L);

	init_grid();

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			scanf("%d", &Grid[i][j]);
		}
	}



}


void print_output()
{
	printf("#%d %d\n", Case, Cnt);
}

int main()
{
	freopen("input.txt", "r", stdin);
	//freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	scanf("%d", &Test_cases);

	for (Case = 1; Case <= Test_cases; Case++){
		take_input();

		Cnt = 1;
		solve(Sx, Sy, 0);
		//print_grid();
		print_output();
	}
}
