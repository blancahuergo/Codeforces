#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int N;
vvi G;
vi size;

int dfs(int S, int par) {
	if (size[S] != -1) return size[S];
	int ans = 0;
	for (int i = 0; i < (int) G[S].size(); i++) {
		if (G[S][i] != par) ans += dfs(G[S][i], S);
	}
	if (ans == 0) return size[S] = 1;
	return size[S] = ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	G.assign(N, vi());
	int p;
	for (int i = 1; i < N; i++) {
		cin >> p;
		p--;
		G[i].emplace_back(p);
		G[p].emplace_back(i);
	}
	size.assign(N, -1);
	dfs(0, -1);
	sort(size.begin(), size.end());
	cout << size[0];
	for (int k = 1; k < N; k++) cout << " " << size[k];
	cout << "\n";
	return 0;
}
