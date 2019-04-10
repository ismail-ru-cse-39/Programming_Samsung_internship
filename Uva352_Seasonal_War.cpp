#include <stdio.h>

#define sc(a,b) scanf("%d %d",&a,&b)
#define scchar2(a,b) scanf("%c %c",&a,&b)
#define scchar(a) scanf("%c",&a)
#define sc1(a) scanf("%d",&a)
#define out(a) printf("%d",a)
#define space() printf(" ")
#define line() printf("\n")
#define SZ 101

char Grid[SZ][SZ];
int M, N;
int Cnt = 0;

int boundary_check(int x, int y){
	if (x < 0 || y < 0){
		return 0;
	}
	if (x >= M || y >= N){
		return 0;
	}

	return 1;
}

void fill(int x, int y){

	Grid[x][y] = '0';

	if (boundary_check(x - 1, y - 1)){
		if ('1' == Grid[x - 1][y - 1]){
			fill(x - 1, y - 1);
		}
	}

	if (boundary_check(x - 1, y) && '1' == Grid[x - 1][y]){
		fill(x - 1, y);
	}

	if (boundary_check(x - 1, y + 1) && '1' == Grid[x - 1][y + 1]){
		fill(x - 1, y + 1);
	}

	if (boundary_check(x, y - 1) && '1' == Grid[x][y - 1]){
		fill(x, y - 1);
	}

	if (boundary_check(x, y + 1) && '1' == Grid[x][y + 1]){
		fill(x, y + 1);
	}

	if (boundary_check(x + 1, y - 1) && '1' == Grid[x + 1][y - 1]){
		fill(x + 1, y - 1);
	}

	if (boundary_check(x + 1, y) && '1' == Grid[x + 1][y]){
		fill(x + 1, y);
	}

	if (boundary_check(x + 1, y + 1) && '1' == Grid[x + 1][y + 1]){
		fill(x + 1, y + 1);
	}


}

int main()
{
	int i;

	//freopen("input.txt", "r", stdin);
	int Case = 0;

	while (1 == sc1(N)){
		M = N;
		Case++;

		if (0 == (M + N)){
			break;
		}

		for (int i = 0; i < M; i++){
			scanf("%s", Grid[i]);
		}

		Cnt = 0;
		//printf("hjhjhj\n");

		for (int i = 0; i < M; i++){
			for (int j = 0; j < N; j++){
				if ('1' == Grid[i][j]){
					Cnt++;
					fill(i, j);
				}
			}
		}

		printf("Image number %d contains %d war eagles.\n",Case,Cnt);
	}

	return 0;
}
