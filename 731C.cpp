#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int N, M, K, cSize;
vvi G;
vi cols, C;
vector<bool> vis;

void dfs(int S) {
	vis[S] = true;
	cols.emplace_back(C[S]);
	cSize++;
	int v;
	for (int i = 0; i < (int) G[S].size(); i++) {
		v = G[S][i];
		if (!vis[v]) dfs(v);
	}
}

int maj() {
	int maxC = 0;
	int i = 0, j;
	sort(cols.begin(), cols.end());
	while(i < (int) cols.size()) {
		j = i;
		while(cols[j] == cols[i]) {
			j++;
			if (j == (int) cols.size()) break;
		}
		maxC = max(maxC, j-i);
		i = j;
	}
	return maxC;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> K;
	int a, b;
	G.assign(N, vi());
	C.assign(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> C[i];
		C[i]--;
	}
	while(M--) {
		cin >> a >> b;
		a--;
		b--;
		G[a].emplace_back(b);
		G[b].emplace_back(a);
	}
	vis.assign(N, false);
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (!vis[i] && G[i].size()) {
			cSize = 0;
			cols.clear();
			dfs(i);
			ans += cSize - maj();
		}
	}
	cout << ans << "\n";
	return 0;
}
