//permutation
#include <stdio.h>

#define out(a) printf("%d",a)
#define space() printf(" ")
#define line() printf("\n");
#define sc(a) scanf("%d",&a)
#define SZ 20000

int check[SZ];

int A[SZ];
int N;

void print()
{
	int i;
	for (i = 0; i < N-1; i++){
		out(A[i]);
		space();
	}

	line();
}


void init()
{
	for (int i = 0; i < N; i++){
		check[i] = 0;
	}
}

void solve(int i){
	int j;


	if (i == N-1){
		print();

		return;
	}


	//init();
	for (j = 1; j < N; j++){
		A[i] = j;

		if (check[j] != 1){
			check[j] = 1;

			solve(i + 1);
			check[j] = 0;
		}
	}
}


int main()
{
	//freopen("out.txt", "w", stdout);

	sc(N);

	solve(0);

	return 0;
}
