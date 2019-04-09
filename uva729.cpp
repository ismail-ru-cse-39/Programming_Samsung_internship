//Uva 729
//Hamming distance

#include <stdio.h>

#define sc(a,b) scanf("%d %d",&a,&b)
#define sc1(a) scanf("%d",&a)
#define out(a) printf("%d",a)
#define space() printf(" ")
#define line() printf("\n")
#define SZ 200+10

int N, Test_cases, H;
int A[SZ];


/*int Count(int n){

	int cnt = 0;

	while (n--){
		if (n & 1){
			cnt++;
		}

		n = n >> 1;
	}

	return cnt;
}*/

void print()
{
	int i;
	int cnt = 0;

	for (i = 0; i < N; i++){
		if (A[i] == 1){
			cnt++;
		}
	}

	if (cnt == H){
		for (i = 0; i < N; i++){
			out(A[i]);
			//space();
		}
		line();
	}


}


void init()
{
	for (int i = 0; i < N; i++){
		//check[i] = 0;
		A[i] = 0;
	}
}

void solve(int i){
	//int j;


	if (i == N){
		print();

		return;
	}


	//init();

		A[i] = 0;

		solve(i + 1);

		A[i] = 1;

		solve(i + 1);



}


void take_input(){
	while (1 == sc1(Test_cases)){

		for (int i = 0; i < Test_cases; i++){
			sc(N, H);

			init();
			solve(0);

			if (i != Test_cases-1){
				line();
			}
		}
	}
}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	take_input();
}
