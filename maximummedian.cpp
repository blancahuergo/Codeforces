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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K;
	cin >> N >> K;
	int A[N];
	for (int i = 0; i < N; i++) cin >> A[i];
	if (N > 1) {
		sort(A, A+N);
		int lo = A[0], hi = 2e9, mid, ans;
		ll x;
		while(lo <= hi) {
			mid = lo + (hi-lo)/2;
			x = 0ll;
			for (int i = (N-1)/2; i < N; i++) x += max(0, mid - A[i]);
			if (x <= K) {
				lo = mid+1;
				ans = mid;
			} else hi = mid-1;
		}
		cout << ans << "\n";
	} else {
		cout << A[0]+K << "\n";
	}
	return 0;
}
