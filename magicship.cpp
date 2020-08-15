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
int N;
ll x[2], y[2];
string S;
vi sumX, sumY;

bool check(ll d) {
	ll initD = d;
	ll windX, windY, Nlong;
	windX = x[0];
	windY = y[0];
	Nlong = (ll) N;
	if (d >= Nlong) {
		windX += sumX[N-1] * (d/Nlong);
		windY += sumY[N-1] * (d/Nlong);
		d %= Nlong;
	}
	if (d > 0) {
		windX += sumX[d-1];
		windY += sumY[d-1];
	}
	return (abs(x[1] - windX) + abs(y[1] - windY)) <= initD;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> x[0] >> y[0] >> x[1] >> y[1];
	cin >> N;
	cin >> S;
	sumX = sumY = vi(N);
	if (S[0] == 'U' || S[0] == 'D') {
		sumX[0] = 0;
		if (S[0] == 'U') sumY[0] = 1;
		else sumY[0] = -1;
	} else {
		sumY[0] = 0;
		if (S[0] == 'L') sumX[0] = -1;
		else sumX[0] = 1;
	}
	for (int i = 1; i < N; i++) {
		if (S[i] == 'U' || S[i] == 'D') {
			sumX[i] = sumX[i-1];
			if (S[i] == 'U') sumY[i] = sumY[i-1]+1;
			else sumY[i] = sumY[i-1]-1;
		} else {
			sumY[i] = sumY[i-1];
			if (S[i] == 'L') sumX[i] = sumX[i-1]-1;
			else sumX[i] = sumX[i-1]+1;
		}
	}
	ll lo = 1, hi = 2e15, mid, ans = -1;
	while(lo <= hi) {
		mid = lo + (hi-lo)/2;
		if (check(mid)) {
			ans = mid;
			hi = mid-1;
		}
		else lo = mid+1;
	}
	cout << ans << "\n";
	return 0;
}
