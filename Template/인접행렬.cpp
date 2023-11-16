#include <bits/stdc++.h>
using namespace std;
const int V = 10;
bool a[V][V], visited[V];
// 0번부터 방문안한 노드를 찾고 해당 노드부터 방문처리를 하고 연결된 노드를 이어서 방문하여 출력하는 재귀함수를 구현

void go(int from){
    visited[from] = 1; 
    cout << from << '\n';
    for(int i = 0; i < V; i++){
        if(visited[i]) continue;
        if(a[from][i]) {
            go(i);
        }
    }
    return;
}

int main(){
    // 그래프의 관계를 1과 0으로 나타냄
    a[1][2] = 1; a[1][3] = 1; a[3][4] = 1;
	a[2][1] = 1; a[3][1] = 1; a[4][3] = 1;
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            if(a[i][j] && !visited[i]){
                go(i);
            }
        }
    }
}