#include <bits/stdc++.h>
using namespace std;
int n, _index, root, _remove;
vector<int> adj[51];

int dfs(vector<int> here){
    if(here.size() == 1 && _remove == here[0]) return 1;
    if(!here.size()) return 1;
    int ret = 0;
    for(int there: here){
        if(there == _remove) continue;
        ret += dfs(adj[there]);
    }
    return ret;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> _index;
        if(_index == -1) {
            root = i; 
            continue;
            }
        adj[_index].push_back(i);
    }
    cin >> _remove;
    if(_remove == root) cout << 0 << '\n';
    else cout << dfs(adj[root]) << '\n';
    return 0;
}
