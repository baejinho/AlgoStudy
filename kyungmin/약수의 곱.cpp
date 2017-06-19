#include <stdio.h>
#include <math.h>
const long long MOD = 1000000007;
int main(){
    long long n, ans, sqr;
    scanf("%lld", &n);
    sqr = sqrt(n);
    ans = 1;
    for(long long i = 1; i <= sqr; i++){
        if(n % i == 0) {
            ans *= i;
            ans %= MOD;
            if(i != sqr){
                ans *= (n / i);
                ans %= MOD;
            }
        }
    }
    printf("%lld\n", ans);

    return 0;
}