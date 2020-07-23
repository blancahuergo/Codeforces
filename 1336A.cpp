#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <unordered_map>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef pair<int, int> pii;
typedef long long int ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> pll;

vvi G;
vl dist, vis, diff;
int N, K;

ll dfs(int u) {
	ll ans = 1;
	for (int i = 0; i < (int) G[u].size(); i++) {
		if (dist[G[u][i]] > dist[u]+1) {
			dist[G[u][i]] = dist[u]+1;
			ans += dfs(G[u][i]);
		}
	}
	return vis[u] = ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int u, v;
	ll res;
	cin >> N >> K;
	G.assign(N, vi());
	for (int i = 0; i < N-1; i++) {
		cin >> u >> v;
		G[u-1].emplace_back(v-1);
		G[v-1].emplace_back(u-1);
	}
	dist.assign(N, LLONG_MAX);
	vis.assign(N, 0);
	dist[0] = 1;
	dfs(0);
	for (int i = 0; i < N; i++) {
		dist[i] = vis[i] - dist[i];
	}
	sort(dist.begin(), dist.end(), greater<>());
	res = 0;
	for (int i = 0; i < N-K; i++) res += dist[i];
	cout << res << "\n";
	return 0;
}
