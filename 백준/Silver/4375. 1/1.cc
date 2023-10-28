#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int main(){
   while(scanf("%d", &n) != EOF) {
      int cnt = 1, ret = 1;
      while(true){
         if(cnt % n == 0){
            // cnt 를 n 으로 나눈 결과가 0 이라면 자릿수(ret)을 출력
            printf("%d\n", ret);
            break;
         }else{
            cnt = (cnt * 10) + 1;
            cnt %= n;
            ret ++;
         }
      }
   }
   return 0;
}