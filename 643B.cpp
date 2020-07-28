#include <iostream>
using namespace std;

int main() {
	int N, M, a, b, c, d;
	cin >> N >> M >> a >> b >> c >> d;
	if (N > 4) {
		M -= 6;
		if (M < N - 5) cout << "-1\n";
		else {
			cout << a << " " << c;
			for (int i = 1; i <= N; i++) {
				if (i == a || i == b || i == c || i == d) continue;
				cout << " " << i;
			}
			cout << " " << d << " " << b << "\n";
			cout << c << " " << a;
			for (int i = 1; i <= N; i++) {
				if (i == a || i == b || i == c || i == d) continue;
				cout << " " << i;
			}
			cout << " " << b << " " << d << "\n";
		}
	} else cout << "-1\n";
	return 0;
}
