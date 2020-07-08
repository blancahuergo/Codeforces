#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	ll first[N], second[N];
	for (int n = 0; n < N; n++) cin >> first[n];
	for (int n = 0; n < N; n++) cin >> second[n];
	vector<pair<ll, ll>> DP = vector<pair<ll, ll>>(N, pair<ll, ll>());
	DP[0].first = first[0];
	DP[0].second = second[0];
	if (N > 1) {
		DP[1].first = DP[0].second + first[1];
		DP[1].second = DP[0].first + second[1];
		for (int i = 2; i < N; i++) {
			DP[i].first = first[i] + max(DP[i-1].second, max(DP[i-2].first, DP[i-2].second));
			DP[i].second = second[i] + max(DP[i-1].first, max(DP[i-2].second, DP[i-2].first));
		}
	}
	cout << max(DP[N-1].first, DP[N-1].second) << "\n";
	return 0;
}
