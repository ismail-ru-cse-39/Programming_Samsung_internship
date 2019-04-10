//Uva 11953
//Battleship

#include <stdio.h>
#include <string.h>

#define sc(a,b) scanf("%d %d",&a,&b)
#define scchar2(a,b) scanf("%c %c",&a,&b)
#define scchar(a) scanf("%c",&a)
#define sc1(a) scanf("%d",&a)
#define out(a) printf("%d",a)
#define space() printf(" ")
#define line() printf("\n")
#define SZ 102

int N;
int T;
char Grid[SZ][SZ];


int boundary_check(int x, int y){
	if (x < 0 || y < 0){
		return 0;
	}
	if (x >= N || y >= N){
		return 0;
	}

	return 1;
}

void fill(int x, int y){
	Grid[x][y] = '.';

	if (boundary_check(x, y + 1) && (Grid[x][y+1] == 'x' || Grid[x][y+1] == '@')){
		fill(x, y + 1);
	}

	if (boundary_check(x+1, y) && (Grid[x+1][y] == 'x' || Grid[x+1][y] == '@')){
		fill(x+1, y);
	}

}

void take_input()
{

	sc1(T);

	for (int cases = 1; cases <= T; cases++){

		sc1(N);

		for (int i = 0; i < N; i++){
			scanf("%s", Grid[i]);
		}

		int Cnt = 0;

		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				if (Grid[i][j] == 'x'){
					Cnt++;

					fill(i, j);
				}
			}
		}

		printf("Case %d: %d\n", cases, Cnt);

	}
}

int main()
{

	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	take_input();

	return 0;
}
