#include <bits/stdc++.h>
using namespace std;
const int n = 6;
vector<int> adj[n];
int visited[n];

// 확인하고 노드를 방문하는 방식
// 노드를 방문하기 전에 확인해주는 방식
// void dfs(int u){
//     visited[u] = 1;
//     cout << u << "\n";
//     for(int i : adj[u]){
//         if(visited[i]) continue;
//         dfs(i);
//     }
//     cout << u << "로부터 시작된 함수가 종료되었습니다.\n";
//     return;
// }

// 무조건 노드를 방문하는 방식
// 무조건 방문을 하고 visited를 확인해서 리턴하는 방식
void dfs(int u){
    if(visited[u]) return;
    visited[u] = 1;
    for(int i : adj[u]){
        dfs(i);
    }
    return;
}

int main(){
    adj[1].push_back(2);
    adj[1].push_back(3); 
    adj[2].push_back(4);  
    adj[4].push_back(2);  
    adj[2].push_back(5);   
    dfs(1);
    return 0;
}