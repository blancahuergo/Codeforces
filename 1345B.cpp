#include <iostream>
#include <vector>
using namespace std;

vector<int> cards;

void createDP() {
	int h = 2, cur=2;
	while(cur <= 1e9) {
		cards.push_back(cur);
		cur += 3*h - 1;
		h++;
	}
}

int findLargest(int key) {
	int lo=0, hi=cards.size()-1, mid, ret;
	while (lo <= hi) {
		mid = (lo+hi)/2;
		if (key == cards[mid]) return cards[mid];
		else if (key < cards[mid]) hi = mid-1;
		else {
			ret = mid;
			lo = mid+1;
		}
	}
	return cards[ret];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N, pyr, cur;
	createDP();
	cin >> T;
	while(T--) {
		cin >> N;
		pyr = 0;
		while(N > 1) {
			N -= findLargest(N);
			pyr++;
		}
		cout << pyr << "\n";
	}
	return 0;
}
