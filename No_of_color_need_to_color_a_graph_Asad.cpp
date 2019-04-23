#include <cstdio>

class MColoring{
	int n, m;
	int path[101][101];
	int color[101];
public:
	MColoring(int n, int m){
		this->n = n;
		this->m = m;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				path[i][j] = 0;
		}
	}

	void reset(){
		for(int i = 0; i < n; i++)
			color[i] = 0;
	}

	void getInput(){
		int u, v;
		for(int i = 0; i < m; i++){
			scanf("%d %d", &u, &v);
			path[u][v] = 1;
			path[v][u] = 1;
		}
	}

	bool isColorable(int u, int c){
		for(int v = 0; v < n; v++){
			if(path[u][v] && c == color[v]){
				return false;
			}
		}
		return true;
	}

	bool dfs(int u, int nc){
		bool isColored = false;
		for(int i = 1; i <= nc; i++ ){
			if(isColorable(u, i))
			{
				color[u] = i;
				isColored = true;
				for(int v = 0; v < n; v++){
					if(path[u][v] && !color[v]){
						return dfs(v, nc);
					}
				}
				break;
			}
		}
		return isColored;
	}

	void solve(){
		for(int i = 1; i <= n; i++){
			reset();
			bool isColored = true;
			for(int u = 0; u < n; u++){
				if(!color[u]){
					if(!dfs(u, i)){
						isColored = false;
						break;
					}
				}
			}
			if(isColored){
				printf("%d\n", i);
				return;
			}
		}
	}
};

int main(int argc, char const *argv[])
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	int st = 0;
	while(st < t){
		int n, m;
		scanf("%d %d", &n, &m);
		MColoring mc(n, m);
		mc.getInput();
		mc.solve();
		st++;
	}
	return 0;
}
