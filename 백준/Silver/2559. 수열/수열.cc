#include<bits/stdc++.h>
using namespace std;
int n, k;
int sum = INT_MIN;
int a[100001]{0}, p[100001]{0};

int main(){
    cin >> n >> k;
    a[0] = 0; p[0] = 0;
    for(int i = 1; i <= n ; i++){ 
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
    }
    for(int i = 1; i <= n; i++){
        if(i < k) continue;
        if(sum < p[i] - p[i - k]) sum = p[i] - p[i - k];
    }
    cout << sum << "\n";
    return 0;
}