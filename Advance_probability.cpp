//Advance
//Graph_Probability

#include <stdio.h>

#define SZ 200+10

double Graph[SZ][SZ];
int Time, N, E;
int Test_cases, Case;


void init_graph()
{
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			Graph[i][j] = 0.0000;
		}
	}
}


void take_input()
{
	scanf("%d %d %d", &N, &E, &Time);

	init_graph();

	for (int i = 0; i < E; i++){
		int u, v;
		double w;

		scanf("%d %d %lf", &u, &v, &w);

		Graph[u][v] = w;
	}
}


void solve()
{
	double tmp[SZ];
	double current[SZ];

	int node = 0;
	double mx = 0.00;

	Time /= 10;
	//printf("Tiem :%d\n", Time);

	current[1] = 1.00;

	for (int i = 2; i <= N; i++){
		current[i] = 0.00;
	}

	for (int i = 1; i <= Time; i++){
		mx = 0.00;
		for (int j = 1; j <= N; j++){
			tmp[j] = 0.000;
		}

		for (int u = 1; u <= N; u++){
			for (int v = 1; v <= N; v++){
				tmp[v] += current[u] * Graph[u][v];
			}
		}

		for (int u = 1; u <= N; u++){
			current[u] = tmp[u];
		}


		for (int u = 1; u <= N; u++){
			if (current[u]-mx > 0.00){
				mx = current[u];
				node = u;
			}
		}
	}


	printf("#%d  %d %.7lf\n", Case, node, mx);


}

int main()
{

	freopen("in.txt", "r", stdin);

	scanf("%d", &Test_cases);

	for (Case = 1; Case <= Test_cases; Case++){
		take_input();
		solve();

	}
}
