#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N, st;
	ll curSum, record, all;
	cin >> T;
	vector<ll> nums;
	bool end;
	while(T--) {
		cin >> N;
		nums.assign(N, 0);
		curSum = all = 0ll;
		record = -2e9;
		end = false;
		st = 0;
		for (int n = 0; n < N; n++) {
			cin >> nums[n];
			curSum += nums[n];
			all += nums[n];
			if (curSum > record) {
				if ((st == 0 && n == N-1) == false) record = curSum;
			}
			if (curSum < 0ll) {
				curSum = 0ll;
				st = n;
			}
		}
		curSum = 0ll;
		st = N-1;
		for (int i = N-1; i >= 0; i--) {
			curSum += nums[i];
			if (curSum > record) {
				if (st == N-1 && i == 0) end = true;
				else record = curSum;
			}
			if (curSum < 0ll) {
				curSum = 0ll;
				st = i;
			}
		}
		if (record > all || (record == all && end == false)) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}
