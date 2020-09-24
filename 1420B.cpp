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
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<vvvl> vvvvl;
typedef vector<string> vs;
#define fir first
#define sec second
#define pb push_back
#define eb emplace_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define len(v) ((int)v.size())
#define all(v) v.begin(), v.end()

vi A;
int N;

ll comb(ll k) {
	return k*(k-1)/2;
}

ll solve() {
	int p = 1;
	ll ans = 0ll, cur = 0ll;
	for (int i = 0; i < N; i++) {
		if (A[i] < p) cur++;
		else {
			ans += comb(cur);
			while(A[i] >= p) p *= 2;
			cur = 1ll;
		}
	}
	ans += comb(cur);
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while(T--) {
		cin >> N;
		A = vi(N);
		for (int i = 0; i < N; i++) cin >> A[i];
		sort(A.begin(), A.end());
		cout << solve() << "\n";
	}
	return 0;
}
