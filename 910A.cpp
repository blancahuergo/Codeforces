#include <iostream>
#include <vector>
using namespace std;

int N, D;
string S;
vector<int> DP;

int journey(int pos) {
	if (pos == N-1) return 0;
	if (DP[pos] != -1) return DP[pos];
	int ans = 1000;
	for (int i = pos + 1; i <= min(N-1, pos+D); i++) {
		if(S[i] == '1') ans = min(ans, 1+journey(i));
	}
	return DP[pos] = ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> D;
	DP.assign(N, -1);
	cin >> S;
	int ans = journey(0);
	if (ans > 100) cout << "-1\n";
	else cout << ans << "\n";
	return 0;
}
