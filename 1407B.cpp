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

vvi calcGCD;

int gcd(int a, int b) {
	if (b == 0) return a;
	if (calcGCD[a][b]) return calcGCD[a][b];
	return calcGCD[a][b] = calcGCD[b][a] = gcd(b, a%b);
}

int mx;

bool cmp(pii A, pii B) {
	if (A.f == mx) return true;
	if (B.f == mx) return false;
	else return A.s > B.s;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N, cur, curGCD, numGCD;
	pii curP;
	vi A, B;
	cin >> T;
	calcGCD.assign(1001, vi(1001, 0));
	while(T--) {
		cin >> N;
		A.assign(N, 0);
		B.assign(N, 0);
		mx = 0;
		for (int i = 0; i < N; i++) {
			cin >> A[i];
			mx = max(mx, A[i]);
		}
		priority_queue<pii> PQ;
		cur = 0;
		for (int i = 0; i < N; i++) {
			if (A[i] == mx) {
				B[cur] = mx;
				cur++;
			}
			else PQ.push(mp(gcd(A[i], mx), A[i]));
		}
		curGCD = mx;
		while(PQ.size()) {
			curP = PQ.top();
			PQ.pop();
			numGCD = gcd(curGCD, curP.s);
			if (numGCD == curP.f) {
				curGCD = numGCD;
				B[cur] = curP.s;
				cur++;
			} else PQ.push(mp(numGCD, curP.s));
		}
		cout << B[0];
		for (int i = 1; i < (int) B.size(); i++) cout << " " << B[i];
		cout << "\n";
	}
	return 0;
}
