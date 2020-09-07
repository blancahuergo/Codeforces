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
	int T, N, p1, p2, diff;
	ll cst;
	vi P;
	cin >> T;
	while(T--) {
		cin >> N;
		P.assign(N, 0);
		for (int i = 0; i < N; i++) cin >> P[i];
		p2 = p1 = -1;
		for (int i = 0; i < N; i++) {
			if (p2 == -1 && P[i] < 0) {
				p2 = i;
				if (p1 != -1) break;
			}
			else if (p1 == -1 && P[i] > 0) {
				p1 = i;
				if (p2 != -1) break;
			}
		}
		cst = 0ll;
		while(p1 < N && p2 < N) {
			if (P[p1] <= 0) {
				p1++;
				continue;
			}
			if (P[p2] >= 0) {
				p2++;
				continue;
			}
			if (p1 >= p2) {
				p2 = p1+1;
				continue;
			}
			diff = min(abs(P[p2]), P[p1]);
			P[p1] -= diff;
			P[p2] += diff;
			if (P[p1] == 0) {
				p1++;
				if (P[p2] == 0) p2++;
			} else p2++;
		}
		p2 = p1 = -1;
		for (int i = 0; i < N; i++) {
			if (p2 == -1 && P[i] > 0) {
				p2 = i;
				if (p1 != -1) break;
			}
			else if (p1 == -1 && P[i] < 0) {
				p1 = i;
				if (p2 != -1) break;
			}
		}
		while(p1 < N && p2 < N) {
			if (P[p1] >= 0) {
				p1++;
				continue;
			}
			if (P[p2] <= 0) {
				p2++;
				continue;
			}
			if (p1 >= p2) {
				p2 = p1+1;
				continue;
			}
			diff = min(abs(P[p1]), P[p2]);
			cst += diff;
			P[p1] += diff;
			P[p2] -= diff;
			if (P[p1] == 0) {
				p1++;
				if (P[p2] == 0) p2++;
			} else p2++;
		}
		cout << cst << "\n";
	}
	return 0;
}
