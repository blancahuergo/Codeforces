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
typedef vector<string> vs;
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define len(v) ((int)v.size())
#define all(v) v.begin(), v.end()

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, msk, ans;
	cin >> N >> M;
	vector<string> grid;
	vvi DP;
	vvi cst2, cst3;
	string L;
	if (min(N, M) >= 4) {
		for (int i = 0; i < N; i++) cin >> L;
		cout << "-1\n";
	} else if (min(N, M) == 1) {
		for (int i = 0; i < N; i++) cin >> L;
		cout << "0\n";
	} else if (min(N, M) == 2) {
		cst2 = {{0, 1, 1, 2},
				{1, 0, 2, 1},
				{1, 2, 0, 1},
				{2, 1, 1, 0}};
		if (N == 2) {
			grid = vector<string>(2);
			cin >> grid[0];
			cin >> grid[1];
			DP.assign(M+1, vi(4, N*M));
			DP[0][0] = DP[0][1] = DP[0][2] = DP[0][3] = 0;
			for (int i = 0; i < M; i++) {
				msk = 2*(grid[0][i] - '0') + grid[1][i] - '0';
				DP[i+1][0] = min(DP[i][1], DP[i][2]) + cst2[msk][0]; // + diff
				DP[i+1][1] = min(DP[i][0], DP[i][3]) + cst2[msk][1]; // + diff
				DP[i+1][2] = min(DP[i][0], DP[i][3]) + cst2[msk][2]; // + diff
				DP[i+1][3] = min(DP[i][1], DP[i][2]) + cst2[msk][3]; // + diff
			}
			cout << min(min(DP[M][0], DP[M][1]), min(DP[M][2], DP[M][3]));
		} else {
			grid = vector<string>(N);
			for (int i = 0; i < N; i++) cin >> grid[i];
			DP.assign(N+1, vi(4, N*M));
			DP[0][0] = DP[0][1] = DP[0][2] = DP[0][3] = 0;
			for (int i = 0; i < N; i++) {
				msk = 2*(grid[0][i] - '0') + grid[1][i] - '0';
				DP[i+1][0] = min(DP[i][1], DP[i][2]) + cst2[msk][0];
				DP[i+1][1] = min(DP[i][0], DP[i][3]) + cst2[msk][1];
				DP[i+1][2] = min(DP[i][0], DP[i][3]) + cst2[msk][2];
				DP[i+1][3] = min(DP[i][1], DP[i][2]) + cst2[msk][3];
			}
			cout << min(min(DP[N][0], DP[N][1]), min(DP[N][2], DP[N][3]));
		}
	} else {
		cst3 = {{0, 1, 1, 2, 1, 2, 2, 3},
				{1, 0, 2, 1, 2, 1, 3, 2},
				{1, 2, 0, 1, 2, 3, 1, 2},
				{2, 1, 1, 0, 3, 2, 2, 1},
				{1, 2, 2, 3, 0, 1, 1, 2},
				{2, 1, 3, 2, 1, 0, 2, 1},
				{2, 3, 1, 2, 1, 2, 0, 1},
				{3, 2, 2, 1, 2, 1, 1, 0}};
		if (N == 3) {
			// 3 rows, more cols
			grid = vector<string>(3);
			cin >> grid[0];
			cin >> grid[1];
			cin >> grid[2];
			DP.assign(M+1, vi(8, N*M));
			for (int i = 0; i < 8; i++) DP[0][i] = 0;
			for (int i = 0; i < M; i++) {
				msk = 4*(grid[0][i] - '0') + 2*(grid[1][i] - '0') + grid[2][i] - '0';
				DP[i+1][0] = min(DP[i][2], DP[i][5]) + cst3[msk][0];
				DP[i+1][1] = min(DP[i][3], DP[i][4]) + cst3[msk][1];
				DP[i+1][2] = min(DP[i][0], DP[i][7]) + cst3[msk][2];
				DP[i+1][3] = min(DP[i][1], DP[i][6]) + cst3[msk][3];
				DP[i+1][4] = min(DP[i][1], DP[i][6]) + cst3[msk][4];
				DP[i+1][5] = min(DP[i][0], DP[i][7]) + cst3[msk][5];
				DP[i+1][6] = min(DP[i][3], DP[i][4]) + cst3[msk][6];
				DP[i+1][7] = min(DP[i][2], DP[i][5]) + cst3[msk][7];
			}
			ans = 1e9;
			for (int i = 0; i < 8; i++) ans = min(ans, DP[M][i]);
			cout << ans << "\n";
		} else {
			// 3 cols, more rows
			grid = vector<string>(N);
			for (int i = 0; i < N; i++) cin >> grid[i];
			DP.assign(N+1, vi(8, N*M));
			for (int i = 0; i < 8; i++) DP[0][i] = 0;
			for (int i = 0; i < N; i++) {
				msk = 4*(grid[0][i] - '0') + 2*(grid[1][i] - '0') + grid[2][i] - '0';
				DP[i+1][0] = min(DP[i][2], DP[i][5]) + cst3[msk][0];
				DP[i+1][1] = min(DP[i][3], DP[i][4]) + cst3[msk][1];
				DP[i+1][2] = min(DP[i][0], DP[i][7]) + cst3[msk][2];
				DP[i+1][3] = min(DP[i][1], DP[i][6]) + cst3[msk][3];
				DP[i+1][4] = min(DP[i][1], DP[i][6]) + cst3[msk][4];
				DP[i+1][5] = min(DP[i][0], DP[i][7]) + cst3[msk][5];
				DP[i+1][6] = min(DP[i][3], DP[i][4]) + cst3[msk][6];
				DP[i+1][7] = min(DP[i][2], DP[i][5]) + cst3[msk][7];
			}
			ans = 1e9;
			for (int i = 0; i < 8; i++) ans = min(ans, DP[N][i]);
			cout << ans << "\n";
		}
	}
	return 0;
}
