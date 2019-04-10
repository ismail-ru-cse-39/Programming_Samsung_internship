#include <stdio.h>
#include <string.h>

#define sc(a,b) scanf("%d %d",&a,&b)
#define scchar2(a,b) scanf("%c %c",&a,&b)
#define scchar(a) scanf("%c",&a)
#define sc1(a) scanf("%d",&a)
#define out(a) printf("%d",a)
#define space() printf(" ")
#define line() printf("\n")
#define SIZE 201

int T, N, M;
char Map[SIZE][SIZE];
int Used[SIZE][SIZE];
int Ans;

void resetUsed()
{
	Ans = 0;
	for (int i = 0; i < N+4; i++){
		for (int j = 0; j < M+4; j++){
			Used[i][j] = 0;
		}
	}
}

void readCase()
{
	N = 0;
	while (gets(Map[N])) {
		if (Map[N][0] != 'L' && Map[N][0] != 'W')
			break;

		M = strlen(Map[N]);

		N++;
	}


}

int boundary_check(int x, int y){
	if (x >= 0 && x < N && y >= 0 && y < M)
		return 1;
	return 0;


}

void fill(int x, int y){

	if (Used[x][y] == 1 || Map[x][y] == 'L') return;

	if (Map[x][y] == 'W'){
		Ans++;
		Used[x][y] = 1;
	}

	//Map[x][y] = 'L';

	if (boundary_check(x - 1, y - 1)){
		if ('W' == Map[x - 1][y - 1]){
			fill(x - 1, y - 1);
		}
	}

	if (boundary_check(x - 1, y) && 'W' == Map[x - 1][y]){

		fill(x - 1, y);
	}

	if (boundary_check(x - 1, y + 1) && 'W' == Map[x - 1][y + 1]){

		fill(x - 1, y + 1);
	}

	if (boundary_check(x, y - 1) && 'W' == Map[x][y - 1]){

		fill(x, y - 1);
	}

	if (boundary_check(x, y + 1) && 'W' == Map[x][y + 1]){

		fill(x, y + 1);
	}

	if (boundary_check(x + 1, y - 1) && 'W' == Map[x + 1][y - 1]){

		fill(x + 1, y - 1);
	}

	if (boundary_check(x + 1, y) && 'W' == Map[x + 1][y]){

		fill(x + 1, y);
	}

	if (boundary_check(x + 1, y + 1) && 'W' == Map[x + 1][y + 1]){

		fill(x + 1, y + 1);
	}


}


void solveCase()
{
	int i, x, y;
	while (Map[N][0] != '\0') {
		i = x = y = 0;
		while (Map[N][i] != ' ') {
			x = x * 10 + Map[N][i] - '0';
			i++;
		}
		i++;

		y = 0;
		while (Map[N][i] != '\0') {
			y = y * 10 + Map[N][i] - '0';
			i++;
			//printf("%d\n", y);
		}
		resetUsed();
		x--;
		y--;
		//printf("%d %d\n", x, y);
		fill(x, y);
		printf("%d\n", Ans);
		if (!gets(Map[N]))
			break;
	}
	if (T)
		printf("\n");
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	scanf("%d ", &T);
	while (T--) {
		readCase();
		Ans = 0;
		solveCase();
	}
	return 0;
}
