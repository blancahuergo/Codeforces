#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int ll;


int main() {
	int N;
	cin >> N;
	int C[N];
	vector<string> str, rev;
	str = rev = vector<string>(N);
	for (int n = 0; n < N; n++) cin >> C[n];
	for (int n = 0; n < N; n++) {
		cin >> str[n];
		rev[n] = str[n];
		reverse(rev[n].begin(), rev[n].end());
	}
	vector<pair<ll, ll>> DP = vector<pair<ll, ll>>(N, {-1, -1}); // DP[pos][normal, rev] = cost
	DP[0] = {0, C[0]};
	bool pos = true, possec;
	for (int i = 1; i < N; i++) {
		pos = false;
		if (str[i] >= str[i-1] && DP[i-1].first != -1) {
			DP[i].first = DP[i-1].first;
			pos = true;
		}
		if (str[i] >= rev[i-1] && DP[i-1].second != -1) {
			if (pos) DP[i].first = min(DP[i].first, DP[i-1].second);
			else DP[i].first = DP[i-1].second;
			pos = true;
		}
		possec = false;
		if (rev[i] >= str[i-1] && DP[i-1].first != -1) {
			pos = true;
			possec = true;
			DP[i].second = DP[i-1].first + C[i];
		}
		if (rev[i] >= rev[i-1] && DP[i-1].second != -1) {
			pos = true;
			if (possec) DP[i].second = min(DP[i].second, DP[i-1].second + C[i]);
			else DP[i].second = DP[i-1].second + C[i];
		}
		if (!pos) break;
	}
	if (pos) {
		ll ans;
		if (DP[N-1].first == -1) ans = DP[N-1].second;
		else if (DP[N-1].second == -1) ans = DP[N-1].first;
		else ans = min(DP[N-1].first, DP[N-1].second);
		cout << ans << "\n";
	}
	else cout << "-1\n";
	return 0;
}
