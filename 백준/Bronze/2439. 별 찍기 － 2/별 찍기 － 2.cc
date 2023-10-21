#include <bits/stdc++.h>
using namespace std;
int n;
string a;
string b;
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-i-1; j++) {
            cout << " ";
        }
        a += "*";
        cout << a << "\n";
    }
    return 0;
}