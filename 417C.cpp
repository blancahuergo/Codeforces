#include <iostream>
using namespace std;

int main() {
	int N, K, cur;
	cin >> N >> K;
	if (K*N > N*(N-1)/2) cout << "-1\n";
	else {
		cout << K*N << "\n";
		for (int i = 1; i <= N; i++) {
			for (int k = 1; k <= K; k++) {
				cur = (i+k)%N;
				if (cur == 0) cur = N;
				cout << i << " " << cur << "\n";
			}
		}
	}
	return 0;
}
