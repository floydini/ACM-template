#include<bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
const int N = 1e6;
const int INF = 0x3f3f3f3f;
struct edge {int to, w;};
vector<edge> G[N];
int d[N], V;

void dij(int s) {
	priority_queue<P, vector<P>, greater<P> > q;
	fill(d, d + V, INF);
	d[s] = 0;
	q.push(P{s, 0});
	while(!q.empty()) {
		P t = q.top(); q.pop();
		int v = t.first;
		if(d[v] < t.second) continue;
		for(auto e : G[v]) {
			int to = e.to, w = e.w;
			if(d[to] > d[v] + w) {
				d[to] = d[v] + w;
				q.push(P{to, d[to]});
			}
		}
	}
}