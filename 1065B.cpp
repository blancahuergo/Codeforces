#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long int N, M, m, curN;
	cin >> N >> M;
	if (N - M*2 >= 0) cout << N-M*2 << " ";
	else cout << "0 ";
	m = M;
	curN = 1;
	while(m > 0) {
		m -= curN;
		curN++;
	}
	if (M) cout << max(0ll, N - curN) << "\n";
	else cout << N << "\n";
	return 0;
}
