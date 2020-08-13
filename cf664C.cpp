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
	int N, M;
	cin >> N >> M;
	int A[N], B[M];
	vvi combs = vvi(N, vi(M));
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < M; i++) cin >> B[i];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			combs[i][j] = A[i]&B[j];
		}
	}
	for (int i = 0; i < N; i++) sort(combs[i].begin(), combs[i].end());
	sort(combs.begin(), combs.end());
	int c = combs[N-1][0], cur;
	for (int i = N-2; i >= 0; i--) {
		cur = 2e9 + 1;
		for (int j = 0; j < M; j++) {
			cur = min(cur, c | combs[i][j]);
		}
		c = cur;
	}
	cout << c << "\n";
	return 0;
}
