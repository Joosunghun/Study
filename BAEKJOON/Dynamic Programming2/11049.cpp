// 문제 11049번 행렬 곱셈 순서
// 크기가 N x M인 행렬 A와 M x K인 B를 곱할 때 필요한 곱셈 연산의 수는 N x M x K 번이다. 행렬 N개를 곱하는데 필요한 곱셈 연산 의 수는 행렬을 곱하는 순서에 따라 달라지게 된다.
// 같은 곱셈이지만, 곱셈을 하는 순서에 따라서 연산의 수가 달라진다.
// 행렬 N개의 크기가 주어졌을 떄, 모든 행렬을 곱하는데 필요한 곱셈 연산 횟수의 최솟값을 구하는 프로그램

#include <iostream>
#include <algorithm>

#define INF 1000000000;

using namespace std;

int n, r, c;
int sum[501], matrix[501][2], dp[501][501];

int main(void) {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> r >> c;
		matrix[i][0] = r;
		matrix[i][1] = c;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; i + j <= n; j++) {
			dp[j][i + j] = INF;
			for (int k = j; k <= i + j; k++)
				dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + matrix[j][0] * matrix[k][1] * matrix[i + j][1]);
		}
	}

	cout << dp[1][n] << '\n';
}