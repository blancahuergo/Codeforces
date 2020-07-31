#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<vvvl> vvvvl;
typedef vector<string> vs;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N, M, i, j;
	cin >> T;
	bool pos;
	while(T--) {
		cin >> N >> M;
		int A[N], B[M];
		for (int n = 0; n < N; n++) cin >> A[n];
		for (int m = 0; m < M; m++) cin >> B[m];
		sort(A, A+N);
		sort(B, B+M);
		i = 0;
		j = 0;
		pos = false;
		while(i < N && j < M) {
			if (A[i] == B[j]) {
				pos = true;
				break;
			}
			else if (A[i] < B[j]) i++;
			else j++;
		}
		if (pos) cout << "YES\n1 " << A[i] << "\n";
		else cout << "NO\n";
	}
	return 0;
}
