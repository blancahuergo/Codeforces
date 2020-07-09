#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int mod = 1e9 + 7;
	string s;
	cin >> s;
	int N = (int) s.size();
	int DP[N];
	if (s[0] == 'm' || s[0] == 'w') {
		DP[N-1] = 0;
	}
	else {
		DP[0] = 1;
		for (int i = 1; i < N; i++) {
			if (s[i] == 'm' || s[i] == 'w') {
				DP[N-1] = 0;
				break;
			} else if (s[i] == 'u') {
				if (s[i-1] == 'u') {
					if (i >= 2) DP[i] = DP[i-2] + DP[i-1];
					else DP[i] = DP[i-1]+1;
				}
				else DP[i] = DP[i-1];
			} else if (s[i] == 'n') {
				if (s[i-1] == 'n') {
					if (i >= 2) DP[i] = DP[i-2] + DP[i-1];
					else DP[i] = DP[i-1]+1;
				}
				else DP[i] = DP[i-1];
			} else DP[i] = DP[i-1];
			DP[i] %= mod;
		}
	}
	cout << DP[N - 1] << "\n";
	return 0;
}
