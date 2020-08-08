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
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define len(v) ((int)v.size())
#define all(v) v.begin(), v.end()

vector<vector<pair<int, ll>>> G;
int N;
ll S, curSum;
priority_queue<vector<ll>> app;

int dfs(int S, int par) {
	if (G[S].size() == 1 && par != -1) return 1;
	pair<int, ll> curP;
	int v, ans = 0, d;
	for (int i = 0; i < (int) G[S].size(); i++) {
		curP = G[S][i];
		v = curP.first;
		if (v == par) continue;
		d = dfs(v, S);
		app.push({curP.second * ((ll) d) - ((curP.second/2) * ((ll) d)), curP.second * ((ll) d), d});
		curSum += curP.second * ((ll) d);
		ans += d;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, a, b;
	ll c, diff, fullCost, e, newCost;
	cin >> T;
	vl curP;
	while(T--) {
		cin >> N >> S;
		G.assign(N, vector<pair<int, ll>>());
		for (int i = 0; i < N-1; i++) {
			cin >> a >> b;
			cin >> c;
			a--;
			b--;
			G[a].push_back(make_pair(b, c));
			G[b].push_back(make_pair(a, c));
		}
		while(!app.empty()) app.pop();
		curSum = 0ll;
		dfs(0, -1);
		c = 0ll;
		while(curSum > S) {
			curP = app.top();
			app.pop();
			diff = curP[0];
			fullCost = curP[1];
			e = curP[2];
			curSum -= diff;
			newCost = fullCost - diff;
			app.push({newCost - ((newCost/e)/2)*e, newCost, e});
			c++;
		}
		cout << c << "\n";
	}
	return 0;
}
