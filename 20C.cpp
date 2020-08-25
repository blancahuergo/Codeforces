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

vvpii G;
int N;
vi pre;

void Dijkstra() {
	vl dist;
	vi vis;
	vis.assign(N, false);
	dist.assign(N, LLONG_MAX);
	pre.assign(N, -2);
	dist[0] = 0;
	pre[0] = -1;
	priority_queue<pair<ll, int>> Q;
	Q.push(mp(0, 0));
	pair<ll, int> curP;
	int v, u;
	ll disV, cst;
	while(Q.size()) {
		curP = Q.top();
		Q.pop();
		v = curP.second;
		vis[v] = true;
		disV = -curP.first;
		for (int i = 0; i < (int) G[v].size(); i++) {
			u = G[v][i].first;
			cst = G[v][i].second;
			if (!vis[u] && dist[u] > disV + cst) {
				dist[u] = disV + cst;
				pre[u] = v;
				Q.push(mp(-dist[u], u));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int M, a, b, c;
	cin >> N >> M;
	G.assign(N, vpii());
	while(M--) {
		cin >> a >> b >> c;
		a--;
		b--;
		G[a].pb(mp(b, c));
		G[b].pb(mp(a, c));
	}
	Dijkstra();
	if (pre[N-1] == -2) cout << "-1";
	else {
		vi ST;
		int cur = N-1;
		while(cur != -1) {
			ST.push_back(cur+1);
			cur = pre[cur];
		}
		for (int i = (int) ST.size()-1; i >= 0; i--) cout << ST[i] << " ";
	}
	return 0;
}
