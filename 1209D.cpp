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

int N, K;
vvi G;
vector<bool> vis;

void dfs(int S) {
	vis[S] = true;
	for (int i = 0; i < (int) G[S].size(); i++) {
		int v = G[S][i];
		if (!vis[v]) dfs(v);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;
	int a, b;
	G.assign(N, vi());
	for (int i = 0; i < K; i++) {
		cin >> a >> b;
		a--;
		b--;
		G[b].emplace_back(a);
		G[a].emplace_back(b);
	}
	vis.assign(N, false);
	int C = 0;
	for (int i = 0; i < N; i++) {
		if (!vis[i]) {
			C++;
			dfs(i);
		}
	}
	cout << K - (N-C) << "\n";
	return 0;
}
