#include <bits/stdc++.h>
using namespace std; 
int n, m, ret, a[101][101], visited[101][101];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
vector<pair<int,int>> v;

void dfs(int y, int x){
	visited[y][x] = 1;
	// 값이 1이라면 더이상 탐색하지 않고 벡터에 좌표정보만 넣는다
	if(a[y][x]){
		v.push_back({y, x});
		return;
	}
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
		dfs(ny, nx);
	}
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}

	while(true){
		fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
		v.clear();
		dfs(0, 0);
		for(auto it : v){
			a[it.first][it.second] = 0;
		}
		bool flag = 0;
		for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j]){
				flag = 1;
				break;
			}
		}
	}
	ret++;
	if(!flag) break;
	}
	cout << ret << '\n';
	cout << v.size() << '\n';
	return 0;
}