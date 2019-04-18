#include <stdio.h>

#define SIZE 1000

int N, M;
int Path[SIZE][SIZE];
int Visited[SIZE];
int Test_cases;
int Src;

void print_case();
int Found = 0;

void init_graph()
{
	for (int i = 0; i < SIZE; i++){
		for (int j = 0; j < SIZE; j++){
			Path[i][j] = 0;
		}
	}

}

void init_visited()
{
	for (int i = 0; i < SIZE; i++){
		Visited[i] = 0;
	}
}

void take_input()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++){
		int u, v;

		scanf("%d %d", &u, &v);

		Path[u][v] = 1;
		Path[v][u] = 1;
	}
}

int dfs(int u)
{
	Visited[u] = 1;

	if (u == Src){
		return Found = 1;
	}

	for (int v = 1; v <= N; v++){
		if (!Visited[v] && Path[u][v]){
			dfs(v);

			if (Found){
				return 1;
			}

			Visited[v] = 0;


		}



	}

	return 0;
}

void print_case()
{
	for (int i = 1; i <= N; i++){
		if (Visited[i]){
			printf("%d ", i);
		}
	}
	printf("\n");
}


void solve_case()
{
	init_visited();

	for (int i = 1; i <= N; i++){

		for (int j = 1; j <= N; j++){

			Visited[j] = 0;

			if (!Visited[i] && Path[i][j]){
				Src = i;
				Found = 0;
				Path[i][j] = Path[j][i] = 0;

				int res = dfs(j);
				if (res)
				{
					print_case();
					return;
				}

				Path[i][j] = Path[j][i] = 1;

				Visited[Src] = 0;
			}
		}


	}
}



int main()
{
	freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);


	scanf("%d", &Test_cases);

	for (int cases = 1; cases <= Test_cases; cases++){

		printf("#");
		init_graph();
		take_input();
		solve_case();

	}
}
