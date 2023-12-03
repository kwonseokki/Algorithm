#include <bits/stdc++.h> 
using namespace std;
int n, k, visited[200001], _prev[200001];
vector<int> cache;

void solve(int start){
	visited[start] = 1;
	queue<int> q;
	q.push(start);
	while(q.size()){
		int start = q.front(); q.pop();
		for(int next : {start + 1, start - 1, start * 2}){
			if(next >= 0 && next <= 100000){
				if(!visited[next]){
				q.push(next);
				visited[next] = visited[start] + 1;
				_prev[next] = start;
			}
			}
		}
	}
}

int main() {
	cin >> n >> k;
	if(n == k){
		cout << 0 << '\n';
		cout << n << '\n';
		return 0;
	}
	solve(n);
	for(int i = k; i != n; i = _prev[i]){
		cache.push_back(i);
	}
	cache.push_back(n);
	reverse(cache.begin(), cache.end());
	cout << visited[k] - 1 << '\n';
	for(int i : cache) cout << i << " ";
	cout << '\n';
    return 0;
}
