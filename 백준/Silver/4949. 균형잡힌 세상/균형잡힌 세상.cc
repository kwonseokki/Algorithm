#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	while(getline(cin, s)){
		if(s == ".")break;
		stack<char> stk;
		for(int i = 0; i < s.size(); i++){
			char c = s[i];
			if(c == '(' || c == '[')stk.push(c);
			else if(stk.size() && stk.top() == '(' && c == ')')stk.pop();
			else if(stk.size() && stk.top() == '[' && c == ']')stk.pop();
			else if(c == '(' || c == ')' || c == '[' || c == ']') stk.push(c);
		}
		if(stk.size()) cout << "no";
		else cout << "yes";
		cout << '\n';
		while(stk.size()) stk.pop();
	}
	return 0;
}