#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
typedef long long int ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;

ll mod = 1e9 + 7;
vvl bin;

ll combs(ll n, ll k) {
	if (bin[n][k] != -1) return bin[n][k];
    if (k == 0 || k == n) return bin[n][k] = 1;
    return bin[n][k] = (combs(n-1, k-1) + combs(n-1, k))%mod;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int K;
	ll cur;
	cin >> K;
	int cols[K];
	for (int i = 0; i < K; i++) {
		cin >> cols[i];
	}
	long long int DP[K];
	memset(DP, 0, sizeof(DP));
	bin.assign(1010, vl(1010, -1));
	DP[0] = 1;
	cur = cols[0];
	for (int i = 1; i < K; i++) {
		cur += cols[i];
		DP[i] = DP[i-1]*combs(cur-1, cols[i]-1);
		DP[i] %= mod;
	}
	cout << DP[K-1] << "\n";
	return 0;
}
