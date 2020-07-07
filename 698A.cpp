#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, cur;
	cin >> N;
	// base states
	vector<vector<int>> DP = vector<vector<int>>(N+1, vector<int>(3, 1e6));
	DP[0][0] = 0;
	for (int n = 1; n <= N; n++) {
		cin >> cur;
		if (cur == 0) {
			// neither
			DP[n][0] = min(DP[n-1][0], min(DP[n-1][1], DP[n-1][2]))+1;
		} else if (cur == 1) {
			// contest
			DP[n][0] = min(DP[n-1][0], min(DP[n-1][1], DP[n-1][2]))+1;
			DP[n][1] = min(DP[n-1][0], DP[n-1][2]);
		} else if (cur == 2) {
			// gym
			DP[n][0] = min(DP[n-1][0], min(DP[n-1][1], DP[n-1][2]))+1;
			DP[n][2] = min(DP[n-1][0], DP[n-1][1]);
		} else {
			// both
			DP[n][0] = min(DP[n-1][0], min(DP[n-1][1], DP[n-1][2]))+1;
			DP[n][1] = min(DP[n-1][0], DP[n-1][2]);
			DP[n][2] = min(DP[n-1][0], DP[n-1][1]);
		}
	}
	cout << min(DP[N][0], min(DP[N][1], DP[N][2])) << "\n";
	return 0;
}
