#include<bits/stdc++.h>
using namespace std;
int n, m, ret, a[10][10], tmp[10][10], visited[10][10];
int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
vector<pair<int, int>> a_list, v_list;

void dfs(int y, int x){
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		// 벽으로 세워져있거나 방문한경우 바이러스를 퍼트릴 수 없음
		if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if(visited[ny][nx]) continue;
		if(a[ny][nx] == 1) continue;
		visited[ny][nx] = 1;
		dfs(ny, nx);
	}
}

int solve(){
	fill(&visited[0][0], &visited[0][0] + 10 * 10, 0);
	// {y, x} 형식으로 담긴 바이러스 퍼트리기
	for(auto b : v_list){
		visited[b.first][b.second] = 1;
		dfs(b.first, b.second);
	}

	int cnt = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			// 바이러스가 퍼지지 않은지역 카운트
			if(a[i][j] == 0 && !visited[i][j])cnt++;
		}
	}
	return cnt;
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
			if(a[i][j] == 0) a_list.push_back({i, j});
			if(a[i][j] == 2) v_list.push_back({i, j});
		}
	}
	
	// 벽세우기
	for(int i = 0; i < a_list.size(); i++){
		for(int j = 0; j < i; j++){
			for(int k = 0; k < j; k++){
				a[a_list[i].first][a_list[i].second] = 1;
				a[a_list[j].first][a_list[j].second] = 1;
				a[a_list[k].first][a_list[k].second] = 1;
				ret = max(ret, solve());
				a[a_list[i].first][a_list[i].second] = 0;
				a[a_list[j].first][a_list[j].second] = 0;
				a[a_list[k].first][a_list[k].second] = 0;
			}
		}
	}
	cout << ret << '\n';
    return 0;
}
