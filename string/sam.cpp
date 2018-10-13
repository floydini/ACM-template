const int N = 250000 + 5;
const int NN = N << 1;
int go[NN][26], len[NN], fa[NN], tot = 1, root = 1, last = 1;
void app(int x) {
	int p = last, s = last = ++tot; len[s] = len[p] + 1;
	for(; p && !go[p][x]; p = fa[p]) go[p][x] = s;
	if(p) {
		int q = go[p][x];
		if(len[q] != len[p] + 1) {
			int nq = ++tot;	len[nq] = len[p] + 1; fa[nq] = fa[q];
			memcpy(go[nq], go[q], sizeof(go[q]));
			fa[q] = fa[s] = nq;
			for(; p && go[p][x] == q; p = fa[p]) go[p][x] = nq;
		} else fa[s] = q;
	} else fa[s] = root;
}