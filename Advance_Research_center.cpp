//Advance
//Research Center
//Solved
//Vai

#include <stdio.h>

#define SZ 21

int Dist[SZ][SZ][5];
int Grid[SZ][SZ];
int N, M,C;
int X[5], Y[5];
int Ans;
int Test_cases, Case;


void take_input()
{
	int i, j;

	scanf("%d %d %d", &N, &M, &C);

	for (i = 0; i < N; i++){
		for (j = 0; j < M; j++){
			scanf("%d", &Grid[i][j]);
		}
	}

	for (i = 0; i < C; i++){
		scanf("%d %d", &X[i], &Y[i]);
	}

}

void dfs(int i, int j, int k, int cost)
{
	if (Dist[i][j][k] > cost){
		Dist[i][j][k] = cost;
	}

	else{
		return;
	}

	//up
	if (i - 1 >= 0 && Grid[i-1][j] == 1){
		dfs(i - 1, j, k, cost + 1);
	}


	//left

	if (j - 1 >= 0 && Grid[i][j - 1] == 1){
		dfs(i, j - 1, k, cost + 1);
	}

	//right

	if (j + 1 < M && Grid[i][j + 1] == 1){
		dfs(i, j + 1, k, cost + 1);
	}

	//down

	if (i + 1 < N && Grid[i + 1][j] == 1){
		dfs(i + 1, j, k, cost+1);
	}
}

void solve_case()
{
	int i, j, k,mx=-1;
	int x, y,centerdist,cardist;

	Ans = N*M;

	for (i = 0; i < N; i++){
		for (j = 0; j < M; j++){
			for (k = 0; k < C; k++){
				Dist[i][j][k] = N*M;
			}
		}
	}


	for (k = 0; k < C; k++){
		dfs(X[k], Y[k], k, 0);
	}

	//Marking rarepoint
	for (k = 0; k < C; k++){
		Grid[X[k]][Y[k]] = 2;
	}


	for (i = 0; i < N; i++){
		for (j = 0; j < M; j++){
			if (Grid[i][j] == 1){
				for (x = 0; x < N; x++){
					for (y = 0; y < M; y++){
						if (Grid[x][y]){
							mx = 0;

							for (k = 0; k < C; k++){
								centerdist = (Dist[i][j][k]);
								cardist = Dist[x][y][k];

								if (centerdist < cardist){
									if (centerdist > mx){
										mx = centerdist;
									}
								}
								else{
									if (cardist > mx){
										mx = cardist;
									}
								}
							}

							if (mx < Ans){
								Ans = mx;
							}

						}
					}
				}
			}
		}
	}
}


void print_output()
{
	printf("#%d %d\n", Case, Ans);
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	scanf("%d", &Test_cases);

	for (Case = 1; Case <= Test_cases; Case++){
		take_input();
		solve_case();
		print_output();
	}
}
