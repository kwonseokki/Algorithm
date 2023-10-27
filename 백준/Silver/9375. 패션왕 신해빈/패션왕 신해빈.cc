#include<bits/stdc++.h>
using namespace std;
int TC, n;
string a, b;
map<string, int> mp;

int main(){
   cin >> TC;
   for(int i = 0; i < TC; i++){
      cin >> n;
      long long ret = 1;
      for(int i = 0; i < n; i++){
         cin >> a >> b;
         mp[b] += 1;
      }
      for(auto it : mp) ret *= it.second + 1;
      cout << ret - 1 << "\n";
      mp.clear();
   }
   
   return 0;
}