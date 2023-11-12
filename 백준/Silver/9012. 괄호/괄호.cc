#include<bits/stdc++.h>
using namespace std;
int TC;
stack<char> stk;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> TC;
	while(TC--){
		string s;
		cin >> s;
		for(int i = 0; i < s.size(); i++){
			char c = s[i];
			if(c == '(') stk.push(c);
			else if(c == ')' && stk.size() && stk.top() == '(') stk.pop();
			else stk.push(c);
		}
		if(stk.size()) cout << "NO";
		else cout << "YES";
		cout << '\n';
		while(stk.size()) stk.pop();
	}
	return 0;
}