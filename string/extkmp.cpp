// S,T start from 0
// f[i]: T[i,f[i]+i) match T[0,f[i])
// g[i]: S[i,g[i]+i) match T[0,g[i])
int f[N], g[N];
void extkmp(char *S, char *T) {
	int a = strlen(S), b = strlen(T);
	f[0] = 0;
	for(int i = 1, l = 1, r = 1; i < b; i++) {
		if(f[i - l] >= r - i) {
			l = i, r = max(l, r);
			while(r < b && T[r] == T[r - i]) r++;
			f[i] = r - l;
		} else f[i] = f[i - l];
	}

	for(int &i = g[0] = 0; i < a && i < b && S[i] == T[i]; i++);
	for(int i = 1, l = 0, r = g[0]; i < a; i++) {
		if(f[i - l] >= r - i) {
			l = i, r = max(l, r);
			while(r < a && S[r] == T[r - i]) r++;
			g[i] = r - l;
		} else g[i] = f[i - l];
	}
}
