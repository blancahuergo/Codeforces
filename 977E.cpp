#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
int N, M;

vvi G;
vi C;
bool pos;
int cSize;

void dfs(int i) {
	int v;
	for (int k = 0; k < (int) G[i].size(); k++) {
		v = G[i][k];
		if (C[v] == -1) {
			C[v] = C[i];
			cSize++;
			dfs(v);
		}
	}
	if (G[i].size() != 2) pos = false;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	int u, v, c;
	G.assign(N, vi());
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		G[u-1].emplace_back(v-1);
		G[v-1].emplace_back(u-1);
	}
	C.assign(N, -1);
	c = 0;
	int cyc = 0;
	for (int i = 0; i < N; i++) {
		if (C[i] == -1) {
			C[i] = c++;
			pos = true;
			cSize = 1;
			dfs(i);
			if (pos && cSize > 2) cyc++;
		}
	}
	cout << cyc << "\n";
	return 0;
}
