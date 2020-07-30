#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int ll;

int N, M, count, numSCC;
vvi G;
vi cost, visit, st, CCbelong, lowest, CCsizes, lowC;
vector<bool> V;

void SCCs(int S) {
	visit[S] = lowest[S] = ++count;
	st.push_back(S);
	V[S] = true;
	int v;
	for (int i = 0; i < (int) G[S].size(); i++) {
		v = G[S][i];
		if (visit[v] == -1) {
			SCCs(v);
			lowest[S] = min(lowest[S], lowest[v]);
		} else if (V[v]) {
			lowest[S] = min(lowest[S], visit[v]);
		}
	}
	if (lowest[S] == visit[S]) {
		while(true) {
			v = st.back();
			st.pop_back();
			V[v] = false;
			CCbelong[v] = numSCC;
			if (S == v) break;
		}
		numSCC++;
	}
}

void runSCC() {
	count = numSCC = 0;
	visit.assign(N, -1);
	lowest.assign(N, 0);
	V.assign(N, false);
	CCbelong.assign(N, 0);
	for (int i = 0; i < N; i++) {
		if (visit[i] == -1)
			SCCs(i);
	}
}

void calcCosts() {
	CCsizes.assign(numSCC, 1);
	lowC.assign(numSCC, 1e9 + 2);
	for (int i = 0; i < N; i++) {
		if (cost[i] < lowC[CCbelong[i]]) {
			lowC[CCbelong[i]] = cost[i];
			CCsizes[CCbelong[i]] = 1;
		} else if (cost[i] == lowC[CCbelong[i]]) {
			CCsizes[CCbelong[i]]++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	G.assign(N, vi());
	cost.assign(N, 0);
	for (int i = 0; i < N; i++) cin >> cost[i];
	cin >> M;
	int u, v;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		G[u-1].emplace_back(v-1);
	}
	runSCC();
	calcCosts();
	ll ways = 1ll, C = 0ll, mod = 1e9 + 7;
	for (int i = 0; i < numSCC; i++) {
		C += lowC[i];
	}
	for (int i = 0; i < numSCC; i++) {
		ways *= CCsizes[i];
		ways %= mod;
	}
	cout << C << " " << ways << "\n";
	return 0;
}
