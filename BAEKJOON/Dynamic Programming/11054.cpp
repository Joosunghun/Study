// 문제 11054번 가장 긴 바이토닉 부분 수열
// 수열 S가 어떤 수 Sk를 기준으로 S1 < S2 < ... Sk-1 < Sk > Sk+1 > ... SN-1 > SN을 만족한다면, 그 수열을 바이토닉 수열이라고 한다.
// 수열 A가 주어졌을 떄, 그 수열의 부분 수열 중 바이토닉 수열이면서 가장 긴 수열의 길이를 구하는 프로그램

#include <iostream>
using namespace std;

int main(void) {
	int n;
	int a[1001];
	int dp[2][1001];

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {             // 처음부터 시작
		dp[0][i] = 1;
		for (int j = 1; j < i; j++) {
			if (a[i] > a[j] && dp[0][i] < dp[0][j] + 1)
				dp[0][i] = dp[0][j] + 1;
		}
	}

	for (int i = n; i >= 1; i--) {            // 끝에서 부터 시작
		dp[1][i] = 1;
		for (int j = n; j > i; j--) {
			if (a[i] > a[j] && dp[1][i] < dp[1][j] + 1)
				dp[1][i] = dp[1][j] + 1;
		}
	}

	int max = 0;
	for (int i = 1; i <= n; i++) {
		if (max < dp[0][i] + dp[1][i] - 1)
			max = dp[0][i] + dp[1][i] - 1;
	}

	cout << max << '\n';

	return 0;
}