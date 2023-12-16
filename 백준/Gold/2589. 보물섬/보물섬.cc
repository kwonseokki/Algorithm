#include <bits/stdc++.h>
using namespace std;
int n, m, ret, visited[51][51];
char a[51][51];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void bfs(int y, int x){
    memset(visited, 0, sizeof(visited));
    visited[y][x] = 1;
    queue<pair<int, int>> q;
    q.push({y, x}); // 경로의 시작점
    while(q.size()){
        tie(y, x) = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            // 이동불가능한 영역
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue; 
            if(a[ny][nx] == 'W') continue;
            if(visited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x] + 1;
            ret = max(ret, visited[ny][nx]);
            q.push({ny, nx});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 'W') continue;
            bfs(i, j);
        }
    }
    cout << ret - 1 << '\n';
    return 0;
}
