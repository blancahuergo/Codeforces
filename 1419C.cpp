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
	int T, N, K, mn, mx, cur, same;
	cin >> T;
	ll sm;
	while(T--) {
		cin >> N >> K;
		mn = INT_MAX;
		mx = INT_MIN;
		sm = 0ll;
		same = 0;
		for (int i = 0; i < N; i++) {
			cin >> cur;
			sm += K - cur;
			mn = min(mn, cur);
			mx = max(mx, cur);
			if (cur == K) same = 1;
		}
		if (mx == mn && mx == K) cout << "0\n";
		else if (sm == 0 || same) cout << "1\n";
		else cout << "2\n";
	}
	return 0;
}
