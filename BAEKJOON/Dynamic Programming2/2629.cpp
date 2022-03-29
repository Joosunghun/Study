// 문제 2629번 양팔저울
// 양팔 저울과 몇 개의 추가 주어졌을 때, 이를 이용하여 입력으로 주어진 구슬의 무게를 확인할 수 있는지를 결정하는 프로그램

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, bead, x, weight[31];
bool dp[31][15001];

void solve(int i, int w) {
	if (i > n || dp[i][w])
		return;
	dp[i][w] = true;
	solve(i + 1, w + weight[i]);
	solve(i + 1, abs(w - weight[i]));
	solve(i + 1, w);
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> weight[i];
	solve(0, 0);

	cin >> bead;

	for (int i = 0; i < bead; i++) {
		cin >> x;

		if (x > 15000)
			cout << "N ";
		else if (dp[n][x])
			cout << "Y ";
		else
			cout << "N ";

	}
}