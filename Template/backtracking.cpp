#include<bits/stdc++.h>
using namespace std; 
int n, temp, ret;
vector<int> v;   
const int mod = 11;
int cnt = 0;
// 백트래킹 = 완전탐색 + 가지치기
void go(int idx, int sum){
	if(ret == 10) return; // ret은 10보다 클 수 없기때문에 더이상의 탐색 하지않는다.
	if(idx == n){
		ret = max(ret, sum % mod); 
		cnt++;
		return;
	}
	go(idx + 1, sum + v[idx]);
	go(idx + 1, sum);
}
int main() {
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> temp;
		v.push_back(temp);
	}
	go(0, 0);
	cout << ret << "\n"; 
	cout << cnt << "\n";
	return 0; 
}