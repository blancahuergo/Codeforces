#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int N, tot;
vvi F, E;
vector<bool> visited;
vi C;
bool pos;

void col(int S) {
	tot++;
	visited[S] = true;
	int v;
	for (int i = 0; i < (int) F[S].size(); i++) {
		v = F[S][i];
		if (C[v] == -1) {
			C[v] = 1;
			col(v);
		} else if (C[v] == 0) pos = false;
	}
	for (int i = 0; i < (int) E[S].size(); i++) {
		v = E[S][i];
		if (C[v] == -1) {
			C[v] = 0;
		} else if (C[v] == 1) pos = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int M, K, a, b;
	cin >> N;
	F.assign(N, vi());
	E.assign(N, vi());
	cin >> M;
	while(M--) {
		cin >> a >> b;
		F[a-1].emplace_back(b-1);
		F[b-1].emplace_back(a-1);
	}
	cin >> K;
	while(K--) {
		cin >> a >> b;
		E[a-1].emplace_back(b-1);
		E[b-1].emplace_back(a-1);
	}
	visited.assign(N, false);
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			tot = 0;
			C.assign(N, -1);
			pos = true;
			C[i] = 1;
			col(i);
			if (pos) ans = max(ans, tot);
		}
	}
	cout << ans << "\n";
	return 0;
}
