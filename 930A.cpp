#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int N, maxT;
vvi G;
vi dist, distTots;

void init_dfs(int S) {
	maxT = max(maxT, dist[S]);
	int v;
	for (int i = 0; i < (int) G[S].size(); i++) {
		v = G[S][i];
		if (dist[v] == -1) {
			dist[v] = dist[S]+1;
			distTots[dist[v]]++;
			init_dfs(v);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int cur;
	G.assign(N, vi());
	for (int i = 1; i < N; i++) {
		cin >> cur;
		cur--;
		G[cur].emplace_back(i);
		G[i].emplace_back(i);
	}
	dist.assign(N, -1);
	distTots.assign(N, 0);
	dist[0] = 0;
	distTots[0] = 1;
	maxT = 0;
	init_dfs(0);
	int ans = 0;
	for (int t = 0; t <= maxT; t++) {
		ans += distTots[t] % 2;
	}
	cout << ans << "\n";
	return 0;
}
