const int INF = 1 << 30;

int v[N], c[N]; // value, flag
void init(int n) {
	n <<= 2;
	fill(v, v + n, 0);
	fill(c, c + n, 0);
}
void up(int p) {
	v[p] = min(v[p << 1], v[p << 1 | 1]);
}
void down(int p) {
	if(c[p] == 0) return;
	v[p << 1] += c[p]; v[p << 1 | 1] += c[p];
	c[p << 1] += c[p]; c[p << 1 | 1] += c[p];
	c[p] = 0;
}
void put(int p, int l, int r, int x, int d) { // [x] = d
	if(l != r - 1) down(p);
	else {
		v[p] = d;
		return;
	}
	int mid = (l + r) / 2;
	if(x < mid) put(p << 1, l, mid, x, d);
	else put(p << 1 | 1, mid, r, x, d);
	up(p);
}
void segadd(int p, int l, int r, int x, int y, int d) { // [x,y) += d
	if(l != r - 1) down(p);
	if(x <= l && r <= y) {
		v[p] += d;
		c[p] += d;
		return;
	}
	int mid = (l + r) / 2;
	if(x < mid) segadd(p << 1, l, mid, x, y, d);
	if(y > mid) segadd(p << 1 | 1, mid, r, x, y, d);
	up(p);
}
int get(int p, int l, int r, int x, int y) {
	if(l != r - 1) down(p);
	if(x <= l && r <= y) return v[p];
	int a = INF, b = INF;
	int mid = (l + r) / 2;
	if(x < mid) a = get(p << 1, l, mid, x, y);
	if(y > mid) b = get(p << 1 | 1, mid, r, x, y);
	return min(a, b);
}