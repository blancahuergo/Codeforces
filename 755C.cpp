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
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<vvvl> vvvvl;
typedef vector<string> vs;
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define len(v) ((int)v.size())
#define all(v) v.begin(), v.end()

vi par, rnk;
int N, numSets;

int root(int a) {
	if (a == par[a]) return a;
	return par[a] = root(par[a]);
}

void merge(int a, int b) {
	int r_a = root(a), r_b = root(b);
	if (r_a == r_b) return;
	numSets--;
	if (rnk[r_a] != rnk[r_b]) {
		if (rnk[r_a] < rnk[r_b]) par[r_a] = r_b;
		else par[r_b] = r_a;
	} else {
		par[r_a] = r_b;
		rnk[r_b]++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	rnk.assign(N, 0);
	par.assign(N, 0);
	for (int i = 1; i < N; i++) par[i] = i;
	int j;
	numSets = N;
	for (int i = 0; i < N; i++) {
		cin >> j;
		merge(i, j-1);
	}
	cout << numSets;
	return 0;
}
