#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int ll;

int main() {
	int N, num;
	cin >> N;
	vector<pair<int, int>> B = vector<pair<int, int>>(N);
	for (int n = 0; n < N; n++) {
		cin >> num;
		B[n].first = n - num;
		B[n].second = num;
	}
	sort(B.begin(), B.end());
	ll cur=B[0].second, record=B[0].second;
	for (int i = 1; i < N; i++) {
		if (B[i].first == B[i-1].first) cur+=B[i].second;
		else {
			record = max(record, cur);
			cur = B[i].second;
		}
	}
	record = max(record, cur);
	cout << record << "\n";
	return 0;
}
