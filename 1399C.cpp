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

int N, cit;
vvi G;
vi H, P, peop, pre;

int dfs(int S, int par) {
	int v, ans = P[S];
	for (int i = 0; i < (int) G[S].size(); i++) {
		v = G[S][i];
		if (v != par) {
			pre[v] = S;
			ans += dfs(v, S);
		}
	}
	return peop[S] = ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, u, v, goodU, goodC;
	cin >> T;
	while(T--) {
		cin >> N >> cit;
		H = P = vi(N);
		G.assign(N, vi());
		for (int i = 0; i < N; i++) cin >> P[i];
		for (int i = 0; i < N; i++) cin >> H[i];
		for (int i = 0; i < N-1; i++) {
			cin >> u >> v;
			u--;
			v--;
			G[u].emplace_back(v);
			G[v].emplace_back(u);
		}
		peop.assign(N, -1);
		pre.assign(N, -1);
		dfs(0, -1);
		bool pos = true;
		u = 0;
		while((u < N) && pos) {
			if (((peop[u] + H[u])&1) || (H[u] > peop[u])) {
				pos = false;
				break;
			}
			goodC = 0;
			goodU = (peop[u]+H[u])/2;
			for (int i = 0; i < (int) G[u].size(); i++) {
				v = G[u][i];
				if (pre[v] != u) continue;
				if (((peop[v]+H[v])&1) || (H[v] > peop[v])) {
					pos = false;
					break;
				}
				goodC += (peop[v]+H[v])/2;
			}
			if (goodC > goodU) {
				pos = false;
				break;
			}
			u++;
		}
		if (pos) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
