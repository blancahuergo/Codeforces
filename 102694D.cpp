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
typedef vector<vpii> vvpii;
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
vi depth, subT, ed, par;
vvi table, HLD;
vvpii G;
vpii pos;
vvi seg;

void calcSparse(int S, int p) {
	table[0][S] = p;
	for (int i = 1; i <= height; i++) {
		table[i][S] = table[i-1][table[i-1][S]];
		if (table[i][S] == -1) break;
	}
}

void dfs(int S, int p) {
	for (int i = 0; i < (int) G[S].size(); i++) {
		int v = G[S][i].first;
		if (v == p) continue;
		calcSparse(v, S);
		depth[v] = depth[S]+1;
		ed[v] = G[S][i].second;
		par[v] = S;
		dfs(v, S);
		subT[S] += subT[v];
	}
}

void decompose(int node, int chain) {
	pos[node] = mp(chain, (int) HLD[chain].size());
	HLD[chain].pb(node);
	int sz = -1, ch = -1;
	for (int i = 0; i < (int) G[node].size(); i++) {
		int v = G[node][i].first;
		if (depth[v] < depth[node]) continue;
		if (subT[v] > sz) {
			sz = subT[v];
			ch = v;
		}
	}
	if (ch == -1) return;
	decompose(ch, chain);
	for (int i = 0; i < (int) G[node].size(); i++) {
		int v = G[node][i].first;
		if (v == ch || depth[v] < depth[node]) continue;
		HLD.pb(vi());
		decompose(v, (int) HLD.size()-1);
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

void segTree(int chain, int x, int l, int r) {
	if (l < r) {
		int mid = l + (r-l)/2;
		segTree(chain, 2*x, l, mid);
		segTree(chain, 2*x+1, mid+1, r);
		seg[chain][x] = min(seg[chain][2*x], seg[chain][2*x+1]);
	} else seg[chain][x] = ed[HLD[chain][l]];
}

void fillMin() {
	int x;
	for (int i = 0; i < (int) HLD.size(); i++) {
		// use segtree for each chain
		x = (int) HLD[i].size();
		seg.pb(vi(4*x, 0));
		segTree(i, 1, 0, x-1);
	}
}

int querySegTree(int chain, int x, int l, int r, int initInd, int endInd) {
	if (l >= initInd && r <= endInd) return seg[chain][x];
	else if (l > endInd || r < initInd) return -1;
	else {
		int mid = l + (r-l)/2;
		int leftVal = querySegTree(chain, 2*x, l, mid, initInd, endInd);
		int rightVal = querySegTree(chain, 2*x+1, mid+1, r, initInd, endInd);
		if (leftVal == -1) return rightVal;
		else if (rightVal == -1) return leftVal;
		else return min(rightVal, leftVal);
	}
}

int RMQ(int chain, int st, int end) {
	if (st > end) return 2e9;
	else return querySegTree(chain, 1, 0, (int) HLD[chain].size()-1, st, end);
}

int maxFlow(int s, int t) {
	int lca = LCA(s, t), ans = 2e9, chLCA = pos[lca].first, nodLCA = pos[lca].second, curCh, curPos, p;
	// path from t to LCA
	curCh = pos[t].first;
	curPos = pos[t].second;
	while(curCh != chLCA) {
		ans = min(ans, RMQ(curCh, 0, curPos));
		p = par[HLD[curCh][0]];
		curCh = pos[p].first;
		curPos = pos[p].second;
	}
	ans = min(ans, RMQ(chLCA, nodLCA+1, curPos));
	// path from s to LCA
	curCh = pos[s].first;
	curPos = pos[s].second;
	while(curCh != chLCA) {
		ans = min(ans, RMQ(curCh, 0, curPos));
		p = par[HLD[curCh][0]];
		curCh = pos[p].first;
		curPos = pos[p].second;
	}
	ans = min(ans, RMQ(chLCA, nodLCA+1, curPos));
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int M, a, b, c, Q;
	cin >> N >> M;
	height = (int) ceil(log2((double) N));
	table.assign(height+1, vi(N, -1));
	G.assign(N, vpii());
	depth.assign(N, 0);
	subT.assign(N, 1);
	ed.assign(N, 2e9);
	par.assign(N, -1);
	pos.assign(N, pii());
	while(M--) {
		cin >> a >> b >> c;
		G[a-1].pb(mp(b-1, c));
		G[b-1].pb(mp(a-1, c));
	}
	dfs(0, -1);
	HLD.pb(vi());
	decompose(0, 0);
	fillMin();
	cin >> Q;
	while(Q--) {
		cin >> a >> b;
		cout << maxFlow(a-1, b-1) << "\n";
	}
	return 0;
}
