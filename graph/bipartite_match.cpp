const int N = 1e3 + 5;
int V;
vector<int> G[N];
int match[N];
bool used[N];

bool dfs(int v) {
	used[v] = true;
	for(auto u : G[v]) {
		int w = match[u];
		if(w < 0 || !used[w] && dfs(w)) {
			match[v] = u;
			match[u] = v;
			return true;
		}
	}
	return false;
}
int bipartite_matching() {
	int res = 0;
	fill(match, match + V, -1);
	for(int v = 0; v < V; v++) {
		if(match[v] < 0) {
			fill(used, used + V, 0);
			if(dfs(v)) res++;
		}
	}
	return res;
}