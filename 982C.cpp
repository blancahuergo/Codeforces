#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi G;
vi con;
vector<bool> visited;

int dfs(int u) {
	int ans = 1;
	for (int i = 0; i < (int) G[u].size(); i++) {
		if (visited[G[u][i]] == false) {
			visited[G[u][i]] = true;
			ans += dfs(G[u][i]);
		}
	}
	return con[u] = ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, u, v, ans;
	cin >> N;
	G.assign(N, vi());
	for (int i = 0; i < N-1; i++) {
		cin >> u >> v;
		G[u-1].emplace_back(v-1);
		G[v-1].emplace_back(u-1);
	}
	if (N&1) cout << "-1\n";
	else {
		visited.assign(N, false);
		visited[0] = true;
		con.assign(N, 1);
		dfs(0);
		ans = 0;
		for (int i = 1; i < N; i++) {
			if (!(con[i]&1)) ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}
