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

int N, u;
vi A;
vector<bool> vis, visStack;

void dfs(int S) {
	visStack[S] = true;
	if (visStack[A[S]]) {
		u = A[S];
		return;
	}
	if (!vis[A[S]]) dfs(A[S]);
	vis[S] = true;
	visStack[S] = false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	A.assign(N, 0);
	int rt = -1;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		A[i]--;
		if (A[i] == i) rt = i;
	}
	vis.assign(N, false);
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (!vis[i]) {
			visStack.assign(N, false);
			u = -1;
			dfs(i);
			if (u >= 0) {
				if (rt == -1) rt = u;
				vis[u] = true;
				ans++;
				if (A[u] == rt) ans--;
				else A[u] = rt;
			}
		}
	}
	cout << ans << "\n";
	cout << A[0]+1;
	for (int i = 1; i < N; i++) cout << " " << A[i]+1;
	return 0;
}
