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


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, a1, b1, c1, a2, b2, c2, ans, cur;
	cin >> T;
	while(T--) {
		cin >> a1 >> b1 >> c1; // 0, 1, 2
		cin >> a2 >> b2 >> c2;
		// first, get all 2-1's possible
		ans = min(c1, b2);
		c1 -= ans;
		b2 -= ans;
		ans *= 2;
		// use up all 2's in the 2nd row
		cur = min(c2, a1);
		a1 -= cur;
		c2 -= cur;
		cur = min(c2, c1);
		c2 -= cur;
		c1 -= cur;
		// if there are any 2's left, they will be combined with the remaining 1's from above
		cur = min(c2, b1);
		ans -= cur*2;
		cout << ans << "\n";
	}
	return 0;
}
