#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, V, cur;
	cin >> N >> V;
	vector<vector<int>> DP = vector<vector<int>>(N+1, vector<int>(V, 1e9));
	DP[1][0] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = i+1; j <= min(N, i+V); j++) {
			for (int curv = 0; curv < V; curv++) {
				for (int fill = max(j- i- curv, 0); fill <= V - curv; fill++) {
					DP[j][curv + fill - (j-i)] = min(DP[j][curv + fill - (j-i)], DP[i][curv] + fill*i);
				}
			}
		}
	}
	cur = 1e9;
	for (int v = 0; v < V; v++) cur = min(cur, DP[N][v]);
	cout << cur << "\n";
	return 0;
}
