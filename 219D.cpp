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
vector<bool> vis;
vi add, DP;

int dfs(int S) {
	if (vis[S]) return DP[S];
	vis[S] = true;
	int ans = 0, v;
	pii curP;
	for (int i = 0; i < (int) G[S].size(); i++) {
		curP = G[S][i];
		v = curP.first;
		if (!vis[v]) {
			ans += curP.second;
			add[v] = add[S];
			if (curP.second == 1) add[v]++;
			else add[v]--;
			ans += dfs(v);
		}
	}
	return DP[S] = ans;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int a, b;
	G.assign(N, vpii());
	DP = add = vi(N, 0);
	vis.assign(N, false);
	for (int i = 0; i < N-1; i++) {
		cin >> a >> b;
		a--;
		b--;
		G[a].push_back(make_pair(b, 0));
		G[b].push_back(make_pair(a, 1));
	}
	int ans = N-1, cur;
	vi res;
	dfs(0);
	for (int i = 0; i < N; i++) {
		cur = DP[0] - add[i];
		if (cur < ans) {
			ans = cur;
			res.clear();
			res.emplace_back(i+1);
		} else if (cur == ans) res.emplace_back(i+1);
	}
	cout << ans << "\n";
	cout << res[0];
	for (int i = 1; i < (int) res.size(); i++) cout << " " << res[i];
	cout << "\n";
	return 0;
}
