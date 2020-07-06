#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	vector<int> B, G;
	cin >> N;
	B.assign(N, 0);
	for(int n = 0; n < N; n++)
		cin >> B[n];
	cin >> M;
	G.assign(M, 0);
	for (int m = 0; m < M; m++)
		cin >> G[m];
	sort(B.begin(), B.end());
	sort(G.begin(), G.end());
	vector<vector<int>> DP = vector<vector<int>>(N+1, vector<int>(M+1, 0));
	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= M; m++) {
			if (abs(B[n-1] - G[m-1]) <= 1) DP[n][m] = DP[n-1][m-1]+1;
			DP[n][m] = max(DP[n][m], DP[n-1][m]);
			DP[n][m] = max(DP[n][m], DP[n][m-1]);
		}
	}
	cout << DP[N][M] << "\n";
	return 0;
}
