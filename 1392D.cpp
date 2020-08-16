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

int solve() {
	int cur = 1, lst = -1;
	vi nums;
	for (int i = 1; i < N; i++) {
		if (S[i] == S[i-1]) {
			cur++;
		} else {
			nums.push_back(cur);
			lst = i-1;
			cur = 1;
		}
	}
	if (lst != N-1) nums.push_back(cur);
	if (N > 3) {
		if (S[N-1] == S[0] && (int) nums.size() > 1) {
			nums[0] += nums[nums.size() - 1];
			nums.pop_back();
		}
	}
	if ((int) nums.size() == 1) return (nums[0]+2)/3;
	int ans = 0;
	for (int i = 0; i < (int) nums.size(); i++) {
		ans += nums[i]/3;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while(T--) {
		cin >> N;
		cin >> S;
		cout << solve() << "\n";
	}
	return 0;
}
