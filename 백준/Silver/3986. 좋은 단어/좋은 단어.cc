#include<bits/stdc++.h>
using namespace std;
int n, ret;
string s;

int main(){
   ios_base::sync_with_stdio(false);
	cin.tie(NULL);
   cin >> n;
   for(int i = 0; i < n; i++){
      stack<char> stk;
      cin >> s;
      for(int j = 0; j < s.size(); j++){
         if(stk.size() && stk.top() == s[j])stk.pop();
         else stk.push(s[j]);
      }
      if(stk.size() == 0) ret++;
   }
   cout << ret << "\n";
   return 0;
}