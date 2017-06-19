#include <stdio.h>
const long long MOD = 1000000007;
long long P[2000001];
long long Pow(long long n, long long p){
    long long ret = 1;
    while(p){
        if(p & 1) ret = (ret * n) % MOD;
        n = (n * n) % MOD;
        p >>= 1;
    }
    return ret % MOD;
}
int main(){
    long long n, t, sub = 0;
    scanf("%lld", &n);
    for(long long i = 1; i <= n; i++) {
        scanf("%lld", &t);
        P[t]++;
        if(P[t] > 1) sub++;
    }
    long long ans = 0, add, mul = Pow(2, n - sub - 1);
    for(int i = 0; i <= 2000000 && mul >= 1; i++) {
        if(P[i] >= 1) {
            ans %= MOD;
            add = (mul * P[i]) % MOD;
            ans += add;
            ans %= MOD;
            mul /= 2;
        }
    }
    printf("%lld\n", ans);
    return 0;
}