// 문제 10844 쉬운 계단 수
// 인접한 모든 자리의 차이가 1인 수를 계단수라고 한다.
// N이 주어질 때, 길이가 N인 계단 수가 총 몇개 있는지를 구하는 프로그램
// 0으로 시작하는 수는 계단수가 아님

#include <iostream>
using namespace std;

int main(void) {
	int dp[101][10];
	int n;
	int sum = 0;

	cin >> n;

	for (int i = 0; i < 10; i++)        // i로 끝나는 길이 1인 계단 수는 1개
		dp[1][i] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0)
				dp[i][0] = dp[i - 1][1];            // 수가 0 일때는 다음 수가 1만 가능
			else if (j == 9)
				dp[i][9] = dp[i - 1][8];           // 수가 9 일때는 다음 수가 8 만가능
			else
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		}
	}
	for (int i = 1; i < 10; i++) {
		sum = (sum + dp[n][i]) % 1000000000;
	}

	cout << sum % 1000000000 << '\n';
}