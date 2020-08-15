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

vi R, G, B;
vvvi DP;

ll calc(int r, int g, int b) {
	if (DP[r][g][b] != -1) return DP[r][g][b];
	ll ans = 0ll;
	if (r && g) ans = max(ans, R[(int) R.size() - r]*G[(int) G.size() - g] + calc(r-1, g-1, b));
	if (r && b) ans = max(ans, R[(int) R.size() - r]*B[(int) B.size() - b] + calc(r-1, g, b-1));
	if (g && b) ans = max(ans, G[(int) G.size() - g]*B[(int) B.size() - b] + calc(r, g-1, b-1));
	return DP[r][g][b] = ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int r, g, b;
	cin >> r >> g >> b;
	R = vi(r);
	G = vi(g);
	B = vi(b);
	for (int l = 0; l < r; l++) cin >> R[l];
	for (int l = 0; l < g; l++) cin >> G[l];
	for (int l = 0; l < b; l++) cin >> B[l];
	sort(R.begin(), R.end(), greater<int>());
	sort(G.begin(), G.end(), greater<int>());
	sort(B.begin(), B.end(), greater<int>());
	DP.assign(r+1, vvi(g+1, vi(b+1, -1)));
	cout << calc(r, g, b) << "\n";
	return 0;
}
