#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

unordered_map<string, int> dict;
vector<vector<int>> G;
vector<int> DP;

int maxLen(int id) {
	if (DP[id] != -1) return DP[id];
	int ans = 1;
	for (int i = 0; i < (int) G[id].size(); i++)
		ans = max(ans, 1+maxLen(G[id][i]));
	return DP[id] = ans;
}

int main() {
	string n1, n2;
	int N, count=0;
	cin >> N;
	G.assign(N+1, vector<int>());
	DP.assign(N+1, -1);
	for (int n = 0; n < N; n++) {
		cin >> n1;
		cin >> n2;
		cin >> n2;
		transform(n1.begin(), n1.end(), n1.begin(), [](unsigned char c){ return tolower(c); });
		transform(n2.begin(), n2.end(), n2.begin(), [](unsigned char c){ return tolower(c); });
		if (dict.find(n1) == dict.end()) dict[n1] = count++;
		if (dict.find(n2) == dict.end()) dict[n2] = count++;
		G[dict[n2]].push_back(dict[n1]);
	}
	cout << maxLen(dict["polycarp"]) << "\n";
	return 0;
}
