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
typedef long double ld;
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
typedef vector<long double> vf;
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

int N;
vvi G;
vi arr, pos, subT;
vf seg, val;

void dfs(int S, int p) {
	pos[S] = (int) arr.size();
	arr.pb(S);
	for (int i = 0; i < (int) G[S].size(); i++) {
		int v = G[S][i];
		if (v == p) continue;
		dfs(v, S);
		subT[S] += 1+subT[v];
	}
}

void makeTree(int x, int l, int r) {
	if (l == r) seg[x] = log(val[arr[l]]);
	else {
		int mid = l + (r-l)/2;
		makeTree(2*x, l, mid);
		makeTree(2*x+1, mid+1, r);
		seg[x] = seg[2*x]+seg[2*x+1];
	}
}

void update(int x, int l, int r, int ind) {
	if (ind < l || ind > r) return;
	if (l == r) seg[x] = log(val[arr[ind]]);
	else {
		int mid = l + (r-l)/2;
		update(2*x, l, mid, ind);
		update(2*x+1, mid+1, r, ind);
		seg[x] = seg[2*x]+seg[2*x+1];
	}
}

pair<ld, bool> query(int x, int l, int r, int initInd, int endInd) {
	if (l > endInd || r < initInd) return mp(0, false);
	if (r <= endInd && l >= initInd) return mp(seg[x], true);
	else {
		int mid = l + (r-l)/2;
		pair<ld, bool> left = query(2*x, l, mid, initInd, endInd);
		pair<ld, bool> right = query(2*x+1, mid+1, r, initInd, endInd);
		if (left.s == false) return mp(right.f, true);
		else if (right.s == false) return mp(left.f, true);
		return mp(left.f+right.f, true);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(7);
	int Q, a, b, c;
	ld newVal, cur, lim = log(1000000000.0);
	cin >> N;
	G.assign(N, vi());
	pos.assign(N, 0);
	val.assign(N, 1);
	subT.assign(N, 0);
	for (int i = 0; i < N-1; i++) {
		cin >> a >> b;
		a--;
		b--;
		G[a].pb(b);
		G[b].pb(a);
	}
	dfs(0, -1);
	seg.assign(4*N, 0ll);
	makeTree(1, 0, N-1);
	cin >> Q;
	while(Q--) {
		cin >> c;
		if (c == 1) {
			cin >> a >> newVal;
			a--;
			val[a] = newVal;
			update(1, 0, N-1, pos[a]);
		} else {
			cin >> a >> b;
			a--;
			b--;
			cur = query(1, 0, N-1, pos[a], pos[a]+subT[a]).f - query(1, 0, N-1, pos[b], pos[b]+subT[b]).f;
			if (cur >= lim) cout << "1000000000\n";
			else cout << exp(cur) << "\n";
		}
	}
	return 0;
}
