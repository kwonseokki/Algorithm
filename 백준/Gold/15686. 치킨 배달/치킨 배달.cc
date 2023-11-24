#include <bits/stdc++.h>
using namespace std;
int n, m, a[51][51], result = 99999999;
vector<pair<int, int>> chikenList, homeList;
vector<vector<int>> indexList;

void combi(int start, vector<int> v){
	if(v.size() == m){
		indexList.push_back(v);
		return;
	}
	for(int i = start + 1; i < chikenList.size(); i++){
		v.push_back(i);
		combi(i, v);
		v.pop_back();
	}
	return;
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
			if(a[i][j] == 1) homeList.push_back({i, j});
			if(a[i][j] == 2) chikenList.push_back({i, j});
		}
	}
	combi(-1, {});
	for(vector<int> lst : indexList){
		int ret = 0;
		for(pair<int, int> home: homeList){
			int _min = 99999999;
			for(int ch: lst){
				int _dist = abs(home.first - chikenList[ch].first) + abs(home.second - chikenList[ch].second);
                _min = min(_min, _dist);
			}
			ret += _min;
		}
		result = min(result, ret);
	}
	cout << result << '\n';
    return 0;
}
