#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<int> sum = vector<int>(n+1, 0);
	for (int i = 1; i <= n; i++) sum[i] = sum[i-1] + a[i-1];
	int rec = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (j == n) rec = max(rec, sum[i-1] + (n-i+1) - (sum[n] - sum[i-1]));
			else rec = max(rec, sum[i-1] + (sum[n] - sum[j]) + (j-i+1) - (sum[j] - sum[i-1]));
		}
	}
	cout << rec << "\n";
	return 0;
}
