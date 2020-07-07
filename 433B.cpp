#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, Q, l, r, typ;
	vector<long long int> v, u;
	cin >> N;
	v.assign(N, 0ll);
	for (int n = 0; n < N; n++) cin >> v[n];
	u = v;
	sort(u.begin(), u.end());
	for (int n = 1; n < N; n++) {
		u[n] += u[n-1];
		v[n] += v[n-1];
	}
	cin >> Q;
	while(Q--) {
		cin >> typ >> l >> r;
		l-=2;
		r--;
		if (typ == 1) {
			if (l >= 0) cout << (v[r]-v[l]) << "\n";
			else cout << v[r] << "\n";
		}
		else if (l >= 0) cout << (u[r]-u[l]) << "\n";
		else cout << u[r] << "\n";
	}
	return 0;
}
