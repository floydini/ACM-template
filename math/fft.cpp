const double PI = acos(-1.0);
struct Cp {
	double r, i;
	Cp() {}
	Cp(double x, double y): r(x), i(y) {}
};
Cp operator + (Cp &x, Cp &y) { return Cp(x.r + y.r, x.i + y.i); }
Cp operator - (Cp &x, Cp &y) { return Cp(x.r - y.r, x.i - y.i); }
Cp operator * (Cp &x, Cp &y) {
	return Cp(x.r * y.r - x.i * y.i, x.r * y.i + x.i * y.r);
}

void change(Cp y[], int len) {
	int t = len >> 1;
	for(int i = 1, j = t, k; i < len - 1; i++) {
		if(i < j) swap(y[i], y[j]);
		for(k = t; j >= k; k >>= 1) j -= k;
		j += k;
	}
}

void fft(Cp y[], int len, int on) {
	change(y, len);
	for(int i = 2; i <= len; i <<= 1) {
		double ang = 2.0 * on * PI / i;
		Cp wn = Cp(cos(ang), sin(ang));
		for(int j = 0; j < len; j += i) {
			Cp w = Cp(1.0, 0.0);
			for(int k = j; k < j + i / 2; k++) {
				Cp a = y[k];
				Cp b = y[k + i / 2] * w;
				y[k] = a + b;
				y[k + i / 2] = a - b;
				w = w * wn;
			}
		}
	}
	if(on == -1) for(int i = 0; i < len; i++) y[i].r = y[i].r / len;
}

// len = 2*\lceil n \rceil
// result is in y1
// y2 will be destructed
void sol(Cp y1[], Cp y2[], int len) {
	fft(y1, len, 1);
	if(y1 != y2) fft(y2, len, 1);
	for(int i = 0; i < len; i++) y1[i] = y1[i] * y2[i];
	fft(y1, len, -1);
}