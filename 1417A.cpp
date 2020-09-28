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
	int T, N, K, cur, nxt, pos;
	priority_queue<int> PQ;
	cin >> T;
	while(T--) {
		cin >> N >> K;
		PQ = priority_queue<int>();
		for (int i = 0; i < N; i++) {
			cin >> cur;
			PQ.push(-cur);
		}
		pos = 0;
		while((int) PQ.size() >= 2) {
			cur = -PQ.top();
			PQ.pop();
			nxt = -PQ.top();
			PQ.pop();
			if (cur + nxt > K) break;
			pos++;
			PQ.push(-(cur+nxt));
			PQ.push(-min(cur, nxt));
		}
		cout << pos << "\n";
	}
	return 0;
}
