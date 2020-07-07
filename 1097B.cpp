#include <iostream>
#include <vector>
using namespace std;

vector<int> A;
int N;

bool recur(int bitmask, int ind, int curPos) {
	if (ind == N) return (curPos%360 == 0);
	if (recur(bitmask + (1<<ind), ind+1, (curPos - A[ind] + 360)%360)) return true;
	if (recur(bitmask, ind+1, (curPos + A[ind] + 360)%360)) return true;
	return false;
}

int main() {
	cin >> N;
	A.assign(N, 0);
	for (int n = 0; n < N; n++) cin >> A[n];
	bool ans = recur(0, 0, 0);
	if (ans) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}
