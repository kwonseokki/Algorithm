#include<bits/stdc++.h>
using namespace std;
string a;
int b[26] = {0};
vector<char> v;
int n;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        b[(int) a[0] - 97] += 1;
    }
    for(int i = 0; i < 26; i++){
        if(b[i] >= 5)v.push_back((char) i + 97);
    }
    if(v.size() > 0) for(char i : v) cout << i;
    else cout << "PREDAJA";
    cout << "\n";
    return 0;
}