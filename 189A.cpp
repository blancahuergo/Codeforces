#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	vector<ll> DP = vector<ll>(n+1, -1);
	DP[0] = 0;
	for (int i = 1; i <= n; i++) {
		if (i >= a && DP[i-a] >= 0) DP[i] = max(DP[i], DP[i-a]+1);
		if (i >= b && DP[i-b] >= 0) DP[i] = max(DP[i], DP[i-b]+1);
		if (i >= c && DP[i-c] >= 0) DP[i] = max(DP[i], DP[i-c]+1);
	}
	cout << DP[n] << "\n";
	return 0;
}
