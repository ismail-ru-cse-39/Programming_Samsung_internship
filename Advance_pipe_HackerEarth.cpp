//pipe
//to solve
//BFS

#include <stdio.h>

#define SZ 1000+20

int Grid[SZ][SZ];
int Visited[SZ][SZ];
int Test_cases, Case;
int N, M, R, C, L;
long long Ans = 0;



struct queuestruct{
	int x, y, len;
};



queuestruct Q[SZ*SZ];

int front, rear;

void initQueue()
{
	front = rear = 0;
}

void push(int x, int y, int len)
{
	Q[rear].x = x;
	Q[rear].y = y;
	Q[rear].len = len;

	rear++;

}

queuestruct pop()
{
	return Q[front++];
}


int isEmpty()
{
	if (rear == front){
		return 1;
	}

	return 0;
}

void take_input()
{
	scanf("%d %d %d %d %d", &N, &M, &R, &C, &L);

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			scanf("%d", &Grid[i][j]);

			if (Grid[i][j]){
				Visited[i][j] = 0;
			}
			else{
				Visited[i][j] = 1;
			}
		}
	}
}


int isup(int n){

	switch (n)
	{
	case 1:
	case 2:
	case 4:
	case 7:
		return 1;

	}

	return 0;
}


int isdown(int n){

	switch (n)
	{
	case 1:
	case 2:
	case 5:
	case 6:
		return 1;

	}

	return 0;
}

int isleft(int n){

	switch (n)
	{
	case 1:
	case 3:
	case 6:
	case 7:
		return 1;

	}

	return 0;
}


int isright(int n){

	switch (n)
	{
	case 1:
	case 3:
	case 4:
	case 5:
		return 1;

	}

	return 0;
}



void solve()
{
	queuestruct q;

	initQueue();

	Ans = 0;

	if (Grid[R][C]){
		Visited[R][C] = 1;
        Ans++;
		push(R, C, 1);
	}

	while (!isEmpty()){

		q = pop();

		if (q.len < L){

			int x = q.x;
			int y = q.y;
			int n = Grid[x][y];
			int l = q.len;

			if (x - 1 >= 0 && isup(n) && Visited[x - 1][y] == 0){
				if (isdown(Grid[x-1][y])){
					Ans++;
					Visited[x - 1][y] = 1;
					push(x - 1, y, l + 1);
				}
			}


			if (y - 1 >= 0 && isleft(n) && Visited[x][y - 1] == 0){
				if (isright(Grid[x][y-1])){
					Ans++;
					Visited[x][y - 1] = 1;
					push(x, y - 1, l + 1);
				}
			}

			if (x + 1 < N && isdown(n) && Visited[x + 1][y] == 0){
				if (isup(Grid[x+1][y])){
					Ans++;
					Visited[x + 1][y] = 1;
					push(x + 1, y, l + 1);
				}
			}



			if (y + 1 < M && isright(n) && Visited[x][y + 1] == 0){
				if (isleft(Grid[x][y+1])){
					Ans++;
					Visited[x][y + 1] = 1;
					push(x, y + 1, l + 1);
				}
			}
		}
	}


}

void print_output()
{
	//printf("#%d %d\n",Case, Ans);
	printf("%d\n", Ans);
}


int main()
{

    freopen("in.txt", "r", stdin);

	scanf("%d", &Test_cases);

	for (Case = 1; Case <= Test_cases; Case++){
		take_input();
		solve();
		print_output();
	}
}
