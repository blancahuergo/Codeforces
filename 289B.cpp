#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, D;
	cin >> N >> M >> D;
	int mat[N*M], med, mod;
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			cin >> mat[n*M + m];
		}
	}
	if (N*M == 1) {
		cout << "0\n";
	} else {
		sort(mat, mat + N*M);
		med = mat[N*M/2];
		mod = mat[0] % D;
		bool pos = true;
		for (int i = 1; i < N*M; i++) {
			if (mat[i] % D != mod) {
				pos = false;
				break;
			}
		}
		if (pos == false) cout << "-1\n";
		else {
			int tot = 0;
			for (int i = 0; i < N*M; i++) {
				tot += (abs(med - mat[i]) / D);
			}
			cout << tot << "\n";
		}
	}
	return 0;
}
