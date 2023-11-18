#include <bits/stdc++.h>
using namespace std;
#define prev esresr
int n, team1, team2, team1_sc, team2_sc, prev;

int calcScore(int now){
    return now - prev;
}

string timeFormat(int time){
    string h = to_string(time / 60), m = to_string(time % 60);
    return (h.size() == 1 ? "0" + h : h) + ":" + (m.size() == 1 ? "0" + m : m);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int win_team, now;
        string s;
        cin >> win_team >> s;
        now = (stoi(s.substr(0, 2)) * 60) + stoi(s.substr(3, 5)); // 현재시간을 초로 변환
        if(team1_sc > team2_sc) team1 += calcScore(now);
        else if(team1_sc < team2_sc) team2 += calcScore(now);
        if(win_team == 1) team1_sc++;
        else team2_sc++;
        prev = now;
    }
    if(team1_sc > team2_sc) team1 += calcScore(48 * 60);
    else if(team1_sc < team2_sc) team2 += calcScore(48 * 60);
    cout << timeFormat(team1) << '\n';
    cout << timeFormat(team2) << '\n';
    return 0;
}