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

int N;
string S;
vi P, F;

bool check(int T) {
	int cur = 0, pos, init, curT;
	for (int i = 0; i < (int) P.size(); i++) {
		pos = P[i];
		// go as far as possible to the right while still having time to eat F[cur] if it is to its left
		// if F[cur] is to its right, go as far as possible to the right
		if (F[cur] < pos) {
			init = cur;
			while(cur < (int) F.size()) {
				if (F[cur] > pos) curT = min(2*(pos - F[init]) + F[cur] - pos, 2*(F[cur] - pos) + pos - F[init]);
				else curT = pos - F[init];
				if (curT <= T) cur++;
				else break;
			}
		} else {
			while(cur < (int) F.size() && F[cur] - pos <= T) {
				cur++;
			}
		}
		if (cur == (int) F.size()) return true;
	}
	return cur == (int) F.size();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	cin >> S;
	for (int i = 0; i < N; i++) {
		if (S[i] == 'P') P.push_back(i);
		else if (S[i] == '*') F.push_back(i);
	}
	int lo = 0, hi = 2e9, mid, ans = 0;
	while(lo <= hi) {
		mid = lo + (hi - lo)/2;
		if (check(mid)) {
			ans = mid;
			hi = mid - 1;
		} else lo = mid+1;
	}
	cout << ans;
	return 0;
}
