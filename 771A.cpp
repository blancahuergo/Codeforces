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

int N;
ll ed, siz;
vvi G;
vector<bool> vis;

void dfs(int S) {
	vis[S] = true;
	siz++;
	ed += (int) G[S].size();
	for (int i = 0; i < (int) G[S].size(); i++) {
		if (!vis[G[S][i]]) dfs(G[S][i]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	G.assign(N, vi());
	vis.assign(N, false);
	int M, a, b;
	cin >> M;
	while(M--) {
		cin >> a >> b;
		a--;
		b--;
		G[a].pb(b);
		G[b].pb(a);
	}
	bool pos = true;
	for (int i = 0; i < N; i++) {
		if (!vis[i]) {
			ed = siz = 0ll;
			dfs(i);
			if (ed/2 != siz*(siz-1)/2) {
				pos = false;
				break;
			}
		}
	}
	if (pos) cout << "YES";
	else cout << "NO";
	return 0;
}
