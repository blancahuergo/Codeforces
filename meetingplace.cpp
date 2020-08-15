#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <cfloat>
#include <cmath>
#include <climits>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
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

int N;
vector<double> coords, speeds;

bool check(double T) {
	double mx = coords[0] + T*speeds[0], mn = coords[0] - T*speeds[0], curmx, curmn;
	for (int i = 0; i < N; i++) {
		curmx = coords[i] + T*speeds[i];
		curmn = coords[i] - T*speeds[i];
		if (curmn > mx || curmx < mn) return false;
		mx = min(mx, curmx);
		mn = max(mn, curmn);
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	cout << fixed << setprecision(8);
	coords = speeds = vector<double>(N);
	for (int i = 0; i < N; i++) cin >> coords[i];
	for (int i = 0; i < N; i++) cin >> speeds[i];
	double lo = 0, hi = DBL_MAX, mid, ans;
	while(hi - lo > 0.0000001) {
		mid = lo + (hi-lo)/2;
		if (check(mid)) {
			ans = mid;
			hi = mid;
		} else lo = mid;
	}
	cout << ans << "\n";
	return 0;
}
