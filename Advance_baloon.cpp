#include<stdio.h>
using namespace std;

long int ara[100];
long int hit[100];
long int n;


long int left_coun(long int index){
	long int val = 1;
	for (long int i = index - 1; i >= 0; i--){
		if (hit[i] == 0){
			val = ara[i];
			break;
		}
	}
	return val;
}

long int right_coun(long int index){
	long int val = 1;
	for (long int i = index + 1; i < n; i++){
		if (hit[i] == 0){
			val = ara[i];
			break;
		}
	}
	return val;
}


long int last_hit(){
	long int coun = 0;
	for (long int i = 0; i < n; i++)
		if (hit[i] == 1)
			coun++;

	if (coun == n - 1) return 1;
	return 0;
}


long int hit_fun(long int i){
	long int val = 0;
	if (last_hit() == 0){
		val = left_coun(i) * right_coun(i);
	}

	return val;

}

long int permutation_gen(long int i , long int score){

	//printf("=>%ld %ld\n", i, score);

	if (i == n)
		return score;

	long int ret = 0;

	for (int k = 0; k < n; k++){
		if (hit[k] == 0){

			long int ht = hit_fun(k);

			hit[k] = 1;

			long int val =  permutation_gen(i + 1, score + ht);
			if (val > ret) ret = val;

			hit[k] = 0;
		}
	}

	return ret ;
}

int main(){
	//freopen("input.txt", "r", stdin);


	long int tests;
	scanf("%ld", &tests);
	for (long int cases = 1; cases <= tests; cases++){
		scanf("%ld", &n);

		for (long int i = 0; i < n; i++){
			scanf("%ld", &ara[i]);
			hit[i] = 0;
		}

		printf("#%ld %ld\n" ,cases , permutation_gen(0 , 0));
	}

	return 0;
}
