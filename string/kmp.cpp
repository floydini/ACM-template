// S,T start from 0
// border[0,n] = [0,f[n])
int f[N];
void kmp(char *S, char *T) {
	int a = strlen(S), b = strlen(T);
	f[0] = 0;
	for(int i = 1, j = 0; i < b; i++) {
		while(j > 0 && T[i] != T[j]) j = f[j - 1];
		if(T[i] == T[j]) ++j;
		f[i] = j;
	}

	for(int i = 0, j = 0; i < a; i++) {
		while(j > 0 && S[i] != T[j]) j = f[j - 1];
		if(S[i] == T[j]) ++j;
		if(j == b) j = f[j - 1]; // S match T at i-b+1
	}
}
