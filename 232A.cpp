#include <iostream>
#include <cstring>
using namespace std;

int K;
int G[100][100];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> K;
	memset(G, 0, sizeof(G));
	bool added;
	int curN = 3, E = 1, c;
	for (int i = 0; i < 3; i++) {
		for (int j = i+1; j < 3; j++) {
			G[i][j] = G[j][i] = 1;
		}
	}
	while(true) {
		added = false;
		if (E == K) break;
		for (int a = 0; a < curN; a++) {
			for (int b = a+1; b < curN; b++) {
				if (!G[a][b]) {
					c = 0;
					for (int j = 0; j < curN; j++) {
						if (G[a][j] && G[b][j]) c++;
					}
					if (E+c <= K) {
						E += c;
						G[a][b] = G[b][a] = 1;
						added = true;
					}
				}
			}
			if (E == K) break;
		}
		if (!added) {
			curN++;
			G[0][curN-1] = G[1][curN-1] = G[curN-1][0] = G[curN-1][1] = 1;
			E++;
		}
	}
	cout << curN << "\n";
	for (int i = 0; i < curN; i++) {
		for (int j = 0; j < curN; j++) {
			cout << G[i][j];
		}
		cout << "\n";
	}
	return 0;
}
