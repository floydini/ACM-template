#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int pa[N];
void init(int n) { for(int i = 0; i <= n; i++) pa[i] = i; }
void findpa(int x) {return pa[x] == x ? x : pa[x] = findpa(pa[x]);}
int unite(int a, int b) {
	a = findpa(a), b = findpa(b);
	if(a == b) return -1;
	return pa[a] = b;
}

struct edge {int u, v, w;};
bool cmp(edge &a, edge&b) {return a.w < b.w;}
edge e[N];
int V;

int ST() { //min spanning tree
	sort(e, e + V, cmp);
	int ans = 0;
	for(int i = 0; i < V; i++) {
		if(unite(e.u, e.v) == -1) continue;
		ans += e.w;
	}
	return ans;
}