#include <bits/stdc++.h>
using namespace std;
int n, m, a[15001], ret;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);
    cin >> n;
    cin >> m;
    for(int i = 0; i < n; i++)cin >> a[i];
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] + a[j] == m)ret++;
        }
    }
    cout << ret << '\n';
    return 0;

}
