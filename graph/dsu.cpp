//O(nlgn)
//for(int i = 0; i < n; i++) par[i] = i;
int par[N];
void findp(int x) { return par[x] == x ? x : par[x] = find(par[x]); }
void merge(int x, int y) {
	x = findp(x), y = findp(y);
	if(x == y) return;
	par[y] = x;
}


//full version
//for(int i = 0; i < n; i++) par[i] = -1;
int par[N];
void findp(int x) { return par[x] < 0 ? x : par[x] = find(par[x]); }
void merge(int x, int y) {
	x = findp(x), y = findp(y);
	if(x == y) return;
	if(par[x] > par[y]) swap(x, y);
	par[x] += par[y];
	par[y] = x;
}