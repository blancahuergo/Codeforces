#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long int ll;
vector<ll> DP;

ll digitAt(ll num, ll pos) {
	return ((ll)(num / pow(10, pos))) % 10ll;
}

ll calc(ll num) {
	if (num < 0) return 1e18;
	if (DP[num] != -1) return DP[num];
	if (num == 0) return 0;
	ll ans = 1e18, cur;
	for (int i = 0; i <= 18; i++) {
		cur = digitAt(num, i);
		if (cur > 0) ans =  min(ans, 1+calc(num - cur));
	}
	return DP[num] = ans;
}

int main() {
	ll N;
	cin >> N;
	DP.assign(N+1, -1);
	cout << calc(N) << "\n";
	return 0;
}
