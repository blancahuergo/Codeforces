#include <iostream>
using namespace std;

string s;

int cost(int l, int r, char c) {
	if (l == r) {
		if (s[l] == c) return 0;
		else return 1;
	}
	int mid = (l+r)/2, totL = 0, totR = 0;
	for (int i = l; i <= mid; i++) {
		if (s[i] == c) totL++;
	}
	for (int i = mid+1; i <= r; i++) {
		if (s[i] == c) totR++;
	}
	return min(mid - l + 1 - totL + cost(mid+1, r, c+1), r - mid - totR + cost(l, mid, c+1));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N;
	cin >> T;
	while(T--) {
		cin >> N;
		cin >> s;
		cout << cost(0, N-1, 'a') << "\n";
	}
	return 0;
}
