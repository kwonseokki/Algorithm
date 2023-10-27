#include<bits/stdc++.h>
using namespace std;
vector<char> v;
int n, cnt;
string s;
int main(){
   cin >> n;
   for(int i = 0; i < n; i++){      
      cin >> s;
      for(int i = 0; i < s.size(); i++){
         if(v.size() > 0 && v.back() == s[i]) v.pop_back();
         else v.push_back(s[i]);
      }
      if(v.size() == 0)cnt++;
      v.clear();
   }
   cout << cnt << "\n";
   return 0;
}