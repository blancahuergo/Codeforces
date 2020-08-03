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

int N, mod = 998244353;
vvi G;
vi C;
int ev, odd;
bool pos;

ll expo(int n) {
    if (n == 0) return 1;
    ll x = expo(n/2);
    if (n % 2 == 0) return (x*x) % mod;
    return (x*((x*2) % mod)) % mod;
}

void dfs(int S) {
	if (C[S] == 1) odd++;
	else ev++;
	for (int i = 0; i < (int) G[S].size(); i++) {
		int v = G[S][i];
		if (C[v] == -1) {
			C[v] = 1 - C[S];
			dfs(v);
		} else if (C[v] == C[S]) pos = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, M, a, b;
	ll ans;
	cin >> T;
	while(T--) {
		cin >> N >> M;
		G.assign(N, vi());
		while(M--) {
			cin >> a >> b;
			a--;
			b--;
			G[a].emplace_back(b);
			G[b].emplace_back(a);
		}
		C.assign(N, -1);
		ans = 1;
		for (int i = 0; i < N; i++) {
			if (C[i] == -1) {
				C[i] = 1;
				ev = odd = 0;
				pos = true;
				dfs(i);
				if (pos) {
					ans *= ((expo(ev) + expo(odd))%mod);
					ans %= mod;
				} else ans = 0;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
