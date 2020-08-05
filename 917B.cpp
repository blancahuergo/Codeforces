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

int N;
vector<vpii> G;
vvvi DP;

int dfs(int u, int v, int c) {
	if (DP[u][v][c] != -1) return DP[u][v][c];
	pii curP;
	for (int i = 0; i < (int) G[u].size(); i++) {
		curP = G[u][i];
		if (curP.second >= c && dfs(v, curP.first, curP.second) == 0) return DP[u][v][c] = 1;
	}
	return DP[u][v][c] = 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int M;
	cin >> N >> M;
	int a, b;
	char c;
	G.assign(N, vpii());
	DP.assign(N, vvi(N, vi(26, -1)));
	while(M--) {
		cin >> a >> b >> c;
		a--;
		b--;
		G[a].push_back(make_pair(b, c - 'a'));
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (dfs(i, j, 0) == 1) cout << "A";
			else cout << "B";
		}
		cout << "\n";
	}
	return 0;
}
