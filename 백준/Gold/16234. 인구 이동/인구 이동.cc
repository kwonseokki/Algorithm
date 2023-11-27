#include <bits/stdc++.h>
using namespace std;
int n, l, r, a[51][51], visited[51][51], ret, sum;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
vector<pair<int, int>> v;

void dfs(int y, int x, vector<pair<int, int>> &v){	
		for(int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) continue;
			int diff = abs(a[ny][nx] - a[y][x]);
			if(diff >= l && diff <= r){
			visited[ny][nx] = 1;
			v.push_back({ny, nx});
			sum += a[ny][nx];
			dfs(ny, nx, v);
			}
		}
	return;
}

void solve(){
	while(true){
		bool flag = 0;
		fill(&visited[0][0], &visited[0][0] + 51 * 51, 0); // 방문기록 초기화
		for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
		if(!visited[i][j]) {
		v.clear();
		v.push_back({i, j});
		visited[i][j] = 1;
		sum = a[i][j];
		dfs(i,j, v);
		if(v.size() == 1) continue;
		for(pair<int, int> p : v) {
			a[p.first][p.second] = sum / v.size();
			flag = 1;
		}
		}
		}
	}
		
	if(!flag)break;
	ret++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> l >> r;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}
	solve();
	cout << ret << '\n';
    return 0;
}
