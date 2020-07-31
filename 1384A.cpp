#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N, common;
	string curS;
	cin >> T;
	while(T--) {
		cin >> N;
		int A[N];
		for (int i = 0; i < N; i++) cin >> A[i];
		curS = "a";
		for (int i = 0; i < 55; i++) curS += "a";
		cout << curS << "\n";
		for (int i = 1; i <= N; i++) {
			common = A[i-1];
			curS[common] = ((curS[common] - 'a' +1)%26) + 'a';
			cout << curS << "\n";
		}
	}
	return 0;
}
