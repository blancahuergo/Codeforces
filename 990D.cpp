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

int N, a, b, comp, i;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> a >> b;
	vvi grid;
	if ((a > 1 && b != 1) || (a != 1 && b > 1) || ((N == 2 || N == 3) && a == 1 && b == 1)) cout << "NO\n";
	else if (a > 1) {
		grid.assign(N, vi(N, 0));
		comp = N;
		i = 0;
		while(comp > a) {
			grid[i][i+1] = 1;
			grid[i+1][i] = 1;
			i++;
			comp--;
		}
		cout << "YES\n";
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				cout << grid[j][k];
			}
			cout << "\n";
		}
	} else {
		grid.assign(N, vi(N, 1));
		comp = N;
		i = 0;
		while(comp > b) {
			grid[i][i+1] = 0;
			grid[i+1][i] = 0;
			i++;
			comp--;
		}
		cout << "YES\n";
		for (int j = 0; j < N; j++) {
			grid[j][j] = 0;
			for (int k = 0; k < N; k++) {
				cout << grid[j][k];
			}
			cout << "\n";
		}
	}
	return 0;
}
