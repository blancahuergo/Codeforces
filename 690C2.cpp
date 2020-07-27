#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int N, M;
vvi G;
vi dist;

int diam() {
	queue<int> Q;
	Q.push(0);
	int rec = 0, recV, u, v;
	dist.assign(N, -1);
	dist[0] = 0;
	while(Q.size()) {
		u = Q.front();
		Q.pop();
		if (dist[u] > rec) {
			rec = dist[u];
			recV = u;
		}
		for (int i = 0; i < (int) G[u].size(); i++) {
			v = G[u][i];
			if (dist[v] == -1) {
				dist[v] = dist[u]+1;
				Q.push(v);
			}
		}
	}
	Q.push(recV);
	dist.assign(N, -1);
	dist[recV] = 0;
	rec = 0;
	while (Q.size()) {
		u = Q.front();
		Q.pop();
		if (dist[u] > rec) {
			rec = dist[u];
			recV = u;
		}
		for (int i = 0; i < (int) G[u].size(); i++) {
			v = G[u][i];
			if (dist[v] == -1) {
				dist[v] = dist[u] + 1;
				Q.push(v);
			}
		}
	}
	return rec;
}

int main() {
	cin >> N >> M;
	G.assign(N, vi());
	int a, b;
	for (int i = 0; i < N-1; i++) {
		cin >> a >> b;
		G[a-1].emplace_back(b-1);
		G[b-1].emplace_back(a-1);
	}
	cout << diam() << "\n";
	return 0;
}
