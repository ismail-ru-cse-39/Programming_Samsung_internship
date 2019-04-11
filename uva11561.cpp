
//should solve

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
#define SZ 105

char Grid[SZ][SZ];
int W, H;
int Mov_x[] = { -1, 1, 0, 0 };
int Mov_y[] = { 0, 0, -1, 1 };
int Cnt = 0;
int Mx = 0;


int boundary_check(int x, int y){
	if (x >= 0 && x < H && y >= 0 && y < W)
		return 1;
	return 0;
}


void fil(int x, int y)
{
   // printf(":: %d %d\n" , x , y) ;
    if(Grid[x][y] == '#') return ;


	if (Grid[x][y] == 'G'){
		Cnt++;
	}

    Grid[x][y] = '#' ;

	for (int i = 0; i < 4; i++){
		if (boundary_check(x + Mov_x[i], y + Mov_y[i]) && Grid[x + Mov_x[i]][y + Mov_y[i]] == 'T'){
			return;
		}
	}


	for (int i = 0; i < 4; i++){
		if (boundary_check(x + Mov_x[i], y + Mov_y[i]))
		{



			if (Grid[x + Mov_x[i]][y + Mov_y[i]] != '#'){
				//fil(x, y);
				fil(x + Mov_x[i], y + Mov_y[i]);
				//continue;
			}
			//if(Grid[x + Mov_x[i]][y + Mov_y[i]] != 'T')




		}
	}

}

//debug
void print_grid(){
    for(int i = 0  ; i < H ; i++){
        for(int j = 0 ; j < W ; j++){
            printf("%c" , Grid[i][j]) ;
        }
        printf("\n") ;
    }
}


void take_input()
{
	while (sc(W, H) == 2){

		for (int i = 0; i < H; i++){
			scanf("%s", Grid[i]);
		}

		Cnt = 0;

      //  print_grid() ;

		for (int i = 0; i < H; i++){
			for (int j = 0; j < W; j++){
				if (Grid[i][j] == 'P'){
					//printf("->%d %d\n" , i , j) ;
					fil(i, j);


				}
				//printf("%c", Grid[i][j]);
			}
			//line();
		}

		out(Cnt);
		line();
	}
}


int main()
{
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	take_input();

	return 0;
}
