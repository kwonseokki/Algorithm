#include<bits/stdc++.h>
using namespace std;
string str;
int a[26];

int main(){
   cin >> str;
   for(char ch : str) a[ch - 'a'] += 1;
   for(int i : a) cout << i << " ";
   cout << '\n';
   return 0;
}