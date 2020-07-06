#include <iostream>
#include <vector>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N, M;
	int x, y;
	vector<string> grid;
	vector<vector<int>> cost;
	cin >> T;
	while(T--) {
		cin >> N >> M >> x >> y;
		grid.assign(N, "");
		cost.assign(N, vector<int>(M, 0));
		for (int n = 0; n < N; n++)
			cin >> grid[n];
		for (int n = 0; n < N; n++) {
			if (grid[n][0] == '.') {
				if (n > 0) {
					cost[n][0] = x + cost[n-1][M-1];
					if (M >= 2) {
						if (grid[n][1] == '.') cost[n][1] = min(cost[n][0]+x, cost[n-1][M-1]+y);
						else cost[n][1] = cost[n][0];
					}
				}
				else {
					cost[n][0] = x;
					if (M >= 2) {
						if (grid[n][1] == '.') cost[n][1] = min(2*x, y);
						else cost[n][1] = cost[n][0];
					}
				}
			} else {
				if (n > 0) {
					cost[n][0] = cost[n-1][M-1];
					if (M >= 2) {
						if (grid[n][1] == '.') cost[n][1] = x + cost[n][0];
						else cost[n][1] = cost[n][0];
					}
				}
				else if (M >= 2) {
					if (grid[n][1] == '.') cost[n][1] = x;
				}
			}
			for (int m = 2; m < M; m++) {
				if (grid[n][m] == '.') {
					if (grid[n][m-1] == '.') cost[n][m] = min(cost[n][m-1]+x, cost[n][m-2]+y);
					else cost[n][m] = cost[n][m-1]+x;
				}
				else cost[n][m] = cost[n][m-1];
			}
		}
		cout << cost[N-1][M-1] << "\n";
	}
	return 0;
}
