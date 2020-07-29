#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int N, r1, c1, r2, c2;
vi A;
vvi dist;

int main() {
	ifstream fin;
	fin.open("input.txt");
	fin >> N;
	A.assign(N, 0);
	int mx = 0;
	for (int i = 0; i < N; i++) {
		fin >> A[i];
		mx = max(mx, A[i]);
	}
	fin >> r1 >> c1 >> r2 >> c2;
	r1--;
	c1--;
	r2--;
	c2--;
	dist.assign(N, vi(mx+1, 1e9));
	dist[r1][c1] = 0;
	queue<int> R, C, D;
	R.push(r1);
	C.push(c1);
	D.push(0);
	int curR, curC, curD;
	while(R.size()) {
		curR = R.front();
		R.pop();
		curC = C.front();
		C.pop();
		curD = D.front();
		D.pop();
		if (curD > dist[curR][curC]) continue;
		// Up
		if ((curR > 0) && (curD + 1 < dist[curR-1][min(curC, A[curR-1])])) {
			dist[curR-1][min(curC, A[curR-1])] = curD + 1;
			R.push(curR - 1);
			C.push(min(curC, A[curR-1]));
			D.push(curD + 1);
		}
		// Down
		if ((curR < N-1) && (curD + 1 < dist[curR+1][min(curC, A[curR+1])])) {
			dist[curR+1][min(curC, A[curR+1])] = curD + 1;
			R.push(curR + 1);
			C.push(min(curC, A[curR+1]));
			D.push(curD + 1);
		}
		// Left
		if ((curC > 0) && (curD + 1 < dist[curR][curC - 1])) {
			dist[curR][curC - 1] = curD + 1;
			R.push(curR);
			C.push(curC - 1);
			D.push(curD + 1);
		}
		// Right
		if ((curC < A[curR]) && (curD + 1 < dist[curR][curC + 1])) {
			dist[curR][curC + 1] = curD + 1;
			R.push(curR);
			C.push(curC + 1);
			D.push(curD + 1);
		}
	}
	fin.close();
	ofstream fout;
	fout.open("output.txt");
	fout << dist[r2][c2] << "\n";
	fout.close();
	return 0;
}
