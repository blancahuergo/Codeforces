#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N, ind;
	bool found;
	cin >> T;
	vector<int> A;
	while (T--) {
		cin >> N;
		A.assign(N, 0);
		for (int n = 0; n < N; n++) {
			cin >> A[n];
			A[n] %= 2;
		}
		if (A[0] == 0) cout << "1\n1\n";
		else {
			found = false;
			ind = 1;
			for (int i = 1; i < N; i++) {
				if (A[i] == 1) {
					found = true;
					ind = i+1;
					break;
				}
			}
			if (found) cout << "2\n" << "1 " << ind << "\n";
			else {
				for (int i = 0; i < N; i++) {
					if (A[i] == 0) {
						found = true;
						ind = i+1;
						break;
					}
				}
				if (found) cout << "1\n" << ind << "\n";
				else cout << "-1\n";
			}
		}
	}
	return 0;
}
