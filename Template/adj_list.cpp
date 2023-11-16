#include <bits/stdc++.h>
using namespace std;
// const int V = 4;
// vector<int> adj[V];
// int main(){
//     adj[0].push_back(1);
//     adj[0].push_back(2);
//     adj[0].push_back(3);

//     adj[1].push_back(0);
//     adj[1].push_back(2);

//     adj[2].push_back(0);
//     adj[2].push_back(1);

//     adj[3].push_back(0);

//         for(int i = 0; i < 4; i++){
//         cout << i << " :: ";
//         for(int there : adj[i]){
//             cout << there << " ";
//         }
//         cout << '\n'; 
//     }

//       for(int i = 0; i < 4; i++){
//         cout << i << " :: ";
//         for(int j = 0; j < adj[i].size(); j++){
//             cout << adj[i][j] << " ";
//         } 
//         cout << '\n'; 
//     }
//    return 0;
// }

const int V = 10;
vector<int> adj[V];
int visited[V];

void go(int from){
    visited[from] = 1;
    cout << from << '\n';
    for(int there : adj[from]){
        if(visited[there]) continue;
        go(there);
    }
    return;
}

int main(){
    adj[1].push_back(2);
    adj[1].push_back(3); 

    adj[2].push_back(1);

    adj[3].push_back(1);
    adj[3].push_back(4);

    adj[4].push_back(3); 
    for(int i = 0; i < V; i++){
        if(adj[i].size() && !visited[i]) go(i);
    }
    return 0;
}