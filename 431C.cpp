#include <iostream>
#include <vector>
using namespace std;

int N, K, D, mod = 1e9 + 7;
vector<pair<int, int>> DP; // [curLen][Dreached / DnotReached]

int paths(int curLen, bool maxE) {
	if (curLen == N) {
		if (maxE) return 1;
		else return 0;
	} else if (curLen > N) return 0;
	if (maxE) {
		if (DP[curLen].first != -1) {
			return DP[curLen].first;
		}
	} else if (DP[curLen].second != -1) return DP[curLen].second;
	int ans = 0;
	for (int i = 1; i <= K; i++) {
		ans += paths(curLen + i, maxE || (i >= D));
		ans %= mod;
	}
	if (maxE) return DP[curLen].first = ans;
	else return DP[curLen].second = ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K >> D;
	DP.assign(N+1, make_pair(-1, -1));
	cout << paths(0, false) << "\n";
	return 0;
}
