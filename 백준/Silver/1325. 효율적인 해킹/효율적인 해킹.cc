#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, ret;
vector<int> adj[100001];
int visited[100001];
vector<int> ret2;

int solve(int here){
    visited[here] = 1;
    int cnt = 1;
    for(int there : adj[here]){
        if(visited[there]) continue;        
        cnt += solve(there);
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        adj[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
       memset(visited, 0, sizeof(visited));
       if(!adj[i].size()) continue;
       int cnt2 = solve(i);
       if(ret < cnt2){
            ret = cnt2;
            ret2.clear();
            ret2.push_back(i);
       } else if(ret == cnt2){
            ret2.push_back(i);
       }
    }
    for(int i : ret2) cout << i << ' ';
    cout << '\n';
    return 0;
}
