#include <bits/stdc++.h>
using namespace std;
int TC, M, N, K, ret, a[2501][2501], visited[2501][2501];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x)
{
   for (int i = 0; i < 4; i++)
   {
      int ny = y + dy[i];
      int nx = x + dx[i];
      // 범위를 초과할때
      if (ny < 0 || nx < 0 || ny >= M || nx >= N)
      {
         continue;
      }

      if (a[ny][nx] == 0 || visited[ny][nx])
      {
         continue;
      }

      visited[ny][nx] = 1;
      dfs(ny, nx);
   }
   return;
}

int main()
{
   cin >> TC; // 테스트 케이스만큼 반복
   for (int i = 0; i < TC; i++)
   {
      cin >> M >> N >> K;
      // K만큼 반복하면서 리스트에 데이터 추가
      for (int j = 0; j < K; j++)
      {
         int x, y;
         cin >> x >> y;
         a[x][y] = 1;
      }
      ret = 0;

      for (int i = 0; i < M; i++)
      {
         for (int j = 0; j < N; j++)
         {
            if (visited[i][j])
            {
               continue;
            }
            else if (a[i][j])
            {

               dfs(i, j);
               ret++;
            }
         }
      }
      cout << ret << '\n';
      for(int i = 0; i < M; i++){
         for(int j = 0; j < N; j++){
            a[i][j] = 0; visited[i][j] = 0;
         }
      }
   }
   return 0;
}