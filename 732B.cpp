#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K;
	cin >> N >> K;
	int A[N];
	for (int n = 0; n < N; n++) cin >> A[n];
	int extra[N], tot=0;
	extra[0] = 0;
	for (int i = 1; i < N; i++) {
		extra[i] = max(0, K - (A[i]+A[i-1]+extra[i-1]));
		tot += extra[i];
	}
	cout << tot << "\n" << (extra[0]+A[0]);
	for (int i = 1; i < N; i++) cout << " " << (A[i]+extra[i]);
	cout << "\n";
	return 0;
}
