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
	int N;
	cin >> N;
	vi A = vi(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	vvi seq;
	int lo, hi, mid, ans;
	for (int i = 0; i < N; i++) {
		lo = 0;
		hi = (int) seq.size()-1;
		ans = -1;
		while(lo <= hi) {
			mid = lo + (hi-lo)/2;
			if (A[i] > seq[mid][(int) seq[mid].size() - 1]) {
				ans = mid;
				hi = mid-1;
			} else lo = mid+1;
		}
		if (ans == -1) seq.push_back({A[i]});
		else seq[ans].push_back(A[i]);
	}
	for (int i = 0; i < (int) seq.size(); i++) {
		cout << seq[i][0];
		for (int j = 1; j < (int) seq[i].size(); j++) cout << " " << seq[i][j];
		cout << "\n";
	}
	return 0;
}
