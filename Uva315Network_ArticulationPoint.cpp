//solved

#include<stdio.h>

#define SIZE 101

int N;
int Path[SIZE][SIZE];
int Pre[SIZE];
int IsCut[SIZE];
int DfsClock;
int Ans;

void initCase()
{
	int i, j;
	for (i = 1; i <= N; i++) for (j = 1; j <= N; j++)
		Path[i][j] = 0;
	for (i = 1; i <= N; i++)
		Pre[i] = 0;
	for (i = 1; i <= N; i++)
		IsCut[i] = 0;
	DfsClock = 0;
}

void readCase()
{
	int x, y;
	char ch;
	while (1 == scanf("%d", &x)) {
		if (0 == x)
			break;
		while (2 == scanf("%d%c", &y, &ch)) {
			Path[x][y] = 1;
			Path[y][x] = 1;
			if (ch == '\n')
				break;
		}
	}
}

void dfs(int u)
{
	Pre[u] = 0;

	for (int v = 1; v <= N; v++){
		if (Path[u][v] && Pre[v]){
			dfs(v);
		}
	}
}

void solveCase()
{
	Ans = 0;

	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			Pre[j] = 1;
		}

		Pre[i] = 0;
		int p;

		for (int j = 1; j <= N; j++){
			if (Path[i][j] && Pre[j]){
				//Pre[j] = 0;
				dfs(j);
				//p = j;
				break;
			}
		}


		for (int j = 1; j <= N; j++){
			if (Path[i][j] && Pre[j]){
				//printf("Path %d %d\n", i, j);
				Ans++;
				break;
			}
		}
	}
}

void printCase()
{
	printf("%d\n", Ans);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	while (1 == scanf("%d", &N) && N) {
		initCase();
		readCase();
		solveCase();
		printCase();
	}
	return 0;
}
