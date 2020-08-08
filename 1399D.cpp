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
#define fs first
#define sc second
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
	int T, N, c;
	vi lastOne, lastZer;
	string s;
	cin >> T;
	while(T--) {
		cin >> N;
		cin >> s;
		lastOne.clear();
		lastZer.clear();
		c = 0;
		int seq[N];
		for (int i = 0; i < N; i++) {
			if (s[i] == '0') {
				if (lastOne.size() == 0) {
					c++;
					seq[i] = c;
					lastZer.push_back(i);
				} else {
					seq[i] = seq[lastOne[lastOne.size()-1]];
					lastZer.push_back(i);
					lastOne.pop_back();
				}
			} else {
				if (lastZer.size() == 0) {
					c++;
					seq[i] = c;
					lastOne.push_back(i);
				} else {
					seq[i] = seq[lastZer[lastZer.size()-1]];
					lastOne.push_back(i);
					lastZer.pop_back();
				}
			}
		}
		cout << c << "\n";
		cout << seq[0];
		for (int i = 1; i < N; i++) cout << " " << seq[i];
		cout << "\n";
	}
	return 0;
}
