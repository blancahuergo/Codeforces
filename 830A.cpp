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

int N, K, O;
vi pers, keys;

bool check(int T) {
	int pos, curP = 0, ans;
	for (int i = 0; i < N; i++) {
		if (curP == K) return false;
		pos = pers[i];
		ans = -1;
		for (int j = curP; j < K; j++) {
			if (abs(keys[j] - pos) + abs(keys[j] - O) <= T) {
				ans = j;
				break;
			}
		}
		if (ans == -1) return false;
		curP = ans+1;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K >> O;
	pers = vi(N);
	keys = vi(K);
	for (int i = 0; i < N; i++) cin >> pers[i];
	for (int i = 0; i < K; i++) cin >> keys[i];
	sort(pers.begin(), pers.end());
	sort(keys.begin(), keys.end());
	int lo = 0, hi = 2e9, mid, ans;
	while(lo <= hi) {
		mid = lo + (hi-lo)/2;
		if (check(mid)) {
			hi = mid-1;
			ans = mid;
		} else lo = mid+1;
	}
	cout << ans << "\n";
	return 0;
}
