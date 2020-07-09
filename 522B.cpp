#include <iostream>
using namespace std;

int main() {
	int N, w, h, totW = 0, maxH=0, secH=0, highest;
	cin >> N;
	int weights[N];
	for (int i = 0; i < N; i++) {
		cin >> w >> h;
		totW += w;
		weights[i] = w;
		if (h > maxH) {
			secH = maxH;
			maxH = h;
			highest = i;
		} else if (h > secH) {
			secH = h;
		}
	}
	int cur;
	for (int i = 0; i < N; i++) {
		cur = totW - weights[i];
		if (i == highest) cur *= secH;
		else cur *= maxH;
		if (i > 0) cout << " " << cur;
		else cout << cur;
	}
	cout << "\n";
	return 0;
}
