#include<bits/stdc++.h>
using namespace std;
string a, tmp;

int main(){
    cin >> a;
    tmp = a;
    reverse(tmp.begin(), tmp.end());
    for(int i = 0; i < a.size() / 2; i++){
        if(a[i] != tmp[i]){
            cout << 0 << "\n";
            exit(0);
        }
    }
    cout << 1 << "\n";
    return 0;
}