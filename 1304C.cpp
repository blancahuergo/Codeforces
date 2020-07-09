#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N, m, t, l, h, lastT, lastL, lastH, high, low;
	bool pos;
	cin >> T;
	while(T--) {
		cin >> N >> m;
		lastT = 0;
		lastL = m;
		lastH = m;
		pos = true;
		for (int n = 0; n < N; n++) {
			cin >> t >> l >> h;
			high = lastH + t - lastT;
			low = lastL - (t - lastT);
			if (high < l || low > h) {
				pos = false;
			} else {
				lastL = max(low, l);
				lastH = min(high, h);
			}
			lastT = t;
		}
		if (pos) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
