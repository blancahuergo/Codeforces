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
	int T, capA, capB, cntA, cntB, wA, wB, Ataken, remA, remB;
	cin >> T;
	while(T--) {
		cin >> capA >> capB;
		cin >> cntA >> cntB;
		cin >> wA >> wB;
		// make A the lighest
		if (wA > wB) {
			swap(wA, wB);
			swap(cntA, cntB);
		}
		// get as many of the lighest as possible:
		Ataken = min(cntA, capA/wA + capB/wA);
		// use the rest of the space to fill with the heaviest
		int ans = 0, cur;
		for (int i = max(0, Ataken - capB/wA); i <= min(Ataken, capA/wA); i++) {
			remA = capA - i*wA;
			remB = capB - wA*(Ataken-i);
			cur = min(remA/wB + remB/wB, cntB);
			ans = max(cur, ans);
			if (ans == cntB) break;
		}
		cout << Ataken+ans << "\n";
	}
	return 0;
}
