#include <stdio.h>
#include <stack>
using namespace std;

const long long MOD = 1000000007;
stack<long long> st;
long long power(long long n, long long p){
    if(p == 0)  return 1;
    if(p & 1)   return (n * power(n, p - 1)) % MOD;
    return power(n * n, p / 2) % MOD;
}
int main(){
    long long n, n1, n2;
    scanf("%lld", &n);
    for(long long i = 0; i < n; i++){
        scanf("%lld", &n1);
        st.push(n1);
    }
    while(st.size() > 1){
        n1 = st.top();
        st.pop();
        n2 = st.top();
        st.pop();
        st.push(power(n1, n2));
    }
    printf("%lld\n", st.top());
    return 0;
}
