const int N = 1000 + 5;
const int INF = 0x3f3f3f3f;
using P = pair<int, int>;
struct edge {int to, cap, cost, rev;};
int d[N], h[N], pv[N], pe[N], V; // V should be set
vector<edge> G[N];

void add_edge(int from, int to, int cap, int cost) {
	G[from].push_back((edge) {to, cap, cost, (int)G[to].size()});
	G[to].push_back((edge) {from, 0, -cost, (int)G[from].size() - 1});
}

int min_cost_flow(int s, int t, int flow, int &cost) { // return used flow
	int f = 0;
	cost = 0;
	fill(h, h + V, 0);
	while(f < flow) {
		priority_queue<P, vector<P>, greater<P> >q;
		fill(d, d + V, INF);
		d[s] = 0;
		q.push(P(0, s));
		while(!q.empty()) {
			P p = q.top(); q.pop();
			int v = p.second;
			if(d[v] < p.first) continue;
			for(int i = 0; i < (int)G[v].size(); i++) {
				edge &e = G[v][i];
				if(e.cap > 0 && d[e.to] > d[v] + e.cost + h[v] - h[e.to]) {
					d[e.to] = d[v] + e.cost + h[v] - h[e.to];
					pv[e.to] = v;
					pe[e.to] = i;
					q.push(P(d[e.to], e.to));
				}
			}
		}
		if(d[t] == INF) return f;
		for(int v = 0; v < V; v++) h[v] += d[v];
		int inc = flow - f;
		for(int v = t; v != s; v = pv[v]) {
			inc = min(inc, G[pv[v]][pe[v]].cap);
		}
		f += inc;
		cost += inc * h[t];
		for(int v = t; v != s; v = pv[v]) {
			edge &e = G[pv[v]][pe[v]];
			e.cap -= inc;
			G[v][e.rev].cap += inc;
		}
	}
	return f;
}