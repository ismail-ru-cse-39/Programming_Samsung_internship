#include <stdio.h>
#include <string.h>

#define sc(a,b) scanf("%d %d",&a,&b)
#define scchar2(a,b) scanf("%c %c",&a,&b)
#define scchar(a) scanf("%c",&a)
#define sc1(a) scanf("%d",&a)
#define scs(a) scanf("%s",&a)
#define out(a) printf("%d",a)
#define space() printf(" ")
#define line() printf("\n")
#define SIZE 1005

int Test_cases;
char Grid[SIZE][SIZE];
int N, M;
int Mov_x[] = { -1, 1, 0, 0 };
int Mov_y[] = { 0, 0, -1, 1 };
char Ch;

int boundary_check(int x, int y){
	if (x < 0 || y < 0){
		return 0;
	}

	if (x >= N-1 || y >= M){
		return 0;
	}

	return 1;
}

void fil(int x, int y){

		if(Grid[x][y] == 'X'){
            return;
		}
		Grid[x][y] = Ch;


	for (int i = 0; i < 4; i++){
		int nx = x + Mov_x[i];
		int ny = y + Mov_y[i];

		if ( Grid[nx][ny] == ' '){
			fil(nx, ny);
		}
	}
}

void print_output()
{
	for (int i = 0; i < N; i++){

		printf("%s", Grid[i]);

		line();
	}
	//line();

	//printf("%s\n", Grid[N]);
}


void print_for_debug()
{
	for (int i = 0; i < N; i++){
		printf("%s",Grid[i]);
		line();
	}
}

void solve()
{

		//print_for_debug();

		/*out(N);
		space();
		out(M);
		line();*/


		for (int i = 0; i < N-1; i++){
                M = strlen(Grid[i]);
			for (int j = 0; j < M; j++){
				if (Grid[i][j] != 'X'&& Grid[i][j] != ' '){
					Ch = Grid[i][j];
					fil(i, j);
				}
			}
		}

		print_output();

}

void take_input()
{

		N = 0;

		while (gets(Grid[N])){
             N++;
            //printf("%s\n",Grid[N-1]);

			if(Grid[N-1][0] == '_'){
               // printf("%s\n",Grid[N-1]);

                solve();
                N = 0;
                //getchar();
			}
		}

		//gets(Grid[N]);




}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	take_input();

	return 0;
}
