#include <bits/stdc++.h>
using namespace std;  
string s;

bool isVol(char c){
   if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {return true;}
   else {return false;}
}

int main () { 
	while(cin >> s){
      if(s == "end") break;
      bool is_vol = false;
      int m_cnt = 0, j_cnt = 0, prev = -1;
      
      for(int i = 0; i < s.size(); i++){
         if(isVol(s[i])) {m_cnt++; j_cnt = 0; is_vol = true;}
         else {j_cnt++; m_cnt = 0;}
      if(m_cnt >= 3 || j_cnt >= 3) break;
      if(i >= 1 && prev == s[i] && (s[i] != 'e' && s[i] != 'o')){
         is_vol = false;
         break;
      }
      prev = s[i];
      }
      if(!is_vol || m_cnt >= 3 || j_cnt >= 3) cout << "<" << s << ">" << " is not acceptable.\n";
      else cout << "<" << s << ">" << " is acceptable.\n";
   }
	return 0;
}