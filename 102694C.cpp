#include <iostream>
#include <fstream>
#include <cfloat>
#include <iomanip>
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
typedef vector<string> vs;
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define len(v) ((int)v.size())
#define all(v) v.begin(), v.end()

int N, height;
vvi G, table;
vi depth;

void calcSparse(int S, int par) {
	table[0][S] = par;
	for (int i = 1; i <= height; i++) {
		table[i][S] = table[i-1][table[i-1][S]];
		if (table[i][S] == -1) break;
	}
}

void dfs(int S, int par) {
	for (int i = 0; i < (int) G[S].size(); i++) {
		int v = G[S][i];
		if (v == par) continue;
		depth[v] = depth[S]+1;
		calcSparse(v, S);
		dfs(v, S);
	}
}

int LCA(int a, int b) {
	if (depth[a] > depth[b]) swap(a, b);
	for (int i = height; i >= 0; i--) {
		if (depth[b] - (1<<i) >= depth[a]) {
			b = table[i][b];
		}
	}
	if (a == b) return a;
	for (int i = height; i >= 0; i--) {
		if (table[i][a] != table[i][b]) {
			a = table[i][a];
			b = table[i][b];
		}
	}
	return table[0][a];
}

int KthAncestor(int a, int k) {
	for (int i = 0; i <= height; i++) {
		if (k & (1 << i)) a = table[i][a];
		if (a == -1) break;
	}
	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int Q, a, b, c, lca, len;
	cin >> N;
	height = (int) ceil(log2((double) N));
	table.assign(height+1, vi(N, -1));
	G.assign(N, vi());
	for (int i = 0; i < N-1; i++) {
		cin >> a >> b;
		G[a-1].pb(b-1);
		G[b-1].pb(a-1);
	}
	depth.assign(N, 0);
	dfs(0, -1);
	cin >> Q;
	while(Q--) {
		cin >> a >> b >> c;
		a--;
		b--;
		lca = LCA(a, b);
		len = depth[a]+depth[b]-2*depth[lca];
		if (len <= c) cout << b+1 << "\n";
		else if (c == depth[a] - depth[lca]) cout << lca+1 << "\n";
		else if (c > depth[a] - depth[lca]) cout << KthAncestor(b, len-c)+1 << "\n";
		else cout << KthAncestor(a, c)+1 << "\n";
	}
	return 0;
}
