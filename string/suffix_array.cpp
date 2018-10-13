// O(nlogn)
// note: string a[] start from 1

int sa[N], rk[N], r[N], h[N], c[N], a[N], n, m;

int cmp(int *f, int x, int y, int w) { return f[x] == f[y] && f[x + w] == f[y + w]; }

void rsort() {
	for(int i = 0; i <= m; i++) c[i] = 0;
	for(int i = 1; i <= n; i++) c[rk[r[i]]]++;
	for(int i = 1; i <= m; i++) c[i] += c[i - 1];
	for(int i = n; i >= 1; i--) sa[c[rk[r[i]]]--] = r[i];
}
void suffix() {
	//SA
	for(int i = 1; i <= n; i++) rk[i] = a[i], r[i] = i;
	rsort();
	for(int w = 1, p = 1, i; p < n; w <<= 1, m = p) {
		for(p = 0, i = n - w + 1; i <= n; i++) r[++p] = i;
		for(i = 1; i <= n; i++) if(sa[i] > w) r[++p] = sa[i] - w;

		rsort(), swap(rk, r), rk[sa[1]] = p = 1;
		for(i = 2; i <= n; i++) rk[sa[i]] = cmp(r, sa[i], sa[i - 1], w) ? p : ++p;
	}
	//height
	int j, k = 0;
	for(int i = 1; i <= n; h[rk[i++]] = k)
		for(k = k ? k - 1 : k, j = sa[rk[i] - 1]; a[i + k] == a[j + k]; ++k);
}