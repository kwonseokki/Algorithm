#include <bits/stdc++.h>
using namespace std;
int n, m, j, ret, a;
pair<int, int> pos;

int main()
{  
   cin >> n >> m;
   cin >> j;
   pos.first = 0; pos.second = m - 1;
   while(j--){
      cin >> a;
      a -= 1;
      if(pos.second < a) {
         int move = a - pos.second;
         ret += move;
         pos.first += move;
         pos.second += move;
      } else if(pos.first > a){
         int move = pos.first - a;
         ret += move;
         pos.first -= move;
         pos.second -= move;
      }
   }

   cout << ret << '\n';
   return 0;
}