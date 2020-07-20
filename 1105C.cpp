#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long int ll;

int main() {
	int N, L, R;
	cin >> N >> L >> R;
	int mods[3], mod = 1e9 + 7;
	ll last[3], cur[3];
	// find number of ints % 3 == 0, 1, 2 between L and R
	mods[0] = (int) floor(R/3.0) - ceil(L/3.0) + 1;
	mods[1] = (int) floor((R-1)/3.0) - ceil((L-1)/3.0) + 1;
	mods[2] = (int) floor((R-2)/3.0) - ceil((L-2)/3.0) + 1;
	last[0] = (ll) mods[0] % mod;
	last[1] = (ll) mods[1] % mod;
	last[2] = (ll) mods[2] % mod;
	for (int i = 1; i < N; i++) {
		cur[0] = (((last[0] * mods[0]) % mod) + ((last[1] * mods[2]) % mod) + ((last[2] * mods[1]) % mod)) % mod;
		cur[1] = (((last[0] * mods[1]) % mod) + ((last[1] * mods[0]) % mod) + ((last[2] * mods[2]) % mod)) % mod;
		cur[2] = (((last[0] * mods[2]) % mod) + ((last[1] * mods[1]) % mod) + ((last[2] * mods[0]) % mod)) % mod;
		last[0] = cur[0];
		last[1] = cur[1];
		last[2] = cur[2];
	}
	cout << last[0] << "\n";
	return 0;
}
