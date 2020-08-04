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
vector<vpii> G;
vvi T;

int nxt(int p, int t) {
	if (!T[p].size() || t > T[p][T[p].size() - 1]) return t;
	int lo = 0, hi = T[p].size()-1, mid, pos = -1;
	while(lo <= hi) {
		mid = lo + (hi-lo)/2;
		if (T[p][mid] == t) {
			pos = mid;
			break;
		}
		else if (T[p][mid] < t) lo = mid+1;
		else hi = mid-1;
	}
	if (pos == -1) return t;
	for (int i = mid+1; i < (int) T[p].size(); i++) {
		if (T[p][i] > T[p][i-1]+1) return T[p][i-1]+1;
	}
	return T[p][T[p].size()-1] + 1;
}

int Dijkstra() {
	vi dist = vi(N, 2e9);
	dist[0] = 0;
	queue<pair<int, int>> Q;
	Q.push({0, dist[0]});
	pair<int, int> curP;
	int u, v, distU;
	while(Q.size()) {
		curP = Q.front();
		Q.pop();
		u = curP.first;
		distU = curP.second;
		if (distU > dist[u]) continue;
		if (u != N-1) dist[u] = nxt(u, dist[u]);
		for (int i = 0; i < (int) G[u].size(); i++) {
			curP = G[u][i];
			v = curP.first;
			if (dist[v] > dist[u] + curP.second) {
				dist[v] = dist[u] + curP.second;
				Q.push({v, dist[v]});
			}
		}
	}
	if (dist[N-1] < 2e9) return dist[N-1];
	else return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int M, a, b, c, k;
	cin >> N >> M;
	G.assign(N, vpii());
	T.assign(N, vi());
	while(M--) {
		cin >> a >> b >> c;
		a--;
		b--;
		G[a].push_back(make_pair(b, c));
		G[b].push_back(make_pair(a, c));
	}
	for (int i = 0; i < N; i++) {
		cin >> k;
		T[i].assign(k, 0);
		for (int j = 0; j < k; j++) cin >> T[i][j];
	}
	cout << Dijkstra() << "\n";
	return 0;
}
