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

int K, N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, ones, zeros;
	char init;
	bool pos;
	cin >> T;
	string S;
	while(T--) {
		cin >> N >> K;
		cin >> S;
		pos = true;
		for (int i = 0; i < K; i++) {
			init = S[i];
			if (init == '?') {
				for (int j = i+K; j < N; j += K) {
					if (S[j] != '?') {
						init = S[j];
						break;
					}
				}
			}
			if (init == '?') continue;
			for (int j = i; j < N; j += K) {
				if (S[j] == '?') S[j] = init;
				else if (S[j] != init) {
					pos = false;
					break;
				}
			}
			if (!pos) break;
		}
		if (pos) {
			ones = zeros = 0;
			for (int i = 0; i < K; i++) {
				if (S[i] == '1') ones++;
				else if (S[i] == '0') zeros++;
			}
			if (max(ones, zeros) > K/2) pos = false;
			if (pos) cout << "YES\n";
			else cout << "NO\n";
		}
		else cout << "NO\n";
	}
	return 0;
}
