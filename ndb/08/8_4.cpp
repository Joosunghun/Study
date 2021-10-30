// 8_4 바닥공사
// 가로의 길이가 N, 세로의 길이가 2
// 1 X 2, 2 X 1, 2 X 2 덮개로 바닥을 채우는 모든 경우의 수 구하기

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	int dp[1001];

	cin >> n;
	dp[1] = 1;                      // n이 1일 경우 경우의 수 1가지
	dp[2] = 3;                      // n이 2일 경우 경우의 수 3가지
	for (int i = 3; i <= n; i++) {                                             // n번째 열을 채우는 경우의 수 => n-1번째 열까지 채우고, 2 X 1 타일을 하나 사용하는 경우 && n-2번째 열까지 채우고 1 X 2 타일 2개를 사용하는 경우, 2 X 2 타일 1개를 사용하는 경우
		dp[i] = (dp[i - 1] + 2 * dp[n - 2]) % 796796;              // D(n) = D(n-1) + 2 X D(n-2)
	}
	cout << dp[n] << endl;
}