#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

string A, B;
int N;
vvi G;
vector<bool> vis;

void dfs(int u) {
	vis[u] = true;
	for (int i = 0; i < (int) G[u].size(); i++) {
		if (vis[G[u][i]] == false) dfs(G[u][i]);
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, c, d, ans;
	cin >> T;
	bool pos;
	while(T--) {
		cin >> N;
		cin >> A;
		cin >> B;
		pos = true;
		G.assign(20, vi());
		for (int i = 0; i < N; i++) {
			if (A[i] < B[i]) {
				c = A[i] - 'a';
				d = B[i] - 'a';
				G[c].push_back(d);
				G[d].push_back(c);
			}
			else if (A[i] > B[i]) {
				pos = false;
				break;
			}
		}
		if (pos) {
			vis.assign(20, false);
			ans = 20;
			for (int i = 0; i < 20; i++) {
				if (!vis[i]) {
					dfs(i);
					ans--;
				}
			}
			cout << ans << "\n";
		} else cout << "-1\n";
	}
	return 0;
}
