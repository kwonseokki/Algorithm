#include <bits/stdc++.h>
using namespace std;
int N, a[101][101], visited[101][101], ret, max_h;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x, int max_h){
   visited[y][x] = 1;
   for(int i = 0; i < 4; i++){
      int ny = y +  dy[i];
      int nx = x +  dx[i];
      if(ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
      if(a[ny][nx] > max_h && !visited[ny][nx]) {
         dfs(ny, nx, max_h);
      }
   }
}

int main()
{
   cin >> N;
   for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
         cin >> a[i][j];
         if(a[i][j] > max_h) max_h = a[i][j];
      }
   }

   for(int i = 0; i <= max_h; i++){
      int cnt = 0;
      for(int j = 0; j < N; j++){
      for(int k = 0; k < N; k++){
         if(visited[j][k]) continue;
         else if(a[j][k] > i){
            dfs(j, k, i); cnt++;
         }
      }
   }
   if(ret < cnt) ret = cnt;
   for(int j = 0; j < N; j++){
      for(int k = 0; k < N; k++){
         visited[j][k] = 0;
      }
   }
   }
   cout << ret << '\n';
   return 0;
}