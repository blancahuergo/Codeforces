#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> prices;

int binSearch(int key) {
	int lo = 0, hi = (int) prices.size()-1, mid, ret=-1;
	while(lo <= hi) {
		mid = (lo+hi)/2;
		if (key >= prices[mid]) {
			ret = mid;
			lo = mid+1;
		} else hi = mid-1;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n;
	prices = vector<int>(n);
	for (int i = 0; i < n; i++) cin >> prices[i];
	cin >> q;
	vector<int> spend = vector<int>(q);
	for (int i = 0; i < q; i++) cin >> spend[i];
	sort(prices.begin(), prices.end());
	for (int d = 0; d < q; d++)
		cout << binSearch(spend[d])+1 << "\n";
	return 0;
}
