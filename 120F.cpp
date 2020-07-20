#include <fstream>
#include <vector>
#include <queue>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi G;
vi dist;
int N;

int diam() {
	dist.assign(N, 1000);
	queue<int> Q;
	Q.push(0);
	dist[0] = 0;
	int u;
	while(Q.size()) {
		u = Q.front();
		Q.pop();
		for (int i = 0; i < (int) G[u].size(); i++) {
			if (dist[G[u][i]] > dist[u]+1) {
				Q.push(G[u][i]);
				dist[G[u][i]] = dist[u]+1;
			}
		}
	}
	int maxV = 0, maxDist = 0;
	for (int i = 1; i < N; i++) {
		if (dist[i] > maxDist) {
			maxDist = dist[i];
			maxV = i;
		}
	}
	Q.push(maxV);
	dist.assign(N, 1000);
	dist[maxV] = 0;
	while (Q.size()) {
		u = Q.front();
		Q.pop();
		for (int i = 0; i < (int) G[u].size(); i++) {
			if (dist[G[u][i]] > dist[u] + 1) {
				Q.push(G[u][i]);
				dist[G[u][i]] = dist[u] + 1;
			}
		}
	}
	maxDist = 0;
	for (int i = 0; i < N; i++) {
		maxDist = max(maxDist, dist[i]);
	}
	return maxDist;
}

int main() {
	int T, tot = 0, a, b;
	ifstream fin;
	ofstream fout;
	fin.open("input.txt");
	fin >> T;
	for (int t = 0; t < T; t++) {
		fin >> N;
		G.assign(N, vi());
		for (int n = 0; n < N-1; n++) {
			fin >> a >> b;
			G[a-1].emplace_back(b-1);
			G[b-1].emplace_back(a-1);
		}
		tot += diam();
	}
	fin.close();
	fout.open("output.txt");
	fout << tot << "\n";
	fout.close();
	return 0;
}
