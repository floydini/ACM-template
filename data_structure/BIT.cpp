int a[N];
void add(int x, int v) {
	for(; x <= n; x += x & -x) a[x] += v;
}
int get(int x) {
	int ans = 0;
	for(; x; x -= x & -x) ans += a[x];
	return ans;
}