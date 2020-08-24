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

vi pos, subT;
int cnt;
vl valLoc, seg;
vvi G;
int N;

void dfs(int S, int p) {
	pos[S] = cnt;
	cnt++;
	for (int i = 0; i < (int) G[S].size(); i++) {
		int v = G[S][i];
		if (v == p) continue;
		dfs(v, S);
		subT[S] += 1+subT[v];
	}
}

void makeTree(int x, int l, int r) {
	if (l == r) seg[x] = valLoc[l];
	else {
		int mid = l + (r-l)/2;
		makeTree(2*x, l, mid);
		makeTree(2*x+1, mid+1, r);
		seg[x] = seg[2*x]+seg[2*x+1];
	}
}

void update(int x, int l, int r, int ind) {
	if (l > ind || r < ind) return;
	if (l == r) seg[x] = valLoc[ind];
	else {
		int mid = l + (r-l)/2;
		update(2*x, l, mid, ind);
		update(2*x+1, mid+1, r, ind);
		seg[x] = seg[2*x]+seg[2*x+1];
	}
}

pair<ll, bool> query(int x, int l, int r, int initInd, int endInd) {
	if (l > endInd || r < initInd) return mp(0, 0);
	else if (l >= initInd && r <= endInd) return mp(seg[x], 1);
	else {
		int mid = l + (r-l)/2;
		pair<ll, bool> left, right;
		left = query(2*x, l, mid, initInd, endInd);
		right = query(2*x+1, mid+1, r, initInd, endInd);
		if (left.second == 0) return mp(right.first, 1);
		else if (right.second == 0) return mp(left.first, 1);
		else return mp(left.first+right.first, 1);
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	// flatten tree into arr
	// use segment tree (sum) on arr vals
	// seed = +, pot = -
	// total at a node means unmatched total, as seeds travel to LCA with nearest pot and combine
	int T, Q, a, b, x;
	ll valA, valB;
	cin >> T;
	while(T--) {
		cin >> N >> Q;
		cnt = 0;
		G.assign(N, vi());
		pos.assign(N, 0);
		valLoc.assign(N, 0ll);
		subT.assign(N, 0);
		for (int i = 0; i < N-1; i++) {
			cin >> a >> b;
			G[a-1].pb(b-1);
			G[b-1].pb(a-1);
		}
		dfs(0, -1);
		seg.assign(4*N, 0ll);
		makeTree(1, 0, N-1);
		while(Q--) {
			cin >> a >> b >> x;
			a--;
			b--;
			if (x == 0) {
				// query
				// a is parent of b or viceversa
				if (pos[a] < pos[b]) {
					// a is parent of b
					valB = query(1, 0, N-1, pos[b], pos[b]+subT[b]).first;
					cout << abs(valB) << "\n";
				} else {
					// b is parent of a
					valA = query(1, 0, N-1, pos[a], pos[a]+subT[a]).first;
					cout << abs(valA) << "\n";
				}
			} else {
				valLoc[pos[a]] += x;
				update(1, 0, N-1, pos[a]);
				valLoc[pos[b]] -= x;
				update(1, 0, N-1, pos[b]);
			}
		}
	}
	return 0;
}
