//Uva10004
//will solve

#include <stdio.h>
#include <math.h>


#define sc1(a) scanf("%d",&a)
#define out(a) printf("%d",a)
#define space() printf(" ")
#define line() printf("\n")

#define SZ 210

int N;
int Graph[SZ][SZ];
int Visited[SZ];

void init_graph()
{
	for (int i = 0; i < SZ; i++){
		for (int j = 0; j < SZ; j++){
			Graph[i][j] = 0;
		}
	}
}

void init()
{
	for (int i = 0; i < SZ; i++){
		Visited[i] = 0;
	}
}

void take_input()
{
	int edges;

	sc1(edges);

	for (int i = 0; i < edges; i++){
		int u, v;
		sc1(u);
		sc1(v);

		Graph[u][v] = 1;
		Graph[v][u] = 1;
	}
}

void dfs(int u){

}


void solve()
{
	dfs(0);
}

int main()
{
	while (sc1(N) == 1){
		if (N == 0){
			return 0;
		}
		init();
		init_graph();
		take_input();

		solve();
	}
}
