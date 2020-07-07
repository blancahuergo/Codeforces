#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, x, h;
	cin >> N;
	vector<vector<int>> DP = vector<vector<int>>(N, vector<int>(3, 0)); // [pos][left, leave, right]
	vector<int> pos = vector<int>(N);
	vector<int> height = vector<int>(N);
	DP[0][0] = 1;
	DP[0][1] = 0;
	for (int n = 0; n < N; n++) cin >> pos[n] >> height[n];
	if (N>1) {
		if (pos[0] + height[0] < pos[1]) DP[0][2]++;
	} else DP[0][1] = DP[0][2] = 1;
	for (int n = 1; n < N; n++) {
		x = pos[n];
		h = height[n];
		DP[n][0] = 1;
		if (pos[n-1] + height[n-1] < x) {
			DP[n][1] = max(DP[n][1], DP[n-1][2]);
			if (pos[n-1] + height[n-1] < x - h) {
				DP[n][0] = max(DP[n][0], DP[n-1][2]+1);
			} else if (pos[n-1] < x-h) {
				DP[n][0] = max(DP[n][0], max(DP[n-1][0], DP[n-1][1])+1);
			}
		} else {
			if (pos[n-1] < x - h) DP[n][0] = max(DP[n][0], max(DP[n-1][0], DP[n-1][1])+1);
			DP[n][1] = max(DP[n][1], max(DP[n-1][0], DP[n-1][1]));
		}
		if (n == N-1 || pos[n] + height[n] < pos[n+1]) DP[n][2] = DP[n][1]+1;
		else DP[n][2] = DP[n][1];
	}
	cout << DP[N-1][2] << "\n";
	return 0;
}
