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

int N, curCC;
vvi G;
vi CC, parentCC, rnk, maxApp;

int root(int a) {
	if (parentCC[a] == a) return a;
	return parentCC[a] = root(parentCC[a]);
}

bool isSameSet(int a, int b) {
	return root(a) == root(b);
}

void mergeByRank(int a, int b) {
	int r_a, r_b;
	r_a = root(a);
	r_b = root(b);
	if (r_a == r_b) return;
	if (rnk[r_a] > rnk[r_b]) {
		parentCC[r_b] = r_a;
		maxApp[r_a] = max(maxApp[r_b], maxApp[r_a]);
	} else if (rnk[r_b] > rnk[r_a]) {
		parentCC[r_a] = r_b;
		maxApp[r_b] = max(maxApp[r_b], maxApp[r_a]);
	} else {
		parentCC[r_a] = r_b;
		maxApp[r_b] = max(maxApp[r_b], maxApp[r_a]);
		rnk[r_b]++;
	}
}

void dfs(int S) {
	CC[S] = curCC;
	for (int i = 0; i < (int) G[S].size(); i++) {
		int v = G[S][i];
		if (CC[v] == -1) dfs(v);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int M, u, v;
	cin >> N >> M;
	G.assign(N, vi());
	while(M--) {
		cin >> u >> v;
		u--;
		v--;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	CC.assign(N, -1);
	curCC = 0;
	for (int i = 0; i < N; i++) {
		if (CC[i] == -1) {
			dfs(i);
			curCC++;
		}
	}
	parentCC.assign(curCC, 0);
	rnk.assign(curCC, 1);
	maxApp.assign(curCC, 0);
	for (int i = 1; i < curCC; i++) parentCC[i] = i;
	int ans = 0;
	for (int i = 1; i < N; i++) {
		maxApp[CC[i]] = i;
	}
	for (int i = 1; i < N; i++) {
		if (root(CC[i]) != root(CC[i-1]) && (maxApp[root(CC[i-1])] > i)) {
			ans++;
			mergeByRank(CC[i], CC[i-1]);
		}
	}
	cout << ans << "\n";
	return 0;
}
