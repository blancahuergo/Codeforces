#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;

int N;
ll K, M;
vector<ll> DP; // DP[pos] stores maximum possible blocks in the bag at that position

bool possible() {
	ll H, last;
	cin >> last;
	DP.assign(N, 0ll);
	DP[0] = M;
	bool ret = true;
	for (int i = 1; i < N; i++) {
		cin >> H;
		if(last + DP[i-1] < H - K) ret = false;
		if (last >= H - K) {
			DP[i] = DP[i-1] + last - max(0ll, H - K);
		} else {
			DP[i] = DP[i-1] - (max(0ll, H-K) - last);
		}
		last = H;
	}
	return ret;
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		cin >> N >> M >> K;
		if (possible()) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
