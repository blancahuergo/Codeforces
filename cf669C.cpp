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
	int N, a, b, known, numA, numB;
	cin >> N;
	vi arr;
	arr.assign(N, -1);
	known = 0;
	queue<int> Q;
	for (int i = 1; i <= N; i++) Q.push(i);
	// odd number of elements?????
	while(Q.size() >= 2) {
		numA = Q.front();
		Q.pop();
		numB = Q.front();
		Q.pop();
		cout << "? " << numA << " " << numB << "\n";
		cout.flush();
		cin >> a;
		cout << "? " << numB << " " << numA << "\n";
		cout.flush();
		cin >> b;
		if (a > b) {
			arr[numA-1] = a;
			known += a;
			Q.push(numB);
		}
		else {
			arr[numB - 1] = b;
			known += b;
			Q.push(numA);
		}
	}
	numA = N*(N+1)/2 - known;
	if (numA > 0) {
		for (int i = 0; i < N; i++) {
			if (arr[i] == -1) {
				arr[i] = numA;
				break;
			}
		}
	}
	cout << "! " << arr[0];
	for (int i = 1; i < N; i++) cout << " " << arr[i];
	cout << "\n";
	cout.flush();
	return 0;
}
