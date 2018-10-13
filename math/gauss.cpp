const double eps = 1e-8;
double a[MAXN][MAXN];
void Gauss(int n, int m) {
	int r, c, k;
	for(r = c = 0; r < n && c < m; r++, c++) {
		for(k = r; k < n; k++) if(fabs(a[k][c]) > eps) break;
		if(r == n) continue;
		if(k != r) for(int j = 0; j <= m; j++) swap(a[k][j], a[r][j]);
		for(int j = c + 1; j <= m; j++) a[r][j] /= a[r][c];
		a[r][c] = 1.0;
		for(int i = 0; i < n; i++) {
			if(i == r || fabs(a[i][c]) < eps) continue;
			for(int j = c + 1; j <= m; j++) a[i][j] -= a[i][c] * a[r][j];
			a[i][c] = 0.0;
		}
	}
}
