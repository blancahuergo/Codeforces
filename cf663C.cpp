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
typedef vector<string> vs;
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

ll N, mod = 1e9 + 7;

ll pot(ll n) {
    if (n == 0) return 1;
    ll x = pot(n/2);
    if (n % 2 == 0) return (x*x) % mod;
    return (((x*x) % mod)*2) % mod;
}

ll fact(ll n) {
    ll res = 1;
    while (n > 1) {
        res = (res * ((n/mod) % 2 ?  mod-1 : 1)) % mod;
        for (ll i = 2; i <= n%mod; ++i)
            res = (res * i) % mod;
        n /= mod;
    }
    return res % mod;
}

int main() {
	// all nodes linked to the closest elements to the right and left of itself which are greater than itself
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	cout << (fact(N) - pot(N-1) + mod) % mod << "\n";
	return 0;
}
