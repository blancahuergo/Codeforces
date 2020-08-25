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


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, c;
	cin >> N >> M;
	vi mod(N);
	for (int i = 0; i < N; i++) {
		cin >> c;
		mod[i] = c % M;
	}
	vi last, cur;
	last.assign(M, 0);
	cur.assign(M, 0);
	for (int i = 0; i < N; i++) {
		for (int j = M-1; j >= 0; j--) if (last[j]) cur[(j + mod[i])%M] = 1;
		cur[mod[i]] = 1;
		last = cur;
		if (last[0]) break;
	}
	if (last[0]) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}
