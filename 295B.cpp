#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;

int N;
int costs[500][500], G[500][500], X[500];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> costs[i][j];
			G[i][j] = costs[i][j];
		}
	}
	for (int i = N-1; i >= 0; i--) {
		cin >> X[i];
		X[i]--;
	}
	int u;
	vl ans = vl(N, 0);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				G[X[j]][X[k]] = min(G[X[j]][X[k]], G[X[j]][X[i]] + G[X[i]][X[k]]);
				if (max(j, k) <= i) ans[i] += G[X[j]][X[k]];
			}
		}
	}
	for (int i = N-1; i > 0; i--) cout << ans[i] << " ";
	cout << ans[0] << "\n";
	return 0;
}
