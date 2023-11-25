#include <bits/stdc++.h>
using namespace std;
int n, m, visited[51][51], ret;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
char a[51][51];

void bfs(pair<int, int> here){
	memset(visited, 0, sizeof(visited)); 
	visited[here.first][here.second] = 1;
	queue<pair<int, int>> q;
	q.push(here);
	while(q.size()){
		int y, x;
		tie(y, x) = q.front(); q.pop();
		for(int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
			if(visited[ny][nx]) continue;
			if(a[ny][nx] == 'W') continue;
			visited[ny][nx] = visited[y][x] +1;
			q.push({ny, nx});
			ret = max(ret, visited[ny][nx]);
		}
	}
	return;
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] == 'L') bfs({i, j});
		}
	}
	cout << ret - 1 << '\n';
    return 0;
}
