#include <iostream>
#include <fstream>
#include <cfloat>
#include <iomanip>
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
typedef vector<vpii> vvpii;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<vvvl> vvvvl;
typedef vector<string> vs;
#define fir first
#define sec second
#define pb push_back
#define eb emplace_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define len(v) ((int)v.size())
#define all(v) v.begin(), v.end()

vi A, DPF, DPY;
int N;

int minSkip(int l, bool fTurn) {
	if (l >= N) return 0;
	int ans = INT_MAX;
	if (fTurn) {
		if (DPF[l] != -1) return DPF[l];
		if (A[l]) {
			if (l+1 < N && A[l+1]) ans = min(ans, 2 + minSkip(l+2, 0));
			else ans = min(ans, 1+minSkip(l+2, 0));
			ans = min(ans, 1 + minSkip(l+1, 0));
		} else {
			if (l+1 < N && A[l+1]) ans = min(ans, 1 + minSkip(l+2, 0));
			else ans = min(ans, minSkip(l+2, 0));
			ans = min(ans, minSkip(l+1, 0));
		}
		return DPF[l] = ans;
	} else {
		if (DPY[l] != -1) return DPY[l];
		ans = min(minSkip(l+1, 1), minSkip(l+2, 1));
		return DPY[l] = ans;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while(T--) {
		cin >> N;
		A = vi(N);
		for (int i = 0; i < N; i++) cin >> A[i];
		DPF.assign(N, -1);
		DPY.assign(N, -1);
		cout << minSkip(0, 1) << "\n";
	}
	return 0;
}
