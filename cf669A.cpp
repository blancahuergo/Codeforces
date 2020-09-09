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
	int T, N, cnt, ones;
	cin >> T;
	while(T--) {
		cin >> N;
		int A[N];
		ones = 0;
		for (int i = 0; i < N; i++) {
			cin >> A[i];
			ones += A[i];
		}
		if (ones > N/2) {
			if (ones % 2 == 0) {
				cout << ones << "\n";
				cout << "1";
				for (int i = 1; i < ones; i++) cout << " 1";
				cout << "\n";
			} else {
				cout << ones-1 << "\n";
				cout << "1";
				for (int i = 1; i < ones-1; i++) cout << " 1";
				cout << "\n";
			}
		} else {
			cout << N/2 << "\n";
			cout << "0";
			for (int i = 1; i < N/2; i++) cout << " 0";
			cout << "\n";
		}
	}
	return 0;
}
