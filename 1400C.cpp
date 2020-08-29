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
	int T, x, N;
	string S, W;
	cin >> T;
	while(T--) {
		cin >> S;
		N = S.length();
		cin >> x;
		W.assign(N, '1');
		for (int i = 0; i < N; i++) {
			if (S[i] == '0') {
				if (i + x < N) W[i+x] = '0';
				if (i - x >= 0) W[i-x] = '0';
			}
		}
		bool pos = true;
		for (int i = 0; i < N; i++) {
			if (S[i] == '1') {
				if (i + x < N && W[i+x] == '1') continue;
				if (i - x >= 0 && W[i-x] == '1') continue;
				pos = false;
				break;
			}
		}
		if (pos) cout << W << "\n";
		else cout << "-1\n";
	}
	return 0;
}
