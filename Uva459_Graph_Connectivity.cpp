#include <stdio.h>
#include <string.h>

#define sc(a,b) scanf("%d %d",&a,&b)
#define scchar2(a,b) scanf("%c %c",&a,&b)
#define scchar(a) scanf("%c",&a)
#define sc1(a) scanf("%d",&a)
#define out(a) printf("%d",a)
#define space() printf(" ")
#define line() printf("\n")
#define SIZE 127


int T, N;
char st[5];
int Path[SIZE][SIZE];
int Visited[SIZE];
int Count;

void initCase()
{
	int i, j;
	for (i = 0; i<N; i++) for (j = 0; j<N; j++)
		Path[i][j] = 0;

	for (i = 0; i<N; i++)
		Visited[i] = 0;
}

void readCase()
{
	int x, y;
	gets(st);
	N = st[0] - 'A' + 1;
	initCase();
	while (gets(st)) {
		if (st[0] == '\0')
			break;
		x = st[0] - 'A';
		y = st[1] - 'A';
		Path[x][y] = 1;
		Path[y][x] = 1;
	}
}

void Dfs(int i){

	int j;

	Visited[i] = 1;

	for (j = 0; j < N; j++){
		if (Visited[j] == 0 && Path[i][j]){
			Path[i][j] = 0;
			Path[j][i] = 0;
			Dfs(j);
		}
	}
}

void solveCase()
{
	for (int i = 0; i < N; i++){
		if (Visited[i] == 0){
			//printf("hello\n");
			Count++;
			Dfs(i);
		}
	}
}

void printCase()
{
	printf("%d\n", Count);
	if (T)
		printf("\n");
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	scanf("%d", &T);
	getchar();
	getchar();
	while (T--) {
		readCase();
		Count = 0;
		solveCase();
		printCase();
	}
	return 0;
}
