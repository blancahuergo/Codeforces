#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N, l, cur;
	vector<bool> ap;
	vector<int> perm;
	cin >> T;
	while(T--) {
		cin >> N;
		perm.assign(N, 0);
		ap.assign(N, false);
		l = 0;
		for (int i = 0; i < 2*N; i++) {
			cin >> cur;
			cur--;
			if (ap[cur] == false) {
				ap[cur] = true;
				perm[l] = cur+1;
				l++;
			}
		}
		cout << perm[0];
		for (int i = 1; i < N; i++) cout << " " << perm[i];
		cout << "\n";
	}
	return 0;
}
