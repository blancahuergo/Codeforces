#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, cur, mx;
	vector<ll> count, DP;
	count.assign(1e5 + 1, 0);
	cin >> N;
	mx = 0;
	for (int n = 0; n < N; n++) {
		cin >> cur;
		mx = max(mx, cur);
		count[cur]++;
	}
	DP.assign(mx + 1, 0);
	DP[1] = count[1];
	for (int i = 2; i <= mx; i++)
		DP[i] = max(DP[i-1], DP[i-2] + count[i]*i);
	cout << DP[mx] << "\n";
	return 0;
}
