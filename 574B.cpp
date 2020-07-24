#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int N, M;
vvi G, con;

int main() {
	cin >> N >> M;
	int u, v;
	G.assign(N, vi());
	con.assign(N, vi(N, 0));
	while(M--) {
		cin >> u >> v;
		G[u-1].emplace_back(v-1);
		G[v-1].emplace_back(u-1);
		con[u-1][v-1] = con[v-1][u-1] = 1;
	}
	int j, k, rec = 3*N, cur;
	for (int i = 0; i < N; i++) {
		for (int jj = 0; jj < (int) G[i].size(); jj++) {
			j = G[i][jj];
			for (int kk = jj+1; kk < (int) G[i].size(); kk++) {
				k = G[i][kk];
				if (!con[j][k]) continue;
				cur = (int) G[i].size() + (int) G[j].size() + (int) G[k].size() - 6;
				if (cur < rec) {
					rec = cur;
				}
			}
		}
	}
	if (rec < 3*N) cout << rec << "\n";
	else cout << "-1\n";
	return 0;
}
