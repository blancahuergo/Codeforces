#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, cur, prev=2e9, tot=0, rec=1;
	cin >> n;
	while(n--) {
		cin >> cur;
		if (cur >= prev) {
			tot++;
			rec = max(rec, tot);
		} else tot = 1;
		prev = cur;
	}
	cout << rec << "\n";
	return 0;
}
