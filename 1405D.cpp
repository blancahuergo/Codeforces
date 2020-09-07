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

int N;
vvi G;
int da, db;

int diam() {
	vi dist;
	queue<int> Q;
	dist.assign(N, 1e9);
	dist[0] = 0;
	Q.push(0);
	int u;
	while(!Q.empty()) {
		u = Q.front();
		Q.pop();
		for (auto v: G[u]) {
			if (dist[v] > dist[u]+1) {
				dist[v] = dist[u]+1;
				Q.push(v);
			}
		}
	}
	dist.assign(N, 1e9);
	dist[u] = 0;
	Q.push(u);
	while(!Q.empty()) {
		u = Q.front();
		Q.pop();
		for (auto v: G[u]) {
			if (dist[v] > dist[u]+1) {
				dist[v] = dist[u]+1;
				Q.push(v);
			}
		}
	}
	return dist[u];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, u, v, D, aInit, bInit, aDist, bDist, ds;
	vi dist;
	cin >> T;
	while(T--) {
		cin >> N >> aInit >> bInit >> aDist >> bDist;
		aInit--;
		bInit--;
		G.assign(N, vi());
		for (int i = 0; i < N-1; i++) {
			cin >> u >> v;
			u--;
			v--;
			G[u].pb(v);
			G[v].pb(u);
		}
		dist.assign(N, 1e9);
		queue<int> Q;
		Q.push(aInit);
		dist[aInit] = 0;
		while(!Q.empty()) {
			u = Q.front();
			Q.pop();
			for (auto v: G[u]) {
				if (dist[v] > dist[u]+1) {
					dist[v] = dist[u]+1;
					Q.push(v);
				}
			}
		}
		ds = dist[bInit];
		if (ds <= aDist) {
			cout << "Alice\n";
			continue;
		}
		D = diam();
		if (aDist*2 >= D) cout << "Alice\n";
		else if (bDist > 2*aDist) cout << "Bob\n";
		else cout << "Alice\n";
	}
	return 0;
}
