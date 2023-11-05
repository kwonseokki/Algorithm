#include <bits/stdc++.h>
using namespace std;
int M, N, K, a[101][101], visited[101][101], ret;
vector<int> ret2;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x){
   visited[y][x] = 1;
   ret2[ret2.size() - 1] += 1; 
   for(int i = 0; i < 4; i++){
      int ny = y + dy[i];
      int nx = x + dx[i];
      if(ny < 0 || nx < 0 || ny >= M || nx >= N){ continue; }
      if(a[ny][nx] == 0 && !visited[ny][nx]){
       dfs(ny, nx);
      }
   }
}

int main()
{
   cin >> M >> N >> K;
   for(int i = 0; i < K; i++){
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      // 정사각형이 그려진 부분의값을 바꾸기
      for(int j = 0; j < M; j++){
         for(int k = 0; k < N; k++){                
         if (j >= M - y2 && k >= x1 && j <= M - y1 - 1 && k <= x2 - 1){
            a[j][k] = 1;
      }
         }
      }
   }
   for(int i = 0; i < M; i++){
      for(int j = 0; j < N; j++){
         if(visited[i][j] || a[i][j]){
            continue;
         } else{
            ret2.push_back(0);
            dfs(i, j);  ret++;
         }
      }
   }
   cout << ret << '\n';
   sort(ret2.begin(), ret2.end());
   for(int i : ret2) cout << i << ' ';
   cout << '\n';
   return 0;
}