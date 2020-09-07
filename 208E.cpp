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

vvi table, G;
vi depth, Tsize, arr, pos, vpos;
int height, N, maxD;
vvi V;

void init() {
	height = (int) ceil(log2((double) N));
	table.assign(height+1, vi(N, -1));
}

void calcSparse(int S, int v) {
	table[0][S] = v;
	for (int i = 1; i <= height; i++) {
		table[i][S] = table[i-1][table[i-1][S]];
		if (table[i][S] == -1) break;
	}
}

void dfs(int S, int par) {
	pos[S] = (int) arr.size();
	arr.pb(S);
	Tsize[S] = 1;
	for (auto v: G[S]) {
		calcSparse(v, S);
		depth[v] = depth[S]+1;
		if (depth[v] == (int) V.size()) V.pb(vi());
		vpos[v] = (int) V[depth[v]].size();
		V[depth[v]].pb(v);
		dfs(v, S);
		Tsize[S] += Tsize[v];
	}
}

int KthAncestor(int u, int k) {
	for (int i = 0; i <= height; i++) {
		if (k & (1<<i)) {
			u = table[i][u];
			if (u == -1) return -1;
		}
	}
	return u;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int cur, M, v, p;
	maxD = 0;
	cin >> N;
	depth.assign(N, 0);
	pos.assign(N, 0);
	Tsize.assign(N, 0);
	init();
	vi roots;
	G.assign(N, vi());
	vpos.assign(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> cur;
		if (cur) G[cur-1].pb(i);
		else roots.pb(i);
	}
	V.pb(vi());
	for (auto x: roots) {
		vpos[x] = (int) V[0].size();
		V[0].pb(x);
		dfs(x, -1);
	}
	cin >> M;
	int d, anc, lb, ub, lo, hi, mid, fir, sec, u;
	while(M--) {
		cin >> v >> p;
		v--;
		d = depth[v];
		if (d < p) {
			cout << "0 ";
			continue;
		}
		anc = KthAncestor(v, p);
		lb = pos[anc];
		ub = pos[anc] + Tsize[anc];
		lo = 0;
		hi = vpos[v];
		fir = 0;
		while(lo <= hi) {
			mid = lo + (hi-lo)/2;
			u = V[d][mid];
			if (pos[u] > lb && pos[u] < ub) {
				fir = mid;
				hi = mid-1;
			} else lo = mid+1;
		}
		sec = 0;
		lo = vpos[v];
		hi = (int) V[d].size()-1;
		while(lo <= hi) {
			mid = lo + (hi-lo)/2;
			u = V[d][mid];
			if (pos[u] > lb && pos[u] < ub) {
				lo = mid+1;
				sec = mid;
			} else hi = mid-1;
		}
		cout << sec-fir << " ";
	}
	return 0;
}
