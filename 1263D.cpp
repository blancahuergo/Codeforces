#include <iostream>
#include <vector>
using namespace std;

int numSets;
vector<int> parent;
vector<int> rnk;

int root(int a) {
	if (parent[a] == a) return a;
	return parent[a] = root(parent[a]);
}

bool isSameSet(int a, int b) {
	return root(a) == root(b);
}

void mergeByRank(int a, int b) {
	int r_a, r_b;
	r_a = root(a);
	r_b = root(b);
	if (r_a == r_b) return;
	numSets--;
	if (rnk[r_a] > rnk[r_b]) {
		parent[r_b] = r_a;
	} else if (rnk[r_b] > rnk[r_a]) {
		parent[r_a] = r_b;
	} else {
		parent[r_a] = r_b;
		rnk[r_b]++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string curString, curLets, rt;
	int N;
	cin >> N;
	numSets = 26;
	parent.assign(26, 0);
	rnk.assign(26, 1);
	vector<int> app;
	app.assign(26, 0);
	for (int i = 0; i < 26; i++) parent[i] = i;
	for (int n = 0; n < N; n++) {
		cin >> curString;
		curLets = "00000000000000000000000000";
		if (numSets == 1) continue;
		for (int i = 0; i < (int) curString.length(); i++) {
			curLets[curString[i] - 'a'] = '1';
			app[curString[i] - 'a'] = 1;
		}
		for (int i = 0; i < 26; i++) {
			if (curLets[i] == '1') {
				for (int j = i+1; j < 26; j++) {
					if (curLets[j] == '1') mergeByRank(i, j);
				}
				break;
			}
		}
	}
	for (int i = 0; i < 26; i++) if (app[i] == 0) numSets--;
	cout << numSets << "\n";
	return 0;
}
