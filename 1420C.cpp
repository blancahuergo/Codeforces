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
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
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

int N;
vi A;
vector<ll> PP, PN, NP, NN;

void setVal(int x) {
	PP[x] = max(max(PP[2*x] + NP[2*x+1], PN[2*x] + PP[2*x+1]), max(PP[2*x], PP[2*x+1]));
	PN[x] = max(max(PP[2*x] + NN[2*x+1], PN[2*x] + PN[2*x+1]), max(PN[2*x], PN[2*x+1]));
	NP[x] = max(max(NN[2*x] + PP[2*x+1], NP[2*x] + NP[2*x+1]), max(NP[2*x], NP[2*x+1]));
	NN[x] = max(max(NN[2*x] + PN[2*x+1], NP[2*x] + NN[2*x+1]), max(NN[2*x], NN[2*x+1]));
}

void calcNode(int x, int L) {
	PP[x] = (ll) A[L];
	NN[x] = (ll) (-A[L]);
	PN[x] = NN[x];
	NP[x] = 0ll;
}

void build(int x, int L, int R) {
	if (L == R) {
		calcNode(x, L);
		return;
	}
	int mid = L + (R-L)/2;
	build(2*x, L, mid);
	build(2*x+1, mid+1, R);
	setVal(x);
}

void update(int x, int l, int r, int firstInd, int secInd) {
	if (r < firstInd || l > secInd) return;
	if (l > firstInd && r < secInd) return;
	if (l == r) {
		calcNode(x, l);
	} else {
		int mid = l + (r-l)/2;
		update(2*x, l, mid, firstInd, secInd);
		update(2*x+1, mid+1, r, firstInd, secInd);
		setVal(x);
	}
}

ll queryAll() {
	return max(max(PP[1], PN[1]), max(NP[1], NN[1]));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, Q, indA, indB;
	cin >> T;
	while(T--) {
		cin >> N >> Q;
		A = vi(N);
		PP = PN = NP = NN = vl(4*N, 0ll);
		for (int i = 0; i < N; i++) cin >> A[i];
		build(1, 0, N-1);
		cout << queryAll() << "\n";
		while(Q--) {
			cin >> indA >> indB;
			indA--;
			indB--;
			swap(A[indA], A[indB]);
			update(1, 0, N-1, indA, indB);
			cout << queryAll() << "\n";
		}
	}
	return 0;
}
