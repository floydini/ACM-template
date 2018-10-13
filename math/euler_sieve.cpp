bool flag[MAXN];
int p[MAXN];
int sieve_euler(int n) {
	int t = 0;
	for(int i = 2; i <= n; i++) {
		if(!used[i]) p[t++] = i;
		for(int j = 0; p[j]*i <= n; j++) {
			used[p[j]*i] = true;
			if(i % p[j] == 0) break;
		}
	}
	return t;
}