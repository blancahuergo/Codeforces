#include <iostream>
using namespace std;

int sum, len;

string minimum(string start, int curSum) {
	if ((int) start.length() == len) {
		if (curSum == sum) {
			return start;
		}
		else return "-1";
	}
	if (curSum + (len - (int) start.length())*9 < sum) return "-1";
	string cur;
	if ((int) start.length()) {
		cur = minimum(start + "0", curSum);
		if (cur[0] != '-') return cur;
	}
	cur = minimum(start + "1", curSum+1);
	if (cur[0] != '-') return cur;
	cur = minimum(start + "2", curSum+2);
	if (cur[0] != '-') return cur;
	cur = minimum(start + "3", curSum+3);
	if (cur[0] != '-') return cur;
	cur = minimum(start + "4", curSum+4);
	if (cur[0] != '-') return cur;
	cur = minimum(start + "5", curSum+5);
	if (cur[0] != '-') return cur;
	cur = minimum(start + "6", curSum+6);
	if (cur[0] != '-') return cur;
	cur = minimum(start + "7", curSum+7);
	if (cur[0] != '-') return cur;
	cur = minimum(start + "8", curSum+8);
	if (cur[0] != '-') return cur;
	cur = minimum(start + "9", curSum+9);
	return cur;
}

string maximum(string start, int curSum) {
	if ((int) start.length() == len) {
		if (curSum == sum) return start;
		else return "-1";
	}
	if (curSum > sum) return "-1";
	string cur;
	cur = maximum(start + "9", curSum+9);
	if (cur[0] != '-') return cur;
	cur = maximum(start + "8", curSum+8);
	if (cur[0] != '-') return cur;
	cur = maximum(start + "7", curSum+7);
	if (cur[0] != '-') return cur;
	cur = maximum(start + "6", curSum+6);
	if (cur[0] != '-') return cur;
	cur = maximum(start + "5", curSum+5);
	if (cur[0] != '-') return cur;
	cur = maximum(start + "4", curSum+4);
	if (cur[0] != '-') return cur;
	cur = maximum(start + "3", curSum+3);
	if (cur[0] != '-') return cur;
	cur = maximum(start + "2", curSum+2);
	if (cur[0] != '-') return cur;
	cur = maximum(start + "1", curSum+1);
	if (cur[0] != '-') return cur;
	if ((int) start.length()) {
		cur = maximum(start + "0", curSum);
		return cur;
	}
	return "-1";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> len >> sum;
	string mn, mx;
	if (sum == 0) {
		if (len == 1) mn = mx = "0";
		else mn = mx = "-1";
	} else if(sum > 9*len) mn = mx = "-1";
	else {
		mn = minimum("", 0);
		mx = maximum("", 0);
		if (mn[0] == '0') mn = "-1";
		if (mx[0] == '0') mx = "-1";
	}
	cout << mn << " " << mx << "\n";
	return 0;
}
