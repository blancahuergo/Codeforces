#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int N, M;
vector<pair<int, int>> P;
vector<int> app;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	int a, b, x, xCount;
	P.assign(M, pair<int, int>());
	for (int m = 0; m < M; m++) {
		cin >> a >> b;
		P[m] = make_pair(a-1, b-1);
	}
	bool pos;
	x = P[0].first;
	app.assign(N, 0);
	xCount = 1;
	for (int m = 1; m < M; m++) {
		if (P[m].first == x || P[m].second == x) {
			xCount++;
			continue;
		}
		app[P[m].first]++;
		app[P[m].second]++;
	}
	pos = false;
	for (int i = 0; i < N; i++) {
		if (app[i] == M - xCount) {
			pos = true;
			break;
		}
	}
	if (pos) cout << "YES\n";
	else {
		x = P[0].second;
		app.assign(N, 0);
		xCount = 1;
		for (int m = 1; m < M; m++) {
			if (P[m].first == x || P[m].second == x) {
				xCount++;
				continue;
			}
			app[P[m].first]++;
			app[P[m].second]++;
		}
		pos = false;
		for (int i = 0; i < N; i++) {
			if (app[i] == M - xCount) {
				pos = true;
				break;
			}
		}
		if (pos) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
