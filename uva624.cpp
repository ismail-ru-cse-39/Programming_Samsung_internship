//SOLVED
//UVA-624
//CD


#include <stdio.h>

#define sc(a,b) scanf("%d %d",&a,&b)
#define sc1(a) scanf("%d",&a)
#define out(a) printf("%d",a)
#define space() printf(" ")
#define line() printf("\n")
#define SZ 20+1


int N, No_duration, Arr_Duration[SZ];
int Bin[SZ],Path[SZ];
int Max = -1;

void print_case()
{
	for (int i = 0; i < No_duration; i++){
		if (Path[i]){
			out(Arr_Duration[i]);
			space();
		}
	}

	printf("sum:%d\n", Max);
}

void update()
{
	int sum = 0;

	for (int i = 0; i < No_duration; i++){
		if (Bin[i]){
			sum += Arr_Duration[i];
		}
	}

	if (sum > Max){
		Max = sum;

		for (int i = 0; i < No_duration; i++){
			Path[i] = Bin[i];
		}
	}
}

void solve(int i, int cap){
	if (i == No_duration){
		update();
		return;
	}

	Bin[i] = 0;

	solve(i + 1, cap);

	Bin[i] = 1;

	if (cap - Arr_Duration[i] >= 0){
		//Bin[i] = 0;
		solve(i + 1, cap - Arr_Duration[i]);
		//Bin[i] = 1;
	}
}



void take_input()
{

	while (2 == sc(N, No_duration)){
		for (int i = 0; i < No_duration; i++){
			sc1(Arr_Duration[i]);
		}
		Max = -1;
		solve(0, N);
		print_case();
	}
}

int main()
{

	freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	take_input();

	return 0;
}
