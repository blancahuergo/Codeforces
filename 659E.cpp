#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int N, M, curC;
vector<bool> visited;
vvi adj;
vi C;
int ed, cSize;

void dfs(int S) {
	ed += adj[S].size();
	cSize++;
	C[S] = curC;
	int v;
	for (int i = 0; i < (int) adj[S].size(); i++) {
		v = adj[S][i];
		if (C[v] == -1) dfs(v);
	}
}

int main() {
	cin >> N >> M;
	adj.assign(N, vi());
	int u, v;
	while(M--) {
		cin >> u >> v;
		u--;
		v--;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	C.assign(N, -1);
	curC = 0;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (C[i] == -1) {
			curC++;
			cSize = 0;
			ed = 0;
			dfs(i);
			ed /= 2;
			if (ed == cSize-1) ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}
