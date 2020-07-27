#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

vector<bool> visited, recStack;
string TS;
vvi G;
bool pos;

void DFS(int u) {
	visited[u] = true;
	recStack[u] = true;
	for (int i = 0; i < (int) G[u].size(); i++) {
		if (!visited[G[u][i]]) DFS(G[u][i]);
		else if (recStack[G[u][i]]) pos = false;
	}
	TS.push_back('a' + u);
	recStack[u] = false;
}

int main() {
	int N;
	cin >> N;
	string last, cur;
	cin >> last;
	G = vvi(26, vi());
	bool br;
	pos = true;
	for (int i = 1; i < N; i++) {
		cin >> cur;
		br = false;
		for (int j = 0; j < (int) min(last.length(), cur.length()); j++) {
			if (cur[j] != last[j]) {
				// last[j] comes before cur[j]
				G[last[j] - 'a'].emplace_back(cur[j] - 'a');
				br = true;
				break;
			}
		}
		if (br == false && cur.length() < last.length()) pos = false;
		last = cur;
	}
	if (pos) {
		visited.assign(26, false);
		TS.clear();
		for (int s = 0; s < 26; s++) {
			if (!visited[s]) {
				recStack.assign(26, false);
				DFS(s);
				if (pos == false) break;
			}
		}
	}
	if (pos) {
		reverse(TS.begin(), TS.end());
		cout << TS << "\n";
	}
	else cout << "Impossible\n";
	return 0;
}
