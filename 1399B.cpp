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
	int T, N, minA, minB, sub;
	ll moves;
	cin >> T;
	while(T--) {
		cin >> N;
		int A[N], B[N];
		moves = 0ll;
		minA = minB = 2e9;
		for (int i = 0; i < N; i++) {
			cin >> A[i];
			minA = min(minA, A[i]);
		}
		for (int i = 0; i < N; i++) {
			cin >> B[i];
			minB = min(minB, B[i]);
		}
		for (int i = 0; i < N; i++) {
			sub = min(A[i] - minA, B[i] - minB);
			A[i] -= sub;
			B[i] -= sub;
			moves += (ll) sub;
			if (A[i] > minA) moves += (ll) (A[i] - minA);
			else moves += (ll) (B[i] - minB);
		}
		cout << moves << "\n";
	}
	return 0;
}
