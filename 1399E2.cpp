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

vvvl G;
int N;
ll S, oneSum, twoSum;
priority_queue<vector<ll>> app;

int dfs(int S, int par) {
	if (G[S].size() == 1 && par != -1) return 1;
	vl curP;
	int v, ans = 0, d;
	for (int i = 0; i < (int) G[S].size(); i++) {
		curP = G[S][i];
		v = curP[0];
		if (v == par) continue;
		d = dfs(v, S);
		app.push({curP[1] * ((ll) d) - ((curP[1]/2) * ((ll) d)), curP[1] * ((ll) d), d, curP[2]});
		if (curP[2] == 1) oneSum += curP[1] * ((ll) d);
		else twoSum += curP[1] * ((ll) d);
		ans += d;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, a, b, c, d;
	ll diff, fullCost, e, newCost;
	cin >> T;
	vl curP, ones, twos;
	while(T--) {
		cin >> N >> S;
		G.assign(N, vvl());
		for (int i = 0; i < N-1; i++) {
			cin >> a >> b >> c >> d;
			a--;
			b--;
			G[a].push_back({b, c, d});
			G[b].push_back({a, c, d});
		}
		while(!app.empty()) app.pop();
		oneSum = twoSum = 0ll;
		dfs(0, -1);
		ones.clear();
		twos.clear();
		ones.push_back(oneSum);
		twos.push_back(twoSum);
		while(oneSum || twoSum) {
			curP = app.top();
			app.pop();
			diff = curP[0];
			fullCost = curP[1];
			e = curP[2];
			if (curP[3] == 1) oneSum -= diff;
			else twoSum -= diff;
			newCost = fullCost - diff;
			app.push({newCost - ((newCost/e)/2)*e, newCost, e, curP[3]});
			if (curP[3] == 1) ones.push_back(oneSum);
			else twos.push_back(twoSum);
		}
		c = ones.size() + 2*twos.size();
		int j = twos.size()-1;
		for (int i = 0; i < (int) ones.size(); i++) {
			while(j > 0 && ones[i] + twos[j-1] <= S) j--;
			if (ones[i] + twos[j] <= S) {
				c = min(c, i + 2*j);
			}
		}
		cout << c << "\n";
	}
	return 0;
}
