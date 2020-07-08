#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, A, curLen, recordLen, last;
	cin >> N;
	cin >> last;
	curLen = 1;
	recordLen = 1;
	for (int n = 1; n < N; n++) {
		cin >> A;
		if (last*2 >= A) curLen++;
		else {
			recordLen = max(recordLen, curLen);
			curLen=1;
		}
		last = A;
	}
	recordLen = max(recordLen, curLen);
	cout << recordLen << "\n";
	return 0;
}
