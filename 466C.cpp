#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int nums[N];
	ll sum=0, cur, obj, pref[N];
	for (int n = 0; n < N; n++) {
		cin >> nums[n];
		sum += nums[n];
	}
	if (sum % 3 != 0) cout << "0\n";
	else {
		obj = sum/3;
		cur = nums[0];
		if (cur == obj) pref[0]=1ll;
		else pref[0] = 0ll;
		for (int i = 1; i < N; i++) {
			pref[i] = pref[i-1];
			cur += nums[i];
			if (cur == obj) pref[i]++;
		}
		ll ans = 0ll;
		cur = 0;
		for (int i = N-1; i >= 2; i--) {
			cur += nums[i];
			if (cur == obj) ans += pref[i-2];
		}
		cout << ans << "\n";
	}
}
