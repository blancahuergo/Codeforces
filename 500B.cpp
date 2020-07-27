#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int N;
vi P, curInd, curNums;
vector<string> M;
vector<bool> visited;

void DFS(int u) {
	visited[u] = true;
	curNums.emplace_back(P[u]);
	curInd.emplace_back(u);
	for(int i = 0; i < N; i++) {
		if (M[u][i] == '1' && visited[i] == false) {
			DFS(i);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	P.assign(N, 0);
	for (int i = 0; i < N; i++) cin >> P[i];
	M.assign(N, "");
	for (int i = 0; i < N; i++) cin >> M[i];
	visited.assign(N, false);
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			curNums.clear();
			curInd.clear();
			DFS(i);
			sort(curNums.begin(), curNums.end());
			sort(curInd.begin(), curInd.end());
			for (int j = 0; j < (int) curNums.size(); j++) {
				P[curInd[j]] = curNums[j];
			}
		}
	}
	cout << P[0];
	for (int i = 1; i < N; i++) cout << " " << P[i];
	cout << "\n";
	return 0;
}
