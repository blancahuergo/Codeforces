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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, i, ans, j;
	ll x;
	cin >> T;
	vl sq, pows;
	for (ll p = 1; p <= (1<<30); p <<= 1) {
		pows.pb(p);
		i = 0;
		j = (int) pows.size()-1;
		x = 0ll;
		while(i < (int) pows.size()) {
			x += pows[i]*pows[j]*pows[j];
			i++;
			j--;
		}
		sq.pb(x);
	}
	while(T--) {
		cin >> x;
		i = ans = 0;
		while(i < (int) sq.size()) {
			if (x < sq[i]) break;
			x -= sq[i];
			ans++;
			i++;
		}
		cout << ans << "\n";
	}
	return 0;
}
