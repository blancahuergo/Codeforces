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
	int T, N;
	bool pos;
	cin >> T;
	while(T--) {
		cin >> N;
		int A[N];
		for (int i = 0; i < N; i++) cin >> A[i];
		sort(A, A+N);
		pos = true;
		for (int i = 1; i < N; i++) {
			if (A[i] > A[i-1]+1) {
				pos = false;
				break;
			}
		}
		if (pos) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
