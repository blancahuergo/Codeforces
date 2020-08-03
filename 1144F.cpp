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

int N, M;
vi E;
vvi G;
vi C;
bool pos;

void dfs(int u) {
	int v;
	for (int i = 0; i < (int) G[u].size(); i++) {
		v = G[u][i];
		if (C[v] == -1) {
			C[v] = 1-C[u];
			dfs(v);
		} else if (C[v] == C[u]) pos = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	int u, v;
	E.assign(M, 0);
	G.assign(N, vi());
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		u--;
		v--;
		E[i] = u;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	pos = true;
	C.assign(N, -1);
	for (int i = 0; i < N; i++) {
		if (C[i] == -1) {
			C[i] = 1;
			dfs(i);
		}
	}
	if (pos) {
		cout << "YES\n";
		for (int i = 0; i < M; i++) {
			if (C[E[i]] == 1) cout << "1";
			else cout << "0";
		}
		cout << "\n";
	} else cout << "NO\n";
	return 0;
}
