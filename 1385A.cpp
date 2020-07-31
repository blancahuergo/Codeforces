#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, x, y, z, a, b, c;
	cin >> T;
	while(T--) {
		cin >> x >> y >> z;
		if (x == y && z <= x) {
			a = x;
			b = z;
			c = b;
			cout << "YES\n";
			cout << a << " " << b << " " << c << "\n";
		} else if (y == z && x <= y) {
			c = y;
			a = x;
			b = a;
			cout << "YES\n";
			cout << a << " " << b << " " << c << "\n";
		} else if (x == z && y <= x) {
			b = x;
			a = y;
			c = a;
			cout << "YES\n";
			cout << a << " " << b << " " << c << "\n";
		} else cout << "NO\n";
	}
	return 0;
}
