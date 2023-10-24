#include<bits/stdc++.h>
using namespace std;
int a, b, c, sum;
int min_t = 101, max_t = 0;
vector<pair<int, int>> v;

int main(){
    cin >> a >> b >> c;
    for(int i = 0; i < 3; i++){
        int f, s;
        cin >> f >> s;
        v.push_back({f, s});
        if(min_t > f) min_t = f;
        if(max_t < s) max_t = s;
    }
    for(int i = min_t; i <= max_t; i++){
        int cnt = 0, money = 0;
        pair<int, int> t1 = v[0];
        pair<int, int> t2 = v[1];
        pair<int, int> t3 = v[2];
        if(t1.first <= i && t1.second > i) cnt++;
        if(t2.first <= i && t2.second > i) cnt++;     
        if(t3.first <= i && t3.second > i) cnt++;
        if (cnt == 0){
            continue;
        } else if(cnt == 1){
            money = a;
        } else if(cnt == 2){
            money = b;
        } else {
            money = c;
        }
        sum += cnt * money;
    }
    cout << sum << "\n";
    return 0;
}