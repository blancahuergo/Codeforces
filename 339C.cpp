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
typedef pair<int, int> pii;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<pii> vpii;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<vvvl> vvvvl;

vi ans, K;
int M;

bool pos(int l, int r, int k, int ls) {
	if (k == M) return true;
	if (l < r) {
		for (int i = (int) K.size() - 1; i >= 0; i--) {
			if (ls == K[i]) continue;
			if (l + K[i] > r) {
				if (pos(l + K[i], r, k+1, K[i])) {
					ans.push_back(K[i]);
					return true;
				}
			}
		}
	} else {
		for (int i = (int) K.size() - 1; i >= 0; i--) {
			if (ls == K[i]) continue;
			if (r + K[i] > l) {
				if (pos(l, r + K[i], k+1, K[i])) {
					ans.push_back(K[i]);
					return true;
				}
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string W;
	cin >> W;
	for (int i = 0; i < 10; i++) {
		if (W[i] == '1') K.emplace_back(i+1);
	}
	cin >> M;
	if (pos(0, 0, 0, -1)) {
		cout << "YES\n";
		cout << ans[M-1];
		for (int i = M-2; i >= 0; i--) cout << " " << ans[i];
		cout << "\n";
	}
	else cout << "NO\n";
	return 0;
}
