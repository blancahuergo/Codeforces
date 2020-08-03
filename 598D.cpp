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

int N, M, K, ans;
vector<string> grid;
vvi pic;
vector<vector<bool>> visited;

void dfs1(int i, int j) {
	if (grid[i][j] == '*') {
		ans++;
		return;
	}
	if (visited[i][j]) return;
	visited[i][j] = true;
	if (i > 0) dfs1(i-1, j);
	if (i < N-1) dfs1(i+1, j);
	if (j > 0) dfs1(i, j-1);
	if (j < M-1) dfs1(i, j+1);
}

void dfs2(int i, int j) {
	if (grid[i][j] == '*') {
		pic[i][j] = 0;
		return;
	}
	pic[i][j] = ans;
	if (i > 0 && pic[i-1][j] == -1) dfs2(i-1, j);
	if (i < N-1 && pic[i+1][j] == -1) dfs2(i+1, j);
	if (j > 0 && pic[i][j-1] == -1) dfs2(i, j-1);
	if (j < M-1 && pic[i][j+1] == -1) dfs2(i, j+1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> K;
	grid.assign(N, "");
	for (int i = 0; i < N; i++) cin >> grid[i];
	pic.assign(N, vi(M, -1));
	visited.assign(N, vector<bool>(M, false));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j] == false && grid[i][j] == '.') {
				ans = 0;
				dfs1(i, j);
				dfs2(i, j);
			}
		}
	}
	int r, c;
	while(K--) {
		cin >> r >> c;
		cout << max(pic[r-1][c-1], 0) << "\n";
	}
	return 0;
}
