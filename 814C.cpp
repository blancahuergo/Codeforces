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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, Q, M;
	string S;
	char c;
	cin >> N;
	cin >> S;
	cin >> Q;
	while(Q--) {
		cin >> M >> c;
		int j = -1, countM = 0, rec = 0;
		for (int i = 0; i < N; i++) {
			if (j < i) {
				countM = 0;
				if (S[i] != c) countM++;
				j = i;
			} else if (i && (S[i-1] != c)) countM--;
			if (countM > M) continue;
			while(j < N-1 && (S[j+1] == c || countM < M)) {
				j++;
				if (S[j] != c) countM++;
			}
			rec = max(rec, j-i+1);
		}
		cout << rec << "\n";
	}
	return 0;
}
