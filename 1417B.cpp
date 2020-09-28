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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N, K;
	vi A, col;
	map<int, int> pos;
	cin >> T;
	while(T--) {
		cin >> N >> K;
		A = vi(N);
		col = vi(N);
		for (int i = 0; i < N; i++) cin >> A[i];
		if (K & 1) {
			for (int i = 0; i < N; i++) col[i] = A[i]&1;
		} else {
			pos.clear();
			for (int i = 0; i < N; i++) {
				if (pos.find(K - A[i]) != pos.end()) col[i] = 1 - pos[K - A[i]];
				else col[i] = 0;
				pos[A[i]] = col[i];
			}
		}
		cout << col[0];
		for (int i = 1; i < N; i++) cout << " " << col[i];
		cout << "\n";
	}
	return 0;
}
