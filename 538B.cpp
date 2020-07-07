#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> quasi;

void fillQuasi(string cur, int ind) {
	if (ind == 7) {
		quasi.push_back(stoi(cur));
		return;
	}
	fillQuasi(cur + "0", ind+1);
	fillQuasi(cur + "1", ind+1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	fillQuasi("0", 0);
	vector<int> DP, prev;
	DP = prev = vector<int>(N+1);
	DP[0] = 0;
	prev[0] = 0;
	for (int am = 1; am <= N; am++) {
		DP[am] = 1e9;
		for (int c = 0; c < (int) quasi.size(); c++) {
			if (quasi[c] > am) break;
			if (DP[am - quasi[c]]+1 < DP[am]) {
				DP[am] = DP[am - quasi[c]]+1;
				prev[am] = am - quasi[c];
			}
		}
	}
	vector<int> ans;
	int i = N;
	while(i != 0) {
		ans.push_back(i - prev[i]);
		i = prev[i];
	}
	cout << (int) ans.size() << "\n";
	cout << ans[0];
	for (int i = 1; i < (int) ans.size(); i++) cout << " " << ans[i];
	cout << "\n";
	return 0;
}
