#include <bits/stdc++.h>
using namespace std;
int n, r, root, visited[51];
vector<int> adj[51];

int dfs(int here){
    if(adj[here].size() == 1 && r == adj[here][0]) return 1;
    if(r == here) return 0;
    if(adj[here].size() == 0) return 1;
    visited[here] = 1;
    int ret = 0;
    for(int there: adj[here]){
        if(there == r || visited[there]) continue;
        ret += dfs(there);
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        int index;
        cin >> index;
        adj[index].push_back(i);
        if(index == -1) root = i;
    }
    cin >> r;
    cout << dfs(root) << '\n';
    return 0;
}