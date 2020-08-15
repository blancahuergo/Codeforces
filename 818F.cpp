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

ll func(ll N, ll K) {
	ll x = K*(K-1)/2;
	if (K <= N) return N-K + min(N-K, x);
	else return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int Q, N;
	unordered_map<int, ll> mem;
	cin >> Q;
	while(Q--) {
		cin >> N;
		if (mem.find(N) != mem.end()) {
			cout << mem[N] << "\n";
			continue;
		}
		ll lo = 1, hi = 2e9, mid1, mid2, ans = 0ll;
		while(hi - lo > 7) {
			mid1 = lo + (hi-lo)/3;
			mid2 = hi - (hi-lo)/3;
			if (func(N, mid1) < func(N, mid2)) lo = mid1;
			else hi = mid2;
		}
		for (ll i = lo; i <= hi; i++) {
			ans = max(ans, func(N, i));
		}
		cout << ans << "\n";
		mem[N] = ans;
	}
	return 0;
}
