#include<bits/stdc++.h>
using namespace std;
vector<int> v;
string s;    
int main() {
    // 0으로 초기화
    for(int i = 0; i < 26; i++) v.push_back(0);
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        v[(int)s[i] - 97] += 1;
    }
    for(int i : v) cout << i << " ";
    cout << "\n";
    return 0;
}