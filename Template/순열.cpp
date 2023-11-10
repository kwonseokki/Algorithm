#include <bits/stdc++.h>
using namespace std;
int a[3] = {1, 2, 3};
int n = 3, r = 3;

void print(){
   for(int i : a) cout << i << ' ';
   cout << '\n';
}

void makePermutaion(int n, int r, int depth){
   if(depth == r){
      print();
      return;
   }

   for(int i = depth; i < n; i++){
      swap(a[i], a[depth]); 
      makePermutaion(n, r, depth + 1);
      swap(a[i], a[depth]);
   }
}

int main()
{
   makePermutaion(n, r, 0);
   return 0;
}
