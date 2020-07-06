#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, k;
	cin >> N >> k;
	int fence[N];
	for (int n = 0; n < N; n++) cin >> fence[n];
	int sum = 0, rec, ans=1;
	for (int i = 0; i < k; i++) sum += fence[i];
	rec = sum;
	for (int i = k; i < N; i++) {
		sum -= fence[i-k];
		sum += fence[i];
		if (sum < rec) {
			rec = sum;
			ans = i-k+2;
		}
	}
	cout << ans << "\n";
	return 0;
}
