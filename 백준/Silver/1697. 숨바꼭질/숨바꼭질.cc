#include <bits/stdc++.h> 
using namespace std;
int n, k, a[3] = {1, -1, 0}, visited[100001];

int solve(int start){
	visited[start] = 1;
	queue<int> q;
	q.push(start);
	while(q.size()){
		if(visited[k]) break;
		int start = q.front(); q.pop();
		for(int i = 0; i < 3; i++){
			if(!a[i]){
				if(start * 2 < 0 || start * 2 > 100000 || visited[start * 2]) continue;
				visited[start * 2] = visited[start] + 1;
				q.push(start * 2);
			} else{
				if(start + a[i] < 0 || start + a[i] > 100000 || visited[start + a[i]]) continue;
				visited[start + a[i]] = visited[start] + 1;
				q.push(start + a[i]);
			}
		}
	}
	return visited[k] - 1;
}

int main() {
	cin >> n >> k;
	cout <<  solve(n) << "\n";
    return 0;
}
