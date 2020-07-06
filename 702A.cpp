#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, cur, prev=-1, rec=0, tot=0;
	cin >> N;
	for (int n = 0; n < N; n++) {
		cin >> cur;
		if (cur > prev) {
			tot++;
			rec = max(rec, tot);
		} else
			tot = 1;
		prev = cur;
	}
	cout << rec << "\n";
	return 0;
}
