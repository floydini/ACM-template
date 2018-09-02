int siz, u[2 * N];
void init(int n) { // [0, n)
	siz = n;
	fill(u, u + 2 * siz, 0);
}
void put(int p, int v) { // [p] = v
	for(p += siz, u[p] += v; p > 1; p >>= 1) u[p >> 1] += v;
}
int get(int l, int r) { // [l, r)
	int res = 0;
	for(l += siz, r += siz; l < r; l >>= 1, r >>= 1) {
		if(l & 1) res += u[l++];
		if(r & 1) res += u[--r];
	}
	return res;
}