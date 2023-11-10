#include <bits/stdc++.h>
using namespace std;
int n = 5; int k = 3;

void print(vector<int> v){
   // 0부터 순서대로 조합을 출력
   for(int i : v) cout << i << ' ';
   cout << '\n';
}

void combi(int start, vector<int> b){
   // 벡터의 크기가 뽑으려는 조합의 수와 같을떄 종료
   if(b.size() == k){
      print(b);
      return;
   }
   // start + 1 을 해줘야 중복되는 숫자를 고르지 않는다.
   for(int i = start + 1; i < n; i++){
      b.push_back(i);
      combi(i, b);
      b.pop_back();
   }
   return;
}

int main()
{
   vector<int> b;
   combi(-1, b);
   return 0;
}
