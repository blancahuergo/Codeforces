#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
	int T, N, x, st, tot;
	vi P;
	cin >> T;
	while(T--) {
		cin >> N >> x;
		P.assign(N, 0);
		for (int n = 0; n < N; n++) {
			cin >> P[n];
		}
		sort(P.begin(), P.end());
		st = N-1;
		tot = 0;
		for (int i = N-1; i >= 0; i--) {
			if (P[i]*(st-i+1) >= x) {
				st = i-1;
				tot++;
			}
		}
		cout << tot << "\n";
	}
	return 0;
}
