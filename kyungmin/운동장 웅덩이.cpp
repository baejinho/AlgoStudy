#include <stdio.h>

char Map[102][102];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
void dfs(int x, int y){
    Map[x][y] = 'x';
    for(int i = 0; i < 4; i++){
        int tx = x + dx[i];
        int ty = y + dy[i];
        if(Map[tx][ty] != '#') continue;
        dfs(tx, ty);
    }
}
int main(){
    int r, c, ccNm = 0;
    scanf("%d %d", &r, &c);
    for(int i = 1; i <= r; i++) for(int j = 1; j <= c; j++) scanf(" %1c", &Map[i][j]);
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++) {
            if(Map[i][j] != '#') continue;
            dfs(i, j);
            ccNm++;  
        }
    }
    printf("%d\n", ccNm);
    return 0;
}