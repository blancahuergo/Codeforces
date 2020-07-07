#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N;
	bool pos;
	cin >> T;
	vector<string> grid;
	vector<vector<bool>> DP;
	while(T--) {
		cin >> N;
		grid.assign(N, "");
		for (int n = 0; n < N; n++) cin >> grid[n];
		DP.assign(N, vector<bool>(N, false));
		pos = true;
		for (int c = 0; c < N; c++) DP[N-1][c] = grid[N-1][c] == '1';
		for (int r = N-2; r >= 0; r--) {
			DP[r][N-1] = grid[r][N-1] == '1';
			for (int c = N-2; c >= 0; c--) {
				DP[r][c] = (DP[r+1][c] || DP[r][c+1]) && grid[r][c] == '1';
				if (DP[r][c] == false && grid[r][c] == '1') {
					pos = false;
					break;
				}
			}
			if (pos == false) break;
		}
		if (pos) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
