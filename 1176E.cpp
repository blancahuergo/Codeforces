#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <cmath>
#include <climits>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<pii> vpii;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<vvvl> vvvvl;

int N, even;
vvi G;
vi dist, ans;

void bfs(int S) {
	queue<int> Q;
	Q.push(S);
	int u;
	dist.assign(N, N+1);
	dist[S] = 0;
	even = 0;
	while(Q.size()) {
		u = Q.front();
		Q.pop();
		if (!(dist[u] & 1)) even++;
		for(int i = 0; i < (int) G[u].size(); i++) {
			int v = G[u][i];
			if (dist[v] > dist[u]+1) {
				dist[v] = dist[u]+1;
				Q.push(v);
			}
		}
	}
	if (even * 2 < N) {
		for (int i = 0; i < N; i++) {
			if (dist[i] & 1) continue;
			ans.emplace_back(i+1);
		}
	} else {
		for (int i = 0; i < N; i++) {
			if (dist[i] & 1) ans.emplace_back(i+1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, M, u, v;
	cin >> T;
	while(T--) {
		cin >> N >> M;
		G.assign(N, vi());
		while(M--) {
			cin >> u >> v;
			u--;
			v--;
			G[u].emplace_back(v);
			G[v].emplace_back(u);
		}
		ans.clear();
		bfs(0);
		cout << ans.size() << "\n";
		cout << ans[0];
		for (int i = 1; i < (int) ans.size(); i++) cout << " " << ans[i];
		cout << "\n";
	}
	return 0;
}
