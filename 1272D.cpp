#include <iostream>
using namespace std;
typedef long long int ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int rec;
	ll A[N];
	int R[N], L[N];
	for (int n = 0; n < N; n++) {
		cin >> A[n];
	}
	L[0] = 1;
	rec = 1;
	for (int i = 1; i < N; i++) {
		if (A[i] > A[i-1]) {
			L[i] = L[i-1]+1;
			rec = max(rec, L[i]);
		}
		else L[i] = 1;
	}
	R[N-1] = 1;
	for (int i = N-2; i >= 0; i--) {
		if (A[i] < A[i+1]) R[i] = R[i+1]+1;
		else R[i] = 1;
	}
	for (int i = 1; i < N-1; i++) {
		if (A[i-1] < A[i+1]) rec = max(rec, L[i-1] + R[i+1]);
	}
	cout << rec << "\n";
	return 0;
}
