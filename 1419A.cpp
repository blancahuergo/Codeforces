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
	int T, N;
	string s;
	cin >> T;
	bool found;
	while(T--) {
		cin >> N;
		cin >> s;
		found = false;
		if (N&1) {
			for (int i = 0; i < N; i += 2) {
				if ((s[i] - '0')&1) {
					found = true;
					cout << "1\n";
					break;
				}
			}
			if (!found) cout << "2\n";
		} else {
			for (int i = 1; i < N; i += 2) {
				if (!((s[i] - '0')&1)) {
					found = true;
					cout << "2\n";
					break;
				}
			}
			if (!found) cout << "1\n";
		}
	}
	return 0;
}
