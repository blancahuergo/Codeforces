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
	int T;
	cin >> T;
	string s;
	vi ones;
	int cur;
	while(T--) {
		cin >> s;
		cur = 0;
		ones.clear();
		for (int i = 0; i < (int) s.length(); i++) {
			if (s[i] == '1') cur++;
			else if (cur > 0) {
				ones.push_back(cur);
				cur = 0;
			}
		}
		if (cur > 0) ones.push_back(cur);
		sort(ones.begin(), ones.end(), greater<int>());
		cur = 0;
		for (int i = 0; i < (int) ones.size(); i+=2) {
			cur += ones[i];
		}
		cout << cur << "\n";
	}
	return 0;
}
