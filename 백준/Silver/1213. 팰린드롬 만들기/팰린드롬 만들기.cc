#include <bits/stdc++.h>
using namespace std;
string s, temp, ret;
int cnt, a[26];

int main()
{
   cin >> s;
   for(char i : s)a[i - 65] += 1;
   for(int i = 'Z'; i >= 'A'; i--) {
      if(cnt > 1) break;
      if(a[i - 65]){
         for(int j = 0; j < a[i - 65] / 2; j++){
            ret = ret + (char) i;
            ret = (char) i + ret;
         }
      }
      if(a[i - 65] % 2 != 0){
         temp = (char) i;
         cnt++;
      }
   }
   if(cnt >  1)cout << "I'm Sorry Hansoo" << "\n";
   else {
      ret = ret.substr(0, ret.size() / 2) + temp + ret.substr(ret.size() / 2, ret.size());
      cout << ret << '\n';
   }
   return 0;
}
