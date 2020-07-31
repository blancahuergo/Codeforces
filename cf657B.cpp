#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<vvvl> vvvvl;
typedef vector<string> vs;

ll top, bot;

ll multBet(ll a) {
	// case where bot < 0???
	if (bot > 0) {
		if (top/a != bot/a) return top/a;
		else if (bot % a == 0) return bot/a;
		else return -1;
	} else if (top/a > 0) return top/a;
	else return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	ll l, r, m, n, diff, b, c;
	cin >> T;
	while(T--) {
		cin >> l >> r >> m;
		top = m+r-l;
		bot = m-r+l;
		for (ll a = l; a <= r; a++) {
			n = multBet(a);
			if (n != -1) {
				diff = m - n*a;
				if (diff < 0) b = l;
				else b = r;
				c = b-diff;
				cout << a << " " << b << " " << c << "\n";
				break;
			}
		}
	}
	return 0;
}
