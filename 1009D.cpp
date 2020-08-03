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

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll N, M;
	cin >> N >> M;
	if (N == 1) {
		if (M == 0) cout << "Possible\n";
		else cout << "Impossible\n";
	} else if (M < N-1 || M*2 > N*(N-1)) cout << "Impossible\n";
	else {
		vpii E;
		for (int i = 2; i <= N; i++) {
			E.push_back(make_pair(1, i));
		}
		int j;
		for (int i = 2; i < N; i++) {
			j = 1;
			while(i*j < N) {
				for (int k = 1; k < i && i*j+k <= N; k++) {
					if ((int) E.size() == M) break;
					if (gcd(i, i*j+k) <= 1) E.push_back(make_pair(i, i*j+k));
				}
				if ((int) E.size() == M) break;
				j++;
			}
			if ((int) E.size() == M) break;
		}
		if ((int) E.size() == M) {
			cout << "Possible\n";
			for (int i = 0; i < (int) E.size(); i++) cout << E[i].first << " " << E[i].second << "\n";
		} else cout << "Impossible\n";
	}
	return 0;
}
