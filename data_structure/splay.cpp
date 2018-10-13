int p[N], key[N], ch[N][2], root, tot;
int sz[N], f[N]; // subtree size, flip lazy flag.

void up(int x) {
	sz[x] = sz[ch[x][0]] + sz[ch[x][1]];
}

inline void flip(x) { f[x] ^= 1;}

void down(int x) {
	if(f[x] == 0) return;
	if(ch[x][0]) flip(ch[x][0]);
	if(ch[x][1]) flip(ch[x][1]);
	swap(ch[x][0], ch[x][1]);
	f[x] = 0;
}

void newnode(int &x, int fa, int k) {
	x = ++tot;
	p[x] = fa;
	key[x] = k;
	ch[x][0] = ch[x][1] = 0;
//	sz[x]=1;
//	f[x]=0;
}

void rise(int x) {
	int y = p[x], c = ch[y][0] == x;
	down(y), down(x);
	ch[y][!c] = ch[x][c];
	p[ch[x][c]] = y;
	if(p[y]) ch[p[y]][ch[p[y]][1] == y] = x;
	p[x] = p[y];
	ch[x][c] = y;
	p[y] = x;
	up(y), up(x);
}

void splay(int x, int goal) { // make p[x]=goal
	for(int y; (y = p[x]) != goal; rise(x))
		if(p[y] != goal) rise(ch[y][ch[p[y]][0] == y] == x ? x : y);
	if(goal == 0) root = x;
}

void insert(int k) { // first node: newnode(root,0,k);
	int x = root;
	while(ch[x][key[x] < k]) x = ch[x][key[x] < k];
	newnode(ch[x][key[x] < k], x, k);
	splay(ch[x][key[x] < k], 0);
}

int kth(int x, int k) {
	while(k) {
		if(sz[ch[x][0]] >= k) x = ch[x][0];
		else if(sz[ch[x][0]] + 1 < k) {
			x = ch[x][1];
			k -= sz[ch[x][0]] + 1;
		} else break;
	}
	splay(x, 0);
	return x;
}

int pre() {
	int x = ch[root][0];
	while(ch[x][1]) x = ch[x][1];
	return x;
}

int suc() {
	int x = ch[root][1];
	while(ch[x][0]) x = ch[x][0];
	return x;
}