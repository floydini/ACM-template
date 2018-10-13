bool ptest(LL x, LL n) {
    LL i = n - 1, ans = 1;
    while(i) {
        if(i & 1) ans = (ans * x) % n;
        if((x * x) % n == 1 && x != 1 && x != n - 1) return false;
        x = (x * x) % n;
        i = i >> 1;
    }
    if(ans == 1) return true;
    return false;
}
