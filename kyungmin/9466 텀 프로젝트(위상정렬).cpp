#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
int G[100000];
int indegree[100000];
queue<int> q;
int main(){
    int T, N, u, cnt;
    scanf("%d", &T);
    for(int t = 0; t < T; t++){
        scanf("%d", &N);
        cnt = 0;
        memset(indegree, 0, sizeof(indegree));
        for(int i = 0; i < N; i++){
            scanf("%d", &G[i]);
            indegree[--G[i]]++;
        }
        for(int i = 0; i < N ;i++){
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty()){ 
            indegree[G[q.front()]]--;
            if(indegree[G[q.front()]] == 0)
                q.push(G[q.front()]);
            q.pop();
            cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}