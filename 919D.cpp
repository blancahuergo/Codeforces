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

int N, rec;
vvi G, DP;
vi lets;
vector<bool> vis, curVis;
bool pos;

void dfs(int S) {
	if (vis[S]) return;
	int v;
	vis[S] = true;
	curVis[S] = true;
	vi ret = vi(26, 0);
	for (int i = 0; i < (int) G[S].size(); i++) {
		v = G[S][i];
		if (curVis[v]) {
			pos = false;
			return;
		}
		if (!vis[v]) dfs(v);
		for (int c = 0; c < 26; c++) DP[S][c] = max(DP[S][c], DP[v][c]);
	}
	DP[S][lets[S]]++;
	curVis[S] = false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int M;
	cin >> N >> M;
	string s;
	cin >> s;
	lets.assign(N, 0);
	for (int i = 0; i < N; i++) lets[i] = s[i] - 'a';
	int a, b;
	G.assign(N, vi());
	while(M--) {
		cin >> a >> b;
		G[a-1].emplace_back(b-1);
	}
	pos = true;
	rec = 0;
	vis.assign(N, false);
	DP.assign(N, vi(26, 0));
	for (int i = 0; i < N; i++) {
		if (!vis[i]) {
			curVis.assign(N, false);
			dfs(i);
			for (int c = 0; c < 26; c++) rec = max(rec, DP[i][c]);
		}
	}
	if (pos) cout << rec << "\n";
	else cout << "-1\n";
	return 0;
}
