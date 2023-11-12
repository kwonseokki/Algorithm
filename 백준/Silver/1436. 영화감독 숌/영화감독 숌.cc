#include<bits/stdc++.h>
using namespace std;
int n, ret = 665, cnt;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	while(true){
		ret++;
		string s = to_string(ret);
		int cnt2 = 0, prev = -1;
		for(int i = 0; i < s.size(); i++){
			if(cnt2 >= 2) break;
			int idx = i;
			if(i > 0 && s[idx] == '6' && s[prev] == '6'){ cnt2++;}
			else {cnt2 = 0;}
			prev = idx;
		}
		if(cnt2 >= 2) cnt++;
		if(cnt == n) {
			cout << ret << '\n'; 
			break;
		}
	}
	return 0;
}