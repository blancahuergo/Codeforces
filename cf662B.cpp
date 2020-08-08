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
#define fs first
#define sc second
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
	int N, Q, x, sq, rect1;
	pii pairSq, curSq;
	string op;
	cin >> N;
	vi counts = vi(1e5 + 1, 0);
	priority_queue<pii> PQ;
	for (int i = 0; i < N; i++) {
		cin >> x;
		counts[x]++;
	}
	for (int i = 1; i <= 100000; i++) {
		if (counts[i] >= 2) PQ.push({counts[i], i});
	}
	cin >> Q;
	while(Q--) {
		cin >> op >> x;
		// first, find number with smallest count of planks that is >= 4
		// then, taking these planks away find two pairs of numbers such that their count >= 2
		if (op[0] == '+') {
			counts[x]++;
		} else {
			counts[x]--;
		}
		if (counts[x] >= 2) PQ.push({counts[x], x});
		pairSq = mp(-1, -1);
		while(!PQ.empty()) {
			curSq = PQ.top();
			PQ.pop();
			if (counts[curSq.second] == curSq.first) {
				pairSq = curSq;
				break;
			}
		}
		if (pairSq.first < 4) {
			if (pairSq.first != -1) PQ.push(pairSq);
			cout << "NO\n";
			continue;
		}
		sq = pairSq.second;
		counts[sq] -= 4;
		if (counts[sq] >= 2) PQ.push({counts[sq], sq});
		pairSq = mp(-1, -1);
		while(!PQ.empty()) {
			curSq = PQ.top();
			PQ.pop();
			if (counts[curSq.second] == curSq.first) {
				pairSq = curSq;
				break;
			}
		}
		if (pairSq.first < 2) {
			cout << "NO\n";
			counts[sq] += 4;
			PQ.push({counts[sq], sq});
			continue;
		} else if (pairSq.first >= 4) {
			cout << "YES\n";
			counts[sq] += 4;
			PQ.push({counts[sq], sq});
			PQ.push(pairSq);
			continue;
		}
		rect1 = pairSq.second;
		counts[rect1] -= 2;
		pairSq = mp(-1, -1);
		while(!PQ.empty()) {
			curSq = PQ.top();
			PQ.pop();
			if (counts[curSq.second] == curSq.first) {
				pairSq = curSq;
				break;
			}
		}
		if (pairSq.first >= 2) {
			cout << "YES\n";
			counts[sq] += 4;
			PQ.push({counts[sq], sq});
			counts[rect1] += 2;
			PQ.push({counts[rect1], rect1});
			PQ.push(pairSq);
			continue;
		} else {
			cout << "NO\n";
			counts[sq] += 4;
			PQ.push({counts[sq], sq});
			counts[rect1] += 2;
			PQ.push({counts[rect1], rect1});
			continue;
		}
	}
	return 0;
}
