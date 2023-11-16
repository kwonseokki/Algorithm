#include <bits/stdc++.h>
using namespace std;
const int n = 5;
int cnt, a[n][n], visited[n][n];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x){
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if(!a[ny][nx]) continue;
        if(visited[ny][nx]) continue;
        dfs(ny, nx);
    }
}

int main(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j] && a[i][j]){
                dfs(i, j); cnt++;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}