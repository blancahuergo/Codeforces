// for a position A[i] to be correct, its parent must have already appeared and there must be no A[j] before parent[A[i]]
// whose children have not all appeared yet.
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

int N;
vvi G;
vi dist, par, ch, realCh;
vector<bool> app;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int a, b;
	G.assign(N, vi());
	for (int i = 0; i < N-1; i++) {
		cin >> a >> b;
		G[a-1].emplace_back(b-1);
		G[b-1].emplace_back(a-1);
	}
	int A[N];
	int place[N];
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		A[i]--;
		place[A[i]] = i;
	}
	if (A[0] != 0) {
		cout << "No\n";
	} else {
		queue <pii> Q;
		Q.push({0, A[0]});
		int u, distU;
		dist.assign(N, N+1);
		par.assign(N, -1);
		dist[A[0]] = 0;
		par[A[0]] = -1;
		pii cur;
		realCh.assign(N, 0);
		while(Q.size()) {
			cur = Q.front();
			Q.pop();
			u = cur.second;
			distU = cur.first;
			if (distU > dist[u]) continue;
			int v;
			for (int i = 0; i < (int) G[u].size(); i++) {
				v = G[u][i];
				if (dist[u] + 1 < dist[v]) {
					dist[v] = dist[u]+1;
					if (par[v] != -1) realCh[par[v]]--;
					par[v] = u;
					realCh[u]++;
					Q.push({dist[v], v});
				}
			}
		}
		ch.assign(N, 0);
		bool pos = true;
		int p;
		app.assign(N, false);
		app[A[0]] = true;
		for (int i = 1; i < N; i++) {
			ch[par[A[i]]]++;
			app[A[i]] = true;
			if (!app[par[A[i]]]) {
				pos = false;
				break;
			}
			if (ch[par[A[i]]] == realCh[par[A[i]]]) {
				p = place[par[A[i]]]-1;
				if ((p >= 0 && ch[A[p]] != realCh[A[p]])) {
					pos = false;
					break;
				}
			}
		}
		if (pos) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}
