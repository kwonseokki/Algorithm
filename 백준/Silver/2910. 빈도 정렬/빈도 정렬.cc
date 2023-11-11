#include<bits/stdc++.h> 
using namespace std;
int n, c, a;
vector<int> v;
map<int, int> mp;
map<int, int> mp2;

bool cmp(int a, int b) {
   if(mp[a] == mp[b]){
      return mp2[a] < mp2[b];
   }
   return mp[a] > mp[b];
}

int main() {
   cin >> n >> c;
   for(int i = 0; i < n; i++){
      cin >> a;
      v.push_back(a);
      mp[a] += 1;
      auto it = mp2.find(a);
      if(it != mp2.end()) continue;
      mp2[a] = i;
   }
   sort(v.begin(), v.end(), cmp);
   for(int i : v) cout << i << " ";
   cout << '\n';
   return 0;
}