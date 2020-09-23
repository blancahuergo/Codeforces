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

vi fact, primeFact, factTimes;
int N;

void factorise() {
	fact.clear();
	for (int i = 2; i*i <= N; i++) {
		if (N%i) continue;
		fact.eb(i);
		if (N/i != i) fact.eb(N/i);
	}
	sort(fact.begin(), fact.end());
	fact.eb(N);
}

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

void getPrimeFactors() {
	primeFact.clear();
	int ind = 0;
	for (int i = 2; i*i <= N; i++) {
		if (N%i) continue;
		primeFact.eb(i);
		factTimes.eb(0);
		while(!(N % i)) {
			N /= i;
			factTimes[ind]++;
		}
		ind++;
	}
	if (N > 1) {
		primeFact.eb(N);
		factTimes.eb(1);
	}
}

void orderFact() {
	getPrimeFactors();
	int k = (int) primeFact.size();
	vi ans;
	map<int, bool> taken;
	for (int i = 0; i < (int) fact.size(); i++) taken[fact[i]] = false;
	for (int i = 0; i < k; i++) taken[primeFact[i]] = true;
	if (k > 1) for (int i = 0; i < k; i++) taken[primeFact[i]*primeFact[(i+1)%k]] = true;
	int st = 0;
	if (k > 2) {
		for (int i = 0; i < k; i++) {
			ans.eb(primeFact[i]);
			while(fact[st] < primeFact[i]) st++;
			for (int j = st; j < (int) fact.size(); j++) {
				if ((fact[j] % primeFact[i] == 0) && (taken[fact[j]] == false)) {
					ans.eb(fact[j]);
					taken[fact[j]] = true;
				}
			}
			ans.eb(primeFact[i]*primeFact[(i+1)%k]);
		}
	} else {
		ans.eb(primeFact[0]);
		while(fact[st] < primeFact[0]) st++;
		for (int j = st; j < (int) fact.size(); j++) {
			if ((fact[j] % primeFact[0] == 0) && (taken[fact[j]] == false)) {
				ans.eb(fact[j]);
				taken[fact[j]] = true;
			}
		}
		if (k == 2) {
			ans.eb(primeFact[1]);
			while(fact[st] < primeFact[1]) st++;
			for (int j = st; j < (int) fact.size(); j++) {
				if ((fact[j] % primeFact[1] == 0) && (taken[fact[j]] == false)) {
					ans.eb(fact[j]);
					taken[fact[j]] = true;
				}
			}
			ans.eb(primeFact[0]*primeFact[1]);
		}
	}
	fact = ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while(T--) {
		cin >> N;
		factorise();
		if ((int) fact.size() <= 3) {
			if ((int) fact.size() == 1) {
				cout << fact[0] << "\n";
				cout << "0\n";
			} else if ((int) fact.size() == 2) {
				cout << fact[0] << " " << fact[1] << "\n";
				cout << "0\n";
			}
			else {
				cout << fact[0] << " " << fact[1] << " " << N << "\n";
				cout << (int) (gcd(fact[0], fact[1])==1) << "\n";
			}
		} else {
			orderFact();
			for (int i = 0; i < (int) fact.size(); i++) cout << fact[i] << " ";
			cout << "\n";
			cout << "0\n";
		}
	}
	return 0;
}
