//Travelling Salesman
//Practice Algorithm for Advance test

#include <stdio.h>

#define SZ 1000

int Graph[SZ][SZ];
int Visited[SZ];
int N, M;
int Test_cases, Case;
int Ans = 9999999;


void init_graph()
{
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			Graph[i][j] = 0;
		}
	}
}

void init_visited()
{
	for (int i = 0; i <= N; i++){
		Visited[i] = 0;
	}
}

void take_input()
{

	scanf("%d %d", &N, &M);
	init_graph();

	for (int i = 0; i < M; i++){
		int u, v, w;

		scanf("%d %d %d", &u, &v, &w);

		Graph[u][v] = w;
		Graph[v][u] = w;
	}
}


int Min(int a, int b)
{
	if (a > b){
		return b;
	}

	return a;
}

void dfs(int curpos, int cnt, int cost)
{
	if (cnt == N && Graph[curpos][1])
	{
		//printf("%d", Ans);
		Ans = Min(Ans, cost + Graph[curpos][1]);
		//printf(" %d\n", Ans);
		return;
	}


	for (int i = 1; i <= N; i++){
		if (Visited[i] == 0 && Graph[curpos][i]){
			Visited[i] = 1;

			//printf("%d %d %d\n", curpos, i, cost + Graph[curpos][i]);

			dfs(i, cnt + 1, cost + Graph[curpos][i]);

			Visited[i] = 0;
		}
	}
}

void solve()
{
	init_visited();

	Ans = 9999999;

	Visited[1] = 1;

	dfs(1, 1, 0);

}


void print_output()
{
	printf("#%d %d\n", Case, Ans);
}

int main()
{
	freopen("in.txt", "r", stdin);

	scanf("%d", &Test_cases);

	for (Case = 1; Case <= Test_cases; Case++){
		take_input();
		solve();
		print_output();
	}
}
