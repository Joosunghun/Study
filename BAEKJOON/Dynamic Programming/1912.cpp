// 문제 1912번 연속합
// n개의 정수로 이루어진 임의의 수열
// 이 중 연속된 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합을 구하는 프로그램
// 단 수는 한 개 이상 선택해야 한다

#include <iostream>
using namespace std;

int main(void) {
	int n;
	int arr[100001];
	int dp[100001];
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dp[0] = arr[0];
	int sum = dp[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		sum = max(sum, dp[i]);
	}

	cout << sum << '\n';
}