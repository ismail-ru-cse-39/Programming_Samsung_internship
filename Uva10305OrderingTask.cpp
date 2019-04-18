//Uva 10305
//ordering task

#include <stdio.h>

#define SZ 110

int Path[SZ][2 * SZ];
int Visited[SZ];
int N, M;

void input_case()
{
	int u, v;
	for (u = 1; u <= N; u++){
		for (v = 1; v <= N; v++){
			Path[u][v] = 0;
		}
	}

	while (M--){
		scanf("%d %d", &u, &v);
		Path[u][v] = 1;
	}
}

void solve_case()
{
	int i;
	for (i = 1; i <= N; i++){
		Visited[i] = 0;
	}

	for (i = 1; i <= N; i++){
		if (!Visited[i]){
			dfs(i);
		}
	}
}

int main()
{
	while (scanf("%d %d", &N, &M) == 2){
		if (N + M == 0){
			return 0;
		}

		input_case();
		solve_case();
	}
}
