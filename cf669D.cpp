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
	int N;
	vi H, lo, hi, loLeft, hiLeft;
	cin >> N;
	H = vi(N);
	for (int i = 0; i < N; i++) cin >> H[i];
	stack<int> larg, smal, largL, smalL;
	lo = hi = loLeft = hiLeft = vi(N, -1);
	larg.push(N-1);
	largL.push(0);
	smalL.push(0);
	smal.push(N-1);
	for (int i = N-2; i >= 0; i--) {
		while(larg.size() && H[larg.top()] < H[i]) {
			larg.pop();
		}
		if (larg.size()) {
			hi[i] = larg.top();
		}
		while(smal.size() && H[smal.top()] > H[i]) {
			smal.pop();
		}
		if (smal.size()) {
			lo[i] = smal.top();
		}
		larg.push(i);
		smal.push(i);
	}
	for (int i = 1; i < N; i++) {
		while (largL.size() && H[largL.top()] < H[i]) {
			largL.pop();
		}
		if (largL.size()) {
			hiLeft[i] = largL.top();
		}
		while(smalL.size() && H[smalL.top()] > H[i]) {
			smalL.pop();
		}
		if (smalL.size()) {
			loLeft[i] = smalL.top();
		}
		largL.push(i);
		smalL.push(i);
	}
	vi dist;
	dist.assign(N, N+1);
	dist[0] = 0;
	priority_queue<pii> PQ;
	PQ.push(mp(0, 0));
	pii curP;
	int u, distU, v;
	while(PQ.size()) {
		curP = PQ.top();
		PQ.pop();
		u = curP.s;
		distU = -curP.f;
		if (distU > dist[u]) continue;
		v = lo[u];
		if (v != -1 && dist[v] > dist[u]+1) {
			dist[v] = dist[u]+1;
			PQ.push(mp(-dist[v], v));
		}
		v = hi[u];
		if (v != -1 && dist[v] > dist[u]+1) {
			dist[v] = dist[u]+1;
			PQ.push(mp(-dist[v], v));
		}
		v = hiLeft[u];
		if (v != -1 && dist[u] > dist[v]+1) {
			dist[u] = dist[v]+1;
			PQ.push(mp(-dist[u], u));
		}
		v = loLeft[u];
		if (v != -1 && dist[u] > dist[v]+1) {
			dist[u] = dist[v]+1;
			PQ.push(mp(-dist[u], u));
		}
	}
	cout << dist[N-1] << "\n";
	return 0;
}
