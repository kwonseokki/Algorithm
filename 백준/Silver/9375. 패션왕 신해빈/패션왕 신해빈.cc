#include <bits/stdc++.h>
using namespace std;
int T, n;
map<string, int> mp;
int main()
{
   cin >> T;
   for(int i = 0; i < T; i++){
      cin >> n;
      for(int j = 0; j < n; j++){
         string k, v;
         cin >> k >> v;
         mp[v] += 1;
      }
      int ret = 1;
      for(auto it : mp) ret *= it.second + 1;
      cout << ret - 1 << '\n';
      mp.clear();
   }
   return 0;
}
