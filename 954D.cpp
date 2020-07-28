#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int N, s, t;
vvi G, con;
vi distS, distT;

int Dijkstra() {
	queue<pair<int, int>> Q;
	distS.assign(N, 1e9);
	distS[s] = 0;
	Q.push({s, 0});
	pair<int, int> cur;
	int u, distU, v;
	while(Q.size()) {
		cur = Q.front();
		Q.pop();
		u = cur.first;
		distU = cur.second;
		if (distU > distS[u]) continue;
		for (int i = 0; i < (int) G[u].size(); i++) {
			v = G[u][i];
			if (distS[u] + 1 < distS[v]) {
				distS[v] = distS[u]+1;
				Q.push({v, distS[v]});
			}
		}
	}
	distT.assign(N, 1e9);
	distT[t] = 0;
	Q.push({t, 0});
	while(Q.size()) {
		cur = Q.front();
		Q.pop();
		u = cur.first;
		distU = cur.second;
		if (distU > distT[u]) continue;
		for (int i = 0; i < (int) G[u].size(); i++) {
			v = G[u][i];
			if (distT[u] + 1 < distT[v]) {
				distT[v] = distT[u] + 1;
				Q.push( { v, distT[v] });
			}
		}
	}
	int ans = 0;
	bool pos;
	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			if (con[i][j]) continue;
			pos = true;
			if (distS[i] + 1 + distT[j] < distS[t]) pos = false;
			else if (distS[j] + 1 + distT[i] < distS[t]) pos = false;
			if (pos) ans++;
		}
	}
	return ans;
}


int main() {
	int M, u, v;
	cin >> N >> M >> s >> t;
	s--;
	t--;
	G.assign(N, vi());
	con.assign(N, vi(N, 0));
	while(M--) {
		cin >> u >> v;
		u--;
		v--;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
		con[u][v] = con[v][u] = 1;
	}
	cout << Dijkstra();
	return 0;
}
