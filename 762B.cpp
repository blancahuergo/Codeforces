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

int A, B, C;
vi u, p;

void solve() {
	int ans = 0, i = 0, j = 0, mn, mnPile;
	ll cost = 0ll;
	while(i < (int) u.size() || j < (int) p.size()) {
		if (A+B+C == 0) break;
		mn = -1;
		if (i < (int) u.size() && (A || C)) {
			mn = u[i];
			mnPile = 0;
		}
		if (j < (int) p.size() && (B || C)) {
			if (mn == -1 || p[j] < mn) {
				mn = p[j];
				mnPile = 1;
			}
		}
		if (mn == -1) break;
		cost += mn;
		ans++;
		if (mnPile) {
			j++;
			if (B) B--;
			else C--;
		}
		else {
			i++;
			if (A) A--;
			else C--;
		}
	}
	cout << ans << " " << cost << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> A >> B >> C;
	int M, cos;
	string S;
	cin >> M;
	while(M--) {
		cin >> cos >> S;
		if (S[0] == 'U') u.push_back(cos);
		else p.push_back(cos);
	}
	sort(u.begin(), u.end());
	sort(p.begin(), p.end());
	solve();
	return 0;
}
