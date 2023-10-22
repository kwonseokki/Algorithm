#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int n;
bool flag = 0;
int main() {
    for(int i = 0; i < 9; i++){
        cin >> n;
        v.push_back(n);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++){
        if (flag) break;
        for(int j = i+1; j < v.size(); j++){
            if(accumulate(v.begin(), v.end(), 0)- (v[i] + v[j]) == 100) {
                for(int k = 0; k < v.size(); k++) {
                    if(k == i || k == j) {
                        continue;
                    }
                    cout << v[k] << "\n";
                }
                flag = 1;
            }
        }
    }
    return 0;
}