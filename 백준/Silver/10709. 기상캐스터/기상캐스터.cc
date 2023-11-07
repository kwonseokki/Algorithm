#include <bits/stdc++.h>
using namespace std;
int n, m, a[101][101];
char c;

int main()
{
   cin >> n >> m;
   for (int i = 0; i < n; i++)
   {
      bool flag = false;
      int cnt = 1;
      for (int j = 0; j < m; j++)
      {
         cin >> c;
         if (c == 'c')
         {
            flag = true;
            a[i][j] = 0;
            cnt = 1;
         }
         else if (!flag && c == '.')
            a[i][j] = -1;
         else if (flag && c == '.')
         {
            a[i][j] = cnt;
            cnt++;
         }
      }
   }
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         cout << a[i][j] << ' ';
      }
      cout << '\n';
   }
   return 0;
}