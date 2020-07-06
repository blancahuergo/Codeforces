#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	int nums[N];
	for (int n = 0; n < N; n++) cin >> nums[n];
	int DP[N];
	DP[N-1] = 1;
	unordered_set<int> found;
	found.insert(nums[N-1]);
	for (int i = N-2; i >= 0; i--) {
		if (found.find(nums[i]) == found.end()) DP[i] = DP[i+1]+1;
		else DP[i] = DP[i+1];
		found.insert(nums[i]);
	}
	int l;
	for (int q = 0; q < M; q++) {
		cin >> l;
		cout << DP[l-1] << "\n";
	}
	return 0;
}
