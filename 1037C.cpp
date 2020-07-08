#include <iostream>
using namespace std;

int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string a, b;
	cin >> N;
	cin >> a;
	cin >> b;
	int ans = 0;
	for (int i = 0; i < N; i++) if (a[i] != b[i]) ans++;
	int j = 0;
	while(j < N-1) {
		if (a[j] != b[j] && a[j+1] != b[j+1] && a[j] != a[j+1]) {
			ans--;
			j += 2;
		}
		else j++;
	}
	cout << ans << "\n";
	return 0;
}
