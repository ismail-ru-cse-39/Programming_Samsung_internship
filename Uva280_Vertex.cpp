//Uva280
//Vertex
//Solved


#include <stdio.h>
#include <math.h>

#define SZ 110
#define space() printf(" ");
#define line() printf("\n");

int Graph[SZ][SZ];
int Node;
int Visited[SZ];
int N;


void print_graph()
{
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			printf("%d ", Graph[i][j]);
		}

		printf("\n");
	}
}

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
	int strt;

	while (scanf("%d", &strt) == 1){
		if (strt == 0){
			break;
		}

		int des;

		while (scanf("%d", &des) == 1){
			if (des == 0){
				break;
			}
			else{
				Graph[strt][des] = 1;
			}
		}
	}
}

void print_output()
{
	int cnt = 0;

	for (int i = 1; i <= N; i++){
		if (Visited[i] == 0){
			cnt++;
		}
	}

	printf("%d", cnt);
	if (cnt == 0){

	}
	else{
		space();
	}
	int j = 0;
	for (int i = 1; i <= N; i++){
		if (Visited[i] == 0){
			j++;
			printf("%d", i);
			if (j < cnt){
				space();
			}
		}
	}
	line();
}

void dfs(int u){


	for (int v = 1; v <= N; v++){
		if (Graph[u][v] == 1 && Visited[v] == 0){
			Visited[v] = 1;
			dfs(v);
		}
	}
}

void solve_cases()
{
	int q;

	scanf("%d", &q);

	for (int i = 0; i < q; i++){
		int strt;
		scanf("%d", &strt);

		init();
		dfs(strt);

		print_output();


	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	while (scanf("%d", &N) == 1){
		if (N == 0){
			return 0;
		}

		init_graph();

		take_input();
		//print_graph();
		solve_cases();
	}
}
