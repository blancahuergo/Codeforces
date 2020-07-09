#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;
typedef vector<viii> viiii;

int N[2], K[2], mod = 1e8;
viiii DP;

int main() {
	cin >> N[0] >> N[1] >> K[0] >> K[1];
	DP.assign(N[0]+N[1]+1, viii(2, vii(max(N[0], N[1])+1, vi(max(K[0], K[1])+1, 0))));
	DP[0][0][0][0] = 1;
	DP[0][1][0][0] = 1;
	for (int L = 1; L <= N[0]+N[1]; L++) {
		for (int typ = 0; typ <= 1; typ++) {
			for (int n = 1; n <= min(N[typ], L); n++) {
				if (L - n > N[1-typ]) continue;
				for (int k = 1; k <= min(K[typ], n); k++) {
					if (n == L) DP[L][typ][n][k] = DP[L-1][typ][n-1][k-1];
					else {
						for (int k_other = 1; k_other <= min(K[1-typ], min(L - n, L - k)); k_other++) {
							DP[L][typ][n][k] += DP[L-k][1-typ][L - n][k_other];
							DP[L][typ][n][k] %= mod;
						}
					}
				}
			}
		}
	}
	int ans = 0;
	for (int k = 1; k <= K[0]; k++) {
		ans += DP[N[0]+N[1]][0][N[0]][k];
		ans %= mod;
	}
	for (int k = 1; k <= K[1]; k++) {
		ans += DP[N[0]+N[1]][1][N[1]][k];
		ans %= mod;
	}
	cout << ans << "\n";
	return 0;
}
