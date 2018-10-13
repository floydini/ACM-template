const int N = 5e4 + 5;

int n1, n2;
vector<int> G[N];
int mx[N], my[N];
queue<int> q;
int dx[N], dy[N];
bool vis[N];
bool find(int u) {
	for(auto v : G[u]) {
		if(!vis[v] && dy[v] == dx[u] + 1) {
			vis[v] = true;
			if(!my[v] || find(my[v])) {
				mx[u] = v;
				my[v] = u;
				return true;
			}
		}
	}
	return false;
}
int matching() {
	memset(mx, 0, sizeof(mx));
	memset(my, 0, sizeof(my));
	int ans = 0;
	while(true) {
		bool flag = false;
		while(!q.empty()) q.pop();
		memset(dx, 0, sizeof(dx));
		memset(dy, 0, sizeof(dy));
		for(int i = 1; i <= n1; i++)
			if(!mx[i]) q.push(i);
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			for(auto v : G[u])
				if(!dy[v]) {
					dy[v] = dx[u] + 1;
					if(my[v]) {
						dx[my[v]] = dy[v] + 1;
						q.push(my[v]);
					} else flag = true;
				}
		}
		if(!flag) break;
		memset(vis, 0, sizeof(vis));
		for(int i = 1; i <= n1; i++)
			if(!mx[i] && find(i)) ans++;
	}
	return ans;
}