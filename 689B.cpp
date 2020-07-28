#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int N;
vvi G;
vi dist;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	G.assign(N, vi());
	int cur;
	for (int i = 0; i < N; i++) {
		cin >> cur;
		G[i].emplace_back(cur-1);
		if (i < N-1) G[i].emplace_back(i+1);
		if (i) G[i].emplace_back(i-1);
	}
	queue<pair<int, int>> Q;
	Q.push({0, 0});
	dist.assign(N, 1e9);
	dist[0] = 0;
	pair<int, int> cp;
	int u, distU;
	while(Q.size()) {
		cp = Q.front();
		Q.pop();
		u = cp.first;
		distU = cp.second;
		if (distU > dist[u]) continue;
		for (int i = 0; i < (int) G[u].size(); i++) {
			int v = G[u][i];
			if (dist[v] > dist[u]+1) {
				dist[v] = dist[u]+1;
				Q.push({v, dist[v]});
			}
		}
	}
	cout << dist[0];
	for (int i = 1; i < N; i++) cout << " " << dist[i];
	return 0;
}
