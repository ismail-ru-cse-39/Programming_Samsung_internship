//Advance
//to solve
//Fisherman
//River

#include <stdio.h>

#define SZ 30+4

int Arr[SZ];
int G1, G2, G3, P1, P2, P3;
int Test_cases, Case;
int Ans = 30;


void init()
{
	for (int i = 1; i <= 30; i++){
		Arr[i] = 0;
	}
}

void take_input()
{
	scanf("%d %d", &G1, &P1);
	scanf("%d %d", &G2, &P2);
	scanf("%d %d", &G3, &P3);


}

int Max(int a, int b)
{
	if (a > b){
		return a;
	}
	else{
		return b;
	}
}

void solve()
{

	int i, j, k, left, right, dist1, dist2, dist3, max;
	Ans = 30;

	for (i = 1; i + m1 + m2 + m3 - 1 <= 30; i++){
		left =abs( p1 - i);

		if (p1 > i + m1 - 1){
			right = p1 - (i + m1 - 1);
		}
		else{
			right = (i + m1 - 1) - p1;
		}

		if (left > right){
			dist1 = left;
		}
		else{
			dist1 = right;
		}

		for (j = i + m1; j + m2 + m3 - 1 <= 30; j++){
			if (j > p2){
				left = j - p2;
			}
			else{
				left = p2 - j;
			}

			if (p2 > j + m2 - 1){
				right = p2 - (j + m2 - 1);
			}
			else{
				right = (j + m2 - 1) - p2;
			}

			if (left > right){
				dist2 = left;
			}

			else{
				dist2 = right;
			}

			for (k = j + m2; k + m3 - 1 <= 30; k++){
				if (k > P3){
					left = k - p3;
				}
				else{
					left = p3 - k;
				}

				if (p3 > k + m3 - 1){
					right = p3 - (k + m3 - 1);
				}
				else{
					right = (k + m3 - 1) - p3;
				}

				if (left > right){
					dist3 = left;
				}
				else{
					dist3 = right;
				}

				max = dist1;

				if (dist2 > max){
					max = dist2;
				}

				if (dist3 > max){
					max = dist3;
				}

				if (max < Ans){
					Ans = max;
				}
			}
		}
	}



}

int main()
{
	scanf("%d", &Test_cases);

	for (Case = 1; Case <= Test_cases; Case++){

		init();
		take_input();

		solve();
	}
}



/*
input

50

2 1
7 2
16 6

6 10
8 8
16 1

5 8
10 4
12 1

3 3
11 5
16 7

5 9
12 4
18 4

5 4
15 6
20 4

4 9
8 7
15 2

7 6
8 1
14 9

4 5
9 10
12 1

9 5
14 2
17 6

9 4
14 1
24 8

3 3
11 4
18 5

10 3
12 4
20 10

9 10
13 10
18 7

5 1
15 9
24 4

3 7
10 9
12 8

2 1
3 10
4 7

10 1
12 9
15 6

10 2
13 9
19 10

3 6
6 9
12 1

9 4
11 2
17 7

7 5
8 7
15 2

10 4
11 8
18 8

4 4
8 3
13 9

5 8
14 2
22 9

7 10
15 10
23 5

2 6
12 4
20 4

6 8
7 9
8 7

10 5
17 7
27 5

8 1
11 3
15 6

7 6
12 3
18 7

1 5
7 6
17 2

8 9
16 6
22 3

7 1
11 1
12 3

7 3
11 5
17 8

7 5
14 5
22 3

3 4
6 4
7 5

8 7
10 7
20 8

5 7
13 6
15 3

7 2
10 1
20 1

4 8
5 1
8 1

1 7
7 2
16 2

10 3
19 6
25 1

7 9
11 5
17 3

1 3
5 4
6 9

7 2
16 6
23 3

7 4
13 1
21 2

8 5
9 1
11 3

8 7
11 9
12 9

8 1
10 9
11 10
*/


/*
output

#1 3
#2 10
#3 4
#4 3
#5 4
#6 3
#7 8
#8 4
#9 6
#10 3
#11 4
#12 2
#13 5
#14 9
#15 4
#16 12
#17 14
#18 6
#19 6
#20 9
#21 3
#22 5
#23 6
#24 4
#25 4
#26 6
#27 4
#28 16
#29 3
#30 3
#31 3
#32 4
#33 4
#34 1
#35 4
#36 2
#37 6
#38 6
#39 3
#40 1
#41 4
#42 6
#43 3
#44 5
#45 10
#46 3
#47 2
#48 3
#49 13
#50 9
*/
