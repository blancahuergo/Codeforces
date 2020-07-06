#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	int m, l, r;
	cin >> s;
	vector<int> DP = vector<int>(s.length());
	DP[0] = 0;
	for (int i = 1; i < (int) s.length(); i++) {
		if (s[i] == s[i-1]) DP[i] = DP[i-1]+1;
		else DP[i] = DP[i-1];
	}
	cin >> m;
	while(m--) {
		cin >> l >> r;
		cout << DP[r-1] - DP[l-1] << "\n";
	}
	return 0;
}
