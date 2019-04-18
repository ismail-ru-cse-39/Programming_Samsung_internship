//Uva 10305
//ordering task

#include <stdio.h>

#define SZ 110

int Path[SZ][2 * SZ];
int Visited[SZ];
int N, M;
int J,Time;

struct node{
    int node;
    int end_time;
};

node S_node[SZ];

void input_case()
{
	int u, v;
	for (u = 1; u <= N; u++){
		for (v = 1; v <= N; v++){
			Path[u][v] = 0;
		}
	}

	while (M--){
		scanf("%d %d", &u, &v);
		Path[u][v] = 1;
		//Path[v][u] = 1;
	}
}

void dfs(int u)
{
    Visited[u] = 1;
    Time += 1;

    for( int v = 1 ; v <= N ; v++ ){
        if(0 == Visited[v] && Path[u][v]){
            dfs(v);
        }
    }

    Time += 1;

    S_node[J].end_time = Time;
    S_node[J].node = u;
    J++;
}

void struct_sort()
{
    for(int i = 0 ; i < J ; i++){
        for(int j = i+1 ; j < J ; j++){
            if(S_node[i].end_time < S_node[j].end_time){
                int tmp_end_time = S_node[i].end_time;
                int tmp_node = S_node[i].node;

                S_node[i].end_time = S_node[j].end_time;
                S_node[i].node = S_node[j].node;

                S_node[j].end_time = tmp_end_time;
                S_node[j].node = tmp_node;
            }
        }
    }
}

void print_struct()
{
    for(int i = 0 ; i< J ; i++){
        printf("Struct.........node time> %d %d\n",S_node[i].node, S_node[i].end_time);
    }
}

void solve_case()
{
	int i;
	for (i = 1; i <= N; i++){
		Visited[i] = 0;
	}
    J = 0;
    Time = 0;
	for (i = 1; i <= N; i++){
		if (!Visited[i]){
			dfs(i);
		}
	}
    //print_struct();
	struct_sort();
	//printf("------------\n");
	//print_struct();
}

void print_case()
{
    for(int i = 0 ; i < J ; i++){
        printf("%d",S_node[i].node);
        if(i < J-1){
            printf(" ");
        }
    }

    printf("\n");
}


int main()
{

    freopen("in.txt", "r", stdin);
   freopen("out.txt", "w", stdout);

	while (scanf("%d %d", &N, &M) == 2){
		if (N + M == 0){
			return 0;
		}

		input_case();
		solve_case();
		print_case();
	}

	return 0;
}
