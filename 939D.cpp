#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int N;
vvi G;
vi vis, CC;
vector<pair<int, int>> sp;

void dfs(int S) {
	vis[S] = true;
	CC.emplace_back(S);
	int v;
	for (int i = 0; i < (int) G[S].size(); i++) {
		v = G[S][i];
		if (!vis[v]) dfs(v);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	string tee, pull;
	cin >> tee;
	cin >> pull;
	int c, d;
	G.assign(26, vi());
	for (int i = 0; i < N; i++) {
		if (tee[i] != pull[i]) {
			c = tee[i] - 'a';
			d = pull[i] - 'a';
			G[c].push_back(d);
			G[d].push_back(c);
		}
	}
	vis.assign(26, false);
	for (int i = 0; i < 26; i++) {
		if (!vis[i]) {
			CC.clear();
			dfs(i);
			for (int j = 1; j < (int) CC.size(); j++) {
				sp.push_back(make_pair(CC[0], CC[j]));
			}
		}
	}
	cout << sp.size() << "\n";
	for (int i = 0; i < (int) sp.size(); i++) {
		cout << ((char) ('a' + sp[i].first)) << " " << ((char) ('a' + sp[i].second)) << "\n";
	}
	return 0;
}
