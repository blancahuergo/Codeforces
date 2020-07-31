#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N;
	cin >> T;
	vector<bool> win;
	while(T--) {
		cin >> N;
		int A[N];
		for (int n = 0; n < N; n++) cin >> A[n];
		win.assign(N, false);
		win[N-1] = true;
		for (int n = N-2; n >= 0; n--) {
			if (win[n+1] == false || A[n] > 1) win[n] = true;
			else win[n] = false;
		}
		if (win[0]) cout << "First\n";
		else cout << "Second\n";
	}
	return 0;
}
