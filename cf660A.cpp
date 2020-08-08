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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N;
	cin >> T;
	while(T--) {
		cin >> N;
		if (N <= 30) cout << "NO\n";
		else if (N == 36) {
			cout << "YES\n";
			cout << "5 6 10 15\n";
		} else if (N == 40) {
			cout << "YES\n";
			cout << "3 6 10 21\n";
		} else if (N == 44) {
			cout << "YES\n";
			cout << "2 6 15 21\n";
		} else {
			cout << "YES\n";
			cout << "6 10 14 " << N-30 << "\n";
		}
	}
	return 0;
}
