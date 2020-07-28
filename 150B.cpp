#include <iostream>
using namespace std;
typedef long long int ll;

ll N, M, K, mod = 1e9 + 7;

ll fastExp(ll bas, ll ex) {
	if (ex == 0) return 1;
	ll x = fastExp(bas, ex/2);
	if (ex & 1) return ((((x*x) % mod)*bas) % mod);
	return (x*x) % mod;
}

int main() {
	cin >> N >> M >> K;
	if (K == 1 || K > N) cout << fastExp(M, N);
	else if (K == N) cout << fastExp(M, (N+1)/2);
	else if (K&1) cout << fastExp(M, 2);
	else cout << M;
	return 0;
}
