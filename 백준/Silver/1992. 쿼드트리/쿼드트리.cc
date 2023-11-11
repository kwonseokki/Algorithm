#include<bits/stdc++.h> 
using namespace std;
int n;
char a[65][65];

string quard(int y, int x, int size){
   if(size == 1) return string(1, a[y][x]);
   char b = a[y][x];
   string ret = "";
   // 0과 1이 틀린경우 ret을 완성하고 함수는 리턴된다.
   for(int i = y; i < y + size; i++){
      for(int j = x; j < x + size; j++){
         if(b != a[i][j]){ 
            ret += "(";
            ret += quard(y, x, size / 2);
            ret += quard(y, x + size / 2, size / 2);
            ret += quard(y + size / 2, x, size / 2);
            ret += quard(y + size / 2, x + size / 2, size / 2);
            ret += ")";
            return ret;
         }
      }
   }

   return string(1, a[y][x]); // 순수한 0과 1인경우
}

int main() {
   cin >> n;
   for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
         cin >> a[i][j];
      }
   }
   cout << quard(0, 0, n) << "\n";
   return 0;
}