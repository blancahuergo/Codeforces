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
	int N;
	cin >> N;
	int A[N], B[N];
	for (int i = 0; i < N; i++) cin >> A[i];
	sort(A, A+N);
	int cnt = 0;
	for (int i = 1; i < N; i += 2) {
		B[i] = A[cnt];
		cnt++;
	}
	for (int i = 0; i < N; i += 2) {
		B[i] = A[cnt];
		cnt++;
	}
	int ans = 0;
	for (int i = 1; i < N-1; i++) if (B[i] < min(B[i-1], B[i+1])) ans++;
	cout << ans << "\n";
	for (int i = 0; i < N; i++) cout << B[i] << " ";
	return 0;
}
