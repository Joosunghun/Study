// 문제 2597번 계단 오르기
// 계단 아래 시작점부터 계단 꼭대기에 위치한 도착점까지 가는 게임.
// 계단에는 일정한 점수가 쓰여 있는데 계단을 밟으면 그 계단에 쓰여 있는 점수를 얻게 됨
// 규칙 : 1. 한 번에 한 계단씩 또는 두 계단씩 오를 수 있다. 2. 연속된 세 계단을 모두 밟아서는 안 된다. 3. 마지막 도착 계단은 반드시 밟아야 한다.
// 계단에서 얻을 수 있는 총 점수의 최댓값을 구하는 프로그램

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[301];
int dp[301];

int main(void) {

	cin >> n;
	for (auto i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dp[0] = arr[0];
	dp[1] = max(arr[1], arr[0] + arr[1]);
	dp[2] = max(arr[0] + arr[2], arr[1] + arr[2]);
	for (auto i = 3; i < n; i++) {
		dp[i] += max(arr[i] + dp[i-2],arr[i]+arr[i-1]+dp[i-3]);
	}
	int result = 0;
	result = dp[n - 1];

	cout << result << '\n';

}