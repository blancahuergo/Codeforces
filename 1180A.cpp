#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int DP[N];
	DP[0] = 1;
	int i = 4;
	for (int j = 1; j < N; j++) {
		DP[j] = DP[j-1] + i;
		i += 4;
	}
	cout << DP[N-1] << "\n";
	return 0;
}
