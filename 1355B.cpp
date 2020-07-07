#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T, N, tot, cur;
	cin >> T;
	while(T--) {
		cin >> N;
		int inexp[N];
		for (int n = 0; n < N; n++) cin >> inexp[n];
		sort(inexp, inexp+N);
		tot = 0;
		cur = 0;
		for (int i = 0; i < N; i++) {
			cur++;
			if (cur >= inexp[i]) {
				cur = 0;
				tot++;
			}
		}
		cout << tot << "\n";
	}
	return 0;
}
