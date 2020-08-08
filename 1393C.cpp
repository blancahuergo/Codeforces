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
	int T, N, cur, maxD, posD;
	cin >> T;
	vi A, lastPos;
	pii curP;
	while(T--) {
		cin >> N;
		A.assign(N, 0);
		maxD = 0;
		for (int j = 0; j < N; j++) {
			cin >> cur;
			A[cur-1]++;
			maxD = max(maxD, A[cur-1]);
		}
		if (maxD == N) {
			cout << "0\n";
			continue;
		}
		posD = 0;
		for (int i = 0; i < N; i++) {
			if (A[i] == maxD) posD++;
		}
		cout << (N - posD*maxD)/(maxD-1)+posD-1 << "\n";
	}
	return 0;
}
