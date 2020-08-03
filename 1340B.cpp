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

int N, K, C;
vi dict, dig;
vector<vpii> canMake;
vvi exist;

int toBin(string A) {
	int ans = 0;
	for (int i = 0; i < 7; i++) {
		if(A[i] == '1') ans += 1<<(7-i-1);
	}
	return ans;
}

int make(int cur, int goal) {
	int ans = 0;
	for (int k = 0; k < 7; k++) {
		if ((goal & (1<<k)) == 0) {
			if ((cur & (1<<k)) > 0) return -1;
		} else if ((cur & (1<<k)) == 0) ans++;
	}
	return ans;
}

void fillIn(int n) {
	int m;
	if (n == 7) {
		for (int i = 9; i >= 0; i--) {
			m = make(C, dict[i]);
			if (m != -1) {
				canMake[C].push_back(make_pair(i, m));
			}
		}
		return;
	}
	C += (1<<n);
	fillIn(n+1);
	C -= (1<<n);
	fillIn(n+1);
}

int pos(int n, int k) {
	if (k > K) return 0;
	if (exist[n][k] != -1) return exist[n][k];
 	if (n == N) {
		if (k == K) {
			return exist[n][k] = 1;
		}
		else {
			return exist[n][k] = 0;
		}
	}
	if (k > K) {
		return exist[n][k] = 0;
	}
	int cst;
	pii curP;
	for (int i = 0; i < (int) canMake[dig[n]].size(); i++) {
		curP = canMake[dig[n]][i];
		cst = curP.second;
		if (pos(n+1, k+cst) == 1) {
			return exist[n][k] = 1;
		}
	}
	return exist[n][k] = 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;
	dict.assign(10, 0);
	dict[0] = 119;
	dict[1] = 18;
	dict[2] = 93;
	dict[3] = 91;
	dict[4] = 58;
	dict[5] = 107;
	dict[6] = 111;
	dict[7] = 82;
	dict[8] = 127;
	dict[9] = 123;
	dig = vector<int>(N);
	string cc;
	for (int i = 0; i < N; i++) {
		cin >> cc;
		dig[i] = toBin(cc);
	}
	C = 0;
	canMake.assign(128, vpii());
	fillIn(0);
	vi disp = vi(N, -1);
	exist.assign(N+1, vi(K+1, -1));
	pos(0, 0);
	int curK, num, cst;
	pii curP;
	if (exist[0][0] == 1) {
		curK = K;
		for (int i = N; i > 0; i--) {
			for (int j = 0; j < (int) canMake[dig[i-1]].size(); j++) {
				curP = canMake[dig[i-1]][j];
				num = curP.first;
				cst = curP.second;
				if (curK - cst >= 0 && exist[i-1][curK - cst] == 1) {
					curK -= cst;
					disp[i-1] = num;
					break;
				}
			}
		}
		for (int i = 0; i < N; i++) cout << disp[i];
		cout << "\n";
	} else cout << "-1\n";
	return 0;
}
