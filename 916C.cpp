#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

vi dist;
vvi E;

bool isPrime(int n) {
    if (n <= 1)  return false;
    if (n <= 3)  return true;
    if (n%2 == 0 || n%3 == 0) return false;
    for (int i=5; i*i<=n; i=i+6) {
        if (n%i == 0 || n%(i+2) == 0) {
           return false;
        }
    }
    return true;
}

int nextP(int n) {
	int i = n;
	while(true) {
		if (isPrime(i)) return i;
		i++;
	}
	return 0;
}

int main() {
	int N, M, sm, edLen, D;
	cin >> N >> M;
	sm = nextP(N-1);
	edLen = sm/(N-1);
	dist.assign(N, 0);
	for (int i = 1; i < N; i++) {
		dist[i] = edLen + dist[i-1];
		if (i < N-1) E.push_back({i, i+1, edLen});
	}
	dist[N-1] += sm - edLen * (N-1);
	E.push_back({N-1, N, dist[N-1] - dist[N-2]});
	D = 2;
	while(E.size() < M) {
		for (int i = 0; i < N-D; i++) {
			E.push_back({i+1, i+D+1, dist[i+D] - dist[i] + 1});
			if (E.size() == M) break;
		}
		D++;
	}
	cout << sm << " " << sm << "\n";
	for (int i = 0; i < M; i++) {
		cout << E[i][0] << " " << E[i][1] << " " << E[i][2] << "\n";
	}
	return 0;
}
