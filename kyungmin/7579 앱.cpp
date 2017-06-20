#include <stdio.h>
int m[101], c[101], dp[10001]; 
int N, M, i, j, size;
int main(){
    scanf("%d %d", &N, &M);
    for(i = 1; i <= N; i++) scanf("%d", &m[i]);
    for(i = 1; i <= N; i++) {
        scanf("%d", &c[i]);
        size += c[i];
    }
    for(i = 1; i <= N; i++){
        for(j = size - c[i]; j >= 0; j--)
            if(dp[j + c[i]] < dp[j] + m[i] && dp[j + c[i]] < M) dp[j + c[i]] = dp[j] + m[i];
    }
    for(i = 0; i <= size; i++) if(dp[i] >= M) break;
    printf("%d\n", i);
    return 0;
}