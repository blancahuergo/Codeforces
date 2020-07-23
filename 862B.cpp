#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;

vector<int> C;
vector<vector<int>> G;
int N;

void dfs(int S) {
	for (int i = 0; i < (int) G[S].size(); i++) {
		if (C[G[S][i]] == -1) {
			C[G[S][i]] = 1 - C[S];
			dfs(G[S][i]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int a, b;
	G.assign(N, vector<int>());
	for (int i = 0; i < N-1; i++) {
		cin >> a >> b;
		G[a-1].emplace_back(b-1);
		G[b-1].emplace_back(a-1);
	}
	C.assign(N, -1);
	for (int i = 0; i < N; i++) {
		if (C[i] == -1) {
			C[i] = 0;
			dfs(i);
		}
	}
	int ones = 0, zeros;
	for (int i = 0; i < N; i++) {
		if (C[i]) ones++;
	}
	zeros = N - ones;
	ll ans = 0ll;
	for (int i = 0; i < N; i++) {
		if (C[i]) ans += zeros - G[i].size();
		else ans += ones - G[i].size();
	}
	cout << ans/2 << "\n";
	return 0;
}
