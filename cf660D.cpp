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

int N;
vi A, B;
vvi G;
vector<bool> vis;
vl DP;
vi ord, cur;

ll calc(int S) {
	if (vis[S]) return DP[S];
	vis[S] = true;
	int v;
	ll ret = (ll) A[S], cV;
	for (int i = 0; i < (int) G[S].size(); i++) {
		v = G[S][i];
		cV = calc(v);
		if (cV >= 0) ret += cV;
	}
	return DP[S] = ret;
}

void makeOrder(int S) {
	int v;
	ll cV;
	vi cc;
	for (int i = 0; i < (int) G[S].size(); i++) {
		v = G[S][i];
		cV = calc(v);
		makeOrder(v);
		if (cV >= 0) {
			ord.emplace_back(v+1);
		} else cc.emplace_back(v+1);
	}
	if (B[S] == -1) ord.emplace_back(S+1);
	for (int i = 0; i < cc.size(); i++) cur.emplace_back(cc[i]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	A = B = vi(N);
	G.assign(N, vi());
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) {
		cin >> B[i];
		if (B[i] != -1) {
			B[i]--;
			G[B[i]].emplace_back(i);
		}
	}
	vis.assign(N, false);
	ll ans = 0ll;
	DP = vl(N);
	for (int i = 0; i < N; i++) {
		if (B[i] == -1) calc(i);
	}
	for (int i = 0; i < N; i++) {
		ans += calc(i);
	}
	cout << ans << "\n";
	for (int i = 0; i < N; i++) {
		if (B[i] == -1) makeOrder(i);
	}
	for (int i = cur.size() - 1; i >= 0 ; i--) ord.emplace_back(cur[i]);
	cout << ord[0];
	for (int i = 1; i < N; i++) cout << " " << ord[i];
	cout << "\n";
	return 0;
}
