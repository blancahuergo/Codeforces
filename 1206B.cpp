#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, zeros = 0, A, neg = 0;
	long long int changes = 0ll;
	cin >> N;
	for (int n = 0; n < N; n++) {
		cin >> A;
		if (A > 0) {
			changes += (A-1);
		} else if (A < 0) {
			neg++;
			changes += (-1-A);
		} else zeros++;
	}
	neg %= 2;
	if (neg == 1) {
		if (zeros > 0) changes += zeros;
		else changes += 2;
	} else changes += zeros;
	cout << changes << "\n";
	return 0;
}
