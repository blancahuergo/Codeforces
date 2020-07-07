#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> DP;

int maxRounds(int a, int b) {
	if (a <= 0 || b <= 0) return 0;
	if (DP[a][b] != -1) return DP[a][b];
	return DP[a][b] = 1 + max(maxRounds(a-2, b+1), maxRounds(a+1, b-2));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a1, a2;
	cin >> a1 >> a2;
	DP.assign(1000, vector<int>(1000, -1));
	DP[1][1] = 0;
	cout << maxRounds(a1, a2) << "\n";
	return 0;
}
