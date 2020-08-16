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
	int T, N, maxI, newM;
	ll K;
	cin >> T;
	vi nums;
	while(T--) {
		cin >> N >> K;
		nums = vi(N);
		maxI = -2e9;
		for (int i = 0; i < N; i++) {
			cin >> nums[i];
			maxI = max(maxI, nums[i]);
		}
		if (N == 1) cout << "0\n";
		else if (K % 2 == 0) {
			newM = -2e9 - 10;
			for (int i = 0; i < N; i++) {
				nums[i] = maxI - nums[i];
				newM = max(newM, nums[i]);
			}
			cout << (newM - nums[0]);
			for (int i = 1; i < N; i++) cout << " " << (newM - nums[i]);
			cout << "\n";
		} else {
			cout << (maxI - nums[0]);
			for (int i = 1; i < N; i++) cout << " " << (maxI - nums[i]);
			cout << "\n";
		}
	}
	return 0;
}
