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
typedef vector<string> vs;
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define len(v) ((int)v.size())
#define all(v) v.begin(), v.end()

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, x, y, lst, cur;
	cin >> N >> M >> x >> y;
	cout << x << " " << y << "\n";
	x--;
	y--;
	lst = 0;
	for (int c = 0; c < M; c++) {
		if (c != y) {
			lst = c;
			cout << x+1 << " " << c+1 << "\n";
		}
	}
	cur = lst;
	for (int r = x+1; r < N; r++) {
		cout << r+1 << " " << lst+1 << "\n";
		for (int c = 0; c < M; c++) {
			if (c != lst) {
				cout << r+1 << " " << c+1 << "\n";
				cur = c;
			}
		}
		lst = cur;
	}
	for (int r = x-1; r >= 0; r--) {
		cout << r+1 << " " << lst+1 << "\n";
		for (int c = 0; c < M; c++) {
			if (c != lst) {
				cout << r+1 << " " << c+1 << "\n";
				cur = c;
			}
		}
		lst = cur;
	}
	return 0;
}
