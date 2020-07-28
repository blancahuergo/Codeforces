#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int N, k;
vvi G;
vi ord, pos, par, endP;
vector<bool> visited;

void dfs(int S) {
	visited[S] = true;
	pos[S] = ord.size();
	ord.emplace_back(S+1);
	int v;
	for (int i = 0; i < (int) G[S].size(); i++) {
		v = G[S][i];
		if (!visited[v]) dfs(v);
	}
}

int end_pos(int S) {
	if (endP[S] != -1) return endP[S];
	if (S == 0) return endP[S] = N-1;
	int j = 0;
	while(true) {
		if (G[par[S]][j] == S) break;
		j++;
	}
	if (j != (int) G[par[S]].size() - 1) return endP[S] = pos[G[par[S]][j+1]]-1;
	else return endP[S] = end_pos(par[S]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int Q, dir, pos1, pos2;
	cin >> N >> Q;
	G.assign(N, vi());
	par.assign(N, 0);
	for (int i = 1; i < N; i++) {
		cin >> dir;
		par[i] = dir-1;
		G[dir-1].emplace_back(i);
	}
	for (int i = 0; i < N; i++) {
		if (G[i].size()) sort(G[i].begin(), G[i].end());
	}
	visited.assign(N, false);
	pos.assign(N, 0);
	endP.assign(N, -1);
	dfs(0);
	while(Q--) {
		cin >> dir >> k;
		dir--;
		pos1 = pos[dir];
		pos2 = end_pos(dir);
		if (pos2-pos1+1 < k) cout << "-1\n";
		else cout << ord[pos1 + k - 1] << "\n";
	}
	return 0;
}
