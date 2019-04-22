//Directed graph
//solved

#include <stdio.h>

#define SZ 1000

int Path[SZ][SZ];
int Visited[SZ];
int N, M;
int flag;
int Test_cases, Case;



void read_case()
{
	int u, v;

	scanf("%d %d", &N, &M);

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

int fil(int src, int cur){
	int i;
	Visited[cur] = 1;

	//printf("curr----------> %d\n", cur);

	for (i = 1; i <= N; i++){
		if (Path[cur][i]){
			if (0 == Visited[i]){
				if (1 == fil(src, i)){
					return 1;
				}
			}
			else if (src == i){
				return 1;
			}
			//Path[cur][i] = 0;
		}

	}

	Visited[cur] = 0;



	return 0;
}


void solve_case()
{
	int i;
	 flag = 0;

	for (i = 1; i <= N; i++){
		Visited[i] = 0;
	}

	for (i = 1; i <= N; i++){
		if (0 == Visited[i]){
			if (1 == fil(i, i)){
				flag = 1;
				break;
			}

		}
	}

}

void print_case()
{
	int i;

	printf("#%d", Case);

	if (1 == flag){
		for (i = 1; i <= N; i++){
			if (Visited[i] == 1){
				printf(" %d", i);
			}
		}
		printf("\n");
	}

	else{
		printf(" -1\n");
	}
}


int main()
{

	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	scanf("%d", &Test_cases);

	for (Case = 1; Case <= Test_cases; Case++){
		read_case();
		solve_case();
		print_case();
	}
}
