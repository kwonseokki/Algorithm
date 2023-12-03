#include <bits/stdc++.h> 
using namespace std;
int n, k, visited[100001];
long long check[100001];

void solve(int start){
	visited[start] = 1;
	check[start] = 1;
	queue<int> q;
	q.push(start);
	while(q.size()){
		int start = q.front(); q.pop();
		for(int next : {start + 1, start -1, start * 2}){
			if(next >= 0 && next <= 100000){
				if(!visited[next]){
					q.push(next);
					visited[next] = visited[start] + 1;
					check[next] += check[start];
				} else if(visited[next] == visited[start] + 1){
					check[next] += check[start];
				}
			}
		}
	}
}

int main() {
	cin >> n >> k;
	if(n == k){
		cout << 0 << '\n';
		cout << 1 << '\n';
		return 0;
	}
	solve(n);
	cout << visited[k] - 1 << '\n';
	cout << check[k] << '\n';
    return 0;
}
