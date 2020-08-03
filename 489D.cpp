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
vvi G, con;
int ans = 0;

int check(int a, int c) {
	int b, d, ret = 0;
	for (int i = 0; i < (int) G[a].size(); i++) {
		b = G[a][i];
		if (con[b][c] == 0) continue;
		for (int j = i+1; j < (int) G[a].size(); j++) {
			d = G[a][j];
			if (con[d][c] == 1) ret++;
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int M, u, v;
	cin >> N >> M;
	G.assign(N, vi());
	con.assign(N, vi(N, 0));
	while(M--) {
		cin >> u >> v;
		u--;
		v--;
		G[u].emplace_back(v);
		con[u][v] = 1;
	}
	for (int a = 0; a < N; a++) {
		for (int c = 0; c < N; c++) {
			if (a == c) continue;
			ans += check(a, c);
		}
	}
	cout << ans << "\n";
	return 0;
}
