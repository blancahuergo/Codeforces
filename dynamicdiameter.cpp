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

int N, diam;
vvi G;
vi dist1, dist2;

void calcDist() {
	vi dist0 = vi(N, 2e9);
	dist0[0] = 0;
	queue<int> Q;
	Q.push(0);
	int furA;
	while(!Q.empty()) {
		int u = Q.front();
		Q.pop();
		furA = u;
		for (int i = 0; i < (int) G[u].size(); i++) {
			int v = G[u][i];
			if (dist0[v] > dist0[u]+1) {
				dist0[v] = dist0[u]+1;
				Q.push(v);
			}
		}
	}
	dist1.assign(N, 2e9);
	dist1[furA] = 0;
	Q.push(furA);
	while(!Q.empty()) {
		int u = Q.front();
		Q.pop();
		furA = u;
		for (int i = 0; i < (int) G[u].size(); i++) {
			int v = G[u][i];
			if (dist1[v] > dist1[u]+1) {
				dist1[v] = dist1[u]+1;
				Q.push(v);
			}
		}
	}
	diam = dist1[furA];
	dist2.assign(N, 2e9);
	dist2[furA] = 0;
	Q.push(furA);
	while(!Q.empty()) {
		int u = Q.front();
		Q.pop();
		for (int i = 0; i < (int) G[u].size(); i++) {
			int v = G[u][i];
			if (dist2[v] > dist2[u]+1) {
				dist2[v] = dist2[u]+1;
				Q.push(v);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	G.assign(N, vi());
	int a, b;
	for (int i = 0; i < N-1; i++) {
		cin >> a >> b;
		G[a-1].pb(b-1);
		G[b-1].pb(a-1);
	}
	calcDist();
	for (int i = 0; i < N; i++) {
		cout << max(diam, 1+max(dist1[i], dist2[i])) << "\n";
	}
	return 0;
}
