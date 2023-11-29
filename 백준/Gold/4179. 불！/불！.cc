#include <bits/stdc++.h>
using namespace std;
const int INF = 99999999;
int r, c, sy, sx, person[1001][1001], fire[1001][1001], ret, y, x;
char a[1001][1001];
int dy[] = {-1, 0, 1, 0}; int dx[] = {0, 1, 0, -1};

void spread_fire(queue<pair<int, int>> q){
	while(q.size()){
		tie(y, x) = q.front(); q.pop();
		for(int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
			if(fire[ny][nx] != INF || a[ny][nx] == '#') continue;
			fire[ny][nx] = fire[y][x] + 1;
			q.push({ny, nx});
		}
	}
	return;
}

void find_exit(queue<pair<int, int>> q){
	while(q.size()){
		tie(y, x) = q.front(); q.pop();
		if(y == 0 || x == 0 || y == r - 1 || x == c - 1){
			ret = person[y][x];
			break;
		}
		for(int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
			if(person[ny][nx]) continue;
			if(a[ny][nx] == '#') continue;
			if(person[y][x] + 1 >= fire[ny][nx]) continue;
			person[ny][nx] = person[y][x] + 1;
			q.push({ny, nx});
		}

	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> r >> c;
	queue<pair<int, int>> q;
	fill(&fire[0][0], &fire[0][0] + 1001 * 1001, INF);
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cin >> a[i][j];
			if(a[i][j] == 'J'){sy = i; sx = j;}
			if(a[i][j] == 'F'){
				fire[i][j] = 1;
				q.push({i, j});
			}
		}
	}
	spread_fire(q);
	person[sy][sx] = 1;
	queue<pair<int, int>> q2;
	q2.push({sy, sx});
	find_exit(q2);
	if(ret != 0) cout << ret << '\n';
	else cout << "IMPOSSIBLE" << '\n';
    return 0;
}
