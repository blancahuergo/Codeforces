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

int N;
vi A, pos, M;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, cur;
	cin >> T;
	while(T--) {
		cin >> N;
		A = vi(N);
		for (int i = 0; i < N; i++) cin >> A[i];
		M.clear();
		pos.clear();
		for (int i = 0; i < N; i++) {
			cin >> cur;
			if (cur == 0) {
				M.eb(A[i]);
				pos.pb(i);
			}
		}
		sort(M.begin(), M.end(), greater<int>());
		for (int i = 0; i < (int) pos.size(); i++) A[pos[i]] = M[i];
		for (int i = 0; i < N; i++) cout << A[i] << " ";
		cout << "\n";
	}
	return 0;
}
