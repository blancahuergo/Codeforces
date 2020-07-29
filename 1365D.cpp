#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int N, M;
vector<string> grid;
vpii G, B;
vvi vis;

void dfs(int r, int c) {
	vis[r][c] = true;
	if (r < N-1 && (grid[r+1][c] != '#') && (vis[r+1][c] == false)) dfs(r+1, c);
	if (r > 0 && (grid[r-1][c] != '#') && (vis[r-1][c] == false)) dfs(r-1, c);
	if (c < M-1 && (grid[r][c+1] != '#') && (vis[r][c+1] == false)) dfs(r, c+1);
	if (c > 0 && (grid[r][c-1] != '#') && (vis[r][c-1] == false)) dfs(r, c-1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	bool pos;
	while(T--) {
		cin >> N >> M;
		grid = vector<string>(N);
		G.clear();
		B.clear();
		for (int i = 0; i < N; i++) {
			cin >> grid[i];
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (grid[i][j] == 'G')
					G.push_back(make_pair(i, j));
				else if (grid[i][j] == 'B') {
					if (grid[i][j] == 'B')
						B.push_back(make_pair(i, j));
					if (i < N - 1 && grid[i + 1][j] == '.')
						grid[i + 1][j] = '#';
					if (i > 0 && grid[i - 1][j] == '.')
						grid[i - 1][j] = '#';
					if (j < M - 1 && grid[i][j + 1] == '.')
						grid[i][j + 1] = '#';
					if (j > 0 && grid[i][j - 1] == '.')
						grid[i][j - 1] = '#';
				}
			}
		}
		pos = true;
		int r, c;
		vis.assign(N, vi(M, false));
		dfs(N-1, M-1);
		if (G.size() > 0) {
			for (int i = 0; i < (int) B.size(); i++) {
				r = B[i].first;
				c = B[i].second;
				if (vis[r][c]) {
					pos = false;
					break;
				}
			}
		}
		if (pos) {
			for (int i = 0; i < (int) G.size(); i++) {
				r = G[i].first;
				c = G[i].second;
				if (!vis[r][c]) {
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
