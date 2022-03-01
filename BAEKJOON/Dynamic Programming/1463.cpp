// 문제 1463번 1로 만들기
// 정수 x에 사용할 수 있는 연산이 3가지
// 1. x가 3으로 나누어 떨어지면, 3으로 나눈다. 2. x가 2로 나누어 떨어지면, 2로 나눈다. 3. 1을 뺀다.
// 정수가 주어졌을 때, 위 연산들을 사용하여 1을 만든다. 연산을 사용하는 횟수의 최솟값을 출력하는 프로그램

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<int> dp(n + 1);

	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;           // 1을 빼는 경우
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);       // 3으로 나누어 지는 경우
		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);       // 2로 나누어 지는 경우
	}
	cout << dp[n] << '\n';
	return 0;

}