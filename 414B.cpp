#include <iostream>
#include <vector>
using namespace std;

int K, N, mod = 1e9 + 7;
vector<vector<int>> DP; // [ind][cur]

int recur(int ind, int cur) {
	if (ind == K) return 1;
	if (DP[ind][cur] != -1) return DP[ind][cur];
	int ans = 0;
	for (int i = 1; i <= N/cur; i++) {
		ans += recur(ind+1, cur*i);
		ans %= mod;
	}
	return DP[ind][cur] = ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;
	int ans = 0;
	DP.assign(K+1, vector<int>(N+1, -1));
	for (int i = 1; i <= N; i++) {
		ans += recur(1, i);
		ans %= mod;
	}
	cout << ans << "\n";
	return 0;
}
