#include <stdio.h>
#include <math.h>
#include <queue>
#include<algorithm>
using namespace std;

#define sc1(a) scanf("%d",&a)
#define sc(a,b) scanf("%d %d",&a, &b)
#define out(a) printf("%d",a)
#define space() printf(" ")
#define line() printf("\n")
#define Max(a,b) a > b ? a : b
#define SZ 100000+10



int N, M;
vector<int>Graph[SZ];
int Visited[SZ];
int Test_cases;
int Time = 0;
int J = 0;

struct node{
	int u;
	int end_time;
};

node S_node[SZ];


bool compare(node a, node b)
{
	if (a.end_time > b.end_time)
		return true;
	else{
		return false;
	}
}


void init()
{
	for (int i = 0; i < N+1; i++){
		Visited[i] = 0;
		//Level[i] = 0;
	}
}

void init_graph()
{
	for (int i = 0; i < N+1; i++){
		Graph[i].clear();
	}
}


void take_input()
{
	sc(N, M);
    init_graph();

	for (int i = 0; i < M; i++){
		int u, v;
		sc(u, v);

		Graph[u].push_back(v);
	}
}


void dfs(int u)
{
	Visited[u] = 1;
	Time = Time + 1;

	for (int i = 0; i < Graph[u].size(); i++){
		int v = Graph[u][i];

		if (!Visited[v]){
			dfs(v);
		}
	}

	Time = Time + 1;

	S_node[J].u = u;
	S_node[J].end_time = Time;
	J++;

}

void dfs2(int u)
{
	Visited[u] = 1;

	for (int j = 0; j < Graph[u].size(); j++){
		int v = Graph[u][j];

		if (!Visited[v]){
			dfs2(v);
		}
	}
}


void print_output( int cnt){

	printf("%d\n",cnt);
	//printf("Case %d: %d\n", cases, Mx);

}

int main()
{

	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);


	sc1(Test_cases);

	for (int cases = 1; cases <= Test_cases; cases++){



		take_input();
		init();

		Time = 0;
		J = 0;

		for (int i = 1; i <= N; i++){
			if (Visited[i] == 0){
				dfs(i);
			}
		}


		sort(S_node, S_node + J, compare);

		int cnt = 0;
		init();

		//printf("jjjjjjjjjj----> %d\n", J);

		for (int i = 0; i < J; i++){
			int u = S_node[i].u;
			//printf("---> %d %d %d\n", S_node[i].u, S_node[i].end_time, i);
			if (!Visited[u]){
				cnt++;
				dfs2(u);
			}
		}



		print_output(cnt);
	}

	return 0;
}

