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

vi A, C;
vector<bool> vis, locVis;
int N, res;

void bfs(int i) {
	queue<int> Q;
	Q.push(i);
	int u, v, fir;
	locVis.assign(N, false);
	while(Q.size()) {
		u = Q.front();
		Q.pop();
		if (locVis[u]) break;
		locVis[u] = true;
		v = A[u];
		if (vis[v]) return;
		Q.push(v);
	}
	fir = u;
	int ret = C[u];
	queue<int> Q2;
	Q2.push(A[u]);
	vis[u] = true;
	while(Q2.size()) {
		u = Q2.front();
		vis[u] = true;
		Q2.pop();
		ret = min(ret, C[u]);
		if (A[u] == fir) break;
		Q2.push(A[u]);
	}
	res += ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	A = C = vi(N);
	for (int i = 0; i < N; i++) {
		cin >> C[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		A[i]--;
	}
	vis.assign(N, false);
	res = 0;
	for (int i = 0; i < N; i++) {
		if (!vis[i]) {
			bfs(i);
			vis[i] = true;
		}
	}
	cout << res << "\n";
	return 0;
}
