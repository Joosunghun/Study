// 8_2 1로 만들기
// X가 5로 나누어 떨어지면, 5로 나눔
// X가 3으로 나누어 떨어지면, 3으로 나눔
// X가 2로 나누어 떨어지면, 2로 나눔
// X에서 1을 뺌
// 4가지 연산을 사용해서 1로 만들기, 최소 연산

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	int x;
	cin >> x;
	int dp[30001];

	dp[1] = 0;
	for (int i = 2; i <= x; i++) {
		dp[i] = dp[i - 1] + 1;                       // 1을 빼는 경우
		if (i % 5 == 0)
			dp[i] = min(dp[i], dp[i / 5] + 1);  // 5로 나누어 지는 경우
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);  // 3으로 나누어 지는 경우
		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);  // 2로 나누어 지는 경우
	}
	cout << dp[x] << endl;      // dp 에 저장된 값 출력
}