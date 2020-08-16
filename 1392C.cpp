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
	int T, N;
	ll cur, last, curDiff, lastDiff, moves;
	cin >> T;
	vl A;
	while(T--) {
		cin >> N;
		A = vl(N);
		for (int i = 0; i < N; i++) cin >> A[i];
		last = A[0];
		moves = 0ll;
		lastDiff = 0ll;
		for (int i = 1; i < N; i++) {
			cur = max(A[i], last);
			curDiff = cur - A[i];
			moves += max(curDiff - lastDiff, 0ll);
			last = cur;
			lastDiff = curDiff;
		}
		cout << moves << "\n";
	}
	return 0;
}
