#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t, k, a, b, mod = 1e9 + 7, tot;
	cin >> t >> k;
	int DP[100001], sums[100001];
	DP[0] = 1;
	for (int i = 1; i <= 100001; i++) {
		DP[i] = DP[i-1];
		if (i >= k) DP[i] += DP[i-k];
		DP[i] %= mod;
	}
	sums[0] = 1;
	for (int i = 1; i <= 100001; i++) {
		sums[i] = sums[i-1]+DP[i];
		sums[i] %= mod;
	}
	while(t--) {
		cin >> a >> b;
		cout << (sums[b] - sums[a-1] + mod)%mod << "\n";
	}
	return 0;
}
