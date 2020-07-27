#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

unordered_map<string, int> dict;
unordered_map<int, string> inv;
int N, M;
vvi G;
vector<bool> visited;

bool correct(int i, int mask) {
	for (int j = 0; j < N; j++) {
		if (mask & (1 << j)) {
			if (G[i][j]) return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	G.assign(N, vi(N, 0));
	string nam, n1, n2;
	for (int n = 0; n < N; n++) {
		cin >> nam;
		dict[nam] = n;
		inv[n] = nam;
	}
	for (int m = 0; m < M; m++) {
		cin >> n1 >> n2;
		G[dict[n1]][dict[n2]] = G[dict[n2]][dict[n1]] = 1;
	}
	queue<pair<int, int>> Q;
	int mask, rec;
	Q.push({0, 0});
	pair<int, int> curP, bestP = {0, 0};
	visited.assign((1 << N) + 1, false);
	while(Q.size()) {
		curP = Q.front();
		Q.pop();
		rec = curP.first;
		mask = curP.second;
		if (visited[mask]) continue;
		visited[mask] = true;
		if (rec > bestP.first) {
			bestP = {rec, mask};
		}
		for (int i = 0; i < N; i++) {
			if (((mask & (1<<i)) == 0) && correct(i, mask)) {
				Q.push({rec+1, mask | (1<<i)});
			}
		}
	}
	cout << rec << "\n";
	vector<string> res;
	for (int i = 0; i < N; i++) {
		if (mask & (1 << i)) res.emplace_back(inv[i]);
	}
	sort(res.begin(), res.end());
	for (int i = 0; i < rec; i++) cout << res[i] << "\n";
	return 0;
}
