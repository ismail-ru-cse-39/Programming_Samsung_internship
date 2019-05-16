//Advance
//Bit
//solution
//solved

#include <stdio.h>

#define SZ 110

int N, M, K,Test_case;
int Ar_grid[SZ][SZ];
int Case;
int Ans = 0;


int Max(int a, int b)
{
	if (a > b){
		return a;
	}

	return b;
}


void take_input()
{
	int i, j;
	scanf("%d %d %d", &N, &M, &K);

	for (i = 0; i < N; i++){
		for (j = 0; j < M; j++){
			scanf("%d", &Ar_grid[i][j]);
		}
	}

}

int cntzero(int i)
{
	int j;
	int cnt = 0;

	for (j = 0; j < M; j++){
		if (Ar_grid[i][j] == 0){
			cnt++;
		}
	}
	return cnt;
}


int isSame(int row1, int row2){
	int j;

	for (j = 0; j < M; j++){
		if (Ar_grid[row1][j] != Ar_grid[row2][j]){
			return 0;
		}
	}

	return 1;
}


void solve_case()
{
	int i;
	int cnt_zero_1;
	int cnt_zero_2;
	int cnt = 0;
	int flag = 0;

	Ans = 0;


	for (i = 0; i < N ; i++){
		cnt_zero_1 = cntzero(i);
		 cnt = 0;
		if (cnt_zero_1 == K || (K>= cnt_zero_1 &&(K-cnt_zero_1)%2 == 0)){
			cnt = 1;
			for (int j = i + 1; j < N; j++){

				if (isSame(i, j)){
					cnt++;
					/*if (cnt > 0){
						flag = 1;
					}*/
				}

			}
			Ans = Max(Ans, cnt);
		}
	}

	/*if (flag > 0){
		Ans++;
	}*/

}

void print_case()
{
	printf("#%d %d\n",Case, Ans);
}

int main()

{

	//freopen("in.txt", "r", stdin);
	freopen("in_bit.txt", "r", stdin);
	freopen("out.txt", "w", stdout);


	scanf("%d", &Test_case);

	for (Case = 1; Case <= Test_case; Case++){
		take_input();
		solve_case();
		print_case();
	}
}
