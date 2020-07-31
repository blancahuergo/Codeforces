#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <cmath>
#include <climits>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, l, r;
	cin >> T;
	while(T--) {
		cin >> l >> r;
		if (2*l <= r) cout << l << " " << 2*l << "\n";
		else cout << "-1 -1\n";
	}
	return 0;
}
