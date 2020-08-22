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
	int T, N, k, ans;
	cin >> T;
	while(T--) {
		cin >> N >> k;
		if (k == 0) cout << N%2 << "\n";
		else {
			if (k & 1) {
				if (N >= k) ans = 1 - (N%2);
				else ans = k-N;
			} else {
				if (N >= k) ans = N%2;
				else ans = k-N;
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
