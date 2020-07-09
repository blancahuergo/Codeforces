#include <iostream>
#include <vector>
using namespace std;

string s;
vector<vector<vector<int>>> DP; // DP[pos][a][b] = max score using a rocks and b paper (the rest will be scissors)
vector<vector<vector<pair<int, int>>>> pre;

int calc(int A, int B, int C, int p) {
	if (p == 0) return 0;
	if (DP[p-1][A][B] != -1) return DP[p-1][A][B];
	int ans = -1, alt;
	if (A) {
		alt = (calc(A-1, B, C, p-1) + (s[p-1] == 'S')); // Rock
		if (alt > ans) {
			ans = alt;
			pre[p-1][A][B] = make_pair(A-1, B);
		}
	}
	if (B) {
		alt = (calc(A, B-1, C, p-1) + (s[p-1] == 'R')); // Paper
		if (alt > ans) {
			ans = alt;
			pre[p-1][A][B] = make_pair(A, B-1);
		}
	}
	if (C) {
		alt = (calc(A, B, C-1, p-1) + (s[p-1] == 'P')); // Scissors
		if (alt > ans) {
			ans = alt;
			pre[p-1][A][B] = make_pair(A, B);
		}
	}
	return DP[p-1][A][B] = max(ans, 0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N, A, B, C, score, curA, curB;
	string output;
	cin >> T;
	while(T--) {
		cin >> N;
		cin >> A >> B >> C;
		cin >> s;
		DP.assign(N, vector<vector<int>>(A+1, vector<int>(B+1, -1)));
		pre.assign(N, vector<vector<pair<int, int>>>(A+1, vector<pair<int, int>>(B+1, {-1, -1})));
		score = calc(A, B, C, N);
		if (score >= (N+1)/2) {
			cout << "YES\n";
			curA = A;
			curB = B;
			output="";
			for (int i = N-1; i > 0; i--) {
				if (pre[i][curA][curB] == make_pair(curA-1, curB)) {
					output = 'R' + output;
					curA--;
				} else if (pre[i][curA][curB] == make_pair(curA, curB-1)) {
					output = 'P' + output;
					curB--;
				} else output = 'S' + output;
			}
			if (curA) output = 'R' + output;
			else if (curB) output = 'P' + output;
			else output = 'S' + output;
			cout << output << "\n";
		}
		else cout << "NO\n";
	}
	return 0;
}
