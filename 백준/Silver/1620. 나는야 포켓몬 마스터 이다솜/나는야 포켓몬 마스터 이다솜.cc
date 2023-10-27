#include<bits/stdc++.h>
using namespace std;
int n, m;
map<string, int> mp1;
map<int, string> mp2;
string s;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);
   cin >> n >> m;
   for(int i = 1; i <= n; i++){
      cin >> s;
      mp1.insert({s, i});
      mp2.insert({i, s});
   }
   for(int i = 0; i < m; i++){
      cin >> s;
      // 숫자인 경우
      if(atoi(s.c_str())){
         cout << mp2[stoi(s)] << "\n";
      }else{
         // 숫자가 아닌경우
         cout << mp1[s] << '\n';
      }
   }
   return 0;
}