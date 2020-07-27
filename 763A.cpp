#include <iostream>
#include <vector>
using namespace std;

int N, M, x;
vector<pair<int, int>> E;
vector<vector<int>> G;
vector<int> C;
vector<bool> vis;

bool sameCol(int S) {
	int v;
	vis[S] = true;
	bool ans = true;
	for (int i = 0; i < (int) G[S].size(); i++) {
		v = G[S][i];
		if (v == x) continue;
		if (C[v] != C[S]) return false;
		else if (!vis[v]) {
			ans = (ans && sameCol(v));
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b;
	cin >> N;
	G.assign(N, vector<int>());
	for (int i = 0; i < N-1; i++) {
		cin >> a >> b;
		a--;
		b--;
		G[a].emplace_back(b);
		G[b].emplace_back(a);
		E.emplace_back(make_pair(a, b));
	}
	C.assign(N, 0);
	for (int i = 0; i < N; i++) cin >> C[i];
	bool diff = false, pos = false;
	int ans = -1;
	for (int i = 0; i < N-1; i++) {
		a = E[i].first;
		b = E[i].second;
		if (C[a] != C[b]) {
			diff = true;
			pos = true;
			for (int j = 0; j < (int) G[a].size(); j++) {
				vis.assign(N, false);
				x = a;
				pos = sameCol(G[a][j]);
				if (pos == false) {
					break;
				}
			}
			if (pos) {
				ans = a + 1;
				break;
			}
			pos = true;
			for (int j = 0; j < (int) G[b].size(); j++) {
				vis.assign(N, false);
				x = b;
				pos = sameCol(G[b][j]);
				if (pos == false) {
					break;
				}
			}
			if (pos) {
				ans = b + 1;
			}
			break;
		}
	}
	if (diff == false) {
		cout << "YES\n";
		cout << "1\n";
	} else if (pos) {
		cout << "YES\n";
		cout << ans << "\n";
	} else cout << "NO\n";
	return 0;
}
