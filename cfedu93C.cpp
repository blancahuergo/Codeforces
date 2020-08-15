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
	int T, N, curSum;
	ll tot;
	unordered_map<int, int> past;
	cin >> T;
	char c;
	while(T--) {
		cin >> N;
		curSum = 0;
		tot = 0ll;
		past.clear();
		for (int i = 0; i < N; i++) {
			cin >> c;
			curSum += c - '0' - 1;
			if (curSum == 0) tot++;
			if (past.find(curSum) != past.end()) {
				tot += past[curSum];
				past[curSum]++;
			} else past[curSum] = 1;
		}
		cout << tot << "\n";
	}
	return 0;
}
