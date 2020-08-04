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

int N, D;
vvi G;
vi distA, distB;

void bfsA() {
	queue<int> Q;
	Q.push(0);
	distA.assign(N, N+1);
	distA[0] = 0;
	while(Q.size()) {
		int u = Q.front();
		Q.pop();
		for (int i = 0; i < (int) G[u].size(); i++) {
			int v = G[u][i];
			if (distA[v] == N+1) {
				distA[v] = distA[u]+1;
				Q.push(v);
			}
		}
	}
}

void bfsB(int x) {
	queue<int> Q;
	Q.push(x);
	distB.assign(N, N+1);
	distB[x] = 0;
	D = 0;
	vi high;
	high.assign(N, -1);
	high[x] = x;
	while(Q.size()) {
		int u = Q.front();
		Q.pop();
		if (distB[u] < distA[u] && distA[high[u]] >= distB[high[u]]) {
			D = max(D, distA[u]);
		}
		for (int i = 0; i < (int) G[u].size(); i++) {
			int v = G[u][i];
			if (distB[v] == N+1) {
				distB[v] = distB[u]+1;
				high[v] = high[u];
				if (distA[v] < distA[high[v]]) high[v] = v;
				Q.push(v);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int x, a, b;
	cin >> N >> x;
	x--;
	G.assign(N, vi());
	for (int i = 0; i < N-1; i++) {
		cin >> a >> b;
		a--;
		b--;
		G[a].emplace_back(b);
		G[b].emplace_back(a);
	}
	bfsA();
	bfsB(x);
	cout << D*2 << "\n";
	return 0;
}
