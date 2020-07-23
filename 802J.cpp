#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> G;

int main() {
	int u, v, c;
	cin >> N;
	G.assign(N, vector<int>(N, 1e9));
	for (int i = 0; i < N; i++) G[i][i] = 0;
	for (int i = 0; i < N-1; i++) {
		cin >> u >> v >> c;
		G[u][v] = G[v][u] = c;
		G[i][i] = 0;
	}
	G[N-1][N-1] = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				G[j][k] = min(G[j][k], G[j][i]+G[i][k]);
			}
		}
	}
	int rec = 0;
	for (int i = 1; i < N; i++) rec = max(rec, G[0][i]);
	cout << rec << "\n";
	return 0;
}
