#include <iostream>
#include <vector>
using namespace std;

int N, mod = 1e9 + 7;

int main() {
	cin >> N;
	pair<int, int> last = {1, 0}, cur;
	for (int i = N-1; i >= 0; i--) {
		cur.first = last.second % mod;
		cur.second = ((((2*last.first % mod) + last.first) % mod) + (2*last.second % mod)) % mod;
		last.first = cur.first;
		last.second = cur.second;
	}
	cout << cur.first << "\n";
	return 0;
}
