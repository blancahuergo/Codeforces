#include <iostream>
#include <vector>
using namespace std;

vector<int> mod, DP;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N, ans, inc;
	cin >> T;
	while(T--) {
		cin >> N;
		mod.resize(N);
		for (int n = 0; n < N; n++) cin >> mod[n];
		DP.assign(N+1, 1);
		ans = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = i*2; j <= N; j += i) {
				if (mod[j-1] > mod[i-1]) DP[j] = max(DP[j], DP[i]+1);
			}
			ans = max(DP[i], ans);
		}
		cout << ans << "\n";
	}
	return 0;
}
