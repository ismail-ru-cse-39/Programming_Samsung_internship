
//Advance
//Spaceship
//solved

#include <stdio.h>

#define SZ 1000

int Grid[SZ][SZ];
int N, M;
int Test_cases, Case;
int Mx = -1;

void init_grid()
{
	for (int i = 0; i < N; i++){
		for (int j = 0; j < 5; j++){
			Grid[i][j] = 0;
		}
	}
}


void take_input()
{
	scanf("%d", &N);
	init_grid();

	for (int i = 0; i < N; i++){
		for (int j = 0; j < 5; j++){
			scanf("%d", &Grid[i][j]);
		}
	}

	for (int i = 0; i < 5; i++)
		Grid[N][i] = 0;

}

int Max(int a, int b){
	if (a > b){
		return a;
	}

	else{
		return b;
	}
}

void ship(int row, int curpos, int cnt)
{
	row--;

	if (row < 0){
		Mx = Max(Mx, cnt);
		return;
	}

	for (int v = -1; v < 2; v++){
		if ((curpos + v) < 5 && (curpos+v) >= 0 && Grid[row][curpos+v] != 2){
			printf("-----> %d %d %d %d\n\n", row, curpos + v,cnt, cnt+Grid[row][curpos+v]);
			ship(row, curpos+v, cnt + Grid[row][curpos+v]);
		}
	}

	Mx = Max(Mx, cnt);



}


void go(int row, int col, int life, int score)
{
	if (row < 0){
		if (score > Mx){
			Mx = score;
		}
		return;
	}

	if (life > 0 && life < 6){
		life--;
	}

	if (1 == Grid[row][col]){
		score++;
	}

	else if (2 == Grid[row][col]){
		if (0 == life){
			if (score > Mx){
				Mx = score;
			}
			return;
		}
		else if (6 == life){
			life--;
		}
	}

	if (col - 1 >= 0){
		go(row - 1, col - 1, life, score);
	}

	go(row - 1, col, life, score);

	if (col + 1 < 5){
		go(row - 1, col + 1, life, score);
	}

	Mx = Max(Mx, score);
}

void solve()
{
	Mx = -1;

	//ship(N, 2, 0);

	go(N, 2, 6, 0);
}

void print_output()
{
	printf("#%d %d\n", Case, Mx);
}

int main()
{
	freopen("input.txt", "r", stdin);
	//freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	scanf("%d", &Test_cases);

	for (Case = 1; Case <= Test_cases; Case++){
		take_input();
		solve();
		print_output();

	}
}
