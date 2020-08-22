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
typedef unsigned long long int ll;
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

int N;
vvi G;
vpii E;
vl used, fact, subT;
ll mod = 1e9 + 7;

ll dfs(int S, int par) {
	if (subT[S]) return subT[S];
	ll ans = 1ll;
	for (int i = 0; i < (int) G[S].size(); i++) {
		if (G[S][i] != par) ans += dfs(G[S][i], S);
	}
	return subT[S] = ans;
}

void fillEdges() {
	int a, b;
	ll cur, lN = ((ll) N);
	for (int i = 0; i < N-1; i++) {
		a = E[i].f;
		b = E[i].s;
		cur = min(subT[a], subT[b]);
		used[i] = cur*(lN-cur);
	}
	sort(used.begin(), used.end());
}

void changeFact() {
	if ((int) fact.size() > N-1) {
		sort(fact.begin(), fact.end());
		ll ans = 1ll;
		while((int) fact.size() > N-2) {
			ans *= fact[(int)fact.size()-1];
			ans %= mod;
			fact.pop_back();
		}
		fact.push_back(ans);
	} else {
		while((int) fact.size() < N-1) fact.push_back(1ll);
		sort(fact.begin(), fact.end());
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, nFact;
	ll ans;
	cin >> T;
	while(T--) {
		cin >> N;
		int a, b;
		G.assign(N, vi());
		subT.assign(N, 0ll);
		E.assign(N-1, pii());
		used.assign(N-1, 0ll);
		for (int i = 0; i < N-1; i++) {
			cin >> a >> b;
			a--;
			b--;
			G[a].pb(b);
			G[b].pb(a);
			E[i] = mp(a, b);
		}
		cin >> nFact;
		fact.assign(nFact, 0ll);
		for (int i = 0; i < nFact; i++) cin >> fact[i];
		dfs(0, -1);
		fillEdges();
		changeFact();
		ans = 0ll;
		for (int i = 0; i < N-1; i++) {
			ans += ((fact[i] % mod)*used[i])%mod;
			ans %= mod;
		}
		cout << ans << "\n";
	}
	return 0;
}
