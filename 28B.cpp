#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int N;
vi P, F;
vvi G;
vector<bool> vis;

void dfs (int S) {
	vis[S] = true;
	int v;
	for (int i = 0; i < (int) G[S].size(); i++) {
		v = G[S][i];
		if (!vis[v]) dfs(v);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	P = F = vi(N);
	G.assign(N, vi());
	for (int i = 0; i < N; i++) cin >> P[i];
	for (int i = 0; i < N; i++) cin >> F[i];
	for (int i = 0; i < N; i++) {
		if (i + F[i] < N) {
			G[i].push_back(i + F[i]);
			G[i + F[i]].push_back(i);
		}
		if (i - F[i] >= 0) {
			G[i].push_back(i - F[i]);
			G[i - F[i]].push_back(i);
		}
	}
	bool pos = true;
	for (int i = 0; i < N; i++) {
		vis.assign(N, false);
		dfs(i);
		if (vis[P[i]-1] == false) {
			pos = false;
			break;
		}
	}
	if (pos) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}
