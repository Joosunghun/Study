// 문제 11053번 가장 긴 증가하는 수열
// 수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램

#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[1001];
vector<int> dp(1001, 1);

int main(void) {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j])
				dp[i] = max(dp[j] + 1, dp[i]);
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, dp[i]);

	cout << ans << '\n';
}