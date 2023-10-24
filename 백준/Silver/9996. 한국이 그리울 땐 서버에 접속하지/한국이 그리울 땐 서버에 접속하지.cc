#include<bits/stdc++.h>
using namespace std;
int n;
string p, p1, p2;
int main(){
    cin >> n;
    cin >> p;
    p1 = p.substr(0, p.find("*"));
    p2 = p.substr(p.find("*") + 1, p.size());
    for(int i = 0; i < n; i++){
        string s, p3, p4;
        cin >> s;
        if(p1.size()+p2.size() <= s.size()){
        p3 = s.substr(0, p1.size());
        p4 = s.substr(s.size()-p2.size(), s.size());
        }
        if(p1 == p3 && p2 == p4) cout << "DA" << "\n";
        else cout << "NE" << "\n";
    }
    return 0;
}