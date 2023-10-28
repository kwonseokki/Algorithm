#include<bits/stdc++.h>
using namespace std;
string s, ret, temp;
int cnt[123], flag;

int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> s;
   for(int ch : s)cnt[ch]++;
   for(int i = 'Z'; i >= 'A'; i--){
      if(cnt[i]){
         // 홀수인경우
        if(cnt[i] & 1){
            temp = i;
            cnt[i]--;
            flag++;
        }
        // 홀수가 2개인 경우 팰린드롬이 아님
        if(flag >= 2) break;
      }
      // 문자열 합치기
      for(int j = 0; j < cnt[i]; j += 2){
         ret = ret + (char) i;
         ret = (char) i + ret;
      }
   }
   // 홀수개 문자열이 1개인경우 합치기
   if(temp.size() != 0){
      ret = ret.substr(0, ret.size() / 2) + temp + ret.substr(ret.size() / 2);
   }
   if(flag >= 2) cout << "I'm Sorry Hansoo" << "\n";
   else cout << ret << '\n';
   return 0;
}