#include <iostream>
using namespace std;

int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, len, i;
	cin >> T;
	while(T--) {
		cin >> N;
		int A[N];
		for (int n = 0; n < N; n++) cin >> A[n];
		len = 0;
		i = N-1;
		while(i && A[i] <= A[i-1]) {
			i--;
		}
		while(i && A[i] >= A[i-1]) {
			i--;
		}
		cout << i << "\n";
	}
	return 0;
}
