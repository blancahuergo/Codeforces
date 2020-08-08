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

int N;

int findX() {
	cout << "1 " << N-1;
	for (int i = 1; i <= N; i++) cout << " " << i;
	cout << "\n";
	cout.flush();
	int last;
	cin >> last;
	int lo = 2, hi = N, mid, cur;
	while(lo < hi) {
		mid = (lo+hi)/2;
		cout << 1 << " " << mid-lo+1;
		cout << " " << 1;
		for (int i = lo; i <= mid; i++) cout << " " << i;
		cout << "\n";
		cout.flush();
		cin >> cur;
		if (cur == last) hi = mid;
		else lo = mid+1;
	}
	cout << 1 << " " << N-1;
	cout << " " << hi;
	for (int i = 1; i < hi; i++) cout << " " << i;
	for (int i = hi+1; i <= N; i++) cout << " " << i;
	cout << "\n";
	cout.flush();
	cin >> last;
	return last;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, x;
	cin >> T;
	while(T--) {
		cin >> N;
		if (N == 2) {
			cout << "1 1 1 2\n";
			cout.flush();
			cin >> x;
			cout << "-1 " << x << "\n";
			cout.flush();
		} else {
			x = findX();
			cout << "-1 " << x << "\n";
			cout.flush();
		}
	}
	return 0;
}
