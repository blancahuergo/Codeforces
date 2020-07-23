#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> dist(max(N, M)+1);
	dist[N] = 0;
	for (int i = N-1; i >= 0; i--) {
		dist[i] = dist[i+1]+1;
	}
	for (int i = N+1; i <= M; i++) {
		if (i&1) dist[i] = dist[(i+1)/2]+2;
		else dist[i] = min(dist[i/2]+1, dist[(i+2)/2]+3);
	}
	cout << dist[M] << "\n";
	return 0;
}
