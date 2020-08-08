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
	int T, x, len, i;
	cin >> T;
	while(T--) {
		cin >> x;
		len = x*3;
		i = 1;
		while(i*4 <= len) {
			cout << "9";
			i++;
		}
		i--;
		while(i < x) {
			cout << "8";
			i++;
		}
		cout << "\n";
	}
	return 0;
}
