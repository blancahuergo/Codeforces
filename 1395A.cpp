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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, r, g, b, w, tot;
	cin >> T;
	while(T--) {
		cin >> r >> g >> b >> w;
		tot = 0;
		if (r % 2 == 0) tot++;
		if (g % 2 == 0) tot++;
		if (b % 2 == 0) tot++;
		if (w % 2 == 0) tot++;
		if (tot >= 3) {
			cout << "Yes\n";
			continue;
		}
		if (r == 0 || g == 0 || b == 0) {
			cout << "No\n";
			continue;
		}
		r--;
		g--;
		b--;
		w += 3;
		tot = 0;
		if (r % 2 == 0) tot++;
		if (g % 2 == 0) tot++;
		if (b % 2 == 0) tot++;
		if (w % 2 == 0) tot++;
		if (tot >= 3) {
			cout << "Yes\n";
		} else cout << "No\n";
	}
	return 0;
}
